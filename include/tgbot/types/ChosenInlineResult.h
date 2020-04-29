#ifndef TGBOT_TYPES_CHOSENINLINERESULT_H
#define TGBOT_TYPES_CHOSENINLINERESULT_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/types/Location.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct ChosenInlineResult
	 * @brief Represents a result of an inline query that was chosen by the user and sent to their chat partner.
	 * @note It is necessary to enable inline feedback via \@Botfather in order to receive these objects in updates.
	 */
	struct ChosenInlineResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ChosenInlineResult> ptr;

		//Member variables
		/**
		 * @var result_id
		 * @brief The unique identifier for the result that was chosen
		 */
		std::string result_id;
		/**
		 * @var from
		 * @brief The user that chose the result
		 */
		User::ptr from;
		/**
		 * @var location
		 * @brief Optional. Sender location, only for bots that require user location
		 */
		Location::ptr location;
		/**
		 * @var inline_message_id
		 * @brief Optional. Identifier of the sent inline message. Available only if there is an inline keyboard attached to the message. Will be also received in callback queries and can be used to edit the message.
		 */
		std::string inline_message_id;
		/**
		 * @var query
		 * @brief The query that was used to obtain the result
		 */
		std::string query;

		//Constructors
		ChosenInlineResult();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		ChosenInlineResult(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
