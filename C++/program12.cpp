//Accept file name from user ,accept bytes from user and read that byte 
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
		fd=open(Name,O_RDONLY);
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
	void ReadData(int size)
	{
		char arr[20]={'\0'};	
		read(fd,arr,size);	
		printf("%s\n",arr);
	}
};
int main()
{
	char str[30];
	int no;
	cout<<"Enter file name\n";
	cin>>str;
	FileX obj(str);	
	cout<<"Enter number of characters u want to read\n";
	cin>>no;
	
	obj.ReadData(no);
	return 0;
}

