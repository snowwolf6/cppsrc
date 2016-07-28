#include"swlib.h"

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
