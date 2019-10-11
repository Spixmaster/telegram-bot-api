#include <iostream>
#include "tgbot/types/Update.h"
#include "tgbot/types/User.h"
#include "Bot.h"
#include "tgbot/types/Message.h"
#include "tgbot/types/ReplyKeyboardRemove.h"
#include <fstream>

int main()
{
	Bot bot("your-bot-token");

	std::vector<std::string> answer_options;
	answer_options.push_back("Yes, I like it here.");
	answer_options.push_back("No, is it terrible here.");
	answer_options.push_back("Of course I don't.");
	answer_options.push_back("I'll have you know that there's no PUSSIEE.");

	bot.get_endpnts()->sendPoll(chat-id-in-here, "Do you get to the Cloud District very often?", answer_options);

	return EXIT_SUCCESS;
}
