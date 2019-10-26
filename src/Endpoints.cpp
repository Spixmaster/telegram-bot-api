#include <tgbot/SpecialTools.h>
#include "tgbot/http/HttpClient.h"
#include "tgbot/http/InputFile.h"
#include "tgbot/Endpoints.h"
#include "tgbot/types/ReplyKeyboardRemove.h"
#include "tgbot/types/User.h"
#include <iostream>

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
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("offset", offset));
		http_args.push_back(HttpArg("limit", limit));
		http_args.push_back(HttpArg("timeout", timeout));
		http_args.push_back(HttpArg("allowed_updates", allowed_updates_json));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getUpdates", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		std::vector<Update::ptr> updates;

		if(doc.HasMember("result"))
		{
			if(doc["result"].IsArray())
			{
				const rapidjson::Value &array = doc["result"].GetArray();
				for(std::size_t j = 0; j< array.Size(); ++j)
					updates.push_back(std::make_shared<Update>(SpecialTools::get_json_obj_as_string(array[j])));
			}
		}

		return updates;
	}

	bool Endpoints::setWebhook(const std::string &url, const InputFile::ptr &certificate, const int &max_connections, const std::vector<std::string> &allowed_updates) const
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
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("url", url));
		http_args.push_back(HttpArg("certificate", certificate));
		http_args.push_back(HttpArg("max_connections", max_connections));
		http_args.push_back(HttpArg("allowed_updates", allowed_updates_json));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setWebhook", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::deleteWebhook() const
	{
		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteWebhook");
		std::string json = http_client.send_get_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	WebhookInfo::ptr Endpoints::getWebhookInfo() const
	{
		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getWebhookInfo");
		std::string json = http_client.send_get_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		WebhookInfo::ptr webhook_info = std::make_shared<WebhookInfo>();

		if(doc.HasMember("result"))
			webhook_info = std::make_shared<WebhookInfo>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return webhook_info;
	}

	User::ptr Endpoints::getMe() const
	{
		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getMe");
		std::string json = http_client.send_get_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		User::ptr usr = std::make_shared<User>();

		if(doc.HasMember("result"))
			usr = std::make_shared<User>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return usr;
	}

	Message::ptr Endpoints::sendMessage(const long long &chat_id, const std::string &text, const std::string &parse_mode, const bool &disable_web_page_preview,
			const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("text", text));
		http_args.push_back(HttpArg("parse_mode", parse_mode));
		http_args.push_back(HttpArg("disable_web_page_preview", disable_web_page_preview));
		http_args.push_back(HttpArg("disable_notification", disable_notification));
		http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendMessage", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::forwardMessage(const long long &chat_id, const long long &from_chat_id, const int &message_id, const bool &disable_notification) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("from_chat_id", from_chat_id));
		http_args.push_back(HttpArg("message_id", message_id));
		http_args.push_back(HttpArg("disable_notification", disable_notification));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/forwardMessage", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::sendPhoto(const long long &chat_id, const std::variant<std::string, InputFile::ptr> &photo, const std::string &caption, const std::string &parse_mode,
			const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(photo))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("photo", std::get<std::string>(photo)));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendPhoto", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		else
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("photo", std::get<InputFile::ptr>(photo)));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendPhoto", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
	}

	Message::ptr Endpoints::sendAudio(const long long &chat_id, const std::variant<std::string, InputFile::ptr> &audio, const std::variant<std::string, InputFile::ptr> &thumb,
			const std::string &caption, const std::string &parse_mode, const int &duration, const std::string &performer, const std::string &title,
			const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(audio) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("audio", std::get<std::string>(audio)));
			http_args.push_back(HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("performer", performer));
			http_args.push_back(HttpArg("title", title));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAudio", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<InputFile::ptr>(audio) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("audio", std::get<InputFile::ptr>(audio)));
			http_args.push_back(HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("performer", performer));
			http_args.push_back(HttpArg("title", title));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAudio", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<std::string>(audio) && std::holds_alternative<InputFile::ptr>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("audio", std::get<std::string>(audio)));
			http_args.push_back(HttpArg("thumb", std::get<InputFile::ptr>(thumb)));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("performer", performer));
			http_args.push_back(HttpArg("title", title));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAudio", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		//both are of type InputFile
		else
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("audio", std::get<InputFile::ptr>(audio)));
			http_args.push_back(HttpArg("thumb", std::get<InputFile::ptr>(thumb)));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("performer", performer));
			http_args.push_back(HttpArg("title", title));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAudio", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
	}

	Message::ptr Endpoints::sendDocument(const long long &chat_id, const std::variant<std::string, InputFile::ptr> &document, const std::variant<std::string, InputFile::ptr> &thumb,
			const std::string &caption, const std::string &parse_mode, const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(document) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("document", std::get<std::string>(document)));
			http_args.push_back(HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendDocument", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<InputFile::ptr>(document) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("document", std::get<InputFile::ptr>(document)));
			http_args.push_back(HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendDocument", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<std::string>(document) && std::holds_alternative<InputFile::ptr>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("document", std::get<std::string>(document)));
			http_args.push_back(HttpArg("thumb", std::get<InputFile::ptr>(thumb)));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendDocument", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		//both are of type InputFile
		else
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("document", std::get<InputFile::ptr>(document)));
			http_args.push_back(HttpArg("thumb", std::get<InputFile::ptr>(thumb)));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendDocument", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
	}

	Message::ptr Endpoints::sendVideo(const long long &chat_id, const std::variant<std::string, InputFile::ptr> &video, const std::variant<std::string, InputFile::ptr> &thumb,
			const int &duration, const int &width, const int &height, const std::string &caption, const std::string &parse_mode,const bool &supports_streaming,
			const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(video) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("video", std::get<std::string>(video)));
			http_args.push_back(HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("width", width));
			http_args.push_back(HttpArg("height", height));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("supports_streaming", supports_streaming));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideo", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<InputFile::ptr>(video) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("video", std::get<InputFile::ptr>(video)));
			http_args.push_back(HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("width", width));
			http_args.push_back(HttpArg("height", height));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("supports_streaming", supports_streaming));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideo", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<std::string>(video) && std::holds_alternative<InputFile::ptr>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("video", std::get<std::string>(video)));
			http_args.push_back(HttpArg("thumb", std::get<InputFile::ptr>(thumb)));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("width", width));
			http_args.push_back(HttpArg("height", height));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("supports_streaming", supports_streaming));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideo", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		//both are of type InputFile
		else
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("video", std::get<InputFile::ptr>(video)));
			http_args.push_back(HttpArg("thumb", std::get<InputFile::ptr>(thumb)));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("width", width));
			http_args.push_back(HttpArg("height", height));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("supports_streaming", supports_streaming));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideo", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
	}

	Message::ptr Endpoints::sendAnimation(const long long &chat_id, const std::variant<std::string, InputFile::ptr> &animation, const std::variant<std::string, InputFile::ptr> &thumb,
			const int &duration, const int &width, const int &height, const std::string &caption, const std::string &parse_mode, const bool &disable_notification,
			const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(animation) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("animation", std::get<std::string>(animation)));
			http_args.push_back(HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("width", width));
			http_args.push_back(HttpArg("height", height));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAnimation", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<InputFile::ptr>(animation) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("animation", std::get<InputFile::ptr>(animation)));
			http_args.push_back(HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("width", width));
			http_args.push_back(HttpArg("height", height));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAnimation", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<std::string>(animation) && std::holds_alternative<InputFile::ptr>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("animation", std::get<std::string>(animation)));
			http_args.push_back(HttpArg("thumb", std::get<InputFile::ptr>(thumb)));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("width", width));
			http_args.push_back(HttpArg("height", height));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAnimation", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		//both are of type InputFile
		else
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("animation", std::get<InputFile::ptr>(animation)));
			http_args.push_back(HttpArg("thumb", std::get<InputFile::ptr>(thumb)));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("width", width));
			http_args.push_back(HttpArg("height", height));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendAnimation", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
	}

	Message::ptr Endpoints::sendVoice(const long long &chat_id, const std::variant<std::string, InputFile::ptr> &voice, const std::string &caption, const std::string &parse_mode,
			const int &duration, const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(voice))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("voice", std::get<std::string>(voice)));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVoice", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		//of type InputFile
		else
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("voice", std::get<InputFile::ptr>(voice)));
			http_args.push_back(HttpArg("caption", caption));
			http_args.push_back(HttpArg("parse_mode", parse_mode));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVoice", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
	}

	Message::ptr Endpoints::sendVideoNote(const long long &chat_id, const std::variant<std::string, InputFile::ptr> &video_note, const std::variant<std::string, InputFile::ptr> &thumb,
			const int &duration, const int &length, const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(video_note) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("video_note", std::get<std::string>(video_note)));
			http_args.push_back(HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("length", length));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideoNote", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<InputFile::ptr>(video_note) && std::holds_alternative<std::string>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("video_note", std::get<InputFile::ptr>(video_note)));
			http_args.push_back(HttpArg("thumb", std::get<std::string>(thumb)));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("length", length));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideoNote", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		else if(std::holds_alternative<std::string>(video_note) && std::holds_alternative<InputFile::ptr>(thumb))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("video_note", std::get<std::string>(video_note)));
			http_args.push_back(HttpArg("thumb", std::get<InputFile::ptr>(thumb)));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("length", length));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideoNote", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		//both are of type InputFile
		else
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("video_note", std::get<InputFile::ptr>(video_note)));
			http_args.push_back(HttpArg("thumb", std::get<InputFile::ptr>(thumb)));
			http_args.push_back(HttpArg("duration", duration));
			http_args.push_back(HttpArg("length", length));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVideoNote", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
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
				if(std::holds_alternative<InputFile::ptr>(std::get<InputMediaPhoto::ptr>(media.at(j))->media))
					files_to_upload.push_back(std::get<InputFile::ptr>(std::get<InputMediaPhoto::ptr>(media.at(j))->media)->m_path);
			}
			//is InputMediaVideo
			else
			{
				media_json.append(std::get<InputMediaVideo::ptr>(media.at(j))->parse_to_json());

				//we only need to upload if the media is of type InputFile
				if(std::holds_alternative<InputFile::ptr>(std::get<InputMediaVideo::ptr>(media.at(j))->media))
					files_to_upload.push_back(std::get<InputFile::ptr>(std::get<InputMediaVideo::ptr>(media.at(j))->media)->m_path);
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
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("media", media_json));
		http_args.push_back(HttpArg("disable_notification", disable_notification));
		http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));
			//plus files which need to be uploaded
		for(std::size_t j = 0; j < files_to_upload.size(); ++j)
		{
			InputFile::ptr temp = std::make_shared<InputFile>(files_to_upload.at(j));
			http_args.push_back(HttpArg(files_to_upload.at(j), temp));
		}

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendMediaGroup", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		std::vector<Message::ptr> msgs;

		if(doc.HasMember("result"))
		{
			if(doc["result"].IsArray())
			{
				const rapidjson::Value &array = doc["result"].GetArray();
				for(std::size_t j = 0; j< array.Size(); ++j)
					msgs.push_back(std::make_shared<Message>(SpecialTools::get_json_obj_as_string(array[j])));
			}
		}

		return msgs;
	}

	Message::ptr Endpoints::sendLocation(const long long &chat_id, const float &latitude, const float &longitude, const int &live_period, const bool &disable_notification,
			const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("latitude", latitude));
		http_args.push_back(HttpArg("longitude", longitude));
		http_args.push_back(HttpArg("live_period", live_period));
		http_args.push_back(HttpArg("live_period", live_period));
		http_args.push_back(HttpArg("disable_notification", disable_notification));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendLocation", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::editMessageLiveLocation(const float &latitude, const float &longitude, const long long &chat_id, const int &message_id,
			const std::string &inline_message_id, const Reply::ptr &reply_markup) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("latitude", latitude));
		http_args.push_back(HttpArg("longitude", longitude));
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("message_id", message_id));
		http_args.push_back(HttpArg("inline_message_id", inline_message_id));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/editMessageLiveLocation", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::stopMessageLiveLocation(const long long &chat_id, const int &message_id, const std::string &inline_message_id,
			const Reply::ptr &reply_markup) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("message_id", message_id));
		http_args.push_back(HttpArg("inline_message_id", inline_message_id));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/stopMessageLiveLocation", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::sendVenue(const long long &chat_id, const float &latitude, const float &longitude, const std::string &title, const std::string &address,
			const std::string &foursquare_id, const std::string &foursquare_type, const bool &disable_notification, const int &reply_to_message_id,
			const Reply::ptr &reply_markup) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("latitude", latitude));
		http_args.push_back(HttpArg("longitude", longitude));
		http_args.push_back(HttpArg("title", title));
		http_args.push_back(HttpArg("address", address));
		http_args.push_back(HttpArg("foursquare_id", foursquare_id));
		http_args.push_back(HttpArg("foursquare_type", foursquare_type));
		http_args.push_back(HttpArg("disable_notification", disable_notification));
		http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendVenue", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::sendContact(const long long &chat_id, const std::string &phone_number, const std::string &first_name, const std::string &last_name,
			const std::string &vcard, const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("phone_number", phone_number));
		http_args.push_back(HttpArg("first_name", first_name));
		http_args.push_back(HttpArg("last_name", last_name));
		http_args.push_back(HttpArg("vcard", vcard));
		http_args.push_back(HttpArg("disable_notification", disable_notification));
		http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendContact", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

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
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("question", question));
		http_args.push_back(HttpArg("options", options_json));
		http_args.push_back(HttpArg("disable_notification", disable_notification));
		http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendPoll", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return msg;
	}

	bool Endpoints::sendChatAction(const long long &chat_id, const std::string &action) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("action", action));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendChatAction", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	UserProfilePhotos::ptr Endpoints::getUserProfilePhotos(const int &user_id, const int &offset, const int &limit) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("user_id", user_id));
		if(offset != -1)
			http_args.push_back(HttpArg("offset", offset));
		http_args.push_back(HttpArg("limit", limit));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getUserProfilePhotos", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		UserProfilePhotos::ptr usr_profile_photos = std::make_shared<UserProfilePhotos>();

		if(doc.HasMember("result"))
			usr_profile_photos = std::make_shared<UserProfilePhotos>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return usr_profile_photos;
	}

	File::ptr Endpoints::getFile(const std::string &file_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("file_id", file_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getFile", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		File::ptr file = std::make_shared<File>();

		if(doc.HasMember("result"))
			file = std::make_shared<File>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return file;
	}

	bool Endpoints::kickChatMember(const long long &chat_id, const int &user_id, const int &until_date) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("user_id", user_id));
		http_args.push_back(HttpArg("until_date", until_date));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/kickChatMember", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::unbanChatMember(const long long &chat_id, const int &user_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("user_id", user_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/unbanChatMember", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::restrictChatMember(const long long &chat_id, const int &user_id, const ChatPermissions::ptr &permissions, const int &until_date) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("user_id", user_id));
		http_args.push_back(HttpArg("permissions", permissions->parse_to_json()));
		http_args.push_back(HttpArg("until_date", until_date));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/restrictChatMember", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::promoteChatMember(const long long &chat_id, const int &user_id, const bool &can_change_info, const bool &can_post_messages, const bool &can_edit_messages,
			const bool &can_delete_messages, const bool &can_invite_users, const bool &can_restrict_members, const bool &can_pin_messages, const bool &can_promote_members) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("user_id", user_id));
		http_args.push_back(HttpArg("can_change_info", can_change_info));
		http_args.push_back(HttpArg("can_post_messages", can_post_messages));
		http_args.push_back(HttpArg("can_edit_messages", can_edit_messages));
		http_args.push_back(HttpArg("can_delete_messages", can_delete_messages));
		http_args.push_back(HttpArg("can_invite_users", can_invite_users));
		http_args.push_back(HttpArg("can_restrict_members", can_restrict_members));
		http_args.push_back(HttpArg("can_pin_messages", can_pin_messages));
		http_args.push_back(HttpArg("can_promote_members", can_promote_members));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/promoteChatMember", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::setChatPermissions(const long long &chat_id, const ChatPermissions::ptr &permissions) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("permissions", permissions->parse_to_json()));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatPermissions", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::exportChatInviteLink(const long long &chat_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/exportChatInviteLink", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::setChatPhoto(const long long &chat_id, const InputFile::ptr &photo) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("photo", photo));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatPhoto", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::deleteChatPhoto(const long long &chat_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteChatPhoto", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::setChatTitle(const long long &chat_id, const std::string &title) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("title", title));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatTitle", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::setChatDescription(const long long &chat_id, const std::string &description) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("description", description));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatDescription", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::pinChatMessage(const long long &chat_id, const int &message_id, const bool &disable_notification) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("description", message_id));
		http_args.push_back(HttpArg("description", disable_notification));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/pinChatMessage", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::unpinChatMessage(const long long &chat_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/unpinChatMessage", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::leaveChat(const long long &chat_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/leaveChat", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	Chat::ptr Endpoints::getChat(const long long &chat_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getChat", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Chat::ptr chat = std::make_shared<Chat>();

		if(doc.HasMember("result"))
			chat = std::make_shared<Chat>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return chat;
	}

	std::vector<ChatMember::ptr> Endpoints::getChatAdministrators(const long long &chat_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getChatAdministrators", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		std::vector<ChatMember::ptr> admins;

		if(doc.HasMember("result"))
		{
			if(doc["result"].IsArray())
			{
				const rapidjson::Value &array = doc["result"].GetArray();
				for(std::size_t j = 0; j< array.Size(); ++j)
					admins.push_back(std::make_shared<ChatMember>(SpecialTools::get_json_obj_as_string(array[j])));
			}
		}

		return admins;
	}

	int Endpoints::getChatMembersCount(const long long &chat_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getChatMembersCount", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetInt();

		return 0;
	}

	ChatMember::ptr Endpoints::getChatMember(const long long &chat_id, const int &user_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("user_id", user_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getChatMember", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		ChatMember::ptr chat_member = std::make_shared<ChatMember>();

		if(doc.HasMember("result"))
			chat_member = std::make_shared<ChatMember>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return chat_member;
	}

	bool Endpoints::setChatStickerSet(const long long &chat_id, const std::string &sticker_set_name) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("sticker_set_name", sticker_set_name));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatStickerSet", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::deleteChatStickerSet(const long long &chat_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteChatStickerSet", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::answerCallbackQuery(const std::string &callback_query_id, const std::string &text, const bool &show_alert, const std::string &url,
			const int &cache_time) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("callback_query_id", callback_query_id));
		http_args.push_back(HttpArg("text", text));
		http_args.push_back(HttpArg("show_alert", show_alert));
		http_args.push_back(HttpArg("url", url));
		http_args.push_back(HttpArg("cache_time", cache_time));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/answerCallbackQuery", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	Message::ptr Endpoints::editMessageText(const std::string &text, const long long &chat_id, const int &message_id, const std::string &inline_message_id,
			const std::string &parse_mode, const bool &disable_web_page_preview, const Reply::ptr reply_markup) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("text", text));
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("message_id", message_id));
		http_args.push_back(HttpArg("inline_message_id", inline_message_id));
		http_args.push_back(HttpArg("parse_mode", parse_mode));
		http_args.push_back(HttpArg("disable_web_page_preview", disable_web_page_preview));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/editMessageText", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::editMessageCaption(const long long &chat_id, const int &message_id, const std::string &inline_message_id, const std::string &caption,
			const std::string &parse_mode, const Reply::ptr reply_markup) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("message_id", message_id));
		http_args.push_back(HttpArg("inline_message_id", inline_message_id));
		http_args.push_back(HttpArg("caption", caption));
		http_args.push_back(HttpArg("parse_mode", parse_mode));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/editMessageCaption", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

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
			if(std::holds_alternative<InputFile::ptr>(std::get<InputMediaAnimation::ptr>(media)->media))
				files_to_upload.push_back(std::get<InputFile::ptr>(std::get<InputMediaAnimation::ptr>(media)->media)->m_path);

			//we only need to upload the thumb if the media is of type InputFile
			if(std::holds_alternative<InputFile::ptr>(std::get<InputMediaAnimation::ptr>(media)->thumb))
				files_to_upload.push_back(std::get<InputFile::ptr>(std::get<InputMediaAnimation::ptr>(media)->thumb)->m_path);

		}
		//InputMediaAudio
		else if(std::holds_alternative<InputMediaAudio::ptr>(media))
		{
			media_json = std::get<InputMediaAudio::ptr>(media)->parse_to_json();

			//we only need to upload the media if the media is of type InputFile
			if(std::holds_alternative<InputFile::ptr>(std::get<InputMediaAudio::ptr>(media)->media))
				files_to_upload.push_back(std::get<InputFile::ptr>(std::get<InputMediaAudio::ptr>(media)->media)->m_path);

			//we only need to upload the thumb if the media is of type InputFile
			if(std::holds_alternative<InputFile::ptr>(std::get<InputMediaAudio::ptr>(media)->thumb))
				files_to_upload.push_back(std::get<InputFile::ptr>(std::get<InputMediaAudio::ptr>(media)->thumb)->m_path);
		}
		//InputMediaDocument
		else if(std::holds_alternative<InputMediaDocument::ptr>(media))
		{
			media_json = std::get<InputMediaDocument::ptr>(media)->parse_to_json();

			//we only need to upload the media if the media is of type InputFile
			if(std::holds_alternative<InputFile::ptr>(std::get<InputMediaDocument::ptr>(media)->media))
				files_to_upload.push_back(std::get<InputFile::ptr>(std::get<InputMediaDocument::ptr>(media)->media)->m_path);

			//we only need to upload the thumb if the media is of type InputFile
			if(std::holds_alternative<InputFile::ptr>(std::get<InputMediaDocument::ptr>(media)->thumb))
				files_to_upload.push_back(std::get<InputFile::ptr>(std::get<InputMediaDocument::ptr>(media)->thumb)->m_path);
		}
		/*
		 * InputMediaPhoto
		 * has not member variable thumb
		 */
		else if(std::holds_alternative<InputMediaPhoto::ptr>(media))
		{
			media_json = std::get<InputMediaPhoto::ptr>(media)->parse_to_json();

			//we only need to upload the media if the media is of type InputFile
			if(std::holds_alternative<InputFile::ptr>(std::get<InputMediaPhoto::ptr>(media)->media))
				files_to_upload.push_back(std::get<InputFile::ptr>(std::get<InputMediaPhoto::ptr>(media)->media)->m_path);
		}
		//InputMediaVideo
		else
		{
			media_json = std::get<InputMediaVideo::ptr>(media)->parse_to_json();

			//we only need to upload the media if the media is of type InputFile
			if(std::holds_alternative<InputFile::ptr>(std::get<InputMediaVideo::ptr>(media)->media))
				files_to_upload.push_back(std::get<InputFile::ptr>(std::get<InputMediaVideo::ptr>(media)->media)->m_path);

			//we only need to upload the thumb if the media is of type InputFile
			if(std::holds_alternative<InputFile::ptr>(std::get<InputMediaVideo::ptr>(media)->thumb))
				files_to_upload.push_back(std::get<InputFile::ptr>(std::get<InputMediaVideo::ptr>(media)->thumb)->m_path);
		}

		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("message_id", message_id));
		http_args.push_back(HttpArg("inline_message_id", inline_message_id));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));
			//plus files which need to be uploaded
		for(std::size_t j = 0; j < files_to_upload.size(); ++j)
		{
			InputFile::ptr temp = std::make_shared<InputFile>(files_to_upload.at(j));
			http_args.push_back(HttpArg(files_to_upload.at(j), temp));
		}

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/editMessageMedia", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::editMessageReplyMarkup(const Reply::ptr &reply_markup, const long long &chat_id, const int &message_id, const std::string &inline_message_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("message_id", message_id));
		http_args.push_back(HttpArg("inline_message_id", inline_message_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/editMessageReplyMarkup", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return msg;
	}

	Poll::ptr Endpoints::stopPoll(const long long &chat_id, const int &message_id, const Reply::ptr reply_markup) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("message_id", message_id));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/stopPoll", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Poll::ptr poll = std::make_shared<Poll>();

		if(doc.HasMember("result"))
			poll = std::make_shared<Poll>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return poll;
	}

	bool Endpoints::deleteMessage(const long long &chat_id, const int &message_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("message_id", message_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteMessage", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	Message::ptr Endpoints::sendSticker(const long long &chat_id, const std::variant<std::string, InputFile::ptr> &sticker, const bool &disable_notification,
			const int &reply_to_message_id, const Reply::ptr &reply_markup) const
	{
		if(std::holds_alternative<std::string>(sticker))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("sticker", std::get<std::string>(sticker)));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendSticker", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
		else
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("chat_id", chat_id));
			http_args.push_back(HttpArg("sticker", std::get<InputFile::ptr>(sticker)));
			http_args.push_back(HttpArg("disable_notification", disable_notification));
			http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
			http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendSticker", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			Message::ptr msg = std::make_shared<Message>();

			if(doc.HasMember("result"))
				msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

			return msg;
		}
	}

	StickerSet::ptr Endpoints::getStickerSet(const std::string &name) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("name", name));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getStickerSet", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		StickerSet::ptr sticker_set = std::make_shared<StickerSet>();

		if(doc.HasMember("result"))
			sticker_set = std::make_shared<StickerSet>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return sticker_set;
	}

	File::ptr Endpoints::uploadStickerFile(const int &user_id, const InputFile::ptr &png_sticker) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("user_id", user_id));
		http_args.push_back(HttpArg("png_sticker", png_sticker));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/uploadStickerFile", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		File::ptr file = std::make_shared<File>();

		if(doc.HasMember("result"))
			file = std::make_shared<File>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return file;
	}

	bool Endpoints::createNewStickerSet(const int &user_id, const std::string &name, const std::string &title, const std::variant<std::string, InputFile::ptr> &png_sticker,
			const std::string &emojis, const bool &contains_mask, const MaskPosition::ptr &mask_position) const
	{
		if(std::holds_alternative<std::string>(png_sticker))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("user_id", user_id));
			http_args.push_back(HttpArg("name", name));
			http_args.push_back(HttpArg("title", title));
			http_args.push_back(HttpArg("png_sticker", std::get<std::string>(png_sticker)));
			http_args.push_back(HttpArg("emojis", emojis));
			http_args.push_back(HttpArg("contains_mask", contains_mask));
			http_args.push_back(HttpArg("mask_position", mask_position->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/createNewStickerSet", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			if(doc.HasMember("result"))
				return doc["result"].GetBool();

			return false;
		}
		else
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("user_id", user_id));
			http_args.push_back(HttpArg("name", name));
			http_args.push_back(HttpArg("title", title));
			http_args.push_back(HttpArg("png_sticker", std::get<InputFile::ptr>(png_sticker)));
			http_args.push_back(HttpArg("emojis", emojis));
			http_args.push_back(HttpArg("contains_mask", contains_mask));
			http_args.push_back(HttpArg("mask_position", mask_position->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/createNewStickerSet", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			if(doc.HasMember("result"))
				return doc["result"].GetBool();

			return false;
		}
	}

	bool Endpoints::addStickerToSet(const int &user_id, const std::string &name, const std::string &title, const std::variant<std::string, InputFile::ptr> &png_sticker,
			const std::string &emojis, const MaskPosition::ptr &mask_position) const
	{
		if(std::holds_alternative<std::string>(png_sticker))
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("user_id", user_id));
			http_args.push_back(HttpArg("name", name));
			http_args.push_back(HttpArg("title", title));
			http_args.push_back(HttpArg("png_sticker", std::get<std::string>(png_sticker)));
			http_args.push_back(HttpArg("emojis", emojis));
			http_args.push_back(HttpArg("mask_position", mask_position->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/addStickerToSet", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			if(doc.HasMember("result"))
				return doc["result"].GetBool();

			return false;
		}
		else
		{
			//http args
			std::vector<HttpArg> http_args;
			http_args.push_back(HttpArg("user_id", user_id));
			http_args.push_back(HttpArg("name", name));
			http_args.push_back(HttpArg("title", title));
			http_args.push_back(HttpArg("png_sticker", std::get<InputFile::ptr>(png_sticker)));
			http_args.push_back(HttpArg("emojis", emojis));
			http_args.push_back(HttpArg("mask_position", mask_position->parse_to_json()));

			HttpClient http_client("https://api.telegram.org/bot" + m_token + "/addStickerToSet", http_args);
			std::string json = http_client.send_post_req().response;

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			if(doc.HasMember("result"))
				return doc["result"].GetBool();

			return false;
		}
	}

	bool Endpoints::setStickerPositionInSet(const std::string &sticker, const int &position) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("sticker", sticker));
		http_args.push_back(HttpArg("position", position));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setStickerPositionInSet", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::deleteStickerFromSet(const std::string &sticker) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("sticker", sticker));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteStickerFromSet", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

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
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("inline_query_id", inline_query_id));
		http_args.push_back(HttpArg("results", results_json));
		http_args.push_back(HttpArg("cache_time", cache_time));
		http_args.push_back(HttpArg("is_personal", is_personal));
		http_args.push_back(HttpArg("next_offset", next_offset));
		http_args.push_back(HttpArg("switch_pm_text", switch_pm_text));
		http_args.push_back(HttpArg("switch_pm_parameter", switch_pm_parameter));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/answerInlineQuery", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	Message::ptr Endpoints::sendInvoice(const long long &chat_id, const std::string &title, const std::string &description, const std::string &payload, const std::string &provider_token,
			const std::string &start_parameter, const std::string &currency, const std::vector<LabeledPrice::ptr> &prices, const std::string &provider_data,
			const std::string &photo_url, const int &photo_size, const int &photo_width, const int &photo_height, const bool &need_name, const bool &need_phone_number,
			const bool &need_email, const bool &need_shipping_address, const bool &send_phone_number_to_provider, const bool &send_email_to_provider,
			const bool &is_flexible, const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const
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
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("title", title));
		http_args.push_back(HttpArg("description", description));
		http_args.push_back(HttpArg("payload", payload));
		http_args.push_back(HttpArg("provider_token", provider_token));
		http_args.push_back(HttpArg("start_parameter", start_parameter));
		http_args.push_back(HttpArg("currency", currency));
		http_args.push_back(HttpArg("prices", prices_json));
		http_args.push_back(HttpArg("provider_data", provider_data));
		http_args.push_back(HttpArg("photo_url", photo_url));
		http_args.push_back(HttpArg("photo_size", photo_size));
		http_args.push_back(HttpArg("photo_width", photo_width));
		http_args.push_back(HttpArg("photo_height", photo_height));
		http_args.push_back(HttpArg("need_name", need_name));
		http_args.push_back(HttpArg("need_phone_number", need_phone_number));
		http_args.push_back(HttpArg("need_email", need_email));
		http_args.push_back(HttpArg("need_shipping_address", need_shipping_address));
		http_args.push_back(HttpArg("send_phone_number_to_provider", send_phone_number_to_provider));
		http_args.push_back(HttpArg("send_email_to_provider", send_email_to_provider));
		http_args.push_back(HttpArg("is_flexible", is_flexible));
		http_args.push_back(HttpArg("disable_notification", disable_notification));
		http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendInvoice", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

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
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("shipping_query_id", shipping_query_id));
		http_args.push_back(HttpArg("ok", ok));
		http_args.push_back(HttpArg("shipping_options", shipping_options_json));
		http_args.push_back(HttpArg("error_message", error_message));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/answerShippingQuery", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	bool Endpoints::answerPreCheckoutQuery(const std::string &pre_checkout_query_id, const bool &ok, const std::string &error_message) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("pre_checkout_query_id", pre_checkout_query_id));
		http_args.push_back(HttpArg("ok", ok));
		http_args.push_back(HttpArg("error_message", error_message));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/answerPreCheckoutQuery", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

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
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("user_id", user_id));
		http_args.push_back(HttpArg("errors", errors_json));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setPassportDataErrors", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.HasMember("result"))
			return doc["result"].GetBool();

		return false;
	}

	Message::ptr Endpoints::sendGame(const long long &chat_id, const std::string &game_short_name, const bool &disable_notification, const int &reply_to_message_id,
			const InlineKeyboardMarkup::ptr &reply_markup) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("game_short_name", game_short_name));
		http_args.push_back(HttpArg("disable_notification", disable_notification));
		http_args.push_back(HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(HttpArg("reply_markup", reply_markup->parse_to_json()));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendGame", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return msg;
	}

	Message::ptr Endpoints::setGameScore(const int &user_id, const int &score, const bool &force, const bool &disable_edit_message, const long long &chat_id,
			const int &message_id, const std::string &inline_message_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("user_id", user_id));
		http_args.push_back(HttpArg("score", score));
		http_args.push_back(HttpArg("force", force));
		http_args.push_back(HttpArg("disable_edit_message", disable_edit_message));
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("message_id", message_id));
		http_args.push_back(HttpArg("inline_message_id", inline_message_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setGameScore", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.HasMember("result"))
			msg = std::make_shared<Message>(SpecialTools::get_json_obj_as_string(doc["result"]));

		return msg;
	}

	std::vector<GameHighScore::ptr> Endpoints::getGameHighScores(const int &user_id, const long long &chat_id, const int &message_id , const std::string &inline_message_id) const
	{
		//http args
		std::vector<HttpArg> http_args;
		http_args.push_back(HttpArg("user_id", user_id));
		http_args.push_back(HttpArg("chat_id", chat_id));
		http_args.push_back(HttpArg("message_id", message_id));
		http_args.push_back(HttpArg("inline_message_id", inline_message_id));

		HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getGameHighScores", http_args);
		std::string json = http_client.send_post_req().response;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		std::vector<GameHighScore::ptr> game_high_score;

		if(doc.HasMember("result"))
		{
			if(doc["result"].IsArray())
			{
				const rapidjson::Value &array = doc["result"].GetArray();
				for(std::size_t j = 0; j< array.Size(); ++j)
					game_high_score.push_back(std::make_shared<GameHighScore>(SpecialTools::get_json_obj_as_string(array[j])));
			}
		}

		return game_high_score;
	}
}
