#include <iostream>
#include <string> 
#include <algorithm>
#include <cctype>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool issame(string & str);//第一题的简单判断 
string transforsame(string & str);//利用ccytpe和string自带方法去除空格，标点，转换为小写，跟上述函数组合


int main(int argc, char** argv) {
	string input,test;
	while(1)
	{
		cout<<"Enter a string(q to quit): ";
	
		getline(cin,input);
		if(input=="q"||input=="Q")
			break;
	
		test=transforsame(input);//如果用 transform 和 replace，处理空格和标点的函数报错说不能用空值替换掉 
		
		cout<<test<<endl; 
		
		if(issame(test))
			cout<<input<<" is a huiwen string.\n";
		else
			cout<<input<<" is a sunflower.\n";//这么搞是为了能一眼看出来输出结果的不同，中文更符合这个要求，但是我喜欢sunflower
	}
	
	cout<<"bye\n";
	return 0;
}

bool issame(string &str)
{ 
	string temp=str;//我没看 string 详细文档不知道string有没有内置的反转方法，所以用的 STL 算法 
//	reverse(temp.begin(),temp.end());  //STL 里的 reverse
	copy(str.rbegin(),str.rend(),temp.begin());// 如果string有内置反转方法，请告诉本屌 
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
//	temp.erase(j);//为了防止数组越界，先使temp和str一样长，处理过后用erase方法消除已处理字母后迷案的无用数据
	string temp;
	for(int i=0;i<str.size();i++)
	{
		if(!isspace(str[i])&&!ispunct(str[i]))
			temp.insert(temp.end(),tolower(str[i]));//insert,无需给string指定大小 
	}
	return temp;
}

