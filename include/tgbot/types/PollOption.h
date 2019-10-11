#ifndef TYPES_POLLOPTION_H
#define TYPES_POLLOPTION_H

#include <string>
#include <memory>

namespace tgbot
{
	struct PollOption
	{
		//pointer of itself
		typedef std::shared_ptr<PollOption> ptr;

		//member variables
		std::string text;
		int voter_count = -1;

		//constructors
		PollOption();

		//@param json: json object of PollOption
		PollOption(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
