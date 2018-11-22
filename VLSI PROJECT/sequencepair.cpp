#include <iostream>
#include <fstream>
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
  int width; int height;
  string filename;
  cout << "Enter filename : \"filename.txt\" to gather information: ";
  cin  >> filename;
  infile.open(filename.c_str());

  if(infile.fail())
  {
    cout << "Error Opening file!" << endl;
    exit(-1);
  }

  infile >> width;
  infile >> height;
  cout << "[WIDTH] : " << width << " [HEIGHT] : " << height << endl;
  int module [linecount(filename)];
  int data; int n;
  while(infile >> data)
  {
    module[n] = data;
    cout << "MODULE [" << n << "] : " << data;
    n++;
    cout << endl;
  }




  return 0;
}
