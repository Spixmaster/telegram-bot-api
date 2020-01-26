#include "tgbot/types/InlineQueryResultArticle.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	InlineQueryResultArticle::InlineQueryResultArticle() : type(), id(), title(), input_message_content(), reply_markup(), url(), hide_url(), description(),
	thumb_url(), thumb_width(), thumb_height()
	{}

	InlineQueryResultArticle::InlineQueryResultArticle(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("type"))
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << "Error: Field \"type\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"type\"." << std::endl;

			if(doc.HasMember("id"))
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					std::cerr << "Error: Field \"id\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"id\"." << std::endl;

			if(doc.HasMember("title"))
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					std::cerr << "Error: Field \"title\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"title\"." << std::endl;

			if(doc.HasMember("reply_markup"))
				if(doc["reply_markup"].IsObject())
					reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
				else
					std::cerr << "Error: Field \"reply_markup\" does not contain a json object." << std::endl;
			else
				std::cerr << "Error: There is no field \"reply_markup\"." << std::endl;

			if(doc.HasMember("url"))
				if(doc["url"].IsString())
					url = doc["url"].GetString();
				else
					std::cerr << "Error: Field \"url\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"url\"." << std::endl;

			if(doc.HasMember("hide_url"))
				if(doc["hide_url"].IsBool())
					hide_url = doc["hide_url"].GetBool();
				else
					std::cerr << "Error: Field \"hide_url\" does not contain a bool." << std::endl;
			else
				std::cerr << "Error: There is no field \"hide_url\"." << std::endl;

			if(doc.HasMember("description"))
				if(doc["description"].IsString())
					description = doc["description"].GetString();
				else
					std::cerr << "Error: Field \"description\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"description\"." << std::endl;

			if(doc.HasMember("thumb_url"))
				if(doc["thumb_url"].IsString())
					thumb_url = doc["thumb_url"].GetString();
				else
					std::cerr << "Error: Field \"thumb_url\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"thumb_url\"." << std::endl;

			if(doc.HasMember("thumb_width"))
				if(doc["thumb_width"].IsInt())
					thumb_width = doc["thumb_width"].GetInt();
				else
					std::cerr << "Error: Field \"thumb_width\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"thumb_width\"." << std::endl;

			if(doc.HasMember("thumb_height"))
				if(doc["thumb_height"].IsInt())
					thumb_height = doc["thumb_height"].GetInt();
				else
					std::cerr << "Error: Field \"thumb_height\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"thumb_height\"." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string InlineQueryResultArticle::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//field input_message_content
		json.append("\"input_message_content\": " + input_message_content->parse_to_json());
		json.append(", ");

		//field reply_markup
		json.append("\"reply_markup\": " + reply_markup->parse_to_json());
		json.append(", ");

		//field url
		json.append("\"url\": \"" + url + "\"");
		json.append(", ");

		// field hide_url
		std::string hide_url_bool = hide_url ? "true" : "false";
		json.append("\"hide_url\": " + hide_url_bool);
		json.append(", ");

		//field description
		json.append("\"description\": \"" + description + "\"");
		json.append(", ");

		//field thumb_url
		json.append("\"thumb_url\": \"" + thumb_url + "\"");
		json.append(", ");

		//field thumb_width
		json.append("\"thumb_width\": " + thumb_width);
		json.append(", ");

		//field thumb_height
		json.append("\"thumb_height\": " + thumb_height);

		json.append("}");

		return json;
	}
}
