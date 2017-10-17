#include "stack.cpp"
#include "queue.cpp"
#include <iostream>
#include <map>
#include <boost/assign/list_of.hpp>
#include <string.h>
#include <cstring>



//using namespace std;


string getting_input();
bool check_precedence(char, char);
void op_on_stack(int* p_mode, char symbol, StackType our_stack, 
					QueueType our_queue);
int para_mode=0;
//bool** address;
int main()
{
	//bool decide = false;
	//para_mode = &decide;
	
	//Getting arithmetic expression from the user
	//string input=getting_input();
	string input="3+4*2/(1-5)^2^3";
	
	//string input;
	//cout << "Enter the expression: " << endl;
	//cin >> input;
	int length_input=input.length();
	QueueType output_queue;
	StackType operator_stack;
	
	string a;
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
			if(temp=='(')
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
							if (temp == '^' && top == '^')
								operator_stack.Push(a);
							else if (check_precedence(temp,top))
								operator_stack.Push(a);
							else
							{
								string from_stack=operator_stack.Pop();
								output_queue.Enqueue(from_stack);
								operator_stack.Push(a);
							}	
						}
					}
					i++;
				}
				i--;

				string x="";
				operator_stack.Pop();
						
				while (true)
				{
					x=operator_stack.Pop();
					cout << endl;
					cout << "x are " << x;
					if (x=="(")
						break;
					output_queue.Enqueue(x);
				}
			}

			else if (k==0)
			{
				operator_stack.Push(a);
				cout << a << endl;
				k=1;
			}
			

			else
			{
				char top=operator_stack.Top()[0];
				cout << temp << endl;
				if(temp=='^' && top=='^')
				{
					operator_stack.Push(a);
				}
				else if (check_precedence(temp,top))
				{
					operator_stack.Push(a);
				}
				else
				{

					string from_stack=operator_stack.Pop();
					//cout << "From stack is " << from_stack;
					output_queue.Enqueue(from_stack);
					operator_stack.Push(a);
					cout << "A is: " << a;
				}
			}	

						
		}
		//cout<<a<<endl;
	}

	while (!operator_stack.IsEmpty())
		{
			string w = operator_stack.Pop();
			output_queue.Enqueue(w);
		}

	cout << endl;
	cout << endl;

	string RPN;
	while(!output_queue.IsEmpty())
	{
		string h=output_queue.Dequeue();
		RPN = RPN + h;
		//cout<<h;
	}
	cout << "RPN is: " << RPN << endl;

	return 0;

}

/*
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


