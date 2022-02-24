// IPLookupGeolocation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ipwhois.h"
#include <string>

using namespace std;

int main()
{
	cout << "#######################################################################" << endl;
	cout << "* IP Geolocation and IP Location Lookup Tools" << endl;
	cout << "- Lookup IP or domain information base on ipwhois (https://ipwhois.io/)" << endl;
	cout << "- Usage limit is free up to 10,000 requests per month" << endl;
	cout << "#######################################################################" << endl;

	IpWhois ipwhoisObj;
    
	int n = 0;
	string ipaddr;

	do{
		cout << "\n\n";
		std::cout << "[1] My current IP information." << endl;
		std::cout << "[2] Search by IPv4, IPv6 address or domain." << endl;
		std::cout << "[3] Exit." << endl;

		cout << "Type a number: ";
		while (!(cin >> n) || n < 0 || n > 3)
		{
			cout << "Error! - Invalid number" << endl;
			cout << "Type a number: ";
			cin.clear();
			cin.ignore(123, '\n');
		}

		switch (n)
		{
		case (1):
			cout << "\n-----------------------------------------------------------------------" << endl;
			cout << "# My current IP information." << endl;
			cout << "-----------------------------------------------------------------------" << endl;
			ipwhoisObj.results();
			break;
		case (2):
			cout << "Enter  IP address or domain: ";
			while (!(cin >> ipaddr) || ipaddr.size() > 100 || ipaddr.size() < 4 )
			{
				cout << "Error! - Invalid IP address or domain" << endl;
				cout << "Enter  IP address or domain: ";
				cin.clear();
				cin.ignore(123, '\n');
			}

			cout << "\n-----------------------------------------------------------------------" << endl;
			printf("# IP information for %s \n", ipaddr.c_str());
			cout << "-----------------------------------------------------------------------" << endl;
			ipwhoisObj.byIpAddr(ipaddr.c_str());
			break;
		case(3):
			exit(0);
			break;
		default:
			break;
		}
		
	} while (n != 3);

	return 0;
}

