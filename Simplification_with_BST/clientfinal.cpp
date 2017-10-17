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
int main()
{
	
	
//Getting arithmetic expression from the user
	string input;
	cout<<"Enter infix expression to be calculated:"<<endl;
	cin>>input;
	int length_input=input.length();
	QueueType output_queue;
	StackType operator_stack;
	

// Calculating RPN using Shunting Algorithm

	string a;
	a=input[0];
	
		int k=0;
	
	for(int i=0;i<length_input;i++)
	{
		
		a=input[i];
		char temp=input[i];

		if (isdigit(temp))
		{

			output_queue.Enqueue(a);
			
		}
		
		else
		{
			if (k==0)
			{
				
				operator_stack.Push(a);
				k=1;
			}
			else if(temp=='(')
			{
				operator_stack.Push(a);
				i++;
				
				int b=0;
					while (temp != ')')
					{

						temp = input[i];
						a=input[i];

						
							if (isdigit(temp))
							{
								output_queue.Enqueue(a);
			
							}
							
							else
							{
								if(b==0)
								{
									operator_stack.Push(a);
									b=1;

								}
								else
								{
									char top=operator_stack.Top()[0];
									if (temp == '^')
									{
										
										operator_stack.Push(a);
									}
									

									else if (check_precedence(temp,top))
									{
										operator_stack.Push(a);
									}
									else
									{

										while (true)
										{
											if (operator_stack.IsEmpty())break;
											string hu=operator_stack.Top();
											if (hu!="^" )break;
											string from_stack=operator_stack.Pop();
											output_queue.Enqueue(from_stack);	
										}
					
					operator_stack.Push(a);
									}	
								}

								
						

							}
						
							
						i++;
						
						
					}


					i--;
					

					k=0;



					string x="";
					operator_stack.Pop();

					
						while (true)
						{
							x=operator_stack.Pop();
							if (x=="(")
								break;
							output_queue.Enqueue(x);


						}

			}
			else
			{
				
				char top=operator_stack.Top()[0];


				

				if(temp=='^')
				{
					//cout<<a<<endl;
					
					operator_stack.Push(a);

				}
				
				
				
				else if (check_precedence(temp,top))
				{
					operator_stack.Push(a);
				}
				else
				{

					while (true)
					{
					if (operator_stack.IsEmpty())break;
					string hu=operator_stack.Top();
					if (hu!="^" )break;
					string from_stack=operator_stack.Pop();
					output_queue.Enqueue(from_stack);	
					}
					
					operator_stack.Push(a);
					
					
				}
			}	

						
		}
			

	}

	while (!operator_stack.IsEmpty())
		{
			string w = operator_stack.Pop();
			output_queue.Enqueue(w);
		}

	
//Creating RPN string
	string RPN;
	while(!output_queue.IsEmpty())
	{
		string h=output_queue.Dequeue();
		RPN = RPN + h;
		
	}
	




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

bool check_precedence(char a, char b){
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


