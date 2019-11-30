#include "tgbot/types/InlineQueryResultArticle.h"
#include "tools/Tools.h"

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
				type = doc["type"].GetString();

			if(doc.HasMember("id"))
				id = doc["id"].GetString();

			if(doc.HasMember("title"))
				title = doc["title"].GetString();

			if(doc.HasMember("reply_markup"))
				reply_markup = std::make_shared<InlineKeyboardMarkup>(SpecialTools::get_json_as_string(doc["reply_markup"]));

			if(doc.HasMember("url"))
				url = doc["url"].GetString();

			if(doc.HasMember("hide_url"))
				hide_url = doc["hide_url"].GetBool();

			if(doc.HasMember("description"))
				description = doc["description"].GetString();

			if(doc.HasMember("thumb_url"))
				thumb_url = doc["thumb_url"].GetString();

			if(doc.HasMember("thumb_width"))
				thumb_width = doc["thumb_width"].GetInt();

			if(doc.HasMember("thumb_height"))
				thumb_height = doc["thumb_height"].GetBool();
		}
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
