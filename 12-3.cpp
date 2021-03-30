#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Stock{
private:	
	char * company;
	int shares;
	double share_val;
	double total_val;
	void set_tot(){total_val=shares*share_val;}
public:
	Stock();
	Stock(const char * ch,long n=0,double pr=0.0);
	~Stock();
	void buy(long num,double price);
	void sell(long num,double price);
	void update(double price);
	friend ostream & operator<<(ostream &os,const Stock &s);
	const Stock & topval(const Stock &s)const;
};

Stock::Stock()
{
	static char *s="no name";
	company=new char[strlen(s)+1];
	strcpy(company,s);
	shares=0;
	share_val=0.0;
	set_tot();
}
Stock::Stock(const char * ch,long n,double pr)
{
	company=new char[strlen(ch)+1];
	strcpy(company,ch);
	shares=n;
	share_val=pr;
	set_tot();
}
Stock::~Stock()
{
	delete [] company;
}
void Stock::buy(long num,double price)
{
	shares+=num;
	share_val=price;
	set_tot();
}
void Stock::sell(long num,double price)
{
	shares-=num;
	share_val=price;
	set_tot();
}
void Stock::update(double price)
{
	share_val=price;
	set_tot();
}
ostream & operator<<(ostream &os,const Stock &s)
{
	ios_base::fmtflags orig=os.setf(ios_base::fixed,ios_base::floatfield);
	streamsize prec=os.precision(3);
	os<<"Company: "<<s.company<<"  Shares: "<<s.shares<<'\n';
	os<<" Share price: $"<<s.share_val;
	os.precision(2);
	os<<" Total worth: $"<<s.total_val<<'\n';
	os.setf(orig,ios_base::floatfield);
	os.precision(prec);
	return os; 
}
const Stock & Stock::topval(const Stock &s)const
{
	return (s.total_val>total_val?s:*this);
}


const int STKS=4;
int main(int argc, char** argv) {
	Stock stocks[STKS]={{"NanoSmart",12,20.0},{"Boffo Objects",200,2.0},{"Monolithic Ibelisks",130,3.25},{"Fleep Enterprises",60,6.5}};
	cout<<"Stock holdings:\n";
	int st;
	for(st=0;st<STKS;st++)
		cout<<stocks[st];
	const Stock *top=&stocks[0];
	for(st=1;st<STKS;st++)
		top=&top->topval(stocks[st]);
	cout<<"\nMost valuable holding:\n";
	cout<<*top;
	return 0;
}
