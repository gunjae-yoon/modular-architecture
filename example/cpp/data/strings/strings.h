#ifndef __example_cpp_data_strings_h__
#define __example_cpp_data_strings_h__

#include <march/base/data.h>
#include <vector>
#include <string>

namespace march {
	class Strings : public Data {
	public:
		Strings();
		virtual ~Strings();
		
		uint64_t attach(const std::string& string);
		
	public:
		std::vector<std::string> values;
	};
}

#endif
