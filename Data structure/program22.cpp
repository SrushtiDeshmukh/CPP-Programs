/*4. Write a program which display smallest digits of all element from singly linear linked list.
void DisplaySmall( PNODE Head);
Input linked list : |11|->|250|->|532|->|415|
Output :1 0 2 1
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
void DisplaySmallDigit(PNODE Head)
{
	int iRem=0;
	int iMin=0;
	int iTemp=0;
	if(Head==NULL)
	{
		printf("LL is  empty\n");
		return ;
	}
	else
	{
		printf("Smallest digits of all elements:\n");
		while(Head!=NULL)
		{
			iMin=9;
			iTemp=Head->Data;
			while(iTemp!=0)
			{
				iRem=iTemp%10;
				if(iMin>iRem)
					iMin=iRem;
				iTemp=iTemp/10;
			}
			printf("%d\t",iMin);
			Head=Head->Next;	
		}
	}
	printf("\n");
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
		printf("\t3.Smallest digits\n");
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
			DisplaySmallDigit(First);
		}
	}while(ch!=0);

	return 0;
}
