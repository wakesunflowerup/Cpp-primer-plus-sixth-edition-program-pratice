#include <iostream>
#include <string>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class ABC{
private:	
	char * label;
public:	
	ABC();
	ABC(char * c);
	ABC(ABC &a);
	ABC & operator=(ABC &a);
	virtual ~ABC();
	virtual void view()=0; 
};

class baseDMA:public ABC{
private:	
	int rating;
public:	
	baseDMA();
	baseDMA(char * c,int i);
	virtual void view(); 
};

class lackDMA:public ABC{
private:	
	char color[40];
public:	
	lackDMA();
	lackDMA(char * c1,char c2[],int len);
	virtual void view(); 
};

class hasDMA:public ABC{
private:	
	char * style;
public:	
	hasDMA();
	hasDMA(char * c,char * c2);
	hasDMA(hasDMA &a);
	hasDMA & operator=(hasDMA &a);
	virtual ~hasDMA();
	virtual void view(); 
};

ABC::ABC()
{
	label=new char[1];
	label[0]='\0';
}
ABC::ABC(char * c)
{
	label=new char[strlen(c)+1];
	strcpy(label,c);
}
ABC::ABC(ABC &a)
{
	label=new char[strlen(a.label)+1];
	strcpy(label,a.label);
}
ABC & ABC::operator=(ABC &a)
{
	delete [] label;
	label=new char[strlen(a.label)+1];
	strcpy(label,a.label);
}
ABC::~ABC()
{
	delete [] label;
}
void ABC::view()
{
	cout<<"Label: "<<label<<endl;
}


baseDMA::baseDMA():ABC()
{
	rating=0;
}
baseDMA::baseDMA(char * c,int i):ABC(c)
{
	rating=i;
}
void baseDMA::view()
{
	ABC::view();
	cout<<"rating: "<<rating<<endl;
}

lackDMA::lackDMA():ABC()
{
	color[0]='\0';
}
lackDMA::lackDMA(char * c1,char c2[],int len):ABC(c1)
{
	if(len>=40)
	{
		cout<<"color can`t over 39 characters.color set null"<<endl;
		color[0]='\0';
	}
	else
		strcpy(color,c2);
}
void lackDMA::view()
{
	ABC::view();
	cout<<"Color: "<<color<<endl;
}


hasDMA::hasDMA():ABC()
{
	style=new char[1];
	style[0]='\0';
}
hasDMA::hasDMA(char * c,char * c2):ABC(c)
{
	style=new char[strlen(c2)+1];
	strcpy(style,c2);
}
hasDMA::hasDMA(hasDMA &a):ABC(a)
{
	style=new char[strlen(a.style)+1];
	strcpy(style,a.style);
}
hasDMA & hasDMA::operator=(hasDMA &a)
{
	ABC::operator=(a);
	delete [] style;
	style=new char[strlen(a.style)+1];
	strcpy(style,a.style);
}
hasDMA::~hasDMA()
{
	delete [] style;
}
void hasDMA::view()
{
	ABC::view();
	cout<<"Style: "<<style<<endl;
} 





const int MAX=5;

int main(int argc, char** argv) {
	ABC * pabc[MAX];
	string str;
	char * label;
	int rating;
	char color[40];
	char * style;
	char kind;
	for(int i=0;i<MAX;i++)
	{
		cout<<"Enter label: ";
		getline(cin,str);
		label=new char[str.size()+1];
		strcpy(label,str.c_str());
		cout<<"Enter 1 for baseDMA or 2 for lackDMA of 3 for hasDMA: ";
		while(cin>>kind&&(kind!='1'&&kind!='2'&&kind!='3'))
			cout<<"enter 1,2 or 3 : ";
		cin.get();
		if(kind=='1')
		{
			cout<<"Enter rating: ";
			while(!(cin>>rating))
			{
				cin.clear();
				while(cin.get()!='\n')
					continue;
				cout<<"Enter rating: ";
			}
			cin.get();
			pabc[i]=new baseDMA(label,rating);
		}
		else if(kind=='2')
		{
			cout<<"Enter color: ";
			getline(cin,str);
			while(str.size()>=40)
			{
				cout<<"color can`t over 39 charactors,please enter again: ";
				getline(cin,str);
			}
			strcpy(color,str.c_str());
			pabc[i]=new lackDMA(label,color,str.size());
		}
		else
		{
			cout<<"Enter style: ";
			getline(cin,str);
			style=new char[str.size()+1];
			strcpy(style,str.c_str());
			pabc[i]=new hasDMA(label,style);
		}
	}
	for(int i=0;i<MAX;i++)
	{
		pabc[i]->view();
		cout<<endl;
	}
	for(int i=0;i<MAX;i++)
		delete pabc[i];
		
	cout<<"done!"<<endl;
	return 0;
}
