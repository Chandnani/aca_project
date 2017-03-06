#include <bits/stdc++.h>
using namespace std;
long x=1,y=1;
long int ipriority[4],opriority[4];
struct Operator
{
	char opv;
	struct Operator* next;
};

struct node
{
	long int val;
	struct node* next;
};
typedef struct node Node;
struct node* add(struct node* head,long int v){
	struct node* temp ;
	temp = (struct node*)calloc(1,sizeof(struct node));
	temp->next = head;
	temp->val = v;
	head = temp;
	return head;
}
struct Operator* addo(struct Operator* head,char v){
	struct Operator* temp ;
	temp = (struct Operator*)calloc(1,sizeof(struct Operator*));
	temp->next = head;
	temp->opv = v;
	head = temp;
	return head;
}
Node* remove(Node* op){
	op->next=op->next->next;
	return op;
}
struct Operator* remove(struct Operator* op){
	op->next=op->next->next;
	return op;
}
Node* solve(Node* no,Node* op,struct Operator* operate){

	if (operate->next->opv=='=')
	{	if (no->next->val==-1)
		{
			x=no->val;
		}
		else if(no->next->val==-2){
			y=no->val;

		}
		
		no->next->val=no->val;
		no=no->next;
		for (int i = 0; i < 3; ++i)
		{
			ipriority[i]-=4;
			opriority[i]-=4;
		}
		op->val-=4;

	}
	else{
		if (no->next->val==-1)
		{
			no->next->val=x;
		}
		else if(no->next->val==-2){
			no->next->val=y;

		}
		if (no->val==-1)
		{
			no->val=x;
		}
		else if(no->val==-2){
			no->val=y;

		}
		if (operate->next->opv=='+')
		{
			no->next->val=no->next->val+no->val;
			no=no->next;
		}
		else if (operate->next->opv=='-')
		{
			no->next->val=no->next->val-no->val;
			no=no->next;

		}
		else if (operate->next->opv=='*')
		{
			no->next->val=no->next->val*no->val;
			no=no->next;

		}
		else if (operate->next->opv=='/')
		{
			no->next->val=no->next->val/no->val;
			no=no->next;

		}
		else if (operate->next->opv=='^')
		{
			no->next->val=pow(no->next->val,no->val);
			no=no->next;

		}
	}
	
	return no;

}
int main()
{	for (int i = 0; i < 3; ++i)
	{
		ipriority[i]=i;
		opriority[i]=i;
	}
	struct Operator* operate;
	operate = (struct Operator*)calloc(1,sizeof(struct Operator));
	operate->next = NULL;

	opriority[2]=3;
	Node* op;
	Node* no;
	op =  (Node*)calloc(1,sizeof(Node));
	no =  (Node*)calloc(1,sizeof(Node));
	op->next = NULL;
	op->val=-10000;
	no->next = NULL;
	char r;
	long int z=0,w;
	cin>>r;
	while(r!='#'){

		if (r=='(')
		{
			for (int i = 0; i < 3; ++i)
			{
				ipriority[i]+=4;
				opriority[i]+=4;
			}
			cin>>r;
			continue;
		}

		else if (r==')')
		{	
			for (int i = 0; i < 3; ++i)
			{
				ipriority[i]-=4;
				opriority[i]-=4;
			}
			cin>>r;
			continue;
		}

		if ((int)r>=48&&(int)r<58)
		{	
			z=10*z + (int)r-48;
			cin>>r;
			continue;
			
		}
		else if ((r=='x')||(r=='y'))
		{	
			char tr;
			cin>>tr;
			if (r=='x')
			{
				z=-1;
			}
			else{
				z=-2;
			}
			if (tr!='=')
			{
				r=tr;
				continue;
			}
			else{
				w=3;
				operate=addo(operate,tr);
				no=add(no,z);
				z=0;
				op=add(op,ipriority[2]+1);
				for (int i = 0; i < 3; ++i)
				{
					ipriority[i]+=4;
					opriority[i]+=4;
				}
			cin>>r;
			continue;

			}
			cin>>r;
			continue;
		}
		if (r=='+')
		{	
			w=0;
			operate=addo(operate,r);

		}
		else if (r=='-')
		{
			w=0;
			operate=addo(operate,r);

		}
		else if (r=='*')
		{
			w=1;
			operate=addo(operate,r);

		}
		else if (r=='/')
		{
			w=1;
			operate=addo(operate,r);

		}
		else if (r=='^')
		{
			w=2;
			operate=addo(operate,r);

		}

		no=add(no,z);
		z=0;
		op=add(op,ipriority[w]);
		while((op->next->val>=op->val)){
			no=solve(no,op,operate);
			op=remove(op);
			operate=remove(operate);			
		}
		cin>>r;

	}
	
	no=add(no,z);
	op=add(op,0);
	operate=addo(operate,'+');
    while((op->next->val>=op->val)){
		no=solve(no,op,operate);
		op=remove(op);
		operate=remove(operate);

	}
	cout<<"x - "<<x<<endl;
cout<<"y - "<<y<<endl;
cout<<"ans - "<<no->val<<endl;


	return 0;
}