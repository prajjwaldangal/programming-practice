
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


