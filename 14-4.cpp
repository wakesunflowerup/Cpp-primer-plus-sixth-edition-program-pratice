#include <iostream>
#include <cstring>
#include "14-4person.h"
#include "14-3queuetp.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int SIZE=5;

int main(int argc, char** argv) {
	
	QueueTP<Person * > lolas(SIZE);

	Person * in[SIZE];//��ӵ�ָ�� 
	Person * out[SIZE];//���ӵ�ָ�룬�������������λ�������СΪct����ʡ�ռ� 
	 
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
		switch(choice)//���ݲ�ͬ���봴���µ�Personָ�룬ָ���Ӧ������ 
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
		in[ct]->Set();//�Ը�Personָ��ָ����������������
		lolas.enqueue(in[ct]);//��� 	 
	} 
	
	cout<<"\nHere is Person info:\n";
	
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
