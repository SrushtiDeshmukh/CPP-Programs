//swapping of 2 nos using call by value.
#include<iostream>
using namespace std;

void Swap(int iNo1,int iNo2)
{
	int temp;
	temp=iNo1;
	iNo1=iNo2;
	iNo2=temp;
	cout<<"After swap iNo1 is :"<<iNo1<<"\n";
	cout<<"After swap iNo2 is :"<<iNo2<<"\n";
}

int main()
{
	int iValue1=0,iValue2=0;
	cout<<"Enter first no\n";
	cin>>iValue1;

	cout<<"Enter second no\n";
	cin>>iValue2;
	
	Swap(iValue1,iValue2);
	cout<<"After swap value1 is :"<<iValue1<<"\n";
	cout<<"After swap value2 is :"<<iValue2<<"\n";
	return 0;
}
