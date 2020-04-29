#ifndef TGBOT_TYPES_POLL_H
#define TGBOT_TYPES_POLL_H

#include <string>
#include "tgbot/types/PollOption.h"
#include <vector>
#include <rapidjson/document.h>
#include <memory>
#include "tgbot/types/MessageEntity.h"

namespace tgbot
{
	/**
	 * @struct Poll
	 * @brief This object contains information about a poll.
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
		 * @var id
		 * @brief Unique poll identifier
		 */
		std::string id;
		/**
		 * @var question
		 * @brief Poll question, 1-255 characters
		 */
		std::string question;
		/**
		 * @var options
		 * @brief List of poll options
		 */
		std::vector<PollOption::ptr> options;
		/**
		 * @var total_voter_count
		 * @brief Total number of users that voted in the poll
		 */
		int total_voter_count;
		/**
		 * @var is_closed
		 * @brief True, if the poll is closed
		 */
		bool is_closed;
		/**
		 * @var is_anonymous
		 * @brief True, if the poll is anonymous
		 */
		bool is_anonymous;
		/**
		 * @var type
		 * @brief Poll type, currently can be “regular” or “quiz”
		 */
		std::string type;
		/**
		 * @var allows_multiple_answers
		 * @brief True, if the poll allows multiple answers
		 */
		bool allows_multiple_answers;
		/**
		 * @var correct_option_id
		 * @brief Optional. 0-based identifier of the correct answer option.
		 * @details Available only for polls in the quiz mode, which are closed, or was sent (not forwarded) by the bot or to the private chat with the bot.
		 */
		int correct_option_id;
		/**
		 * @var explanation
		 * @brief Optional. Text that is shown when a user chooses an incorrect answer or taps on the lamp icon in a quiz-style poll, 0-200 characters
		 */
		std::string explanation;
		/**
		 * @var explanation_entities
		 * @brief Optional. Special entities like usernames, URLs, bot commands, etc. that appear in the explanation
		 */
		std::vector<MessageEntity::ptr> explanation_entities;
		/**
		 * @var open_period
		 * @brief Optional. Amount of time in seconds the poll will be active after creation
		 */
		int open_period;
		/**
		 * @var close_date
		 * @brief Optional. Point in time (Unix timestamp) when the poll will be automatically closed
		 */
		int close_date;

		//Constructors
		Poll();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Poll(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
