#include<iostream>
using namespace std;

struct node{
	int info;
	struct node* link;
}*top1,*top2,*top3;

node * insertnode(node *start)
{
	int val	;
	cout<<"\nEnter the value to be inserted:";
	cin>>val;
	if(start==NULL)
	{
		start=new node;
		start->info=val;
		start->link=NULL;
		
	}
	else{
		node *p,*temp=start;
		while(temp->link!=NULL&&val>temp->link->info)temp=temp->link;
		p=new node;
		p->info=val;
		p->link=temp->link;
		temp->link=p;
	}
	return start;
}

void display(node *t)
{
	if(t!=NULL)
	{	
		cout<<"The Elements in the list are :\n";
		while(t->link!=NULL){
		cout<<t->info<<"\t";
		t=t->link;
		}cout<<t->info<<"\t";
	}
	else cout<<"There are no elements in the linked list";
}

int main()
{
	top1=top2=top3=NULL;
	char ch;
	do{
	top1=insertnode(top1);
	cout<<"Insert values into list 1 (y/n) :";
	cin>>ch;
	}while(ch=='Y'||ch=='y');
	do{
	top2=insertnode(top2);
	cout<<"Insert values into list 2 (y/n) :";
	cin>>ch;
	}while(ch=='Y'||ch=='y');
	node *t;
	t=top3=new node;
	while(top1!=NULL||top2!=NULL)
	{
		if(top1==NULL){
		t->link=top2;
		top2=top2->link;
		t=t->link;
		}
		else if(top2==NULL){
		t->link=top1;
		top1=top1->link;
		t=t->link;
		}
		else{
			if(top1->info<top2->info){
			t->link=top1;
			top1=top1->link;
			t=t->link;
			}
			else{
			t->link=top2;
			top2=top2->link;
			t=t->link;
			}
			
		}
	}
	display(top3->link);
	
	return 0;
}
