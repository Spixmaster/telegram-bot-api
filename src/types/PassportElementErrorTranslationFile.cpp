#include "tgbot/types/PassportElementErrorTranslationFile.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	PassportElementErrorTranslationFile::PassportElementErrorTranslationFile() : source(), type(), file_hash(), message()
	{}

	PassportElementErrorTranslationFile::PassportElementErrorTranslationFile(const std::string &json)
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

			if(doc.HasMember("file_hash"))
			{
				if(doc["file_hash"].IsString())
					file_hash = doc["file_hash"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("file_hash"));
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

	std::string PassportElementErrorTranslationFile::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field source
		json.append("\"source\": \"" + source + "\"");
		json.append(", ");

		//Field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//Field file_hash
		json.append("\"file_hash\": \"" + file_hash + "\"");
		json.append(", ");

		//Field message
		json.append("\"message\": \"" + message + "\"");

		json.append("}");
		return json;
	}
}
