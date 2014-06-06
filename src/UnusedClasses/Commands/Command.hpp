#ifndef COMMAND_HPP
#define COMMAND_HPP

namespace VRS {
	class Command {
	public:
		virtual ~Command() {}
		virtual void execute() = 0;
	};
}

#endif