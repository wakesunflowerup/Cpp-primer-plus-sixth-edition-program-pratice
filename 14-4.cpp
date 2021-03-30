#include <iostream>
#include <cstring>
#include "14-4person.h"
#include "14-3queuetp.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int SIZE=5;

int main(int argc, char** argv) {
	
	QueueTP<Person * > lolas(SIZE);

	Person * in[SIZE];//入队的指针 
	Person * out[SIZE];//出队的指针，放在下面输出的位置让其大小为ct更节省空间 
	 
	int ct;
	
	for(ct=0;ct<SIZE;ct++)
	{
		char choice;
		cout<<"Enter the person category:\np:PokerPlayer\tg:Gunslinger\tb:BadDude\tq:quit\n";
		cin>>choice;
		while(strchr("pgbq",choice)==nullptr)
		{
			cout<<"Please enter just p, g, b, or q for once: ";
			cin>>choice;
		}
		if(choice=='q')
			break;
		switch(choice)//根据不同输入创建新的Person指针，指向对应派生类 
		{
			case 'p':	in[ct]=new PokerPlayer; 
						break;
			case 'b':	in[ct]=new BadDude;
						break;
			case 'g':	in[ct]=new Gunslinger;
						break; 
		}
		while(cin.get()!='\n')
			continue;
		in[ct]->Set();//对该Person指针指向的派生类进行设置
		lolas.enqueue(in[ct]);//入队 	 
	} 
	
	cout<<"\nHere is Person info:\n";
	
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
