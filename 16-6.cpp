#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MIN_PER_HR=60;

class Customer{
private:
	long arrive;//到达时间 
	int processtime;//处理时间 
public:
	Customer() {arrive=processtime=0;}//初始化一个空顾客 
	void set(long when); //设置处理时间为1-3分钟，到达时间为when 
	long when() const {return arrive;}//何时到达 
	int ptime() const {return processtime;}//处理时间 
	
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
	cout<<"案例调查：Heather银行的ATM\n";
	cout<<"请输入最大排队长度: ";
	int qs;
	cin>>qs;
	
	queue<Customer> line;
	
	
	cout<<"以小时为单位，输入模拟时间: ";
	int hours;
	cin>>hours;
	long cyclelimit=MIN_PER_HR*hours;
	
	cout<<"输入每小时平均多少位顾客排队: ";
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
		cout<<"来到顾客位数: "<<customers<<endl;
		cout<<"接待顾客位数: "<<served<<endl;
		cout<<"看队伍太长跑路的顾客位数: "<<turnaways<<endl;
		cout<<"平均队伍长度: ";
		cout.precision(2);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout<<(double)sum_line/cyclelimit<<endl;
		cout<<"平均排队时间: "<<(double)line_wait/served<<"分钟\n";
	}
	else
		cout<<"没有顾客！\n";
	cout<<endl;


	cout<<"完成模拟"<<endl;
	
	return 0;
}
