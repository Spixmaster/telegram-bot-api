#ifndef TGBOT_BOT_H
#define TGBOT_BOT_H

#include <string>
#include "tgbot/Endpoints.h"
#include <memory>
#include "tgbot/EventHandler.h"

/**
 * @mainpage telegram-bot-api
 * @author Matheus Gabriel Werny de Lima
 * @copyright Apache-2.0 License
 * @version
 * 1.3.23 (15.08.2020)
 * - Submodule update.
 * - Files update.
 * @version
 * 1.3.22 (12.08.2020)
 * - Cmake update.
 * - Submodule update.
 * @version
 * 1.3.21 (12.08.2020)
 * - Cmake update.
 * - Submodule update.
 * @version
 * 1.3.20 (12.08.2020)
 * - Cmake update.
 * - Submodule update.
 * @version
 * 1.3.19 (11.08.2020)
 * - Used unused variables.
 * @version
 * 1.3.18 (10.08.2020)
 * - Cmake update.
 * @version
 * 1.3.17 (09.08.2020)
 * - Cmake update.
 * - Readme update.
 * @version
 * 1.3.16 (09.08.2020)
 * - Cmake added.
 * - Typo fixed.
 * - Submodule update.
 * @version
 * 1.3.15 (06.07.2020)
 * - Submodule update.
 * @version
 * 1.3.14 (03.07.2020)
 * - Submodule update.
 * @version
 * 1.3.13 (25.06.2020)
 * - License changed.
 * @version
 * 1.3.12 (22.06.2020)
 * - Submodule update.
 * @version
 * 1.3.11 (22.06.2020)
 * - Submodule update.
 * @version
 * 1.3.10 (21.06.2020)
 * - Submodule update.
 * - Removed contributing.
 * @version
 * 1.3.9 (20.06.2020)
 * - Submodule update.
 * - Code revision.
 * @version
 * 1.3.8 (20.06.2020)
 * - Submodule update.
 * @version
 * 1.3.7 (19.06.2020)
 * - HTTP arguments corrected.
 * @version
 * 1.3.6 (19.06.2020)
 * - Submodule updated.
 * @version
 * 1.3.5 (18.06.2020)
 * - Comment errors were fixed.
 * @version
 * 1.3.4 (16.06.2020)
 * - Readme update.
 * @version
 * 1.3.3 (16.06.2020)
 * - Script updated.
 * - Submodule updated.
 * @version
 * 1.3.2 (15.06.2020)
 * - Submodule updated.
 * - Adjusted error log.
 * @version
 * 1.3.1 (07.06.2020)
 * - Readme updated.
 * @version
 * 1.3.0 (06.06.2020)
 * - Updated to Telegram bot API version 4.9.
 * - Code revision.
 * @version
 * 1.2.15 (04.06.2020)
 * - Submodule update.
 * - Contributing update.
 * - Code revision.
 * @version
 * 1.2.14 (31.05.2020)
 * - Submodule update.
 * @version
 * 1.2.13 (29.05.2020)
 * - Submodule updated.
 * - Fixed a wrong text message.
 * @version
 * 1.2.12 (28.05.2020)
 * - Submodule updated.
 * @version
 * 1.2.11 (25.05.2020)
 * - Changed some error output.
 * - Improved some messages.
 * @version
 * 1.2.10 (24.05.2020)
 * - Submodule updated.
 * @version
 * 1.2.9 (23.05.2020)
 * - Contributing.md update.
 * @version
 * 1.2.8 (22.05.2020)
 * - Submodule updated.
 * @version
 * 1.2.7 (15.05.2020)
 * - Bug fixes.
 * @version
 * 1.2.6 (15.05.2020)
 * - Submodule update.
 * @version
 * 1.2.5 (15.05.2020)
 * - Submodule updated.
 * - Contributing updated.
 * - Readme updated.
 * - Examples updated.
 * @version
 * 1.2.4 (11.05.2020)
 * - Submodule and readme update.
 * @version
 * 1.2.3 (01.05.2020)
 * - Regenerated the documentation.
 * @version
 * 1.2.2 (01.05.2020)
 * - Improved the endpoints.
 * @version
 * 1.2.1 (29.04.2020)
 * - Updated a Doxygen page.
 * @version
 * 1.2.0 (29.04.2020)
 * - Used formatting strings in the messages file to ease translations.
 * - Applied an error log instead of output to stderr.
 * - Modified all comments to fit the Doxygen syntax.
 * - Revision of the whole code.
 */

/**
 * @page dev-log Developer log
 * @section dev-log-notes Notes
 * In some constructors (mainly for field "thumb"), I only look for a string value although InputFile would also be possible but I do not know how they would send me that.
 * This is nothing to worry about as it is not even intended that Telegram sends all objects to us. Some are just sent by us.
 * There is only a field "result" in the JSON object answer if the request was a success.
 */

namespace tgbot
{
	/**
	 * @class Bot
	 * @brief This class represents the Telegram bot.
	 * @details It contains all endpoints and knows how to process incoming information.
	 */
	class Bot
	{
	public:
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Bot> ptr;

	private:
		//Member variables
		/**
		 * @var m_token
		 * @brief The bot token.
		 */
		std::string m_token;
		/**
		 * @var m_endpnts
		 * @brief This object contains all endpoints.
		 */
		Endpoints::ptr m_endpnts;
		/**
		 * @var m_event_handler
		 * @brief This object is responsible for handling the incoming events.
		 */
		EventHandler::ptr m_event_handler;

	public:
		//Constructors
		/**
		 * @param[in] token The Telegram bot token which is needed for the endpoints.
		 */
		Bot(const std::string &token);

		//Member functions
		/**
		 * @brief Getter.
		 * @return The Telegram bot token used by this bot.
		 */
		std::string get_token() const noexcept;

		/**
		 * @brief Getter.
		 * @return Endpoints
		 */
		Endpoints::ptr get_endpnts() const noexcept;

		/**
		 * @brief Getter.
		 * @return EventHandler
		 */
		EventHandler::ptr get_event_handler() const noexcept;
	};
}

#endif
