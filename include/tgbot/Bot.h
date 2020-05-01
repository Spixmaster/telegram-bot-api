#ifndef TGBOT_BOT_H
#define TGBOT_BOT_H

#include <string>
#include "tgbot/Endpoints.h"
#include <memory>
#include "tgbot/EventHandler.h"

/**
 * @mainpage telegram-bot-api
 * @author Matheus Gabriel Werny de Lima
 * @copyright GNU General Public License v2.0
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
 * This is nothing to worry about at it is not even intended that Telegram sends all objects to us. Some are just sent by us.
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
