#include "tgbot/types/InlineKeyboardButton.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InlineKeyboardButton::InlineKeyboardButton() : text(), url(), login_url(), callback_data(), switch_inline_query(), switch_inline_query_current_chat(),
	callback_game(), pay()
	{}

	InlineKeyboardButton::InlineKeyboardButton(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("text"))
			{
				if(doc["text"].IsString())
					text = doc["text"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("text") << std::endl;
			}

			if(doc.HasMember("url"))
			{
				if(doc["url"].IsString())
					url = doc["url"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("url") << std::endl;
			}

			if(doc.HasMember("login_url"))
			{
				if(doc["login_url"].IsObject())
					login_url = std::make_shared<LoginUrl>(tools::Tools::get_json_as_string(doc["login_url"]));
				else
					std::cerr << Messages::field_does_not_contain_json_obj("login_url") << std::endl;
			}

			if(doc.HasMember("callback_data"))
			{
				if(doc["callback_data"].IsString())
					callback_data = doc["callback_data"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("callback_data") << std::endl;
			}

			if(doc.HasMember("switch_inline_query"))
			{
				if(doc["switch_inline_query"].IsString())
					switch_inline_query = doc["switch_inline_query"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("switch_inline_query") << std::endl;
			}

			if(doc.HasMember("switch_inline_query_current_chat"))
			{
				if(doc["switch_inline_query_current_chat"].IsString())
					switch_inline_query_current_chat = doc["switch_inline_query_current_chat"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("switch_inline_query_current_chat") << std::endl;
			}

			if(doc.HasMember("callback_game"))
			{
				if(doc["callback_game"].IsObject())
					callback_game = std::make_shared<CallbackGame>(tools::Tools::get_json_as_string(doc["callback_game"]));
				else
					std::cerr << Messages::field_does_not_contain_json_obj("callback_game") << std::endl;
			}

			if(doc.HasMember("pay"))
			{
				if(doc["pay"].IsBool())
					pay = doc["pay"].GetBool();
				else
					std::cerr << Messages::field_does_not_contain_bool("pay") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string InlineKeyboardButton::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field text
		json.append("\"text\": \"" + text + "\"");
		json.append(", ");

		//field url
		json.append("\"url\": \"" + url + "\"");
		json.append(", ");

		//field login_url
		json.append("\"login_url\": " + login_url->parse_to_json());
		json.append(", ");

		//field callback_data
		json.append("\"callback_data\": \"" + callback_data + "\"");
		json.append(", ");

		//field switch_inline_query
		json.append("\"switch_inline_query\": " + switch_inline_query);
		json.append(", ");

		//field switch_inline_query_current_chat
		json.append("\"switch_inline_query_current_chat\": " + switch_inline_query_current_chat);
		json.append(", ");

		//field callback_game
		json.append("\"callback_game\": " + callback_game->parse_to_json());
		json.append(", ");

		//field pay
		std::string pay_bool = pay ? "true" : "false";
		json.append("\"pay\": " + pay_bool);

		json.append("}");

		return json;
	}
}
