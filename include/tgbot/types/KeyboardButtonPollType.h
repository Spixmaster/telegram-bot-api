#ifndef TGBOT_TYPES_KEYBOARDBUTTONPOLLTYPE_H
#define TGBOT_TYPES_KEYBOARDBUTTONPOLLTYPE_H

#include <string>
#include "rapidjson/document.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct KeyboardButtonPollType
	 * @brief This object represents type of a poll, which is allowed to be created and sent when the corresponding button is pressed.
	 */
	struct KeyboardButtonPollType
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<KeyboardButtonPollType> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Optional. If quiz is passed, the user will be allowed to create only polls in the quiz mode. If regular is passed, only regular polls will be allowed. Otherwise, the user will be allowed to create a poll of any type.
		 */
		std::string type;

		//Constructors
		KeyboardButtonPollType();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		KeyboardButtonPollType(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
