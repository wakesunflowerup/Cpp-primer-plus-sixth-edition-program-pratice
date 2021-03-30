#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void eatline()
{
	while(cin.get()!='\n')
		continue;
}

//可以读取数组 返回数组长度，但是与题意不太符合 


 
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
	
//	理解错了，cin.gcount() 只返回上次非 cin>> 方式读取的字符串，如果是每次读一个字符串
//	只返回 1 ，如果是 1 串 则返回 该串 的 长度； 
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
