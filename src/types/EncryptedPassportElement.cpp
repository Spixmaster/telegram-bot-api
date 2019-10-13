#include "tgbot/types/EncryptedPassportElement.h"

namespace tgbot
{
	EncryptedPassportElement::EncryptedPassportElement() : type(), data(), phone_number(), email(), files(), front_side(), reverse_side(), selfie(), translation(), hash()
	{}

	EncryptedPassportElement::EncryptedPassportElement(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("type"))
			type = doc["type"].GetString();

		if(doc.HasMember("data"))
			data = doc["data"].GetString();

		if(doc.HasMember("phone_number"))
			phone_number = doc["phone_number"].GetString();

		if(doc.HasMember("files"))
			for(std::size_t j = 0; j < doc["files"].GetArray().Size(); ++j)
			{
				files.resize(doc["files"].GetArray().Size());

				files.at(j) = std::make_shared<PassportFile>(SpecialTools::get_json_obj_as_string(doc["files"][j]));
			}

		if(doc.HasMember("front_side"))
			front_side = std::make_shared<PassportFile>(SpecialTools::get_json_obj_as_string(doc["front_side"]));

		if(doc.HasMember("reverse_side"))
			reverse_side = std::make_shared<PassportFile>(SpecialTools::get_json_obj_as_string(doc["reverse_side"]));

		if(doc.HasMember("selfie"))
			selfie = std::make_shared<PassportFile>(SpecialTools::get_json_obj_as_string(doc["selfie"]));

		if(doc.HasMember("translation"))
			for(std::size_t j = 0; j < doc["translation"].GetArray().Size(); ++j)
			{
				files.resize(doc["files"].GetArray().Size());

				files.at(j) = std::make_shared<PassportFile>(SpecialTools::get_json_obj_as_string(doc["translation"][j]));
			}

		if(doc.HasMember("hash"))
			hash = doc["hash"].GetString();
	}

	std::string EncryptedPassportElement::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field data
		json.append("\"data\": \"" + data + "\"");
		json.append(", ");

		//field phone_number
		json.append("\"phone_number\": \"" + phone_number + "\"");
		json.append(", ");

		//field email
		json.append("\"email\": \"" + email + "\"");
		json.append(", ");

		//field files
		std::string files_cont = "[";
		for(std::size_t j = 0; j < files.size(); ++j)
		{
			files_cont.append(files.at(j)->parse_to_json());
			files_cont.append(", ");
		}

		//if size() == 0 pop_back() would crash the programme
		if(files.size() > 0)
		{
			//finish json array
			files_cont.pop_back();
			files_cont.pop_back();
		}
		files_cont.append("]");

		json.append("\"files\": " + files_cont);
		json.append(", ");

		//field front_side
		json.append("\"front_side\": " + front_side->parse_to_json());
		json.append(", ");

		//field reverse_side
		json.append("\"reverse_side\": " + reverse_side->parse_to_json());
		json.append(", ");

		//field selfie
		json.append("\"selfie\": \"" + selfie->parse_to_json() + "\"");
		json.append(", ");

		//field translation
		std::string translation_cont = "[";
		for(std::size_t j = 0; j < translation.size(); ++j)
		{
			translation_cont.append(translation.at(j)->parse_to_json());
			translation_cont.append(", ");
		}

		//if size() == 0 pop_back() would crash the programme
		if(translation.size() > 0)
		{
			//finish json array
			translation_cont.pop_back();
			translation_cont.pop_back();
		}
		translation_cont.append("]");

		json.append("\"translation\": " + translation_cont);
		json.append(", ");

		//field hash
		json.append("\"hash\": \"" + hash + "\"");

		json.append("}");

		return json;
	}
}
