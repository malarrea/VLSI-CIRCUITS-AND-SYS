#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

bool isNumber(string line)
{
    return (atoi(line.c_str()));
}
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
  return count;
}
void netnode (string filename, int& net, int& nod)
{
  ifstream file; file.open(filename.c_str());
  string line; string netnode;
  getline(file, line);
  netnode = line; bool separator = false;
  string nodes; string netlists;
  for (int x = 0; x < netnode.size(); x++)
  {
    if (netnode[x] == ' ')
    {
      separator = true;
      x++;
    }
    if (separator == true)
    {
      nodes = nodes + netnode[x];
    }
    else
      {
          netlists = netlists + netnode[x];
      }
  }
  file.close();
  stringstream convert1(nodes);
  stringstream convert2(netlists);
  int node; convert1 >> nod;
  int netlist; convert2 >> net;

}
void listcreate (string filename, int size, vector<string> arr[])
{
  // OPENS FILE AND READS IT!
  ifstream file; file.open(filename.c_str()); string line;
  // CAPTURES FIRST LINE
  getline(file, line);
  // CAPTURES UNTIL THE END OF FILE
  int x = 0;
  while (getline(file, line))
  {
      std::stringstream lineStream(line);
      std::vector<string> lineData;
      string data;
      while (lineStream >> data)
      {
        //generates the list of node|nets
        //cout << data;
        lineData.push_back(data);
      }
      arr[x] = lineData;
      x++;
      //iterates to the next node|nets
      //cout << endl;
  }
}
string coordinates (vector<string> arr[], int size)
{
  string data = ""; int edges = 0;
  for (int x = 0; x < size; x++)
  {
    for (vector<string>::size_type t = 0; t < arr[x].size(); t++)
    {
      if ((arr[x][0] != arr[x][t]))
      {
        edges++;
        data += "(" + arr[x][0] + "," + arr[x][t] + ") ";
        //cout << data << endl;
      }
    }
  }
  return data;
}
int edges (vector<string> arr[], int size)
{
  int edges = 0;
  for (int x = 0; x < size; x++)
  {
    for (vector<string>::size_type t = 0; t < arr[x].size(); t++)
    {
      if ((arr[x][0] != arr[x][t]))
      {
        edges++;
      }
    }
  }
  return edges;
}
string separse (string data, int size)
{
  string array[size];
  //cout << data << endl;
  int index = 0; string cord;
  for (int x = 0; x < data.size(); x++)
  {
    if (data[x] == '(' && data[x] != ' ')
    {
      std::stringstream ss;
      ss << data[x] << data[x + 1] << data[x + 2] << data[x + 3] << data[x + 4];
      cord =  ss.str();
      cout << cord << endl;
      array[index] = cord;
      index++;
    }
  }




}


int main()
{
  ifstream file;
  string filename;
  cout << "Enter hyper graph file : \"filename.hgr\" to obtain netlist: ";
  cin  >> filename;
  int nodes; int netlists;
  int size = linecount(filename);
  int datasize = size - 1;
  vector<string> array[size];
  netnode(filename,nodes,netlists);
  listcreate(filename,size,array);
  string data = coordinates(array,size);
  separse(data,edges(array,size));




  cout << "[Netlist(s), Node(s)]:  [" << netlists << "," << nodes << "]" << endl;
  file.close();
  int input;
  cout << endl;
  cout << "Maximum # of passes : ";
  cin >> input;
  cout << endl;
  cout << "Enter intial partition file : " << endl;
  filename = "";
  cin >> filename;
  cout << "[Edge(s), Total Edge Weight]: [" << edges(array,size) << "," << "]" << endl;




  return 0;
}
