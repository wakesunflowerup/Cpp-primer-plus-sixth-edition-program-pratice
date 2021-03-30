#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void showmenu();
const int strsize=20;
struct bop{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};

int main(int argc, char** argv) {
	bop pro[5]={{"wimp macho","a","A",0,},{"raki rhodes","junior programmer","B",1,},
	{"celia laiter","MIPS","C",1,},{"hoppy hipman","analyst trainee","D",1,},{"pat hand","e","LOOPY",2}};
	
	showmenu();
	cout<<"enter your choice:";
	char ch;
	cin>>ch;
	while(ch!='q'){
		for(int i=0;i<5;i++){
			switch (ch){
				case 'a':cout<<pro[i].fullname<<endl;
				break;
				case 'b':cout<<pro[i].title<<endl;
				break; 
				case 'c':cout<<pro[i].bopname<<endl;
				break;
				case 'd':
				{
					switch (pro[i].preference){
						case 0:cout<<pro[i].fullname<<endl;
						break;
						case 1:cout<<pro[i].title<<endl;
						break;
						case 2:cout<<pro[i].bopname<<endl;
						 break;
					}
				 } 
				 break; 
			}
		}
		cout<<"next choice:";
		cin>>ch;
	}
	cout<<"bye!"<<endl;
	return 0;
}

void showmenu(){
	cout<<"B O O P R\n"
		  "a.display by name		b.display by title\n"
		  "c.display by bopname		d.display by preference\n"
		  "q.quit\n";
}
