#include "tgbot/Bot.h"
#include "tgbot/types/Message.h"
#include <memory>

int main()
{
	tgbot::Bot::ptr bot = std::make_shared<tgbot::Bot>("put your key in here");

	//########make inline keyboard##########################
	std::vector<tgbot::InlineKeyboardButton::ptr> row0;
	std::vector<tgbot::InlineKeyboardButton::ptr> row1;

	tgbot::InlineKeyboardButton::ptr button0 = std::make_shared<tgbot::InlineKeyboardButton>();
	button0->text = "Click me!";
	button0->url = "https://digital-growth-company.com";

	tgbot::InlineKeyboardButton::ptr button1 = std::make_shared<tgbot::InlineKeyboardButton>();
	button1->text = "Click me even harder!";
	button1->url = "https://hija-look.com";

	tgbot::InlineKeyboardButton::ptr button2 = std::make_shared<tgbot::InlineKeyboardButton>();
	button2->text = "I know what you want ;)";
	button2->url = "https://unsplash.com/collections/668920/pussy";


	row0.push_back(button0);
	row0.push_back(button1);
	row1.push_back(button2);

	std::vector<std::vector<tgbot::InlineKeyboardButton::ptr>> keyboard;
	keyboard.push_back(row0);
	keyboard.push_back(row1);

	tgbot::InlineKeyboardMarkup::ptr keyboard_ptr = std::make_shared<tgbot::InlineKeyboardMarkup>(keyboard);
	//######################################################

	tgbot::Message::ptr msg = bot->get_endpnts()->sendMessage(proper-chat-id,"<b>What's up!</b>", keyboard_ptr);

	return EXIT_SUCCESS;
}

