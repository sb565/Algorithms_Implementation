#include<iostream>
using namespace std;

int main()
{
	int x,fl=0,i;
	int arr[]= {2,3,1,4,8,9,6,5,7,15,17,14,16,20,24,38,43,50};
	cout<<"ENTER THE VALUE TO BE SEARCHED :";
	cin>>x;
	for(i=0;i<18;i++)
	{
		if(arr[i]==x){
		fl=1;
		break;
		}
	}
	
	if(fl==1)
	{
		cout<<"ELEMENT "<<x<<" FOUND AT LOCATION "<<i+1;
	}
	else
	cout<<"ELEMENT NOT FOUND";
	return 0;
}
