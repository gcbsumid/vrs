#ifndef CREATECOMMAND_HPP
#define CREATECOMMAND_HPP

#include "Command.hpp"

namespace VRS {
	class CreateCommand : public Command {
	public:
		CreateCommand();
		virtual ~CreateCommand();
		void execute();
	};
}

#endif