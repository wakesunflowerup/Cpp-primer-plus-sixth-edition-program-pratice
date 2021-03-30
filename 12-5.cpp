#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_PER_HR=60;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
typedef Customer Item;

class Queue{
private:
	struct Node{
		Item item;
		struct Node *next;
	};
	enum {Q_SIZE=10};
	Node *front;//���е�һ�� ��ָ�� 
	Node *rear;//�������һ�� ��ָ�� 
	int items;// �ڶ����еĹ˿���items��
	const int qsize;//��������Ĺ˿Ͷ�����󳤶�Ϊqsize 
	Queue(const Queue & q):qsize(0) { }//����Ϊ˽�к�������ֹ�� Queue�� ���� ���п�����=��ֵ 
	Queue & operator=(const Queue & q) {return *this;}//ͬ�� 
public:
	Queue(int qs=Q_SIZE);//��qsize����Ϊqs���������˿�����Ĭ��ΪQ_SIZE=10 
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item &item);//��item�������β 
	bool dequeue(Item &item);//ȡ�����ף�����item 
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
Queue::~Queue()//�����в�Ϊ��ʱ�����׵�ָ�򸳸�temp�������׳��� 
{
	Node *temp;//����ָ����һ���ڵ㣬ɾ����һ��ʼ�Ķ���ָ����ͬ��ַ��temp 
	while(front!=nullptr)//��ɾ������ 
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
	cout<<"�������飺Heather���е�ATM\n";
	cout<<"����������Ŷӳ���: ";
	int qs;
	cin>>qs;

//	cout<<"��СʱΪ��λ������ģ��ʱ��: ";
//	int hours;
//	cin>>hours;
//	long cyclelimit=MIN_PER_HR*hours;
	
//	cout<<"����ÿСʱƽ������λ�˿��Ŷ�: ";
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
	cout<<"ÿСʱƽ������˿�λ��: "<<perhour<<endl;;
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
		cout<<"�����˿�λ��: "<<customers<<endl;
		cout<<"�Ӵ��˿�λ��: "<<served<<endl;
		cout<<"������̫����·�Ĺ˿�λ��: "<<turnaways<<endl;
		cout<<"ƽ�����鳤��: ";
		cout.precision(2);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout<<(double)sum_line/cyclelimit<<endl;
		per=1.0*line_wait/served;
		cout<<"ƽ���Ŷ�ʱ��: "<<per<<"����\n";
	}
	else
		cout<<"û�й˿ͣ�\n";
	cout<<endl;

}
	cout<<"���ģ��"<<endl;
	return 0;
}
