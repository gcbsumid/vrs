#ifndef TRANSLATECOMMAND_HPP
#define TRANSLATECOMMAND_HPP

#include "UpdateCommand.hpp"

class TranslateCommand : public UpdateCommand {
public: 
	TranslateCommand();
	~TranslateCommand();

	void execute();
};

#endif