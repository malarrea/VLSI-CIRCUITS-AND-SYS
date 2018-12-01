#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int linecount (string filename)
{
  int count = 0;  string lines;
  ifstream input;
  input.open(filename.c_str());
  while (std::getline(input,lines))
    {
      ++count;
    }
  input.close();
  count - 1;
  return count;
}

int main()
{
  ifstream infile;
  string filename;
  cout << "Enter filename : \"filename.pe\" to gather information: ";
  cin  >> filename;
  infile.open(filename.c_str());

  if(infile.fail())
  {
    cout << "Error Opening file!" << endl;
    exit(-1);
  }
  string initial;
  getline(infile,initial);

  // cout << "START : " << initial << endl;
  string array[linecount(filename)-1]; int iterator = 0;
  while (infile.good())
  {
    string capture;
    getline(infile,capture);
    array[iterator] = capture;
    iterator++;

  }
  // for (int x = 0; x < linecount(filename) - 1;  x++)
  // {
  //   cout << "x : " << x << " -> " << array[x] << endl;
  // }

  // INDICAtOR OF MOVES
  // for (int x = 0; x < linecount(filename) - 1; x++)
  // {
  //   string line;
  //   line = array[x];
  //   char indicator = line[0];
  //   if (indicator == '-')
  //   {
  //     cout << "MOVE 1 or MOVE 2" << endl;
  //   }
  //   else
  //   {
  //     cout << "MOVE 3 " << endl;
  //   }
  //
  // }

//  REMEMEBR!!!
// ▪ Move 1 (Operand swap): Swap two adjacent operands.
// ▪ Move 2 (Chain invert): Complement a chain (V→H, H→V)
// ▪ Move 3 (Operator/operand swap): Swap two adjacent operand and
// operator.
// --------------------------------------------------------------------




  return 0;
}
