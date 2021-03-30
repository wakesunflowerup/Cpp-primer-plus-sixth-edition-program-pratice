#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_PER_HR=60;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
typedef Customer Item;

class Queue{
private:
	struct Node{
		Item item;
		struct Node *next;
	};
	enum {Q_SIZE=10};
	Node *front;//队列第一名 的指针 
	Node *rear;//队列最后一名 的指针 
	int items;// 在队列中的顾客有items个
	const int qsize;//超市允许的顾客队列最大长度为qsize 
	Queue(const Queue & q):qsize(0) { }//设置为私有函数，阻止对 Queue类 对象 进行拷贝和=赋值 
	Queue & operator=(const Queue & q) {return *this;}//同上 
public:
	Queue(int qs=Q_SIZE);//将qsize设置为qs即队列最多顾客数，默认为Q_SIZE=10 
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item &item);//将item添加至队尾 
	bool dequeue(Item &item);//取出队首，赋给item 
};


void Customer::set(long when)
{
	processtime =rand()%3+1;
	arrive=when; 
}

Queue::Queue(int qs):qsize(qs)
{
	front=rear=nullptr;
	items=0;
}
Queue::~Queue()//当队列不为空时将队首的指向赋给temp，将队首出队 
{
	Node *temp;//队首指向下一个节点，删除与一开始的队首指向相同地址的temp 
	while(front!=nullptr)//即删除队首 
	{
		temp=front;
		front=front->next;
		delete temp;
	}
}
bool Queue::isempty() const
{
	return items==0;
} 
bool Queue::isfull() const
{
	return items==qsize;
}
int Queue::queuecount() const
{
	return items;
}
bool Queue::enqueue(const Item &item)
{
	if(isfull())
		return false;
	Node * add=new Node;
	add->item=item;
	add->next=nullptr;
	items++;
	if(front==nullptr)
		front=add;
	else
		rear->next=add;
	rear=add;
	return true;
}
bool Queue::dequeue(Item &item)
{
	if(front==nullptr)
		return false;
	item=front->item;
	items--;
	Node * temp=front;
	front=front->next;
	delete temp;
	if(items==0)
		rear=nullptr;
	return true; 
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

//	cout<<"以小时为单位，输入模拟时间: ";
//	int hours;
//	cin>>hours;
//	long cyclelimit=MIN_PER_HR*hours;
	
//	cout<<"输入每小时平均多少位顾客排队: ";
//	double perhour;
//	cin>>perhour;
//	double min_per_cust=MIN_PER_HR/perhour;
	int hours=10;
	long cyclelimit=MIN_PER_HR*hours;	
	double perhour=10;
	double per=0;
while(perhour++&&per<=1)
{
	Queue line(qs);
	Queue line2(qs);
	Item temp;
	long turnaways=0;
	long customers=0;
	long served=0;
	long sum_line=0;
	int wait_time=0,wait_time2=0;
	long line_wait=0;
	cout<<"每小时平均到达顾客位数: "<<perhour<<endl;;
	double min_per_cust=MIN_PER_HR/perhour;
	for(long cycle=0;cycle<cyclelimit;cycle++)
	{
		if(newcustomer(min_per_cust))
		{
			if(line.isfull()&&line2.isfull()) 
				turnaways++;
			else
			{
				
				if(line.queuecount()<=line2.queuecount())
				{
					customers++;
					temp.set(cycle);
					line.enqueue(temp);
				}
				else
				{
					customers++;
					temp.set(cycle);
					line2.enqueue(temp);
				}
			}
		}
		
		if(wait_time<=0&&!line.isempty())
		{
			line.dequeue(temp);
			wait_time=temp.ptime();
			line_wait+=cycle-temp.when();
			served++;
		}
		
		if(wait_time2<=0&&!line2.isempty())
		{
			line2.dequeue(temp);
			wait_time2=temp.ptime();
			line_wait+=cycle-temp.when();
			served++;
		}
		if(wait_time>0)
			wait_time--;
		if(wait_time2>0)
			wait_time2--;
		sum_line+=line.queuecount();
		sum_line+=line2.queuecount(); 
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
		per=1.0*line_wait/served;
		cout<<"平均排队时间: "<<per<<"分钟\n";
	}
	else
		cout<<"没有顾客！\n";
	cout<<endl;

}
	cout<<"完成模拟"<<endl;
	return 0;
}
