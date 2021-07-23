/*3. Write application which accept two file names from user. Append the contents of
first file at the end of second file.
Input : Demo.txt
Hello.txt
Output : Concat contents of Demo.txt at the end of Hello.txt
*/
#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

using namespace std;
class FileX
{
	public:
	int fd1=0,fd2=0;
	FileX(char *FileName1,char *FileName2)
	{
		fd1=open(FileName1,O_RDWR | O_APPEND);
		fd2=open(FileName2,O_RDWR | O_APPEND);
		
		if((fd1==-1)||(fd2==-1))
		{
			cout<<"Unable to open file\n";
			exit(0);
		}
		else
		{
			cout<<"File created succesfully\n";
		}
	}
	
	void AppendX()
	{
		int Ret=0;
		char str[10];
		
		while((Ret=read(fd2,str,10))!=0)
		{
			write(fd1,str,Ret);
		}
	}
	
	~FileX()
	{
		close(fd1);
		close(fd2);
	}
};

int main()
{
	char str1[20];
	char str2[20];
	cout<<"Enter first file name\n";
	cin>>str1;
	
	cout<<"Enter first file name\n";
	cin>>str2;
	
	FileX obj(str1,str2);
	obj.AppendX();
	return 0;
}



