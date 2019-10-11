#ifndef TGBOT_TYPES_INPUTMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTMESSAGECONTENT_H

#include <memory>

namespace tgbot
{
	struct InputMessageContent
	{
		//pointer of itself
		typedef std::shared_ptr<InputMessageContent> ptr;

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
