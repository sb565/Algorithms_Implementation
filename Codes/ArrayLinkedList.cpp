#include<iostream>
#include<cstdlib>

using namespace std;

int avail,start;
const int n=10;

struct nodes{
	int link;
	int info;
}node[n];

void init()
{
	avail=0;
	start=-1;
	for(int i=0;i<n-1;i++)
	node[i].link=i+1;
	node[n-1].link=-1;
}

void display()
{
	int t;
	t=start;
	if(t==-1)cout<<"NO ELEMENTS TO DISPLAY!!!";
	else{
		cout<<node[t].info<<'\t';
		while(node[t].link!=-1){
			t=node[t].link;
			cout<<node[t].info<<'\t';
		}	
	}
}

void insertnode(){
	if(avail==-1){cout<<"CANNOT ENTER MORE NODES !!! DELETE SOME NODES FIRST !!!";}
	else {
		int t,temp;
		temp=avail;
		t=start;
		avail = node[avail].link;
		cout<<"ENTER THE VALUE TO BE INSERTED :";
		cin>>node[temp].info;
		if(t==-1||node[temp].info<node[t].info)
		{	
			node[temp].link=start;
			start=temp;
		}
		else
		{
			while(node[t].link!=-1&&node[node[t].link].info<node[temp].info)t=node[t].link;
			node[temp].link=node[t].link;
			node[t].link=temp;
		}
	}
}

void deletenode(){
	int val;
	cout<<"ENTER THE VALUE TO BE DELETED :";
	cin>>val;
	int t = start;
	if(node[t].info==val){
		start=node[start].link;
		node[t].link=avail;
		avail=t;
	}
	else{
		while(node[t].link!=-1&&node[node[t].link].info!=val)t=node[t].link;
		if(node[t].link==-1)cout<<"ELEMENT NOT FOUND!!!";
		else{
			int temp = node[t].link;
			node[t].link=node[temp].link;
			node[temp].link=avail;
			avail=temp;
		}
	}
}

int menu()
{
	system("clear");
	int choice;
	cout<<"MENU\n";
	cout<<"1.DISPLAY\n";
	cout<<"2.INSERT\n";
	cout<<"3.DELETE\n";
	cout<<"0.EXIT\n";
	cout<<"ENTER CHOICE :";
	cin>>choice;
	switch(choice)
	{
		case 1: display();
			break;
		case 2: insertnode();
			break;
		case 3:deletenode();
			break;
		default:choice=-1;
	}
	return choice;
}

int main()
{
	init();
	int ch;
	do{ch=menu();
	}while(ch!=-1);
	return 0;
}
