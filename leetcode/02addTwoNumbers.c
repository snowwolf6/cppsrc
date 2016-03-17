#include<stdio.h>
#include<malloc.h>

struct ListNode{
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers1(struct ListNode* l1,struct ListNode* l2)
{//由于题目中明确说明是非负数，所以用unsigned,又int可能会超范围，所以用long long
	unsigned long long a=0,b=0,sum,base=1;
	int t;
	struct ListNode *p=NULL;
	p=l1;base=1;
	while(p!=NULL)
	{
		a+=p->val*base;
		base*=10;
		p=p->next;
	}

	p=l2;base=1;
	while(p!=NULL)
	{
		b+=p->val*base;
		base*=10;
		p=p->next;
	}

	struct ListNode *res=NULL;
	struct ListNode* tem=(struct ListNode*)malloc(40*sizeof(struct ListNode));
	sum=a+b;
	tem[0].val=sum%10;
	tem[0].next=NULL;
	res=tem;
	int i=1;
	while(sum/10)
	{
		sum/=10;
		tem[i].val=sum%10;
		tem[i].next=NULL;
		tem[i-1].next=tem+i;
		i++;
	}

	return res;
}

void printList(struct ListNode *lt)
{
	int cnt=0;
	struct ListNode *p=lt;
	while(p!=NULL)
	{
		if(!cnt)
			printf("%d",p->val);
		else
			printf(" --> %d",p->val);
		p=p->next;
		cnt++;
	}
	printf("\n");
}

struct ListNode* creatList(unsigned long long num)
{
	struct ListNode* tem=(struct ListNode*)malloc(40*sizeof(struct ListNode));
	int i=0;
	struct ListNode* res=tem;
	res->val=0;
	res->next=NULL;
	while(num)
	{
		(tem+i)->val=num%10;
		(tem+i)->next=NULL;
		if(i)
			(tem+i-1)->next=tem+i;
		num/=10;
		i++;
	}
	return res;
}


struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2)
{//如果先把链表转成数字，则其表示范围会受影响，所以直接按链表模拟加法
	struct ListNode *resList=(struct ListNode*)malloc(100*sizeof(struct ListNode));
	struct ListNode *p=resList;
	int i=0,rd=0,t;
	while(l1&&l2)
	{
		t=l1->val+l2->val+rd;
		if(t>9)
		{
			(p+i)->val=t%10;
			rd=t/10;
		}
		else
		{
			(p+i)->val=t;
			rd=0;
		}
		(p+i)->next=NULL;
		if(i)
			(p+i-1)->next=(p+i);
		i++;
		l1=l1->next;
		l2=l2->next;
	}
	while(l1)
	{
		t=rd+l1->val;
		if(t>9)
			rd=t/10;
		else
			rd=0;
		(p+i)->val=t%10;
		(p+i)->next=NULL;
		if(i)
			(p+i-1)->next=p+i;
		i++;
		l1=l1->next;
	}
	while(l2)
	{
		t=rd+l2->val;
		if(t>9)
			rd=t/10;
		else
			rd=0;
		(p+i)->val=t%10;
		(p+i)->next=NULL;
		if(i)
			(p+i-1)->next=p+i;
		i++;
		l2=l2->next;
	}
	//进位后还有可能产生一个新的最高位
	if(rd)
	{
		(p+i)->val=rd;
		(p+i)->next=NULL;
		(p+i-1)->next=(p+i);
	}
	return resList;
}

int main()
{
	unsigned long long a,b;
	while(scanf("%lld %lld",&a,&b)!=EOF)
	{
		struct ListNode *la=creatList(a);
		printList(la);
		struct ListNode *lb=creatList(b);
		printList(lb);
		struct ListNode *sum=addTwoNumbers(la,lb);
		printList(sum);

		free(la);
		free(lb);
		free(sum);
	}
	return 0;
}
