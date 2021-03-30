#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Cd{
private:
	char * performers;
	char * label;
	int selections;
	double playtime;
public:
	Cd(char * s1,char * s2,int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();	
	virtual void Report() const;
	Cd & operator=(const Cd & d);
}; 

class Classic:public Cd{
private:
	char * album;
public:
	Classic(char * s1,char * s2, char * s3,int n,double x);
	Classic(char * s1,Cd &d);
	Classic(const Classic & c);
	Classic();
	~Classic();
	virtual void Report() const;
	Classic & operator=(const Classic & c);	
};

Cd::Cd(char * s1,char * s2,int n, double x)
{
	performers=new char[strlen(s1)+1];
	label=new char[strlen(s2)+1];
	strcpy(performers,s1);
	strcpy(label,s2);
	selections=n;
	playtime=x;
}
Cd::Cd(const Cd &d)
{
	performers=new char[strlen(d.performers)+1];
	label=new char[strlen(d.label)+1];
	strcpy(performers,d.performers);
	strcpy(label,d.label);
	selections=d.selections;
	playtime=d.playtime;	
}
Cd::Cd()
{
	performers=new char[1];
	label=new char[1];
	performers[0]='\0';
	label[0]='\0';
	playtime=0;
}
Cd::~Cd()
{
	delete [] performers;
	delete [] label;
}
void Cd::Report() const
{
	cout<<"\nPerformers: "<<performers;
	cout<<"\nLabel: "<<label;
	cout<<"\nSelections: "<<selections;
	cout<<"\nPlaytime: "<<playtime<<endl;
}
Cd & Cd::operator=(const Cd & d)
{
	if(this==&d)
		return *this;
	delete [] performers;
	delete [] label;
	performers=new char[strlen(d.performers)+1];
	label=new char[strlen(d.label)+1];
	strcpy(performers,d.performers);
	strcpy(label,d.label);
	selections=d.selections;
	playtime=d.playtime;
	return *this; 
}

Classic::Classic(char * s1,char * s2, char * s3,int n,double x):Cd(s2,s3,n,x)
{
	album=new char[strlen(s1)+1];
	strcpy(album,s1);
}
Classic::Classic(char * s1,Cd &d):Cd(d)
{
	album=new char[strlen(s1)+1];
	strcpy(album,s1);
}
Classic::Classic(const Classic &c):Cd(c)
{
	album=new char[strlen(c.album)+1];
	strcpy(album,c.album);
}
Classic::Classic():Cd()
{
	album=new char[1];
	album[0]='\0';
}
Classic::~Classic()
{
	delete [] album;
}
void Classic::Report() const
{
	Cd::Report();
	cout<<"Album: "<<album<<endl<<endl;
}
Classic & Classic::operator=(const Classic &c)
{
	if(this==&c)
		return *this;
	Cd::operator=(c);
	delete [] album;
	album=new char[strlen(c.album)+1];
	strcpy(album,c.album);
	return *this;
}

void Bravo(const Cd & disk)
{
	disk.Report();
} 

int main(int argc, char** argv) {
	Cd c1("Beatles","Capitol",14,35.5);
	Classic c2=Classic("Piano Sonata in B flat, Fantasia in C","Alfred Brendel","Philips",2,57.17);
	Cd *pcd=&c1;
	
	cout<<"Using object directly:\n";
	c1.Report();
	c2.Report();
	
	cout<<"Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd=&c2;
	pcd->Report();
	
	cout<<"Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	
	cout<<"Testing assignment: ";
	Classic copy;
	copy=c2;
	copy.Report();
	
	return 0;
}
