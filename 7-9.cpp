#include <iostream>
#include <cstring>
using namespace std;
const int SLEN=30;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//int main(int argc, char** argv) {
//	return 0;
//}

struct student{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
int getinfo(student pa[],int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[],int n);
int main()
{
   cout << "enter class size: ";
   int class_size;
   cin>>class_size;
   while(cin.get()!='\n')
       continue;
   student *ptr_stu=new student[class_size];
   int entered=getinfo(ptr_stu,class_size);
   for(int i=0;i<entered;i++){
       display1(ptr_stu[i]);
       display2(&ptr_stu[i]);
   }
   display3(ptr_stu, entered);
   delete [] ptr_stu;
    cout<<"done\n";
   return 0;
}
int getinfo(student pa[],int n){
    int i;
    for(i=0;i<n;i++){
        cout<<"enter student #"<<i+1<<" `s fullname:";

        cin.getline(pa[i].fullname,SLEN);
        if(!strcmp(pa[i].fullname," ")){
        	return i;
        	break;
		}
        cout<<"enter student #"<<i+1<<" `s hobby:";
		cin.getline(pa[i].hobby,SLEN);
	
        cout<<"enter student #"<<i+1<<" `s ooplevel:";
    
    	cin>>pa[i].ooplevel;
    	if(!cin){
    		cin.clear();
    		while(cin.get()!='\n')
    			continue;
		}
    	while(cin.get()!='\n')
		continue;
    }
    return i;
}
void display1(student st){
    cout<<"fullname:"<<st.fullname<<"\nhobby:"<<st.hobby<<"\nooplevel:"<<st.ooplevel<<endl;
}
void display2(const student * ps){
    cout<<"fullname:"<<ps->fullname<<"\nhobby:"<<ps->hobby<<"\nooplevel:"<<ps->ooplevel<<endl;
}
void display3(const student pa[],int n){
    for(int i=0;i<n;i++){
        cout<<"student #"<<i+1<<" `s fullname:"<<pa[i].fullname<<"\nhobby:"<<pa[i].hobby<<"\nooplevel:"<<pa[i].ooplevel<<endl;
    }
}
