#ifndef UPDATECOMMAND_HPP
#define UPDATECOMMAND_HPP

#include "Command.hpp"

class UpdateCommand : public Command {
public:
	UpdateCommand(uint id) : mId(id) {}
	virtual ~UpdateCommand() {}

protected: 
	uint mId;
};

#endif