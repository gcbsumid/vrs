#ifndef TRANSLATECOMMAND_HPP
#define TRANSLATECOMMAND_HPP

#include "UpdateCommand.hpp"

namespace VRS {
	class TranslateCommand : public UpdateCommand {
	public: 
		TranslateCommand();
		~TranslateCommand();

		void execute();
	};
}

#endif