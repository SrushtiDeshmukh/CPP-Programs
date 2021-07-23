//swapping using template fun that is in generic way
#include<iostream>
using namespace std;

//specific function
void Swap(int &iNo1,int &iNo2)
{
	int temp;
	temp=iNo1;
	iNo1=iNo2;
	iNo2=temp;
}

//using Template 
template <class T>	
void SwapX(T &iNo1,T &iNo2)
{
	T temp;
	temp=iNo1;
	iNo1=iNo2;
	iNo2=temp;
}

int main()
{
	float iValue1=0,iValue2=0;
	char ch1='A',ch2='B';
	cout<<"Enter first no\n";
	cin>>iValue1;

	cout<<"Enter second no\n";
	cin>>iValue2;
	
	SwapX(iValue1,iValue2);
	SwapX(ch1,ch2);
	
	cout<<"After swap value1 is :"<<iValue1<<"\n";
	cout<<"After swap value2 is :"<<iValue2<<"\n";
	cout<<"After swap value1 is :"<<ch1<<"\n";
	cout<<"After swap value2 is :"<<ch2<<"\n";
	
	return 0;
}
