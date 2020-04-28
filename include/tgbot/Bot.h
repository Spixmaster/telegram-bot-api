#ifndef TGBOT_BOT_H
#define TGBOT_BOT_H

#include <string>
#include "tgbot/Endpoints.h"
#include <memory>
#include "tgbot/EventHandler.h"

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
		 * @param token The Telegram bot token which is needed for the endpoints.
		 */
		Bot(const std::string &token);

		//Member functions
		/*
		 * @brief Getter.
		 * @return The Telegram bot token used by this bot.
		 */
		std::string get_token() const noexcept;

		/*
		 * @brief Getter.
		 * @return Endpoints
		 */
		Endpoints::ptr get_endpnts() const noexcept;

		/*
		 * @brief Getter.
		 * @return EventHandler
		 */
		EventHandler::ptr get_event_handler() const noexcept;
	};
}

#endif
