#include <tgbot/SpecialTools.h>
#include "tgbot/types/Chat.h"
#include "tgbot/types/Message.h"

namespace tgbot
{
	Message::Message() : message_id(), from(), date() , chat(), forward_from(), forward_from_chat(), forward_from_message_id(), forward_signature(), forward_sender_name(),
			forward_date(), reply_to_message(), edit_date(), media_group_id(), author_signature(), text(), entities(), caption_entities(), audio(), document(),
			animation(), game(), photo(), sticker(), video(), voice(), video_note(), caption(), contact(), location(), venue(), poll(), new_chat_members(),
			left_chat_member(), new_chat_title(), delete_chat_photo(), group_chat_created(), supergroup_chat_created(),channel_chat_created(), migrate_to_chat_id(),
			migrate_from_chat_id(), pinned_message(), invoice(), successful_payment(), connected_website(), passport_data(), reply_markup()
	{}

	Message::Message(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("message_id"))
			message_id = doc["message_id"].GetInt();

		if(doc.HasMember("from"))
			from = std::make_shared<User>(SpecialTools::get_json_obj_as_string(doc["from"]));

		if(doc.HasMember("date"))
			date = doc["date"].GetInt();

		if(doc.HasMember("chat"))
			chat = std::make_shared<Chat>(SpecialTools::get_json_obj_as_string(doc["chat"]));

		if(doc.HasMember("forward_from"))
			forward_from = std::make_shared<User>(SpecialTools::get_json_obj_as_string(doc["forward_from"]));

		if(doc.HasMember("forward_from_chat"))
			forward_from_chat = std::make_shared<Chat>(SpecialTools::get_json_obj_as_string(doc["forward_from_chat"]));

		if(doc.HasMember("forward_from_message_id"))
			forward_from_message_id = doc["forward_from_message_id"].GetInt();

		if(doc.HasMember("forward_signature"))
			forward_signature = doc["forward_signature"].GetString();

		if(doc.HasMember("forward_sender_name"))
			forward_sender_name = doc["forward_sender_name"].GetString();

		if(doc.HasMember("forward_date"))
			forward_date = doc["forward_date"].GetInt();

