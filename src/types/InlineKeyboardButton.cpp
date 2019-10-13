#include "tgbot/types/InlineKeyboardButton.h"

namespace tgbot
{
	InlineKeyboardButton::InlineKeyboardButton() : text(), url(), login_url(), callback_data(), switch_inline_query(), switch_inline_query_current_chat(),
	callback_game(), pay()
	{}

	InlineKeyboardButton::InlineKeyboardButton(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("text"))
			text = doc["text"].GetString();

		if(doc.HasMember("url"))
			url = doc["url"].GetString();

		if(doc.HasMember("login_url"))
			login_url = std::make_shared<LoginUrl>(SpecialTools::get_json_obj_as_string(doc["login_url"]));

		if(doc.HasMember("callback_data"))
			callback_data = doc["callback_data"].GetString();

		if(doc.HasMember("switch_inline_query"))
			switch_inline_query = doc["switch_inline_query"].GetString();

		if(doc.HasMember("switch_inline_query_current_chat"))
			switch_inline_query_current_chat = doc["switch_inline_query_current_chat"].GetString();

		if(doc.HasMember("callback_game"))
			callback_game = std::make_shared<CallbackGame>();

		if(doc.HasMember("pay"))
			pay = doc["pay"].GetBool();
	}

	std::string InlineKeyboardButton::parse_to_json() const
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
		json.append("\"thumb\": \"" + switch_inline_query + "\"");
		json.append(", ");

		//field switch_inline_query_current_chat
		json.append("\"switch_inline_query_current_chat\": \"" + switch_inline_query_current_chat + "\"");
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
