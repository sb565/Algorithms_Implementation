#include<iostream>
using namespace std;

struct node
{
	int info;
	node * next;
}*top;

void display()
{
	if(top==NULL)cout<<"STACK EMPTY!!!!";
	else {
		node * temp=top;
		while(temp!=NULL)
		{
			cout<<temp->info<<'\t';
			temp=temp->next;
		}
	}
}

void push()
{
	node *n;
	n = new node;
	cout<<"ENTER THE VALUE TO BE INSERTED :";
	cin>>n->info;
	n->next=top;
	top=n;
}

void pop()
{
	if(top==NULL)cout<<"STACK EMPTY!!!!";
	else {
		cout<<"THE VALUE POPED :"<<top->info;
		node *t;
		t=top;
		top=top->next;
		delete t;
	}
}

int main()
{
	top=NULL;
	int ch;
	
	do{
	cout<<"\n MENU\n1.DISPLAY\n2.PUSH\n3.POP\n0.EXIT\nENTER CHOICE:";
	cin>>ch;
	switch(ch){
		case 1: display();
			break;
		case 2: push();
			break;
		case 3: pop();
			break;
		default: ch=-1;
	}
	}while(ch!=-1);
	return 0;
}

