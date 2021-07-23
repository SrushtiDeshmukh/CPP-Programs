/*1. Write a program which displays all elements which are perfect from singly linear linked list.
int DisplayPerfect( PNODE Head);
Input linked list : |11|->|28|->|17|->|41|->|6|->|89|
Output :6 28
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
void DisplayPerfect(PNODE Head)
{
	int i=0;
	int iSum=0;
	if(Head==NULL)
	{
		printf("LL is  empty\n");
		return ;
	}
	else
	{
		printf("elements which are perfect\n");
		while(Head!=NULL)
		{
			iSum=0;
			for(i=1;i<=((Head->Data)/2);i++)
			{
				if((Head->Data)%i==0)
				{
					iSum=iSum+i;	
				}
			}
			if((Head->Data)==iSum)
			{
				printf("%d\t",Head->Data);
			}
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
		printf("\t3.Perfect elements\n");
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
			DisplayPerfect(First);
		}
	}while(ch!=0);

	return 0;
}
