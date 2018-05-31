#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
        int info;
        node *next;
        node *prev;
} *start;

void display()
{
	node *temp;
	temp=start;
	if(temp==NULL)cout<<"CANNOT DISPLAY ELEMENTS OF EMPTY LIST !!!\n";
	else {
		while(temp!=NULL)
		{cout<<temp->info<<'\t';temp=temp->next;}
	}
}

void insertnode()
{
	node *p,*t;
	t=start;
	p= new node;
	cout<<"ENTER THE VALUE TO BE INSERTED :";
	cin>>p->info;
	if(start==NULL){
		p->next=NULL;
		p->prev=NULL;
		start=p;
	}
	else if(t->info>p->info){
		start=p;
		p->next=t;
		p->prev=t->prev;
		t->prev=p;
	}
	else{ 
		while(t->next!=NULL&&t->next->info<p->info)t=t->next;
		p->next=t->next;
		p->prev=t;
		if(t->next!=NULL)t->next->prev=p;
		t->next=p;
	} 
}

void deletenode()
{
	int val;
	cout<<"ENTER THE VALUE TO BE DELETED :";
	cin>>val;
	if(start==NULL)cout<<"CANNOT DELETE FROM EMPTY LIST!!!!";
	else{
		node *temp;
		temp=start;
		while(temp->next!=NULL&&temp->info<val)temp=temp->next;
		if(temp->info==val){
			if(temp->prev!=NULL)
			temp->prev->next=temp->next;
			else{start=start->next;}
			if (temp->next!=NULL)
			temp->next->prev=temp->prev;
			delete temp;
			cout<<"ELEMENT DELETED!!!";
		}
		else cout<<"\nELEMENT NOT FOUND!!!\n"; 
	}
}

int main()
{
	int choice;
        start=NULL;
        do{
        	cout<<"\nMENU\n1.DISPLAY\n2.INSERT\n3.DELETE\n0.EXIT";
        	cin>>choice;
		system("clear");
        	switch(choice)
        	{
        		case 1: display(); 
        			break;
        		case 2: insertnode(); 
        			break;
        		case 3: deletenode(); 
        			break;
        		default: choice=0;
		}
        }while(choice!=0);
}
