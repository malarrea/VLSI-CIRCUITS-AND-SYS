#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stack>
#include <vector>
using namespace std;

struct node
{
	char info;
	node *left,*right;
};

node *newNode(char n)
{
	node *ptr=new node;
	ptr->info=n;
	ptr->left=ptr->right=NULL;
	return ptr;
}
//https://www.youtube.com/watch?v=rQ42CyfJ5EA
int main()
{
  string test = "4 2 1 H 3 H V 5 V\0";
	vector<char> test1;
  stack<char>evaluate;
  bool start = false;
  bool flip;
  // WE NEED TO USE POST EXPRESSION STRATEGY
	for (int position = 0; position < test.size(); position++)
	{

		if (test[position] != '\n' && test[position] != ' ' && test[position] != '\0')
		{
      if ( (test[position] == 'H'|| test[position] == 'V') && (start == false) )
      {
        start = true;
        flip = true;
        node* netlist = newNode (test[position]);
        while(!evaluate.empty())
        {
          if (flip == true)
          {
            cout << "bottom -> ";
            flip = false;
          }
          else
          {
            cout << "top -> ";
            flip = true;
          }

          cout << evaluate.top() << " ";
          evaluate.pop();
        }
      }
      if (test[position] == 'H' && start == true)
      {
        //cout << "H: " << test[position] << endl;
        flip = true;
        while(!evaluate.empty())
        {
          if (flip == true)
          {
            cout << "bottom -> ";
            flip = false;
          }
          else
          {
            cout << "top -> ";
            flip = true;
          }
          cout << evaluate.top() << " ";
          evaluate.pop();

        }
        cout << " : H" << endl;
      }
      if (test[position] == 'V' && start == true)
      {
        //cout << "V: " << test[position] << endl;
        flip = true;
        while(!evaluate.empty())
        {
          if (flip == true)
          {
            cout << "left -> ";
            flip = false;
          }
          else
          {
            cout << "right -> ";
            flip = true;
          }
          cout << evaluate.top() << " ";
          evaluate.pop();

        }
        cout<< " : V" << endl;
      }
      if (isdigit(test[position]))
      {
        //cout << "NUMBER : " << test[position] << endl;
        evaluate.push(test[position]);
      }
		}
	}













  return 0;
}
