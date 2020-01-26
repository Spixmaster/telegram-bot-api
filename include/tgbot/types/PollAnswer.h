#ifndef TGBOT_TYPES_POLLANSWER_H
#define TGBOT_TYPES_POLLANSWER_H

#include <string>
#include <memory>
#include "tgbot/types/User.h"
#include <vector>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct PollAnswer
	{
		//pointer of itself
		typedef std::shared_ptr<PollAnswer> ptr;

		//member variables
		std::string poll_id;
		User::ptr user;
		std::vector<int> option_ids;

		//constructors
		PollAnswer();

		//@param json: json object of PollAnswer
		PollAnswer(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
