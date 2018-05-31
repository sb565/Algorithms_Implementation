#include<iostream>
#include<ctime>
using namespace std;

struct node{
	int info;
	node *left;
	node *right;
}*root;

node * insertnode(node * r,int val){
	if(r==NULL)
	{
		node *p;
		p=new node;
		p->info=val;
		p->left=NULL;
		p->right=NULL;
		return p;
	}
	else if(r->info==val)
	{
		cout<<"\nVALUE ALREADY EXISTS!!!";
	}
	else if(r->info>val)
	{
		r->left=insertnode(r->left,val);
	}
	else
	{
		r->right=insertnode(r->right,val);
	}
	return r;

}

int treen(node *r)
{
	int val=0;
	if(r==NULL)
	return val;
	int x=0,y=0;
	x=treen(r->left);
	y=treen(r->right);
	val++;
	val+=x+y;
	return val; 
}

int treel(node *r)
{
	int val=0;
	if(r==NULL)
	return val;
	int x=0,y=0;
	x=treel(r->left);
	y=treel(r->right);
	val++;
	val+=x>y?x:y;
	return val; 
}

void traversal(node * r,int val){
	if(r!=NULL)
	{
		if(val==0)cout<<r->info<<' ';
		
		traversal(r->left,val);
		if(val==1)cout<<r->info<<' ';
		
		traversal(r->right,val);
		if(val==2)cout<<r->info<<' ';
	}
}



void display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	}
        cout<<ptr->info;
        display(ptr->left, level+1);
    }
}

int main()
{
	clock_t t;
	t=clock();
	int choice=0,value;
	root= NULL;
	do{
	cout<<"\nMenu\n";
	cout<<"1.INSERT INTO BINARY TREE\n";
	cout<<"2.PRE-ORDER TRAVERSAL\n";
	cout<<"3.IN-ORDER TRAVERSAL\n";
	cout<<"4.POST-OREDER TRAVERSAL\n";
	cout<<"5.LENGTH\n";
	cout<<"6.NUMBER OF NODES\n";
	cout<<"0.EXIT\nENTER CHOICE : ";
	cin>>choice;
	switch(choice)
	{
		case 0: display(root,1);
			break;
		case 1:	cout<<"ENTER THE VALUE TO BE INSERTED :";
			cin>>value;
			root=insertnode(root,value);
			break;
		case 2:	cout<<endl;
			traversal(root,0);
			cout<<endl;
			break;
		case 3:	cout<<endl;
			traversal(root,1);
			cout<<endl;
			break;
		case 4:	cout<<endl;
			traversal(root,2);
			cout<<endl;
			break;
		case 5: value=treel(root);
			cout<<endl<<value-1<<endl;
			break;
		case 6: value=treen(root);
			cout<<endl<<value<<endl;
			break;
		default :choice=0;
	}
	
	}while(choice!=0);
	t=clock()-t;
	cout<<"\nTOTAL TIME TAKEN :"<<t;
	return 0;
}
