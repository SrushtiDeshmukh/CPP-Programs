/*5. Write a program which return smallest element from singly linear linked list.
Input linked list : |110|->|230|->|20|->|240|->|640|
Output : 20
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
int Minimum(PNODE Head)
{
	int iMin=0;
	if(Head==NULL)
	{
		printf("LL is  empty\n");
		return 0;
	}
	else
	{
		iMin=Head->Data;
		while(Head!=NULL)
		{
			if(iMin>Head->Data)
			{
				iMin=Head->Data;
			}
			Head=Head->Next;
		}	
	}
	return iMin;
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
		printf("\t3.Minimum elements\n");
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
			iRet=Minimum(First);
			printf("Minimum elements is %d\n",iRet);
		}
	}while(ch!=0);
	
	return 0;
}
