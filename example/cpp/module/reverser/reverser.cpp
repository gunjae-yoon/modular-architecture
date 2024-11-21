#include "reverser.h"
#include <march/data/impl/integers.h>
#include <march/data/impl/strings.h>
#include <typeinfo>
#include <iostream>

namespace march {
	Reverser::Reverser() : Module() {
		converted_.push_back(std::make_shared<Integers>());
		converted_.push_back(std::make_shared<Strings>());
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
			std::cout << "INTEGERS" << std::endl;
		} else if (typeid(*data) == typeid(Strings)) {
			std::cout << "STRINGS" << std::endl;
		} else {
			std::cout << "UNKNOWN" << std::endl;
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
