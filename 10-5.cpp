#include <iostream>

typedef cus Item; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct cus{
	char name[35];
	double payment;
};
class stack{
private:
	enum {MAX=10};
	Item item[MAX];
	int top;
public:
	stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item &item);
	bool pop(Item &item);
};
	stack::stack()
	{
		top=0;
	}
	bool isempty() const
	{
		return top==0;
	}
	bool isfull() const
	{
		return top==MAX;
	}
	bool push(const Item &item)
	{
		if(top<MAX)
		{
			item[top++]=item;
			return true; 
		}
		else
			return false;
	}
	bool pop(Item &item)
	{
		if(top>0)
		{
			item=stems[--top];
			return true;
		}
		else
			return false;
	}

int main(int argc, char** argv) {
	
	return 0;
}
