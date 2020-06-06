#include "tgbot/types/InlineKeyboardMarkup.h"
#include <iostream>
#include "tools/Tools.h"
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InlineKeyboardMarkup::InlineKeyboardMarkup() : inline_keyboard()
	{}

	InlineKeyboardMarkup::InlineKeyboardMarkup(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("inline_keyboard"))
			{
				if(doc["inline_keyboard"].IsArray())
				{
					const rapidjson::Value &keyboard_array = doc["inline_keyboard"].GetArray();

					//Reserve enough rows.
					inline_keyboard.resize(keyboard_array.Size());

					for(std::size_t row = 0; row < doc["inline_keyboard"].GetArray().Size(); ++row)
					{
						if(keyboard_array[row].IsArray())
						{
							//Reserve enough columns for each row.
							inline_keyboard.at(row).resize(keyboard_array[row].GetArray().Size());

							for(std::size_t column = 0; column < keyboard_array[row].GetArray().Size(); ++column)
							{
								if(keyboard_array[row][column].IsObject())
									inline_keyboard.at(row).at(column) = std::make_shared<InlineKeyboardButton>(tools::Tools::get_json_as_string(keyboard_array[row][column]));
								else
									tools::Tools::write_err_log(Messages::field_element_element_does_not_contain_json_obj("inline_keyboard"));
							}
						}
						else
							tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("inline_keyboard"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("inline_keyboard"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	InlineKeyboardMarkup::InlineKeyboardMarkup(const std::vector<std::vector<InlineKeyboardButton::ptr>> &keyboard) : inline_keyboard(keyboard)
	{}

	std::string InlineKeyboardMarkup::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field inline_keyboard
		std::string inline_keyboard_cont = "[";

		//Rows
		for(std::size_t j = 0; j < inline_keyboard.size(); ++j)
		{
			inline_keyboard_cont.append("[");

			//Columns in row
			for(std::size_t k = 0; k < inline_keyboard.at(j).size(); ++k)
			{
				inline_keyboard_cont.append("{");
				inline_keyboard_cont.append("\"text\": \"" + inline_keyboard.at(j).at(k)->text + "\"");
				inline_keyboard_cont.append(", ");

				if(!inline_keyboard.at(j).at(k)->url.empty())
				{
					inline_keyboard_cont.append("\"url\": \"" + inline_keyboard.at(j).at(k)->url + "\"");
					inline_keyboard_cont.append("}");
				}
				else if(inline_keyboard.at(j).at(k)->login_url != nullptr)
				{
					//login_url
					inline_keyboard_cont.append("{");
					inline_keyboard_cont.append("\"url\": \"" + inline_keyboard.at(j).at(k)->login_url->url + "\", ");
					inline_keyboard_cont.append("\"forward_text\": \"" + inline_keyboard.at(j).at(k)->login_url->forward_text + "\", ");
					inline_keyboard_cont.append("\"bot_username\": \"" + inline_keyboard.at(j).at(k)->login_url->bot_username + "\", ");
					std::string request_write_access_bool = inline_keyboard.at(j).at(k)->login_url->request_write_access ? "true" : "false";
					inline_keyboard_cont.append("\"request_write_access\": " + request_write_access_bool);
					inline_keyboard_cont.append("}");

					inline_keyboard_cont.append("}");
				}
				else if(!inline_keyboard.at(j).at(k)->callback_data.empty())
				{
					inline_keyboard_cont.append("\"callback_data\": \"" + inline_keyboard.at(j).at(k)->callback_data + "\"");
					inline_keyboard_cont.append("}");
				}
				else if(!inline_keyboard.at(j).at(k)->switch_inline_query.empty())
				{
					inline_keyboard_cont.append("\"switch_inline_query\": \"" + inline_keyboard.at(j).at(k)->switch_inline_query + "\"");
					inline_keyboard_cont.append("}");
				}
				else if(!inline_keyboard.at(j).at(k)->switch_inline_query_current_chat.empty())
				{
					inline_keyboard_cont.append("\"switch_inline_query_current_chat\": \"" + inline_keyboard.at(j).at(k)->switch_inline_query_current_chat + "\"");
					inline_keyboard_cont.append("}");
				}
				else if(inline_keyboard.at(j).at(k)->callback_game != nullptr)
				{
					inline_keyboard_cont.append("{");
					json.append("}");

					inline_keyboard_cont.append("}");
				}
				else if(inline_keyboard.at(j).at(k)->pay)
				{
					std::string pay_bool = inline_keyboard.at(j).at(k)->pay ? "true" : "false";
					inline_keyboard_cont.append("\"pay\": " + pay_bool);
					inline_keyboard_cont.append("}");
				}

				if(k != inline_keyboard.at(j).size() - 1)
					inline_keyboard_cont.append(", ");
			}

			inline_keyboard_cont.append("]");

			if(j != inline_keyboard.size() - 1)
				inline_keyboard_cont.append(", ");
		}

		inline_keyboard_cont.append("]");

		json.append("\"inline_keyboard\": " + inline_keyboard_cont);

		json.append("}");
		return json;
	}
}
