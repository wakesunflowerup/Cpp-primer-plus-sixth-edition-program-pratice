#include <iostream>
#include <cstring>
#include "14-3workermi.h"
#include "14-3queuetp.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int SIZE=5;

int main(int argc, char** argv) {
	
	QueueTP<Worker * > lolas(SIZE);

	Worker * in[SIZE];//入队的指针 
	Worker * out[SIZE];//出队的指针，放在下面输出的位置让其大小为ct更节省空间 
	 
	int ct;
	
	for(ct=0;ct<SIZE;ct++)
	{
		char choice;
		cout<<"Enter the employee category:\nw:waiter\ts:singer\tt:singing waiter\tq:quit\n";
		cin>>choice;
		while(strchr("wtsq",choice)==nullptr)
		{
			cout<<"Please enter just w, s, t, or q for once: ";
			cin>>choice;
		}
		if(choice=='q')
			break;
		switch(choice)//根据不同输入创建新的Worker指针，指向对应派生类 
		{
			case 'w':	in[ct]=new Waiter; 
						break;
			case 's':	in[ct]=new Singer;
						break;
			case 't':	in[ct]=new SingingWaiter;
						break; 
		}
		while(cin.get()!='\n')
			continue;
		in[ct]->Set();//对该Wrker指针指向的派生类进行设置
		lolas.enqueue(in[ct]);//入队 	 
	} 
	
	cout<<"\nHere is your staff:\n";
	
	for(int i=0;i<ct;i++)
	{ 
		lolas.dequeue(out[i]);
		out[i]->Show();
		cout<<endl; 
		delete out[i];//也可以写成in[i]，指向的地址都一样
		//人走茶凉，该指针已经完成了历史使命，可以释放掉了所占空间了 
	}
	
	cout<<"bye\n";
	return 0;
}
