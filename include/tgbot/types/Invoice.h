#ifndef TYPES_INVOICE_H
#define TYPES_INVOICE_H

#include <string>
#include <memory>

namespace tgbot
{
	struct Invoice
	{
		//pointer of itself
		typedef std::shared_ptr<Invoice> ptr;

		//member variables
		std::string title;
		std::string description;
		std::string start_parameter;
		std::string currency;
		int total_amount = -1;

		//constructors
		Invoice();

		//@param json: json object of Invoice
		Invoice(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
