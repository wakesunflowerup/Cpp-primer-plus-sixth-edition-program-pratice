#include <iostream>
#include <cstring>
#include "14-3workermi.h"
#include "14-3queuetp.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int SIZE=5;

int main(int argc, char** argv) {
	
	QueueTP<Worker * > lolas(SIZE);

	Worker * in[SIZE];//��ӵ�ָ�� 
	Worker * out[SIZE];//���ӵ�ָ�룬�������������λ�������СΪct����ʡ�ռ� 
	 
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
		switch(choice)//���ݲ�ͬ���봴���µ�Workerָ�룬ָ���Ӧ������ 
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
		in[ct]->Set();//�Ը�Wrkerָ��ָ����������������
		lolas.enqueue(in[ct]);//��� 	 
	} 
	
	cout<<"\nHere is your staff:\n";
	
	for(int i=0;i<ct;i++)
	{ 
		lolas.dequeue(out[i]);
		out[i]->Show();
		cout<<endl; 
		delete out[i];//Ҳ����д��in[i]��ָ��ĵ�ַ��һ��
		//���߲�������ָ���Ѿ��������ʷʹ���������ͷŵ�����ռ�ռ��� 
	}
	
	cout<<"bye\n";
	return 0;
}
