/**
 *a wheel create by snowwolf
 *
 *History:
 *	05/23/2016:add debug info; create, print and destroy LinkList.
 **/
#ifndef _SWLIB_H_
#define _SWLIB_H_
#include<stdio.h>
#include<stdlib.h>

//print the debug info
#define DEBUG_SWITCH 0
#define dbg(fmt,args...) if(DEBUG_SWITCH){\
	printf("in %s:%d:"fmt,__FILE__,__LINE__,##args);\
	printf("\n");}

//print the node's value of LinkList
#define printList(head)\
	while(head!=NULL){\
		int flag=0;\
		if(!flag){printf("%d",head->value);flag=1;}\
		else{printf("-->%d",head->value);}\
		if(head->next!=NULL) head=head->next;\
		else {printf("\n");break;}}

//the define of the LinkList node
struct LinkNode
{
	int value;
	struct LinkNode *next;
};

//create LinkList
struct LinkNode* createList();

void destroyList(struct LinkNode** head);

struct LinkNode* createList()
{
	struct LinkNode *head=NULL,*pcur=NULL,*ptem=NULL;
	int i,n,a;
	printf("please input the numbs of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("please input the %dth node's value:",i+1);
		scanf("%d",&a);
		ptem=(struct LinkNode*)malloc(sizeof(struct LinkNode));
		if(ptem)
		{
			ptem->value=a;
			ptem->next=NULL;
			if(NULL==pcur)
				head=pcur=ptem;
			else
			{
				pcur->next=ptem;
				pcur=ptem;
			}
		}
		else
		{
			printf("new LinkList node error\n");
			return NULL;
		}
	}
	return head;
}

void destroyList(struct LinkNode** head)
{
	if(NULL==head || NULL==*head)
		return ;
	struct LinkNode* pnext=NULL;
	while(*head!=NULL)
	{
		pnext= (*head)->next;
		free (*head);
		*head=pnext;
	}
	*head=NULL;
}

#endif
