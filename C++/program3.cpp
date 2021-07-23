#include<iostream>
using namespace std;
class Arithmetic
{
	public:		//Access specifier
		int iNo1,iNo2;		//Characteristics
		
		Arithmetic(int x,int y)		//Constructor
		{
			iNo1=x;
			iNo2=y;
		}
		
		int Addition()		//Behaviour
		{
			int iResult=0;
			iResult=iNo1+iNo2;
			return iResult;
		}
		int Subtraction()	//Behaviour
		{
			int iResult=0;
			iResult=iNo1-iNo2;
			return iResult;
		}
};
int main()
{
	int iRet1=0,iRet2=0;
	int i=0,j=0;
	cout<<"Enter first no\n";
	cin>>i;
	
	cout<<"Enter second no\n";
	cin>>j;
	Arithmetic obj1(i,j);		//object creation
	
	cout<<"Enter first no\n";
	cin>>i;
	
	cout<<"Enter second no\n";
	cin>>j;			
	Arithmetic obj2(i,j);		
	
	iRet1=obj1.Addition();
	cout<<"Addition is :"<<iRet1<<"\n";
	
		
	iRet2=obj2.Subtraction();
	cout<<"Subtraction is :"<<iRet2<<"\n";
	return 0;
}

