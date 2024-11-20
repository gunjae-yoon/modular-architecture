#ifndef __march_base_data_h__
#define __march_base_data_h__

namespace march {
	class Data {
	public:
		Data() {}
		virtual ~Data() {}
		
		virtual Data* create_instance() = 0;
	};
}

#endif
