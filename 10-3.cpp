#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int Len=40;
class golf{
public:
	char m_fullname[Len];
	int m_handicap;

	golf(char * name,int hc);
	golf();
	void setgolf();
	bool isempty();
	void handicap(const int hc);
	void showgolf() const;
};

golf::golf(char * name,int hc)
{
	strcpy(m_fullname,name);
	m_handicap=hc;
}
golf::golf()
{
	
}
void golf::setgolf()
{
	cout<<"please enter the fullname of golf(if u enter nothing,program will be terminated.): ";
	cin.getline(m_fullname,Len);
	cout<<"please enter the handicap of golf: ";
	cin>>m_handicap;
	
}
bool golf::isempty()
{
	if(!strcmp(m_fullname,""))
		return false;
	else
		return true;
		
}
void golf::handicap(const int hc)
{
	m_handicap=hc;
}

void golf::showgolf() const
{
	cout<<"golf`s fullname: "<<m_fullname<<endl;
	cout<<"golf`s handicap: "<<m_handicap<<endl; 
}


int main(int argc, char** argv) {
//	golf gog[5];
//	golf g;
//	int i=0;
//	int cho,hc;
//	char * ch="asd";
//	int in=2;
//	while(i<5){
//		g.setgolf();
//		if(g.isempty()) 
//		{
//			gog[i].golf(ch,in);
//			gog[i].showgolf();
//	
//			cout<<"do you want to change handicap of golf?\n"
//					"1.yes"		"2.no\n";
//			cin>>cho;
//			cin.get();
//			if(cho==1)
//			{
//				cout<<"enter the handicap: ";
//				cin>>hc;
//				cin.get();
//				gog[i].handicap(hc);
//				gog[i].showgolf();
//			}
//		}
//		else
//			break;
//		if(i<4)
//			i++;
//		else{
//			cout<<"you have entered enough information of golf,program terminated.\n";
//			break;
//		}
//		
//	}
	golf g;
	g.golf()
	return 0;
}
