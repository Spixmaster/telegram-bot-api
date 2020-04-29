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
#include "tgbot/types/BotCommand.h"

namespace tgbot
{
	/**
	 * @class Endpoints
	 * @brief Contains all endpoints for the Telegram Bot API.
	 */
	class Endpoints
	{
	public:
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Endpoints> ptr;

	private:
		//Member variables
		/**
		 * @var m_token
		 * @brief The token from the bot which is used for identification.
		 */
		std::string m_token;

	public:
		//Constructors
		/**
		 * @param[in] token The token from the bot which is used for identification.
		 */
		Endpoints(const std::string &token);

		//member functions
		/**
		 * @brief Use this method to receive incoming updates using long polling (wiki).
		 * @note 1. This method will not work if an outgoing webhook is set up.
		 * @note 2. In order to avoid getting duplicate updates, recalculate offset after each server response.
		 * @param[in] offset Identifier of the first update to be returned. Must be greater by one than the highest among the identifiers of previously received updates. By default, updates starting with the earliest unconfirmed update are returned. An update is considered confirmed as soon as getUpdates is called with an offset higher than its update_id. The negative offset can be specified to retrieve updates starting from -offset update from the end of the updates queue. All previous updates will forgotten.
		 * @param[in] limit Limits the number of updates to be retrieved. Values between 1-100 are accepted. Defaults to 100.
		 * @param[in] timeout Timeout in seconds for long polling. Defaults to 0, i.e. usual short polling. Should be positive, short polling should be used for testing purposes only.
		 * @param[in] allowed_updates A JSON-serialized list of the update types you want your bot to receive. For example, specify [“message”, “edited_channel_post”, “callback_query”] to only receive updates of these types. See Update for a complete list of available update types. Specify an empty list to receive all updates regardless of type (default). If not specified, the previous setting will be used. Please note that this parameter doesn't affect updates created before the call to the getUpdates, so unwanted updates may be received for a short period of time.
		 * @return An Array of Update objects is returned.
		 */
		std::vector<Update::ptr> getUpdates(const int &offset, const int &limit = 100, const int &timeout = 0,
				const std::vector<std::string> &allowed_updates = std::vector<std::string>()) const noexcept;

		/**
		 * @brief Use this method to specify a url and receive incoming updates via an outgoing webhook. Whenever there is an update for the bot, we will send an HTTPS POST request to the specified url, containing a JSON-serialized Update. In case of an unsuccessful request, we will give up after a reasonable amount of attempts.
		 * @details If you'd like to make sure that the Webhook request comes from Telegram, we recommend using a secret path in the URL, e.g. https://www.example.com/\<token\>. Since nobody else knows your bot‘s token, you can be pretty sure it’s us.
		 * @note 1. You will not be able to receive updates using getUpdates for as long as an outgoing webhook is set up.
		 * @note 2. To use a self-signed certificate, you need to upload your public key certificate using certificate parameter. Please upload as InputFile, sending a String will not work.
		 * @note 3. Ports currently supported for Webhooks: 443, 80, 88, 8443.
		 * @param[in] url  	HTTPS url to send updates to. Use an empty string to remove webhook integration
		 * @param[in] certificate Upload your public key certificate so that the root certificate in use can be checked. See our self-signed guide for details.
		 * @param[in] max_connections Maximum allowed number of simultaneous HTTPS connections to the webhook for update delivery, 1-100. Defaults to 40. Use lower values to limit the load on your bot‘s server, and higher values to increase your bot’s throughput.
		 * @param[in] allowed_updates A JSON-serialized list of the update types you want your bot to receive. For example, specify [“message”, “edited_channel_post”, “callback_query”] to only receive updates of these types. See Update for a complete list of available update types. Specify an empty list to receive all updates regardless of type (default). If not specified, the previous setting will be used. Please note that this parameter doesn't affect updates created before the call to the setWebhook, so unwanted updates may be received for a short period of time.
		 * @return Returns True on
		 */
		bool setWebhook(const std::string &url, const tools::InputFile::ptr &certificate = std::make_shared<tools::InputFile>(""), const int &max_connections = 40,
				const std::vector<std::string> &allowed_updates = std::vector<std::string>()) const noexcept;

		/**
		 * @brief Use this method to remove webhook integration if you decide to switch back to getUpdates.
		 * @return Returns True on success.
		 */
		bool deleteWebhook() const noexcept;

		/**
		 * @brief Use this method to get current webhook status. Requires no parameters.
		 * @return On success, returns a WebhookInfo object. If the bot is using getUpdates, will return an object with the url field empty.
		 */
		WebhookInfo::ptr getWebhookInfo() const noexcept;

		/**
		 * @brief A simple method for testing your bot's auth token. Requires no parameters.
		 * @return Returns basic information about the bot in form of a User object.
		 */
		User::ptr getMe() const noexcept;

		/**
		 * @brief Use this method to send text messages.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] text Text of the message to be sent, 1-4096 characters after entities parsing
		 * @param[in] parse_mode Mode for parsing entities in the message text. See formatting options for more details.
		 * @param[in] disable_web_page_preview Disables link previews for links in this message
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
		 * @return On success, the sent Message is returned.
		 */
		Message::ptr sendMessage(const long long &chat_id, const std::string &text, const std::string &parse_mode = "", const bool &disable_web_page_preview = true,
				const bool &disable_notification = false, const int &reply_to_message_id = 0, const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to forward messages of any kind.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] from_chat_id Unique identifier for the chat where the original message was sent (or channel username in the format \@channelusername)
		 * @param[in] message_id Message identifier in the chat specified in from_chat_id
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @return On success, the sent Message is returned.
		 */
		Message::ptr forwardMessage(const long long &chat_id, const long long &from_chat_id, const int &message_id, const bool &disable_notification = false) const noexcept;

