#include "tgbot/types/PassportData.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	PassportData::PassportData() : data(), credentials()
	{}

	PassportData::PassportData(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("data"))
			{
				if(doc["data"].IsArray())
				{
					data.resize(doc["data"].GetArray().Size());

					for(std::size_t j = 0; j < doc["data"].GetArray().Size(); ++j)
					{
						if(doc["data"][j].IsObject())
							data.at(j) = std::make_shared<EncryptedPassportElement>(tools::Tools::get_json_as_string(doc["data"][j]));
						else
							std::cerr << "Error: Field \"data\"'s json array's element is not a json object." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"data\" does not contain a json array." << std::endl;
			}

			if(doc.HasMember("credentials"))
			{
				if(doc["credentials"].IsObject())
					credentials = std::make_shared<EncryptedCredentials>(tools::Tools::get_json_as_string(doc["credentials"]));
				else
					std::cerr << "Error: Field \"credentials\" does not contain a json object." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string PassportData::parse_to_json() const
	{
		std::string json = "{";

		//field data
		std::string data_cont = "[";
		for(std::size_t j = 0; j < data.size(); ++j)
		{
			data_cont.append(data.at(j)->parse_to_json());
			data_cont.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * data and not data_cont in condition as in that case we would destroy the json array
		 */
		if(data.size() > 0)
		{
			//finish json array
			data_cont.pop_back();
			data_cont.pop_back();
		}
		data_cont.append("]");

		json.append("\"data\": \"" + data_cont + "\"");
		json.append(", ");

		//field credentials
		json.append("\"credentials\": " + credentials->parse_to_json());

		json.append("}");

		return json;
	}
}
