#include "tgbot/types/Poll.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	Poll::Poll() : id(), question(), options(), total_voter_count(), is_closed(), is_anonymous(), type(), allows_multiple_answers(), correct_option_id()
	{}

	Poll::Poll(const std::string &json)
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

			if(doc.HasMember("question"))
			{
				if(doc["question"].IsString())
					question = doc["question"].GetString();
				else
					std::cerr << "Error: Field \"question\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("options"))
			{
				if(doc["options"].IsArray())
				{
					options.resize(doc["options"].GetArray().Size());

					for(std::size_t j = 0; j < doc["options"].GetArray().Size(); ++j)
					{
						if(doc["options"][j].IsObject())
							options.at(j) = std::make_shared<PollOption>(tools::Tools::get_json_as_string(doc["options"][j]));
						else
							std::cerr << "Error: Field \"options\"'s json array's element is not a json object." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"options\" does not contain a json array." << std::endl;
			}

			if(doc.HasMember("total_voter_count"))
			{
				if(doc["total_voter_count"].IsInt())
					total_voter_count = doc["total_voter_count"].GetInt();
				else
					std::cerr << "Error: Field \"total_voter_count\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("is_closed"))
			{
				if(doc["is_closed"].IsBool())
					is_closed = doc["is_closed"].GetBool();
				else
					std::cerr << "Error: Field \"is_closed\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("is_anonymous"))
			{
				if(doc["is_anonymous"].IsBool())
					is_anonymous = doc["is_anonymous"].GetBool();
				else
					std::cerr << "Error: Field \"is_anonymous\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << "Error: Field \"type\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("allows_multiple_answers"))
			{
				if(doc["allows_multiple_answers"].IsBool())
					allows_multiple_answers = doc["allows_multiple_answers"].GetBool();
				else
					std::cerr << "Error: Field \"allows_multiple_answers\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("correct_option_id"))
			{
				if(doc["correct_option_id"].IsInt())
					correct_option_id = doc["correct_option_id"].GetInt();
				else
					std::cerr << "Error: Field \"correct_option_id\" does not contain an int." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string Poll::parse_to_json() const noexcept
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

		//field total_voter_count
		json.append("\"total_voter_count\": \"" + std::to_string(total_voter_count) + "\"");
		json.append(", ");

		//field is_closed
		std::string is_closed_bool = is_closed ? "true" : "false";
		json.append("\"is_closed\": " + is_closed_bool);
		json.append(", ");

		//field is_anonymous
		std::string is_anonymous_bool = is_anonymous ? "true" : "false";
		json.append("\"is_anonymous\": " + is_anonymous_bool);
		json.append(", ");

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field is_anonymous
		std::string allows_multiple_answers_bool = allows_multiple_answers ? "true" : "false";
		json.append("\"allows_multiple_answers\": " + allows_multiple_answers_bool);
		json.append(", ");

		//field correct_option_id
		json.append("\"correct_option_id\": \"" + std::to_string(correct_option_id) + "\"");

		json.append("}");

		return json;
	}
}
