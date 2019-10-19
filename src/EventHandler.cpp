#include <tgbot/Tools.h>
#include "tgbot/EventHandler.h"

namespace tgbot
{
	EventHandler::EventHandler(const std::string &token) : m_endpnts(std::make_shared<Endpoints>(token))
	{}

	void EventHandler::long_poll()
	{
		std::vector<Update::ptr> updates = m_endpnts->getUpdates(m_offset);

		//iterate through all the updates
		for(std::size_t j = 0; j < updates.size(); ++j)
		{
			m_offset = updates.at(j)->update_id + 1;
			handle_update(updates.at(j));
		}
	}

	void EventHandler::handle_update(const Update::ptr &update)
	{
		if (update->message != nullptr || update->edited_message != nullptr || update->channel_post != nullptr || update->edited_channel_post != nullptr)
		{
			if(update->message != nullptr)
			{
				//any message
				for(std::size_t j = 0; j < m_on_any_msg_listener_ls.size(); ++j)
				{
					m_message_listener_element element = m_on_any_msg_listener_ls.at(j);
					element(update->message);
				}

				//see whether command
				if(Tools::starts_w(update->message->text, "/"))
				{
					//get argument 0
					std::vector<std::string> args = Tools::get_args(update->message->text);
					//cut off first char
					std::string cmd = Tools::cut_off_first_char(args.at(0));

					//known command
					if(!(m_on_cmd_listener_ls.find(cmd) == m_on_cmd_listener_ls.end()))
						m_on_cmd_listener_ls.find(cmd)->second(update->message);
					//unknown command
					else
					{
						for(std::size_t j = 0; j < m_on_unknwn_cmd_listener_ls.size(); ++j)
						{
							m_message_listener_element element = m_on_unknwn_cmd_listener_ls.at(j);
							element(update->message);
						}
					}
				}
				//non command message
				else
				{
					for(std::size_t j = 0; j < m_on_non_cmd_msg_listener_ls.size(); ++j)
					{
						m_message_listener_element element = m_on_non_cmd_msg_listener_ls.at(j);
						element(update->message);
					}
				}
			}
			else if(update->edited_message != nullptr)
			{
				//any message
				for(std::size_t j = 0; j < m_on_any_msg_listener_ls.size(); ++j)
				{
					m_message_listener_element element = m_on_any_msg_listener_ls.at(j);
					element(update->edited_message);
				}

				//see whether command
				if(Tools::starts_w(update->edited_message->text, "/"))
				{
					//get argument 0
					std::vector<std::string> args = Tools::get_args(update->edited_message->text);
					//cut off first char
					std::string cmd = Tools::cut_off_first_char(args.at(0));

					//known command
					if(!(m_on_cmd_listener_ls.find(cmd) == m_on_cmd_listener_ls.end()))
						m_on_cmd_listener_ls.find(cmd)->second(update->edited_message);
					//unknown command
					else
					{
						for(std::size_t j = 0; j < m_on_unknwn_cmd_listener_ls.size(); ++j)
						{
							m_message_listener_element element = m_on_unknwn_cmd_listener_ls.at(j);
							element(update->edited_message);
						}
					}
				}
				//non command message
				else
				{
					for(std::size_t j = 0; j < m_on_non_cmd_msg_listener_ls.size(); ++j)
					{
						m_message_listener_element element = m_on_non_cmd_msg_listener_ls.at(j);
						element(update->edited_message);
					}
				}
			}
			else if(update->channel_post != nullptr)
			{
				//any message
				for(std::size_t j = 0; j < m_on_any_msg_listener_ls.size(); ++j)
				{
					m_message_listener_element element = m_on_any_msg_listener_ls.at(j);
					element(update->channel_post);
				}

				//see whether command
				if(Tools::starts_w(update->channel_post->text, "/"))
				{
					//get argument 0
					std::vector<std::string> args = Tools::get_args(update->channel_post->text);
					//cut off first char
					std::string cmd = Tools::cut_off_first_char(args.at(0));

					//known command
					if(!(m_on_cmd_listener_ls.find(cmd) == m_on_cmd_listener_ls.end()))
						m_on_cmd_listener_ls.find(cmd)->second(update->channel_post);
					//unknown command
					else
					{
						for(std::size_t j = 0; j < m_on_unknwn_cmd_listener_ls.size(); ++j)
						{
							m_message_listener_element element = m_on_unknwn_cmd_listener_ls.at(j);
							element(update->channel_post);
						}
					}
				}
				//non command message
				else
				{
					for(std::size_t j = 0; j < m_on_non_cmd_msg_listener_ls.size(); ++j)
					{
						m_message_listener_element element = m_on_non_cmd_msg_listener_ls.at(j);
						element(update->channel_post);
					}
				}
			}
			else if(update->edited_channel_post != nullptr)
			{
				//any message
				for(std::size_t j = 0; j < m_on_any_msg_listener_ls.size(); ++j)
				{
					m_message_listener_element element = m_on_any_msg_listener_ls.at(j);
					element(update->edited_channel_post);
				}

				//see whether command
				if(Tools::starts_w(update->edited_channel_post->text, "/"))
				{
					//get argument 0
					std::vector<std::string> args = Tools::get_args(update->edited_channel_post->text);
					//cut off first char
					std::string cmd = Tools::cut_off_first_char(args.at(0));

					//known command
					if(!(m_on_cmd_listener_ls.find(cmd) == m_on_cmd_listener_ls.end()))
						m_on_cmd_listener_ls.find(cmd)->second(update->edited_channel_post);
					//unknown command
					else
					{
						for(std::size_t j = 0; j < m_on_unknwn_cmd_listener_ls.size(); ++j)
						{
							m_message_listener_element element = m_on_unknwn_cmd_listener_ls.at(j);
							element(update->edited_channel_post);
						}
					}
				}
				//non command message
				else
				{
					for(std::size_t j = 0; j < m_on_non_cmd_msg_listener_ls.size(); ++j)
					{
						m_message_listener_element element = m_on_non_cmd_msg_listener_ls.at(j);
						element(update->edited_channel_post);
					}
				}
			}
		}
		else if (update->inline_query != nullptr)
		{
			for(std::size_t j = 0; j < m_on_inline_query_listener_ls.size(); ++j)
			{
				m_inline_query_listener_element element = m_on_inline_query_listener_ls.at(j);
				element(update->inline_query);
			}
		}
		else if (update->chosen_inline_result != nullptr)
		{
			for(std::size_t j = 0; j < m_on_chosen_inline_result_listener_ls.size(); ++j)
			{
				m_chosen_inline_result_listener_element element = m_on_chosen_inline_result_listener_ls.at(j);
				element(update->chosen_inline_result);
			}
		}
		else if (update->callback_query != nullptr)
		{
			for(std::size_t j = 0; j < m_on_callback_query_listener_ls.size(); ++j)
			{
				m_callback_query_listener_element element = m_on_callback_query_listener_ls.at(j);
				element(update->callback_query);
			}
		}
		else if (update->shipping_query != nullptr)
		{
			for(std::size_t j = 0; j < m_on_shipping_query_listener_ls.size(); ++j)
			{
				m_shipping_query_listener_element element = m_on_shipping_query_listener_ls.at(j);
				element(update->shipping_query);
			}
		}
		else if (update->pre_checkout_query != nullptr)
		{
			for(std::size_t j = 0; j < m_pre_checkout_query_listener_ls.size(); ++j)
			{
				m_pre_checkout_query_listener_element element = m_pre_checkout_query_listener_ls.at(j);
				element(update->pre_checkout_query);
			}
		}
		else if (update->poll != nullptr)
		{
			for(std::size_t j = 0; j < m_poll_listener_ls.size(); ++j)
			{
				m_poll_listener_element element = m_poll_listener_ls.at(j);
				element(update->poll);
			}
		}
	}

