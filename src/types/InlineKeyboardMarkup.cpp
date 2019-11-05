#include "tgbot/types/InlineKeyboardMarkup.h"
#include <iostream>

namespace tgbot
{
	InlineKeyboardMarkup::InlineKeyboardMarkup() : inline_keyboard()
	{}

	InlineKeyboardMarkup::InlineKeyboardMarkup(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("inline_keyboard"))
			for(std::size_t row = 0; row < doc["inline_keyboard"].GetArray().Size(); ++row)
			{
				const rapidjson::Value &keyboard_array = doc["inline_keyboard"].GetArray();

				//reserve enough rows
				inline_keyboard.resize(keyboard_array.Size());

				//reserve enough columns for each row
				inline_keyboard.at(row).resize(keyboard_array[row].GetArray().Size());

				for(std::size_t column = 0; column < keyboard_array[row].GetArray().Size(); ++column)
					inline_keyboard.at(row).at(column) = std::make_shared<InlineKeyboardButton>(SpecialTools::get_json_obj_as_string(keyboard_array[row][column]));
			}
	}

	InlineKeyboardMarkup::InlineKeyboardMarkup(const std::vector<std::vector<InlineKeyboardButton::ptr>> &keyboard) : inline_keyboard(keyboard)
	{}

	std::string InlineKeyboardMarkup::parse_to_json() const
	{
		std::string json = "{\"inline_keyboard\": [";

		//rows
		for(size_t j = 0; j < inline_keyboard.size(); ++j)
		{
			json.append("[");

			//columns in row
			for(size_t k = 0; k < inline_keyboard.at(j).size(); ++k)
			{
				//button text is stated
				json.append("{");
				json.append("\"text\": \"" + inline_keyboard.at(j).at(k)->text + "\"");
				json.append(", ");

				//option is stated
				if(!inline_keyboard.at(j).at(k)->url.empty())
				{
					json.append("\"url\": \"" + inline_keyboard.at(j).at(k)->url + "\"");
					json.append("}");
				}
				else if(inline_keyboard.at(j).at(k)->login_url != nullptr)
				{
					//login_url json object
					json.append("{");
					json.append("\"url\": \"" + inline_keyboard.at(j).at(k)->login_url->url + "\", ");
					json.append("\"forward_text\": \"" + inline_keyboard.at(j).at(k)->login_url->forward_text + "\", ");
					json.append("\"bot_username\": \"" + inline_keyboard.at(j).at(k)->login_url->bot_username + "\", ");
					std::string request_write_access_bool = inline_keyboard.at(j).at(k)->login_url->request_write_access ? "true" : "false";
					json.append("\"request_write_access\": \"" + request_write_access_bool + "\"");
					json.append("}");


					json.append("}");
				}
				else if(!inline_keyboard.at(j).at(k)->callback_data.empty())
				{
					json.append("\"callback_data\": \"" + inline_keyboard.at(j).at(k)->callback_data + "\"");
					json.append("}");
				}
				else if(!inline_keyboard.at(j).at(k)->switch_inline_query.empty())
				{
					json.append("\"switch_inline_query\": \"" + inline_keyboard.at(j).at(k)->switch_inline_query + "\"");
					json.append("}");
				}
				else if(!inline_keyboard.at(j).at(k)->switch_inline_query_current_chat.empty())
				{
					json.append("\"switch_inline_query_current_chat\": \"" + inline_keyboard.at(j).at(k)->switch_inline_query_current_chat + "\"");
					json.append("}");
				}
				else if(inline_keyboard.at(j).at(k)->callback_game != nullptr)
				{
					//callback_game json object
					json.append("{");
					json.append("}");


					json.append("}");
				}
				else if(inline_keyboard.at(j).at(k)->pay)
				{
					std::string pay_bool = inline_keyboard.at(j).at(k)->pay ? "true" : "false";
					json.append("\"pay\": \"" + pay_bool + "\"");
					json.append("}");
				}

				//add comma between several json objects in a single row
				//the condition equals last iteration
				if(k != (inline_keyboard.at(j).size() - 1))
					json.append(", ");
			}
			json.append("], ");
		}

		//remove ", "
		if(json.size() > 0)
		{
			json.pop_back();
			json.pop_back();
		}

		json.append("]}");

		return json;
	}
}
