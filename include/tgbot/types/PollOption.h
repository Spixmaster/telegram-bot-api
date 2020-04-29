#ifndef TGBOT_TYPES_POLLOPTION_H
#define TGBOT_TYPES_POLLOPTION_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PollOption
	 * @brief This object contains information about one answer option in a poll.
	 */
	struct PollOption
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PollOption> ptr;

		//Member variables
		/**
		 * @var text
		 * @brief Option text, 1-100 characters
		 */
		std::string text;
		/**
		 * @var voter_count
		 * @brief Number of users that voted for this option
		 */
		int voter_count;

		//Constructors
		PollOption();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		PollOption(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
