#include "tgbot/types/PassportData.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			//Assignments
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
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("data"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("data"));
			}

			if(doc.HasMember("credentials"))
			{
				if(doc["credentials"].IsObject())
					credentials = std::make_shared<EncryptedCredentials>(tools::Tools::get_json_as_string(doc["credentials"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("credentials"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string PassportData::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field data
		std::string data_cont = "[";

		for(std::size_t j = 0; j < data.size(); ++j)
		{
			data_cont.append(data.at(j)->parse_to_json());

			if(j != data.size() -1)
				data_cont.append(", ");
		}

		data_cont.append("]");

		json.append("\"data\": " + data_cont);
		json.append(", ");

		//Field credentials
		json.append("\"credentials\": " + credentials->parse_to_json());

		json.append("}");
		return json;
	}
}
