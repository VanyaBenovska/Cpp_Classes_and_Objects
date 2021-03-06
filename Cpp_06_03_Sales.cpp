// Cpp_06_03_Sales.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<sstream>
#include <vector>
#include <map>
#include<algorithm>
#include <iomanip>

class TownSale
{
private:
	std::string town;
	double townSales;

public:
	std::string getTown()
	{
		return town;
	}

	double getTownIncome()
	{
		return townSales;
	}

	void setTownSales(double singleSale) {
		this->townSales += singleSale;
	}

	TownSale(std::string town = "", double townSales = 0.0) :
		town(town), townSales(townSales) {
	}
};

int main()
{
	std::map<std::string, TownSale> mapTownSales;
	int n, c = 0;
	std::cin >> n;
	std::cin.ignore();
	std::string inputLine;
	while (n > 0)
	{
		std::getline(std::cin, inputLine);
		std::istringstream iss(inputLine);
		std::string token;
		std::string tempArr[4];
		int k = 0;
		while (iss >> token)
		{
			tempArr[k] = token;
			k++;
		}
		std::string city = tempArr[0];
		std::string product = tempArr[1];

		std::string::size_type sz;     // alias of size_t
		double price = std::stod(tempArr[2], &sz);

		int quantity = atoi(tempArr[3].c_str());

		double singleSale = price * quantity;


		std::map<std::string, TownSale>::iterator foundCity = mapTownSales.find(city);
		if (foundCity != mapTownSales.end()) {
			mapTownSales[city].setTownSales(singleSale);
		}
		else {
			TownSale sale(city, singleSale);
			mapTownSales.insert({ city, sale });
		}

		n--;
	}

	for (auto i = mapTownSales.begin(); i != mapTownSales.end(); i++) {
		std::pair<std::string, TownSale> item = *i;
		std::cout << i->first << " -> " << std::fixed << std::setprecision(2) << i->second.getTownIncome() << std::endl;
	}

	return 0;
}

