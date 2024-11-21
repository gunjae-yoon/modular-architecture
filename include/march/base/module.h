#ifndef __march_base_module_h__
#define __march_base_module_h__

#include <cstdint>
#include <march/base/data.h>
#include <memory>
#include <vector>

namespace march {
	class Module {
	public:
		Module() noexcept;
		virtual ~Module() noexcept;
		
		virtual bool initialize() = 0;
		virtual void finalize() = 0;
		
		virtual int64_t push(const std::shared_ptr<Data>& data) = 0;
		virtual bool pull(std::shared_ptr<Data>& data) = 0;
		
		virtual bool is_runnable() const noexcept;
		
		void register_predecessor(std::shared_ptr<Module>& predecessor) noexcept;
		void register_successor(std::shared_ptr<Module>& successor) noexcept;
		
		[[nodiscard]] const std::vector<std::shared_ptr<Module>>& predecessors() const noexcept;
		[[nodiscard]] const std::vector<std::shared_ptr<Module>>& successors() const noexcept;
		
	protected:
		std::vector<std::shared_ptr<Module>> predecessors_;
		std::vector<std::shared_ptr<Module>> successors_;
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
		
		virtual bool is_runnable() const noexcept;
	};
}

#endif
