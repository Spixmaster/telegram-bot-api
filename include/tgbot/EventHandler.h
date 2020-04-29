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

namespace tgbot
{
	/**
	 * @EventHandler
	 * @brief The event handler which handles incoming data.
	 */
	class EventHandler
	{
	public:
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<EventHandler> ptr;

	private:
		//Member variables
		/**
		 * @var m_endpnts
		 * @brief An object of the class Endpoints is needed as the instance of this class need to send requests.
		 */
		Endpoints::ptr m_endpnts;
		/**
		 * @var m_offset
		 * @brief It is used for the getUpdates() function of the class Endpoints.
		 */
		int m_offset = 0;
		//Listener elements
		/**
		 * @var m_message_listener_element
		 * @brief An element which is added to the proper listener.
		 */
		typedef std::function<void (const Message::ptr)> m_message_listener_element;
		/**
		 * @var m_edited_message_listener_element
		 * @brief An element which is added to the proper listener.
		 */
		typedef std::function<void (const Message::ptr)> m_edited_message_listener_element;
		/**
		 * @var m_channel_post_listener_element
		 * @brief An element which is added to the proper listener.
		 */
		typedef std::function<void (const Message::ptr)> m_channel_post_listener_element;
		/**
		 * @var m_edited_channel_post_listener_element
		 * @brief An element which is added to the proper listener.
		 */
		typedef std::function<void (const Message::ptr)> m_edited_channel_post_listener_element;
		/**
		 * @var m_inline_query_listener_element
		 * @brief An element which is added to the proper listener.
		 */
		typedef std::function<void (const InlineQuery::ptr)> m_inline_query_listener_element;
		/**
		 * @var m_chosen_inline_result_listener_element
		 * @brief An element which is added to the proper listener.
		 */
		typedef std::function<void (const ChosenInlineResult::ptr)> m_chosen_inline_result_listener_element;
		/**
		 * @var m_callback_query_listener_element
		 * @brief An element which is added to the proper listener.
		 */
		typedef std::function<void (const CallbackQuery::ptr)> m_callback_query_listener_element;
		/**
		 * @var m_shipping_query_listener_element
		 * @brief An element which is added to the proper listener.
		 */
		typedef std::function<void (const ShippingQuery::ptr)> m_shipping_query_listener_element;
		/**
		 * @var m_pre_checkout_query_listener_element
		 * @brief An element which is added to the proper listener.
		 */
		typedef std::function<void (const PreCheckoutQuery::ptr)> m_pre_checkout_query_listener_element;
		/**
		 * @var m_poll_listener_element
		 * @brief An element which is added to the proper listener.
		 */
		typedef std::function<void (const Poll::ptr)> m_poll_listener_element;
		/**
		 * @var m_poll_answer_listener_element
		 * @brief An element which is added to the proper listener.
		 */
		typedef std::function<void (const PollAnswer::ptr)> m_poll_answer_listener_element;
		//Vectors of listeners
		/**
		 * @var m_on_any_msg_listener_ls
		 * @brief A collection of all function which are executed when a certain event is triggered.
		 */
		std::vector<m_message_listener_element> m_on_any_msg_listener_ls;
		/**
		 * @var m_on_cmd_listener_ls
		 * @brief A collection of all function which are executed when a certain event is triggered.
		 */
		std::unordered_map<std::string, m_message_listener_element> m_on_cmd_listener_ls;
		/**
		 * @var m_on_unknwn_cmd_listener_ls
		 * @brief A collection of all function which are executed when a certain event is triggered.
		 */
		std::vector<m_message_listener_element> m_on_unknwn_cmd_listener_ls;
		/**
		 * @var m_on_non_cmd_msg_listener_ls
		 * @brief A collection of all function which are executed when a certain event is triggered.
		 */
		std::vector<m_message_listener_element> m_on_non_cmd_msg_listener_ls;
		/**
		 * @var m_on_inline_query_listener_ls
		 * @brief A collection of all function which are executed when a certain event is triggered.
		 */
		std::vector<m_inline_query_listener_element> m_on_inline_query_listener_ls;
		/**
		 * @var m_on_chosen_inline_result_listener_ls
		 * @brief A collection of all function which are executed when a certain event is triggered.
		 */
		std::vector<m_chosen_inline_result_listener_element> m_on_chosen_inline_result_listener_ls;
		/**
		 * @var m_on_callback_query_listener_ls
		 * @brief A collection of all function which are executed when a certain event is triggered.
		 */
		std::vector<m_callback_query_listener_element> m_on_callback_query_listener_ls;
		/**
		 * @var m_on_shipping_query_listener_ls
		 * @brief A collection of all function which are executed when a certain event is triggered.
		 */
		std::vector<m_shipping_query_listener_element> m_on_shipping_query_listener_ls;
		/**
		 * @var m_pre_checkout_query_listener_ls
		 * @brief A collection of all function which are executed when a certain event is triggered.
		 */
		std::vector<m_pre_checkout_query_listener_element> m_pre_checkout_query_listener_ls;
		/**
		 * @var m_poll_listener_ls
		 * @brief A collection of all function which are executed when a certain event is triggered.
		 */
		std::vector<m_poll_listener_element> m_poll_listener_ls;
		/**
		 * @var m_poll_answer_listener_ls
		 * @brief A collection of all function which are executed when a certain event is triggered.
		 */
		std::vector<m_poll_answer_listener_element> m_poll_answer_listener_ls;

