#include "tgbot/types/PassportElementErrorTranslationFiles.h"
#include "tools/Tools.h"
#include <iostream>

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
				if(doc["source"].IsString())
					source = doc["source"].GetString();
				else
					std::cerr << "Error: Field \"source\" does not contain a string." << std::endl;

			if(doc.HasMember("type"))
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << "Error: Field \"type\" does not contain a string." << std::endl;

			if(doc.HasMember("file_hashes"))
				if(doc["file_hashes"].IsArray())
				{
					file_hashes.resize(doc["file_hashes"].GetArray().Size());

					for(std::size_t j = 0; j < doc["file_hashes"].GetArray().Size(); ++j)
					{
						if(doc["file_hashes"][j].IsString())
							file_hashes.at(j) = doc["file_hashes"][j].GetString();
						else
							std::cerr << "Error: Field \"file_hashes\"'s json array's element is not a string." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"file_hashes\" does not contain a json array." << std::endl;

			if(doc.HasMember("message"))
				if(doc["message"].IsString())
					message = doc["message"].GetString();
				else
					std::cerr << "Error: Field \"message\" does not contain a string." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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

