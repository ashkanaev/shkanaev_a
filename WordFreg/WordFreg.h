//
// Created by ashkanaev on 12/5/15.
//
#ifndef WORDFEG_WORDFREG_H
#define WORDFEG_WORDFREG_H

#include <map>

class WordFreg {
public:
	WordFreg() = default;
	WordFreg(const WordFreg& arg) = default;
	WordFreg& operator=(const WordFreg& arg) = default;
	void ReadStat(char* arg);
	void GetStat(char* arg);
	void save(char* arg);
	void clear();
private:
	std::map<std::string, int> _data;
};


#endif //WORDFEG_WORDFREG_H
