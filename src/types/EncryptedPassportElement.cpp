#include "tgbot/types/EncryptedPassportElement.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	EncryptedPassportElement::EncryptedPassportElement() : type(), data(), phone_number(), email(), files(), front_side(), reverse_side(), selfie(), translation(), hash()
	{}

	EncryptedPassportElement::EncryptedPassportElement(const std::string &json)
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

			if(doc.HasMember("data"))
				if(doc["data"].IsString())
					data = doc["data"].GetString();
				else
					std::cerr << "Error: Field \"data\" does not contain a string." << std::endl;

			if(doc.HasMember("phone_number"))
				if(doc["phone_number"].IsString())
					phone_number = doc["phone_number"].GetString();
				else
					std::cerr << "Error: Field \"phone_number\" does not contain a string." << std::endl;

			if(doc.HasMember("files"))
				if(doc["files"].IsArray())
				{
					files.resize(doc["files"].GetArray().Size());

					for(std::size_t j = 0; j < doc["files"].GetArray().Size(); ++j)
					{
						if(doc["files"][j].IsObject())
							files.at(j) = std::make_shared<PassportFile>(tools::Tools::get_json_as_string(doc["files"][j]));
						else
							std::cerr << "Error: Field \"files\"'s json array's element is not a json object." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"files\" does not contain a json array." << std::endl;

			if(doc.HasMember("front_side"))
				if(doc["front_side"].IsObject())
					front_side = std::make_shared<PassportFile>(tools::Tools::get_json_as_string(doc["front_side"]));
				else
					std::cerr << "Error: Field \"front_side\" does not contain a json object." << std::endl;

			if(doc.HasMember("reverse_side"))
				if(doc["reverse_side"].IsObject())
					reverse_side = std::make_shared<PassportFile>(tools::Tools::get_json_as_string(doc["reverse_side"]));
				else
					std::cerr << "Error: Field \"reverse_side\" does not contain a json object." << std::endl;

			if(doc.HasMember("selfie"))
				if(doc["selfie"].IsObject())
					selfie = std::make_shared<PassportFile>(tools::Tools::get_json_as_string(doc["selfie"]));
				else
					std::cerr << "Error: Field \"selfie\" does not contain a json object." << std::endl;

			if(doc.HasMember("translation"))
				if(doc["translation"].IsArray())
				{
					translation.resize(doc["translation"].GetArray().Size());

					for(std::size_t j = 0; j < doc["translation"].GetArray().Size(); ++j)
					{
						if(doc["translation"][j].IsObject())
							translation.at(j) = std::make_shared<PassportFile>(tools::Tools::get_json_as_string(doc["translation"][j]));
						else
							std::cerr << "Error: Field \"translation\"'s json array's element is not a json object." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"translation\" does not contain a json array." << std::endl;

			if(doc.HasMember("hash"))
				if(doc["hash"].IsString())
					hash = doc["hash"].GetString();
				else
					std::cerr << "Error: Field \"hash\" does not contain a string." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * files and not files_cont in condition as in that case we would destroy the json array
		 */
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

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * translation and not translation_cont in condition as in that case we would destroy the json array
		 */
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
