#ifndef TGBOT_TYPES_POLL_H
#define TGBOT_TYPES_POLL_H

#include <string>
#include "tgbot/types/PollOption.h"
#include <vector>
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Poll
	 */
	struct Poll
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Poll> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string id;
		/**
		 * @var
		 */
		std::string question;
		/**
		 * @var
		 */
		std::vector<PollOption::ptr> options;
		/**
		 * @var
		 */
		int total_voter_count = -1;
		/**
		 * @var
		 */
		bool is_closed;
		/**
		 * @var
		 */
		bool is_anonymous;
		/**
		 * @var
		 */
		std::string type;
		/**
		 * @var
		 */
		bool allows_multiple_answers;
		/**
		 * @var
		 */
		int correct_option_id = -1;

		//Constructors
		Poll();

		//@param json: json object of Poll
		Poll(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
