#include "tgbot/types/PassportData.h"

namespace tgbot
{
	PassportData::PassportData() : data(), credentials()
	{}

	PassportData::PassportData(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("data"))
			for(std::size_t j = 0; j < doc["data"].GetArray().Size(); ++j)
			{
				data.resize(doc["data"].GetArray().Size());

				data.at(j) = std::make_shared<EncryptedPassportElement>(SpecialTools::get_json_obj_as_string(doc["data"][j]));
			}

		if(doc.HasMember("credentials"))
			credentials = std::make_shared<EncryptedCredentials>(SpecialTools::get_json_obj_as_string(doc["credentials"]));
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
