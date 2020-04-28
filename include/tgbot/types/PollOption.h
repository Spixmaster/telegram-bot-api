#ifndef TGBOT_TYPES_POLLOPTION_H
#define TGBOT_TYPES_POLLOPTION_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct PollOption
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
		std::string text;
		int voter_count = -1;

		//Constructors
		PollOption();

		//@param json: json object of PollOption
		PollOption(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
