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
	bool mark;//刚好两个值，记录谁先到文件尾 
	
	//文件生成后这两段可以注释掉了 
	fout.open("17-4one.txt");
	fout<<"eggs kites dounuts\nballoons hammers\nstones sunflower\nwake up"<<endl;
	fout.close();
	
	fout.open("17-4two.txt");
	fout<<"zero lassitude\nfinance drama wakesunflowerup"<<endl;
	fout.close();
	
	//文件已经被生成了必定能打开，检测其实可有可无,所以本屌就不写 exit(failure)了。lazy 
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
	
	while(true)//只要两个文件有一个到了 EOF，就停止这种愚蠢的行为 
	{
		getline(fino,temp);
		fout<<temp<<" ";
		getline(fint,temp);
		fout<<temp<<" ";
		
		fout<<endl;//记得换行 
		
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
