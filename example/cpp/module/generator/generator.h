#ifndef __example_cpp_module_generator_h__
#define __example_cpp_module_generator_h__

#include <march/base/module.h>
#include <vector>
#include <thread>

namespace march {
	class Generator : public RunnableModule {
	public:
		Generator();
		virtual ~Generator();
		
		bool initialize() override;
		void finalize() override;
		
		int64_t push(const std::shared_ptr<Data>& data) override;
		bool pull(std::shared_ptr<Data>& data) override;
		
		bool start() override;
		void stop() override;
		
	private:
		std::thread thread_;
		bool is_running_;
	};
	
	extern "C" std::shared_ptr<Module> create_instance();
}

#endif
