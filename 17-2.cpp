#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// cd 文件路径(可以直接复制的)  ***.exe  ***.txt ***.txt  etc 
int main(int argc, char** argv) {
	char ch;
	ofstream fout;
	if(argc==1)
	{
		cerr<<"Usage: "<<argv[0]<<" filename[s]\n";
		exit(EXIT_FAILURE);
	}
	
	for(int i=1;i<argc;i++)
	{
		fout.open(argv[i]);
		cout<<argv[i]<<"is opened.\n";
		cout<<"Now enter something: \n";
		while(cin.get((ch)))
		{
			fout<<ch;
		}
		fout<<endl;
		cout<<"OK!"<<endl;
		cin.clear();
		
		cout<<"Now enter something: \n";	
		while((ch=cin.get())!=EOF)
		{
			fout<<ch;
		}
		fout<<endl;
		cout<<"OK!\n";
		cin.clear();
		fout.close();
	}
	
	cout<<"bye"<<endl; 
	return 0;
}
