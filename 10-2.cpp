#include <iostream>
#include <string>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Person{
private:
	static const int LIMIT=25;
	string lname;
	char fname[LIMIT];
public:
	Person();
	Person(const string &ln,const char * fn="heyyou");
	void show() const;
	void Formalshow() const;
	
};
Person::Person()
{
	lname="";
	fname[0]='\0';
}
Person::Person(const string &ln,const char * fn)
{
	lname=ln;
	strcpy(fname,fn);
}
void Person::show() const
{
	cout<<fname<<" "<<lname<<endl;
}
void Person::Formalshow() const
{
	cout<<lname<<" "<<fname<<endl;
}
int main(int argc, char** argv) {
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy","Sam");
	one.show();
	cout<<endl;
	one.Formalshow();
	cout<<endl;
	two.show();
	cout<<endl;
	two.Formalshow();
	cout<<endl;
	three.show();
	cout<<endl;
	three.Formalshow();
	cout<<endl;
	return 0;
}
