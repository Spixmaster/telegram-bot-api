#include "tgbot/types/Poll.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	Poll::Poll() : id(), question(), options(), total_voter_count(), is_closed(), is_anonymous(), type(), allows_multiple_answers(), correct_option_id(), explanation(),
			explanation_entities(), open_period(), close_date()
	{}

	Poll::Poll(const std::string &json)
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

			if(doc.HasMember("question"))
			{
				if(doc["question"].IsString())
					question = doc["question"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("question"));
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
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("options"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("options"));
			}

			if(doc.HasMember("total_voter_count"))
			{
				if(doc["total_voter_count"].IsInt())
					total_voter_count = doc["total_voter_count"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("total_voter_count"));
			}

			if(doc.HasMember("is_closed"))
			{
				if(doc["is_closed"].IsBool())
					is_closed = doc["is_closed"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("is_closed"));
			}

			if(doc.HasMember("is_anonymous"))
			{
				if(doc["is_anonymous"].IsBool())
					is_anonymous = doc["is_anonymous"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("is_anonymous"));
			}

			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("type"));
			}

			if(doc.HasMember("allows_multiple_answers"))
			{
				if(doc["allows_multiple_answers"].IsBool())
					allows_multiple_answers = doc["allows_multiple_answers"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("allows_multiple_answers"));
			}

			if(doc.HasMember("correct_option_id"))
			{
				if(doc["correct_option_id"].IsInt())
					correct_option_id = doc["correct_option_id"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("correct_option_id"));
			}

			if(doc.HasMember("explanation"))
			{
				if(doc["explanation"].IsString())
					type = doc["explanation"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("explanation"));
			}

			if(doc.HasMember("explanation_entities"))
			{
				if(doc["explanation_entities"].IsArray())
				{
					explanation_entities.resize(doc["explanation_entities"].GetArray().Size());

					for(std::size_t j = 0; j < doc["explanation_entities"].GetArray().Size(); ++j)
					{
						if(doc["explanation_entities"][j].IsObject())
							explanation_entities.at(j) = std::make_shared<MessageEntity>(tools::Tools::get_json_as_string(doc["explanation_entities"][j]));
						else
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("explanation_entities"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("explanation_entities"));
			}

			if(doc.HasMember("open_period"))
			{
				if(doc["open_period"].IsInt())
					open_period = doc["open_period"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("open_period"));
			}

			if(doc.HasMember("close_date"))
			{
				if(doc["close_date"].IsInt())
					close_date = doc["close_date"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("close_date"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string Poll::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//Field question
		json.append("\"question\": \"" + question + "\"");
		json.append(", ");

		//Field options
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

		//Field total_voter_count
		json.append("\"total_voter_count\": \"" + std::to_string(total_voter_count) + "\"");
		json.append(", ");

		//Field is_closed
		std::string is_closed_bool = is_closed ? "true" : "false";
		json.append("\"is_closed\": " + is_closed_bool);
		json.append(", ");

		//Field is_anonymous
		std::string is_anonymous_bool = is_anonymous ? "true" : "false";
		json.append("\"is_anonymous\": " + is_anonymous_bool);
		json.append(", ");

		//Field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//Field is_anonymous
		std::string allows_multiple_answers_bool = allows_multiple_answers ? "true" : "false";
		json.append("\"allows_multiple_answers\": " + allows_multiple_answers_bool);
		json.append(", ");

		//Field correct_option_id
		json.append("\"correct_option_id\": \"" + std::to_string(correct_option_id) + "\"");
		json.append(", ");

		//Field explanation
		json.append("\"explanation\": \"" + explanation + "\"");
		json.append(", ");

		//Field explanation_entities
		std::string explanation_entities_cont = "[";
		for(std::size_t j = 0; j < options.size(); ++j)
		{
			explanation_entities_cont.append(explanation_entities.at(j)->parse_to_json());
			explanation_entities_cont.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * explanation_entities and not explanation_entities_cont in condition as in that case we would destroy the json array
		 */
		if(explanation_entities.size() > 0)
		{
			//finish json array
			explanation_entities_cont.pop_back();
			explanation_entities_cont.pop_back();
		}
		explanation_entities_cont.append("]");

		json.append("\"explanation_entities\": " + explanation_entities_cont);
		json.append(", ");

		//Field open_period
		json.append("\"open_period\": \"" + std::to_string(open_period) + "\"");
		json.append(", ");

		//Field close_date
		json.append("\"close_date\": \"" + std::to_string(close_date) + "\"");

		json.append("}");

		return json;
	}
}
