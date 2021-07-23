//1. Write application which accept two file names from user. Compare the contents of
//that two files. If contents are same then return true otherwise return false.
/*
Input : Demo.txt
Hello.txt
Output : Compare contents of Demo.txt and Hello.txt
*/

#include<fcntl.h>
#include<unistd.h>
#include<iostream>
#include<string.h>
#include<stdbool.h>
using namespace std;
class FileX
{
	public:
	int fd1=0,fd2=0;
	FileX(char *str1,char *str2)
	{
		fd1=open(str1,O_RDWR);
		fd2=open(str2,O_RDWR);
		if((fd1==-1)||(fd2==-1))
			cout<<"Unable to open file\n";
		else
			cout<<"File created succesfully\n";
	}
	
	bool CompareX()
	{
		int Ret1=0,Ret2=0;
		int i=0,iCnt=0;
		
		char str1[20]={'\0'};
		char str2[20]={'\0'};
		
		char *ptr1=str1;
		char *ptr2=str2;
		
		while((Ret1=read(fd1,str1,10))!=0 && (Ret2=read(fd2,str2,10))!=0)
		{
			read(fd1,str1,Ret1);
			read(fd2,str2,Ret2);
			
			if(Ret1!=Ret2)
			{
				i++;
				break;
			}
			
			while(iCnt<Ret1)
			{
				if(*ptr1!=*ptr2)
				{
					i++;
					break;
				}
				iCnt++;
				ptr1++;
				ptr2++;
			}
			if(i==1)
				break;
		}
		
		if(i!=0)
			return false;
		else
			return true;
	}
	
	~FileX()
	{
		close(fd1);
		close(fd2);
	}
};
int main()
{
	char str1[30],str2[30];
	bool ret=false;
	cout<<"Enter the 1st file name\n";
	cin>>str1;
	
	cout<<"Enter the 2nd file name\n";
	cin>>str2;
	
	FileX obj(str1,str2);
	ret=obj.CompareX();
	if(ret==true)
		{ cout<<"contents are same\n";}
	else
		{ cout<<"content are different\n";}
		
		return 0;	
}

