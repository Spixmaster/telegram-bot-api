#include "tgbot/types/Update.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	Update::Update() : update_id(), message(), edited_message(), channel_post(), edited_channel_post(), inline_query(), chosen_inline_result(), callback_query(),
			shipping_query(), pre_checkout_query(), poll()
	{}

	Update::Update(std::string json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("update_id"))
				update_id = doc["update_id"].GetInt();

			if(doc.HasMember("message"))
				message = std::make_shared<Message>(SpecialTools::get_json_as_string(doc["message"]));

			if(doc.HasMember("edited_message"))
				edited_message = std::make_shared<Message>(SpecialTools::get_json_as_string(doc["edited_message"]));

			if(doc.HasMember("channel_post"))
				channel_post = std::make_shared<Message>(SpecialTools::get_json_as_string(doc["channel_post"]));

			if(doc.HasMember("edited_channel_post"))
				edited_channel_post = std::make_shared<Message>(SpecialTools::get_json_as_string(doc["edited_channel_post"]));

			if(doc.HasMember("inline_query"))
				inline_query = std::make_shared<InlineQuery>(SpecialTools::get_json_as_string(doc["inline_query"]));

			if(doc.HasMember("chosen_inline_result"))
				chosen_inline_result = std::make_shared<ChosenInlineResult>(SpecialTools::get_json_as_string(doc["chosen_inline_result"]));

			if(doc.HasMember("callback_query"))
				callback_query = std::make_shared<CallbackQuery>(SpecialTools::get_json_as_string(doc["callback_query"]));

			if(doc.HasMember("shipping_query"))
				shipping_query = std::make_shared<ShippingQuery>(SpecialTools::get_json_as_string(doc["shipping_query"]));

			if(doc.HasMember("pre_checkout_query"))
				pre_checkout_query = std::make_shared<PreCheckoutQuery>(SpecialTools::get_json_as_string(doc["pre_checkout_query"]));

			if(doc.HasMember("poll"))
				poll = std::make_shared<Poll>(SpecialTools::get_json_as_string(doc["poll"]));
		}
	}

	std::string Update::parse_to_json() const
	{
		std::string json = "{";

		//field update_id
		json.append("\"update_id\": " + update_id);
		json.append(", ");

		//field message
		json.append("\"message\": " + message->parse_to_json());
		json.append(", ");

		//field edited_message
		json.append("\"edited_message\": " + edited_message->parse_to_json());
		json.append(", ");

		//field channel_post
		json.append("\"channel_post\": " + channel_post->parse_to_json());
		json.append(", ");

		//field edited_channel_post
		json.append("\"edited_channel_post\": " + edited_channel_post->parse_to_json());
		json.append(", ");

		//field inline_query
		json.append("\"inline_query\": " + inline_query->parse_to_json());
		json.append(", ");

		//field chosen_inline_result
		json.append("\"chosen_inline_result\": " + chosen_inline_result->parse_to_json());
		json.append(", ");

		//field callback_query
		json.append("\"callback_query\": " + callback_query->parse_to_json());
		json.append(", ");

		//field shipping_query
		json.append("\"shipping_query\": " + shipping_query->parse_to_json());
		json.append(", ");

		//field pre_checkout_query
		json.append("\"pre_checkout_query\": " + pre_checkout_query->parse_to_json());
		json.append(", ");

		//field poll
		json.append("\"poll\": " + poll->parse_to_json());

		json.append("}");

		return json;
	}
}
