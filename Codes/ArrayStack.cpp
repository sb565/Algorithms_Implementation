#include<iostream>
#define size 100
using namespace std;

int a[size],l=-1; 

void push(){
	int val;
	cout<<"\nENTER THE VALUE";
	cin>>val;
	if(l+1==size)
	cout<<"CANNOT INSERT STACK FULL!!!!";
	else
	{
		l++;
		a[l]=val;
		cout<<"ELEMENT INSERTED";
	}
}

void pop(){
	if(l==-1)cout<<"/n STACK EMPTY CANNOT DELETE!!!!!!";
	else 
	{
		cout<<"VALUE POPPED :"<<a[l];
		l--; 
	}
}


int main()
{
	int ch=3;
	do{
	cout<<"\n1.PUSH INTO STACK";
	cout<<"\n2.POP FROM STACK";
	cout<<"\n3.EXIT";
	cin>>ch;
	if(ch==1)push();
	if(ch==2)pop();
	}while(ch!=3);
}
