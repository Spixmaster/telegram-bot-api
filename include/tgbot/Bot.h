#ifndef BOT_H
#define BOT_H

#include <string>
#include "Endpoints.h"
#include <memory>
#include "EventHandler.h"

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
		std::string get_token();

		/*
		 * @brief simply, returns the private member endpnts
		 * @return class Endpoints
		 */
		Endpoints::ptr get_endpnts();

		/*
		 * @brief simply, returns the private member event_handler
		 * @return class EventHandler
		 */
		EventHandler::ptr get_event_handler();
	};
}

#endif
