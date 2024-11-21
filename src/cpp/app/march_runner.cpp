#include <chrono>
#include <cstdint>
#include <iostream>
#include <dlfcn.h>
#include <march/base/module.h>
#include <march/data/impl/integers.h>
#include <march/data/impl/strings.h>
#include <thread>
#include <vector>
#include <map>

using namespace march;
using namespace std::chrono_literals;

std::vector<std::shared_ptr<Module>> modules;
std::map<std::string, void*> libs;

int32_t open_module(std::string name);
void connect_modules();
void do_something();
void close_modules();

int32_t main(int32_t argc, char** argv) {
	std::cout << "modular-architecture version: " << PROJECT_VERSION_DETAIL << std::endl;
	open_module("libmarch_module_generator.so");
	open_module("libmarch_module_printer.so");
	open_module("libmarch_module_reverser.so");
	open_module("libmarch_module_printer.so");
	connect_modules();
	do_something();
	close_modules();
	return 0;
}

int32_t open_module(std::string name) {
	void* handle = dlopen(name.c_str(), RTLD_LAZY);
	if (handle == nullptr) {
		std::cerr << "Error loading library: " << dlerror() << std::endl;
		return -1;
	}
	
	dlerror(); // Clear any existing error
	
	typedef std::shared_ptr<Module> (*function_create_instance)();
	function_create_instance create_instance = (function_create_instance)dlsym(handle, "create_instance");
	const char* error = dlerror();
	if (error) {
		std::cerr << "Error finding symbol 'createInstance': " << error << std::endl;
		dlclose(handle);
		return -2;
	}
	
	std::shared_ptr<Module> instance = create_instance();
	if (instance == nullptr) {
		std::cerr << "Error: createInstance returned nullptr." << std::endl;
		dlclose(handle);
		return -3;
	}
	
	modules.push_back(instance);
	libs.insert({name, handle});
	return 0;
}

void connect_modules() {
	for (size_t idx = 0; idx < modules.size(); idx++) {
		if (idx == 0) {
			continue;
		}
		
		modules[idx - 1]->register_successor(modules[idx]);
	}
}

void do_something() {
	for (std::shared_ptr<Module>& module: modules) {
		if (module->is_runnable()) {
			std::static_pointer_cast<RunnableModule>(module)->start();
		}
	}
	
	std::this_thread::sleep_for(5s);
}

void close_modules() {
	for (std::shared_ptr<Module>& module: modules) {
		module->finalize();
		module.reset();
	}

	std::map<std::string, void*>::iterator iter = libs.begin();
	while (iter != libs.end()) {
		dlclose(iter->second);
		iter++;
	}
}
