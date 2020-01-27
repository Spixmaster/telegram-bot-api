#include "tgbot/types/Update.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	Update::Update() : update_id(), message(), edited_message(), channel_post(), edited_channel_post(), inline_query(), chosen_inline_result(), callback_query(),
			shipping_query(), pre_checkout_query(), poll(), poll_answer()
	{}

	Update::Update(std::string json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("update_id"))
			{
				if(doc["update_id"].IsInt())
					update_id = doc["update_id"].GetInt();
				else
					std::cerr << "Error: Field \"update_id\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("message"))
			{
				if(doc["message"].IsObject())
					message = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["message"]));
				else
					std::cerr << "Error: Field \"message\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("edited_message"))
			{
				if(doc["edited_message"].IsObject())
					edited_message = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["edited_message"]));
				else
					std::cerr << "Error: Field \"edited_message\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("channel_post"))
			{
				if(doc["channel_post"].IsObject())
					channel_post = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["channel_post"]));
				else
					std::cerr << "Error: Field \"channel_post\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("edited_channel_post"))
			{
				if(doc["edited_channel_post"].IsObject())
					edited_channel_post = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["edited_channel_post"]));
				else
					std::cerr << "Error: Field \"edited_channel_post\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("inline_query"))
			{
				if(doc["inline_query"].IsObject())
					inline_query = std::make_shared<InlineQuery>(tools::Tools::get_json_as_string(doc["inline_query"]));
				else
					std::cerr << "Error: Field \"inline_query\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("chosen_inline_result"))
			{
				if(doc["chosen_inline_result"].IsObject())
					chosen_inline_result = std::make_shared<ChosenInlineResult>(tools::Tools::get_json_as_string(doc["chosen_inline_result"]));
				else
					std::cerr << "Error: Field \"chosen_inline_result\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("callback_query"))
			{
				if(doc["callback_query"].IsObject())
					callback_query = std::make_shared<CallbackQuery>(tools::Tools::get_json_as_string(doc["callback_query"]));
				else
					std::cerr << "Error: Field \"callback_query\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("shipping_query"))
			{
				if(doc["shipping_query"].IsObject())
					shipping_query = std::make_shared<ShippingQuery>(tools::Tools::get_json_as_string(doc["shipping_query"]));
				else
					std::cerr << "Error: Field \"shipping_query\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("pre_checkout_query"))
			{
				if(doc["pre_checkout_query"].IsObject())
					pre_checkout_query = std::make_shared<PreCheckoutQuery>(tools::Tools::get_json_as_string(doc["pre_checkout_query"]));
				else
					std::cerr << "Error: Field \"pre_checkout_query\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("poll"))
			{
				if(doc["poll"].IsObject())
					poll = std::make_shared<Poll>(tools::Tools::get_json_as_string(doc["poll"]));
				else
					std::cerr << "Error: Field \"poll\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("poll_answer"))
			{
				if(doc["poll_answer"].IsObject())
					poll_answer = std::make_shared<PollAnswer>(tools::Tools::get_json_as_string(doc["poll_answer"]));
				else
					std::cerr << "Error: Field \"poll_answer\" does not contain a json object." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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
		json.append(", ");

		//field poll_answer
		json.append("\"poll_answer\": " + poll_answer->parse_to_json());

		json.append("}");

		return json;
	}
}
