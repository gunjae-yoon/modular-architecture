#include "strings.h"

namespace march {
	Strings::Strings() : Data() {
		values.reserve(100);
	}

	Strings::~Strings() {
		values.clear();
	}

	uint64_t Strings::attach(const std::string& string) {
		values.push_back(string);
		return values.size();
	}
}
