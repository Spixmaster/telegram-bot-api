# telegram-bot-api
C++ library for the Telegram bot API.

Current state: Bot API 4.4 (up to date)

See the [Telegram documentation](https://core.telegram.org/bots/api).

## Usage
### Dependencies
You need to use a C++17 compiler.

The following packages need to be installed:
```sh
sudo apt install libpoco-dev
```
Moreover, [rapdijson](https://github.com/Tencent/rapidjson) needs to be installed.

For this, do the following steps:
1. git clone https://github.com/Tencent/rapidjson
2. cd rapidjson
3. cmake .
4. make -j4
5. sudo make install

#### Libraries that need to be linked (option -l)
* PocoFoundation
* PocoNetSSL
* PocoNet

### Example
```cpp
#include "tgbot/Bot.h"
#include <memory>

int main()
{
	tgbot::Bot::ptr bot = std::make_shared<tgbot::Bot>("your-bot-token");

	/*
	 * command /test
	 * just for testing purposes
	 */
	bot->get_event_handler()->on_cmd("test", [&bot](const tgbot::Message::ptr &msg)
	{
		bot->get_endpnts()->sendMessage(msg->chat->id, "Hey, <b>there</b>.", "HTML", false, 0);
	});

	//test listener
	bot->get_event_handler()->on_non_cmd_msg([&bot](const tgbot::Message::ptr &msg)
	{
		bot->get_endpnts()->sendMessage(msg->chat->id, "I hear you.");
	});

	while(true)
	{
		bot->get_event_handler()->long_poll();
	}

	return EXIT_SUCCESS;
}
```
