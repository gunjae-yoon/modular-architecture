#include "generator.h"
#include <march/data/impl/integers.h>
#include <march/data/impl/strings.h>
#include <chrono>

using namespace std::chrono_literals;

namespace march {
	Generator::Generator() {
	}

	Generator::~Generator() {
	}

	bool Generator::initialize() {
		is_running_ = false;
		return true;
	}

	void Generator::finalize() {
		stop();
	}

	int64_t Generator::push(const std::shared_ptr<Data>& data) {
		return 0;
	}

	bool Generator::pull(std::shared_ptr<Data>& data) {
		return false;
	}

	bool Generator::start() {
		if (is_running_) {
			return true;
		}
		
		is_running_ = true;
		thread_ = std::thread([this]() {
			uint64_t count = 0;
			while (is_running_) {
				std::this_thread::sleep_for(200ms);
				
				std::shared_ptr<Integers> integers = std::make_shared<Integers>();
				std::shared_ptr<Strings> strings = std::make_shared<Strings>();
				for (uint64_t idx = 0; idx < count; idx++) {
					integers->attach(idx);
					strings->attach("" + std::to_string(idx));
				}
				
				for (std::shared_ptr<Module>& successor : successors_) {
					successor->push(integers);
					successor->push(strings);
				}
				
				count++;
			}
		});
		
		return true;
	}

	void Generator::stop() {
		if (is_running_ == false) {
			return;
		}
		
		is_running_ = false;
		if (thread_.joinable()) {
			thread_.join();
		}
	}
}

namespace march {
	extern "C" std::shared_ptr<Module> create_instance() {
		return std::make_shared<Generator>();
	}
}