	void EventHandler::on_any_msg(const m_message_listener_element &listener_element)
	{
		m_on_any_msg_listener_ls.push_back(listener_element);
	}

	void EventHandler::on_cmd(const std::string &cmd, const m_message_listener_element &listener_element)
	{
		m_on_cmd_listener_ls[cmd] = listener_element;
	}

	void EventHandler::on_unknwn_cmd(const m_message_listener_element &listener_element)
	{
		m_on_unknwn_cmd_listener_ls.push_back(listener_element);
	}

	void EventHandler::on_non_cmd_msg(const m_message_listener_element &listener_element)
	{
		m_on_non_cmd_msg_listener_ls.push_back(listener_element);
	}

	void EventHandler::on_inline_query(const m_inline_query_listener_element &listener_element)
	{
		m_on_inline_query_listener_ls.push_back(listener_element);
	}

	void EventHandler::on_chosen_inline_result(const m_chosen_inline_result_listener_element &listener_element)
	{
		m_on_chosen_inline_result_listener_ls.push_back(listener_element);
	}

	void EventHandler::on_callback_query(const m_callback_query_listener_element &listener_element)
	{
		m_on_callback_query_listener_ls.push_back(listener_element);
	}

	void EventHandler::on_shipping_query(const m_shipping_query_listener_element &listener_element)
	{
		m_on_shipping_query_listener_ls.push_back(listener_element);
	}

	void EventHandler::on_pre_checkout_query(const m_pre_checkout_query_listener_element &listener_element)
	{
		m_pre_checkout_query_listener_ls.push_back(listener_element);
	}

	void EventHandler::on_poll_query(const m_poll_listener_element &listener_element)
	{
		m_poll_listener_ls.push_back(listener_element);
	}
}