		if(doc.HasMember("reply_to_message"))
			reply_to_message = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["reply_to_message"]));

		if(doc.HasMember("edit_date"))
			edit_date = doc["edit_date"].GetInt();

		if(doc.HasMember("media_group_id"))
			media_group_id = doc["media_group_id"].GetString();

		if(doc.HasMember("author_signature"))
			author_signature = doc["author_signature"].GetString();

		if(doc.HasMember("text"))
			text = doc["text"].GetString();

		if(doc.HasMember("entities"))
			for(std::size_t j = 0; j < doc["entities"].GetArray().Size(); ++j)
			{
				entities.resize(doc["entities"].GetArray().Size());

				entities.at(j) = std::make_shared<MessageEntity>(SpecialTools::get_json_obj_as_string(doc["entities"][j]));
			}

		if(doc.HasMember("caption_entities"))
			for(std::size_t j = 0; j < doc["caption_entities"].GetArray().Size(); ++j)
			{
				caption_entities.resize(doc["caption_entities"].GetArray().Size());

				caption_entities.at(j) = std::make_shared<MessageEntity>(SpecialTools::get_json_obj_as_string(doc["caption_entities"][j]));
			}

		if(doc.HasMember("audio"))
			audio = std::make_shared<Audio>(SpecialTools::get_json_obj_as_string(doc["audio"]));

		if(doc.HasMember("document"))
			document = std::make_shared<Document>(SpecialTools::get_json_obj_as_string(doc["document"]));

		if(doc.HasMember("animation"))
			animation = std::make_shared<Animation>(SpecialTools::get_json_obj_as_string(doc["animation"]));

		if(doc.HasMember("game"))
			game = std::make_shared<Game>(SpecialTools::get_json_obj_as_string(doc["game"]));

		if(doc.HasMember("photo"))
			for(std::size_t j = 0; j < doc["photo"].GetArray().Size(); ++j)
			{
				photo.resize(doc["photo"].GetArray().Size());

				photo.at(j) = std::make_shared<PhotoSize>(SpecialTools::get_json_obj_as_string(doc["photo"][j]));
			}

		if(doc.HasMember("sticker"))
			sticker = std::make_shared<Sticker>(SpecialTools::get_json_obj_as_string(doc["sticker"]));

		if(doc.HasMember("video"))
			video = std::make_shared<Video>(SpecialTools::get_json_obj_as_string(doc["video"]));

		if(doc.HasMember("voice"))
			voice = std::make_shared<Voice>(SpecialTools::get_json_obj_as_string(doc["voice"]));

		if(doc.HasMember("video_note"))
			video_note = std::make_shared<VideoNote>(SpecialTools::get_json_obj_as_string(doc["video_note"]));

		if(doc.HasMember("caption"))
			caption = doc["caption"].GetString();

		if(doc.HasMember("contact"))
			contact = std::make_shared<Contact>(SpecialTools::get_json_obj_as_string(doc["contact"]));

		if(doc.HasMember("location"))
			location = std::make_shared<Location>(SpecialTools::get_json_obj_as_string(doc["location"]));

		if(doc.HasMember("venue"))
			venue = std::make_shared<Venue>(SpecialTools::get_json_obj_as_string(doc["venue"]));

		if(doc.HasMember("poll"))
			poll = std::make_shared<Poll>(SpecialTools::get_json_obj_as_string(doc["poll"]));

		if(doc.HasMember("new_chat_members"))
			for(std::size_t j = 0; j < doc["new_chat_members"].GetArray().Size(); ++j)
			{
				new_chat_members.resize(doc["new_chat_members"].GetArray().Size());

				new_chat_members.at(j) = std::make_shared<User>(SpecialTools::get_json_obj_as_string(doc["new_chat_members"][j]));
			}

		if(doc.HasMember("left_chat_member"))
			left_chat_member = std::make_shared<User>(SpecialTools::get_json_obj_as_string(doc["left_chat_member"]));

		if(doc.HasMember("new_chat_title"))
			new_chat_title = doc["new_chat_title"].GetString();

		if(doc.HasMember("new_chat_photo"))
			for(std::size_t j = 0; j < doc["new_chat_photo"].GetArray().Size(); ++j)
			{
				new_chat_photo.resize(doc["new_chat_photo"].GetArray().Size());

				new_chat_photo.at(j) = std::make_shared<PhotoSize>(SpecialTools::get_json_obj_as_string(doc["new_chat_photo"][j]));
			}

		if(doc.HasMember("delete_chat_phtot"))
			delete_chat_photo = doc["delete_chat_phtot"].GetBool();

		if(doc.HasMember("group_chat_created"))
			group_chat_created = doc["group_chat_created"].GetBool();

		if(doc.HasMember("supergroup_chat_created"))
			supergroup_chat_created = doc["supergroup_chat_created"].GetBool();

		if(doc.HasMember("channel_chat_created"))
			channel_chat_created = doc["channel_chat_created"].GetBool();

		if(doc.HasMember("migrate_to_chat_id"))
			migrate_to_chat_id = doc["migrate_to_chat_id"].GetInt();

		if(doc.HasMember("migrate_from_chat_id"))
			migrate_from_chat_id = doc["migrate_from_chat_id"].GetInt();

		if(doc.HasMember("pinned_message"))
			pinned_message = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["pinned_message"]));

		if(doc.HasMember("invoice"))
			invoice = std::make_shared<Invoice>(SpecialTools::get_json_obj_as_string(doc["invoice"]));

		if(doc.HasMember("successful_payment"))
			successful_payment = std::make_shared<SuccessfulPayment>(SpecialTools::get_json_obj_as_string(doc["successful_payment"]));

		if(doc.HasMember("connected_website"))
			connected_website = doc["connected_website"].GetString();

		if(doc.HasMember("passport_data"))
			passport_data = std::make_shared<PassportData>(SpecialTools::get_json_obj_as_string(doc["passport_data"]));

		if(doc.HasMember("reply_markup"))
			reply_markup = std::make_shared<InlineKeyboardMarkup>(SpecialTools::get_json_obj_as_string(doc["reply_markup"]));
	}

	std::string Message::parse_to_json() const
	{
		std::string json = "{";

		//field message_id
		json.append("\"message_id\": " + message_id);
		json.append(", ");

		//field from
		json.append("\"from\": " + from->parse_to_json());
		json.append(", ");

		//field date
		json.append("\"date\": " + date);
		json.append(", ");

		//field chat
		json.append("\"chat\": " + chat->parse_to_json());
		json.append(", ");

		//field forward_from
		json.append("\"forward_from\": " + forward_from->parse_to_json());
		json.append(", ");

		//field forward_from_chat
		json.append("\"forward_from_chat\": " + forward_from_chat->parse_to_json());
		json.append(", ");

		//field forward_from_message_id
		json.append("\"forward_from_message_id\": " + forward_from_message_id);
		json.append(", ");

		//field forward_signature
		json.append("\"forward_signature\": \"" + forward_signature + "\"");
		json.append(", ");

		//field forward_sender_name
		json.append("\"forward_sender_name\": \"" + forward_sender_name + "\"");
		json.append(", ");

		//field forward_date
		json.append("\"forward_date\": " + forward_date);
		json.append(", ");

		//field reply_to_message
		json.append("\"reply_to_message\": " + reply_to_message->parse_to_json());
		json.append(", ");

		//field edit_date
		json.append("\"edit_date\": " + edit_date);
		json.append(", ");

		//field media_group_id
		json.append("\"media_group_id\": \"" + media_group_id + "\"");
		json.append(", ");

		//field author_signature
		json.append("\"author_signature\": \"" + author_signature + "\"");
		json.append(", ");

		//field text
		json.append("\"text\": \"" + text + "\"");
		json.append(", ");

		//field entities
		std::string entities_cont = "[";
		for(std::size_t j = 0; j < entities.size(); ++j)
		{
			entities_cont.append(entities.at(j)->parse_to_json());
			entities_cont.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * entities and not entities_cont in condition as in that case we would destroy the json array
		 */
		if(entities.size() > 0)
		{
			//finish json array
			entities_cont.pop_back();
			entities_cont.pop_back();
		}
		entities_cont.append("]");

		json.append("\"entities\": " + entities_cont);
		json.append(", ");

		//field caption_entities
		std::string caption_entities_cont = "[";
		for(std::size_t j = 0; j < caption_entities.size(); ++j)
		{
			caption_entities_cont.append(caption_entities.at(j)->parse_to_json());
			caption_entities_cont.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * caption_entities and not caption_entities_cont in condition as in that case we would destroy the json array
		 */
		if(caption_entities.size() > 0)
		{
			//finish json array
			caption_entities_cont.pop_back();
			caption_entities_cont.pop_back();
		}
		caption_entities_cont.append("]");

		json.append("\"caption_entities\": " + caption_entities_cont);
		json.append(", ");

		//field audio
		json.append("\"audio\": " + audio->parse_to_json());
		json.append(", ");

		//field document
		json.append("\"document\": " + document->parse_to_json());
		json.append(", ");

		//field animation
		json.append("\"animation\": " + animation->parse_to_json());
		json.append(", ");

		//field game
		json.append("\"game\": " + game->parse_to_json());
		json.append(", ");

		//field photo
		std::string photo_cont = "[";
		for(std::size_t j = 0; j < photo.size(); ++j)
		{
			photo_cont.append(photo.at(j)->parse_to_json());
			photo_cont.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * photo and not photo_cont in condition as in that case we would destroy the json array
		 */
		if(photo.size() > 0)
		{
			//finish json array
			photo_cont.pop_back();
			photo_cont.pop_back();
		}
		photo_cont.append("]");

		json.append("\"photo\": " + photo_cont);
		json.append(", ");

		//field sticker
		json.append("\"sticker\": " + sticker->parse_to_json());
		json.append(", ");

		//field video
		json.append("\"video\": " + video->parse_to_json());
		json.append(", ");

		//field voice
		json.append("\"voice\": " + voice->parse_to_json());
		json.append(", ");

		//field video_note
		json.append("\"video_note\": " + video_note->parse_to_json());
		json.append(", ");

		//field caption
		json.append("\"caption\": \"" + caption + "\"");
		json.append(", ");

		//field contact
		json.append("\"contact\": " + contact->parse_to_json());
		json.append(", ");

		//field location
		json.append("\"location\": " + location->parse_to_json());
		json.append(", ");

		//field venue
		json.append("\"venue\": " + venue->parse_to_json());
		json.append(", ");

		//field poll
		json.append("\"poll\": " + poll->parse_to_json());
		json.append(", ");

		//field new_chat_members
		std::string new_chat_members_cont = "[";
		for(std::size_t j = 0; j < new_chat_members.size(); ++j)
		{
			new_chat_members_cont.append(new_chat_members.at(j)->parse_to_json());
			new_chat_members_cont.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * new_chat_members and not new_chat_members_cont in condition as in that case we would destroy the json array
		 */
		if(new_chat_members.size() > 0)
		{
			//finish json array
			new_chat_members_cont.pop_back();
			new_chat_members_cont.pop_back();
		}
		new_chat_members_cont.append("]");

		json.append("\"new_chat_members\": " + new_chat_members_cont);
		json.append(", ");

		//field left_chat_member
		json.append("\"left_chat_member\": " + left_chat_member->parse_to_json());
		json.append(", ");

		//field new_chat_title
		json.append("\"new_chat_title\": \"" + new_chat_title + "\"");
		json.append(", ");

		//field new_chat_photo
		std::string new_chat_photo_cont = "[";
		for(std::size_t j = 0; j < new_chat_photo.size(); ++j)
		{
			new_chat_photo_cont.append(new_chat_photo.at(j)->parse_to_json());
			new_chat_photo_cont.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * new_chat_photo and not new_chat_photo_cont in condition as in that case we would destroy the json array
		 */
		if(new_chat_photo.size() > 0)
		{
			//finish json array
			new_chat_photo_cont.pop_back();
			new_chat_photo_cont.pop_back();
		}
		new_chat_photo_cont.append("]");

		json.append("\"new_chat_photo\": " + new_chat_photo_cont);
		json.append(", ");

		//field delete_chat_photo
		std::string delete_chat_photo_bool = delete_chat_photo ? "true" : "false";
		json.append("\"delete_chat_photo\": " + delete_chat_photo_bool);
		json.append(", ");

		//field group_chat_created
		std::string group_chat_created_bool = group_chat_created ? "true" : "false";
		json.append("\"group_chat_created\": " + group_chat_created_bool);
		json.append(", ");

		//field supergroup_chat_created
		std::string supergroup_chat_created_bool = supergroup_chat_created ? "true" : "false";
		json.append("\"supergroup_chat_created\": " + supergroup_chat_created_bool);
		json.append(", ");

		//field channel_chat_created
		std::string channel_chat_created_bool = channel_chat_created ? "true" : "false";
		json.append("\"channel_chat_created\": " + channel_chat_created_bool);
		json.append(", ");

		//field migrate_to_chat_id
		json.append("\"migrate_to_chat_id\": " + migrate_to_chat_id);
		json.append(", ");

		//field migrate_from_chat_id
		json.append("\"migrate_from_chat_id\": " + migrate_from_chat_id);
		json.append(", ");

		//field pinned_message
		json.append("\"pinned_message\": " + pinned_message->parse_to_json());
		json.append(", ");

		//field invoice
		json.append("\"invoice\": " + invoice->parse_to_json());
		json.append(", ");

		//field successful_payment
		json.append("\"successful_payment\": " + successful_payment->parse_to_json());
		json.append(", ");

		//field connected_website
		json.append("\"connected_website\": \"" + connected_website + "\"");
		json.append(", ");

		//field passport_data
		json.append("\"passport_data\": " + passport_data->parse_to_json());
		json.append(", ");

		//field reply_markup
		json.append("\"reply_markup\": " + reply_markup->parse_to_json());

		json.append("}");

		return json;
	}
}

