//Addition of array elements by recursion
#include<stdio.h>
#include<stdlib.h>

int SumI(int *Arr,int iSize)
{
	int i=0,iSum=0;
	while(i<=iSize)
	{
		iSum=iSum+Arr[i];
		i++;
	}
	return iSum;
}

int SumR(int *Arr,int iSize)
{
	static int i=0,iSum=0;
	if(i<=iSize)
	{
		iSum=iSum+Arr[i];
		i++;
		SumR(Arr,iSize);
	}
	return iSum;
}

int main()
{
	int *ptr=NULL;
	int iRet=0,iLen=0,iCnt=0;
	
	printf("Enter size of array\n");
	scanf("%d",&iLen);

	ptr=(int*)malloc(sizeof(int)*iLen);

	printf("Enter array elemets\n");
	while(iCnt<iLen)
	{		
		scanf("%d",&ptr[iCnt]);
		iCnt++;
	}
	iRet=SumR(ptr,iLen);
	printf("Addition is :%d\n",iRet);
	free(ptr);
	
	return 0;
}
