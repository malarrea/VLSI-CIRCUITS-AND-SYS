#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stack>
#include <vector>
using namespace std;

void ROF (vector<int> pV, int &mn, vector<int> nV, vector<int> &collect)
{
  //  [A]   [A]
  //(B X, B X)
  int PA;int NA;
  vector<int>table;
  int nummod = 8;
  for (int x =0; x < nummod; x++)
  {
    if (pV[x] == mn)
    {
      PA = x;
      //cout << "LOCATION OF mn is on PV = " << x << endl;
    }
    if (nV[x] == mn)
    {
      NA = x;
      //cout << "LOCATION OF mn is on NV = " << x << endl;
    }
  }
  //cout << "\tRIGHT :\t{ ";
  for (int B = 0; B < nummod; B++)
  {
    if ((B > NA))
    {
      table.push_back(nV[B]);
    }
    if ((B > PA))
    {
      table.push_back(pV[B]);
    }
  }

  for(int i = 0; i < table.size(); i++)
  {
   for ( int j=i+1; j < table.size() ; j++ )
   {
    if (table[i] == table[j])
    {
      //cout << table[j] << " ";
      collect.push_back(table[i]);
    }
   }
  }
//  cout << "}";
}

void LOF(vector<int> pV, int &mn, vector<int> nV, vector<int> &collect)
{
  // [A]   [A]
  // (X  B, X  B)
  int PA;int NA;
  vector<int>table;
  int nummod = 8;
  for (int x =0; x < nummod; x++)
  {
    if (pV[x] == mn)
    {
      PA = x;
    }
    if (nV[x] == mn)
    {
      NA = x;
    }
  }
//  cout << "\tLEFT :\t{ ";
  for (int B = 0; B < nummod; B++)
  {
    if ((B < NA))
    {
      //cout << "NV : " << nV[B] << endl;
      table.push_back(nV[B]);
    }
    if ((B < PA))
    {
      //cout << "PV : " << pV[B] << endl;
      table.push_back(pV[B]);
    }

  }

  for(int i = 0; i < table.size(); i++)
  {
   for ( int j=i+1; j < table.size() ; j++ )
   {
    if (table[i] == table[j])
    {
    //  cout << table[j] << " ";
    collect.push_back(table[i]);

    }
   }
  }
//  cout << "}";

}

void AOF(vector<int> pV, int &mn, vector<int> nV,vector<int> &collect)
{
  // [A]      [A]
  // (X  B, B  X)
  int PA;int NA;
  vector<int>table;
  int nummod = 8;
  for (int x =0; x < nummod; x++)
  {
    if (pV[x] == mn)
    {
      PA = x;
    }
    if (nV[x] == mn)
    {
      NA = x;
    }
  }
  //cout << "\tABOVE :\t{ ";
  for (int B = 0; B < nummod; B++)
  {
    if ((B > NA))
    {
      //cout << "NV : " << nV[B] << endl;
      table.push_back(nV[B]);
    }
    if ((B < PA))
    {
      //cout << "PV : " << pV[B] << endl;
      table.push_back(pV[B]);
    }
  }

  for(int i = 0; i < table.size(); i++)
  {
   for ( int j=i+1; j < table.size() ; j++ )
   {
    if (table[i] == table[j])
    {
    //  cout << table[j] << " ";
    collect.push_back(table[i]);

    }
   }
  }
//  cout << "}";

}

void BOF(vector<int> pV, int &mn, vector<int> nV,vector<int> &collect)
{
  //    [A] [A]
  // (B  X , X  B)

  int PA; int NA;
  vector<int>table;

  int nummod = 8;
  for (int x = 0; x < nummod; x++)
  {
    if (pV[x] == mn)
    {
      PA = x;
    }
    if (nV[x] == mn)
    {
      NA = x;
    }
  }

//  cout << "\tBELOW :\t{ ";
  for (int B = 0; B < nummod; B++)
  {

    if ((B < NA))
    {
      //cout << "NV : " << nV[B] << endl;
      table.push_back(nV[B]);
    }
    if ((B > PA))
    {
      //cout << "PV : " << pV[B] << endl;
      table.push_back(pV[B]);
    }
  }

  for(int i = 0; i < table.size(); i++)
  {
   for ( int j=i+1; j < table.size() ; j++ )
   {
    if (table[i] == table[j])
    {
      collect.push_back(table[i]);

    //  cout << table[j] << " ";
    }
   }
  }
//  cout << "}";

}




int main()
{
  string test = "+1 7 4 5 2 6 3 8 -8 4 7 2 5 3 6 1\0";
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
          //cout << "!POSTIVE! : " << test[position] <<  endl;
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
          //cout << "!NEGATIVE! : " << test[position] <<  endl;
          int convert = test[position];
          convert = convert - 48;
          evaluate2.push_back(convert);
        }
      }
    }
  }

    int modules = 8;
    vector<int> collect1;
    vector<int> collect2;
    vector<int> collect3;
    vector<int> collect4;

    int right[modules][modules];
    int left [modules][modules];
    int above[modules][modules];
    int below[modules][modules];

    int x = 2;

    cout << endl;
    ROF(evaluate1,x,evaluate2,collect1);
    for (int x = 0; x < collect1.size(); x ++)
    {
      cout << collect1[x] << " ";
    }
    cout << endl;
        // mod[x][z] = ROF(evaluate1,x,evaluate2);
        // mod[x][z] = LOF(evaluate1,x,evaluate2);
        // mod[x][z] = AOF(evaluate1,x,evaluate2);
        // mod[x][z] = BOF(evaluate1,x,evaluate2);
        //cout << endl; cout << endl;



  return 0;
}
