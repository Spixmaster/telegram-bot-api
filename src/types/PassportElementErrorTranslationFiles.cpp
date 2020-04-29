#include "tgbot/types/PassportElementErrorTranslationFiles.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	PassportElementErrorTranslationFiles::PassportElementErrorTranslationFiles() : source(), type(), file_hashes(), message()
	{}

	PassportElementErrorTranslationFiles::PassportElementErrorTranslationFiles(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("source"))
			{
				if(doc["source"].IsString())
					source = doc["source"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("source"));
			}

			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("type"));
			}

			if(doc.HasMember("file_hashes"))
			{
				if(doc["file_hashes"].IsArray())
				{
					file_hashes.resize(doc["file_hashes"].GetArray().Size());

					for(std::size_t j = 0; j < doc["file_hashes"].GetArray().Size(); ++j)
					{
						if(doc["file_hashes"][j].IsString())
							file_hashes.at(j) = doc["file_hashes"][j].GetString();
						else
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_string("file_hashes"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("file_hashes"));
			}

			if(doc.HasMember("message"))
			{
				if(doc["message"].IsString())
					message = doc["message"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("message"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string PassportElementErrorTranslationFiles::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field source
		json.append("\"source\": \"" + source + "\"");
		json.append(", ");

		//Field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//Field file_hashes
		std::string file_hashes_cont = "[";
		for(std::size_t j = 0; j < file_hashes.size(); ++j)
		{
			file_hashes_cont.append(file_hashes.at(j));
			file_hashes_cont.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * file_hashes and not file_hashes_cont in condition as in that case we would destroy the json array
		 */
		if(file_hashes.size() > 0)
		{
			//finish json array
			file_hashes_cont.pop_back();
			file_hashes_cont.pop_back();
		}
		file_hashes_cont.append("]");

		json.append("\"file_hashes\": " + file_hashes_cont);
		json.append(", ");

		//Field message
		json.append("\"message\": \"" + message + "\"");

		json.append("}");
		return json;
	}
}

