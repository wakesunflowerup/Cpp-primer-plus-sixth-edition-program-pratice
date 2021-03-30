#include <iostream>
#include <string>
#include <valarray>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//没用到重载运算符啊？？？ 
template <class T1,class T2> 
class Pair{
private:	
	T1 a;
	T2 b;
public:
	T1 & first() {return a;}  
	T2 & second() {return b;} 
	T1 first() const {return a;}
	T2 second() const {return b;}
	Pair(const T1 &aval,const T2 &bval) : a(aval),b(bval) {}
	Pair() {}	
};

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt,ArrayInt> PairArray;


class Wine : private PairArray,private string{
private:
//	string name;
//	PairArray storage;
	int years;
public:
	Wine(const char * l,int y,const int yr[],const int bot[]);
	Wine(const char * l,int y);
	void GetBottles();
	void Show();
	const string & Label() { return (const string &)(*this); }
	int sum(){ return (PairArray::second()).sum(); }
};

Wine::Wine(const char * l,int y,const int yr[],const int bot[]) : string(l),PairArray(ArrayInt(yr,y),ArrayInt(bot,y))
{
	years=y;
}
Wine::Wine(const char * l,int y) : string(l),PairArray(ArrayInt(y),ArrayInt(y))
{
	years=y;
}
void Wine::GetBottles()
{
	cout<<"Enter "<<(const string &)(*this)<<" data for "<<years<<" year(s): \n";
	for(int i=0;i<years;i++)
	{
		cout<<"Enter years: ";
		cin>>(PairArray::first())[i];
		cout<<"Enter bottles for that year: ";
		cin>>(PairArray::second())[i];
	}
}
void Wine::Show()
{
	cout<<"Wine: "<<(const string &)(*this);
	cout<<"\n\tYear\tBottles";
	for(int i=0;i<years;i++)
	{
		cout<<"\n\t"<<(PairArray::first())[i]<<"\t"<<(PairArray::second())[i];
	}
	cout<<endl;
}



int main(int argc, char** argv) {
	
	cout<<"Enter name of wine: ";
	char lab[50];
	cin.getline(lab,50);
	cout<<"Enter number of years: ";
	int yrs;
	cin>>yrs;
	
	Wine holding(lab,yrs);
	holding.GetBottles();
	holding.Show();
	
	const int YRS=3;
	int y[YRS]={1993,1995,1998};
	int b[YRS]={48,60,72};
	
	Wine more("Gushing Grape Red",YRS,y,b);
	more.Show();
	cout<<"Total bottles for "<<more.Label()<<": "<<more.sum()<<endl;
	cout<<"bye\n";
	return 0;
}
