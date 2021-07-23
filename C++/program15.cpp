//Accept file name from user write given string into that file 
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<iostream>
using namespace std;
class FileX
{
	public:
	int fd;
	FileX(char Name[])		
	{
		fd=open(Name,O_WRONLY);
		if(fd==-1)
		{
			cout<<"Unable to create file\n";
		}
		else
		{
			cout<<"File succesfully created\n";
		}
	}
	~FileX()
	{
		close(fd);
	}
	void WriteData()
	{
		char str[]="Pune";
		write(fd,str,4);
	}
};
int main()
{
	char str[30];
	int no;
	cout<<"Enter file name\n";
	cin>>str;
	FileX obj(str);		
	
	obj.WriteData();
	return 0;
}

