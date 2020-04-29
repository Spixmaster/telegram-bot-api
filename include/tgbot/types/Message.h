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
#include "tgbot/types/Dice.h"

namespace tgbot
{
	/**
	 * @struct Message
	 * @brief This object represents a message.
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
		 * @var message_id
		 * @brief Unique message identifier inside this chat
		 */
		int message_id;
		/**
		 * @var from
		 * @brief Optional. Sender, empty for messages sent to channels
		 */
		User::ptr from;
		/**
		 * @var date
		 * @brief Date the message was sent in Unix time
		 */
		int date;
		/**
		 * @var chat
		 * @brief Conversation the message belongs to
		 */
		Chat::ptr chat;
		/**
		 * @var forward_from
		 * @brief Optional. For forwarded messages, sender of the original message
		 */
		User::ptr forward_from;
		/**
		 * @var forward_from_chat
		 * @brief Optional. For messages forwarded from channels, information about the original channel
		 */
		Chat::ptr forward_from_chat;
		/**
		 * @var forward_from_message_id
		 * @brief Optional. For messages forwarded from channels, identifier of the original message in the channel
		 */
		int forward_from_message_id;
		/**
		 * @var forward_signature
		 * @brief String Optional. For messages forwarded from channels, signature of the post author if present
		 */
		std::string forward_signature;
		/**
		 * @var forward_sender_name
		 * @brief Optional. Sender's name for messages forwarded from users who disallow adding a link to their account in forwarded messages
		 */
		std::string forward_sender_name;
		/**
		 * @var forward_date
		 * @brief Optional. For forwarded messages, date the original message was sent in Unix time
		 */
		int forward_date;
		/**
		 * @var reply_to_message
		 * @brief Optional. For replies, the original message. Note that the Message object in this field will not contain further reply_to_message fields even if it itself is a reply.
		 */
		Message::ptr reply_to_message;
		/**
		 * @var edit_date
		 * @brief Optional. Date the message was last edited in Unix time
		 */
		int edit_date;
		/**
		 * @var media_group_id
		 * @brief Optional. The unique identifier of a media message group this message belongs to
		 */
		std::string media_group_id;
		/**
		 * @var author_signature
		 * @brief Optional. Signature of the post author for messages in channels
		 */
		std::string author_signature;
		/**
		 * @var text
		 * @brief Optional. For text messages, the actual UTF-8 text of the message, 0-4096 characters
		 */
		std::string text;
		/**
		 * @var entities
		 * @brief Optional. For text messages, special entities like usernames, URLs, bot commands, etc. that appear in the text
		 */
		std::vector<MessageEntity::ptr> entities;
		/**
		 * @var caption_entities
		 * @brief Optional. For messages with a caption, special entities like usernames, URLs, bot commands, etc. that appear in the caption
		 */
		std::vector<MessageEntity::ptr> caption_entities;
		/**
		 * @var audio
		 * @brief Optional. Message is an audio file, information about the file
		 */
		Audio::ptr audio;
		/**
		 * @var document
		 * @brief Optional. Message is a general file, information about the file
		 */
		Document::ptr document;
		/**
		 * @var animation
		 * @brief Optional. Message is an animation, information about the animation. For backward compatibility, when this field is set, the document field will also be set
		 */
		Animation::ptr animation;
		/**
		 * @var game
		 * @brief Optional. Message is a game, information about the game.
		 */
		Game::ptr game;
		/**
		 * @var photo
		 * @brief Optional. Message is a photo, available sizes of the photo
		 */
		std::vector<PhotoSize::ptr> photo;
		/**
		 * @var sticker
		 * @brief Optional. Message is a sticker, information about the sticker
		 */
		Sticker::ptr sticker;
		/**
		 * @var video
		 * @brief Optional. Message is a video, information about the video
		 */
		Video::ptr video;
		/**
		 * @var voice
		 * @brief Optional. Message is a voice message, information about the file
		 */
		Voice::ptr voice;
		/**
		 * @var video_note
		 * @brief Optional. Message is a video note, information about the video message
		 */
		VideoNote::ptr video_note;
		/**
		 * @var caption
		 * @brief Optional. Caption for the animation, audio, document, photo, video or voice, 0-1024 characters
		 */
		std::string caption;
		/**
		 * @var contact
		 * @brief Optional. Message is a shared contact, information about the contact
		 */
		Contact::ptr contact;
		/**
		 * @var location
		 * @brief Optional. Message is a shared location, information about the location
		 */
		Location::ptr location;
		/**
		 * @var venue
		 * @brief Optional. Message is a venue, information about the venue
		 */
		Venue::ptr venue;
		/**
		 * @var poll
		 * @brief Optional. Message is a native poll, information about the poll
		 */
		Poll::ptr poll;
		/**
		 * @var dice
		 * @brief Optional. Message is a dice with random value from 1 to 6
		 */
		Dice::ptr dice;
		/**
		 * @var new_chat_members
		 * @brief Optional. New members that were added to the group or supergroup and information about them (the bot itself may be one of these members)
		 */
		std::vector<User::ptr> new_chat_members;
		/**
		 * @var left_chat_member
		 * @brief Optional. A member was removed from the group, information about them (this member may be the bot itself)
		 */
		User::ptr left_chat_member;
		/**
		 * @var new_chat_title
		 * @brief Optional. A chat title was changed to this value
		 */
		std::string new_chat_title;
		/**
		 * @var new_chat_photo
		 * @brief Optional. A chat photo was change to this value
		 */
		std::vector<PhotoSize::ptr> new_chat_photo;
		/**
		 * @var delete_chat_photo
		 * @brief Optional. Service message: the chat photo was deleted
		 */
		bool delete_chat_photo;
		/**
		 * @var group_chat_created
		 * @brief Optional. Service message: the group has been created
		 */
		bool group_chat_created;
		/**
		 * @var supergroup_chat_created
		 * @brief Optional. Service message: the supergroup has been created.
		 * @details This field can‘t be received in a message coming through updates, because bot can’t be a member of a supergroup when it is created.
		 * @details It can only be found in reply_to_message if someone replies to a very first message in a directly created supergroup.
		 */
		bool supergroup_chat_created;
		/**
		 * @var channel_chat_created
		 * @brief Optional. Service message: the channel has been created.
		 * @details This field can‘t be received in a message coming through updates, because bot can’t be a member of a channel when it is created.
		 * @details It can only be found in reply_to_message if someone replies to a very first message in a channel.
		 */
		bool channel_chat_created;
		/**
		 * @var migrate_to_chat_id
		 * @brief Optional. The group has been migrated to a supergroup with the specified identifier.
		 * @details This number may be greater than 32 bits and some programming languages may have difficulty/silent defects in interpreting it.
		 * @details But it is smaller than 52 bits, so a signed 64 bit integer or double-precision float type are safe for storing this identifier.
		 */
		int migrate_to_chat_id;
		/**
		 * @var migrate_from_chat_id
		 * @brief Optional. The supergroup has been migrated from a group with the specified identifier.
		 * @details This number may be greater than 32 bits and some programming languages may have difficulty/silent defects in interpreting it.
		 * @details But it is smaller than 52 bits, so a signed 64 bit integer or double-precision float type are safe for storing this identifier.
		 */
		int migrate_from_chat_id;
		/**
		 * @var pinned_message
		 * @brief Optional. Specified message was pinned. Note that the Message object in this field will not contain further reply_to_message fields even if it is itself a reply.
		 */
		Message::ptr pinned_message;
		/**
		 * @var invoice
		 * @brief Optional. Message is an invoice for a payment, information about the invoice.
		 */
		Invoice::ptr invoice;
		/**
		 * @var successful_payment
		 * @brief Optional. Message is a service message about a successful payment, information about the payment.
		 */
		SuccessfulPayment::ptr successful_payment;
		/**
		 * @var connected_website
		 * @brief Optional. The domain name of the website on which the user has logged in.
		 */
		std::string connected_website;
		/**
		 * @var passport_data
		 * @brief Optional. Telegram Passport data
		 */
		PassportData::ptr passport_data;
		/**
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message. login_url buttons are represented as ordinary url buttons.
		 */
		InlineKeyboardMarkup::ptr reply_markup;

		//Constructors
		Message();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		Message(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
