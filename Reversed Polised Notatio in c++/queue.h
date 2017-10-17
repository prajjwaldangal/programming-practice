
#include <iostream>
using namespace std;
class QueueType
{
	private:
		int head,tail;
		int MAX_SIZE,MAX;
		string *queue;
	public:
		QueueType()
		{
			MAX=100;
			MAX_SIZE=MAX+1;
			head=MAX_SIZE-1;
			tail=MAX_SIZE-1;
			
			queue=new string[MAX_SIZE];
		}

		bool IsEmpty()
		{
			return(head==tail);
		}

		bool IsFull()
		{
			return((tail+1)%MAX_SIZE==head);
		}

		void Enqueue(string ch)
		{
			if (!IsFull())
        	{
        		tail=(tail+1)%MAX_SIZE;
    			queue[tail]=ch;
    			
        	}
		}

		string Dequeue()
		{
			if (!IsEmpty())
        	{
        		
        		head=(head+1)%MAX_SIZE;
    			string item=queue[head];
    			return item;
        	}
		}


		~QueueType() {
            delete[] queue;
      }
};



/**

//#include "stack.cpp"
//#include "queue.cpp"
//#include "stack.h"
//#include "queue.h"
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

//void stack_queue(char temp, StackType &our_stack, QueueType &queue, string a);
	//cout << "Enter the expression: " << endl;
	//cin >> input;
	
//bool** address;
int main()
{
	//Getting arithmetic expression from the user
	//string input=getting_input();
	cout << "Hello world";
	string input="3+4*2/(1-5)^2^3";
	cout << input;
	
	// std::queue <string> output_queue;
	// std::stack <string> operator_stack;

	std::queue <char> output_queue;
	std::stack <char> operator_stack;

	//QueueType <string> output_queue;
	//StackType <string> operator_stack;

	//StackType operator_stack;

	//string input = "(3-5)/5*7-(2-5)";
	
	//string a("");
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

	//gdb brk pts 45, 68, 73p


	cout << endl;
	cout << endl;

	string RPN;
	int counter = 0;
	
	//while(!output_queue.empty())
	while(counter < 100)
	{
		//string h=output_queue.front();
		char h = output_queue.front();
		operator_stack.pop();
		//RPN = RPN + h;
		cout << h;
		counter++;
	}
	cout << "RPN is: " << RPN << endl;

	//cout << output_queue;

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

//void stack_queue(char temp, std::stack <StackType> &our_stack, 
//					std::queue <QueueType> &our_queue, string a)

//void stack_queue(char temp, std::stack <string> &our_stack, 
//					std::queue<string> &our_queue, string a)
void stack_queue(char temp, std::stack <char> &our_stack, 
					std::queue <char> &our_queue, char a)
{
	//string x = "";
	char x;

	if (isdigit(temp))
		our_queue.push(a);

	else{

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
			//top1 = our_stack.top()[0];
			//top1 = our_stack.top();
			//if (top1 != '(')

			if (!our_stack.empty() && our_stack.top()!='(')
			{
				top1 = our_stack.top();
				if (temp=='^' && top1=='^')
				{
					our_stack.push(a);
				}
				else if(check_precedence(temp, top1))
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



/**		if (isdigit(temp))
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
	}**/


**/
