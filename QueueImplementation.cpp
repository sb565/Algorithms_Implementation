#include<iostream>
using namespace std;

struct node{
	int info;
	struct node* link;
}*rear,*front, *t;

void display()
{
	if(front != NULL)
	{
		t=front;
		cout<<"The Elements in the list are :\n";
		while(t->link!=NULL){
		cout<<t->info<<"\t";
		t=t->link;
		}cout<<t->info<<"\t";
	}
	else cout<<"There are no elements in the queue";
}


void insertrear(int val)
{
	if(rear == NULL)
	{
		rear=front=new node;
		rear->link=NULL;
		rear->info=val;
	}
	
	else
	{
		rear->link=new node;
		rear=rear->link;
		rear->info=val;	
		rear->link=NULL;
	}
}



void deletefront()
{
	if(front==NULL){cout<<"Can not delete from emplty list!!!!\n";}
	else if(rear==front)
	{
		cout<<"The value deleted is :"<<rear->info<<endl;
		delete rear;
		rear=front=NULL;
	}
	else
	{
		node *ptr;
		ptr=front;
		front =front->link;
		cout<<"The value deleted is :"<<ptr->info<<endl;
		delete ptr;
	}
}


int main()
{
	int ch,i;
	front=rear=NULL;
	do{cout<<"\nMENU\n1>DISPLAY\n2>INSERT IN QUEUE\n3>DELETE FOM QUEUE\n0>EXIT\nENTER_YOUR_CHOICE:";
		cin>>ch;
		switch(ch)
		{
			case 1: display();
				break;
			case 2: cout<<"ENTER THE VALUE TO BE INSERTED AT REAR END :";
				cin>>i;
				insertrear(i);
				break;
			case 3: deletefront();
				break;
			
			default: ch=0;
			
		}
	
	}while(ch!=0);
	return 0;   
}
