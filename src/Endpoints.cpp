#include "tools/http/HttpClient.h"
#include "tools/http/InputFile.h"
#include "tgbot/Endpoints.h"
#include "tgbot/types/ReplyKeyboardRemove.h"
#include "tgbot/types/User.h"
#include <iostream>
#include "tools/Tools.h"

namespace tgbot
{
	Endpoints::Endpoints(const std::string &token) : m_token(token)
	{}

	std::vector<Update::ptr> Endpoints::getUpdates(const int &offset, const int &limit, const int &timeout, const std::vector<std::string> &allowed_updates) const
	{
		//go through vector to build up the json array
		std::string allowed_updates_json = "[";

		for(std::size_t j = 0; j < allowed_updates.size(); ++j)
		{
			allowed_updates_json.append(allowed_updates.at(j));

			//make ready for next json object
			allowed_updates_json.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * allowed_updates and not allowed_updates_json in condition as in that case we would destroy the json array
		 */
		if(allowed_updates.size() > 0)
		{
			//finish json array
			allowed_updates_json.pop_back();
			allowed_updates_json.pop_back();
		}
		allowed_updates_json.append("]");

		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("offset", offset));
		http_args.push_back(tools::HttpArg("limit", limit));
		http_args.push_back(tools::HttpArg("timeout", timeout));
		http_args.push_back(tools::HttpArg("allowed_updates", allowed_updates_json));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getUpdates", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		std::vector<Update::ptr> updates;

		if(doc.IsObject())
			if(doc.HasMember("result"))
			{
				if(doc["result"].IsArray())
				{
					const rapidjson::Value &array = doc["result"].GetArray();
					for(std::size_t j = 0; j< array.Size(); ++j)
						updates.push_back(std::make_shared<Update>(tools::Tools::get_json_as_string(array[j])));
				}
			}

		return updates;
	}

