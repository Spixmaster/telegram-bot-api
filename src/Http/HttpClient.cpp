#include <iostream>
#include <curl/curl.h>
#include <rapidjson/document.h>
#include <tgbot/http/HttpClient.h>
#include <tgbot/http/InputFile.h>
#include <tgbot/SpecialTools.h>

namespace tgbot
{
	size_t write_callback(void *contents, size_t size, size_t nmemb, std::string *s)
	{
		size_t new_length = size*nmemb;
		try
		{
			s->append((char*)contents, new_length);
		}
		catch(std::bad_alloc &e)
		{
			//handle memory problem
			return 0;
		}
		return new_length;
	}

	HttpClient::HttpClient(const std::string &url) : m_url(url)
	{}

	HttpClient::HttpClient(const std::string &url, const std::vector<HttpArg> &http_args) : m_url(url), m_http_args(http_args)
	{}

	std::string HttpClient::send_get_req()
	{
		//###Curl###
		//beginning
		curl_global_init(CURL_GLOBAL_ALL);
		CURL *curl;
		CURLcode result;
		curl = curl_easy_init();
		std::string response;
		long http_code = 0;

		//options
		curl_easy_setopt(curl, CURLOPT_URL, m_url.c_str());

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		//end
		result = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
		curl_easy_cleanup(curl);
		curl_global_cleanup();

		if(result != CURLE_OK)
				std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(result) << std::endl;

		if(http_code != 200)
		{
			std::cerr << "Error: Request's status code is not 200!" << std::endl;
			//so that assertion does not fail that the response is a json object as Message(std::string json) is built with the response
			return "{}";
		}

		return response;
	}

	std::string HttpClient::send_post_req()
	{
		//###Curl###
		//beginning
		curl_global_init(CURL_GLOBAL_ALL);
		CURL *curl;
		CURLcode result;
		curl_mime *form = NULL;
		curl_mimepart *field = NULL;
		curl = curl_easy_init();
		std::string response;
		long http_code = 0;

		//options
		curl_easy_setopt(curl, CURLOPT_URL, m_url.c_str());

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		//form
		form = curl_mime_init(curl);
			//add each field
		for (std::size_t j = 0; j < m_http_args.size(); ++j)
		{
			if(std::holds_alternative<long long>(m_http_args.at(j).m_value))
			{
				field = curl_mime_addpart(form);
				curl_mime_name(field, m_http_args.at(j).m_key.c_str());
				curl_mime_data(field, std::to_string(std::get<long long>(m_http_args.at(j).m_value)).c_str(), CURL_ZERO_TERMINATED);
			}
			else if(std::holds_alternative<std::string>(m_http_args.at(j).m_value))
			{
				field = curl_mime_addpart(form);
				curl_mime_name(field, m_http_args.at(j).m_key.c_str());
				curl_mime_data(field, std::get<std::string>(m_http_args.at(j).m_value).c_str(), CURL_ZERO_TERMINATED);
			}
			//value is type of InputFile::ptr
			else
			{
				field = curl_mime_addpart(form);
				curl_mime_name(field, m_http_args.at(j).m_key.c_str());
				curl_mime_filedata(field, std::get<InputFile::ptr>(m_http_args.at(j).m_value)->m_path.c_str());
			}
		}
		curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

		//end
		result = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
		curl_easy_cleanup(curl);
		curl_global_cleanup();

		if(result != CURLE_OK)
				std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(result) << std::endl;

		if(http_code != 200)
		{
			std::cerr << "Error: Request's status code is not 200!" << std::endl;

			//so that the parsing does not complain that the response is not a json object
			response = "{}";

			rapidjson::Document doc;
			doc.Parse(response.c_str());
			if(doc.HasMember("description"))
				std::cerr << doc["description"].GetString() << std::endl;
			//so that assertion does not fail that the response is a json object as Message(std::string json) is built with the response
			return "{}";
		}

		return response;
	}
}
