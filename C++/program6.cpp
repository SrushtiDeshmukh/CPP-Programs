/*
Input : Hello
Output : 	
	H	
	H	e	
	H	e	l	
	H	e	l	l	
	H	e	l	l	o			
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
		while(*ptr!='\0')
		{
			while(s<=ptr)
			{
				cout<<*s<<"\t";
				s++;
			}
			ptr++;
			s=str;
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
