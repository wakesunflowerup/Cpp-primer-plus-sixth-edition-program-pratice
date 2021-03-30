#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// windows 10 �ļ��±������ɵ��ļ�������  ��ʼ��һ��С�����һ�ѿո�֮������ַ���
//����ַ������з��ţ�������ʾ�������ַ��� 

const char * file="17-7strings.dat";

void ShowStr(const string & str);

void GetStrs(ifstream & fin,vector<string> & vec);

//  main ��û��������࣬��˱�������д��ģ���� 
class Store{
private:
	ofstream & os;// �����黹��ӡˢ����Ϊɶ������ ifstream ? ���溦�ң��������ң� 
public:
	Store(ofstream & fout):os(fout) {}
	void operator()(const string & s){
		size_t len=s.size();
		os.write((char *)&len,sizeof(size_t));// size_t �� sizeof ���ص��������͵� typedef 
		os.write(s.data(),len);
	}
};

int main(int argc, char** argv) {
	string temp;
	vector<string> vostr;
	
	cout<<"Enter strings (empty line to quit):\n";
	while(getline(cin,temp) && temp[0]!='\0')
		vostr.push_back(temp);
	cout<<"Here is your input.\n";
	for_each(vostr.begin(),vostr.end(),ShowStr);
	
	ofstream fout(file,ios_base::out|ios_base::binary);
	for_each(vostr.begin(),vostr.end(),Store(fout));
	fout.close();
	
	vector<string> vistr;
	ifstream fin(file,ios_base::in|ios_base::binary);
	if(!fin.is_open())
	{
		cerr<<"Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin,vistr);
	cout<<"\nHere are the strings read from the file:\n";
	for_each(vistr.begin(),vistr.end(),ShowStr);
	
	
	return 0;
}


void ShowStr(const string & str)
{
	cout<<str<<endl;
}

void GetStrs(ifstream & fin,vector<string> & vec)
{
	string temp;
	size_t len;
	while(fin.read((char *)&len,sizeof(size_t)))
	{
		char ch[len+1];
		fin.read(ch,len);
		ch[len+1]='\0';
		temp=ch;
		vec.push_back(temp);
	}
}

