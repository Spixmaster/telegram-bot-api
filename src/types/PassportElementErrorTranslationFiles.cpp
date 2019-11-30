#include "tgbot/types/PassportElementErrorTranslationFiles.h"
#include "tools/Tools.h"

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
			//assignments
			if(doc.HasMember("source"))
				source = doc["source"].GetString();

			if(doc.HasMember("type"))
				type = doc["type"].GetString();

			if(doc.HasMember("file_hashes"))
				for(std::size_t j = 0; j < doc["file_hashes"].GetArray().Size(); ++j)
				{
					file_hashes.resize(doc["file_hashes"].GetArray().Size());

					file_hashes.at(j) = doc["file_hashes"][j].GetString();
				}

			if(doc.HasMember("message"))
				message = doc["message"].GetString();
		}
	}

	std::string PassportElementErrorTranslationFiles::parse_to_json() const
	{
		std::string json = "{";

		//field source
		json.append("\"source\": \"" + source + "\"");
		json.append(", ");

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field file_hashes
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

		//field message
		json.append("\"message\": \"" + message + "\"");

		json.append("}");

		return json;
	}
}