		/**
		 * @brief Use this method to send photos.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] photo Photo to send. Pass a file_id as String to send a photo that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get a photo from the Internet, or upload a new photo using multipart/form-data. More info on Sending Files »
		 * @param[in] caption Photo caption (may also be used when resending photos by file_id), 0-1024 characters after entities parsing
		 * @param[in] parse_mode Mode for parsing entities in the photo caption. See formatting options for more details.
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
		 * @return
		 */
		Message::ptr sendPhoto(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &photo, const std::string &caption = "",
				const std::string &parse_mode = "", const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to send audio files, if you want Telegram clients to display them in the music player. Your audio must be in the .MP3 or .M4A format.
		 * @details For sending voice messages, use the sendVoice method instead.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] audio Audio file to send. Pass a file_id as String to send an audio file that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get an audio file from the Internet, or upload a new one using multipart/form-data.
		 * @param[in] caption Audio caption, 0-1024 characters after entities parsing
		 * @param[in] parse_mode Mode for parsing entities in the audio caption. See formatting options for more details.
		 * @param[in] duration Duration of the audio in seconds
		 * @param[in] performer Performer
		 * @param[in] title Track name
		 * @param[in] thumb Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. The thumbnail should be in JPEG format and less than 200 kB in size. A thumbnail‘s width and height should not exceed 320. Ignored if the file is not uploaded using multipart/form-data. Thumbnails can’t be reused and can be only uploaded as a new file, so you can pass “attach://\<file_attach_name\>” if the thumbnail was uploaded using multipart/form-data under \<file_attach_name\>.
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
		 * @return On success, the sent Message is returned. Bots can currently send audio files of up to 50 MB in size, this limit may be changed in the future.
		 */
		Message::ptr sendAudio(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &audio, const std::string &caption = "",
				const std::string &parse_mode = "", const int &duration = 0, const std::string &performer = "", const std::string &title = "",
				const std::variant<std::string, tools::InputFile::ptr> &thumb = "", const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to send general files.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] document File to send. Pass a file_id as String to send a file that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get a file from the Internet, or upload a new one using multipart/form-data.
		 * @param[in] thumb Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. The thumbnail should be in JPEG format and less than 200 kB in size. A thumbnail‘s width and height should not exceed 320. Ignored if the file is not uploaded using multipart/form-data. Thumbnails can’t be reused and can be only uploaded as a new file, so you can pass “attach://\<file_attach_name\>” if the thumbnail was uploaded using multipart/form-data under \<file_attach_name\>.
		 * @param[in] caption Document caption (may also be used when resending documents by file_id), 0-1024 characters after entities parsing
		 * @param[in] parse_mode Mode for parsing entities in the document caption. See formatting options for more details.
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
		 * @return On success, the sent Message is returned. Bots can currently send files of any type of up to 50 MB in size, this limit may be changed in the future.
		 */
		Message::ptr sendDocument(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &document,
				const std::variant<std::string, tools::InputFile::ptr> &thumb = "", const std::string &caption = "", const std::string &parse_mode = "",
				const bool &disable_notification = false, const int &reply_to_message_id = 0, const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to send video files, Telegram clients support mp4 videos (other formats may be sent as Document).
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] video Video to send. Pass a file_id as String to send a video that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get a video from the Internet, or upload a new video using multipart/form-data.
		 * @param[in] duration Duration of sent video in seconds
		 * @param[in] width Video width
		 * @param[in] height Video height
		 * @param[in] thumb Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. The thumbnail should be in JPEG format and less than 200 kB in size. A thumbnail‘s width and height should not exceed 320. Ignored if the file is not uploaded using multipart/form-data. Thumbnails can’t be reused and can be only uploaded as a new file, so you can pass “attach://\<file_attach_name\>” if the thumbnail was uploaded using multipart/form-data under \<file_attach_name\>.
		 * @param[in] caption Video caption (may also be used when resending videos by file_id), 0-1024 characters after entities parsing
		 * @param[in] parse_mode Mode for parsing entities in the video caption. See formatting options for more details.
		 * @param[in] supports_streaming Pass True, if the uploaded video is suitable for streaming
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
		 * @return On success, the sent Message is returned. Bots can currently send video files of up to 50 MB in size, this limit may be changed in the future.
		 */
		Message::ptr sendVideo(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &video, const int &duration = 0, const int &width = 0,
				const int &height = 0, const std::variant<std::string, tools::InputFile::ptr> &thumb = "", const std::string &caption = "",
				const std::string &parse_mode = "", const bool &supports_streaming = false, const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to send animation files (GIF or H.264/MPEG-4 AVC video without sound).
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] animation Animation to send. Pass a file_id as String to send an animation that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get an animation from the Internet, or upload a new animation using multipart/form-data.
		 * @param[in] duration Duration of sent animation in seconds
		 * @param[in] width Animation width
		 * @param[in] height Animation height
		 * @param[in] thumb Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. The thumbnail should be in JPEG format and less than 200 kB in size. A thumbnail‘s width and height should not exceed 320. Ignored if the file is not uploaded using multipart/form-data. Thumbnails can’t be reused and can be only uploaded as a new file, so you can pass “attach://\<file_attach_name\>” if the thumbnail was uploaded using multipart/form-data under \<file_attach_name\>.
		 * @param[in] caption Animation caption (may also be used when resending animation by file_id), 0-1024 characters after entities parsing
		 * @param[in] parse_mode Mode for parsing entities in the animation caption. See formatting options for more details.
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
		 * @return On success, the sent Message is returned. Bots can currently send animation files of up to 50 MB in size, this limit may be changed in the future.
		 */
		Message::ptr sendAnimation(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &animation,
				const int &duration = 0, const int &width = 0, const int &height = 0, const std::variant<std::string, tools::InputFile::ptr> &thumb = "",
				const std::string &caption = "", const std::string &parse_mode = "", const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to send audio files, if you want Telegram clients to display the file as a playable voice message. For this to work, your audio must be in an .OGG file encoded with OPUS (other formats may be sent as Audio or Document).
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] voice Audio file to send. Pass a file_id as String to send a file that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get a file from the Internet, or upload a new one using multipart/form-data.
		 * @param[in] caption Voice message caption, 0-1024 characters after entities parsing
		 * @param[in] parse_mode Mode for parsing entities in the voice message caption. See formatting options for more details.
		 * @param[in] duration Duration of the voice message in seconds
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
		 * @return On success, the sent Message is returned. Bots can currently send voice messages of up to 50 MB in size, this limit may be changed in the future.
		 */
		Message::ptr sendVoice(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &voice, const std::string &caption = "",
				const std::string &parse_mode = "", const int &duration = 0, const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief As of v.4.0, Telegram clients support rounded square mp4 videos of up to 1 minute long. Use this method to send video messages.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] video_note Video note to send. Pass a file_id as String to send a video note that exists on the Telegram servers (recommended) or upload a new video using multipart/form-data. More info on Sending Files ». Sending video notes by a URL is currently unsupported
		 * @param[in] duration Duration of sent video in seconds
		 * @param[in] length Video width and height, i.e. diameter of the video message
		 * @param[in] thumb Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. The thumbnail should be in JPEG format and less than 200 kB in size. A thumbnail‘s width and height should not exceed 320. Ignored if the file is not uploaded using multipart/form-data. Thumbnails can’t be reused and can be only uploaded as a new file, so you can pass “attach://\<file_attach_name\>” if the thumbnail was uploaded using multipart/form-data under \<file_attach_name\>.
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
		 * @return On success, the sent Message is returned.
		 */
		Message::ptr sendVideoNote(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &video_note,
				const int &duration = 0, const int &length = 0, const std::variant<std::string, tools::InputFile::ptr> &thumb = "",
				const bool &disable_notification = false, const int &reply_to_message_id = 0, const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to send a group of photos or videos as an album.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] media A JSON-serialized array describing photos and videos to be sent, must include 2-10 items
		 * @param[in] disable_notification
		 * @param[in] reply_to_message_id
		 * @return On success, an array of the sent Messages is returned.
		 */
		std::vector<Message::ptr> sendMediaGroup(const long long &chat_id, const std::vector<std::variant<InputMediaPhoto::ptr, InputMediaVideo::ptr>> &media,
				const bool &disable_notification = false, const int &reply_to_message_id = 0) const noexcept;

