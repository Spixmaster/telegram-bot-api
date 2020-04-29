#include "tgbot/Bot.h"

namespace tgbot
{
	Bot::Bot(const std::string &token) : m_token(token), m_endpnts(std::make_shared<Endpoints>(token)), m_event_handler(std::make_shared<EventHandler>(token))
	{}

	std::string Bot::get_token() const noexcept
	{
		return m_token;
	}

	Endpoints::ptr Bot::get_endpnts() const noexcept
	{
		return m_endpnts;
	}

	EventHandler::ptr Bot::get_event_handler() const noexcept
	{
		return m_event_handler;
	}
}
