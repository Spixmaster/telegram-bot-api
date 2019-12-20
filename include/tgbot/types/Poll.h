#ifndef TGBOT_TYPES_POLL_H
#define TGBOT_TYPES_POLL_H

#include <string>
#include "tgbot/types/PollOption.h"
#include <vector>
#include <rapidjson/document.h>
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct Poll
	{
		//pointer of itself
		typedef std::shared_ptr<Poll> ptr;

		//member variables
		std::string id;
		std::string question;
		std::vector<PollOption::ptr> options;
		bool is_closed;

		//constructors
		Poll();

		//@param json: json object of Poll
		Poll(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
