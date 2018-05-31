#include<iostream>
#include<cmath>
using namespace std;

bool check(int a, int b, int c ,int d){
	if(b==d||abs(a-c)==abs(b-d))
		return false;
	return true;
}

void qprint(int x[],int n)
{
	for(int j=0;j<n;j++)
		cout<<"__";
	cout<<"_"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<'|';
		for(int j=0;j<n;j++)
		{
			if(x[i]==j)
				cout<<'X'<<'|';
			else
				cout<<"_|";
		}
		cout<<endl;
		
	}
	cout<<endl<<endl;
}

int nqueen(int x[],int n,int k)
{
	int count=0; 
	
	for(int i=0;i<k-1;i++)
	for(int j=i+1;j<k;j++)
		if(check(i,x[i],j,x[j])==false)
			return 0;
	
	if(k==n)
		{
			qprint(x,n);
			count++;
		}
	else{
		for(int i=0;i<n;i++)
		{
			x[k]=i;
			count+=nqueen(x,n,k+1);
		}
	}
	return count;
}

int main()
{
	int n;
	cout<<"Enter the size :";
	cin>>n;
	int a[n];
	cout<<"The results are :\n";
	cout<<"Total number of possible results :"<<nqueen(a,n,0)<<endl;
	return 0;
}
