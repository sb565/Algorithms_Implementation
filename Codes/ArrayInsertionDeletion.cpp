#include<iostream>
#define size 10
using namespace std;
int a[size],l=-1;

void insertarr(){
	int val;
	cout<<"\nENTER THE VALUE";
	cin>>val;
	if(l+1==size)
	cout<<"CANNOT INSERT ARRAY FULL!!!!";
	else
	{
		l++;
		a[l]=val;
		cout<<"ELEMENT INSERTED";
	}
}

void deletearr(){
	int val,fl=0;
	cout<<"ENTER THE VALUE TO BE DELETED :";
	cin>>val;
	for(int i=0;i<=l;i++)
	{
		if(fl==1)
			a[i-1]=a[i];
		if(a[i]==val)
			fl=1;
		
	}
	if(fl==1){l--;cout<<"ELEMENT DELETED";}
	if(fl==0)cout<<"\nELEMENT NOT FOUND";
}

void display(){
	if(l==-1)cout<<"\n EMPTY ARRAY";
	else{
		cout<<"\nTHE ELEMENTS IN THE ARRAY ARE :\n";
		for(int i=0;i<=l;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
}

int main()
{
	int ch=3;
	do{
	cout<<"\n0.DISPLAY ARRAY";
	cout<<"\n1.INSERT INTO ARRAY";
	cout<<"\n2.DELETION INTO ARRAY";
	cout<<"\n3.EXIT";
	cin>>ch;
	if(ch==0)display();
	if(ch==1)insertarr();
	if(ch==2)deletearr();
	}while(ch!=3);
}
