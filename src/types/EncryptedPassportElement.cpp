#include "tgbot/types/EncryptedPassportElement.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			//Assignments
			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("type"));
			}

			if(doc.HasMember("data"))
			{
				if(doc["data"].IsString())
					data = doc["data"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("data"));
			}

			if(doc.HasMember("phone_number"))
			{
				if(doc["phone_number"].IsString())
					phone_number = doc["phone_number"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("phone_number"));
			}

			if(doc.HasMember("email"))
			{
				if(doc["email"].IsString())
					phone_number = doc["email"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("email"));
			}

			if(doc.HasMember("files"))
			{
				if(doc["files"].IsArray())
				{
					files.resize(doc["files"].GetArray().Size());

					for(std::size_t j = 0; j < doc["files"].GetArray().Size(); ++j)
					{
						if(doc["files"][j].IsObject())
							files.at(j) = std::make_shared<PassportFile>(tools::Tools::get_json_as_string(doc["files"][j]));
						else
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("files"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("files"));
			}

			if(doc.HasMember("front_side"))
			{
				if(doc["front_side"].IsObject())
					front_side = std::make_shared<PassportFile>(tools::Tools::get_json_as_string(doc["front_side"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("front_side"));
			}

			if(doc.HasMember("reverse_side"))
			{
				if(doc["reverse_side"].IsObject())
					reverse_side = std::make_shared<PassportFile>(tools::Tools::get_json_as_string(doc["reverse_side"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("reverse_side"));
			}

			if(doc.HasMember("selfie"))
			{
				if(doc["selfie"].IsObject())
					selfie = std::make_shared<PassportFile>(tools::Tools::get_json_as_string(doc["selfie"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("selfie"));
			}

			if(doc.HasMember("translation"))
			{
				if(doc["translation"].IsArray())
				{
					translation.resize(doc["translation"].GetArray().Size());

					for(std::size_t j = 0; j < doc["translation"].GetArray().Size(); ++j)
					{
						if(doc["translation"][j].IsObject())
							translation.at(j) = std::make_shared<PassportFile>(tools::Tools::get_json_as_string(doc["translation"][j]));
						else
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("translation"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("translation"));
			}

			if(doc.HasMember("hash"))
			{
				if(doc["hash"].IsString())
					hash = doc["hash"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("hash"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string EncryptedPassportElement::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//Field data
		json.append("\"data\": \"" + data + "\"");
		json.append(", ");

		//Field phone_number
		json.append("\"phone_number\": \"" + phone_number + "\"");
		json.append(", ");

		//Field email
		json.append("\"email\": \"" + email + "\"");
		json.append(", ");

		//Field files
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

		//Field front_side
		json.append("\"front_side\": " + front_side->parse_to_json());
		json.append(", ");

		//Field reverse_side
		json.append("\"reverse_side\": " + reverse_side->parse_to_json());
		json.append(", ");

		//Field selfie
		json.append("\"selfie\": \"" + selfie->parse_to_json() + "\"");
		json.append(", ");

		//Field translation
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

		//Field hash
		json.append("\"hash\": \"" + hash + "\"");

		json.append("}");

		return json;
	}
}
