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

namespace tgbot
{
	/**
	 * @struct Message
	 */
	struct Message
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Message> ptr;

		//Member variables
		/**
		 * @var
		 */
		int message_id = -1;
		/**
		 * @var
		 */
		User::ptr from;
		/**
		 * @var
		 */
		int date = -1;
		/**
		 * @var
		 */
		Chat::ptr chat;
		/**
		 * @var
		 */
		User::ptr forward_from;
		/**
		 * @var
		 */
		Chat::ptr forward_from_chat;
		/**
		 * @var
		 */
		int forward_from_message_id = -1;
		/**
		 * @var
		 */
		std::string forward_signature;
		/**
		 * @var
		 */
		std::string forward_sender_name;
		/**
		 * @var
		 */
		int forward_date;
		/**
		 * @var
		 */
		Message::ptr reply_to_message;
		/**
		 * @var
		 */
		int edit_date = -1;
		/**
		 * @var
		 */
		std::string media_group_id;
		/**
		 * @var
		 */
		std::string author_signature;
		/**
		 * @var
		 */
		std::string text;
		/**
		 * @var
		 */
		std::vector<MessageEntity::ptr> entities;
		/**
		 * @var
		 */
		std::vector<MessageEntity::ptr> caption_entities;
		/**
		 * @var
		 */
		Audio::ptr audio;
		/**
		 * @var
		 */
		Document::ptr document;
		/**
		 * @var
		 */
		Animation::ptr animation;
		/**
		 * @var
		 */
		Game::ptr game;
		/**
		 * @var
		 */
		std::vector<PhotoSize::ptr> photo;
		/**
		 * @var
		 */
		Sticker::ptr sticker;
		/**
		 * @var
		 */
		Video::ptr video;
		/**
		 * @var
		 */
		Voice::ptr voice;
		/**
		 * @var
		 */
		VideoNote::ptr video_note;
		/**
		 * @var
		 */
		std::string caption;
		/**
		 * @var
		 */
		Contact::ptr contact;
		/**
		 * @var
		 */
		Location::ptr location;
		/**
		 * @var
		 */
		Venue::ptr venue;
		/**
		 * @var
		 */
		Poll::ptr poll;
		/**
		 * @var
		 */
		std::vector<User::ptr> new_chat_members;
		/**
		 * @var
		 */
		User::ptr left_chat_member;
		/**
		 * @var
		 */
		std::string new_chat_title;
		/**
		 * @var
		 */
		std::vector<PhotoSize::ptr> new_chat_photo;
		/**
		 * @var
		 */
		bool delete_chat_photo;
		/**
		 * @var
		 */
		bool group_chat_created;
		/**
		 * @var
		 */
		bool supergroup_chat_created;
		/**
		 * @var
		 */
		bool channel_chat_created;
		/**
		 * @var
		 */
		int migrate_to_chat_id = -1;
		/**
		 * @var
		 */
		int migrate_from_chat_id = -1;
		/**
		 * @var
		 */
		Message::ptr pinned_message;
		/**
		 * @var
		 */
		Invoice::ptr invoice;
		/**
		 * @var
		 */
		SuccessfulPayment::ptr successful_payment;
		/**
		 * @var
		 */
		std::string connected_website;
		/**
		 * @var
		 */
		PassportData::ptr passport_data;
		/**
		 * @var
		 */
		InlineKeyboardMarkup::ptr reply_markup;

		//Constructors
		Message();

		//@param json: json object of Message
		Message(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
