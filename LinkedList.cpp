#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
	int info;
	struct node* link;
}*start, *t;

void display()
{
	system("clear");
	if(start!=NULL)
	{
		t=start;
		cout<<"The Elements in the list are :\n";
		while(t->link!=NULL){
		cout<<t->info<<"\t";
		t=t->link;
		}cout<<t->info<<"\t";
	}
	else cout<<"There are no elements in the linked list";
}

void inserttop(int val)
{

	if(start == NULL)
	{
		start = new node;
		start->info=val;
		start->link=NULL;
	}
	else
	{
		t=new node;
		t->link=start;
		t->info=val;
		start=t;
	}
}

void insertend(int val)
{
	if(start == NULL)
	{
		start=new node;
		start->info=val;
		start->link=NULL;
	}
	
	else
	{
		t=start;
		while(t->link!=NULL)
		t=t->link;
		node* n;
		n=new node;
		n->info=val;
		n->link=NULL;
		t->link=n;	
	}
}

void insertmid(int val)
{
	int i,j;
	cout<<"ENTER THE POSITION, VALUE IS TO BE PLACED AT:";
	cin>>i;
	t=start;
	if(i==1)
	{inserttop(val);}
	else
	{
		for(j=1;j<(i-1)&&t->link!=NULL;j++)
		{
			t=t->link;
		}
		if(j==i-1)
		{
			node *p = new node;
			p->info=val;
			p->link=t->link;
			t->link=p;
		}
		else
			cout<<"Can not insert at that position";
	}
}

void deletetop()
{
	if(start==NULL){cout<<"Can not delete from emplty list!!!!\n";}
	else if(start->link==NULL)
		{delete start;
		start=NULL;}
	else
		{
		t=start;
		start=start->link;
		delete t;
		t=NULL;
		}
}

void deleteend()
{
	system("clear");
	if(start!=NULL)
	{
		if(start->link==NULL)
		{
			delete start;
			start = NULL;
		}
		else
		{
			t=start;
			while(t->link->link!=NULL){
			t=t->link;
			}
			node *p;
			p=t->link;
			delete p;
			t->link=NULL;
		}
	}
	else cout<<"There are no elements in the linked list";
}

void deletemid()
{
	int i,j;
	cout<<"ENTER THE POSITION TO BE DELETED:";
	cin>>i;
	t=start;
	if(i==1)
	{deletetop();}
	else
	{
		for(j=1;j<(i-1)&&t->link!=NULL;j++)
		{
			t=t->link;
		}
		if(j==(i-1) && t->link!=NULL)
		{
			node *p = t->link;
			t->link=p->link;
			delete p;
		}
		else
			cout<<"Can not perform delete at that position";
	}
}

void clearall()
{
	while(start!=NULL)
	{
		if(start->link==NULL)
			{delete start;
			start=NULL;}
		else
			{t=start;
			start=start->link;
			delete t;
			t=NULL;
			}
	}
	cout<<"SUCCESSFULLY CLEARED SPACE!!!";
}
int main()
{
	int ch,i;
	do{cout<<"\nMENU\n1>DISPLAY\n2>INSERT-TOP\n3>DELETE-TOP\n4>INSERT-END\n5>DELETE-END\n6>INSERT-MID\n7>DELETE-MID\n0>EXIT\nENTER_YOUR_CHOICE:";
		cin>>ch;
		switch(ch)
		{
			case 1: display();
				break;
			case 2: cout<<"ENTER_THE_VALUE_TO_BE_ENTERED_AT_TOP:";
				cin>>i;
				inserttop(i);
				break;
			case 3: deletetop();
				break;
			case 4: cout<<"ENTER_THE_VALUE_TO_BE_ENTERED_AT_END:";
				cin>>i;
				insertend(i);
				break;
			case 5: deleteend();
				break;
			case 6: cout<<"ENTER_THE_VALUE_TO_BE_ENTERED_IN_MID:";
				cin>>i;
				insertmid(i);
				break;
			case 7: deletemid();
				break;
			
			default: ch=0;
			
		}
	
	}while(ch!=0);
	clearall();
	return 0;   
}
