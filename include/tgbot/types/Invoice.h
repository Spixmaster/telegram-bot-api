#ifndef TGBOT_TYPES_INVOICE_H
#define TGBOT_TYPES_INVOICE_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Invoice
	 */
	struct Invoice
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Invoice> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string title;
		/**
		 * @var
		 */
		std::string description;
		/**
		 * @var
		 */
		std::string start_parameter;
		/**
		 * @var
		 */
		std::string currency;
		/**
		 * @var
		 */
		int total_amount = -1;

		//Constructors
		Invoice();

		//@param json: json object of Invoice
		Invoice(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
