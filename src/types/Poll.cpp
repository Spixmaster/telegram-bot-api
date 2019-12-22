#include "tgbot/types/Poll.h"
#include "tools/Tools.h"

namespace tgbot
{
	Poll::Poll() : id(), question(), options(), is_closed()
	{}

	Poll::Poll(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("id"))
				id = doc["id"].GetString();

			if(doc.HasMember("question"))
				question = doc["question"].GetString();

			if(doc.HasMember("options"))
				for(std::size_t j = 0; j < doc["options"].GetArray().Size(); ++j)
				{
					options.resize(doc["options"].GetArray().Size());

					options.at(j) = std::make_shared<PollOption>(tools::Tools::get_json_as_string(doc["options"][j]));
				}

			if(doc.HasMember("is_closed"))
				is_closed = doc["is_closed"].GetBool();
		}
	}

	std::string Poll::parse_to_json() const
	{
		std::string json = "{";

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field question
		json.append("\"question\": \"" + question + "\"");
		json.append(", ");

		//field options
		std::string options_cont = "[";
		for(std::size_t j = 0; j < options.size(); ++j)
		{
			options_cont.append(options.at(j)->parse_to_json());
			options_cont.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * options and not options_cont in condition as in that case we would destroy the json array
		 */
		if(options.size() > 0)
		{
			//finish json array
			options_cont.pop_back();
			options_cont.pop_back();
		}
		options_cont.append("]");

		json.append("\"options\": " + options_cont);
		json.append(", ");

		//field is_closed
		std::string is_closed_bool = is_closed ? "true" : "false";
		json.append("\"is_closed\": " + is_closed_bool);

		json.append("}");

		return json;
	}
}
