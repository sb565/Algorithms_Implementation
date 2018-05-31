#include<iostream>
using namespace std;

int x[50],g[50][50],n,i,j,m;

void next_value(int k)
{
	while(1)
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;
		for(j=1;j<=n;j++)
		{
			if(g[k][j]!=0&&(x[k]==x[j]))
			break;
		}
		if(j==n+1)
			return;
	}
}

int coloring(int k)
{
	int c=0;
	do
	{
		next_value(k);
		if(x[k]==0)
			return c;
		if(k==n)
		{
			for(i=1;i<=n;i++)
				cout<<"v:"<<i<<" = c:"<<x[i]<<"   ";
			cout<<endl;
			c++;
		}
		else
			c+=coloring(k+1);
	}while(k<n+1);
}

int main()
{
	int e,k,l;
	cout<<"Enter no. of vertices : ";
	cin>>n;
	cout<<"Enter the number of colours :";
	cin>>m;
	cout<<"Enter no. of edges : ";
	cin>>e;
	cout<<"\nThe maximum possible colours that can be assigned are: "<<m<<endl;
	for(i=0;i<=n;i++)
	for(j=0;j<=n;j++)
		g[i][j]=0;
	cout<<"Enter u and v of an edge\n";
	for(i=1;i<=e;i++)
	{
		cout<<"for egde "<<i<<endl;
		cin>>k>>l;
		g[k][l]=1;
		g[l][k]=1;
	}
	for(i=0;i<=n;i++)
		x[i]=0;
	cout<<"\nThe colouring possibilities are:\n";
	k=coloring(1);
	if(k==0)
		cout<<"Colouring not possible \n";
	else
		cout<<"Total number of possible ways of colouring are :"<<k<<endl;
	return 0;
}


