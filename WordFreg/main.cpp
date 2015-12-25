#include <iostream>
#include "WordFreg.h"

using namespace std;

/*
first parameter is path to file for processing
second parameter is path to result(statictic) file
third parameter is path to old statictis file - OPTIONAL
*/

int main(int argc, char* argv[]) 
{
    WordFreg test;
	if(argc == 3)
	{
		test.GetStat(argv[1]);
		test.save(argv[2]);
	}
    else if(argc == 4 )
    {
		test.ReadStat(argv[3]);
		test.GetStat(argv[1]);
		test.save(argv[2]);
    }
	else
	{
		std::cout << "Check parameters!" << endl;
	}
    return 0;
}