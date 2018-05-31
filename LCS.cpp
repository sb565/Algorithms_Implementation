#include<bits/stdc++.h>
using namespace std;

int lcs(int **a, int **p, string X, string Y, int m, int n )
{
	int i,j;
	for(i=0;i<=m;i++)
	for(j=0;j<=n;j++)
	{
		if(i==0||j==0)
		{
			a[i][j]=0,p[i][j]=2;
		}
		else if(X[i-1]==Y[j-1])
		{
			a[i][j]=1+a[i-1][j-1],p[i][j]=0;
		}
		else{
			if(a[i][j-1]>a[i-1][j])
				a[i][j]=a[i][j-1],p[i][j]=-1;
			else
				a[i][j]=a[i-1][j],p[i][j]=1;
		}
	}
	
	return a[m][n];
}

void lprint(int **a,int m, int n,string x)
{
	if(a[m][n]==1)
		lprint(a,m-1,n,x);
	else if(a[m][n]==-1)
		lprint(a,m,n-1,x);
	else if(a[m][n]==0){
		lprint(a,m-1,n-1,x);
		cout<<x[m-1];
	}
	else return;
}

int main()
{
	string X,Y;
	cout<<"Enter the First string  :";
	cin>>X;
	
	cout<<"Enter the Second string :";
	cin>>Y;
	
	int m = X.length();
	int n = Y.length();
	int **a=new int *[m+1],**p=new int *[m+1];
	for(int i=0;i<=m;i++){
		a[i] =new int[n+1];
		p[i] =new int[n+1];
	}
		
	
	cout<<"Lenght is :"<< lcs( a, p, X, Y, m, n )<<endl ;
	
	lprint(p,m,n,X);
	cout<<endl;
	return 0;
}
