#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stack>
using namespace std;

/*structure to store a BST*/
struct node
{
	int info;
	node *left,*right;
};

/*Method to create a newNode if a tree does not exist*/
node *newNode(char n)
{
	node *ptr=new node;
	ptr->info=n;
	ptr->left=ptr->right=NULL;
	return ptr;
}

/*Method to insert given node in the BST */
node *insert(node* node,char info)
{
	if(node==NULL)
	{
		return newNode(info);
	}
	if(info < node->info)
	{
		node->left=insert(node->left,info);
	}
	else
	{
		node->right=insert(node->right,info);
	}
	return node;
}

/*Method to print postorder traversal of a BST*/
void postorder(node *root)
{
	stack<node*> post;
	post.push(root);

	stack<char> pout;
	while(!post.empty())
	{
		node *curr=post.top();
		post.pop();
		pout.push(curr->info);

		if(curr->left)
		{
			post.push(curr->left);
		}
		if(curr->right)
		{
			post.push(curr->right);
		}
	}
	cout<<"PostOrder traversal :";
	while(!pout.empty())
	{
		cout<<pout.top()<<" ";
		pout.pop();
	}
}

int main()
{
  string test = "1 6 H 3 5 V 2 H V 7 4 H V\0";
  node* root = newNode(test[test.size() - 1]);

  for (int x = test.size(); x >= 0; x--)
  {
    if (test[x] != ' ' && test[x] != '\0')
    {
      //cout << test[x];
      insert(root,test[x]);
    }
  }
  postorder(root);


















  return 0;
}
