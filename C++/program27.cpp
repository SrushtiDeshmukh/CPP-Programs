//5. Write application which accept file name from user and one string from user. Write that string at the end of file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<iostream>
#include<string.h>
using namespace std;
class FileX
{
	public:
	int fd=0;
	FileX(char *Name)
	{
		fd=open(Name,O_RDWR | O_APPEND);
		if(fd==-1)
			cout<<"Unable to open file\n";
		else
			cout<<"File created succesfully\n";
	}
	void WriteData(char str[])
	{
		int iLength=strlen(str);
		write(fd,str,iLength);
	}
	~FileX()
	{
		close(fd);
	}
};
int main()
{
	char Fname[30],str[30];
	cout<<"Enter the file name\n";
	cin>>Fname;
	
	cout<<"Enter the string\n";
	scanf(" %[^'\n']s",str);
	
	FileX obj(Fname);
	obj.WriteData(str);
}
