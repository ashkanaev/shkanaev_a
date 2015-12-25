//
// Created by ashkanaev on 12/5/15.
//

#include "WordFreg.h"
#include <iostream>
#include <fstream>
#include <boost\algorithm\string\split.hpp>
#include <boost\algorithm\string\classification.hpp>
#include <boost\algorithm\string.hpp>
#include <vector>
using namespace std;

void WordFreg::ReadStat(char* arg)
{
	std::fstream in;
	in.open(arg);
	std::string word;
	int numStat{ 0 };
	while(!in.eof())
	{
		in >> word >> numStat;
		_data[word] = numStat;
	}
	in.close();
}

void WordFreg::GetStat(char* arg) {
	string path(arg);
	std::fstream in2;
	in2.open(path);

    if(!in2.is_open())
    {
        return;
    }
    std::string temp;
    std::vector<std::string> splitedLine;
    while(!in2.eof())
    {
        std::getline(in2, temp);
        boost::split(splitedLine, temp, boost::is_any_of("  ` .,*-|?:'><()"));
        while (!splitedLine.empty())
        {
			temp = splitedLine.back();
			boost::algorithm::to_lower(temp);
            _data[temp]++;
            splitedLine.pop_back();
        }
    }
	in2.close();
	_data.erase("");
    std::cout << "Statistic is ready" << std::endl;

	for (std::map<std::string, int>::const_iterator it = _data.begin(); it != _data.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}

void WordFreg::save(char* arg)
{
	ofstream out(arg);
	for (std::map<std::string, int>::const_iterator it = _data.begin(); it != _data.end(); ++it)
	{
		out << it->first << " " << it->second << std::endl;
	}
	out.close();
}