		/**
		 * @brief Use this method to send point on the map.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] latitude Latitude of the location
		 * @param[in] longitude Longitude of the location
		 * @param[in] live_period Period in seconds for which the location will be updated (see Live Locations, should be between 60 and 86400.
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
		 * @return On success, the sent Message is returned.
		 */
		Message::ptr sendLocation(const long long &chat_id, const float &latitude, const float &longitude, const int &live_period = 0,
				const bool &disable_notification = false, const int &reply_to_message_id = 0, const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to edit live location messages. A location can be edited until its live_period expires or editing is explicitly disabled by a call to stopMessageLiveLocation.
		 * @param[in] latitude Latitude of new location
		 * @param[in] longitude Longitude of new location
		 * @param[in] chat_id Required if inline_message_id is not specified. Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] message_id Required if inline_message_id is not specified. Identifier of the message to edit
		 * @param[in] inline_message_id Required if chat_id and message_id are not specified. Identifier of the inline message
		 * @param[in] reply_markup A JSON-serialized object for a new inline keyboard.
		 * @return On success, if the edited message was sent by the bot, the edited Message is returned, otherwise True is returned.
		 */
		Message::ptr editMessageLiveLocation(const float &latitude, const float &longitude, const long long &chat_id = 0, const int &message_id = 0,
				const std::string &inline_message_id = "", const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to stop updating a live location message before live_period expires.
		 * @param[in] chat_id Required if inline_message_id is not specified. Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] message_id Required if inline_message_id is not specified. Identifier of the message with live location to stop
		 * @param[in] inline_message_id Required if chat_id and message_id are not specified. Identifier of the inline message
		 * @param[in] reply_markup A JSON-serialized object for a new inline keyboard.
		 * @return On success, if the message was sent by the bot, the sent Message is returned, otherwise True is returned.
		 */
		Message::ptr stopMessageLiveLocation(const long long &chat_id = 0, const int &message_id = 0, const std::string &inline_message_id = "",
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to send information about a venue.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] latitude Latitude of the venue
		 * @param[in] longitude Longitude of the venue
		 * @param[in] title Name of the venue
		 * @param[in] address Address of the venue
		 * @param[in] foursquare_id Foursquare identifier of the venue
		 * @param[in] foursquare_type Foursquare type of the venue, if known. (For example, “arts_entertainment/default”, “arts_entertainment/aquarium” or “food/icecream”.)
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
		 * @return On success, the sent Message is returned.
		 */
		Message::ptr sendVenue(const long long &chat_id, const float &latitude, const float &longitude, const std::string &title, const std::string &address,
				const std::string &foursquare_id = "", const std::string &foursquare_type = "", const bool &disable_notification = false,
				const int &reply_to_message_id = 0, const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to send phone contacts.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] phone_number Contact's phone number
		 * @param[in] first_name Contact's first name
		 * @param[in] last_name Contact's last name
		 * @param[in] vcard Additional data about the contact in the form of a vCard, 0-2048 bytes
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove keyboard or to force a reply from the user.
		 * @return On success, the sent Message is returned.
		 */
		Message::ptr sendContact(const long long &chat_id, const std::string &phone_number, const std::string &first_name, const std::string &last_name = "",
				const std::string &vcard = "", const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to send a native poll.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] question Poll question, 1-255 characters
		 * @param[in] options A JSON-serialized list of answer options, 2-10 strings 1-100 characters each
		 * @param[in] is_anonymous True, if the poll needs to be anonymous, defaults to True
		 * @param[in] type Poll type, “quiz” or “regular”, defaults to “regular”
		 * @param[in] allows_multiple_answers True, if the poll allows multiple answers, ignored for polls in quiz mode, defaults to False
		 * @param[in] correct_option_id 0-based identifier of the correct answer option, required for polls in quiz mode
		 * @param[in] explanation Text that is shown when a user chooses an incorrect answer or taps on the lamp icon in a quiz-style poll, 0-200 characters with at most 2 line feeds after entities parsing
		 * @param[in] explanation_parse_mode Mode for parsing entities in the explanation. See formatting options for more details.
		 * @param[in] open_period Amount of time in seconds the poll will be active after creation, 5-600. Can't be used together with close_date.
		 * @param[in] close_date Point in time (Unix timestamp) when the poll will be automatically closed. Must be at least 5 and no more than 600 seconds in the future. Can't be used together with open_period.
		 * @param[in] is_closed Pass True, if the poll needs to be immediately closed. This can be useful for poll preview.
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
		 * @return On success, the sent Message is returned.
		 */
		Message::ptr sendPoll(const long long &chat_id, const std::string &question, const std::vector<std::string> &options, const bool &is_anonymous = true,
				const std::string &type = "regular", const bool &allows_multiple_answers = false, const int &correct_option_id = -1, const std::string &explanation = "",
				const std::string &explanation_parse_mode = "", const int &open_period = -1, const int &close_date = -1, const bool &is_closed = false,
				const bool &disable_notification = false, const int &reply_to_message_id = 0, const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to send a dice, which will have a random value from 1 to 6.
		 * @details (Yes, we're aware of the “proper” singular of die. But it's awkward, and we decided to help it change. One dice at a time!)
		 * @param[in] chat_id
		 * @param[in] emoji
		 * @param[in] disable_notification
		 * @param[in] reply_to_message_id
		 * @param[in] reply_markup
		 * @return On success, the sent Message is returned.
		 */
		Message::ptr sendDice(const long long &chat_id, const std::string &emoji = "", const bool &disable_notification = false, const int &reply_to_message_id = -1,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method when you need to tell the user that something is happening on the bot's side. The status is set for 5 seconds or less (when a message arrives from your bot, Telegram clients clear its typing status).
		 * @details Example: The ImageBot needs some time to process a request and upload the image. Instead of sending a text message along the lines of “Retrieving image, please wait…”, the bot may use sendChatAction with action = upload_photo. The user will see a “sending photo” status for the bot.
		 * @details We only recommend using this method when a response from the bot will take a noticeable amount of time to arrive.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] action Type of action to broadcast. Choose one, depending on what the user is about to receive: typing for text messages, upload_photo for photos, record_video or upload_video for videos, record_audio or upload_audio for audio files, upload_document for general files, find_location for location data, record_video_note or upload_video_note for video notes.
		 * @return Returns True on success.
		 */
		bool sendChatAction(const long long &chat_id, const std::string &action) const noexcept;

		/**
		 * @brief Use this method to get a list of profile pictures for a user.
		 * @param[in] user_id Unique identifier of the target user
		 * @param[in] offset Sequential number of the first photo to be returned. By default, all photos are returned.
		 * @param[in] limit Limits the number of photos to be retrieved. Values between 1-100 are accepted. Defaults to 100.
		 * @return Returns a UserProfilePhotos object.
		 */
		UserProfilePhotos::ptr getUserProfilePhotos(const int &user_id, const int &offset = 0, const int &limit = 100) const noexcept;

		/**
		 * @brief Use this method to get basic info about a file and prepare it for downloading. For the moment, bots can download files of up to 20MB in size.
		 * @details The file can then be downloaded via the link https://api.telegram.org/file/bot\<token\>/\<file_path\>, where \<file_path\> is taken from the response. It is guaranteed that the link will be valid for at least 1 hour. When the link expires, a new one can be requested by
		 * @param[in] file_id File identifier to get info about
		 * @return On success, a File object is returned.
		 */
		File::ptr getFile(const std::string &file_id) const noexcept;

		/**
		 * @brief Use this method to kick a user from a group, a supergroup or a channel.
		 * @details In the case of supergroups and channels, the user will not be able to return to the group on their own using invite links, etc., unless unbanned first. The bot must be an administrator in the chat for this to work and must have the appropriate admin rights.
		 * @param[in] chat_id Unique identifier for the target group or username of the target supergroup or channel (in the format \@channelusername)
		 * @param[in] user_id Unique identifier of the target user
		 * @param[in] until_date Date when the user will be unbanned, unix time. If user is banned for more than 366 days or less than 30 seconds from the current time they are considered to be banned forever
		 * @return Returns True on success.
		 */
		bool kickChatMember(const long long &chat_id, const int &user_id, const int &until_date = 0) const noexcept;

		/**
		 * @brief Use this method to unban a previously kicked user in a supergroup or channel.
		 * @details The user will not return to the group or channel automatically, but will be able to join via link, etc. The bot must be an administrator for this to work.
		 * @param[in] chat_id Unique identifier for the target group or username of the target supergroup or channel (in the format \@username)
		 * @param[in] user_id Unique identifier of the target user
		 * @return Returns True on success.
		 */
		bool unbanChatMember(const long long &chat_id, const int &user_id) const noexcept;

		/**
		 * @brief Use this method to restrict a user in a supergroup.
		 * @details The bot must be an administrator in the supergroup for this to work and must have the appropriate admin rights. Pass True for all permissions to lift restrictions from a user.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target supergroup (in the format \@supergroupusername)
		 * @param[in] user_id Unique identifier of the target user
		 * @param[in] permissions New user permissions
		 * @param[in] until_date Date when restrictions will be lifted for the user, unix time. If user is restricted for more than 366 days or less than 30 seconds from the current time, they are considered to be restricted forever
		 * @return Returns True on success.
		 */
		bool restrictChatMember(const long long &chat_id, const int &user_id, const ChatPermissions::ptr &permissions, const int &until_date = 0) const noexcept;

		/**
		 * @brief Use this method to promote or demote a user in a supergroup or a channel.
		 * @details The bot must be an administrator in the chat for this to work and must have the appropriate admin rights. Pass False for all boolean parameters to demote a user.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] user_id Unique identifier of the target user
		 * @param[in] can_change_info Pass True, if the administrator can change chat title, photo and other settings
		 * @param[in] can_post_messages Pass True, if the administrator can create channel posts, channels only
		 * @param[in] can_edit_messages Pass True, if the administrator can edit messages of other users and can pin messages, channels only
		 * @param[in] can_delete_messages Pass True, if the administrator can delete messages of other users
		 * @param[in] can_invite_users Pass True, if the administrator can invite new users to the chat
		 * @param[in] can_restrict_members Pass True, if the administrator can restrict, ban or unban chat members
		 * @param[in] can_pin_messages Pass True, if the administrator can pin messages, supergroups only
		 * @param[in] can_promote_members Pass True, if the administrator can add new administrators with a subset of their own privileges or demote administrators that he has promoted, directly or indirectly (promoted by administrators that were appointed by him)
		 * @return Returns True on success.
		 */
		bool promoteChatMember(const long long &chat_id, const int &user_id, const bool &can_change_info, const bool &can_post_messages, const bool &can_edit_messages,
				const bool &can_delete_messages, const bool &can_invite_users, const bool &can_restrict_members, const bool &can_pin_messages,
				const bool &can_promote_members) const noexcept;

		/**
		 * @brief Use this method to set a custom title for an administrator in a supergroup promoted by the bot.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target supergroup (in the format \@supergroupusername)
		 * @param[in] user_id Unique identifier of the target user
		 * @param[in] custom_title New custom title for the administrator; 0-16 characters, emoji are not allowed
		 * @return Returns True on success.
		 */
		bool setChatAdministratorCustomTitle(const long long &chat_id, const int &user_id, const std::string &custom_title) const noexcept;

		/**
		 * @brief Use this method to set default chat permissions for all members.
		 * @details The bot must be an administrator in the group or a supergroup for this to work and must have the can_restrict_members admin rights.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target supergroup (in the format \@supergroupusername)
		 * @param[in] permissions New default chat permissions
		 * @return Returns True on success.
		 */
		bool setChatPermissions(const long long &chat_id, const ChatPermissions::ptr &permissions) const noexcept;

		/**
		 * @brief Use this method to generate a new invite link for a chat; any previously generated link is revoked.
		 * @details The bot must be an administrator in the chat for this to work and must have the appropriate admin rights.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @return Returns the new invite link as String on success.
		 */
		bool exportChatInviteLink(const long long &chat_id) const noexcept;

		/**
		 * @brief Use this method to set a new profile photo for the chat. Photos can't be changed for private chats.
		 * @details The bot must be an administrator in the chat for this to work and must have the appropriate admin rights.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] photo New chat photo, uploaded using multipart/form-data
		 * @return Returns True on success.
		 */
		bool setChatPhoto(const long long &chat_id, const tools::InputFile::ptr &photo) const noexcept;

		/**
		 * @brief Use this method to delete a chat photo.
		 * @details Photos can't be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate admin rights.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @return Returns True on success.
		 */
		bool deleteChatPhoto(const long long &chat_id) const noexcept;

		/**
		 * @brief Use this method to change the title of a chat.
		 * @details itles can't be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate admin rights.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] title New chat title, 1-255 characters
		 * @return Returns True on success.
		 */
		bool setChatTitle(const long long &chat_id, const std::string &title) const noexcept;

		/**
		 * @brief Use this method to change the description of a group, a supergroup or a channel.
		 * @details The bot must be an administrator in the chat for this to work and must have the appropriate admin rights.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] description New chat description, 0-255 characters
		 * @return Returns True on success.
		 */
		bool setChatDescription(const long long &chat_id, const std::string &description = "") const noexcept;

		/**
		 * @brief Use this method to pin a message in a group, a supergroup, or a channel.
		 * @details The bot must be an administrator in the chat for this to work and must have the ‘can_pin_messages’ admin right in the supergroup or ‘can_edit_messages’ admin right in the channel.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] message_id Identifier of a message to pin
		 * @param[in] disable_notification Pass True, if it is not necessary to send a notification to all chat members about the new pinned message. Notifications are always disabled in channels.
		 * @return Returns True on success.
		 */
		bool pinChatMessage(const long long &chat_id, const int &message_id, const bool &disable_notification = false) const noexcept;

		/**
		 * @brief Use this method to unpin a message in a group, a supergroup, or a channel.
		 * @details The bot must be an administrator in the chat for this to work and must have the ‘can_pin_messages’ admin right in the supergroup or ‘can_edit_messages’ admin right in the channel.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @return Returns True on success.
		 */
		bool unpinChatMessage(const long long &chat_id) const noexcept;

		/**
		 * @brief Use this method for your bot to leave a group, supergroup or channel.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target supergroup or channel (in the format \@channelusername)
		 * @return Returns True on success.
		 */
		bool leaveChat(const long long &chat_id) const noexcept;

		/**
		 * @brief Use this method to get up to date information about the chat (current name of the user for one-on-one conversations, current username of a user, group or channel, etc.).
		 * @param[in] chat_id Unique identifier for the target chat or username of the target supergroup or channel (in the format \@channelusername)
		 * @return Returns a Chat object on success.
		 */
		Chat::ptr getChat(const long long &chat_id) const noexcept;

		/**
		 * @brief Use this method to get a list of administrators in a chat.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target supergroup or channel (in the format \@channelusername)
		 * @return On success, returns an Array of ChatMember objects that contains information about all chat administrators except other bots. If the chat is a group or a supergroup and no administrators were appointed, only the creator will be returned.
		 */
		std::vector<ChatMember::ptr> getChatAdministrators(const long long &chat_id) const noexcept;

		/**
		 * @brief Use this method to get the number of members in a chat.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target supergroup or channel (in the format \@channelusername)
		 * @return Returns Int on success.
		 */
		int getChatMembersCount(const long long &chat_id) const noexcept;

		/**
		 * @brief Use this method to get information about a member of a chat.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target supergroup or channel (in the format \@channelusername)
		 * @param[in] user_id Unique identifier of the target user
		 * @return Returns a ChatMember object on success.
		 */
		ChatMember::ptr getChatMember(const long long &chat_id, const int &user_id) const noexcept;

		/**
		 * @brief Use this method to set a new group sticker set for a supergroup.
		 * @details The bot must be an administrator in the chat for this to work and must have the appropriate admin rights. Use the field can_set_sticker_set optionally returned in getChat requests to check if the bot can use this method.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target supergroup (in the format \@supergroupusername)
		 * @param[in] sticker_set_name Name of the sticker set to be set as the group sticker set
		 * @return Returns True on success.
		 */
		bool setChatStickerSet(const long long &chat_id, const std::string &sticker_set_name) const noexcept;

		/**
		 * @brief Use this method to delete a group sticker set from a supergroup.
		 * @details The bot must be an administrator in the chat for this to work and must have the appropriate admin rights. Use the field can_set_sticker_set optionally returned in getChat requests to check if the bot can use this method.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target supergroup (in the format \@supergroupusername)
		 * @return Returns True on success.
		 */
		bool deleteChatStickerSet(const long long &chat_id) const noexcept;

		/**
		 * @brief Use this method to send answers to callback queries sent from inline keyboards.
		 * @details The answer will be displayed to the user as a notification at the top of the chat screen or as an alert.
		 * @details Alternatively, the user can be redirected to the specified Game URL. For this option to work, you must first create a game for your bot via \@Botfather and accept the terms. Otherwise, you may use links like t.me/your_bot?start=XXXX that open your bot with a parameter.
		 * @param[in] callback_query_id Unique identifier for the query to be answered
		 * @param[in] text Text of the notification. If not specified, nothing will be shown to the user, 0-200 characters
		 * @param[in] show_alert If true, an alert will be shown by the client instead of a notification at the top of the chat screen. Defaults to false.
		 * @param[in] url URL that will be opened by the user's client. If you have created a Game and accepted the conditions via \@Botfather, specify the URL that opens your game — note that this will only work if the query comes from a callback_game button. Otherwise, you may use links like t.me/your_bot?start=XXXX that open your bot with a parameter.
		 * @param[in] cache_time The maximum amount of time in seconds that the result of the callback query may be cached client-side. Telegram apps will support caching starting in version 3.14. Defaults to 0.
		 * @return On success, True is returned.
		 */
		bool answerCallbackQuery(const std::string &callback_query_id, const std::string &text = "", const bool &show_alert = false, const std::string &url = "",
				const int &cache_time = 0) const noexcept;

		/**
		 * @brief Use this method to change the list of the bot's commands.
		 * @param[in] commands A JSON-serialized list of bot commands to be set as the list of the bot's commands. At most 100 commands can be specified.
		 * @return Returns True on success.
		 */
		bool setMyCommands(const std::vector<BotCommand::ptr> commands) const noexcept;

		/**
		 * @brief Use this method to get the current list of the bot's commands. Requires no parameters.
		 * @return Returns Array of BotCommand on success.
		 */
		std::vector<BotCommand::ptr> getMyCommands(const std::vector<BotCommand::ptr> commands) const noexcept;

		/**
		 * @brief Use this method to edit text and game messages.
		 * @param[in] text New text of the message, 1-4096 characters after entities parsing
		 * @param[in] chat_id  	Required if inline_message_id is not specified. Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] message_id Required if inline_message_id is not specified. Identifier of the message to edit
		 * @param[in] inline_message_id Required if chat_id and message_id are not specified. Identifier of the inline message
		 * @param[in] parse_mode Mode for parsing entities in the message text. See formatting options for more details.
		 * @param[in] disable_web_page_preview Disables link previews for links in this message
		 * @param[in] reply_markup A JSON-serialized object for an inline keyboard.
		 * @return On success, if edited message is sent by the bot, the edited Message is returned, otherwise True is returned.
		 */
		Message::ptr editMessageText(const std::string &text, const long long &chat_id = 0, const int &message_id = 0, const std::string &inline_message_id = "",
				const std::string &parse_mode = "", const bool &disable_web_page_preview = false, const Reply::ptr reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to edit captions of messages.
		 * @param[in] chat_id Required if inline_message_id is not specified. Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] message_id Required if inline_message_id is not specified. Identifier of the message to edit
		 * @param[in] inline_message_id Required if chat_id and message_id are not specified. Identifier of the inline message
		 * @param[in] caption New caption of the message, 0-1024 characters after entities parsing
		 * @param[in] parse_mode Mode for parsing entities in the message caption. See formatting options for more details.
		 * @param[in] reply_markup A JSON-serialized object for an inline keyboard.
		 * @return On success, if edited message is sent by the bot, the edited Message is returned, otherwise True is returned.
		 */
		Message::ptr editMessageCaption(const long long &chat_id = 0, const int &message_id = 0, const std::string &inline_message_id = "", const std::string &caption = 0,
				const std::string &parse_mode = "", const Reply::ptr reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to edit animation, audio, document, photo, or video messages.
		 * @details f a message is a part of a message album, then it can be edited only to a photo or a video. Otherwise, message type can be changed arbitrarily.
		 * @details When inline message is edited, new file can't be uploaded. Use previously uploaded file via its file_id or specify a URL.
		 * @param[in] chat_id Required if inline_message_id is not specified. Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] message_id Required if inline_message_id is not specified. Identifier of the message to edit
		 * @param[in] inline_message_id Required if chat_id and message_id are not specified. Identifier of the inline message
		 * @param[in] media A JSON-serialized object for a new media content of the message
		 * @param[in] reply_markup A JSON-serialized object for a new inline keyboard.
		 * @return On success, if the edited message was sent by the bot, the edited Message is returned, otherwise True is returned.
		 */
		Message::ptr editMessageMedia(const std::variant<InputMediaAnimation::ptr, InputMediaAudio::ptr, InputMediaDocument::ptr, InputMediaPhoto::ptr,
				InputMediaVideo::ptr> &media, const long long &chat_id = 0, const int &message_id = 0, const std::string &inline_message_id = "",
				const Reply::ptr reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to edit only the reply markup of messages.
		 * @param[in] reply_markup Required if inline_message_id is not specified. Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] chat_id Required if inline_message_id is not specified. Identifier of the message to edit
		 * @param[in] message_id Required if chat_id and message_id are not specified. Identifier of the inline message
		 * @param[in] inline_message_id A JSON-serialized object for an inline keyboard.
		 * @return On success, if edited message is sent by the bot, the edited Message is returned, otherwise True is returned.
		 */
		Message::ptr editMessageReplyMarkup(const Reply::ptr &reply_markup, const long long &chat_id = 0, const int &message_id = 0,
				const std::string &inline_message_id = "") const noexcept;

		/**
		 * @brief Use this method to stop a poll which was sent by the bot.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] message_id Identifier of the original message with the poll
		 * @param[in] reply_markup A JSON-serialized object for a new message inline keyboard.
		 * @return On success, the stopped Poll with the final results is returned.
		 */
		Poll::ptr stopPoll(const long long &chat_id, const int &message_id, const Reply::ptr reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to delete a message, including service messages, with the following limitations:
		 * @details A message can only be deleted if it was sent less than 48 hours ago.
		 * @details A dice message in a private chat can only be deleted if it was sent more than 24 hours ago.
		 * @details Bots can delete outgoing messages in private chats, groups, and supergroups.
		 * @details Bots can delete incoming messages in private chats.
		 * @details Bots granted can_post_messages permissions can delete outgoing messages in channels.
		 * @details If the bot is an administrator of a group, it can delete any message there.
		 * @details If the bot has can_delete_messages permission in a supergroup or a channel, it can delete any message there.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] message_id Identifier of the message to delete
		 * @return Returns True on success.
		 */
		bool deleteMessage(const long long &chat_id, const int &message_id) const noexcept;

		/**
		 * @brief Use this method to send static .WEBP or animated .TGS stickers.
		 * @param[in] chat_id Unique identifier for the target chat or username of the target channel (in the format \@channelusername)
		 * @param[in] sticker Sticker to send. Pass a file_id as String to send a file that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get a .WEBP file from the Internet, or upload a new one using multipart/form-data.
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
		 * @return On success, the sent Message is returned.
		 */
		Message::ptr sendSticker(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &sticker, const bool &disable_notification = false,
				const int &reply_to_message_id = 0, const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief Use this method to get a sticker set.
		 * @param[in] name Name of the sticker set
		 * @return On success, a StickerSet object is returned.
		 */
		StickerSet::ptr getStickerSet(const std::string &name) const noexcept;

		/**
		 * @brief Use this method to upload a .PNG file with a sticker for later use in createNewStickerSet and addStickerToSet methods (can be used multiple times).
		 * @param[in] user_id User identifier of sticker file owner
		 * @param[in] png_sticker PNG image with the sticker, must be up to 512 kilobytes in size, dimensions must not exceed 512px, and either width or height must be exactly 512px.
		 * @return Returns the uploaded File on success.
		 */
		File::ptr uploadStickerFile(const int &user_id, const tools::InputFile::ptr &png_sticker) const noexcept;

		/**
		 * @brief Use this method to create a new sticker set owned by a user.
		 * @details The bot will be able to edit the sticker set thus created. You must use exactly one of the fields png_sticker or tgs_sticker.
		 * @param[in] user_id User identifier of created sticker set owner
		 * @param[in] name Short name of sticker set, to be used in t.me/addstickers/ URLs (e.g., animals). Can contain only english letters, digits and underscores. Must begin with a letter, can't contain consecutive underscores and must end in “_by_<bot username>”. \<bot_username\> is case insensitive. 1-64 characters.
		 * @param[in] title Sticker set title, 1-64 characters
		 * @param[in] png_sticker PNG image with the sticker, must be up to 512 kilobytes in size, dimensions must not exceed 512px, and either width or height must be exactly 512px. Pass a file_id as a String to send a file that already exists on the Telegram servers, pass an HTTP URL as a String for Telegram to get a file from the Internet, or upload a new one using multipart/form-data.
		 * @param[in] tgs_sticker TGS animation with the sticker, uploaded using multipart/form-data. See https://core.telegram.org/animated_stickers#technical-requirements for technical requirements
		 * @param[in] emojis One or more emoji corresponding to the sticker
		 * @param[in] contains_mask Pass True, if a set of mask stickers should be created
		 * @param[in] mask_position A JSON-serialized object for position where the mask should be placed on faces
		 * @return Returns True on success.
		 */
		bool createNewStickerSet(const int &user_id, const std::string &name, const std::string &title, const std::string &emojis,
				const std::variant<std::string, tools::InputFile::ptr> &png_sticker = "",
				const tools::InputFile::ptr tgs_sticker = std::make_shared<tools::InputFile>(""),
				const bool &contains_mask = false, const MaskPosition::ptr &mask_position = std::make_shared<MaskPosition>()) const noexcept;

		/**
		 * @brief Use this method to add a new sticker to a set created by the bot.
		 * @details You must use exactly one of the fields png_sticker or tgs_sticker. Animated stickers can be added to animated sticker sets and only to them.
		 * @details Animated sticker sets can have up to 50 stickers. Static sticker sets can have up to 120 stickers.
		 * @param[in] user_id  	User identifier of sticker set owner
		 * @param[in] name Sticker set name
		 * @param[in] png_sticker PNG image with the sticker, must be up to 512 kilobytes in size, dimensions must not exceed 512px, and either width or height must be exactly 512px. Pass a file_id as a String to send a file that already exists on the Telegram servers, pass an HTTP URL as a String for Telegram to get a file from the Internet, or upload a new one using multipart/form-data.
		 * @param[in] emojis One or more emoji corresponding to the sticker
		 * @param[in] tgs_sticker TGS animation with the sticker, uploaded using multipart/form-data. See https://core.telegram.org/animated_stickers#technical-requirements for technical requirements
		 * @param[in] mask_position A JSON-serialized object for position where the mask should be placed on faces
		 * @return Returns True on success.
		 */
		bool addStickerToSet(const int &user_id, const std::string &name, const std::variant<std::string, tools::InputFile::ptr> &png_sticker,
				const std::string &emojis, const tools::InputFile::ptr tgs_sticker = std::make_shared<tools::InputFile>(""),
				const MaskPosition::ptr &mask_position = std::make_shared<MaskPosition>()) const noexcept;

		/**
		 * @brief Use this method to move a sticker in a set created by the bot to a specific position.
		 * @param[in] sticker File identifier of the sticker
		 * @param[in] position New sticker position in the set, zero-based
		 * @return Returns True on success.
		 */
		bool setStickerPositionInSet(const std::string &sticker, const int &position) const noexcept;

		/**
		 * @brief Use this method to delete a sticker from a set created by the bot.
		 * @param[in] sticker File identifier of the sticker
		 * @return Returns True on success.
		 */
		bool deleteStickerFromSet(const std::string &sticker) const noexcept;

		/**
		 * @brief Use this method to set the thumbnail of a sticker set. Animated thumbnails can be set for animated sticker sets only.
		 * @param[in] name Sticker set name
		 * @param[in] user_id User identifier of the sticker set owner
		 * @param[in] thumb A PNG image with the thumbnail, must be up to 128 kilobytes in size and have width and height exactly 100px, or a TGS animation with the thumbnail up to 32 kilobytes in size; see https://core.telegram.org/animated_stickers#technical-requirements for animated sticker technical requirements. Pass a file_id as a String to send a file that already exists on the Telegram servers, pass an HTTP URL as a String for Telegram to get a file from the Internet, or upload a new one using multipart/form-data. More info on Sending Files ». Animated sticker set thumbnail can't be uploaded via HTTP URL.
		 * @return Returns True on success.
		 */
		bool setStickerSetThumb(const std::string &name, const int &user_id, const std::variant<std::string, tools::InputFile::ptr> &thumb = "") const noexcept;

		/**
		 * @brief Use this method to send answers to an inline query.
		 * @details No more than 50 results per query are allowed.
		 * @param[in] inline_query_id Unique identifier for the answered query
		 * @param[in] results A JSON-serialized array of results for the inline query
		 * @param[in] cache_time The maximum amount of time in seconds that the result of the inline query may be cached on the server. Defaults to 300.
		 * @param[in] is_personal Pass True, if results may be cached on the server side only for the user that sent the query. By default, results may be returned to any user who sends the same query
		 * @param[in] next_offset Pass the offset that a client should send in the next query with the same text to receive more results. Pass an empty string if there are no more results or if you don‘t support pagination. Offset length can’t exceed 64 bytes.
		 * @param[in] switch_pm_text If passed, clients will display a button with specified text that switches the user to a private chat with the bot and sends the bot a start message with the parameter switch_pm_parameter
		 * @param[in] switch_pm_parameter Deep-linking parameter for the /start message sent to the bot when user presses the switch button. 1-64 characters, only A-Z, a-z, 0-9, _ and - are allowed. Example: An inline bot that sends YouTube videos can ask the user to connect the bot to their YouTube account to adapt search results accordingly. To do this, it displays a ‘Connect your YouTube account’ button above the results, or even before showing any. The user presses the button, switches to a private chat with the bot and, in doing so, passes a start parameter that instructs the bot to return an oauth link. Once done, the bot can offer a switch_inline button so that the user can easily return to the chat where they wanted to use the bot's inline capabilities.
		 * @return On success, True is returned.
		 */
		bool answerInlineQuery(const std::string &inline_query_id, const std::vector<InlineQueryResult::ptr> &results, const int &cache_time = 300,
				const bool &is_personal = false, const std::string &next_offset = "", const std::string &switch_pm_text = "",
				const std::string &switch_pm_parameter = "") const noexcept;

		/**
		 * @brief Use this method to send invoices.
		 * @param[in] chat_id Unique identifier for the target private chat
		 * @param[in] title Product name, 1-32 characters
		 * @param[in] description Product description, 1-255 characters
		 * @param[in] payload Bot-defined invoice payload, 1-128 bytes. This will not be displayed to the user, use for your internal processes.
		 * @param[in] provider_token Payments provider token, obtained via Botfather
		 * @param[in] start_parameter Unique deep-linking parameter that can be used to generate this invoice when used as a start parameter
		 * @param[in] currency Three-letter ISO 4217 currency code, see more on currencies
		 * @param[in] prices Price breakdown, a JSON-serialized list of components (e.g. product price, tax, discount, delivery cost, delivery tax, bonus, etc.)
		 * @param[in] provider_data JSON-encoded data about the invoice, which will be shared with the payment provider. A detailed description of required fields should be provided by the payment provider.
		 * @param[in] photo_url URL of the product photo for the invoice. Can be a photo of the goods or a marketing image for a service. People like it better when they see what they are paying for.
		 * @param[in] photo_size Photo size
		 * @param[in] photo_width Photo width
		 * @param[in] photo_height Photo height
		 * @param[in] need_name Pass True, if you require the user's full name to complete the order
		 * @param[in] need_phone_number Pass True, if you require the user's phone number to complete the order
		 * @param[in] need_email Pass True, if you require the user's email address to complete the order
		 * @param[in] need_shipping_address Pass True, if you require the user's shipping address to complete the order
		 * @param[in] send_phone_number_to_provider Pass True, if user's phone number should be sent to provider
		 * @param[in] send_email_to_provider Pass True, if user's email address should be sent to provider
		 * @param[in] is_flexible Pass True, if the final price depends on the shipping method
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup A JSON-serialized object for an inline keyboard. If empty, one 'Pay total price' button will be shown. If not empty, the first button must be a Pay button.
		 * @return On success, the sent Message is returned.
		 */
		Message::ptr sendInvoice(const long long &chat_id, const std::string &title, const std::string &description, const std::string &payload,
				const std::string &provider_token, const std::string &start_parameter, const std::string &currency, const std::vector<LabeledPrice::ptr> &prices,
				const std::string &provider_data = "", const std::string &photo_url = "", const int &photo_size = 0, const int &photo_width = 0,
				const int &photo_height = 0, const bool &need_name = false, const bool &need_phone_number = false, const bool &need_email = false,
				const bool &need_shipping_address = false, const bool &send_phone_number_to_provider = false, const bool &send_email_to_provider = false,
				const bool &is_flexible = false, const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const Reply::ptr &reply_markup = std::make_shared<Reply>()) const noexcept;

		/**
		 * @brief If you sent an invoice requesting a shipping address and the parameter is_flexible was specified, the Bot API will send an Update with a shipping_query field to the bot.
		 * @details Use this method to reply to shipping queries.
		 * @param[in] shipping_query_id Unique identifier for the query to be answered
		 * @param[in] ok Specify True if delivery to the specified address is possible and False if there are any problems (for example, if delivery to the specified address is not possible)
		 * @param[in] shipping_options Required if ok is True. A JSON-serialized array of available shipping options.
		 * @param[in] error_message Required if ok is False. Error message in human readable form that explains why it is impossible to complete the order (e.g. "Sorry, delivery to your desired address is unavailable'). Telegram will display this message to the user.
		 * @return On success, True is returned.
		 */
		bool answerShippingQuery(const std::string &shipping_query_id, const bool &ok,
				const std::vector<ShippingOption::ptr> &shipping_options = std::vector<ShippingOption::ptr>(), const std::string &error_message = "") const noexcept;

		/**
		 * @brief Once the user has confirmed their payment and shipping details, the Bot API sends the final confirmation in the form of an Update with the field pre_checkout_query.
		 * @details Use this method to respond to such pre-checkout queries.
		 * @note The Bot API must receive an answer within 10 seconds after the pre-checkout query was sent.
		 * @param[in] pre_checkout_query_id Unique identifier for the query to be answered
		 * @param[in] ok Specify True if everything is alright (goods are available, etc.) and the bot is ready to proceed with the order. Use False if there are any problems.
		 * @param[in] error_message Required if ok is False. Error message in human readable form that explains the reason for failure to proceed with the checkout (e.g. "Sorry, somebody just bought the last of our amazing black T-shirts while you were busy filling out your payment details. Please choose a different color or garment!"). Telegram will display this message to the user.
		 * @return On success, True is returned.
		 */
		bool answerPreCheckoutQuery(const std::string &pre_checkout_query_id, const bool &ok, const std::string &error_message = "") const noexcept;

		/**
		 * @brief Informs a user that some of the Telegram Passport elements they provided contains errors.
		 * @details The user will not be able to re-submit their Passport to you until the errors are fixed (the contents of the field for which you returned the error must change).
		 * @details Use this if the data submitted by the user doesn't satisfy the standards your service requires for any reason. For example, if a birthday date seems invalid, a submitted document is blurry, a scan shows evidence of tampering, etc. Supply some details in the error message to make sure the user knows how to correct the issues.
		 * @param[in] user_id User identifier
		 * @param[in] errors A JSON-serialized array describing the errors
		 * @return Returns True on success.
		 */
		bool setPassportDataErrors(const int &user_id, const std::vector<PassportElementError::ptr> &errors) const noexcept;

		/**
		 * @brief Use this method to send a game.
		 * @param[in] chat_id Unique identifier for the target chat
		 * @param[in] game_short_name Short name of the game, serves as the unique identifier for the game. Set up your games via Botfather.
		 * @param[in] disable_notification Sends the message silently. Users will receive a notification with no sound.
		 * @param[in] reply_to_message_id If the message is a reply, ID of the original message
		 * @param[in] reply_markup A JSON-serialized object for an inline keyboard. If empty, one ‘Play game_title’ button will be shown. If not empty, the first button must launch the game.
		 * @return On success, the sent Message is returned.
		 */
		Message::ptr sendGame(const long long &chat_id, const std::string &game_short_name, const bool &disable_notification = false, const int &reply_to_message_id = 0,
				const InlineKeyboardMarkup::ptr &reply_markup = std::make_shared<InlineKeyboardMarkup>()) const noexcept;

		/**
		 * @brief Use this method to set the score of the specified user in a game.
		 * @param[in] user_id User identifier
		 * @param[in] score New score, must be non-negative
		 * @param[in] force Pass True, if the high score is allowed to decrease. This can be useful when fixing mistakes or banning cheaters
		 * @param[in] disable_edit_message Pass True, if the game message should not be automatically edited to include the current scoreboard
		 * @param[in] chat_id Required if inline_message_id is not specified. Unique identifier for the target chat
		 * @param[in] message_id Required if inline_message_id is not specified. Identifier of the sent message
		 * @param[in] inline_message_id Required if chat_id and message_id are not specified. Identifier of the inline message
		 * @return On success, if the message was sent by the bot, returns the edited Message, otherwise returns True. Returns an error, if the new score is not greater than the user's current score in the chat and force is False.
		 */
		Message::ptr setGameScore(const int &user_id, const int &score, const bool &force = false, const bool &disable_edit_message = false, const long long &chat_id = 0,
				const int &message_id = 0, const std::string &inline_message_id = "") const noexcept;

		/**
		 * @brief Use this method to get data for high score tables.
		 * @note This method will currently return scores for the target user, plus two of their closest neighbors on each side. Will also return the top three users if the user and his neighbors are not among them. Please note that this behavior is subject to change.
		 * @param[in] user_id Target user id
		 * @param[in] chat_id Required if inline_message_id is not specified. Unique identifier for the target chat
		 * @param[in] message_id Required if inline_message_id is not specified. Identifier of the sent message
		 * @param[in] inline_message_id Required if chat_id and message_id are not specified. Identifier of the inline message
		 * @return Will return the score of the specified user and several of their neighbors in a game. On success, returns an Array of GameHighScore objects.
		 */
		std::vector<GameHighScore::ptr> getGameHighScores(const int &user_id, const long long &chat_id = 0, const int &message_id = 0,
				const std::string &inline_message_id = "") const noexcept;
	};
}

#endif
