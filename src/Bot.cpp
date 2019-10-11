#include "tgbot/Bot.h"

namespace tgbot
{
	Bot::Bot(const std::string &token) : m_token(token), m_endpnts(std::make_shared<Endpoints>(token)), m_event_handler(std::make_shared<EventHandler>(token))
	{}

	std::string Bot::get_token()
	{
		return m_token;
	}

	Endpoints::ptr Bot::get_endpnts()
	{
		return m_endpnts;
	}

	EventHandler::ptr Bot::get_event_handler()
	{
		return m_event_handler;
	}
}
