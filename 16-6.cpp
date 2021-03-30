#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MIN_PER_HR=60;

class Customer{
private:
	long arrive;//����ʱ�� 
	int processtime;//����ʱ�� 
public:
	Customer() {arrive=processtime=0;}//��ʼ��һ���չ˿� 
	void set(long when); //���ô���ʱ��Ϊ1-3���ӣ�����ʱ��Ϊwhen 
	long when() const {return arrive;}//��ʱ���� 
	int ptime() const {return processtime;}//����ʱ�� 
	
};

void Customer::set(long when)
{
	processtime =rand()%3+1;
	arrive=when; 
}

bool newcustomer(double x)
{
	return (rand()*x/RAND_MAX<1);
}


int main(int argc, char** argv) {
	
	srand(time(0));
	cout<<"�������飺Heather���е�ATM\n";
	cout<<"����������Ŷӳ���: ";
	int qs;
	cin>>qs;
	
	queue<Customer> line;
	
	
	cout<<"��СʱΪ��λ������ģ��ʱ��: ";
	int hours;
	cin>>hours;
	long cyclelimit=MIN_PER_HR*hours;
	
	cout<<"����ÿСʱƽ������λ�˿��Ŷ�: ";
	double perhour;
	cin>>perhour;
	double min_per_cust=MIN_PER_HR/perhour;
	
	Customer temp;
	long turnaways=0;
	long customers=0;
	long served=0;
	long sum_line=0;
	int wait_time=0,wait_time2=0;
	long line_wait=0;


	for(long cycle=0;cycle<cyclelimit;cycle++)
	{
		if(newcustomer(min_per_cust))
		{
			if(line.size()==qs) 
				turnaways++;
			else
			{	
				customers++;
				temp.set(cycle);
				line.push(temp);
			}
		}

		if(wait_time<=0&&!line.empty())
		{
			temp=line.front();
			line.pop();
			wait_time=temp.ptime();
			line_wait+=cycle-temp.when();
			served++;
		}
		
		if(wait_time>0)
			wait_time--;
		sum_line+=line.size();
	}
	if(customers>0)
	{
		cout<<"�����˿�λ��: "<<customers<<endl;
		cout<<"�Ӵ��˿�λ��: "<<served<<endl;
		cout<<"������̫����·�Ĺ˿�λ��: "<<turnaways<<endl;
		cout<<"ƽ�����鳤��: ";
		cout.precision(2);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout<<(double)sum_line/cyclelimit<<endl;
		cout<<"ƽ���Ŷ�ʱ��: "<<(double)line_wait/served<<"����\n";
	}
	else
		cout<<"û�й˿ͣ�\n";
	cout<<endl;


	cout<<"���ģ��"<<endl;
	
	return 0;
}
