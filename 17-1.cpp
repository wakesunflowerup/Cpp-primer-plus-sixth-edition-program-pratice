#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void eatline()
{
	while(cin.get()!='\n')
		continue;
}

//���Զ�ȡ���� �������鳤�ȣ����������ⲻ̫���� 


 
int main(int argc, char** argv) {
	char ch;
	int count=0;
	cout<<"Enter something, the number of characters before the first \"$\" will be show:  \n";
	
	cout<<"using cin.peek(): ";
	while(cin.peek()!='$')
	{
		cin.get(ch);
		count++;
		cout<<ch;
	}
	cout<<endl<<count<<endl;
	cin.get(ch);
	cout<<ch<<endl;
	
	count=0;
	eatline();
	cout<<"using cin.putback(): ";
	while(cin.get(ch))
	{
		if(ch!='$')
		{
			count++;
			cout<<ch;
		}
		else
		{
			cin.putback(ch);
			break;
		}
	}
	cout<<endl<<count<<endl;
	cin.get(ch);
	cout<<ch<<endl;
	
//	�����ˣ�cin.gcount() ֻ�����ϴη� cin>> ��ʽ��ȡ���ַ����������ÿ�ζ�һ���ַ���
//	ֻ���� 1 ������� 1 �� �򷵻� �ô� �� ���ȣ� 
//	count=0;
//	eatline();
//	cout<<"using cin.gcount(): ";
//	while(cin.get(ch))
//	{
//		if(ch!='$')
//		{
//			count++;
//			cout<<ch;
//		}
//		else
//		{
//			cout<<endl<<cin.gcount()<<endl;
//			break;
//		}
//	}
	
	
	cout<<"bye"<<endl;
	return 0;
}
