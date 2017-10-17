//Names:
//		Prajjwal Dangal		@02721735
//		Roshan Thapaliya	
#include "stack.cpp"
#include "queue.cpp"
#include <iostream>
#include <map>
#include <boost/assign/list_of.hpp>
#include <string.h>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <list>
#include <iomanip>
#include <deque>
#include <sstream>
#include <fstream>

//using namespace std;

struct BST
{
	/* data */
	string data;
	BST * left;
	BST * right;

	
};


// Find the maximum height of the binary tree
int maxHeight(BST *p) {
  if (!p) return 0;
  int leftHeight = maxHeight(p->left);
  int rightHeight = maxHeight(p->right);
  return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}

// Convert an integer value to string
string intToString(int val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

// Print the arm branches (eg, /    \ ) on a line
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BST*>& nodesQueue, ostream& out) {
  deque<BST*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {  
    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << endl;
}

// Print the branches and node (eg, ___10___ )
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BST*>& nodesQueue, ostream& out) {
  deque<BST*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? ((*iter)->data) : "");
    out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}

// Print the leaves only (just for the bottom row)
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<BST*>& nodesQueue, ostream& out) {
  deque<BST*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? ((*iter)->data) : "");
  }
  out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
void printPretty(BST *root, int level, int indentSpace, ostream& out) {
  int h = maxHeight(root);
  int nodesInThisLevel = 1;

  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)
    
  deque<BST*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    for (int i = 0; i < nodesInThisLevel; i++) {
      BST *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
	      nodesQueue.push_back(currNode->left);
	      nodesQueue.push_back(currNode->right);
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}


string getting_input();
bool check_precedence(char, char);
void op_on_stack(int* p_mode, char symbol, StackType our_stack, 
					QueueType our_queue);
int para_mode=0;

void stack_queue(char temp, std::stack <char> &our_stack, 
					std::queue <char> &our_queue, char a);
int main()
{
	
	
//Getting arithmetic expression from the user
	string input; 
	cout << "Enter the expression: ";
	cin >> input;
	
	std::queue <char> output_queue;
	std::stack <char> operator_stack;

	char a;

	int length_input=input.length();

	for(int i=0;i<length_input;i++)
	{
		
		a=input[i];
		char temp=input[i];
		stack_queue(temp, operator_stack, output_queue, a);
	}
	
	cout << endl;
	
	while (!operator_stack.empty())
	{
		char w = operator_stack.top();
		operator_stack.pop();
		output_queue.push(w);
	}

	cout << endl;

	string RPN;
	
	while(!output_queue.empty())
	{
		char h = output_queue.front();
		output_queue.pop();
		RPN = RPN + h;
	}
	
// Calculating RPN using Shunting Algorithm


	int aa=RPN.length();
	stack <BST*> pointer_stack;

	stack<float> calculate;


	int counter=0;
	BST * holder;
	for (int i=0;i<aa;i++)
	{

		string value;
		value=RPN[i];
		char test=value[0];
		
		

		if((isdigit(test)))
		{
			float m=test-'0';
			calculate.push(m);
			
			
		}
		else
		{
			float first=calculate.top();
			calculate.pop();
			float second=calculate.top();
			calculate.pop();
			

			if (test=='+')
			{
				calculate.push(first+second);

			}
				
			else if(test=='-')
				calculate.push(second-first);
			else if(test=='*')
			{
				calculate.push(first*second);
			}
				
			else if(test=='/')
			{
				calculate.push(second/first);

				
			}
				
			else
				calculate.push(pow(second,first));
			




		}


		if (counter<2)
		{
			holder=new BST;
			holder->data=value;
			holder->left=NULL;
			holder->right=NULL;
			pointer_stack.push(holder);
			counter++;	

		}
		else if((isdigit(test)))
		{
			holder=new BST;
			holder->data=value;
			holder->left=NULL;
			holder->right=NULL;
			pointer_stack.push(holder);
		}
		else
		{
			holder=new BST;
			holder->data=value;
			holder->right=pointer_stack.top();
			pointer_stack.pop();
			holder->left=pointer_stack.top();
			pointer_stack.pop();
			pointer_stack.push(holder);

		}

	}
BST * root=holder;


//Outputting our answers

cout << "RPN is: " << RPN << endl;
cout<<"Infix:"<<input<<endl;
cout<<"Calculated value:"<<calculate.top()<<endl;
cout<<"Binary Tree"<<endl;
printPretty(root, 1, 0, cout);


	return 0;

}

/*
Checking precedence
'+' is less than '/'->1
'+' is equal to '-'->0
'*' is greater than '-'->1
*/

bool check_precedence(char a, char b)
{
	static std::map<char, int>  order = boost::assign::map_list_of
    ('+', 2)
    ('-', 2)
    ('*', 3)
    ('/', 3)
    ('^', 4);



    if (order[a]>order[b])
    	return true;
    else
     	return false;
}

void stack_queue(char temp, std::stack <char> &our_stack, 
					std::queue <char> &our_queue, char a)
{
	char x;

	if (isdigit(temp))
		our_queue.push(a);

	else
	{
		if (temp=='(')
			our_stack.push(a);

		else if (temp==')')
		{
			while (true)
			{
				x = our_stack.top();
				if (x=='(')
				{
					our_stack.pop();
					break;
				}
				our_queue.push(x);
				our_stack.pop();
			}
		}
		else
		{
			char top1;
			if (!our_stack.empty() && our_stack.top()!='(')
			{
				top1 = our_stack.top();
			
				if (check_precedence(temp, top1))
					our_stack.push(a);
				else
				{
					char from_stack;
					from_stack = our_stack.top();
					our_stack.pop();
					our_queue.push(from_stack);
					our_stack.push(a);
				}
			}
			else
				our_stack.push(a);
		}
	}
}
