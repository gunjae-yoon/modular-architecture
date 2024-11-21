#ifndef __example_cpp_module_printer_h__
#define __example_cpp_module_printer_h__

#include <march/base/module.h>
#include <vector>

namespace march {
	class Printer : public Module {
	public:
		Printer();
		virtual ~Printer();

		bool initialize() override;
		void finalize() override;
		
		int64_t push(const std::shared_ptr<Data>& data) override;
		bool pull(std::shared_ptr<Data>& data) override;
	};
	
	extern "C" std::shared_ptr<Module> create_instance();
}

#endif
