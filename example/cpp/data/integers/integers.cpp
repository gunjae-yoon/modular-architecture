#include "integers.h"

namespace march {
	Integers::Integers() : Data() {
		values.reserve(100);
	}

	Integers::~Integers() {
	}

	uint64_t Integers::attach(const uint64_t value) {
		values.push_back(value);
		return values.size();
	}
}
