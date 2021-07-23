/*
Input : Hello
Output :
	H	e	l	l	o	
	H	e	l	l	
	H	e	l	
	H	e	
	H	

*/
#include<iostream>
using namespace std;
class StringX
{
	public:
	char str[30];
	
	void Accept()
	{
		cout<<"Enter String\n";
		scanf("%[^'\n']s",str);
	}

	void Pattern()
	{
		char *ptr=str;
		char *s=str;
		int iCnt=0;
		while(*ptr!='\0')
		{
			while(*(s+iCnt)!='\0')
			{
				cout<<*s<<"\t";
				s++;
			}
			ptr++;
			s=str;
			iCnt++;
			cout<<"\n";
		}
	}
	
};
int main()
{
	StringX obj;
	obj.Accept();
	obj.Pattern();
	return 0;
}
