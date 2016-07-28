#include<stdio.h>
#include<stdlib.h>
#define printList(head) \
	while(head!=NULL){\
		bool flag=false;\
		if(!flag){printf("%d",head->value);flag=true;}\
		else{printf("-->%d",head->value);}\
		if(head->next!=NULL) head=head->next;\
		else {printf("\n");break;}}

#define DEBUG_SWITCH 1
#define dbg(fmt,args...) if(DEBUG_SWITCH)\
	{printf("in %s:%d:"fmt,\
			__FILE__,__LINE__,##args);\
		printf("\n");}

struct linkNode
{
	int value;
	struct linkNode *next;
};

void reverseList(struct linkNode** head)
{
	if(*head==NULL||head==NULL)
		return ;
	dbg("debug:%d\n",(*head)->value);
	struct linkNode *pCur=NULL,*pNext=NULL,*pPre=NULL;
	for(pCur=*head;pCur->next!=NULL;)
	{
		pNext=pCur->next;
		pCur->next=pPre;
		if(pPre&&pCur)
			dbg("debug:%d-->%d\n",pCur->value,pPre->value);
		if(pNext->next!=NULL)
		{
			pPre=pCur;
			pCur=pNext;
		}
		else
		{
			if(pNext&&pCur)
			   dbg("debug:%d-->%d\n",pNext->value,pCur->value);
			pNext->next=pCur;
			*head=pNext;
		}
	}
}

int main()
{
	int n,a,i;
	struct linkNode *head=NULL,*pcur=NULL,*ptem=NULL;
	printf("please input the numbs of node:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("please input the %dth node value:",i);
		scanf("%d",&a);
		ptem=(struct linkNode *)malloc(sizeof(struct linkNode));
		if(ptem)
		{
			ptem->value=a;
			ptem->next=NULL;
			if(pcur==NULL)
			{
				head=pcur=ptem;
			}
			else
			{
				pcur->next=ptem;
				pcur=ptem;
			}
		}
	}
	ptem=head;
	printList(ptem);
	reverseList(&head);
	printList(ptem);
	return 0;
}
