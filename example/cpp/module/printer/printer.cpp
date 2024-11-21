#include "printer.h"
#include <march/data/impl/integers.h>
#include <march/data/impl/strings.h>
#include <typeinfo>
#include <iostream>

namespace march {
	Printer::Printer() : Module() {
	}

	Printer::~Printer() {
	}

	bool Printer::initialize() {
		return true;
	}

	void Printer::finalize() {
	}

	int64_t Printer::push(const std::shared_ptr<Data>& data) {
		if (typeid(*data) == typeid(Integers)) {
			const std::shared_ptr<Integers>& typed_data = std::static_pointer_cast<Integers>(data);
			for (const uint64_t& value : typed_data->values) {
				std::cout << "integer: " << value << std::endl;
			}
		} else if (typeid(*data) == typeid(Strings)) {
			const std::shared_ptr<Strings>& typed_data = std::static_pointer_cast<Strings>(data);
			for (const std::string& value : typed_data->values) {
				std::cout << "string: " << value << std::endl;
			}
		} else {
			std::cout << "UNKNOWN" << std::endl;
			return -1;
		}
		
		std::cout << std::endl;
		for (std::shared_ptr<Module>& successor : successors_) {
			successor->push(data);
		}
		return 0;
	}

	bool Printer::pull(std::shared_ptr<Data>& data) {
		return true;
	}
}

namespace march {
	extern "C" std::shared_ptr<Module> create_instance() {
		return std::make_shared<Printer>();
	}
}
