#include <rapidjson/document.h>
#include "tgbot/types/ReplyKeyboardMarkup.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	ReplyKeyboardMarkup::ReplyKeyboardMarkup() : keyboard(), resize_keyboard(), one_time_keyboard(), selective()
	{}

	ReplyKeyboardMarkup::ReplyKeyboardMarkup(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("keyboard"))
			{
				if(doc["keyboard"].IsArray())
				{
					const rapidjson::Value &keyboard_array = doc["keyboard"].GetArray();

					//reserve enough rows
					keyboard.resize(keyboard_array.Size());

					for(std::size_t row = 0; row < doc["keyboard"].GetArray().Size(); ++row)
					{
						if(keyboard_array[row].IsArray())
						{
							//reserve enough columns for each row
							keyboard.at(row).resize(keyboard_array[row].GetArray().Size());

							for(std::size_t column = 0; column < keyboard_array[row].GetArray().Size(); ++column)
							{
								if(keyboard_array[row][column].IsObject())
									keyboard.at(row).at(column) = std::make_shared<KeyboardButton>(tools::Tools::get_json_as_string(keyboard_array[row][column]));
								else
									tools::Tools::write_err_log(Messages::field_element_element_does_not_contain_json_obj("keyboard"));
							}
						}
						else
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_arr("keyboard"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("keyboard"));
			}

			if(doc.HasMember("resize_keyboard"))
			{
				if(doc["resize_keyboard"].IsBool())
					resize_keyboard = doc["resize_keyboard"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("resize_keyboard"));
			}

			if(doc.HasMember("one_time_keyboard"))
			{
				if(doc["one_time_keyboard"].IsBool())
					one_time_keyboard = doc["one_time_keyboard"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("one_time_keyboard"));
			}

			if(doc.HasMember("selective"))
			{
				if(doc["selective"].IsBool())
					selective = doc["selective"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("selective"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	ReplyKeyboardMarkup::ReplyKeyboardMarkup(const std::vector<std::vector<KeyboardButton::ptr>> &keyboard) : keyboard(keyboard), resize_keyboard(), one_time_keyboard(),
			selective()
	{}

	std::string ReplyKeyboardMarkup::parse_to_json() const noexcept
	{
		std::string json = "{\"keyboard\": [";

		//rows
		for(std::size_t j = 0; j < keyboard.size(); ++j)
		{
			json.append("[");

			//columns in row
			for(std::size_t k = 0; k < keyboard.at(j).size(); ++k)
			{
				//button text is stated
				json.append("{");
				json.append("\"text\": \"" + keyboard.at(j).at(k)->text + "\"");
				json.append(", ");

				//options are stated
					//request_contact
				std::string request_contact_bool = keyboard.at(j).at(k)->request_contact ? "true" : "false";
				json.append("\"request_contact\": " + request_contact_bool);
				json.append(", ");

					//request_location
				std::string request_location_bool = keyboard.at(j).at(k)->request_location ? "true" : "false";
				json.append("\"request_location\": " + request_location_bool);

				json.append("}");

				//add comma between several json objects in a single row
				//the condition equals last iteration
				if(k != (keyboard.at(j).size() - 1))
					json.append(", ");
			}
			json.append("], ");
		}

		//remove ", "
		if(json.size() > 0)
		{
			json.pop_back();
			json.pop_back();
		}

		json.append("], ");

		//Field resize_keyboard
		std::string resize_keyboard_bool = resize_keyboard ? "true" : "false";
		json.append("\"resize_keyboard\": " + resize_keyboard_bool);
		json.append(", ");

		//Field one_time_keyboard
		std::string one_time_keyboard_bool = one_time_keyboard ? "true" : "false";
		json.append("\"one_time_keyboard\": " + one_time_keyboard_bool);
		json.append(", ");

		//Field selective
		std::string selective_bool = selective ? "true" : "false";
		json.append("\"selective\": " + selective_bool);

		json.append("}");

		return json;
	}
}
