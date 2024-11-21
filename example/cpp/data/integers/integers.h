#ifndef __example_cpp_data_integers_h__
#define __example_cpp_data_integers_h__

#include <march/base/data.h>
#include <vector>
#include <string>

namespace march {
	class Integers : public Data {
	public:
		Integers();
		virtual ~Integers();
		
		uint64_t attach(const uint64_t value);
		
	public:
		std::vector<uint64_t> values;
	};
}

#endif
