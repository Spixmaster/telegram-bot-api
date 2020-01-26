#include "tgbot/types/InlineKeyboardMarkup.h"
#include <iostream>
#include "tools/Tools.h"

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
			//assignments
			if(doc.HasMember("inline_keyboard"))
				if(doc["inline_keyboard"].IsArray())
				{
					const rapidjson::Value &keyboard_array = doc["inline_keyboard"].GetArray();

					//reserve enough rows
					inline_keyboard.resize(keyboard_array.Size());

					for(std::size_t row = 0; row < doc["inline_keyboard"].GetArray().Size(); ++row)
					{
						if(keyboard_array[row].IsArray())
						{
							//reserve enough columns for each row
							inline_keyboard.at(row).resize(keyboard_array[row].GetArray().Size());

							for(std::size_t column = 0; column < keyboard_array[row].GetArray().Size(); ++column)
							{
								if(keyboard_array[row][column].IsObject())
									inline_keyboard.at(row).at(column) = std::make_shared<InlineKeyboardButton>(tools::Tools::get_json_as_string(keyboard_array[row][column]));
								else
									std::cerr << "Error: Field \"inline_keyboard\"'s json array's array element is not a json object." << std::endl;
							}
						}
						else
							std::cerr << "Error: Field \"inline_keyboard\"'s json array does not contain a json array." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"inline_keyboard\" does not contain a json array." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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
