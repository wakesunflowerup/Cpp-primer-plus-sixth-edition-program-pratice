#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ofstream fout;
	ifstream fino;
	ifstream fint;
	string temp;
	bool mark;//�պ�����ֵ����¼˭�ȵ��ļ�β 
	
	//�ļ����ɺ������ο���ע�͵��� 
	fout.open("17-4one.txt");
	fout<<"eggs kites dounuts\nballoons hammers\nstones sunflower\nwake up"<<endl;
	fout.close();
	
	fout.open("17-4two.txt");
	fout<<"zero lassitude\nfinance drama wakesunflowerup"<<endl;
	fout.close();
	
	//�ļ��Ѿ��������˱ض��ܴ򿪣������ʵ���п���,���Ա��žͲ�д exit(failure)�ˡ�lazy 
	fino.open("17-4one.txt");
	if(!fino.is_open())
		cout<<"17-4one is not opened.\n"; 
	else
		cout<<"17-4one is opened.\n";
	
	fint.open("17-4two.txt");
	if(!fino.is_open())
		cout<<"17-4two is not opened.\n";
	else
		cout<<"17-4two is not opened.\n";
	
	fout.open("17-4out.txt");
	cout<<"17-4out writing......\n";
	
	while(true)//ֻҪ�����ļ���һ������ EOF����ֹͣ�����޴�����Ϊ 
	{
		getline(fino,temp);
		fout<<temp<<" ";
		getline(fint,temp);
		fout<<temp<<" ";
		
		fout<<endl;//�ǵû��� 
		
		if(fino.peek()==EOF)
		{
			mark=true;
			cout<<"17-4one ends first.\n";
			break;
		}
		if(fint.peek()==EOF)
		{
			mark=false;
			cout<<"17-4two ends first.\n";
			break;
		}
	}
	
	if(mark)
	{
		cout<<"17-4two --rest of it.\n";
		while(fint.peek()!=EOF)
		{
			fint>>temp;
			fout<<temp<<" "; 
		}
		fout<<endl;
	}
	else
	{
		cout<<"17-4one --rest of it.\n";
		while(fino.peek()!=EOF)
		{
			fino>>temp;
			fout<<temp<<" ";
		}
		fout<<endl;
	}
	
	fino.close();
	fint.close();
	
	cout<<"bye"<<endl;
	return 0;
}
