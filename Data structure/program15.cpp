/*2. Write a program which displays all elements which are prime from singly linear linked list.
Input linked list : |11|->|20|->|17|->|41|->|22|->|89|
Output : 11 17 41 89
int DisplayPrime( PNODE Head);
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
void DisplayPrime(PNODE Head)
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
		printf("elements which are prime\n");
		while(Head!=NULL)
		{
			iSum=0;
			for(i=2;i<=(Head->Data)/2;i++)
			{
				if((Head->Data)%i==0)
				{
					break;
				}
			}
			if(i>(Head->Data)/2)
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
		printf("\t3.Prime elements\n");
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
			DisplayPrime(First);
		}
	}while(ch!=0);

	return 0;
}
