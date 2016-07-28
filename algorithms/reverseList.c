#include<stdio.h>
#include"/home/sw/src/swlib/swlib.h"

void reverseList(struct LinkNode** head)
{
	if(*head==NULL||head==NULL)
		return ;
	struct LinkNode *pCur=NULL,*pNext=NULL,*pPre=NULL;
	for(pCur=*head;pCur!=NULL;)
	{
		pNext=pCur->next;
		pCur->next=pPre;
		if(pPre!=NULL)
			dbg("%d-->%d",pCur->value,pPre->value);
		pPre=pCur;
		pCur=pNext;
	}
	*head=pPre;
}

int main()
{
	struct LinkNode *head=NULL,*iter=NULL;
	head=createList();
	if(NULL!=head)
	{
		iter=head;
		printList(iter);
		reverseList(&head);
		iter=head;
		printList(iter);
		destroyList(&head);
	}
	return 0;
}
