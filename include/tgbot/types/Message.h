#ifndef TGBOT_TYPES_MESSAGE_H
#define TGBOT_TYPES_MESSAGE_H

#include <string>
#include "tgbot/types/User.h"
#include "tgbot/types/MessageEntity.h"
#include "tgbot/types/Audio.h"
#include "tgbot/types/Document.h"
#include "tgbot/types/Animation.h"
#include "tgbot/types/Game.h"
#include "tgbot/types/Animation.h"
#include "tgbot/types/PhotoSize.h"
#include "tgbot/types/Sticker.h"
#include "tgbot/types/Video.h"
#include "tgbot/types/VideoNote.h"
#include "tgbot/types/Contact.h"
#include "tgbot/types/Location.h"
#include "tgbot/types/Venue.h"
#include "tgbot/types/Poll.h"
#include "tgbot/types/Voice.h"
#include "tgbot/types/Venue.h"
#include "tgbot/types/Invoice.h"
#include "tgbot/types/SuccessfulPayment.h"
#include "tgbot/types/PassportData.h"
#include "tgbot/types/InlineKeyboardMarkup.h"
#include <rapidjson/document.h>
#include "tgbot/types/Chat.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct Message
	{
		//pointer of itself
		typedef std::shared_ptr<Message> ptr;

		//member variables
		int message_id = -1;
		User::ptr from;
		int date = -1;
		Chat::ptr chat;
		User::ptr forward_from;
		Chat::ptr forward_from_chat;
		int forward_from_message_id = -1;
		std::string forward_signature;
		std::string forward_sender_name;
		int forward_date;
		Message::ptr reply_to_message;
		int edit_date = -1;
		std::string media_group_id;
		std::string author_signature;
		std::string text;
		std::vector<MessageEntity::ptr> entities;
		std::vector<MessageEntity::ptr> caption_entities;
		Audio::ptr audio;
		Document::ptr document;
		Animation::ptr animation;
		Game::ptr game;
		std::vector<PhotoSize::ptr> photo;
		Sticker::ptr sticker;
		Video::ptr video;
		Voice::ptr voice;
		VideoNote::ptr video_note;
		std::string caption;
		Contact::ptr contact;
		Location::ptr location;
		Venue::ptr venue;
		Poll::ptr poll;
		std::vector<User::ptr> new_chat_members;
		User::ptr left_chat_member;
		std::string new_chat_title;
		std::vector<PhotoSize::ptr> new_chat_photo;
		bool delete_chat_photo;
		bool group_chat_created;
		bool supergroup_chat_created;
		bool channel_chat_created;
		int migrate_to_chat_id = -1;
		int migrate_from_chat_id = -1;
		Message::ptr pinned_message;
		Invoice::ptr invoice;
		SuccessfulPayment::ptr successful_payment;
		std::string connected_website;
		PassportData::ptr passport_data;
		InlineKeyboardMarkup::ptr reply_markup;

		//constructors
		Message();

		//@param json: json object of Message
		Message(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
