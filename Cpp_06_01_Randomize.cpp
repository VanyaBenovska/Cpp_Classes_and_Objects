// Cpp_06_01_Randomize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<sstream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

class TokensList {
private:
	std::string name;
	std::vector<std::string> listOftokens;

public:
	TokensList(std::string name, std::vector<std::string> listOftokens) :
		name(name), listOftokens(listOftokens) {
	}

	void setAnotherOrder() {
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(this->listOftokens.begin(), this->listOftokens.end(), g);
	}

	std::string getInfoToPrint() {
		std::ostringstream info;
		for (std::vector<std::string>::iterator it = this->listOftokens.begin(); it != this->listOftokens.end(); it++)
		{
			info << *it << std::endl;
		}
		return info.str();
	}
};

int main()
{
	std::vector<std::string > listOfTokens;
	std::string input;
	getline(std::cin, input);
	std::istringstream iss(input);
	std::string token;
	while (iss >> token)
	{
		listOfTokens.push_back(token);
	}

	TokensList element("firstElement", listOfTokens);

	element.setAnotherOrder();
	std::cout << element.getInfoToPrint() << std::endl;
	std::cout << std::endl << std::endl;
	//element.setAnotherOrder();
	//std::cout << element.getInfoToPrint() << std::endl;
	return 0;
}

