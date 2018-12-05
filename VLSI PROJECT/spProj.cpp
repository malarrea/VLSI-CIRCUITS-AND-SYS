#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stack>
#include <vector>
using namespace std;


void LOF(vector<int> pV, int mn, vector<int> nV)
{
  bool print = false;
  cout << pV[0] << " " << nV[0] << endl;
  for (int x = 0; x < pV.size(); x++)
  {
    for (int z = 0; z <nV.size(); z++)
    {
      // INITIAL START OF SP
      if (pV[x] == mn && nV[z] == mn && x == 0 && z == 0)
      {
        cout << "RIGHT :\tNULL" << endl;
      }

      if







    }
  }

}








int main()
{
  string test = "+3 2 5 1 4 -3 1 4 5 2\0";
	vector<int> test1;
  vector<int>evaluate1;
  vector<int>evaluate2;

  bool start = false; bool flip = true;

  // WE NEED TO USE POST EXPRESSION STRATEGY
	for (int position = 0; position < test.size(); position++)
  {
		if (test[position] != '\n' && test[position] != ' ' && test[position] != '\0')
		{
      if (test[position] == '+' || flip == true )
      {
        flip = true;
        if (isdigit(test[position]))
        {
          cout << "!POSTIVE! : " << test[position] <<  endl;
          int convert = test[position];
          convert = convert - 48;
          evaluate1.push_back(convert);
        }
        else
          {
          }
      }
      if (test[position] == '-' || flip == false)
      {
        flip = false;
        if (isdigit(test[position]))
        {
          cout << "!NEGATIVE! : " << test[position] <<  endl;
          int convert = test[position];
          convert = convert - 48;
          evaluate2.push_back(convert);
        }
      }
    }
  }

  // for(int i=0; i<evaluate1.size(); ++i)
  // {
  //   cout << evaluate1[i] << ' ';
  // }
  // for(int i=0; i<evaluate2.size(); ++i)
  // {
  //   cout << evaluate2[i] << ' ';
  // }

    // use reference on parameter mn
    LOF(evaluate1,3,evaluate2);
    //ABOF(evaluate1,x,evaluate2)



  return 0;
}
