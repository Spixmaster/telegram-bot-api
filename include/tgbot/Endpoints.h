#ifndef TGBOT_ENDPOINTS_H
#define TGBOT_ENDPOINTS_H

#include <string>
#include "tgbot/types/User.h"
#include <memory>
#include "tools/http/HttpArg.h"
#include <vector>
#include "tgbot/types/Message.h"
#include "tgbot/types/ReplyKeyboardMarkup.h"
#include "tgbot/types/ForceReply.h"
#include "tgbot/types/ReplyKeyboardRemove.h"
#include "tools/http/InputFile.h"
#include <variant>
#include "tgbot/types/InputMediaPhoto.h"
#include "tgbot/types/InputMediaVideo.h"
#include "tgbot/types/UserProfilePhotos.h"
#include "tgbot/types/File.h"
#include "tgbot/types/ChatPermissions.h"
#include "tgbot/types/ChatMember.h"
#include "tgbot/types/InputMediaAnimation.h"
#include "tgbot/types/InputMediaAudio.h"
#include "tgbot/types/InputMediaDocument.h"
#include "tgbot/types/StickerSet.h"
#include "tgbot/types/InlineQueryResult.h"
#include "tgbot/types/LabeledPrice.h"
#include "tgbot/types/ShippingOption.h"
#include "tgbot/types/PassportElementError.h"
#include "tgbot/types/GameHighScore.h"
#include "tgbot/types/Update.h"
#include "tgbot/types/WebhookInfo.h"

//@brief contains all endpoints for the Telegram Bot Api

namespace tgbot
{
	class Endpoints
	{
	public:
		//pointer of itself
		typedef std::shared_ptr<Endpoints> ptr;

	private:
		//member variables
		std::string m_token; //needed for the endpoints

	public:
		//constructors
		//@param token: token which the member functions need for the requests they make
		Endpoints(const std::string &token);

		//member functions
		/*
		 * @brief get updates for the bot
		 * @param offset: Identifier of the first update to be returned. Must be greater by one than the highest among the identifiers of previously received updates.
		 * 				By default, updates starting with the earliest unconfirmed update are returned. An update is considered confirmed as soon as getUpdates is called with
		 * 				an offset higher than its update_id. The negative offset can be specified to retrieve updates starting from -offset update from the end
		 * 				of the updates queue. All previous updates will forgotten.
		 * @param limit: Limits the number of updates to be retrieved. Values between 1—100 are accepted. Defaults to 100.
		 * @param timeout: Timeout in seconds for long polling. Defaults to 0, i.e. usual short polling. Should be positive, short polling should be used for testing purposes only.
		 * @param allowed_updates: List the types of updates you want your bot to receive. For example, specify [“message”, “edited_channel_post”, “callback_query”] to only
		 * 				receive updates of these types. See Update for a complete list of available update types. Specify an empty list to receive all updates regardless
		 * 				of type (default). If not specified, the previous setting will be used. Please note that this parameter doesn't affect updates created
		 * 				before the call to the getUpdates, so unwanted updates may be received for a short period of time.
		 * @return Update object
		 */
		std::vector<Update::ptr> getUpdates(const int &offset, const int &limit = 100, const int &timeout = 0,
				const std::vector<std::string> &allowed_updates = std::vector<std::string>()) const;

		/*
		 * @brief sets the webhook for the bot
		 * @param url: where updates shall be sent to
		 * @param certificate: Upload your public key certificate so that the root certificate in use can be checked.
		 * @param max_connections: Maximum allowed number of simultaneous HTTPS connections to the webhook for update delivery, 1-100.
		 * 				Defaults to 40. Use lower values to limit the load on your bot‘s server, and higher values to increase your bot’s throughput.
		 * @param allowed_updates: List the types of updates you want your bot to receive. For example, specify [“message”, “edited_channel_post”, “callback_query”] to only receive
		 * 				updates of these types. See Update for a complete list of available update types. Specify an empty list to receive all updates regardless
		 * 				of type (default). If not specified, the previous setting will be used. Please note that this parameter doesn't affect updates created
		 * 				before the call to the setWebhook, so unwanted updates may be received for a short period of time.
		 * @return true on success
		 */
		bool setWebhook(const std::string &url, const tools::InputFile::ptr &certificate = std::make_shared<tools::InputFile>(""), const int &max_connections = 40,
				const std::vector<std::string> &allowed_updates = std::vector<std::string>()) const;

