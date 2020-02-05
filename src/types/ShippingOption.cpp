#include "tgbot/types/ShippingOption.h"
#include "tools/Tools.h"
#include <iostream>

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
			//assignments
			if(doc.HasMember("id"))
			{
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					std::cerr << "Error: Field \"id\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					std::cerr << "Error: Field \"title\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("prices"))
			{
				if(doc["prices"].IsArray())
				{
					prices.resize(doc["prices"].GetArray().Size());

					for(std::size_t j = 0; j < doc["prices"].GetArray().Size(); ++j)
					{
						if(doc["prices"][j].IsObject())
							prices.at(j) = std::make_shared<LabeledPrice>(tools::Tools::get_json_as_string(doc["prices"][j]));
						else
							std::cerr << "Error: Field \"prices\"'s json array's element is not a json object." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"prices\" does not contain a json array." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string ShippingOption::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//field prices
		std::string prices_cont = "[";
		for(std::size_t j = 0; j < prices.size(); ++j)
		{
			prices_cont.append(prices.at(j)->parse_to_json());
			prices_cont.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * prices and not prices_cont in condition as in that case we would destroy the json array
		 */
		if(prices.size() > 0)
		{
			//finish json array
			prices_cont.pop_back();
			prices_cont.pop_back();
		}
		prices_cont.append("]");

		json.append("\"prices\": " + prices_cont);

		json.append("}");

		return json;
	}
}
