#define STACK_CAPACITY 1000
class Stack
{
	private:
		char stack[STACK_CAPACITY];
		int index;
	public:
		Stack() //constructor for a stacik
		{
			index = 0;
		}
		void push(char c)//adds c to the top of the stack
		{
			if (index < STACK_CAPACITY)
			{
				stack[index] = c;
				index++;
			}
		}
		char pop()//removes top element, returns it
		{
			if (index > 0)
			{
				index--;
				char ret = stack[index];
				stack[index] = char(0);
				return ret;
			}
		}
		char top()//returns the top element, w/o removing
		{
			return stack[index-1];
		}
		bool isEmpty() //returns true iff the stack is empty
		{
			if (index==0)
			{
				return true;
			}
			return false;
		}
		bool isFull()//returns true iff the stack is full
		{
			return (index == STACK_CAPACITY + 1);
		}
		~Stack()//destructor for a stack
		{
			//delete[] stack;
		}
};
