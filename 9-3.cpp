#include <iostream>
#include <cstring>
#include <new>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct chaff{
	char dross[20];
	int slag; 
};
	char buffer[500];
int main(int argc, char** argv) {
	chaff *p1,*p2;
	
	p1=new chaff[2];
	p2=new (buffer) chaff[2];
	for(int i=0;i<2;i++){
		cout<<"enter #"<<i+1<<" chaff`s dross: ";
		cin.getline(p1[i].dross,20);
		strcpy(p2[i].dross,p1[i].dross);
		cout<<"enter #"<<i+1<<" chaff`s slag: ";
		cin>>p1[i].slag;
		cin.get();
		p2[i].slag=p1[i].slag;
	}
	for(int i=0;i<2;i++){
		cout<<"\n#"<<i+1<<" chaff in heap:\n dross: "<<p1[i].dross<<" at "<<&p1[i].dross<<"\n slag: "<<p1[i].slag<<" at "<<&p1[i].slag<<endl;
		cout<<"\n#"<<i+1<<" chaff in buffer:\n dross: "<<p2[i].dross<<" at "<<&p2[i].dross<<"\n slag: "<<p2[i].slag<<" at "<<&p2[i].slag<<endl;

	}
	return 0;
}
