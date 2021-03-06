#include "tools/http/HttpClient.h"
#include "tools/http/InputFile.h"
#include "tgbot/Endpoints.h"
#include "tgbot/types/ReplyKeyboardRemove.h"
#include "tgbot/types/User.h"
#include <iostream>
#include "tools/Tools.h"
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	Endpoints::Endpoints(const std::string &token) : m_token(token)
	{}

	std::vector<Update::ptr> Endpoints::getUpdates(const int &offset, const int &limit, const int &timeout, const std::vector<std::string> &allowed_updates) const noexcept
	{
		std::string allowed_updates_json = "[";

		for(std::size_t j = 0; j < allowed_updates.size(); ++j)
		{
			allowed_updates_json.append(allowed_updates.at(j));

			if(j != allowed_updates.size() - 1)
				allowed_updates_json.append(", ");
		}

		allowed_updates_json.append("]");

		//HTTP arguments
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
		{
			if(doc.HasMember("result"))
			{
				if(doc["result"].IsArray())
				{
					const rapidjson::Value &array = doc["result"].GetArray();

					for(std::size_t j = 0; j < array.Size(); ++j)
						updates.push_back(std::make_shared<Update>(tools::Tools::get_json_as_string(array[j])));
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("result"));
			}
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		}
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return updates;
	}

	bool Endpoints::setWebhook(const std::string &url, const tools::InputFile::ptr &certificate, const int &max_connections,
			const std::vector<std::string> &allowed_updates) const noexcept
	{
		std::string allowed_updates_json = "[";

		for(std::size_t j = 0; j < allowed_updates.size(); ++j)
		{
			allowed_updates_json.append(allowed_updates.at(j));

			if(j != allowed_updates.size() - 1)
				allowed_updates_json.append(", ");
		}

		allowed_updates_json.append("]");

		//HTTP arguments
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
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::deleteWebhook() const noexcept
	{
		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteWebhook");
		std::string json = http_client.send_get_req().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	WebhookInfo::ptr Endpoints::getWebhookInfo() const noexcept
	{
		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getWebhookInfo");
		std::string json = http_client.send_get_req().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		WebhookInfo::ptr webhook_info = std::make_shared<WebhookInfo>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsObject())
					webhook_info = std::make_shared<WebhookInfo>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return webhook_info;
	}

	User::ptr Endpoints::getMe() const noexcept
	{
		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getMe");
		std::string json = http_client.send_get_req().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		User::ptr usr = std::make_shared<User>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsObject())
					usr = std::make_shared<User>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return usr;
	}

	Message::ptr Endpoints::sendMessage(const long long &chat_id, const std::string &text, const std::string &parse_mode, const bool &disable_web_page_preview,
			const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::forwardMessage(const long long &chat_id, const long long &from_chat_id, const int &message_id, const bool &disable_notification) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::sendPhoto(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &photo, const std::string &caption,
			const std::string &parse_mode, const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const noexcept
	{
		if(std::holds_alternative<std::string>(photo))
		{
			//HTTP arguments
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
					if(doc["result"].IsObject())
						msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
					else
						tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
				else
					tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

			return msg;
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(photo))
		{
			//HTTP arguments
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
					if(doc["result"].IsObject())
						msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
					else
						tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
				else
					tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

			return msg;
		}

		Message::ptr msg = std::make_shared<Message>();
		return msg;
	}

	Message::ptr Endpoints::sendAudio(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &audio, const std::string &caption,
			const std::string &parse_mode, const int &duration, const std::string &performer, const std::string &title,
			const std::variant<std::string, tools::InputFile::ptr> &thumb, const bool &disable_notification, const int &reply_to_message_id,
			const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		if(std::holds_alternative<std::string>(audio))
			http_args.push_back(tools::HttpArg("audio", std::get<std::string>(audio)));
		else if(std::holds_alternative<tools::InputFile::ptr>(audio))
			http_args.push_back(tools::HttpArg("audio", std::get<tools::InputFile::ptr>(audio)));

		http_args.push_back(tools::HttpArg("caption", caption));
		http_args.push_back(tools::HttpArg("parse_mode", parse_mode));
		http_args.push_back(tools::HttpArg("duration", duration));
		http_args.push_back(tools::HttpArg("performer", performer));
		http_args.push_back(tools::HttpArg("title", title));

		if(std::holds_alternative<std::string>(thumb))
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
		else if(std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			http_args.push_back(tools::HttpArg("thumb", "attach://" + std::get<tools::InputFile::ptr>(thumb)->m_path));
			http_args.push_back(tools::HttpArg(std::get<tools::InputFile::ptr>(thumb)->m_path, std::get<tools::InputFile::ptr>(thumb)));
		}

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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::sendDocument(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &document,
			const std::variant<std::string, tools::InputFile::ptr> &thumb, const std::string &caption, const std::string &parse_mode,
			const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		if(std::holds_alternative<std::string>(document))
			http_args.push_back(tools::HttpArg("document", std::get<std::string>(document)));
		else if(std::holds_alternative<tools::InputFile::ptr>(document))
			http_args.push_back(tools::HttpArg("document", std::get<tools::InputFile::ptr>(document)));

		if(std::holds_alternative<std::string>(thumb))
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
		else if(std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			http_args.push_back(tools::HttpArg("thumb", "attach://" + std::get<tools::InputFile::ptr>(thumb)->m_path));
			http_args.push_back(tools::HttpArg(std::get<tools::InputFile::ptr>(thumb)->m_path, std::get<tools::InputFile::ptr>(thumb)));
		}

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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::sendVideo(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &video, const int &duration, const int &width,
			const int &height, const std::variant<std::string, tools::InputFile::ptr> &thumb, const std::string &caption,
			const std::string &parse_mode, const bool &supports_streaming, const bool &disable_notification, const int &reply_to_message_id,
			const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		if(std::holds_alternative<std::string>(video))
			http_args.push_back(tools::HttpArg("video", std::get<std::string>(video)));
		else if(std::holds_alternative<tools::InputFile::ptr>(video))
			http_args.push_back(tools::HttpArg("video", std::get<tools::InputFile::ptr>(video)));

		http_args.push_back(tools::HttpArg("duration", duration));
		http_args.push_back(tools::HttpArg("width", width));
		http_args.push_back(tools::HttpArg("height", height));

		if(std::holds_alternative<std::string>(thumb))
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
		else if(std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			http_args.push_back(tools::HttpArg("thumb", "attach://" + std::get<tools::InputFile::ptr>(thumb)->m_path));
			http_args.push_back(tools::HttpArg(std::get<tools::InputFile::ptr>(thumb)->m_path, std::get<tools::InputFile::ptr>(thumb)));
		}

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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::sendAnimation(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &animation,
			const int &duration, const int &width, const int &height, const std::variant<std::string, tools::InputFile::ptr> &thumb,
			const std::string &caption, const std::string &parse_mode, const bool &disable_notification, const int &reply_to_message_id,
			const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		if(std::holds_alternative<std::string>(animation))
			http_args.push_back(tools::HttpArg("animation", std::get<std::string>(animation)));
		else if(std::holds_alternative<tools::InputFile::ptr>(animation))
			http_args.push_back(tools::HttpArg("animation", std::get<tools::InputFile::ptr>(animation)));

		http_args.push_back(tools::HttpArg("duration", duration));
		http_args.push_back(tools::HttpArg("width", width));
		http_args.push_back(tools::HttpArg("height", height));

		if(std::holds_alternative<std::string>(thumb))
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
		else if(std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			http_args.push_back(tools::HttpArg("thumb", "attach://" + std::get<tools::InputFile::ptr>(thumb)->m_path));
			http_args.push_back(tools::HttpArg(std::get<tools::InputFile::ptr>(thumb)->m_path, std::get<tools::InputFile::ptr>(thumb)));
		}

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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::sendVoice(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &voice, const std::string &caption,
			const std::string &parse_mode, const int &duration, const bool &disable_notification, const int &reply_to_message_id,
			const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		if(std::holds_alternative<std::string>(voice))
			http_args.push_back(tools::HttpArg("voice", std::get<std::string>(voice)));
		else if(std::holds_alternative<tools::InputFile::ptr>(voice))
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::sendVideoNote(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &video_note,
			const int &duration, const int &length, const std::variant<std::string, tools::InputFile::ptr> &thumb,
			const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		if(std::holds_alternative<std::string>(video_note))
			http_args.push_back(tools::HttpArg("video_note", std::get<std::string>(video_note)));
		else if(std::holds_alternative<tools::InputFile::ptr>(video_note))
			http_args.push_back(tools::HttpArg("video_note", std::get<tools::InputFile::ptr>(video_note)));

		http_args.push_back(tools::HttpArg("duration", duration));
		http_args.push_back(tools::HttpArg("length", length));

		if(std::holds_alternative<std::string>(thumb))
			http_args.push_back(tools::HttpArg("thumb", std::get<std::string>(thumb)));
		else if(std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			http_args.push_back(tools::HttpArg("thumb", "attach://" + std::get<tools::InputFile::ptr>(thumb)->m_path));
			http_args.push_back(tools::HttpArg(std::get<tools::InputFile::ptr>(thumb)->m_path, std::get<tools::InputFile::ptr>(thumb)));
		}

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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	std::vector<Message::ptr> Endpoints::sendMediaGroup(const long long &chat_id, const std::vector<std::variant<InputMediaPhoto::ptr, InputMediaVideo::ptr>> &media,
			const bool &disable_notification, const int &reply_to_message_id) const noexcept
	{
		//The vector contains all paths to files which need to be uploaded.
		std::vector<std::string> files_to_upload;

		//Go through vector to build up the JSON array.
		std::string media_json = "[";

		for(std::size_t j = 0; j < media.size(); ++j)
		{
			if(std::holds_alternative<InputMediaPhoto::ptr>(media.at(j)))
			{
				media_json.append(std::get<InputMediaPhoto::ptr>(media.at(j))->parse_to_json());

				//We only need to upload if the media is of type InputFile.
				if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaPhoto::ptr>(media.at(j))->media))
					files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaPhoto::ptr>(media.at(j))->media)->m_path);
			}
			else if(std::holds_alternative<InputMediaVideo::ptr>(media.at(j)))
			{
				media_json.append(std::get<InputMediaVideo::ptr>(media.at(j))->parse_to_json());

				//We only need to upload if the media is of type InputFile.
				if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaVideo::ptr>(media.at(j))->media))
					files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaVideo::ptr>(media.at(j))->media)->m_path);
			}

			if(j != media.size() - 1)
				media_json.append(", ");
		}

		media_json.append("]");

		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("media", media_json));
		http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
		http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));

		//Upload the files to the server.
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
				if(doc["result"].IsArray())
				{
					const rapidjson::Value &array = doc["result"].GetArray();

					for(std::size_t j = 0; j < array.Size(); ++j)
					{
						if(array[j].IsObject())
							msgs.push_back(std::make_shared<Message>(tools::Tools::get_json_as_string(array[j])));
						else
						{
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("result"));
							continue;
						}
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msgs;
	}

	Message::ptr Endpoints::sendLocation(const long long &chat_id, const float &latitude, const float &longitude, const int &live_period, const bool &disable_notification,
			const int &reply_to_message_id, const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("latitude", std::to_string(latitude)));
		http_args.push_back(tools::HttpArg("longitude", std::to_string(longitude)));
		http_args.push_back(tools::HttpArg("live_period", live_period));
		http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
		http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendLocation", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::editMessageLiveLocation(const float &latitude, const float &longitude, const long long &chat_id, const int &message_id,
			const std::string &inline_message_id, const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("latitude", std::to_string(latitude)));
		http_args.push_back(tools::HttpArg("longitude", std::to_string(longitude)));
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::stopMessageLiveLocation(const long long &chat_id, const int &message_id, const std::string &inline_message_id,
			const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::sendVenue(const long long &chat_id, const float &latitude, const float &longitude, const std::string &title, const std::string &address,
			const std::string &foursquare_id, const std::string &foursquare_type, const bool &disable_notification, const int &reply_to_message_id,
			const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("latitude", std::to_string(latitude)));
		http_args.push_back(tools::HttpArg("longitude", std::to_string(longitude)));
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::sendContact(const long long &chat_id, const std::string &phone_number, const std::string &first_name, const std::string &last_name,
			const std::string &vcard, const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::sendPoll(const long long &chat_id, const std::string &question, const std::vector<std::string> &options, const bool &is_anonymous,
			const std::string &type, const bool &allows_multiple_answers, const int &correct_option_id, const std::string &explanation,
			const std::string &explanation_parse_mode, const int &open_period, const int &close_date, const bool &is_closed,
			const bool &disable_notification, const int &reply_to_message_id, const Reply::ptr &reply_markup) const noexcept
	{
		//Create a JSON array of options.
		std::string options_json = "[";

		for(std::size_t j = 0; j < options.size(); ++j)
		{
			options_json.append("\"" + options.at(j) + "\"");

			if(j != options.size() - 1)
				options_json.append(", ");
		}

		options_json.append("]");

		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("question", question));
		http_args.push_back(tools::HttpArg("options", options_json));
		http_args.push_back(tools::HttpArg("is_anonymous", is_anonymous));
		http_args.push_back(tools::HttpArg("type", type));
		http_args.push_back(tools::HttpArg("allows_multiple_answers", allows_multiple_answers));

		if(correct_option_id != -1)
			http_args.push_back(tools::HttpArg("correct_option_id", correct_option_id));

		http_args.push_back(tools::HttpArg("explanation", explanation));
		http_args.push_back(tools::HttpArg("explanation_parse_mode", explanation_parse_mode));
		http_args.push_back(tools::HttpArg("open_period", open_period));
		http_args.push_back(tools::HttpArg("close_date", close_date));
		http_args.push_back(tools::HttpArg("is_closed", is_closed));
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::sendDice(const long long &chat_id, const std::string &emoji, const bool &disable_notification, const int &reply_to_message_id,
			const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("emoji", emoji));
		http_args.push_back(tools::HttpArg("disable_notification", disable_notification));
		http_args.push_back(tools::HttpArg("reply_to_message_id", reply_to_message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendDice", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	bool Endpoints::sendChatAction(const long long &chat_id, const std::string &action) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("action", action));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/sendChatAction", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	UserProfilePhotos::ptr Endpoints::getUserProfilePhotos(const int &user_id, const int &offset, const int &limit) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsObject())
					usr_profile_photos = std::make_shared<UserProfilePhotos>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return usr_profile_photos;
	}

	File::ptr Endpoints::getFile(const std::string &file_id) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("file_id", file_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getFile", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		File::ptr file = std::make_shared<File>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsObject())
					file = std::make_shared<File>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return file;
	}

	bool Endpoints::kickChatMember(const long long &chat_id, const int &user_id, const int &until_date) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::unbanChatMember(const long long &chat_id, const int &user_id) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("user_id", user_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/unbanChatMember", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::restrictChatMember(const long long &chat_id, const int &user_id, const ChatPermissions::ptr &permissions, const int &until_date) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::promoteChatMember(const long long &chat_id, const int &user_id, const bool &can_change_info, const bool &can_post_messages,
			const bool &can_edit_messages, const bool &can_delete_messages, const bool &can_invite_users, const bool &can_restrict_members,
			const bool &can_pin_messages, const bool &can_promote_members) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::setChatAdministratorCustomTitle(const long long &chat_id, const int &user_id, const std::string &custom_title) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("user_id", user_id));
		http_args.push_back(tools::HttpArg("custom_title", custom_title));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatAdministratorCustomTitle", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::setChatPermissions(const long long &chat_id, const ChatPermissions::ptr &permissions) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("permissions", permissions->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatPermissions", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::exportChatInviteLink(const long long &chat_id) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/exportChatInviteLink", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::setChatPhoto(const long long &chat_id, const tools::InputFile::ptr &photo) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("photo", photo));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatPhoto", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::deleteChatPhoto(const long long &chat_id) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteChatPhoto", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::setChatTitle(const long long &chat_id, const std::string &title) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("title", title));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatTitle", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::setChatDescription(const long long &chat_id, const std::string &description) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("description", description));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatDescription", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::pinChatMessage(const long long &chat_id, const int &message_id, const bool &disable_notification) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::unpinChatMessage(const long long &chat_id) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/unpinChatMessage", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::leaveChat(const long long &chat_id) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/leaveChat", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	Chat::ptr Endpoints::getChat(const long long &chat_id) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getChat", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Chat::ptr chat = std::make_shared<Chat>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsObject())
					chat = std::make_shared<Chat>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return chat;
	}

	std::vector<ChatMember::ptr> Endpoints::getChatAdministrators(const long long &chat_id) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getChatAdministrators", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		std::vector<ChatMember::ptr> admins;

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsArray())
				{
					const rapidjson::Value &array = doc["result"].GetArray();

					for(std::size_t j = 0; j < array.Size(); ++j)
					{
						if(array[j].IsObject())
							admins.push_back(std::make_shared<ChatMember>(tools::Tools::get_json_as_string(array[j])));
						else
						{
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("result"));
							continue;
						}
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return admins;
	}

	int Endpoints::getChatMembersCount(const long long &chat_id) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getChatMembersCount", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsInt())
					return doc["result"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return 0;
	}

	ChatMember::ptr Endpoints::getChatMember(const long long &chat_id, const int &user_id) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsObject())
					chat_member = std::make_shared<ChatMember>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return chat_member;
	}

	bool Endpoints::setChatStickerSet(const long long &chat_id, const std::string &sticker_set_name) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("sticker_set_name", sticker_set_name));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setChatStickerSet", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::deleteChatStickerSet(const long long &chat_id) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteChatStickerSet", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::answerCallbackQuery(const std::string &callback_query_id, const std::string &text, const bool &show_alert, const std::string &url,
			const int &cache_time) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::setMyCommands(const std::vector<BotCommand::ptr> commands) const noexcept
	{
		//Create the value for commands.
		std::string commands_json = "[";

		for(std::size_t j = 0; j < commands.size(); ++j)
		{
			commands_json.append(commands.at(j)->parse_to_json());

			if(j != commands.size() - 1)
				commands_json.append(", ");
		}

		commands_json.append("]");

		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("commands", commands_json));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setMyCommands", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	std::vector<BotCommand::ptr> Endpoints::getMyCommands() const noexcept
	{
		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getMyCommands");
		std::string json = http_client.send_get_req().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		std::vector<BotCommand::ptr> my_cmds;

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsArray())
				{
					const rapidjson::Value &array = doc["result"].GetArray();

					for(std::size_t j = 0; j < array.Size(); ++j)
					{
						if(array[j].IsObject())
							my_cmds.push_back(std::make_shared<BotCommand>(tools::Tools::get_json_as_string(array[j])));
						else
						{
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("result"));
							continue;
						}
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return my_cmds;
	}

	Message::ptr Endpoints::editMessageText(const std::string &text, const long long &chat_id, const int &message_id, const std::string &inline_message_id,
			const std::string &parse_mode, const bool &disable_web_page_preview, const Reply::ptr reply_markup) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::editMessageCaption(const long long &chat_id, const int &message_id, const std::string &inline_message_id, const std::string &caption,
			const std::string &parse_mode, const Reply::ptr reply_markup) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::editMessageMedia(
			const std::variant<InputMediaAnimation::ptr, InputMediaAudio::ptr, InputMediaDocument::ptr, InputMediaPhoto::ptr, InputMediaVideo::ptr> &media,
			const long long &chat_id, const int &message_id, const std::string &inline_message_id, const Reply::ptr reply_markup) const noexcept
	{
		//Contains the paths to files which need to be uploaded.
		std::vector<std::string> files_to_upload;

		//Create the JSON.
		std::string media_json;

		if(std::holds_alternative<InputMediaAnimation::ptr>(media))
		{
			media_json = std::get<InputMediaAnimation::ptr>(media)->parse_to_json();

			//We only need to upload the media if the media is of type InputFile.
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaAnimation::ptr>(media)->media))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaAnimation::ptr>(media)->media)->m_path);

			//We only need to upload the thumb if the media is of type InputFile.
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaAnimation::ptr>(media)->thumb))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaAnimation::ptr>(media)->thumb)->m_path);

		}
		else if(std::holds_alternative<InputMediaAudio::ptr>(media))
		{
			media_json = std::get<InputMediaAudio::ptr>(media)->parse_to_json();

			//We only need to upload the media if the media is of type InputFile.
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaAudio::ptr>(media)->media))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaAudio::ptr>(media)->media)->m_path);

			//We only need to upload the thumb if the media is of type InputFile.
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaAudio::ptr>(media)->thumb))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaAudio::ptr>(media)->thumb)->m_path);
		}
		else if(std::holds_alternative<InputMediaDocument::ptr>(media))
		{
			media_json = std::get<InputMediaDocument::ptr>(media)->parse_to_json();

			//We only need to upload the media if the media is of type InputFile.
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaDocument::ptr>(media)->media))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaDocument::ptr>(media)->media)->m_path);

			//We only need to upload the thumb if the media is of type InputFile.
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaDocument::ptr>(media)->thumb))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaDocument::ptr>(media)->thumb)->m_path);
		}
		//InputMediaPhoto does not have the member variable thumb.
		else if(std::holds_alternative<InputMediaPhoto::ptr>(media))
		{
			media_json = std::get<InputMediaPhoto::ptr>(media)->parse_to_json();

			//We only need to upload the media if the media is of type InputFile.
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaPhoto::ptr>(media)->media))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaPhoto::ptr>(media)->media)->m_path);
		}
		else if(std::holds_alternative<InputMediaVideo::ptr>(media))
		{
			media_json = std::get<InputMediaVideo::ptr>(media)->parse_to_json();

			//We only need to upload the media if the media is of type InputFile.
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaVideo::ptr>(media)->media))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaVideo::ptr>(media)->media)->m_path);

			//We only need to upload the thumb if the media is of type InputFile.
			if(std::holds_alternative<tools::InputFile::ptr>(std::get<InputMediaVideo::ptr>(media)->thumb))
				files_to_upload.push_back(std::get<tools::InputFile::ptr>(std::get<InputMediaVideo::ptr>(media)->thumb)->m_path);
		}

		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));
		http_args.push_back(tools::HttpArg("inline_message_id", inline_message_id));
		http_args.push_back(tools::HttpArg("media", media_json));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		//Upload the files to the server.
		for(std::size_t j = 0; j < files_to_upload.size(); ++j)
		{
			tools::InputFile::ptr tmp = std::make_shared<tools::InputFile>(files_to_upload.at(j));
			http_args.push_back(tools::HttpArg(files_to_upload.at(j), tmp));
		}

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/editMessageMedia", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::editMessageReplyMarkup(const long long &chat_id, const int &message_id,
			const std::string &inline_message_id, const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));
		http_args.push_back(tools::HttpArg("inline_message_id", inline_message_id));
		http_args.push_back(tools::HttpArg("reply_markup", reply_markup->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/editMessageReplyMarkup", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		Message::ptr msg = std::make_shared<Message>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Poll::ptr Endpoints::stopPoll(const long long &chat_id, const int &message_id, const Reply::ptr reply_markup) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsObject())
					poll = std::make_shared<Poll>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return poll;
	}

	bool Endpoints::deleteMessage(const long long &chat_id, const int &message_id) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));
		http_args.push_back(tools::HttpArg("message_id", message_id));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteMessage", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	Message::ptr Endpoints::sendSticker(const long long &chat_id, const std::variant<std::string, tools::InputFile::ptr> &sticker, const bool &disable_notification,
			const int &reply_to_message_id, const Reply::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("chat_id", chat_id));

		if(std::holds_alternative<std::string>(sticker))
			http_args.push_back(tools::HttpArg("sticker", std::get<std::string>(sticker)));
		else if(std::holds_alternative<tools::InputFile::ptr>(sticker))
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	StickerSet::ptr Endpoints::getStickerSet(const std::string &name) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("name", name));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/getStickerSet", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		StickerSet::ptr sticker_set = std::make_shared<StickerSet>();

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsObject())
					sticker_set = std::make_shared<StickerSet>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return sticker_set;
	}

	File::ptr Endpoints::uploadStickerFile(const int &user_id, const tools::InputFile::ptr &png_sticker) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsObject())
					file = std::make_shared<File>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return file;
	}

	bool Endpoints::createNewStickerSet(const int &user_id, const std::string &name, const std::string &title, const std::string &emojis,
			const std::variant<std::string, tools::InputFile::ptr> &png_sticker, const tools::InputFile::ptr tgs_sticker,
			const bool &contains_mask, const MaskPosition::ptr &mask_position) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("user_id", user_id));
		http_args.push_back(tools::HttpArg("name", name));
		http_args.push_back(tools::HttpArg("title", title));

		if(std::holds_alternative<std::string>(png_sticker))
			http_args.push_back(tools::HttpArg("png_sticker", std::get<std::string>(png_sticker)));
		else if(std::holds_alternative<tools::InputFile::ptr>(png_sticker))
			http_args.push_back(tools::HttpArg("png_sticker", std::get<tools::InputFile::ptr>(png_sticker)));

		http_args.push_back(tools::HttpArg("tgs_sticker", tgs_sticker));
		http_args.push_back(tools::HttpArg("emojis", emojis));
		http_args.push_back(tools::HttpArg("contains_mask", contains_mask));
		http_args.push_back(tools::HttpArg("mask_position", mask_position->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/createNewStickerSet", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::addStickerToSet(const int &user_id, const std::string &name, const std::string &emojis,
			const std::variant<std::string, tools::InputFile::ptr> &png_sticker, const tools::InputFile::ptr tgs_sticker,
			const MaskPosition::ptr &mask_position) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("user_id", user_id));
		http_args.push_back(tools::HttpArg("name", name));
		http_args.push_back(tools::HttpArg(emojis, emojis));

		if(std::holds_alternative<std::string>(png_sticker))
			http_args.push_back(tools::HttpArg("png_sticker", std::get<std::string>(png_sticker)));
		else if(std::holds_alternative<tools::InputFile::ptr>(png_sticker))
			http_args.push_back(tools::HttpArg("png_sticker", std::get<tools::InputFile::ptr>(png_sticker)));

		http_args.push_back(tools::HttpArg("tgs_sticker", tgs_sticker));
		http_args.push_back(tools::HttpArg("mask_position", mask_position->parse_to_json()));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/addStickerToSet", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::setStickerPositionInSet(const std::string &sticker, const int &position) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("sticker", sticker));
		http_args.push_back(tools::HttpArg("position", position));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setStickerPositionInSet", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::deleteStickerFromSet(const std::string &sticker) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("sticker", sticker));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/deleteStickerFromSet", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::setStickerSetThumb(const std::string &name, const int &user_id, const std::variant<std::string, tools::InputFile::ptr> &thumb) const noexcept
	{
		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("name", name));
		http_args.push_back(tools::HttpArg("user_id", user_id));

		if(std::holds_alternative<std::string>(thumb))
			http_args.push_back(tools::HttpArg("sticker", std::get<std::string>(thumb)));
		else if(std::holds_alternative<tools::InputFile::ptr>(thumb))
			http_args.push_back(tools::HttpArg("sticker", std::get<tools::InputFile::ptr>(thumb)));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setStickerSetThumb", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::answerInlineQuery(const std::string &inline_query_id, const std::vector<InlineQueryResult::ptr> &results, const int &cache_time, const bool &is_personal,
				const std::string &next_offset, const std::string &switch_pm_text, const std::string &switch_pm_parameter) const noexcept
	{
		//Go through vector to build up the JSON array.
		std::string results_json = "[";

		for(std::size_t j = 0; j < results.size(); ++j)
		{
			results_json.append(results.at(j)->parse_to_json());

			if(j != results.size() - 1)
				results_json.append(", ");
		}

		results_json.append("]");

		//HTTP arguments
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
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	Message::ptr Endpoints::sendInvoice(const long long &chat_id, const std::string &title, const std::string &description, const std::string &payload,
			const std::string &provider_token, const std::string &start_parameter, const std::string &currency, const std::vector<LabeledPrice::ptr> &prices,
			const std::string &provider_data, const std::string &photo_url, const int &photo_size, const int &photo_width, const int &photo_height,
			const bool &need_name, const bool &need_phone_number, const bool &need_email, const bool &need_shipping_address,
			const bool &send_phone_number_to_provider, const bool &send_email_to_provider, const bool &is_flexible, const bool &disable_notification,
			const int &reply_to_message_id, const Reply::ptr &reply_markup) const noexcept
	{
		//Go through vector to build up the JSON array.
		std::string prices_json = "[";

		for(std::size_t j = 0; j < prices.size(); ++j)
		{
			prices_json.append(prices.at(j)->parse_to_json());

			if(j != prices.size() - 1)
				prices_json.append(", ");
		}

		prices_json.append("]");

		//HTTP arguments
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	bool Endpoints::answerShippingQuery(const std::string &shipping_query_id, const bool &ok, const std::vector<ShippingOption::ptr> &shipping_options,
			const std::string &error_message) const noexcept
	{
		//Go through vector to build up the JSON array.
		std::string shipping_options_json = "[";

		for(std::size_t j = 0; j < shipping_options.size(); ++j)
		{
			shipping_options_json.append(shipping_options.at(j)->parse_to_json());

			if(j != shipping_options.size() - 1)
				shipping_options_json.append(", ");
		}

		shipping_options_json.append("]");

		//HTTP arguments
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
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::answerPreCheckoutQuery(const std::string &pre_checkout_query_id, const bool &ok, const std::string &error_message) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	bool Endpoints::setPassportDataErrors(const int &user_id, const std::vector<PassportElementError::ptr> &errors) const noexcept
	{
		//Go through vector to build up the JSON array.
		std::string errors_json = "[";

		for(std::size_t j = 0; j < errors.size(); ++j)
		{
			errors_json.append(errors.at(j)->parse_to_json());

			if(j != errors.size() - 1)
				errors_json.append(", ");
		}

		errors_json.append("]");

		//HTTP arguments
		std::vector<tools::HttpArg> http_args;
		http_args.push_back(tools::HttpArg("user_id", user_id));
		http_args.push_back(tools::HttpArg("errors", errors_json));

		tools::HttpClient http_client("https://api.telegram.org/bot" + m_token + "/setPassportDataErrors", http_args);
		std::string json = http_client.send_post_req_multipart().m_body;

		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
			if(doc.HasMember("result"))
				if(doc["result"].IsBool())
					return doc["result"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return false;
	}

	Message::ptr Endpoints::sendGame(const long long &chat_id, const std::string &game_short_name, const bool &disable_notification, const int &reply_to_message_id,
			const InlineKeyboardMarkup::ptr &reply_markup) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	Message::ptr Endpoints::setGameScore(const int &user_id, const int &score, const bool &force, const bool &disable_edit_message, const long long &chat_id,
			const int &message_id, const std::string &inline_message_id) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsObject())
					msg = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["result"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return msg;
	}

	std::vector<GameHighScore::ptr> Endpoints::getGameHighScores(const int &user_id, const long long &chat_id, const int &message_id ,
			const std::string &inline_message_id) const noexcept
	{
		//HTTP arguments
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
				if(doc["result"].IsArray())
				{
					const rapidjson::Value &array = doc["result"].GetArray();

					for(std::size_t j = 0; j < array.Size(); ++j)
					{
						if(array[j].IsObject())
							game_high_score.push_back(std::make_shared<GameHighScore>(tools::Tools::get_json_as_string(array[j])));
						else
						{
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("result"));
							continue;
						}
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("result"));
			else
				tools::Tools::write_err_log_tmp(Messages::field_non_existent("result"));
		else
			tools::Tools::write_err_log_tmp(Messages::server_resp_not_json_object);

		return game_high_score;
	}
}
