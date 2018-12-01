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
  cout << "Enter filename : \"filename.size\" to gather information: ";
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
  int modulew [linecount(filename)];  int moduleh [linecount(filename)];

  int w; int h; int n;
  while(infile >> w >> h)
  {
    modulew[n] = w;
    moduleh[n] = h;
    cout << "MODULE [" << n << "] : " << w << " " << h;
    n++;
    cout << endl;
  }




  return 0;
}
