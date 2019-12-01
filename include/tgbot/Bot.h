#ifndef TGBOT_BOT_H
#define TGBOT_BOT_H

#include <string>
#include "tgbot/Endpoints.h"
#include <memory>
#include "tgbot/EventHandler.h"

/*
 * @brief this object represent the Telegram bot
 * @brief it contains all endpoints and knows how to process incoming information
 */

namespace tgbot
{
	class Bot
	{
	public:
		//pointer of itself
		typedef std::shared_ptr<Bot> ptr;

	private:
		//member variables
		std::string m_token;
		Endpoints::ptr m_endpnts;
		EventHandler::ptr m_event_handler;

	public:
		//constructors
		//@param token: token which is needed for endpoints
		Bot(const std::string &token);

		//member functions
		/*
		 * @brief simply, returns the private member token
		 * @return token
		 */
		std::string get_token() const;

		/*
		 * @brief simply, returns the private member endpnts
		 * @return class Endpoints
		 */
		Endpoints::ptr get_endpnts() const;

		/*
		 * @brief simply, returns the private member event_handler
		 * @return class EventHandler
		 */
		EventHandler::ptr get_event_handler() const;
	};
}

#endif
