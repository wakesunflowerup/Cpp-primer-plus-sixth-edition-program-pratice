#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class String{
private:
	char *str;
	int len;
	static int num_strings;
	static const int CINLIM=80;
public:
	String(const char * s);
	String();
	String(const String &);
	~String();
	int length()const{return len;}
	String & operator=(const String &);
	String & operator=(const char *);
	char & operator[](int i);
	const char & operator[](int i)const;
	void Stringlow();
	void Stringup();
	int has(char ch);
	friend bool operator<(const String &st1,const String &st2);
	friend bool operator>(const String &st1,const String &st2);
	friend bool operator==(const String &st1,const String &st2);
	friend String operator+(const String &st1,const String &st2);
		
	friend ostream & operator<<(ostream &os,const String &st);
	friend istream & operator>>(istream &is,String &st);
	static int howmany();
};
int String::num_strings=0;

String::String(const char * s)
{
	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	num_strings++;
}
String::String()
{
	len=4;
	str=new char[1];
	str[1]='\0';
	num_strings++;
}
String::String(const String &st)
{
	len=st.len;
	str=new char[len+1];
	strcpy(str,st.str);
	num_strings++; 
}
String::~String()
{
	delete [] str;
	num_strings--;
}
String & String::operator=(const String &st)
{
	if(this==&st)
	{
		return *this;
	}
	delete [] str;
	len=st.len;
	str=new char[len+1];
	strcpy(str,st.str);
	return *this;
}
String & String::operator=(const char *s)
{
	delete [] str;
	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	return *this;
}
char & String::operator[](int i)
{
	return str[i];
}
const char & String::operator[](int i)const
{
	return str[i];
}
void String::Stringlow()
{
	for(int i=0;i<len;i++)
	{
		str[i]=tolower(str[i]);
	}
}
void String::Stringup()
{
	for(int i=0;i<len;i++)
	{
		str[i]=toupper(str[i]);
	}
}
int String::has(char ch)
{
	int num=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]==ch)
			num++;
	}
	return num;
}

bool operator<(const String &st1,const String &st2)
{
	return(strcmp(st1.str,st2.str)<0);
}
bool operator>(const String &st1,const String &st2)
{
	return(strcmp(st1.str,st2.str)>0);
}
bool operator==(const String &st1,const String &st2)
{
	return(strcmp(st1.str,st2.str)==0);
}
String operator+(const String &st1,const String &st2)
{
	String temp;
	temp.len=st1.len+st2.len;
	temp.str=new char[temp.len+1];
	strcpy(temp.str,st1.str);
	strcat(temp.str,st2.str);
	return temp;
}
ostream & operator<<(ostream &os,const String &st)
{
	os<<st.str;
	return os;
} 
istream & operator>>(istream &is,String &st)
{
	char temp[String::CINLIM];
	is.get(temp,String::CINLIM);
	if(is)
		st=temp;
	while(is&&is.get()!='\n')
		continue;
	return is;
}
int String::howmany()
{
	return num_strings;
}
 


int main(int argc, char** argv) {
	String s1(" and I am a C++ student.");
	String s2="Please enter your name: ";
	String s3;
	cout<<s2;
	cin>>s3;
	s2="My name is "+ s3;
	cout<<s2<<"\n";
	s2=s2+s1;
	s2.Stringup();
	cout<<"The string\n"<<s2<<"\ncontains "<<s2.has('A')<<" 'A'characters in it.\n";
	s1="red";
	String rgb[3]={String(s1),String("green"),String("blue")};
	cout<<"Enter the name of a primary color for mixing light: ";
	String ans;
	bool success=false;
	while(cin>>ans)
	{
		ans.Stringlow();
		for(int i=0;i<3;i++)
		{
			if(ans==rgb[i])
			{
				cout<<"That`s right!\n";
				success =true;
				break;
			}
		}
		if(success)
			break;
		else
			cout<<"Try again!\n";
	}
	cout<<"Bye\n";
	
	return 0;
}
