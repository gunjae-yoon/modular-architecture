#include "reverser.h"
#include <march/data/impl/integers.h>
#include <march/data/impl/strings.h>
#include <typeinfo>
#include <iostream>

namespace march {
	Reverser::Reverser() : Module() {
	}

	Reverser::~Reverser() {
	}

	bool Reverser::initialize() {
		return true;
	}

	void Reverser::finalize() {
	}

	int64_t Reverser::push(const std::shared_ptr<Data>& data) {
		if (typeid(*data) == typeid(Integers)) {
			std::shared_ptr<Integers> reversed =  std::make_shared<Integers>();
			const std::shared_ptr<Integers>& typed_data = std::static_pointer_cast<Integers>(data);
			for (size_t idx = 0; idx < typed_data->values.size(); idx++) {
				reversed->values.push_back(typed_data->values[typed_data->values.size() - (idx + 1)]);
			}
			for (std::shared_ptr<Module>& successor : successors_) {
				successor->push(reversed);
			}
		} else if (typeid(*data) == typeid(Strings)) {
			std::shared_ptr<Strings> reversed =  std::make_shared<Strings>();
			const std::shared_ptr<Strings>& typed_data = std::static_pointer_cast<Strings>(data);
			for (size_t idx = 0; idx < typed_data->values.size(); idx++) {
				reversed->values.push_back(typed_data->values[typed_data->values.size() - (idx + 1)]);
			}
			for (std::shared_ptr<Module>& successor : successors_) {
				successor->push(reversed);
			}
		} else {
			std::cout << "UNKNOWN" << std::endl;
			return -1;
		}
		return 0;
	}

	bool Reverser::pull(std::shared_ptr<Data>& data) {
		return true;
	}
}

namespace march {
	extern "C" std::shared_ptr<Module> create_instance() {
		return std::make_shared<Reverser>();
	}
}
