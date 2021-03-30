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
	//�����������ļ� ��mat��ˮ�����ѣ�pat���߲����� 
	char mat[5][MAX]={"Tomato","Banana","Apple","Carrot","Peach"};//�������κ�ָ�룬����ֻ�洢��ַ		 
	char pat[5][MAX]={"Carrot","Onion","Radish","Tomato","Potato"};//ÿ�г�ȥ \n \0֮��ֻ�ܴ�8�� char 
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
	//���� char ���ݣ��洢��ʽ ������ and �ı���ʽ ����һ���� 
	//���ǵ���ϰ�� .write .read; 
	
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

// the same �Ͼ������ɵ��ļ����϶��ܴ򿪣�������� 
void vector_use()
{
	ifstream fin;
	ofstream fout;
	vector<string> Mat,Pat,MP;
	string name;
	ostream_iterator<string,char> outs(cout," ");
	ostream_iterator<string,char> outf(fout,"\n");//ע���� foutŶ	
	char temp[MAX];
 
	fin.open("17-5mat.dat",ios_base::in|ios_base::binary);
	while(fin.read((char*) &temp,sizeof temp))//���������ֱ�� getline(fin,name) ����������ϰ .read 
	{										//gtetline �Ļ��Ͱѿո�Ҳֱ�Ӹ���string�ˣ�������Ӱ������ 
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
	
	merge(Mat.begin(),Mat.end(),Pat.begin(),Pat.end(),insert_iterator<vector<string>>(MP,MP.begin()));//merge �������ͬ����ʽ����������ʹ�� 
	sort(MP.begin(),MP.end());
	vector<string>::iterator newend=unique(MP.begin(),MP.end()); //������Ӧ�����ĵ����� 
	
	fout.open("17-5matnpat.dat",ios_base::out|ios_base::binary);
	//�������������ʽ������ 
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
	ostream_iterator<string,char> outf(fout,"\n");//ע���� foutŶ	
	char temp[MAX];
 
	fin.open("17-5mat.dat",ios_base::in|ios_base::binary);
	while(fin.read((char*) &temp,sizeof temp))//���������ֱ�� getline(fin,name) ����������ϰ .read 
	{										//gtetline �Ļ��Ͱѿո�Ҳֱ�Ӹ���string�ˣ�������Ӱ������ 
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
	
	Mat.merge(Pat);//��ʱ Pat Ϊ�� 
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
	ostream_iterator<string,char> outf(fout,"\n");//ע���� foutŶ	
	char temp[MAX];
 
	fin.open("17-5mat.dat",ios_base::in|ios_base::binary);
	while(fin.read((char*) &temp,sizeof temp))//���������ֱ�� getline(fin,name) ����������ϰ .read 
	{										//gtetline �Ļ��Ͱѿո�Ҳֱ�Ӹ���string�ˣ�������Ӱ������ 
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
	
	set_union(Mat.begin(),Mat.end(),Pat.begin(),Pat.end(),insert_iterator<set<string>>(MP,MP.begin()));//merge �������ͬ����ʽ����������ʹ�� 
//	Mat_uniq.insert(Pat.begin(),Pat.end()); //Ϊʲô��֧�� uniq.insert()?
	
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
