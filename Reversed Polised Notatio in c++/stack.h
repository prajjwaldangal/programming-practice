
#include <string>
#include <iostream>
using namespace std;
class StackType
{
	private:
		int current_index;
		int max_item;
		string *stack;
	public:
		StackType()
		{
			current_index=-1;
			max_item=100;
			stack=new string[max_item];
		}

		void Push(string character)
		{
			current_index++;
			stack[current_index]=character;
	
		}

		int Length()
		{
			return current_index;
		}

		string Pop()
		{
			if (current_index!=-1)
			{
				int temp=current_index;
				current_index--;
				return stack[temp];
			}

		}

		string Top()
			{

				if (current_index!=-1)
				{
					
					return stack[current_index];
				}
			}

		bool IsEmpty()
			{
				return current_index==-1;
			}

		~StackType() {
            delete[] stack;
      }
};


