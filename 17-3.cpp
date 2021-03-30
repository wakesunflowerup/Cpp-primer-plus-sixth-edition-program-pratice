#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	char ch;
	char * text="abcdefg";
	
	if(argc==1)
	{
		cout<<"Usage: "<<argv[0]<<" filename[s]\n";
		exit(EXIT_FAILURE);
	}
	ifstream fin;
	ofstream fout;
	
	fout.open(argv[1]);//还是先生成一个文件，文件生成后这段可以注释掉了 
	if(!fout.is_open())
	{
		cout<<"can`t open build file!\n";
		exit(EXIT_FAILURE);
	}
	cout<<"building the first file......\n";
	for(int i=0;i<5;i++)
		fout<<text<<endl;
	fout.close();
	cout<<"file is built.\n";
	
	fin.open(argv[1]);
	if(!fin.is_open())
	{
		cout<<"can`t open in file!\n";
		fin.clear();
	}
	cout<<"in file is opened.\n";
	
	fout.open(argv[2]);
	if(!fout.is_open())
	{
		cout<<"can`t open out file!\n";
		exit(EXIT_FAILURE);
	}
	cout<<"out file is opened.\nNow copying......\n";
	
	while(fin.get(ch))
	{
		fout<<ch;
	}
	cout<<"Copy end.\n";

	fin.clear();
	fin.close();
	fout.close();

	return 0;
}
