#include <iostream>
#include "WordFreg.h"

using namespace std;

int main(int argc, char* argv[]) {
    WordFreg test;
    test.readStat(argv[1]);
	test.save(argv[2]);
    return 0;
}