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
	 * @brief This object represents an answer of a user in a non-anonymous poll.
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
		 * @var poll_id
		 * @brief Unique poll identifier
		 */
		std::string poll_id;
		/**
		 * @var user
		 * @brief The user, who changed the answer to the poll
		 */
		User::ptr user;
		/**
		 * @var option_ids
		 * @brief 0-based identifiers of answer options, chosen by the user. May be empty if the user retracted their vote.
		 */
		std::vector<int> option_ids;

		//Constructors
		PollAnswer();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PollAnswer(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
