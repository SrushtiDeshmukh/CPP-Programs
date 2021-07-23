/*2. Write a program which display all palindrome elements of singly linked list.
void DisplayPallindrome( PNODE Head);
Input linked list : |11|->|28|->|17|->|414|->|6|->|89|
Output :             11 	       414    6
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
void DisplayPallindrome(PNODE Head)
{
	int iRem=0;
	int iRev=0;
	int iTemp1=0,iTemp2=0;
	if(Head==NULL)
	{
		printf("LL is  empty\n");
		return ;
	}
	else
	{
		printf("Palindrome elements :\n");
		while(Head!=NULL)
		{
			iRev=0;
			iTemp1=iTemp2=Head->Data;
			while(iTemp1!=0)
			{
				iRem=iTemp1 %10;
				iRev=(iRev*10)+iRem;
				iTemp1=iTemp1/10; 
			}
			if(iRev==iTemp2)
			{
				printf("%d\t",iRev);
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
		printf("\t3.palindrome elements\n");
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
			DisplayPallindrome(First);
		}
	}while(ch!=0);

	return 0;
}
