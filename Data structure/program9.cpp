/*1. Write a program which search first occurrence of particular element from
singly linear linked list.
Function should return position at which element is found.*/
//Input linked list : |10|->|20|->|30|->|40|->|50|->|30|->|70|
//Input element : 30
//Output : 3
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
int FirstOccurence(PNODE Head,int iNo)
{
	int iCnt=0;
	if(Head==NULL)
	{
		printf("LL is  empty\n");
		return 0;
	}
	else
	{
		while(Head!=NULL)
		{
			iCnt++;		
			if(Head->Data==iNo)
			{	
				break;		
			}
			Head=Head->Next;
		}	
	}
	if(Head==NULL)
		return -1;
	else
		return iCnt;
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
		printf("\t3.First occ of given element\n");
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
			printf("Enter no u want to search\n");
			scanf("%d",&iNo);
			iRet=FirstOccurence(First,iNo);
			if(iRet==-1)
			printf("No such elements in LL\n");
			else
			printf("First occurence is %d\n",iRet);
		}
	}while(ch!=0);
	
	return 0;
}
