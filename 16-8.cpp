#include <iostream>
#include <vector>
#include <set>
#include <list> 
#include <algorithm>
#include <iterator>
#include <cctype>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void vector_use();
void list_use();
void set_use();

int main(int argc, char** argv) {
	cout<<"Enter the character to choose different method:\n"
			"v.vector   l.list   s.set   q.quit\n";
	char ch;
	cin>>ch;
	while(cin.get()!='\n')
		continue;
	ch=tolower(ch);
	switch(ch){
		case 'q':break;
		case 'v':vector_use();
				 break;
		case 'l':list_use();
				 break;
		case 's':set_use();
				 break;
	}
	
	cout<<"bye\n";
	return 0;
}


void vector_use()
{
	vector<string> Mat,Pat,MP;
	string name;
	ostream_iterator<string,char> out(cout," ");//声明一个屏幕输出迭代器 
	
	
	cout<<"Enter Mat`s friends`name(q to quit): \n";
	while(1)
	{
		getline(cin,name);
		if(name=="q"||name=="Q")
			break; 
		Mat.insert(Mat.end(),name);
		cout<<"Enter another(q to quit): \n";
	}
	
	sort(Mat.begin(),Mat.end());
	cout<<"Mat`s friends by cout: \n";
	for(string mname:Mat)
		cout<<mname<<" ";
	cout<<endl;

	cout<<"Mat`s friends by iterator: \n";
	copy(Mat.begin(),Mat.end(),out);
	cout<<endl;
	
	cout<<"Enterr Pat`s friends`name(q to quit): \n";
	while(1)
	{
		getline(cin,name);
		if(name=="q"||name=="Q")
			break;
		Pat.insert(Pat.end(),name);
		cout<<"Enter another(q to quit): \n";
	}
	
	sort(Pat.begin(),Pat.end());
	cout<<"Pat`s freinds by cout: \n";
	for(string pname:Pat)
		cout<<pname<<" ";
	cout<<endl;
	
	cout<<"Pat`s friends by iterator: \n";
	copy(Pat.begin(),Pat.end(),out);
	cout<<endl;
	
	merge(Mat.begin(),Mat.end(),Pat.begin(),Pat.end(),insert_iterator<vector<string>>(MP,MP.begin()));//merge 必须对相同排序方式排序后的容器使用 
	sort(MP.begin(),MP.end());
	vector<string>::iterator newend=unique(MP.begin(),MP.end()); //声明对应容器的迭代器 
	
	cout<<"Mat & Pat `s friends by cout: \n";
	for(vector<string>::iterator ps=MP.begin();ps!=newend;ps++)
		cout<<*ps<<" ";
	cout<<endl;
	
	cout<<"Mat & Pat `s friends by iterator: \n";
	copy(MP.begin(),newend,out);
	cout<<endl;
}


void list_use()
{
	list<string> Mat,Pat;
	string name;
	ostream_iterator<string,char> out(cout," ");//声明一个屏幕输出迭代器 
	
	
	cout<<"Enter Mat`s friends`name(q to quit): \n";
	while(1)
	{
		getline(cin,name);
		if(name=="q"||name=="Q")
			break; 
		Mat.insert(Mat.end(),name);
		cout<<"Enter another(q to quit): \n";
	}
	
	Mat.sort();
	cout<<"Mat`s friends by cout: \n";
	for(string mname:Mat)
		cout<<mname<<" ";
	cout<<endl;

	cout<<"Mat`s friends by iterator: \n";
	copy(Mat.begin(),Mat.end(),out);
	cout<<endl;
	
	cout<<"Enterr Pat`s friends`name(q to quit): \n";
	while(1)
	{
		getline(cin,name);
		if(name=="q"||name=="Q")
			break;
		Pat.insert(Pat.end(),name);
		cout<<"Enter another(q to quit): \n";
	}
	
	Pat.sort();
	cout<<"Pat`s freinds by cout: \n";
	for(string pname:Pat)
		cout<<pname<<" ";
	cout<<endl;
	
	cout<<"Pat`s friends by iterator: \n";
	copy(Pat.begin(),Pat.end(),out);
	cout<<endl;
	
	Mat.merge(Pat);//此时 Pat 为空 
	Mat.unique();
	Mat.sort(); 
	
	cout<<"Mat & Pat `s friends by cout: \n";
	for(string mpname:Mat)
		cout<<mpname<<" ";
	cout<<endl;
	
	cout<<"Mat & Pat `s friends by iterator: \n";
	copy(Mat.begin(),Mat.end(),out);
	cout<<endl;
}


void set_use()
{
	set<string> Mat,Pat,MP;
	string name;
	ostream_iterator<string,char> out(cout," ");//声明一个屏幕输出迭代器 
	
	
	cout<<"Enter Mat`s friends`name(q to quit): \n";
	while(1)
	{
		getline(cin,name);
		if(name=="q"||name=="Q")
			break; 
		Mat.insert(Mat.end(),name);
		cout<<"Enter another(q to quit): \n";
	}
	
	cout<<"Mat`s friends by cout: \n";
	for(string mname:Mat)
		cout<<mname<<" ";
	cout<<endl;

	cout<<"Mat`s friends by iterator: \n";
	copy(Mat.begin(),Mat.end(),out);
	cout<<endl;
	
	cout<<"Enterr Pat`s friends`name(q to quit): \n";
	while(1)
	{
		getline(cin,name);
		if(name=="q"||name=="Q")
			break;
		Pat.insert(Pat.end(),name);
		cout<<"Enter another(q to quit): \n";
	}
	
	cout<<"Pat`s freinds by cout: \n";
	for(string pname:Pat)
		cout<<pname<<" ";
	cout<<endl;
	
	cout<<"Pat`s friends by iterator: \n";
	copy(Pat.begin(),Pat.end(),out);
	cout<<endl;
	
	set_union(Mat.begin(),Mat.end(),Pat.begin(),Pat.end(),insert_iterator<set<string>>(MP,MP.begin()));//merge 必须对相同排序方式排序后的容器使用 
//	Mat_uniq.insert(Pat.begin(),Pat.end()); //为什么不支持 uniq.insert()?
	cout<<"Mat & Pat `s friends by cout: \n";
	for(string mpname:MP)
		cout<<mpname<<" ";
	cout<<endl;
	
	cout<<"Mat & Pat `s friends by iterator: \n";
	copy(MP.begin(),MP.end(),out);
	cout<<endl;
}