		/*
		 * @brief deletes the webhook
		 * @return true on success
		 */
		bool deleteWebhook() const;

		/*
		 * @brief gets webhook information
		 * @return WebhookInfo object
		 */
		WebhookInfo::ptr getWebhookInfo() const;

		/*
		 * @brief executes endpoint getMe
		 * @return User object of the bot
		 */
		User::ptr getMe() const;

		/*
		 * @brief sends a message to the chat
		 * @param chat_id: states chat id to which the message shall be sent
		 * @param text: text which is sent as a message
		 * @param parse_mode: how message is parsed; can either be HTML or Markdown
		 * @param disable_web_page_preview: whether messages which contain a website link shall show a preview
		 * @param disable_notification: whether users shall be notified about the sent message
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the message
		 * @return sent message
		 */
		Message::ptr sendMessage(const long long &chat_id, const std::string &text, const std::string &parse_mode = "", const bool &disable_web_page_preview = true,
				const bool &disable_notification = false, const int &reply_to_message_id = 0, const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief forwards a message from one chat to another
		 * @param chat_id: to which chat the message is sent
		 * @param from_chat_id: from which chat the message to send is got
		 * @param message_id: message id in chat from_chat_id which belongs to message which is to send
		 * @param disable_notification: whether users shall be notified about the message
		 * @return sent message
		 */
		Message::ptr forwardMessage(const long long &chat_id, const long long &from_chat_id, const int &message_id, const bool &disable_notification = false) const;

		/*
		 * @brief sends a photo to the chat
		 * @param chat_id: states chat id to which the photo shall be sent
		 * @param photo: photo which is sent; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param caption: caption of the photo
		 * @param parse_mode: refers to the caption how it shall be parsed; either HTML of Markdown
		 * @param disable_notification: whether users shall be notified about the sent photo
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the photo
		 * @return sent message
		 */
		Message::ptr sendPhoto(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &photo, const std::string &caption = "",
				const std::string &parse_mode = "", const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief sends an audio to the chat
		 * @param chat_id: states chat id to which the audio shall be sent
		 * @param audio: audio which is sent; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param thumb: thumbnail of the audio; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param caption: caption of the audio
		 * @param parse_mode: refers to the caption how it shall be parsed; either HTML of Markdown
		 * @param duration: duration of the audio
		 * @param performer: performer of the audio
		 * @param title: title of the audio
		 * @param disable_notification: whether users shall be notified of the sent audio
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the audio
		 * @return sent message
		 */
		Message::ptr sendAudio(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &audio, const std::variant<std::string,
				tools::InputFile::ptr> &thumb, const std::string &caption = "", const std::string &parse_mode = "", const int &duration = 0,
				const std::string &performer = "", const std::string &title = "", const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief sends a document to the chat
		 * @param chat_id: states chat id to which the document shall be sent
		 * @param document: document which is sent; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param thumb: thumbnail of the document; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param caption: caption of the document
		 * @param parse_mode: refers to the caption how it shall be parsed; either HTML of Markdown
		 * @param disable_notification: whether users shall be notified of the sent document
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the audio
		 * @return sent message
		 */
		Message::ptr sendDocument(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &document, const std::variant<std::string, tools::InputFile::ptr> &thumb,
				const std::string &caption = "", const std::string &parse_mode = "", const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief sends a video to the chat
		 * @param chat_id: states chat id to which the video shall be sent
		 * @param video: video which is sent; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param thumb: thumbnail of the video; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param duration: video's duration
		 * @param width: video's width
		 * @param height: video's height
		 * @param caption: caption of the video
		 * @param parse_mode: refers to the caption how it shall be parsed; either HTML of Markdown
		 * @param supports_streaming: state whether video is suitable for streaming
		 * @param disable_notification: whether users shall be notified of the sent video
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the audio
		 * @return sent message
		 */
		Message::ptr sendVideo(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &video, const std::variant<std::string,
				tools::InputFile::ptr> &thumb, const int &duration = 0, const int &width = 0, const int &height = 0, const std::string &caption = "",
				const std::string &parse_mode = "", const bool &supports_streaming = false, const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief sends a animation to the chat
		 * @param chat_id: states chat id to which the animation shall be sent
		 * @param animation: animation which is sent; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param thumb: thumbnail of the animation; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param duration: animation's duration
		 * @param width: animation's width
		 * @param height: animation's height
		 * @param caption: caption of the animation
		 * @param parse_mode: refers to the caption how it shall be parsed; either HTML of Markdown
		 * @param disable_notification: whether users shall be notified of the sent animation
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the audio
		 * @return sent message
		 */
		Message::ptr sendAnimation(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &animation,
				const std::variant<std::string, tools::InputFile::ptr> &thumb, const int &duration = 0, const int &width = 0, const int &height = 0,
				const std::string &caption = "", const std::string &parse_mode = "", const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief sends a voice message to the chat
		 * @param chat_id: states chat id to which the voice message shall be sent
		 * @param voice: voice message which is sent; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param caption: caption of the voice message
		 * @param parse_mode: refers to the caption how it shall be parsed; either HTML of Markdown
		 * @param duration: voice message's duration
		 * @param disable_notification: whether users shall be notified of the sent voice message
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the voice message
		 * @return sent message
		 */
		Message::ptr sendVoice(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &voice, const std::string &caption = "",
				const std::string &parse_mode = "", const int &duration = 0, const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief sends a video note to the chat
		 * @param chat_id: states chat id to which the video note shall be sent
		 * @param video_note: video note which is sent; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param thumb: thumbnail of the video note; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param duration: video note's duration
		 * @param length: video note's length
		 * @param disable_notification: whether users shall be notified of the sent video note
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the video note
		 * @return sent message
		 */
		Message::ptr sendVideoNote(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &video_note,
				const std::variant<std::string, tools::InputFile::ptr> &thumb, const int &duration = 0, const int &length = 0,
				const bool &disable_notification = false, const int &reply_to_message_id = 0, const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief sends a media group to the chat
		 * @param chat_id: states chat id to which the video note shall be sent
		 * @param media: media vector which is sent; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param disable_notification: whether users shall be notified of the sent media group
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the media group
		 * @return vector of the sent messages
		 */
		std::vector<Message::ptr> sendMediaGroup(const long long &chat_id, const std::vector<std::variant<InputMediaPhoto::ptr, InputMediaVideo::ptr>> &media,
				const bool &disable_notification = false, const int &reply_to_message_id = 0, const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief sends a location to the chat
		 * @param chat_id: states chat id to which the location shall be sent
		 * @param latitude: location's latitude
		 * @param longitude: location's longitude
		 * @param live_period: interval in seconds between updated for live locations
		 * @param disable_notification: whether users shall be notified of the sent location
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the location
		 * @return sent message
		 */
		Message::ptr sendLocation(const long long &chat_id, const float &latitude, const float &longitude, const int &live_period = 0, const bool &disable_notification = false,
				const int &reply_to_message_id = 0, const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief edits the live locations
		 * @param latitude: location's latitude
		 * @param longitude: location's longitude
		 * @param chat_id: states chat id in which the location is which shall be edited
		 * @param message_id: states message id of location which shall be edited
		 * @param inline_message_id: states inline message id of live loaction which shall be edited
		 * @param reply_markup: keyboard which is appendended to the edited location
		 * @return edited messages
		 */
		Message::ptr editMessageLiveLocation(const float &latitude, const float &longitude, const long long &chat_id = 0, const int &message_id = 0,
				const std::string &inline_message_id = "", const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief stops the live locations
		 * @param chat_id: states chat id in which the location is which shall be stopped
		 * @param message_id: states message id of live loacation which shall be stopped
		 * @param inline_message_id: states inline message id of live location which shall be stopped
		 * @param reply_markup: keyboard which is appendended to the stopped location
		 * @return edited messages
		 */
		Message::ptr stopMessageLiveLocation(const long long &chat_id = 0, const int &message_id = 0, const std::string &inline_message_id = "",
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief sends a venue to the chat
		 * @param chat_id: states chat id to which the venue shall be sent
		 * @param latitude: venue's latitude
		 * @param longitude: venue's longitude
		 * @param title: venue's title
		 * @param address: venue's address
		 * @param foursquare_id: foursquare identifier
		 * @param foursquare_type: e. g. "food", "art", "restaurant"
		 * @param disable_notification: whether users shall be notified of the sent venue
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the venue
		 * @return sent message
		 */
		Message::ptr sendVenue(const long long &chat_id, const float &latitude, const float &longitude, const std::string &title = "", const std::string &address = "",
				const std::string &foursquare_id = "", const std::string &foursquare_type = "", const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief sends a contact to the chat
		 * @param chat_id: states chat id to which the contact shall be sent
		 * @param phone_number: contact's phone number
		 * @param first_name: contact's first name
		 * @param first_name: contact's last name
		 * @param first_name: contact's vcard
		 * @param disable_notification: whether users shall be notified of the sent contact
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the contact
		 * @return sent message
		 */
		Message::ptr sendContact(const long long &chat_id, const std::string &phone_number, const std::string &first_name, const std::string &last_name = "",
				const std::string &vcard = "", const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief sends a poll to the chat
		 * @param chat_id: states chat id to which the poll shall be sent
		 * @param question: poll's question
		 * @param options: vector of arrays where every element represents one answer option
		 * @param disable_notification: whether users shall be notified of the sent poll
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the poll
		 * @return sent message
		 */
		Message::ptr sendPoll(const long long &chat_id, const std::string &question, const std::vector<std::string> &options,
				const bool &disable_notification = false, const int &reply_to_message_id = 0, const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief changes bot's status for 5 seconds
		 * @param chat_id: states chat id to which the proper status will be shown
		 * @param action: look up on Telgram bot api documentation which strings are allowed; changes the bot's status properly
		 * @return true on success
		 */
		bool sendChatAction(const long long &chat_id, const std::string &action) const;

		/*
		 * @brief get user's profile photos
		 * @param chat_id: user id of which the photos shall be got
		 * @param offset: index of photo which shall be returned starting with 0; pass -1 if all shall be got
		 * @return UserProfilePhotos json object
		 */
		UserProfilePhotos::ptr getUserProfilePhotos(const int &user_id, const int &offset = 0, const int &limit = 100) const;

		/*
		 * @brief shows path on Telegram servers where file can be downloaded from
		 * @brief file can be downloaded from https://api.telegram.org/file/bot<token>/<file_path> wherby file_path is member of object File
		 * @param file_id: file id from file we want to get information from and download possibly
		 * @return File
		 */
		File::ptr getFile(const std::string &file_id) const;

		/*
		 * @brief bans/kicks a Telegram user
		 * @brief by default, users are banned forever
		 * @param chat_id: chat id from which the user shall be banned
		 * @param user_id: Telegram user which shall be banned
		 * @param until_date: Date when the user will be unbanned, unix time. If user is banned for more than 366 days or less than 30 seconds from the current time
		 * 		they are considered to be banned forever
		 * @return true on success
		 */
		bool kickChatMember(const long long &chat_id, const int &user_id, const int &until_date = 0) const;

		/*
		 * @brief unbans a Telegram user
		 * @param chat_id: chat id from which the user shall be unbanned
		 * @param user_id: Telegram user which shall be unbanned
		 * @return true on success
		 */
		bool unbanChatMember(const long long &chat_id, const int &user_id) const;

		/*
		 * @brief sets permissions for the user
		 * @param chat_id: chat in which the user's permissions are edited
		 * @param user_id: Telegram user whose permissions shall be updated
		 * @param permissions: object which contains all the abilities/permissions with the proper bool
		 * @param user_id: Date when restrictions will be lifted for the user, unix time. If user is restricted for more than 366 days or less than 30 seconds from the current time,
		 * 		they are considered to be restricted forever
		 * @return true on success
		 */
		bool restrictChatMember(const long long &chat_id, const int &user_id, const ChatPermissions::ptr &permissions, const int &until_date = 0) const;

		/*
		 * @brief sets permissions for the user
		 * @param chat_id: chat in which the user's permissions are edited
		 * @param user_id: Telegram user whose permissions shall be updated
		 * @param can_change_info: change group info
		 * @param can_post_messages: send a message
		 * @param can_edit_messages: edit a message
		 * @param can_delete_messages: delete message
		 * @param can_invite_users: invite others to group
		 * @param can_restrict_members: restrict other members
		 * @param can_pin_messages: pin a message in a group
		 * @param can_promote_members: promote other group members
		 * @return true on success
		 */
		bool promoteChatMember(const long long &chat_id, const int &user_id, const bool &can_change_info, const bool &can_post_messages, const bool &can_edit_messages,
				const bool &can_delete_messages, const bool &can_invite_users, const bool &can_restrict_members, const bool &can_pin_messages,
				const bool &can_promote_members) const;

		/*
		 * @brief sets default permissions an entire group
		 * @param chat_id: chat in which the default permissions are edited
		 * @param permissions: the default permissions by passing type ChatPermissions
		 * @return true on success
		 */
		bool setChatPermissions(const long long &chat_id, const ChatPermissions::ptr &permissions) const;

		/*
		 * @brief accesses group's invite link
		 * @param chat_id: chat from which the invite link shall be got
		 * @return true on success
		 */
		bool exportChatInviteLink(const long long &chat_id) const;

		/*
		 * @brief sets the photo of a group
		 * @param chat_id: chat in which group photo shall be changed
		 * @param photo: photo which shall be used as a group photo
		 * @return true on success
		 */
		bool setChatPhoto(const long long &chat_id, const tools::InputFile::ptr &photo) const;

		/*
		 * @brief deletes the photo of a group
		 * @param chat_id: chat in which group photo shall be deleted
		 * @return true on success
		 */
		bool deleteChatPhoto(const long long &chat_id) const;

		/*
		 * @brief sets the title of a group
		 * @param chat_id: chat in which group title shall be changed
		 * @param title: the corresponding title
		 * @return true on success
		 */
		bool setChatTitle(const long long &chat_id, const std::string &title) const;

		/*
		 * @brief sets the description of a group
		 * @param chat_id: chat in which group description shall be changed
		 * @param description: the corresponding description
		 * @return true on success
		 */
		bool setChatDescription(const long long &chat_id, const std::string &description) const;

		/*
		 * @brief pins a message in the group
		 * @param chat_id: chat in which the message shall be pinned
		 * @param message_id: id of the message which shall be pinned in the group
		 * @param disable_notification: whether users shall be notified of the pinned message
		 * @return true on success
		 */
		bool pinChatMessage(const long long &chat_id, const int &message_id, const bool &disable_notification = false) const;

		/*
		 * @brief unpins the actual pin message in the group
		 * @param chat_id: chat in which the pinned message shall be unpinned
		 * @return true on success
		 */
		bool unpinChatMessage(const long long &chat_id) const;

		/*
		 * @brief lets bot leave the chat
		 * @param chat_id: id of chat which bot shall leave
		 * @return true on success
		 */
		bool leaveChat(const long long &chat_id) const;

		/*
		 * @brief gets Chat object
		 * @param chat_id: id of chat from which we want some information
		 * @return true on success
		 */
		Chat::ptr getChat(const long long &chat_id) const;

		/*
		 * @brief gets all administrators
		 * @param chat_id: id of chat from which we want the admins
		 * @return array with all the admins
		 */
		std::vector<ChatMember::ptr> getChatAdministrators(const long long &chat_id) const;

		/*
		 * @brief gets amount of group members
		 * @param chat_id: id of chat from which we want the amount of group members
		 * @return the amount as an integer
		 */
		int getChatMembersCount(const long long &chat_id) const;

		/*
		 * @brief gets ChatMember object of one group member
		 * @param chat_id: id of chat which refers to the ChatMember object
		 * @param user_id: id of user whose information we want
		 * @return ChatMember of user in the group
		 */
		ChatMember::ptr getChatMember(const long long &chat_id, const int &user_id) const;

		/*
		 * @brief sets a sticker set which can be used in the group
		 * @param chat_id: id of chat in which we want to enable the sticker set
		 * @param sticker_set_name: name of the sticker set which we enable in the chat
		 * @return true on success
		 */
		bool setChatStickerSet(const long long &chat_id, const std::string &sticker_set_name) const;

		/*
		 * @brief deletes a sticker set which can be used in the group
		 * @param chat_id: id of chat in which we want to delete the sticker set
		 * @return true on success
		 */
		bool deleteChatStickerSet(const long long &chat_id) const;

		/*
		 * @brief answers a callback query from an inline keyboard
		 * @param callback_query_id: unique identifier from a callback query
		 * @param text: text of the notification
		 * @param show_alert: whether user shall get a notification
		 * @param url: user is asked to open that url
		 * @param cache_time: time the answer is saved on client side
		 * @return true on success
		 */
		bool answerCallbackQuery(const std::string &callback_query_id, const std::string &text = "", const bool &show_alert = false, const std::string &url = "",
				const int &cache_time = 0) const;

		/*
		 * @brief edits an already sent message
		 * @param text: text with which the message gets substituted
		 * @param chat_id: id of chat in which the message is which shall be edited
		 * @param message_id: id of message which shall be edited
		 * @param inline_message_id: id of message which contains an inline keyboard
		 * @param parse_mode: how message shall be parsed
		 * @param disable_web_page_preview: whether users shall be notified of the sent poll
		 * @param reply_markup: keyboard which is sent with the message
		 * @return new edited Message
		 */
		Message::ptr editMessageText(const std::string &text, const long long &chat_id = 0, const int &message_id = 0, const std::string &inline_message_id = "",
				const std::string &parse_mode = "", const bool &disable_web_page_preview = false, const Reply::ptr reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief edits an already sent message
		 * @param chat_id: id of chat in which the message is which shall be edited
		 * @param message_id: id of message which shall be edited
		 * @param inline_message_id: id of message which contains an inline keyboard
		 * @param caption: text with which the message's caption gets substituted
		 * @param parse_mode: how caption shall be parsed
		 * @param reply_markup: keyboard which is sent with the message
		 * @return new edited Message
		 */
		Message::ptr editMessageCaption(const long long &chat_id = 0, const int &message_id = 0, const std::string &inline_message_id = "", const std::string &caption = 0,
				const std::string &parse_mode = "", const Reply::ptr reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief edits an already sent message media
		 * @param chat_id: id of chat in which the message media is which shall be edited
		 * @param message_id: id of message whose media shall be edited
		 * @param inline_message_id: id of message which contains an inline keyboard
		 * @param media: message media with which the old message's media gets substituted
		 * @param reply_markup: keyboard which is sent with the message
		 * @return new edited Message
		 */
		Message::ptr editMessageMedia(const std::variant<InputMediaAnimation::ptr, InputMediaAudio::ptr, InputMediaDocument::ptr, InputMediaPhoto::ptr,
				InputMediaVideo::ptr> &media, const long long &chat_id = 0, const int &message_id = 0, const std::string &inline_message_id = "",
				const Reply::ptr reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief edits an already sent keyboard
		 * @param reply_markup: keyboard which is sent with the message
		 * @param chat_id: id of chat in which the keyboard is which shall be edited
		 * @param message_id: id of message whose keyboard shall be edited
		 * @param inline_message_id: id of message which contains an inline keyboard
		 * @return new edited Message
		 */
		Message::ptr editMessageReplyMarkup(const Reply::ptr &reply_markup, const long long &chat_id = 0, const int &message_id = 0,
				const std::string &inline_message_id = "") const;

		/*
		 * @brief stops a running poll
		 * @param chat_id: id of chat in which the poll is which shall be stopped
		 * @param message_id: id of message with the poll
		 * @param reply_markup: keyboard which is sent with the message
		 * @return Poll object with final results
		 */
		Poll::ptr stopPoll(const long long &chat_id, const int &message_id, const Reply::ptr reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief eletes a message
		 * @param chat_id: id of chat in which the message is which shall be deleted
		 * @param message_id: id of message which shall be deleted
		 * @return true on success
		 */
		bool deleteMessage(const long long &chat_id, const int &message_id) const;

		/*
		 * @brief sends a sticker to the chat
		 * @param chat_id: states chat id to which the sticker shall be sent
		 * @param sticker: sticker which is sent; can be url, file_id to file on Telegram server, InputFile with file on own machine
		 * @param disable_notification: whether users shall be notified of the sent animation
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the sticker
		 * @return sent message
		 */
		Message::ptr sendSticker(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &sticker, const bool &disable_notification = false,
				const int &reply_to_message_id = 0, const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief gets a StickerSet
		 * @param name: sticker set's name
		 * @return StickerSet object
		 */
		StickerSet::ptr getStickerSet(const std::string &name) const;

		/*
		 * @brief uploads a new sticker
		 * @param user_id: user id of sticker file owner
		 * @param png_sticker: the sticker itself
		 * @return File object
		 */
		File::ptr uploadStickerFile(const int &user_id, const tools::InputFile::ptr &png_sticker) const;

		/*
		 * @brief uploads a new sticker
		 * @param user_id: user id of sticker file owner
		 * @param name: name of sticker set
		 * @param title: sticker set title
		 * @param png_sticker: the sticker itself
		 * @param emojis: one or more emojis correspoding to the sticker
		 * @param contains_mask: Pass True, if a set of mask stickers should be created
		 * @param mask_position: A JSON-serialized object for position where the mask should be placed on faces
		 * @return true on success
		 */
		bool createNewStickerSet(const int &user_id, const std::string &name, const std::string &title, const std::variant<std::string, tools::InputFile::ptr> &png_sticker,
				const std::string &emojis, const bool &contains_mask = false, const MaskPosition::ptr &mask_position = std::make_shared<MaskPosition>()) const;

		/*
		 * @brief adds a sticker to a created set by a bot
		 * @param user_id: user id of sticker set owner
		 * @param name: name of sticker set
		 * @param title: sticker set title
		 * @param png_sticker: the sticker itself
		 * @param emojis: one or more emojis correspoding to the sticker
		 * @param mask_position: A JSON-serialized object for position where the mask should be placed on faces
		 * @return true on success
		 */
		bool addStickerToSet(const int &user_id, const std::string &name, const std::string &title, const std::variant<std::string, tools::InputFile::ptr> &png_sticker,
				const std::string &emojis, const MaskPosition::ptr &mask_position = std::make_shared<MaskPosition>()) const;

		/*
		 * @brief moves a sticker in a set
		 * @param sticker: file identifier of the sticker
		 * @param position: New sticker position in the set, zero-based
		 * @return true on success
		 */
		bool setStickerPositionInSet(const std::string &sticker, const int &position) const;

		/*
		 * @brief deletes a sticker from a set
		 * @param sticker: file identifier of the sticker
		 * @return true on success
		 */
		bool deleteStickerFromSet(const std::string &sticker) const;

		/*
		 * @brief answers inline queries
		 * @param inline_query_id: id for answered inline query
		 * @param results: array of results for the inline query
		 * @param cache_time: The maximum amount of time in seconds that the result of the inline query may be cached on the server. Defaults to 300.
		 * @param is_personal: Pass True, if results may be cached on the server side only for the user that sent the query.
		 * 			By default, results may be returned to any user who sends the same query
		 * @param next_offset: Pass the offset that a client should send in the next query with the same text to receive more results.
		 * 			Pass an empty string if there are no more results or if you don‘t support pagination. Offset length can’t exceed 64 bytes.
		 * @param switch_pm_text: If passed, clients will display a button with specified text that switches the user to a private chat with the bot and
		 * 			sends the bot a start message with the parameter switch_pm_parameter
		 * @param switch_pm_parameter: Deep-linking parameter for the /start message sent to the bot when user presses the switch button. 1-64 characters,
		 * 			only A-Z, a-z, 0-9, _ and - are allowed.
		 * @return true on success
		 */
		bool answerInlineQuery(const std::string &inline_query_id, const std::vector<InlineQueryResult::ptr> &results, const int &cache_time = 300,
				const bool &is_personal = false, const std::string &next_offset = "", const std::string &switch_pm_text = "",
				const std::string &switch_pm_parameter = "") const;

		/*
		 * @brief sends an invoice to the chat
		 * @param chat_id: target for the private chat
		 * @param title: product name
		 * @param description: product description
		 * @param payload: Bot-defined invoice payload, 1-128 bytes. This will not be displayed to the user, use for your internal processes.
		 * @param provider_token: Payments provider token, obtained via Botfather
		 * @param start_parameter: Unique deep-linking parameter that can be used to generate this invoice when used as a start parameter
		 * @param currency: Three-letter ISO 4217 currency code, see more on currencies
		 * @param prices: Price breakdown, a list of components (e.g. product price, tax, discount, delivery cost, delivery tax, bonus, etc.)
		 * @param provider_data: JSON-encoded data about the invoice, which will be shared with the payment provider.
		 * 			A detailed description of required fields should be provided by the payment provider.
		 * @param photo_url: URL of the product photo for the invoice. Can be a photo of the goods or a marketing image for a service.
		 * 			People like it better when they see what they are paying for.
		 * @param photo_size: Photo size
		 * @param photo_width: Photo width
		 * @param photo_height: Photo height
		 * @param need_name: Pass True, if you require the user's full name to complete the order
		 * @param need_phone_number: Pass True, if you require the user's phone number to complete the order
		 * @param need_email: Pass True, if you require the user's email address to complete the order
		 * @param need_shipping_address: Pass True, if you require the user's shipping address to complete the order
		 * @param send_phone_number_to_provider: Pass True, if user's phone number should be sent to provider
		 * @param send_email_to_provider: Pass True, if user's email address should be sent to provider
		 * @param is_flexible: Pass True, if the final price depends on the shipping method
		 * @param disable_notification: whether users shall be notified of the sent invoice
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the invoice
		 * @return sent message
		 */
		Message::ptr sendInvoice(const long long &chat_id, const std::string &title, const std::string &description, const std::string &payload,
				const std::string &provider_token, const std::string &start_parameter, const std::string &currency, const std::vector<LabeledPrice::ptr> &prices,
				const std::string &provider_data = "", const std::string &photo_url = "", const int &photo_size = 0, const int &photo_width = 0,
				const int &photo_height = 0, const bool &need_name = false, const bool &need_phone_number = false, const bool &need_email = false,
				const bool &need_shipping_address = false, const bool &send_phone_number_to_provider = false, const bool &send_email_to_provider = false,
				const bool &is_flexible = false, const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const;

		/*
		 * @brief answers a shipping query
		 * @param shipping_query_id: Unique identifier for the query to be answered
		 * @param ok: Specify True if delivery to the specified address is possible and False if there are any problems
		 * 			(for example, if delivery to the specified address is not possible)
		 * @param shipping_options: Required if ok is True. A JSON-serialized array of available shipping options.
		 * @param error_message: Required if ok is False. Error message in human readable form that explains why it is impossible to complete the order
		 * 			(e.g. "Sorry, delivery to your desired address is unavailable'). Telegram will display this message to the user.
		 * @return true on success
		 */
		bool answerShippingQuery(const std::string &shipping_query_id, const bool &ok,
				const std::vector<ShippingOption::ptr> &shipping_options = std::vector<ShippingOption::ptr>(), const std::string &error_message = "") const;

		/*
		 * @brief answers a pre checkout query
		 * @param pre_checkout_query_id: Unique identifier for the query to be answered
		 * @param ok: Specify True if everything is alright (goods are available, etc.) and the bot is ready to proceed with the order. Use False if there are any problems.
		 * @param error_message: Required if ok is False. Error message in human readable form that explains the reason for failure to proceed with the checkout
		 * 			(e.g. "Sorry, somebody just bought the last of our amazing black T-shirts while you were busy filling out your payment details.
		 * 			Please choose a different color or garment!"). Telegram will display this message to the user.
		 * @return true on success
		 */
		bool answerPreCheckoutQuery(const std::string &pre_checkout_query_id, const bool &ok, const std::string &error_message = "") const;

		/*
		 * @brief answers a pre checkout query
		 * @param user_id: Telegram user id
		 * @param ok: array describing the errors
		 * @return true on success
		 */
		bool setPassportDataErrors(const int &user_id, const bool &ok, const std::vector<PassportElementError::ptr> &errors) const;

		/*
		 * @brief send a game
		 * @param chat_id: id of the chat
		 * @param game_short_name: Short name of the game, serves as the unique identifier for the game. Set up your games via Botfather.
		 * @param disable_notification: whether users shall be notified of the sent game
		 * @param reply_to_message_id: to which message this is a reply
		 * @param reply_markup: keyboard which is sent with the game
		 * @return sent Message
		 */
		Message::ptr sendGame(const long long &chat_id, const std::string &game_short_name, const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const InlineKeyboardMarkup::ptr &reply_markup = std::make_shared<InlineKeyboardMarkup>()) const;

		/*
		 * @brief sets a game score
		 * @param user_id: Telegram user id
		 * @param score: score which user achieved
		 * @param force: Pass True, if the high score is allowed to decrease. This can be useful when fixing mistakes or banning cheaters
		 * @param disable_edit_message: Pass True, if the game message should not be automatically edited to include the current scoreboard
		 * @param chat_id: id of the chat
		 * @param message_id: id of the message
		 * @param inline_message_id: id of the inline message
		 * @return sent Message
		 */
		Message::ptr setGameScore(const int &user_id, const int &score, const bool &force = false, const bool &disable_edit_message = false, const long long &chat_id = 0,
				const int &message_id = 0, const std::string &inline_message_id = "") const;

		/*
		 * @brief gets a game score
		 * @param user_id: Telegram user id
		 * @param chat_id: id of the chat
		 * @param message_id: id of the message
		 * @param inline_message_id: id of the inline message
		 * @return sent Message
		 */
		std::vector<GameHighScore::ptr> getGameHighScores(const int &user_id, const long long &chat_id = 0, const int &message_id = 0,
				const std::string &inline_message_id = "") const;
	};
}

#endif
