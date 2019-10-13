#ifndef TGBOT_SPECIALTOOLS_H
#define TGBOT_SPECIALTOOLS_H

#include <string>
#include <rapidjson/document.h>
#include <memory>

/*
 * @brief the class contains functions which are only in user for this project
 * @brief it is a monostate class
 */

namespace tgbot
{
	class SpecialTools
	{
	public:
		//pointer of itself
		typedef std::shared_ptr<SpecialTools> ptr;

		//member functions

		/*
		 * @brief expects a rapidjson::Value and turns it back into a string
		 * @param the Value which shall be converted
		 * @return the string of the json object
		 */
		static std::string get_json_obj_as_string(const rapidjson::Value &val);
	};
}

#endif
