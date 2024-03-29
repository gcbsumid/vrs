#ifndef UPDATECOMMAND_HPP
#define UPDATECOMMAND_HPP

#include "Command.hpp"

namespace VRS {
	class UpdateCommand : public Command {
	public:
		UpdateCommand(uint id) : mId(id) {}
		virtual ~UpdateCommand() {}

	protected: 
		uint mId;
	};
}

#endif