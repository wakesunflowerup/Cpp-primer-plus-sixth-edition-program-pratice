#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct candybar{
	char * brand;
	double weight;
	int cal;
};

void set(candybar & can,char * ch="millennium munch",double d=2.85,int i=350); 

void show(const candybar & can);

int main(int argc, char** argv) {
	char a[255];
	double b;
	int c;
	candybar s;
	cout<<"enter the brand: ";
	cin.getline(a,255);
	cout<<"enter the weight: ";
	cin>>b;
	cout<<"enter the cal: ";
	cin>>c;
	set(s);
	show(s);
	set(s,a,b,c);
	show(s);
	return 0;
}

void set(candybar & can, char * ch, double d, int i){
	can.brand=ch;
	can.weight=d;
	can.cal=i;
}

void show(const candybar & can){
	cout<<can.brand<<endl;
	cout<<can.weight<<endl;
	cout<<can.cal<<endl;
}
