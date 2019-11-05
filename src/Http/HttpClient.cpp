#include <iostream>
#include <rapidjson/document.h>
#include "tgbot/http/HttpClient.h"
#include "tgbot/http/InputFile.h"
#include "tgbot/SpecialTools.h"
#include "tgbot/Tools.h"
#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTMLForm.h>
#include <Poco/Net/FilePartSource.h>
#include <Poco/Net/Context.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>
#include <string>

namespace tgbot
{
	HttpClient::HttpClient(const std::string &uri) : m_uri(uri)
	{}

	HttpClient::HttpClient(const std::string &uri, const std::vector<HttpArg> &http_args) : m_uri(uri), m_http_args(http_args)
	{}

	HttpResponse HttpClient::send_get_req()
	{
		Poco::Net::HTTPResponse::HTTPStatus http_response_code;
		std::string http_response_txt;

		try
		{
			//uri
			Poco::URI uri(m_uri);
			std::string path_query = uri.getPathAndQuery();
			if(path_query.empty())
				path_query = "/";

			//request
		    const Poco::Net::Context::Ptr context = new Poco::Net::Context(
		        Poco::Net::Context::CLIENT_USE, "", "", "",
		        Poco::Net::Context::VERIFY_NONE, 9, false,
		        "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
			Poco::Net::HTTPSClientSession session(uri.getHost(), uri.getPort(), context);
			session.setTimeout(Poco::Timespan(150L, 0L));
			Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_GET, path_query, Poco::Net::HTTPMessage::HTTP_1_1);
			session.sendRequest(req);

			//response
			Poco::Net::HTTPResponse response;
			http_response_code = response.getStatus();

			std::ostringstream oss;
			std::istream  &in = session.receiveResponse(response);
			Poco::StreamCopier::copyStream(in, oss);
			http_response_txt = oss.str();

			if(http_response_code != Poco::Net::HTTPResponse::HTTPStatus::HTTP_OK)
			{
				std::cerr << "Error: Request's http code is not 200!" << std::endl;

				//condition that we probably have a json object
				if(Tools::starts_w(http_response_txt, "{") && Tools::ends_w(http_response_txt, "}"))
				{
					rapidjson::Document doc;
					doc.Parse(http_response_txt.c_str());
					if(doc.HasMember("description"))
						std::cerr << doc["description"].GetString() << std::endl;
				}

				//so that assertion does not fail that the response is a json object as Message(std::string json) is built with the response
				HttpResponse http_response;
				http_response.code = http_response_code;
				http_response.txt = "{}";
				return http_response;
			}

			HttpResponse http_response;
			http_response.code = http_response_code;
			http_response.txt = http_response_txt;
			return http_response;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;

			//so that assertion does not fail that the response is a json object as Message(std::string json) is built with the response
			HttpResponse http_response;
			http_response.code = http_response_code;
			http_response.txt = "{}";
			return http_response;
		}
	}

	HttpResponse HttpClient::send_post_req()
	{
		Poco::Net::HTTPResponse::HTTPStatus http_response_code;
		std::string http_response_txt;

		try
		{
			//uri
			Poco::URI uri(m_uri);
			std::string path_query = uri.getPathAndQuery();
			if(path_query.empty())
				path_query = "/";

			//request
		    const Poco::Net::Context::Ptr context = new Poco::Net::Context(
		        Poco::Net::Context::CLIENT_USE, "", "", "",
		        Poco::Net::Context::VERIFY_NONE, 9, false,
		        "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
			Poco::Net::HTTPSClientSession session(uri.getHost(), uri.getPort(), context);
			session.setTimeout(Poco::Timespan(150L, 0L));
			Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_GET, path_query, Poco::Net::HTTPMessage::HTTP_1_1);

				//html form
			Poco::Net::HTMLForm form;
			form.setEncoding(Poco::Net::HTMLForm::ENCODING_MULTIPART);
					//add each field
			for (std::size_t j = 0; j < m_http_args.size(); ++j)
			{
				if(std::holds_alternative<long long>(m_http_args.at(j).m_value))
					form.set(m_http_args.at(j).m_key, std::to_string(std::get<long long>(m_http_args.at(j).m_value)));
				else if(std::holds_alternative<std::string>(m_http_args.at(j).m_value))
					form.set(m_http_args.at(j).m_key, std::get<std::string>(m_http_args.at(j).m_value));
				//value is type of InputFile::ptr
				else
					form.addPart(m_http_args.at(j).m_key, new Poco::Net::FilePartSource(std::get<InputFile::ptr>(m_http_args.at(j).m_value)->m_path));
			}

			form.prepareSubmit(req);
			form.write(session.sendRequest(req));

			//response
			Poco::Net::HTTPResponse response;
			http_response_code = response.getStatus();

			std::ostringstream oss;
			std::istream  &in = session.receiveResponse(response);
			Poco::StreamCopier::copyStream(in, oss);
			http_response_txt = oss.str();

			if(http_response_code != Poco::Net::HTTPResponse::HTTPStatus::HTTP_OK)
			{
				std::cerr << "Error: Request's http code is not 200!" << std::endl;

				//condition that we probably have a json object
				if(Tools::starts_w(http_response_txt, "{") && Tools::ends_w(http_response_txt, "}"))
				{
					rapidjson::Document doc;
					doc.Parse(http_response_txt.c_str());
					if(doc.HasMember("description"))
						std::cerr << doc["description"].GetString() << std::endl;
				}

				//so that assertion does not fail that the response is a json object as Message(std::string json) is built with the response
				HttpResponse http_response;
				http_response.code = http_response_code;
				http_response.txt = "{}";
				return http_response;
			}

			HttpResponse http_response;
			http_response.code = http_response_code;
			http_response.txt = http_response_txt;
			return http_response;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;

			//so that assertion does not fail that the response is a json object as Message(std::string json) is built with the response
			HttpResponse http_response;
			http_response.code = http_response_code;
			http_response.txt = "{}";
			return http_response;
		}
	}
}
