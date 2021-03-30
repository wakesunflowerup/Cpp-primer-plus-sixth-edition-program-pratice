#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef int Type;
class List{
private:
	enum{MAX=10};
	Type m_type[MAX];
	int top;
public:
	List();
	bool isempty()const;
	bool isfull()const;
	bool push(const Type & type);
	void visit(void (*pf)(Type & type));
	
};
List::List()
{
	top=0;
}
bool List::isempty()const
{
	return top==0;
}
bool List::isfull()const
{
	return top==MAX;
}
bool List::push(const Type &type)
{
	if(top<MAX)
	{
		m_type[top++]=type;
		return true;
	}
	else 
		return false;
}
void List::visit(void (*pf)(Type & type))
{
	for(int i=0;i<top;i++)
	{
		(*pf)(m_type[i]);
	}
}
void show(Type &type)
{
	cout<<type<<" ";
}
void add(Type &type)
{
	type+=1;
}
int main(int argc, char** argv) {
	List l;
	if(l.isempty())
		cout<<"isempty.\n";
	l.push(1);
	l.push(2);
	l.push(3);
	l.push(4);
	l.push(5);
	l.push(6);
	l.push(7);
	l.push(8);
	l.push(9);
	l.push(10);
	if(l.isfull())
		cout<<"isfull.\n";
	l.visit(show);
	cout<<endl;
	
	l.visit(add);
	l.visit(show);
	cout<<endl; 
	return 0;
}
