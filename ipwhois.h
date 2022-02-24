#pragma once
#include <string>
using namespace std;

class IpWhois
{
private:
	void curlIP(string url);
	void tableIP();
public:
	string ip;
	bool success = false;
	string message;
	string type;
	string continent;
	string continent_code;
	string country;
	string country_code;
	string country_flag;
	string country_capital;
	string country_phone;
	string country_neighbours;
	string region;
	string city;
	float latitude = 0.00;
	float longitude = 0.00;
	string asn;
	string org;
	string isp;
	string timezone;
	string timezone_name;
	int timezone_dstOffset = 0;
	int timezone_gmtOffset = 0;
	string timezone_gmt;
	string currency;
	string currency_code;
	string currency_symbol;
	float currency_rates = 0.00;
	string currency_plural;
	int completed_requests = 0;
	
	IpWhois() {
		type = "IPv4";
	}

	void results();

	void byIpAddr(string ipAdrr);
};

