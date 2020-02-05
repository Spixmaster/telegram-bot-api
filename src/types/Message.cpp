#include "tgbot/types/Chat.h"
#include "tgbot/types/Message.h"
#include "tools/Tools.h"
#include <iostream>

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

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("message_id"))
			{
				if(doc["message_id"].IsInt())
					message_id = doc["message_id"].GetInt();
				else
					std::cerr << "Error: Field \"message_id\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("from"))
			{
				if(doc["from"].IsObject())
					from = std::make_shared<User>(tools::Tools::get_json_as_string(doc["from"]));
				else
					std::cerr << "Error: Field \"from\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("date"))
			{
				if(doc["date"].IsInt())
					date = doc["date"].GetInt();
				else
					std::cerr << "Error: Field \"date\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("chat"))
			{
				if(doc["chat"].IsObject())
					chat = std::make_shared<Chat>(tools::Tools::get_json_as_string(doc["chat"]));
				else
					std::cerr << "Error: Field \"chat\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("forward_from"))
			{
				if(doc["forward_from"].IsObject())
					forward_from = std::make_shared<User>(tools::Tools::get_json_as_string(doc["forward_from"]));
				else
					std::cerr << "Error: Field \"forward_from\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("forward_from_chat"))
			{
				if(doc["forward_from_chat"].IsObject())
					forward_from_chat = std::make_shared<Chat>(tools::Tools::get_json_as_string(doc["forward_from_chat"]));
				else
					std::cerr << "Error: Field \"forward_from_chat\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("forward_from_message_id"))
			{
				if(doc["forward_from_message_id"].IsInt())
					forward_from_message_id = doc["forward_from_message_id"].GetInt();
				else
					std::cerr << "Error: Field \"forward_from_message_id\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("forward_signature"))
			{
				if(doc["forward_signature"].IsString())
					forward_signature = doc["forward_signature"].GetString();
				else
					std::cerr << "Error: Field \"forward_signature\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("forward_sender_name"))
			{
				if(doc["forward_sender_name"].IsString())
					forward_sender_name = doc["forward_sender_name"].GetString();
				else
					std::cerr << "Error: Field \"forward_sender_name\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("forward_date"))
			{
				if(doc["forward_date"].IsInt())
					forward_date = doc["forward_date"].GetInt();
				else
					std::cerr << "Error: Field \"forward_date\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("reply_to_message"))
			{
				if(doc["reply_to_message"].IsObject())
					reply_to_message = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["reply_to_message"]));
				else
					std::cerr << "Error: Field \"reply_to_message\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("edit_date"))
			{
				if(doc["edit_date"].IsInt())
					edit_date = doc["edit_date"].GetInt();
				else
					std::cerr << "Error: Field \"edit_date\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("media_group_id"))
			{
				if(doc["media_group_id"].IsString())
					media_group_id = doc["media_group_id"].GetString();
				else
					std::cerr << "Error: Field \"media_group_id\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("author_signature"))
			{
				if(doc["author_signature "].IsString())
					author_signature = doc["author_signature"].GetString();
				else
					std::cerr << "Error: Field \"author_signature\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("text"))
			{
				if(doc["text"].IsString())
					text = doc["text"].GetString();
				else
					std::cerr << "Error: Field \"text\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("entities"))
			{
				if(doc["entities"].IsArray())
				{
					entities.resize(doc["entities"].GetArray().Size());

					for(std::size_t j = 0; j < doc["entities"].GetArray().Size(); ++j)
					{
						if(doc["entities"][j].IsObject())
							entities.at(j) = std::make_shared<MessageEntity>(tools::Tools::get_json_as_string(doc["entities"][j]));
						else
							std::cerr << "Error: Field \"entities\"'s json array's element is not a json object." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"entities\" does not contain a json array." << std::endl;
			}

			if(doc.HasMember("caption_entities"))
			{
				if(doc["caption_entities"].IsArray())
				{
					caption_entities.resize(doc["caption_entities"].GetArray().Size());

					for(std::size_t j = 0; j < doc["caption_entities"].GetArray().Size(); ++j)
					{
						if(doc["caption_entities"][j].IsObject())
							caption_entities.at(j) = std::make_shared<MessageEntity>(tools::Tools::get_json_as_string(doc["caption_entities"][j]));
						else
							std::cerr << "Error: Field \"caption_entities\"'s json array's element is not a json object." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"caption_entities\" does not contain a json array." << std::endl;
			}

			if(doc.HasMember("audio"))
			{
				if(doc["audio"].IsObject())
					audio = std::make_shared<Audio>(tools::Tools::get_json_as_string(doc["audio"]));
				else
					std::cerr << "Error: Field \"audio\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("document"))
			{
				if(doc["document"].IsObject())
					document = std::make_shared<Document>(tools::Tools::get_json_as_string(doc["document"]));
				else
					std::cerr << "Error: Field \"document\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("animation"))
			{
				if(doc["animation"].IsObject())
					animation = std::make_shared<Animation>(tools::Tools::get_json_as_string(doc["animation"]));
				else
					std::cerr << "Error: Field \"animation\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("game"))
			{
				if(doc["game"].IsObject())
					game = std::make_shared<Game>(tools::Tools::get_json_as_string(doc["game"]));
				else
					std::cerr << "Error: Field \"game\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("photo"))
			{
				if(doc["photo"].IsArray())
				{
					photo.resize(doc["photo"].GetArray().Size());

					for(std::size_t j = 0; j < doc["photo"].GetArray().Size(); ++j)
					{
						if(doc["photo"][j].IsObject())
							photo.at(j) = std::make_shared<PhotoSize>(tools::Tools::get_json_as_string(doc["photo"][j]));
						else
							std::cerr << "Error: Field \"photo\"'s json array's element is not a json object." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"photo\" does not contain a json array." << std::endl;
			}

			if(doc.HasMember("sticker"))
			{
				if(doc["sticker"].IsObject())
					sticker = std::make_shared<Sticker>(tools::Tools::get_json_as_string(doc["sticker"]));
				else
					std::cerr << "Error: Field \"sticker\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("video"))
			{
				if(doc["video"].IsObject())
					video = std::make_shared<Video>(tools::Tools::get_json_as_string(doc["video"]));
				else
					std::cerr << "Error: Field \"video\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("voice"))
			{
				if(doc["voice"].IsObject())
					voice = std::make_shared<Voice>(tools::Tools::get_json_as_string(doc["voice"]));
				else
					std::cerr << "Error: Field \"voice\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("video_note"))
			{
				if(doc["video_note"].IsObject())
					video_note = std::make_shared<VideoNote>(tools::Tools::get_json_as_string(doc["video_note"]));
				else
					std::cerr << "Error: Field \"video_note\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("caption"))
			{
				if(doc["caption"].IsString())
					caption = doc["caption"].GetString();
				else
					std::cerr << "Error: Field \"caption\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("contact"))
			{
				if(doc["contact"].IsObject())
					contact = std::make_shared<Contact>(tools::Tools::get_json_as_string(doc["contact"]));
				else
					std::cerr << "Error: Field \"contact\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("location"))
			{
				if(doc["location"].IsObject())
					location = std::make_shared<Location>(tools::Tools::get_json_as_string(doc["location"]));
				else
					std::cerr << "Error: Field \"location\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("venue"))
			{
				if(doc["venue"].IsObject())
					venue = std::make_shared<Venue>(tools::Tools::get_json_as_string(doc["venue"]));
				else
					std::cerr << "Error: Field \"venue\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("poll"))
			{
				if(doc["poll"].IsObject())
					poll = std::make_shared<Poll>(tools::Tools::get_json_as_string(doc["poll"]));
				else
					std::cerr << "Error: Field \"poll\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("new_chat_members"))
			{
				if(doc["new_chat_members"].IsArray())
				{
					new_chat_members.resize(doc["new_chat_members"].GetArray().Size());

					for(std::size_t j = 0; j < doc["new_chat_members"].GetArray().Size(); ++j)
					{
						if(doc["new_chat_members"][j].IsObject())
							new_chat_members.at(j) = std::make_shared<User>(tools::Tools::get_json_as_string(doc["new_chat_members"][j]));
						else
							std::cerr << "Error: Field \"new_chat_members\"'s json array's element is not a json object." << std::endl;
					}
				}
			}

			if(doc.HasMember("left_chat_member"))
			{
				if(doc["left_chat_member"].IsObject())
					left_chat_member = std::make_shared<User>(tools::Tools::get_json_as_string(doc["left_chat_member"]));
				else
					std::cerr << "Error: Field \"left_chat_member\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("new_chat_title"))
			{
				if(doc["new_chat_title"].IsString())
					new_chat_title = doc["new_chat_title"].GetString();
				else
					std::cerr << "Error: Field \"new_chat_title\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("new_chat_photo"))
			{
				if(doc["new_chat_photo"].IsArray())
				{
					new_chat_photo.resize(doc["new_chat_photo"].GetArray().Size());

					for(std::size_t j = 0; j < doc["new_chat_photo"].GetArray().Size(); ++j)
					{
						if(doc["new_chat_photo"][j].IsObject())
							new_chat_photo.at(j) = std::make_shared<PhotoSize>(tools::Tools::get_json_as_string(doc["new_chat_photo"][j]));
						else
							std::cerr << "Error: Field \"new_chat_photo\"'s json array's element is not a json object." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"new_chat_photo\" does not contain a json array." << std::endl;
			}

			if(doc.HasMember("delete_chat_photo"))
			{
				if(doc["delete_chat_photo"].IsBool())
					delete_chat_photo = doc["delete_chat_photo"].GetBool();
				else
					std::cerr << "Error: Field \"delete_chat_photo\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("group_chat_created"))
			{
				if(doc["group_chat_created"].IsBool())
					group_chat_created = doc["group_chat_created"].GetBool();
				else
					std::cerr << "Error: Field \"group_chat_created\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("supergroup_chat_created"))
			{
				if(doc["supergroup_chat_created"].IsBool())
					supergroup_chat_created = doc["supergroup_chat_created"].GetBool();
				else
					std::cerr << "Error: Field \"supergroup_chat_created\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("channel_chat_created"))
			{
				if(doc["channel_chat_created"].IsBool())
					channel_chat_created = doc["channel_chat_created"].GetBool();
				else
					std::cerr << "Error: Field \"channel_chat_created\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("migrate_to_chat_id"))
			{
				if(doc["migrate_to_chat_id"].IsInt())
					migrate_to_chat_id = doc["migrate_to_chat_id"].GetInt();
				else
					std::cerr << "Error: Field \"migrate_to_chat_id\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("migrate_from_chat_id"))
			{
				if(doc["migrate_from_chat_id"].IsInt())
					migrate_from_chat_id = doc["migrate_from_chat_id"].GetInt();
				else
					std::cerr << "Error: Field \"migrate_from_chat_id\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("pinned_message"))
			{
				if(doc["pinned_message"].IsObject())
					pinned_message = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["pinned_message"]));
				else
					std::cerr << "Error: Field \"pinned_message\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("invoice"))
			{
				if(doc["invoice"].IsObject())
					invoice = std::make_shared<Invoice>(tools::Tools::get_json_as_string(doc["invoice"]));
				else
					std::cerr << "Error: Field \"invoice\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("successful_payment"))
			{
				if(doc["successful_payment"].IsObject())
					successful_payment = std::make_shared<SuccessfulPayment>(tools::Tools::get_json_as_string(doc["successful_payment"]));
				else
					std::cerr << "Error: Field \"successful_payment\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("connected_website"))
			{
				if(doc["connected_website"].IsString())
					connected_website = doc["connected_website"].GetString();
				else
					std::cerr << "Error: Field \"connected_website\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("passport_data"))
			{
				if(doc["passport_data"].IsObject())
					passport_data = std::make_shared<PassportData>(tools::Tools::get_json_as_string(doc["passport_data"]));
				else
					std::cerr << "Error: Field \"passport_data\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("reply_markup"))
			{
				if(doc["reply_markup"].IsObject())
					reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
				else
					std::cerr << "Error: Field \"reply_markup\" does not contain a json object." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string Message::parse_to_json() const noexcept
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

