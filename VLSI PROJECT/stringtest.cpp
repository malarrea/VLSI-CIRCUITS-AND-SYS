#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stack>
#include <vector>
using namespace std;


//https://www.youtube.com/watch?v=rQ42CyfJ5EA
int main()
{
  string test = "1 6 H 3 5 V 2 H V 7 4 H V\0";
	vector<char> test1;

	for (int x = 0; x < test.size(); x++)
	{
		if (test[x] != '\n' && test[x] != ' ' && test[x] != '\0')
		{
			test1.push_back(test[x]);
		}
	}

	for (std::vector<char>::const_iterator i = test1.begin(); i != test1.end(); i++)
	{

	}














  return 0;
}
