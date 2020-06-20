#include "tgbot/types/ShippingOption.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	ShippingOption::ShippingOption() : id(), title(), prices()
	{}

	ShippingOption::ShippingOption(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("id"))
			{
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("id"));
			}

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("title"));
			}

			if(doc.HasMember("prices"))
			{
				if(doc["prices"].IsArray())
				{
					for(std::size_t j = 0; j < doc["prices"].GetArray().Size(); ++j)
					{
						if(doc["prices"][j].IsObject())
							prices.push_back(std::make_shared<LabeledPrice>(tools::Tools::get_json_as_string(doc["prices"][j])));
						else
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("prices"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("prices"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string ShippingOption::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//Field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//Field prices
		std::string prices_cont = "[";

		for(std::size_t j = 0; j < prices.size(); ++j)
		{
			prices_cont.append(prices.at(j)->parse_to_json());

			if(j != prices.size() - 1)
				prices_cont.append(", ");
		}

		prices_cont.append("]");

		json.append("\"prices\": " + prices_cont);

		json.append("}");
		return json;
	}
}
