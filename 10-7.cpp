#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Plorg{
private:
	char m_name[20];
	int m_CI;
public:
	Plorg();
	Plorg(const char * name,const int CI);
	void changeCI(const int CI);
	void showp()const;
	 
};
Plorg::Plorg()
{
	strcpy(m_name,"Plorga");
}
Plorg::Plorg(const char *name,const int CI)
{
	strcpy(m_name,name);
	m_CI=CI;
}
void Plorg::changeCI(const int CI)
{
	m_CI=CI;
}
void Plorg::showp()const
{
	cout<<"name: "<<m_name<<"\nCI: "<<m_CI<<endl;
}


int main(int argc, char** argv) {
	Plorg p1;
	Plorg p2=Plorg("sunflower",5);
	Plorg p3("newbee",3);
	Plorg p4{"ACE",4};
	p1.showp();
	p2.showp();
	p3.showp();
	p4.showp();
	p1.changeCI(2);
	p1.showp();
	return 0;
}
