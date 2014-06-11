#ifndef CREATECOMMAND_HPP
#define CREATECOMMAND_HPP

#include "Command.hpp"

class CreateCommand : public Command {
public:
	CreateCommand();
	virtual ~CreateCommand();
	void execute();
};

#endif