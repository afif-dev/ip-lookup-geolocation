#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "ipwhois.h"
#include "TextTable.h"

constexpr auto IPWHOIS_API = "https://ipwhois.app/json/";

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

void IpWhois::curlIP(string url = IPWHOIS_API)
{
	CURL* curl;
	string readBuffer;

	curl = curl_easy_init();

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		CURLcode res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		auto json = nlohmann::json::parse(readBuffer);

		if (json.size() > 0) {
			if (json.contains("ip")) {
				ip = json["ip"];
			}
			if (json.contains("success")) {
				success = json["success"];
			}
			if (json.contains("message")) {
				message = json["message"];
			}
			if (json.contains("type")) {
				type = json["type"];
			}
			if (json.contains("continent")) {
				continent = json["continent"];
			}
			if (json.contains("continent_code")) {
				continent_code = json["continent_code"];
			}
			if (json.contains("country")) {
				country = json["country"];
			}
			if (json.contains("country_code")) {
				country_code = json["country_code"];
			}
			if (json.contains("country_flag")) {
				country_flag = json["country_flag"];
			}
			if (json.contains("country_capital")) {
				country_capital = json["country_capital"];
			}
			if (json.contains("country_phone")) {
				country_phone = json["country_phone"];
			}
			if (json.contains("country_neighbours")) {
				country_neighbours = json["country_neighbours"];
			}
			if (json.contains("region")) {
				region = json["region"];
			}
			if (json.contains("city")) {
				city = json["city"];
			}
			if (json.contains("latitude")) {
				latitude = json["latitude"];
			}
			if (json.contains("longitude")) {
				longitude = json["longitude"];
			}
			if (json.contains("asn")) {
				asn = json["asn"];
			}
			if (json.contains("org")) {
				org = json["org"];
			}
			if (json.contains("isp")) {
				isp = json["isp"];
			}
			if (json.contains("timezone")) {
				timezone = json["timezone"];
			}
			if (json.contains("timezone_name")) {
				timezone_name = json["timezone_name"];
			}
			if (json.contains("timezone_dstOffset")) {
				timezone_dstOffset = json["timezone_dstOffset"];
			}
			if (json.contains("timezone_gmtOffset")) {
				timezone_gmtOffset = json["timezone_gmtOffset"];
			}
			if (json.contains("timezone_gmt")) {
				timezone_gmt = json["timezone_gmt"];
			}
			if (json.contains("currency")) {
				currency = json["currency"];
			}
			if (json.contains("currency_code")) {
				currency_code = json["currency_code"];
			}
			if (json.contains("currency_symbol")) {
				currency_symbol = json["currency_symbol"];
			}
			if (json.contains("currency_rates")) {
				currency_rates = json["currency_rates"];
			}
			if (json.contains("currency_plural")) {
				currency_plural = json["currency_plural"];
			}
			if (json.contains("completed_requests")) {
				completed_requests = json["completed_requests"];
			}
		}
	}
}

void IpWhois::tableIP()
{
	TextTable t('-', '|', '+');

	t.add("Item");
	t.add("Value");
	t.endOfRow();

	if (!success) {
		t.add("IP Address");
		t.add(ip);
		t.endOfRow();

		t.add("Success");
		t.add((success ? "true" : "false"));
		t.endOfRow();
		
		t.add("Message");
		t.add(message);
		t.endOfRow();
	}
	else
	{
		t.add("IP Address");
		t.add(ip);
		t.endOfRow();

		t.add("Success");
		t.add((success ? "true" : "false"));
		t.endOfRow();

		t.add("IP Type");
		t.add(type);
		t.endOfRow();

		t.add("Continent");
		t.add(continent);
		t.endOfRow();

		t.add("Continent Code");
		t.add(continent_code);
		t.endOfRow();

		t.add("Country");
		t.add(country);
		t.endOfRow();

		t.add("Country Code");
		t.add(country_code);
		t.endOfRow();

		t.add("Country Flag");
		t.add(country_flag);
		t.endOfRow();

		t.add("Country Capital");
		t.add(country_capital);
		t.endOfRow();

		t.add("Country Phone");
		t.add(country_phone);
		t.endOfRow();

		t.add("Country Neighbours");
		t.add(country_neighbours);
		t.endOfRow();

		t.add("Region");
		t.add(region);
		t.endOfRow();

		t.add("City");
		t.add(city);
		t.endOfRow();

		t.add("Latitude");
		t.add(to_string(latitude));
		t.endOfRow();

		t.add("Longitude");
		t.add(to_string(longitude));
		t.endOfRow();

		t.add("ASN");
		t.add(asn);
		t.endOfRow();

		t.add("ORG");
		t.add(org);
		t.endOfRow();

		t.add("ISP");
		t.add(isp);
		t.endOfRow();

		t.add("Timezone");
		t.add(timezone);
		t.endOfRow();

		t.add("Timezone Name");
		t.add(timezone_name);
		t.endOfRow();

		t.add("Timezone DST Offset");
		t.add(to_string(timezone_dstOffset));
		t.endOfRow();

		t.add("Timezone GMT Offset");
		t.add(to_string(timezone_gmtOffset));
		t.endOfRow();

		t.add("Timezone GMT");
		t.add(timezone_gmt);
		t.endOfRow();

		t.add("Currency");
		t.add(currency);
		t.endOfRow();

		t.add("Currency Code");
		t.add(currency_code);
		t.endOfRow();

		t.add("Currency Symbol");
		t.add(currency_symbol);
		t.endOfRow();

		t.add("Currency Rates");
		t.add(to_string(currency_rates));
		t.endOfRow();

		t.add("Currency Plural");
		t.add(currency_plural);
		t.endOfRow();

		t.add("Completed Requests");
		t.add(to_string(completed_requests));
		t.endOfRow();
	}

	t.setAlignment(2, TextTable::Alignment::RIGHT);
	std::cout << t;
}

void IpWhois::results() {
	curlIP();
	tableIP();
}

void IpWhois::byIpAddr(string ipAdrr)
{
	string url = IPWHOIS_API + ipAdrr;
	curlIP(url);
	tableIP();
}
