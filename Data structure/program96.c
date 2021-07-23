//No of ON bits in given no by recursion
#include<stdio.h>

int CountOneI(int iNo)
{
	int iMask=1;
	int i=0,iCnt=0;
	while(i<32)
	{
		if((iNo&iMask)==iMask)
		{
			iCnt++;
		}
		i++;
		iMask=iMask<<1;
	}
	return iCnt;
}

int CountOneR(int iNo)
{
	static int iMask=1;
	static int i=0,iCnt=0;
	if(i<32)
	{
		if((iNo&iMask)==iMask)
		{
			iCnt++;
		}
		i++;
		iMask=iMask<<1;
		CountOneR(iNo);
	}
	return iCnt;
}

int main()
{
	int iNo=0,iRet=0;
	printf("Enter the no\n");
	scanf("%d",&iNo);
	iRet=CountOneR(iNo);

	printf("No of 1's bit are :%d\n",iRet);
}
