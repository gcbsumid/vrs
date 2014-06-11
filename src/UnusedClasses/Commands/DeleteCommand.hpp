#ifndef DELETECOMMAND_HPP
#define DELETECOMMAND_HPP

#include "Command.hpp"

class DeleteCommand : public Command {
public:
	DeleteCommand(uint id);
	~DeleteCommand();
	void execute();

private:
	uing mId;
};

#endif