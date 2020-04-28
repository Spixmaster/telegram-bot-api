# telegram-bot-api
A C++ library for the Telegram bot API.

Current state: Bot API 4.6

See the [Telegram documentation](https://core.telegram.org/bots/api).

## Usage
You can only use this project in your own ones. Thus, no main is included.

### As a submodule
```sh
cd to/your/project
git submodule add *link to this repo*
```

### As a contributor
#### eclipse
* clone the project to anywhere
* create a new eclipse project
* right click on the project > Import > General > File System
* select all content from the cloned project

### Compiler
You need to use a C++17 compiler.

### Dependencies
The following packages need to be installed:

#### Poco
```sh
sudo apt install libpoco-dev
```

#### rapidjson
Moreover, [rapdijson](https://github.com/Tencent/rapidjson) needs to be installed.

For this, do the following steps:
```sh
git clone https://github.com/Tencent/rapidjson
cd rapidjson
cmake .
make -j4
sudo make install
```

#### boost
```sh
sudo apt install libboost-all-dev
```

#### Submodules
```sh
git submodule init
git submodule update
```

#### Libraries that need to be linked (option -l)
* PocoFoundation
* PocoNetSSL
* PocoNet
* PocoCrypto
* boost_iostreams

### Example
Also, look in the examples folder.

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

## Known Errors
The function editMessageMedia() does not work properly although it should as the principle is the same as with other functions. The issue may be from Telegram's side.

## FAQ
* Q: Can I run a bot with this API which runs 24/7?
* A: Yes, you can. I can assure you that as I do it myself. There is not a single memory leak so you RAM will not bloat. Additionally, the http requests are completely safe.
If you send wrong requests to the Telegram servers like trying to delete messages with a bot which does not have admin rights the proper error messages will be output to stderr.
***
* Q: What happens at night when the internal ip changes or my Internet connection is interrupted due to a blackout or similar?
* A: The Http client is completely safe. It will just connect again as soon as a connection can be established.
