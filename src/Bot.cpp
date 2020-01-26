#include "tgbot/Bot.h"

/*
 * ###this project###
 * in some constructors (mainly for field "thumb"), I only look for a string value although InputFile would also be possible but I do not know how they would arrange that
 */

namespace tgbot
{
	Bot::Bot(const std::string &token) : m_token(token), m_endpnts(std::make_shared<Endpoints>(token)), m_event_handler(std::make_shared<EventHandler>(token))
	{}

	std::string Bot::get_token() const
	{
		return m_token;
	}

	Endpoints::ptr Bot::get_endpnts() const
	{
		return m_endpnts;
	}

	EventHandler::ptr Bot::get_event_handler() const
	{
		return m_event_handler;
	}
}
