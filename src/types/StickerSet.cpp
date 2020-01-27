#include "tgbot/types/StickerSet.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	StickerSet::StickerSet() : name(), title(), is_animated(), contains_masks(), sticker()
	{}

	StickerSet::StickerSet(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("name"))
			{
				if(doc["name"].IsString())
					name = doc["name"].GetString();
				else
					std::cerr << "Error: Field \"name\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					std::cerr << "Error: Field \"title\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("is_animated"))
			{
				if(doc["is_animated"].IsBool())
					is_animated = doc["is_animated"].GetBool();
				else
					std::cerr << "Error: Field \"is_animated\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("contains_masks"))
			{
				if(doc["contains_masks"].IsBool())
					contains_masks = doc["contains_masks"].GetBool();
				else
					std::cerr << "Error: Field \"contains_masks\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("sticker"))
			{
				if(doc["sticker"].IsArray())
				{
					sticker.resize(doc["sticker"].GetArray().Size());

					for(std::size_t j = 0; j < doc["sticker"].GetArray().Size(); ++j)
					{
						if(doc["sticker"][j].IsObject())
							sticker.at(j) = std::make_shared<Sticker>(tools::Tools::get_json_as_string(doc["sticker"][j]));
						else
							std::cerr << "Error: Field \"sticker\"'s json array's element is not a json object." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"sticker\" does not contain a json array." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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
