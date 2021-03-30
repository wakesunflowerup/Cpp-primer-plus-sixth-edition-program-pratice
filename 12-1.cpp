#include <iostream>
#include <cstring> 
using namespace std;
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Cow{
	char name[20];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char *nm,const char *ho,double wt);
	Cow(const Cow &c);
	~Cow();
	Cow & operator=(const Cow & c);
	void showCow()const;
};
Cow::Cow()
{
	name[0]='\0';
	hobby=nullptr;
	weight=0;
}
Cow::Cow(const char *nm,const char *ho,double wt)
{
	strcpy(name,nm);
	hobby=new char[strlen(ho)+1];
	strcpy(hobby,ho);
	weight=wt;
}
Cow::Cow(const Cow &c)
{
	strcpy(name,c.name);
	hobby=new char[strlen(c.hobby)+1];
	strcpy(hobby,c.hobby);
	weight=c.weight;
}
Cow::~Cow()
{
	delete [] hobby;
}
Cow & Cow::operator=(const Cow & c)
{
	if(this==&c)
		return *this;
	strcpy(name,c.name);
	delete [] hobby;
	hobby=new char[strlen(c.hobby)+1];
	strcpy(hobby,c.hobby);
	weight=c.weight;
	return *this;
} 
void Cow::showCow()const
{
	cout<<"name: "<<name<<"\nhobby: "<<hobby<<"\nweight: "<<weight<<endl;
}

int main(int argc, char** argv) {
	Cow a;
	Cow b("sunflower","wakeup",250);
	Cow c=Cow(b);
	a=c;
	a.showCow();
	b.showCow();
	c.showCow(); 
	
	
	return 0;
}
