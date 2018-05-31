#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
	int info;
	node * link;
}header,*start;

void display();
void insertnode();
void deletenode();
void clearall();

int main()
{
	start=&header;
	start->link=start;
	start->info=0;
	int ch;
	do{
	cout<<"Menu\n1.Display\n2.Instertion\n3.Deletion\n0.Exit";
	cin>>ch;
	switch(ch)
	{
		case 1: display();
			break;
		case 2: insertnode();
			break;
		case 3: deletenode();
			break;
		default:ch=0;
	}
	}while(ch!=0);	
	return 0;
}

void display()
{
	node *temp;
	temp=start->link;
	cout<<"Total no. of nodes:"<<start->info<<endl;
	if(start->link==start)cout<<"No elements in the list!!!";
	else{
		while(temp!=start)
		{
			cout<<temp->info<<"\t";
			temp=temp->link;
		}
		cout<<endl;
	}
}

void insertnode()
{
	node * temp,*p;
	temp=start;
	p=new node;
	cout<<"\nEnter the value to be inserted:";
	cin>>p->info;
	while(temp->link!=start&&p->info>temp->link->info)temp=temp->link;
	p->link=temp->link;
	temp->link=p;
	start->info++;
}

void deletenode()
{
	int val;
	cout<<"\nEnter the value to be deleted:";
	cin>>val;
	node *temp;
	temp=start->link;
	if(start->link==start)cout<<"No elements in the list cannot delete!!!";
	else{
		while(temp->link!=start&&val>temp->link->info)temp=temp->link;
		if(temp->link==start)cout<<"Cannot delete. Element not found!!!";
		else{node *ptr;
			ptr=temp->link;
			temp->link=ptr->link;
			delete ptr;
			cout<<"\nNode deleted\n";
			start->info--;
		}
	}
	
}