	public:
		//Constructors
		EventHandler(const std::string &token);

		//Member functions
		/**
		 * @brief Gets the updated for the bot and handles them.
		 * @details Needs to be run in an endless loop to react on new incoming updates constantly.
		 */
		void long_poll() noexcept;

	private:
		/**
		 * @brief Checks the kind of incoming update and then executes the suitable listener list.
		 * @param[in] update An update object which is handled.
		 */
		void handle_update(const Update::ptr &update) const noexcept;

	public:
		/**
		 * @brief Adds the listener to proper lister list.
		 * @param[in] listener_element Listener to add.
		 */
		void on_any_msg(const m_message_listener_element &listener_element) noexcept;

		/**
		 * @brief Adds the listener to proper lister list.
		 * @param[in] listener_element Listener to add.
		 */
		void on_cmd(const std::string &cmd, const m_message_listener_element &listener_element) noexcept;

		/**
		 * @brief Adds the listener to proper lister list.
		 * @param[in] listener_element Listener to add.
		 */
		void on_unknwn_cmd(const m_message_listener_element &listener_element) noexcept;

		/**
		 * @brief Adds the listener to proper lister list.
		 * @param[in] listener_element Listener to add.
		 */
		void on_non_cmd_msg(const m_message_listener_element &listener_element) noexcept;

		/**
		 * @brief Adds the listener to proper lister list.
		 * @param[in] listener_element Listener to add.
		 */
		void on_inline_query(const m_inline_query_listener_element &listener_element) noexcept;

		/**
		 * @brief Adds the listener to proper lister list.
		 * @param[in] listener_element Listener to add.
		 */
		void on_chosen_inline_result(const m_chosen_inline_result_listener_element &listener_element) noexcept;

		/**
		 * @brief Adds the listener to proper lister list.
		 * @param[in] listener_element Listener to add.
		 */
		void on_callback_query(const m_callback_query_listener_element &listener_element) noexcept;

		/**
		 * @brief Adds the listener to proper lister list.
		 * @param[in] listener_element Listener to add.
		 */
		void on_shipping_query(const m_shipping_query_listener_element &listener_element) noexcept;

		/**
		 * @brief Adds the listener to proper lister list.
		 * @param[in] listener_element Listener to add.
		 */
		void on_pre_checkout_query(const m_pre_checkout_query_listener_element &listener_element) noexcept;

		/**
		 * @brief Adds the listener to proper lister list.
		 * @param[in] listener_element Listener to add.
		 */
		void on_poll(const m_poll_listener_element &listener_element) noexcept;

		/**
		 * @brief Adds the listener to proper lister list.
		 * @param[in] listener_element Listener to add.
		 */
		void on_poll_answer(const m_poll_answer_listener_element &listener_element) noexcept;
	};
}

#endif
