#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <list> 
#include <algorithm>
#include <iterator>
#include <cctype>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int MAX=10; 

void vector_use();
void list_use();
void set_use();

int main(int argc, char** argv) {
	
	ofstream fout;
	//还是先生成文件 ，mat的水果朋友，pat的蔬菜朋友 
	char mat[5][MAX]={"Tomato","Banana","Apple","Carrot","Peach"};//不能用任何指针，否则只存储地址		 
	char pat[5][MAX]={"Carrot","Onion","Radish","Tomato","Potato"};//每行除去 \n \0之后只能存8个 char 
	for(int i=0;i<5;i++)
	{
		mat[i][9]='\n';
		pat[i][9]='\n';
	}
	
	fout.open("17-5mat.dat",ios_base::out|ios_base::binary);
	fout.write((char *) &mat,sizeof mat);
	fout.close();
	fout.open("17-5pat.dat",ios_base::out|ios_base::binary);
	fout.write((char *) &pat,sizeof pat);
	fout.close(); 
	//对于 char 数据，存储方式 二进制 and 文本格式 都是一样的 
	//但是得练习下 .write .read; 
	
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

// the same 毕竟是生成的文件，肯定能打开，不检测了 
void vector_use()
{
	ifstream fin;
	ofstream fout;
	vector<string> Mat,Pat,MP;
	string name;
	ostream_iterator<string,char> outs(cout," ");
	ostream_iterator<string,char> outf(fout,"\n");//注意是 fout哦	
	char temp[MAX];
 
	fin.open("17-5mat.dat",ios_base::in|ios_base::binary);
	while(fin.read((char*) &temp,sizeof temp))//括号里可以直接 getline(fin,name) 我这里是练习 .read 
	{										//gtetline 的话就把空格也直接赋给string了，不过不影响排序 
		name=temp;
		Mat.insert(Mat.end(),name);
	}
	fin.close();
	
	fin.open("17-5pat.dat",ios_base::in|ios_base::binary);
	while(fin.read((char*) &temp,sizeof temp))
	{
		name=temp;
		Pat.insert(Pat.end(),name);
	}
	fin.close();
	
	sort(Mat.begin(),Mat.end());
	cout<<"Mat`s friends by cout: \n";
	for(string mname:Mat)
		cout<<mname<<" ";
	cout<<endl;

	sort(Pat.begin(),Pat.end());
	cout<<"Pat`s freinds by cout: \n";
	for(string pname:Pat)
		cout<<pname<<" ";
	cout<<endl;
	
	merge(Mat.begin(),Mat.end(),Pat.begin(),Pat.end(),insert_iterator<vector<string>>(MP,MP.begin()));//merge 必须对相同排序方式排序后的容器使用 
	sort(MP.begin(),MP.end());
	vector<string>::iterator newend=unique(MP.begin(),MP.end()); //声明对应容器的迭代器 
	
	fout.open("17-5matnpat.dat",ios_base::out|ios_base::binary);
	//下面两种输出方式都可以 
	cout<<"Mat & Pat `s friends by cout: \n";
	for(vector<string>::iterator ps=MP.begin();ps!=newend;ps++)
	{
		cout<<*ps<<" ";
		//fout<<*ps<<endl;
	} 
	cout<<endl;
	
	cout<<"Mat & Pat `s friends by iterator: \n";
	copy(MP.begin(),newend,outs);
	copy(MP.begin(),newend,outf);
	cout<<endl;
	
	fout.close();
}


void list_use()
{
	list<string> Mat,Pat;	
	ifstream fin;
	ofstream fout;
	string name;
	ostream_iterator<string,char> outs(cout," ");
	ostream_iterator<string,char> outf(fout,"\n");//注意是 fout哦	
	char temp[MAX];
 
	fin.open("17-5mat.dat",ios_base::in|ios_base::binary);
	while(fin.read((char*) &temp,sizeof temp))//括号里可以直接 getline(fin,name) 我这里是练习 .read 
	{										//gtetline 的话就把空格也直接赋给string了，不过不影响排序 
		name=temp;
		Mat.insert(Mat.end(),name);
	}
	fin.close();
	
	fin.open("17-5pat.dat",ios_base::in|ios_base::binary);
	while(fin.read((char*) &temp,sizeof temp))
	{
		name=temp;
		Pat.insert(Pat.end(),name);
	}
	fin.close();
	
	Mat.sort();
	cout<<"Mat`s friends by cout: \n";
	for(string mname:Mat)
		cout<<mname<<" ";
	cout<<endl;
	
	Pat.sort();
	cout<<"Pat`s freinds by cout: \n";
	for(string pname:Pat)
		cout<<pname<<" ";
	cout<<endl;
	
	Mat.merge(Pat);//此时 Pat 为空 
	Mat.unique();
	Mat.sort(); 
	
	fout.open("17-5matnpat.dat",ios_base::out|ios_base::binary);
	cout<<"Mat & Pat `s friends by cout: \n";
	for(string mpname:Mat)
	{
		cout<<mpname<<" ";
		fout<<mpname<<endl;
	}
	cout<<endl;
	
	cout<<"Mat & Pat `s friends by iterator: \n";
	copy(Mat.begin(),Mat.end(),outs);
//	copy(Mat.begin(),Mat.end(),outf);
	cout<<endl;
}


void set_use()
{
	set<string> Mat,Pat,MP;
	ifstream fin;
	ofstream fout;
	string name;
	ostream_iterator<string,char> outs(cout," ");
	ostream_iterator<string,char> outf(fout,"\n");//注意是 fout哦	
	char temp[MAX];
 
	fin.open("17-5mat.dat",ios_base::in|ios_base::binary);
	while(fin.read((char*) &temp,sizeof temp))//括号里可以直接 getline(fin,name) 我这里是练习 .read 
	{										//gtetline 的话就把空格也直接赋给string了，不过不影响排序 
		name=temp;
		Mat.insert(Mat.end(),name);
	}
	fin.close();
	
	fin.open("17-5pat.dat",ios_base::in|ios_base::binary);
	while(fin.read((char*) &temp,sizeof temp))
	{
		name=temp;
		Pat.insert(Pat.end(),name);
	}
	fin.close();	
	
	cout<<"Mat`s friends by cout: \n";
	for(string mname:Mat)
		cout<<mname<<" ";
	cout<<endl;
	
	cout<<"Pat`s freinds by cout: \n";
	for(string pname:Pat)
		cout<<pname<<" ";
	cout<<endl;
	
	set_union(Mat.begin(),Mat.end(),Pat.begin(),Pat.end(),insert_iterator<set<string>>(MP,MP.begin()));//merge 必须对相同排序方式排序后的容器使用 
//	Mat_uniq.insert(Pat.begin(),Pat.end()); //为什么不支持 uniq.insert()?
	
	fout.open("17-5matnpat.dat",ios_base::out|ios_base::binary);
	cout<<"Mat & Pat `s friends by cout: \n";
	for(string mpname:MP)
	{
		cout<<mpname<<" ";
//		fout<<mpname<<endl; 
	} 
	cout<<endl;
	
	cout<<"Mat & Pat `s friends by iterator: \n";
	copy(MP.begin(),MP.end(),outs);
	copy(MP.begin(),MP.end(),outf);
	cout<<endl;
}
