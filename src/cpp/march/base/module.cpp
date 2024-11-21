#include <march/base/module.h>

namespace march {
	Module::Module() noexcept {
		predecessors_.reserve(8);
		successors_.reserve(8);
	}

	Module::~Module() noexcept {
	}

	bool Module::is_runnable() const noexcept {
		return false;
	}

	bool RunnableModule::is_runnable() const noexcept {
		return true;
	}

	void Module::register_predecessor(std::shared_ptr<Module>& predecessor) noexcept {
		predecessors_.push_back(predecessor);
	}

	void Module::register_successor(std::shared_ptr<Module>& successor) noexcept {
		successors_.push_back(successor);
	}

	const std::vector<std::shared_ptr<Module>>& Module::predecessors() const noexcept {
		return predecessors_;
	}

	const std::vector<std::shared_ptr<Module>>& Module::successors() const noexcept {
		return successors_;
	}
}
