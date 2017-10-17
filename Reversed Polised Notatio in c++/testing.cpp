#include <iostream>
#include <map>
#include <boost/assign/list_of.hpp>
#include <string.h>
#include <cstring>
#include <stack>
#include <queue>



using namespace std;


string getting_input();
bool check_precedence(char, char);

//void op_on_stack(int* p_mode, char symbol, StackType our_stack, 
//					QueueType our_queue);

//void stack_queue(char temp, Stack <StackType> &our_stack, 
//					Queue <QueueType> &our_queue, string a);

//void stack_queue(char temp, Stacktype <string> &our_stack, 
//					QueueType <string> &our_queue, string a);

//void stack_queue(char temp, std::stack <string> &our_stack, 
//					std::queue <string> &our_queue, string a);

void stack_queue(char temp, std::stack <char> &our_stack, 
					std::queue <char> &our_queue, char a);

int main()
{
	//Getting arithmetic expression from the user
	//string input=getting_input();
	
	string input = "3+(2*4-7)^3/2-7*3";
	//cout << "Enter the expression: ";
	//cin >> input;
	
	//cout << input;
	
	// std::queue <string> output_queue;
	// std::stack <string> operator_stack;

	std::queue <char> output_queue;
	std::stack <char> operator_stack;

	char a;

	int length_input=input.length();

	cout << "0 index: " << input[0];

	for(int i=0;i<length_input;i++)
	{
		
		a=input[i];
		char temp=input[i];
		stack_queue(temp, operator_stack, output_queue, a);
	}
		//here to 
		//here
	cout << endl;
	cout << "From stack: " << endl;

	while (!operator_stack.empty())
	{
		//string w = operator_stack.top();
		char w = operator_stack.top();
		cout << w;
		operator_stack.pop();
		output_queue.push(w);
		//output_queue.push_back(w);
	}

	//gdb brk pts 68, 73


	cout << endl;
	cout << endl;

	string RPN;
	int counter = 0;
	
	while(!output_queue.empty())
	{
		//string h=output_queue.front();
		char h = output_queue.front();
		//operator_stack.pop();
		output_queue.pop();
		//operator_stack.pop();
		RPN = RPN + h;
		//cout << h;
		counter++;
	}
	cout << "RPN is: " << RPN << endl;

	return 0;

}

/*
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
	//string x = "";
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
				//our_stack.pop();
				//if (x=="(")
				if (x=='(')
				{
					our_stack.pop();
					break;
				}
				//x = our_stack.top();
				our_queue.push(x);
				our_stack.pop();
			}
		}
		else
		{
			//if (our_stack.top() || our_stack.top() != "(")
			char top1;
			if (!our_stack.empty() && our_stack.top()!='(')
			{
				top1 = our_stack.top();
				//if (temp=='^' && top1=='^')
				//{
				// 	our_stack.push(a);
				// }
				
				//else if(check_precedence(temp, top1))
				if (check_precedence(temp, top1))
					our_stack.push(a);
				else
				{
					//string from_stack;
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