#include <iostream>
#include <string> 
#include <algorithm>
#include <cctype>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool issame(string & str);//��һ��ļ��ж� 
string transforsame(string & str);//����ccytpe��string�Դ�����ȥ���ո񣬱�㣬ת��ΪСд���������������


int main(int argc, char** argv) {
	string input,test;
	while(1)
	{
		cout<<"Enter a string(q to quit): ";
	
		getline(cin,input);
		if(input=="q"||input=="Q")
			break;
	
		test=transforsame(input);//����� transform �� replace������ո�ͱ��ĺ�������˵�����ÿ�ֵ�滻�� 
		
		cout<<test<<endl; 
		
		if(issame(test))
			cout<<input<<" is a huiwen string.\n";
		else
			cout<<input<<" is a sunflower.\n";//��ô����Ϊ����һ�ۿ������������Ĳ�ͬ�����ĸ��������Ҫ�󣬵�����ϲ��sunflower
	}
	
	cout<<"bye\n";
	return 0;
}

bool issame(string &str)
{ 
	string temp=str;//��û�� string ��ϸ�ĵ���֪��string��û�����õķ�ת�����������õ� STL �㷨 
//	reverse(temp.begin(),temp.end());  //STL ��� reverse
	copy(str.rbegin(),str.rend(),temp.begin());// ���string�����÷�ת����������߱��� 
	if(temp==str)
		return true;
	else
		return false;
}

string transforsame(string &str)
{
//	string temp=str;
//	int i,j;
//	for(i=0,j=0;i<str.size();i++)
//	{
//		if(isgraph(str[i])&&!ispunct(str[i]))
//			temp[j++]=tolower(str[i]);
//	}
//	temp.erase(j);//Ϊ�˷�ֹ����Խ�磬��ʹtemp��strһ���������������erase���������Ѵ�����ĸ���԰�����������
	string temp;
	for(int i=0;i<str.size();i++)
	{
		if(!isspace(str[i])&&!ispunct(str[i]))
			temp.insert(temp.end(),tolower(str[i]));//insert,�����stringָ����С 
	}
	return temp;
}

