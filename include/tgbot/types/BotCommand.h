#ifndef TGBOT_TYPES_BOTCOMMAND_H
#define TGBOT_TYPES_BOTCOMMAND_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct BotCommand
	 * @brief This object represents a bot command.
	 */
	struct BotCommand
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<BotCommand> ptr;

		//Member variables
		/**
		 * @var command
		 * @brief Text of the command, 1-32 characters. Can contain only lowercase English letters, digits and underscores.
		 */
		std::string command;
		/**
		 * @var description
		 * @brief Description of the command, 3-256 characters.
		 */
		std::string description;

		//Constructors
		BotCommand();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		BotCommand(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
