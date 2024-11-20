#ifndef __march_base_module_h__
#define __march_base_module_h__

#include <cstdint>
#include <march/base/data.h>
#include <memory>

namespace march {
	class Module {
	public:
		Module() {}
		virtual ~Module() {}
		
		virtual bool initialize() = 0;
		virtual void finalize() = 0;
		
		virtual int64_t push(const std::shared_ptr<Data>& data) = 0;
		virtual bool pull(std::shared_ptr<Data>& data) = 0;
	};
	
	class RunnableModule : public Module {
	public:
		RunnableModule() : Module() {}
		virtual ~RunnableModule() {}
		
		virtual bool initialize() = 0;
		virtual void finalize() = 0;
		
		virtual int64_t push(const std::shared_ptr<Data>& data) = 0;
		virtual bool pull(std::shared_ptr<Data>& data) = 0;
		
		virtual bool start() = 0;
		virtual void stop() = 0;
	};
}

#endif
