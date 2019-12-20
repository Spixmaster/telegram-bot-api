#ifndef TGBOT_EVENTHANDLER_H
#define TGBOT_EVENTHANDLER_H

#include <string>
#include "tgbot/Endpoints.h"
#include <memory>
#include "tgbot/types/Update.h"
#include <functional>
#include "tgbot/types/Message.h"
#include "tgbot/types/InlineQuery.h"
#include "tgbot/types/ChosenInlineResult.h"
#include "tgbot/types/CallbackQuery.h"
#include <unordered_map>

/*
 * @brief entry of every Bot is function EventHandler::long_poll() which simply makes a request getUpdates() via the Endpoints object; therefore, it needs to be run
 * 			in an endless loop for always fetching new incoming data
 * @brief each new update is processed by this->handle_update()
 * @brief this->handle_update calls proper vector which contains the functions which shall be called for that specific event
 * @brief all function which start with on_...() simply add the function given as argument to the proper vector
 */

namespace tgbot
{
	class EventHandler
	{
	public:
		//pointer of itself
		typedef std::shared_ptr<EventHandler> ptr;

	private:
		//member variables
		Endpoints::ptr m_endpnts;
		int m_offset = 0; //is used for getUpdates() function of member variable m_endpnts
		//listener elements
		typedef std::function<void (const Message::ptr)> m_message_listener_element;
		typedef std::function<void (const Message::ptr)> m_edited_message_listener_element;
		typedef std::function<void (const Message::ptr)> m_channel_post_listener_element;
		typedef std::function<void (const Message::ptr)> m_edited_channel_post_listener_element;
		typedef std::function<void (const InlineQuery::ptr)> m_inline_query_listener_element;
		typedef std::function<void (const ChosenInlineResult::ptr)> m_chosen_inline_result_listener_element;
		typedef std::function<void (const CallbackQuery::ptr)> m_callback_query_listener_element;
		typedef std::function<void (const ShippingQuery::ptr)> m_shipping_query_listener_element;
		typedef std::function<void (const PreCheckoutQuery::ptr)> m_pre_checkout_query_listener_element;
		typedef std::function<void (const Poll::ptr)> m_poll_listener_element;
		//vectors of listeners
			//just for member variable message
		std::vector<m_message_listener_element> m_on_any_msg_listener_ls;
		std::unordered_map<std::string, m_message_listener_element> m_on_cmd_listener_ls;
		std::vector<m_message_listener_element> m_on_unknwn_cmd_listener_ls;
		std::vector<m_message_listener_element> m_on_non_cmd_msg_listener_ls;
			//rest which is element of the Update object
		std::vector<m_inline_query_listener_element> m_on_inline_query_listener_ls;
		std::vector<m_chosen_inline_result_listener_element> m_on_chosen_inline_result_listener_ls;
		std::vector<m_callback_query_listener_element> m_on_callback_query_listener_ls;
		std::vector<m_shipping_query_listener_element> m_on_shipping_query_listener_ls;
		std::vector<m_pre_checkout_query_listener_element> m_pre_checkout_query_listener_ls;
		std::vector<m_poll_listener_element> m_poll_listener_ls;

	public:
		//constructors
		EventHandler(const std::string &token);

		//member functions
		/*
		 * @brief needs to be run in an endless loop
		 * @brief calls getUpdates function of Endpoints object
		 */
		void long_poll();

	private:
		/*
		 * @brief get called by long_poll() which sends this function an update
		 * @brief calls all the corresponding vector of listener elements
		 */
		void handle_update(const Update::ptr &update) const;

	public:
		//@brief adds the listener to proper lister list
		void on_any_msg(const m_message_listener_element &listener_element);

		//@brief adds the listener to proper lister list
		void on_cmd(const std::string &cmd, const m_message_listener_element &listener_element);

		//@brief adds the listener to proper lister list
		void on_unknwn_cmd(const m_message_listener_element &listener_element);

		//@brief adds the listener to proper lister list
		void on_non_cmd_msg(const m_message_listener_element &listener_element);

		//@brief adds the listener to proper lister list
		void on_inline_query(const m_inline_query_listener_element &listener_element);

		//@brief adds the listener to proper lister list
		void on_chosen_inline_result(const m_chosen_inline_result_listener_element &listener_element);

		//@brief adds the listener to proper lister list
		void on_callback_query(const m_callback_query_listener_element &listener_element);

		//@brief adds the listener to proper lister list
		void on_shipping_query(const m_shipping_query_listener_element &listener_element);

		//@brief adds the listener to proper lister list
		void on_pre_checkout_query(const m_pre_checkout_query_listener_element &listener_element);

		//@brief adds the listener to proper lister list
		void on_poll_query(const m_poll_listener_element &listener_element);
	};
}

#endif
