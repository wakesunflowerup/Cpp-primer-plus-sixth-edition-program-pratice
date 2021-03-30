#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef unsigned long Item;
class Stack{
private:
	enum{MAX=10};
	Item * pitems;
	int size;
	int top;
public:
	Stack(int n=MAX);
	Stack(const Stack &st);
	~Stack();
	bool isempty()const;
	bool isfull()const;
	bool push(const Item & item);
	bool pop(Item &item);
	Stack & operator=(const Stack &st);
	
};
Stack::Stack(int n)
{
	size=n;
	top=n;
	pitems=new Item[n];
	for(int i=0;i<n;i++)
	{
		pitems[i]=0;
	}
}
Stack::Stack(const Stack &st)
{
	size=st.size;
	top=st.top;
	pitems=new Item[st.size];
	for(int i=0;i<st.size;i++)
	{
		pitems[i]=st.pitems[i];
	}
}
Stack::~Stack()
{
	delete [] pitems;
}
bool Stack::isempty()const
{
	return top==0;
}
bool Stack::isfull()const
{
	return top==MAX;
}
bool Stack::push(const Item &item)
{
	if(top<MAX)
	{
		Item * temp=new Item[size+1];
		for(int i=0;i<size;i++)
		{
			temp[i]=pitems[i];
		}
		delete [] pitems;
		pitems=new Item[size+1];
		for(int i=0;i<size;i++)
		{
			pitems[i]=temp[i];
		}
		delete [] temp;
		size++;
		pitems[top++]=item; 
		return true;
	}
	else 
		return false;
}
bool Stack::pop(Item &item)
{
	if(top>0)
	{
		item=pitems[--top];
		size--;
		Item * temp=new Item[size];
		for(int i=0;i<size;i++)
		{
			temp[i]=pitems[i];
		}
		delete [] pitems;
		pitems=new Item[size];
		for(int i=0;i<size;i++)
		{
			pitems[i]=temp[i];
		}
		delete [] temp; 
		return true;
	}
	else 
		return false;
}
Stack & Stack::operator=(const Stack &st)
{
	size=st.size;
	top=st.top;
	delete [] st.pitems;
	pitems=new Item[st.size];
	for(int i=0;i<st.size;i++)
	{
		pitems[i]=st.pitems[i];
	}
}
int main(int argc, char** argv) {
	Stack a(7);
	a.push(1);
	a.push(5);
	a.push(8);
	if(a.isfull())
		cout<<"full\n";
	unsigned long n;
	
	a.pop(n);
	cout<<n<<endl;
	a.pop(n);
	cout<<n<<endl;
	
	
	Stack b=a;
	Stack c;
	b.pop(n);
	b.push(14);
	b.push(20);
	b.push(76);
	if(b.isfull())
		cout<<"b is full\n";
	c=b;
	c.pop(n);
	cout<<n<<endl;
	for(int i=0;i<9;i++)
		{
			c.pop(n);
			cout<<n<<endl;
		}
	cout<<n<<endl;
	if(c.isempty())
		cout<<"c is empty"<<endl;
	return 0;
}
