#include "tgbot/Bot.h"
#include <memory>

int main()
{
	tgbot::Bot::ptr bot = std::make_shared<tgbot::Bot>("your-bot-token");

	std::vector<std::string> answer_options;
	answer_options.push_back("Yes, I like it here.");
	answer_options.push_back("No, is it terrible here.");
	answer_options.push_back("Of course I don't.");
	answer_options.push_back("I'll have you know that there's no PUSSIEE.");

	bot->get_endpnts()->sendPoll(chat-id-in-here, "Do you get to the Cloud District very often?", answer_options);

	return EXIT_SUCCESS;
}
