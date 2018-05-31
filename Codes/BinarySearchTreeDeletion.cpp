#include<iostream>
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

int findpre(node * r){
	node * ptr,*prev;
	int val;
	ptr=r->right;
	if(ptr->left==NULL)
	{
		r->right=ptr->right;
		val=ptr->info;
		delete ptr;
		return val; 
	}
	prev=r;
	while(ptr->left!=NULL){
	prev=ptr;
	ptr=ptr->left;
	}
	prev->left=ptr->right;
	val=ptr->info;
	delete ptr;
	return val; 
}
node * deletenode(node * r, int val){
	if(r==NULL){
		cout<<"ELEMENT NOT FOUND!!!!";
		return r;
	}
	else if(val==r->info)
	{
		node * ptr;
		if(r->left==NULL)
		{
			ptr=r->right;
			delete r;
			return ptr;
		}
		if(r->right==NULL)
		{
			ptr=r->left;
			delete r;
			return ptr;
		}
		r->info=findpre(r);
	}
	else if(r->info<val)r->right=deletenode(r->right,val);
	else r->left=deletenode(r->left,val);
	return r;
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

int search(node * r ,int val){
	if(r!=NULL)
	{
		if(r->info==val)return 1;
		if(r->info>val)
		return search(r->left,val);
		else return search(r->right,val);
	}
	return 0;
}

int main()
{
	int choice=0,value;
	root= NULL;
	do{
	cout<<"\nMenu\n";
	cout<<"1.INSERT INTO BINARY TREE\n";
	cout<<"2.DELETE NODE FROM TREE\n";
	cout<<"3.DISPLAY TREE\n";
	cout<<"4.SEARCH VALUE\n";
	cout<<"0.EXIT\nENTER CHOICE : ";
	cin>>choice;
	switch(choice)
	{
		case 3: display(root,1);
			break;
		case 1:	cout<<"ENTER THE VALUE TO BE INSERTED :";
			cin>>value;
			root=insertnode(root,value);
			break;
		case 2: cout<<"ENTER VALUE TO BE DELETED :";
			cin>>value;
			root = deletenode(root, value);
			break;
		case 4: cout<<"ENTER THE VALUE TO BE SEARCHED :";
			cin>>value;
			value=search(root,value);
			if(value==0)cout<<"ELEMENT NOT FOUND\n";
			else cout<<"ELEMENT FOUND\n";
			break;
		default :choice=0;
	}
	
	}while(choice!=0);
	return 0;
}
