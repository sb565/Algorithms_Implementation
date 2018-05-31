#include<iostream>
using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main()
{
	int n;
	cout<<"Enter the number of nodes in assembly :";
	cin>>n;
	
	int a[2][n];
	int t[2][n];
	int e[2] , x[2] ;
	
		for(int i=0;i<n;i++)
	{
		cout<<"Line 1 : Node "<<i+1<<':';
		cin>>a[0][i];
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<"Line 2 : Node "<<i+1<<':';
		cin>>a[1][i];
	}
	
	t[0][0]=0;t[1][0]=0;
	for(int i=1;i<n;i++)
	{
		cout<<"Line 1 : Transportation "<<i+1<<':';
		cin>>a[0][i];
	}
	for(int i=1;i<n;i++)
	{
		cout<<"Line 2 : Transportation "<<i+1<<':';
		cin>>a[1][i];
	}
	cout<<"Enter e1, e2:";cin>>e[0];cin>>e[1];
	cout<<"Enter x1, x2:";cin>>x[0];cin>>x[1];
 	
 	int T1[n], T2[n], i;
 
	T1[0] = e[0] + a[0][0]; 
	T2[0] = e[1] + a[1][0]; 
 

	for (i = 1; i < n; ++i)
	{
		T1[i] = min(T1[i-1] + a[0][i], T2[i-1] + t[1][i] + a[0][i]);
		T2[i] = min(T2[i-1] + a[1][i], T1[i-1] + t[0][i] + a[1][i]);
	}
	cout<<min(T1[n-1] + x[0], T2[n-1] + x[1])<<endl;
 
	return 0;
}

