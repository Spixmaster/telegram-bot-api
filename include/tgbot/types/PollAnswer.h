#ifndef TGBOT_TYPES_POLLANSWER_H
#define TGBOT_TYPES_POLLANSWER_H

#include <string>
#include <memory>
#include "tgbot/types/User.h"
#include <vector>

namespace tgbot
{
	/**
	 * @struct PollAnswer
	 */
	struct PollAnswer
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PollAnswer> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string poll_id;
		/**
		 * @var
		 */
		User::ptr user;
		/**
		 * @var
		 */
		std::vector<int> option_ids;

		//Constructors
		PollAnswer();

		//@param json: json object of PollAnswer
		PollAnswer(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