	bool Endpoints::setWebhook(const std::string &url, const tools::InputFile::ptr &certificate, const int &max_connections,
			const std::vector<std::string> &allowed_updates) const
	{
		//go through vector to build up the json array
		std::string allowed_updates_json = "[";

		for(std::size_t j = 0; j < allowed_updates.size(); ++j)
		{
			allowed_updates_json.append(allowed_updates.at(j));

			//make ready for next json object
			allowed_updates_json.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * allowed_updates and not allowed_updates_json in condition as in that case we would destroy the json array
		 */
		if(allowed_updates.size() > 0)
		{
			//finish json array
			allowed_updates_json.pop_back();
			allowed_updates_json.pop_back();
		}
		allowed_updates_json.append("]");

		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("url", url));
		http_args.push_back(tools::HttpArg("certificate", certificate));
		http_args.push_back(tools::HttpArg("max_connections", max_connections));
		http_args.push_back(tools::HttpArg("allowed_updates", allowed_updates_json));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setWebhook", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::deleteWebhook() const
	{
		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteWebhook");
		std::string json = http_client.send_get_req().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	WebhookInfo::ptr Endpoints::getWebhookInfo() const
	{
		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getWebhookInfo");
		std::string json = http_client.send_get_req().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		WebhookInfo::ptr webhook_info = std::make_shared<WebhookInfo>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				webhook_info = std::make_shared<WebhookInfo>(tools::Tools::get_json_as_string(doc["result"]));

		return webhook_info;
	}

	User::ptr Endpoints::getMe() const
	{
		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getMe");
		std::string json = http_client.send_get_req().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		User::ptr usr = std::make_shared<User>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				usr = std::make_shared<User>(tools::Tools::get_json_as_string(doc["result"]));

		return usr;
	}

	Message::ptr Endpoints::sendMessage(const long long &chat_id, const std::string &text, const std::string &parse_mode, const bool &disable_web_page_preview,
			const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("text", text));
		http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
		http_args.push_back(tools::HttpArg("disable_web_page_preview", disable_web_page_preview));
		http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
		http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendMessage", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::forwardMessage(const long long &chat_id, const long long &from_chat_id, const int &message_id, const bool &disable_notification) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("from_chat_id", from_chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));
		http_args.push_back(tools::HttpArg("disable_notification", disable_notification));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/forwardMessage", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::sendPhoto(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &photo, const std::string &caption,
			const std::string &parse_mode, const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(photo))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("photo", std::get<std::string>(photo)));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendPhoto", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(photo))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("photo", std::get<tools::InputFile::ptr>(photo)));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendPhoto", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}

		Message::ptr msg = std::make_shared<Message>();
		return msg;
	}

	Message::ptr Endpoints::sendAudio(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &audio,
			const std::variant<std::string, tools::InputFile::ptr> &thumb, const std::string &caption, const std::string &parse_mode,
			const int &duration, const std::string &performer, const std::string &title, const bool &disable_notification, const int &reply_to_message_id,
			const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(audio) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("audio", std::get<std::string>(audio)));
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("performer", performer));
			http_args.push_back(tools::HttpArg("title", title));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAudio", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(audio) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("audio", std::get<tools::InputFile::ptr>(audio)));
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("performer", performer));
			http_args.push_back(tools::HttpArg("title", title));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAudio", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<std::string>(audio) && std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("audio", std::get<std::string>(audio)));
			http_args.push_back(tools::HttpArg("thumb", std::get<tools::InputFile::ptr>(thumb)));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("performer", performer));
			http_args.push_back(tools::HttpArg("title", title));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAudio", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(audio) && std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("audio", std::get<tools::InputFile::ptr>(audio)));
			http_args.push_back(tools::HttpArg("thumb", std::get<tools::InputFile::ptr>(thumb)));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("performer", performer));
			http_args.push_back(tools::HttpArg("title", title));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAudio", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}

		Message::ptr msg = std::make_shared<Message>();
		return msg;
	}

	Message::ptr Endpoints::sendDocument(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &document,
			const std::variant<std::string, tools::InputFile::ptr> &thumb, const std::string &caption, const std::string &parse_mode,
			const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(document) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("document", std::get<std::string>(document)));
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendDocument", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(document) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("document", std::get<tools::InputFile::ptr>(document)));
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendDocument", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<std::string>(document) && std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("document", std::get<std::string>(document)));
			http_args.push_back(tools::HttpArg("thumb", std::get<tools::InputFile::ptr>(thumb)));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendDocument", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(document) && std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("document", std::get<tools::InputFile::ptr>(document)));
			http_args.push_back(tools::HttpArg("thumb", std::get<tools::InputFile::ptr>(thumb)));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendDocument", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}

		Message::ptr msg = std::make_shared<Message>();
		return msg;
	}

	Message::ptr Endpoints::sendVideo(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &video,
			const std::variant<std::string, tools::InputFile::ptr> &thumb, const int &duration, const int &width, const int &height, const std::string &caption,
			const std::string &parse_mode,const bool &supports_streaming, const bool &disable_notification, const int &reply_to_message_id,
			const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(video) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("video", std::get<std::string>(video)));
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("width", width));
			http_args.push_back(tools::HttpArg("height", height));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("supports_streaming", supports_streaming));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideo", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(video) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("video", std::get<tools::InputFile::ptr>(video)));
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("width", width));
			http_args.push_back(tools::HttpArg("height", height));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("supports_streaming", supports_streaming));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideo", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<std::string>(video) && std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("video", std::get<std::string>(video)));
			http_args.push_back(tools::HttpArg("thumb", std::get<tools::InputFile::ptr>(thumb)));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("width", width));
			http_args.push_back(tools::HttpArg("height", height));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("supports_streaming", supports_streaming));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideo", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(video) && std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("video", std::get<tools::InputFile::ptr>(video)));
			http_args.push_back(tools::HttpArg("thumb", std::get<tools::InputFile::ptr>(thumb)));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("width", width));
			http_args.push_back(tools::HttpArg("height", height));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("supports_streaming", supports_streaming));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideo", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}

		Message::ptr msg = std::make_shared<Message>();
		return msg;
	}

	Message::ptr Endpoints::sendAnimation(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &animation,
			const std::variant<std::string, tools::InputFile::ptr> &thumb, const int &duration, const int &width, const int &height,
			const std::string &caption, const std::string &parse_mode, const bool &disable_notification,
			const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(animation) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("animation", std::get<std::string>(animation)));
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("width", width));
			http_args.push_back(tools::HttpArg("height", height));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAnimation", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(animation) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("animation", std::get<tools::InputFile::ptr>(animation)));
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("width", width));
			http_args.push_back(tools::HttpArg("height", height));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAnimation", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<std::string>(animation) && std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("animation", std::get<std::string>(animation)));
			http_args.push_back(tools::HttpArg("thumb", std::get<tools::InputFile::ptr>(thumb)));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("width", width));
			http_args.push_back(tools::HttpArg("height", height));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAnimation", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(animation) && std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("animation", std::get<tools::InputFile::ptr>(animation)));
			http_args.push_back(tools::HttpArg("thumb", std::get<tools::InputFile::ptr>(thumb)));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("width", width));
			http_args.push_back(tools::HttpArg("height", height));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAnimation", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}

		Message::ptr msg = std::make_shared<Message>();
		return msg;
	}

	Message::ptr Endpoints::sendVoice(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &voice, const std::string &caption,
			const std::string &parse_mode, const int &duration, const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(voice))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("voice", std::get<std::string>(voice)));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVoice", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(voice))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("voice", std::get<tools::InputFile::ptr>(voice)));
			http_args.push_back(tools::HttpArg("caption", caption));
			http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVoice", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}

		Message::ptr msg = std::make_shared<Message>();
		return msg;
	}

	Message::ptr Endpoints::sendVideoNote(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &video_note,
			const std::variant<std::string, tools::InputFile::ptr> &thumb, const int &duration, const int &length, const bool &disable_notification,
			const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(video_note) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("video_note", std::get<std::string>(video_note)));
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("length", length));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideoNote", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(video_note) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("video_note", std::get<tools::InputFile::ptr>(video_note)));
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("length", length));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideoNote", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<std::string>(video_note) && std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("video_note", std::get<std::string>(video_note)));
			http_args.push_back(tools::HttpArg("thumb", std::get<tools::InputFile::ptr>(thumb)));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("length", length));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideoNote", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(video_note) && std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("video_note", std::get<tools::InputFile::ptr>(video_note)));
			http_args.push_back(tools::HttpArg("thumb", std::get<tools::InputFile::ptr>(thumb)));
			http_args.push_back(tools::HttpArg("duration", duration));
			http_args.push_back(tools::HttpArg("length", length));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideoNote", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}

		Message::ptr msg = std::make_shared<Message>();
		return msg;
	}

	std::vector<Message::ptr> Endpoints::sendMediaGroup(const long long &chat_id, const std::vector<std::variant<InputMediaPhoto::ptr, InputMediaVideo::ptr>> &media,
			const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		//vector contains all paths to files which still need to be uploaded
		std::vector<std::string> files_to_upload;

		//go through vector to build up the json array
		std::string media_json = "[";

		for(std::size_t j = 0; j < media.size(); ++j)
		{
			if(std::holds_alternative<InputMediaPhoto::ptr>(media.at(j)))
			{
				media_json.append(std::get<InputMediaPhoto::ptr>(media.at(j))->parse_to_json());

				//we only need to upload if the media is of type InputFile
				if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaPhoto::ptr>(media.at(j))->media))
					files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaPhoto::ptr>(media.at(j))->media)->m_path);
			}
			else if(std::holds_alternative<InputMediaVideo::ptr>(media.at(j)))
			{
				media_json.append(std::get<InputMediaVideo::ptr>(media.at(j))->parse_to_json());

				//we only need to upload if the media is of type InputFile
				if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaVideo::ptr>(media.at(j))->media))
					files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaVideo::ptr>(media.at(j))->media)->m_path);
			}

			//make ready for next json object
			media_json.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * media and not media_json in condition as in that case we would destroy the json array
		 */
		if(media.size() > 0)
		{
			//finish json array
			media_json.pop_back();
			media_json.pop_back();
		}
		media_json.append("]");

		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("media", media_json));
		http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
		http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));
			//plus files which need to be uploaded
		for(std::size_t j = 0; j < files_to_upload.size(); ++j)
		{
			tools::InputFile::ptr temp = std::make_shared<tools::InputFile>(files_to_upload.at(j));
			http_args.push_back(tools::HttpArg(files_to_upload.at(j), temp));
		}

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendMediaGroup", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		std::vector<Message::ptr> msgs;

		if(doc.IsObject())
			if(doc.HasMember("result"))
			{
				if(doc["result"].IsArray())
				{
					const rapidjson::Value &array = doc["result"].GetArray();
					for(std::size_t j = 0; j< array.Size(); ++j)
						msgs.push_back(std::make_shared<Message>(tools::Tools::get_json_as_string(array[j])));
				}
			}

		return msgs;
	}

	Message::ptr Endpoints::sendLocation(const long long &chat_id, const float &latitude, const float &longitude, const int &live_period, const bool &disable_notification,
			const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("latitude", latitude));
		http_args.push_back(tools::HttpArg("longitude", longitude));
		http_args.push_back(tools::HttpArg("live_period", live_period));
		http_args.push_back(tools::HttpArg("live_period", live_period));
		http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendLocation", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::editMessageLiveLocation(const float &latitude, const float &longitude, const long long &chat_id, const int &message_id,
			const std::string &inline_message_id, const Reply::ptr &reply_markup) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("latitude", latitude));
		http_args.push_back(tools::HttpArg("longitude", longitude));
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));
		http_args.push_back(tools::HttpArg("inline_message_id", inline_message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/editMessageLiveLocation", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::stopMessageLiveLocation(const long long &chat_id, const int &message_id, const std::string &inline_message_id,
			const Reply::ptr &reply_markup) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));
		http_args.push_back(tools::HttpArg("inline_message_id", inline_message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/stopMessageLiveLocation", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::sendVenue(const long long &chat_id, const float &latitude, const float &longitude, const std::string &title, const std::string &address,
			const std::string &foursquare_id, const std::string &foursquare_type, const bool &disable_notification, const int &reply_to_message_id,
			const Reply::ptr &reply_markup) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("latitude", latitude));
		http_args.push_back(tools::HttpArg("longitude", longitude));
		http_args.push_back(tools::HttpArg("title", title));
		http_args.push_back(tools::HttpArg("address", address));
		http_args.push_back(tools::HttpArg("foursquare_id", foursquare_id));
		http_args.push_back(tools::HttpArg("foursquare_type", foursquare_type));
		http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
		http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVenue", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::sendContact(const long long &chat_id, const std::string &phone_number, const std::string &first_name, const std::string &last_name,
			const std::string &vcard, const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("phone_number", phone_number));
		http_args.push_back(tools::HttpArg("first_name", first_name));
		http_args.push_back(tools::HttpArg("last_name", last_name));
		http_args.push_back(tools::HttpArg("vcard", vcard));
		http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
		http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendContact", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::sendPoll(const long long &chat_id, const std::string &question, const std::vector<std::string> &options, const bool &disable_notification,
			const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		//create json array of options
		std::string options_json = "[";
		for(std::size_t j = 0; j < options.size(); ++j)
			options_json.append("\"" + options.at(j) + "\", ");

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * options and not options_json in condition as in that case we would destroy the json array
		 */
		if(options.size() > 0)
		{
			//finish json array
			options_json.pop_back();
			options_json.pop_back();
		}
		options_json.append("]");

		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("question", question));
		http_args.push_back(tools::HttpArg("options", options_json));
		http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
		http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendPoll", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	bool Endpoints::sendChatAction(const long long &chat_id, const std::string &action) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("action", action));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendChatAction", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	UserProfilePhotos::ptr Endpoints::getUserProfilePhotos(const int &user_id, const int &offset, const int &limit) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("user_id", user_id));
		if(offset != -1)
			http_args.push_back(tools::HttpArg("offset", offset));
		http_args.push_back(tools::HttpArg("limit", limit));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getUserProfilePhotos", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		UserProfilePhotos::ptr usr_profile_photos = std::make_shared<UserProfilePhotos>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				usr_profile_photos = std::make_shared<UserProfilePhotos>(tools::Tools::get_json_as_string(doc["result"]));

		return usr_profile_photos;
	}

	File::ptr Endpoints::getFile(const std::string &file_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("file_id", file_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getFile", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		File::ptr file = std::make_shared<File>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				file = std::make_shared<File>(tools::Tools::get_json_as_string(doc["result"]));

		return file;
	}

	bool Endpoints::kickChatMember(const long long &chat_id, const int &user_id, const int &until_date) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("user_id", user_id));
		http_args.push_back(tools::HttpArg("until_date", until_date));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/kickChatMember", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::unbanChatMember(const long long &chat_id, const int &user_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("user_id", user_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/unbanChatMember", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::restrictChatMember(const long long &chat_id, const int &user_id, const ChatPermissions::ptr &permissions, const int &until_date) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("user_id", user_id));
		http_args.push_back(tools::HttpArg("permissions", permissions->parse_to_json()));
		http_args.push_back(tools::HttpArg("until_date", until_date));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/restrictChatMember", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::promoteChatMember(const long long &chat_id, const int &user_id, const bool &can_change_info, const bool &can_post_messages,
			const bool &can_edit_messages, const bool &can_delete_messages, const bool &can_invite_users, const bool &can_restrict_members,
			const bool &can_pin_messages, const bool &can_promote_members) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("user_id", user_id));
		http_args.push_back(tools::HttpArg("can_change_info", can_change_info));
		http_args.push_back(tools::HttpArg("can_post_messages", can_post_messages));
		http_args.push_back(tools::HttpArg("can_edit_messages", can_edit_messages));
		http_args.push_back(tools::HttpArg("can_delete_messages", can_delete_messages));
		http_args.push_back(tools::HttpArg("can_invite_users", can_invite_users));
		http_args.push_back(tools::HttpArg("can_restrict_members", can_restrict_members));
		http_args.push_back(tools::HttpArg("can_pin_messages", can_pin_messages));
		http_args.push_back(tools::HttpArg("can_promote_members", can_promote_members));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/promoteChatMember", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::setChatPermissions(const long long &chat_id, const ChatPermissions::ptr &permissions) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("permissions", permissions->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatPermissions", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::exportChatInviteLink(const long long &chat_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/exportChatInviteLink", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::setChatPhoto(const long long &chat_id, const tools::InputFile::ptr &photo) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("photo", photo));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatPhoto", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::deleteChatPhoto(const long long &chat_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteChatPhoto", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::setChatTitle(const long long &chat_id, const std::string &title) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("title", title));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatTitle", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::setChatDescription(const long long &chat_id, const std::string &description) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("description", description));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatDescription", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::pinChatMessage(const long long &chat_id, const int &message_id, const bool &disable_notification) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("description", message_id));
		http_args.push_back(tools::HttpArg("description", disable_notification));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/pinChatMessage", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::unpinChatMessage(const long long &chat_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/unpinChatMessage", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::leaveChat(const long long &chat_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/leaveChat", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	Chat::ptr Endpoints::getChat(const long long &chat_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getChat", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Chat::ptr chat = std::make_shared<Chat>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				chat = std::make_shared<Chat>(tools::Tools::get_json_as_string(doc["result"]));

		return chat;
	}

	std::vector<ChatMember::ptr> Endpoints::getChatAdministrators(const long long &chat_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getChatAdministrators", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		std::vector<ChatMember::ptr> admins;

		if(doc.IsObject())
			if(doc.HasMember("result"))
			{
				if(doc["result"].IsArray())
				{
					const rapidjson::Value &array = doc["result"].GetArray();
					for(std::size_t j = 0; j< array.Size(); ++j)
						admins.push_back(std::make_shared<ChatMember>(tools::Tools::get_json_as_string(array[j])));
				}
			}

		return admins;
	}

	int Endpoints::getChatMembersCount(const long long &chat_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getChatMembersCount", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetInt();

		return 0;
	}

	ChatMember::ptr Endpoints::getChatMember(const long long &chat_id, const int &user_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("user_id", user_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getChatMember", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		ChatMember::ptr chat_member = std::make_shared<ChatMember>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				chat_member = std::make_shared<ChatMember>(tools::Tools::get_json_as_string(doc["result"]));

		return chat_member;
	}

	bool Endpoints::setChatStickerSet(const long long &chat_id, const std::string &sticker_set_name) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("sticker_set_name", sticker_set_name));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatStickerSet", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::deleteChatStickerSet(const long long &chat_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteChatStickerSet", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::answerCallbackQuery(const std::string &callback_query_id, const std::string &text, const bool &show_alert, const std::string &url,
			const int &cache_time) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("callback_query_id", callback_query_id));
		http_args.push_back(tools::HttpArg("text", text));
		http_args.push_back(tools::HttpArg("show_alert", show_alert));
		http_args.push_back(tools::HttpArg("url", url));
		http_args.push_back(tools::HttpArg("cache_time", cache_time));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/answerCallbackQuery", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	Message::ptr Endpoints::editMessageText(const std::string &text, const long long &chat_id, const int &message_id, const std::string &inline_message_id,
			const std::string &parse_mode, const bool &disable_web_page_preview, const Reply::ptr reply_markup) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("text", text));
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));
		http_args.push_back(tools::HttpArg("inline_message_id", inline_message_id));
		http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
		http_args.push_back(tools::HttpArg("disable_web_page_preview", disable_web_page_preview));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/editMessageText", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::editMessageCaption(const long long &chat_id, const int &message_id, const std::string &inline_message_id, const std::string &caption,
			const std::string &parse_mode, const Reply::ptr reply_markup) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));
		http_args.push_back(tools::HttpArg("inline_message_id", inline_message_id));
		http_args.push_back(tools::HttpArg("caption", caption));
		http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/editMessageCaption", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	/*
	 * todo
	 * editing a media by uploading a new image does not work although the principle is the same as with sendMediaGroup
	 */
	Message::ptr Endpoints::editMessageMedia(
			const std::variant<InputMediaAnimation::ptr, InputMediaAudio::ptr, InputMediaDocument::ptr, InputMediaPhoto::ptr, InputMediaVideo::ptr> &media,
			const long long &chat_id, const int &message_id, const std::string &inline_message_id, const Reply::ptr reply_markup) const
	{
		//contains the paths to files which need to be uploaded
		std::vector<std::string> files_to_upload;

		//gather the proper json
		std::string media_json;

		//InputMediaAnimation
		if(std::holds_alternative<InputMediaAnimation::ptr>(media))
		{
			media_json = std::get<InputMediaAnimation::ptr>(media)->parse_to_json();

			//we only need to upload the media if the media is of type InputFile
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaAnimation::ptr>(media)->media))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaAnimation::ptr>(media)->media)->m_path);

			//we only need to upload the thumb if the media is of type InputFile
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaAnimation::ptr>(media)->thumb))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaAnimation::ptr>(media)->thumb)->m_path);

		}
		//InputMediaAudio
		else if(std::holds_alternative<InputMediaAudio::ptr>(media))
		{
			media_json = std::get<InputMediaAudio::ptr>(media)->parse_to_json();

			//we only need to upload the media if the media is of type InputFile
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaAudio::ptr>(media)->media))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaAudio::ptr>(media)->media)->m_path);

			//we only need to upload the thumb if the media is of type InputFile
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaAudio::ptr>(media)->thumb))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaAudio::ptr>(media)->thumb)->m_path);
		}
		//InputMediaDocument
		else if(std::holds_alternative<InputMediaDocument::ptr>(media))
		{
			media_json = std::get<InputMediaDocument::ptr>(media)->parse_to_json();

			//we only need to upload the media if the media is of type InputFile
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaDocument::ptr>(media)->media))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaDocument::ptr>(media)->media)->m_path);

			//we only need to upload the thumb if the media is of type InputFile
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaDocument::ptr>(media)->thumb))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaDocument::ptr>(media)->thumb)->m_path);
		}
		/*
		 * InputMediaPhoto
		 * has not member variable thumb
		 */
		else if(std::holds_alternative<InputMediaPhoto::ptr>(media))
		{
			media_json = std::get<InputMediaPhoto::ptr>(media)->parse_to_json();

			//we only need to upload the media if the media is of type InputFile
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaPhoto::ptr>(media)->media))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaPhoto::ptr>(media)->media)->m_path);
		}
		//InputMediaVideo
		else if(std::holds_alternative<InputMediaVideo::ptr>(media))
		{
			media_json = std::get<InputMediaVideo::ptr>(media)->parse_to_json();

			//we only need to upload the media if the media is of type InputFile
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaVideo::ptr>(media)->media))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaVideo::ptr>(media)->media)->m_path);

			//we only need to upload the thumb if the media is of type InputFile
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaVideo::ptr>(media)->thumb))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaVideo::ptr>(media)->thumb)->m_path);
		}

		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));
		http_args.push_back(tools::HttpArg("inline_message_id", inline_message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));
			//plus files which need to be uploaded
		for(std::size_t j = 0; j < files_to_upload.size(); ++j)
		{
			tools::InputFile::ptr temp = std::make_shared<tools::InputFile>(files_to_upload.at(j));
			http_args.push_back(tools::HttpArg(files_to_upload.at(j), temp));
		}

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/editMessageMedia", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::editMessageReplyMarkup(const Reply::ptr &reply_markup, const long long &chat_id, const int &message_id, const std::string &inline_message_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));
		http_args.push_back(tools::HttpArg("inline_message_id", inline_message_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/editMessageReplyMarkup", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	Poll::ptr Endpoints::stopPoll(const long long &chat_id, const int &message_id, const Reply::ptr reply_markup) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/stopPoll", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Poll::ptr poll = std::make_shared<Poll>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				poll = std::make_shared<Poll>(tools::Tools::get_json_as_string(doc["result"]));

		return poll;
	}

	bool Endpoints::deleteMessage(const long long &chat_id, const int &message_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteMessage", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	Message::ptr Endpoints::sendSticker(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &sticker, const bool &disable_notification,
			const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(sticker))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("sticker", std::get<std::string>(sticker)));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendSticker", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(sticker))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("chat_id", chat_id));
			http_args.push_back(tools::HttpArg("sticker", std::get<tools::InputFile::ptr>(sticker)));
			http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
			http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendSticker", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.IsObject())
				if(doc.HasMember("result"))
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

			return msg;
		}

		Message::ptr msg = std::make_shared<Message>();
		return msg;
	}

	StickerSet::ptr Endpoints::getStickerSet(const std::string &name) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("name", name));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getStickerSet", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		StickerSet::ptr sticker_set = std::make_shared<StickerSet>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				sticker_set = std::make_shared<StickerSet>(tools::Tools::get_json_as_string(doc["result"]));

		return sticker_set;
	}

	File::ptr Endpoints::uploadStickerFile(const int &user_id, const tools::InputFile::ptr &png_sticker) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("user_id", user_id));
		http_args.push_back(tools::HttpArg("png_sticker", png_sticker));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/uploadStickerFile", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		File::ptr file = std::make_shared<File>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				file = std::make_shared<File>(tools::Tools::get_json_as_string(doc["result"]));

		return file;
	}

	bool Endpoints::createNewStickerSet(const int &user_id, const std::string &name, const std::string &title,
			const std::variant<std::string, tools::InputFile::ptr> &png_sticker, const std::string &emojis, const bool &contains_mask,
			const MaskPosition::ptr &mask_position) const
	{
		if(std::holds_alternative<std::string>(png_sticker))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("user_id", user_id));
			http_args.push_back(tools::HttpArg("name", name));
			http_args.push_back(tools::HttpArg("title", title));
			http_args.push_back(tools::HttpArg("png_sticker", std::get<std::string>(png_sticker)));
			http_args.push_back(tools::HttpArg("emojis", emojis));
			http_args.push_back(tools::HttpArg("contains_mask", contains_mask));
			http_args.push_back(tools::HttpArg("mask_position", mask_position->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/createNewStickerSet", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			if(doc.IsObject())
				if(doc.HasMember("result"))
					return doc["result"].GetBool();

			return false;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(png_sticker))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("user_id", user_id));
			http_args.push_back(tools::HttpArg("name", name));
			http_args.push_back(tools::HttpArg("title", title));
			http_args.push_back(tools::HttpArg("png_sticker", std::get<tools::InputFile::ptr>(png_sticker)));
			http_args.push_back(tools::HttpArg("emojis", emojis));
			http_args.push_back(tools::HttpArg("contains_mask", contains_mask));
			http_args.push_back(tools::HttpArg("mask_position", mask_position->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/createNewStickerSet", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			if(doc.IsObject())
				if(doc.HasMember("result"))
					return doc["result"].GetBool();

			return false;
		}

		return false;
	}

	bool Endpoints::addStickerToSet(const int &user_id, const std::string &name, const std::string &title,
			const std::variant<std::string, tools::InputFile::ptr> &png_sticker, const std::string &emojis, const MaskPosition::ptr &mask_position) const
	{
		if(std::holds_alternative<std::string>(png_sticker))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("user_id", user_id));
			http_args.push_back(tools::HttpArg("name", name));
			http_args.push_back(tools::HttpArg("title", title));
			http_args.push_back(tools::HttpArg("png_sticker", std::get<std::string>(png_sticker)));
			http_args.push_back(tools::HttpArg("emojis", emojis));
			http_args.push_back(tools::HttpArg("mask_position", mask_position->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/addStickerToSet", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			if(doc.IsObject())
				if(doc.HasMember("result"))
					return doc["result"].GetBool();

			return false;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(png_sticker))
		{
			//http args
			std::vector<tools::HttpArg> http_args;
			http_args.push_back(tools::HttpArg("user_id", user_id));
			http_args.push_back(tools::HttpArg("name", name));
			http_args.push_back(tools::HttpArg("title", title));
			http_args.push_back(tools::HttpArg("png_sticker", std::get<tools::InputFile::ptr>(png_sticker)));
			http_args.push_back(tools::HttpArg("emojis", emojis));
			http_args.push_back(tools::HttpArg("mask_position", mask_position->parse_to_json()));

			tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/addStickerToSet", http_args);
			std::string json = http_client.send_post_req_multipart().m_body;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			if(doc.IsObject())
				if(doc.HasMember("result"))
					return doc["result"].GetBool();

			return false;
		}

		return false;
	}

	bool Endpoints::setStickerPositionInSet(const std::string &sticker, const int &position) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("sticker", sticker));
		http_args.push_back(tools::HttpArg("position", position));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setStickerPositionInSet", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::deleteStickerFromSet(const std::string &sticker) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("sticker", sticker));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteStickerFromSet", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::answerInlineQuery(const std::string &inline_query_id, const std::vector<InlineQueryResult::ptr> &results, const int &cache_time, const bool &is_personal,
				const std::string &next_offset, const std::string &switch_pm_text, const std::string &switch_pm_parameter) const
	{
		//go through vector to build up the json array
		std::string results_json = "[";

		for(std::size_t j = 0; j < results.size(); ++j)
		{
			results_json.append(results.at(j)->parse_to_json());

			//make ready for next json object
			results_json.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * results and not results_json in condition as in that case we would destroy the json array
		 */
		if(results.size() > 0)
		{
			//finish json array
			results_json.pop_back();
			results_json.pop_back();
		}
		results_json.append("]");

		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("inline_query_id", inline_query_id));
		http_args.push_back(tools::HttpArg("results", results_json));
		http_args.push_back(tools::HttpArg("cache_time", cache_time));
		http_args.push_back(tools::HttpArg("is_personal", is_personal));
		http_args.push_back(tools::HttpArg("next_offset", next_offset));
		http_args.push_back(tools::HttpArg("switch_pm_text", switch_pm_text));
		http_args.push_back(tools::HttpArg("switch_pm_parameter", switch_pm_parameter));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/answerInlineQuery", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	Message::ptr Endpoints::sendInvoice(const long long &chat_id, const std::string &title, const std::string &description, const std::string &payload,
			const std::string &provider_token, const std::string &start_parameter, const std::string &currency, const std::vector<LabeledPrice::ptr> &prices,
			const std::string &provider_data, const std::string &photo_url, const int &photo_size, const int &photo_width, const int &photo_height,
			const bool &need_name, const bool &need_phone_number, const bool &need_email, const bool &need_shipping_address,
			const bool &send_phone_number_to_provider, const bool &send_email_to_provider, const bool &is_flexible, const bool &disable_notification,
			const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		//go through vector to build up the json array
		std::string prices_json = "[";

		for(std::size_t j = 0; j < prices.size(); ++j)
		{
			prices_json.append(prices.at(j)->parse_to_json());

			//make ready for next json object
			prices_json.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * prices and not prices_json in condition as in that case we would destroy the json array
		 */
		if(prices.size() > 0)
		{
			//finish json array
			prices_json.pop_back();
			prices_json.pop_back();
		}
		prices_json.append("]");

		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("title", title));
		http_args.push_back(tools::HttpArg("description", description));
		http_args.push_back(tools::HttpArg("payload", payload));
		http_args.push_back(tools::HttpArg("provider_token", provider_token));
		http_args.push_back(tools::HttpArg("start_parameter", start_parameter));
		http_args.push_back(tools::HttpArg("currency", currency));
		http_args.push_back(tools::HttpArg("prices", prices_json));
		http_args.push_back(tools::HttpArg("provider_data", provider_data));
		http_args.push_back(tools::HttpArg("photo_url", photo_url));
		http_args.push_back(tools::HttpArg("photo_size", photo_size));
		http_args.push_back(tools::HttpArg("photo_width", photo_width));
		http_args.push_back(tools::HttpArg("photo_height", photo_height));
		http_args.push_back(tools::HttpArg("need_name", need_name));
		http_args.push_back(tools::HttpArg("need_phone_number", need_phone_number));
		http_args.push_back(tools::HttpArg("need_email", need_email));
		http_args.push_back(tools::HttpArg("need_shipping_address", need_shipping_address));
		http_args.push_back(tools::HttpArg("send_phone_number_to_provider", send_phone_number_to_provider));
		http_args.push_back(tools::HttpArg("send_email_to_provider", send_email_to_provider));
		http_args.push_back(tools::HttpArg("is_flexible", is_flexible));
		http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
		http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendInvoice", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	bool Endpoints::answerShippingQuery(const std::string &shipping_query_id, const bool &ok, const std::vector<ShippingOption::ptr> &shipping_options,
			const std::string &error_message) const
	{
		//go through vector to build up the json array
		std::string shipping_options_json = "[";

		for(std::size_t j = 0; j < shipping_options.size(); ++j)
		{
			shipping_options_json.append(shipping_options.at(j)->parse_to_json());

			//make ready for next json object
			shipping_options_json.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * shipping_options and not shipping_options_json in condition as in that case we would destroy the json array
		 */
		if(shipping_options.size() > 0)
		{
			//finish json array
			shipping_options_json.pop_back();
			shipping_options_json.pop_back();
		}
		shipping_options_json.append("]");

		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("shipping_query_id", shipping_query_id));
		http_args.push_back(tools::HttpArg("ok", ok));
		http_args.push_back(tools::HttpArg("shipping_options", shipping_options_json));
		http_args.push_back(tools::HttpArg("error_message", error_message));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/answerShippingQuery", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::answerPreCheckoutQuery(const std::string &pre_checkout_query_id, const bool &ok, const std::string &error_message) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("pre_checkout_query_id", pre_checkout_query_id));
		http_args.push_back(tools::HttpArg("ok", ok));
		http_args.push_back(tools::HttpArg("error_message", error_message));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/answerPreCheckoutQuery", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::setPassportDataErrors(const int &user_id, const bool &ok, const std::vector<PassportElementError::ptr> &errors) const
	{
		//go through vector to build up the json array
		std::string errors_json = "[";

		for(std::size_t j = 0; j < errors.size(); ++j)
		{
			errors_json.append(errors.at(j)->parse_to_json());

			//make ready for next json object
			errors_json.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * errors and not errors_json in condition as in that case we would destroy the json array
		 */
		if(errors.size() > 0)
		{
			//finish json array
			errors_json.pop_back();
			errors_json.pop_back();
		}
		errors_json.append("]");

		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("user_id", user_id));
		http_args.push_back(tools::HttpArg("errors", errors_json));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setPassportDataErrors", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				return doc["result"].GetBool();

		return false;
	}

	Message::ptr Endpoints::sendGame(const long long &chat_id, const std::string &game_short_name, const bool &disable_notification, const int &reply_to_message_id,
			const InlineKeyboardMarkup::ptr &reply_markup) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("game_short_name", game_short_name));
		http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
		http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendGame", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::setGameScore(const int &user_id, const int &score, const bool &force, const bool &disable_edit_message, const long long &chat_id,
			const int &message_id, const std::string &inline_message_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("user_id", user_id));
		http_args.push_back(tools::HttpArg("score", score));
		http_args.push_back(tools::HttpArg("force", force));
		http_args.push_back(tools::HttpArg("disable_edit_message", disable_edit_message));
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));
		http_args.push_back(tools::HttpArg("inline_message_id", inline_message_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setGameScore", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));

		return msg;
	}

	std::vector<GameHighScore::ptr> Endpoints::getGameHighScores(const int &user_id, const long long &chat_id, const int &message_id ,
			const std::string &inline_message_id) const
	{
		//http args
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("user_id", user_id));
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));
		http_args.push_back(tools::HttpArg("inline_message_id", inline_message_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getGameHighScores", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		std::vector<GameHighScore::ptr> game_high_score;

		if(doc.IsObject())
			if(doc.HasMember("result"))
			{
				if(doc["result"].IsArray())
				{
					const rapidjson::Value &array = doc["result"].GetArray();
					for(std::size_t j = 0; j< array.Size(); ++j)
						game_high_score.push_back(std::make_shared<GameHighScore>(tools::Tools::get_json_as_string(array[j])));
				}
			}

		return game_high_score;
	}
}
