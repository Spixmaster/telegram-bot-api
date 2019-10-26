#include "tgbot/types/StickerSet.h"

namespace tgbot
{
	StickerSet::StickerSet() : name(), title(), is_animated(), contains_masks(), sticker()
	{}

	StickerSet::StickerSet(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("name"))
			name = doc["name"].GetString();

		if(doc.HasMember("title"))
			title = doc["title"].GetString();

		if(doc.HasMember("is_animated"))
			is_animated = doc["is_animated"].GetBool();

		if(doc.HasMember("contains_masks"))
			contains_masks = doc["contains_masks"].GetBool();

		if(doc.HasMember("sticker"))
			for(std::size_t j = 0; j < doc["sticker"].GetArray().Size(); ++j)
			{
				sticker.resize(doc["sticker"].GetArray().Size());

				sticker.at(j) = std::make_shared<Sticker>(SpecialTools::get_json_obj_as_string(doc["sticker"][j]));
			}
	}

	std::string StickerSet::parse_to_json() const
	{
		std::string json = "{";

		//field name
		json.append("\"name\": \"" + name + "\"");
		json.append(", ");

		//field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//field is_animated
		std::string is_animated_bool = is_animated ? "true" : "false";
		json.append("\"is_animated\": " + is_animated_bool);
		json.append(", ");

		//field contains_masks
		std::string contains_masks_bool = contains_masks ? "true" : "false";
		json.append("\"contains_masks\": " + contains_masks_bool);
		json.append(", ");

		//field sticker
		std::string sticker_cont = "[";
		for(std::size_t j = 0; j < sticker.size(); ++j)
		{
			sticker_cont.append(sticker.at(j)->parse_to_json());
			sticker_cont.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * sticker and not sticker_cont in condition as in that case we would destroy the json array
		 */
		if(sticker.size() > 0)
		{
			//finish json array
			sticker_cont.pop_back();
			sticker_cont.pop_back();
		}
		sticker_cont.append("]");

		json.append("\"sticker\": \"" + sticker_cont + "\"");

		json.append("}");

		return json;
	}
}
