#include "tgbot/types/ShippingOption.h"
#include "tgbot/Tools.h"

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
				id = doc["id"].GetString();

			if(doc.HasMember("title"))
				title = doc["title"].GetString();

			if(doc.HasMember("prices"))
				for(std::size_t j = 0; j < doc["prices"].GetArray().Size(); ++j)
				{
					prices.resize(doc["prices"].GetArray().Size());

					prices.at(j) = std::make_shared<LabeledPrice>(SpecialTools::get_json_as_string(doc["prices"][j]));
				}
		}
	}

	std::string ShippingOption::parse_to_json() const
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
