/*4. Write a program which return second maximum element from singly linear linked list.
int SecMaximum( PNODE Head);
Input linked list : |110|->|230|->|320|->|240|
Output : 240
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int Data;
	struct node *Next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;
void InsertLast(PPNODE Head,int iNo)
{
	PNODE newn=NULL;
	PNODE temp=*Head; 
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->Data=iNo;
	newn->Next=NULL;

	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		while(temp->Next!=NULL)
		{
			temp=temp->Next;
		}
		temp->Next=newn;
	}
}
int SecMaximum(PNODE Head)
{
	int iMax=0;
	int SecMax=0;
	if(Head==NULL)
	{
		printf("LL is  empty\n");
		return 0;
	}
	else if(Head->Next==NULL)
	{
		printf("LL contains only one element\n");
		return 0;
	}
	else
	{
		while(Head!=NULL)
		{
			if((Head->Data) > iMax)
			{
				SecMax=iMax;
				iMax=Head->Data;
			}
			else if(((Head->Data) > SecMax) && (Head->Data)!=iMax)
			{
				SecMax=Head->Data;
			}
			Head=Head->Next;
		}	
	}
	return SecMax;
}
void Display(PNODE Head)
{
	while(Head!=NULL)
	{
		printf("|%d|->\t",Head->Data);
		Head=Head->Next;
	}
	printf("NULL\n");
}
int main()
{
	PNODE First=NULL;
	int ch=0;
	do
	{
		printf("\t1.Insert element\n");
		printf("\t2.Display\n");
		printf("\t3.Second Maximum elements\n");
		printf("\t0.Exit\n");
		
		printf("Enter choice\n");
		scanf("%d",&ch);
		
		if(ch==1)

		{
			int iValue=0;
			printf("Enter no u want to insert\n");
			scanf("%d",&iValue);
			InsertLast(&First,iValue);
		}		
		else if(ch==2)
		{
			Display(First);
		}
		else if(ch==3)
		{
			int iNo=0;
			int iRet=0;
			iRet=SecMaximum(First);
			printf("Second Maximum elements is %d\n",iRet);
		}
	}while(ch!=0);
	
	return 0;
}
