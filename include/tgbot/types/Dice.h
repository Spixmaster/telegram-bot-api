#ifndef TGBOT_TYPES_DICE_H
#define TGBOT_TYPES_DICE_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Dice
	 * @brief This object represents an animated emoji that displays a random value.
	 */
	struct Dice
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Dice> ptr;

		//Member variables
		/**
		 * @var emoji
		 * @brief Emoji on which the dice throw animation is based
		 */
		std::string emoji;
		/**
		 * @var value
		 * @brief Value of the dice, 1-6 for “🎲” and “🎯” base emoji, 1-5 for “🏀” base emoji
		 */
		int value;

		//Constructors
		Dice();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Dice(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
