#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <list>
#include <iomanip>
#include <deque>
#include <sstream>
#include <fstream>


using namespace std;



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







void postorder(BST *p, int indent=0) {


    
    if(p != NULL) {
        if(p->right) {
            postorder(p->right, indent+4);
        }
        if (indent) {
            cout << setw(indent) << ' ';
        }
        if (p->right) cout<<" /\n" << setw(indent) << ' ';
        cout<< p->data << "\n ";
        if(p->left) {
            cout << setw(indent) << ' ' <<" \\\n";
            postorder(p->left, indent+4);
        }
    }
}

main()
{
	//RPN to binary
	int a=13;
	string RPN[]={"3","4","2","*","1","5","-","2","3","^","^","/","+"};
	stack <BST*> pointer_stack;

	stack<float> calculate;


	int counter=0;
	BST * holder;
	for (int i=0;i<a;i++)
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
			//cout<<first<<","<<second<<endl;



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
cout<<endl;
BST * root=holder;


cout<<"Infix:3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3"<<endl;
cout<<"Calculated value for 3 4 2 * 1 5 - 2 3 ^ ^ / +"<<endl;
cout<<calculate.top()<<endl<<endl;

cout<<"Level Order printing"<<endl;


printPretty(root, 1, 0, cout);
}



