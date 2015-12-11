//
// Created by ashkanaev on 12/5/15.
//
#ifndef WORDFEG_WORDFREG_H
#define WORDFEG_WORDFREG_H

#include <map>
#include <vector>

class WordFreg {
public:
    WordFreg() = default;
    WordFreg(const WordFreg& arg) = default;
    void readStat(char* arg);
	void save(char* arg);
private:
    std::map<std::string,int> _data;
};


#endif //WORDFEG_WORDFREG_H
