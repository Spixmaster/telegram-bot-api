#include <rapidjson/document.h>
#include "tgbot/types/ReplyKeyboardMarkup.h"
#include "tools/Tools.h"
#include <iostream>

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
			//assignments
			if(doc.HasMember("keyboard"))
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
									std::cerr << "Error: Field \"keyboard\"'s json array's array element is not a json object." << std::endl;
							}
						}
						else
							std::cerr << "Error: Field \"keyboard\"'s json array does not contain a json array." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"keyboard\" does not contain a json array." << std::endl;
			else
				std::cerr << "Error: There is no field \"keyboard\"." << std::endl;

			if(doc.HasMember("resize_keyboard"))
				if(doc["resize_keyboard"].IsBool())
					resize_keyboard = doc["resize_keyboard"].GetBool();
				else
					std::cerr << "Error: Field \"resize_keyboard\" does not contain a bool." << std::endl;
			else
				std::cerr << "Error: There is no field \"resize_keyboard\"." << std::endl;

			if(doc.HasMember("one_time_keyboard"))
				if(doc["one_time_keyboard"].IsBool())
					one_time_keyboard = doc["one_time_keyboard"].GetBool();
				else
					std::cerr << "Error: Field \"one_time_keyboard\" does not contain a bool." << std::endl;
			else
				std::cerr << "Error: There is no field \"one_time_keyboard\"." << std::endl;

			if(doc.HasMember("selective"))
				if(doc["selective"].IsBool())
					selective = doc["selective"].GetBool();
				else
					std::cerr << "Error: Field \"selective\" does not contain a bool." << std::endl;
			else
				std::cerr << "Error: There is no field \"selective\"." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	ReplyKeyboardMarkup::ReplyKeyboardMarkup(const std::vector<std::vector<KeyboardButton::ptr>> &keyboard) : keyboard(keyboard), resize_keyboard(), one_time_keyboard(),
			selective()
	{}

	std::string ReplyKeyboardMarkup::parse_to_json() const
	{
		std::string json = "{\"keyboard\": [";

		//rows
		for(size_t j = 0; j < keyboard.size(); ++j)
		{
			json.append("[");

			//columns in row
			for(size_t k = 0; k < keyboard.at(j).size(); ++k)
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

		//field resize_keyboard
		std::string resize_keyboard_bool = resize_keyboard ? "true" : "false";
		json.append("\"resize_keyboard\": " + resize_keyboard_bool);
		json.append(", ");

		//field one_time_keyboard
		std::string one_time_keyboard_bool = one_time_keyboard ? "true" : "false";
		json.append("\"one_time_keyboard\": " + one_time_keyboard_bool);
		json.append(", ");

		//field selective
		std::string selective_bool = selective ? "true" : "false";
		json.append("\"selective\": " + selective_bool);

		json.append("}");

		return json;
	}
}
