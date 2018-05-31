#include<iostream>
#include<algorithm>
using namespace std;

int printsub(int a[],int x[], int n){
	cout<<"Solution :";
	for(int i=0;i<n;i++)
		if(x[i]==1){
			cout<<a[i]<<' ';
		}
	cout<<endl;
}

int subsum( int a[], int x[], int s, int r, int n, int m, int k)
{
	int c=0;
	if(k==n)return c;
	x[k]=1;
	if(s+a[k]==m)
	{
		printsub(a,x,n);
		c++;
		x[k]=0;
	}
	else{
 		if(s+a[k] < m)
			c+=subsum(a,x,s+a[k],r-a[k],n,m,k+1);
		x[k]=0;
		if(r-a[k]+s>=m) 
			c+=subsum(a,x,s,r-a[k],n,m,k+1);
	}
	return c;
}
int main()
{
	unsigned int n,m,sum=0;
	cout<<"Enter the size of array :";
	cin>>n;
	int a[n],x[n];
	cout<<"Enter the elements of set :\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		x[i]=0;
	}
	sort(a,a+n);
	cout<<"Enter the desired sum :";cin>>m;
	cout<<"The desired possible solutions can be :\n";
	n=subsum(a,x,0,sum,n,m,0);
	if(n==0)
		cout<<"\nNo results found";
	else
		cout<<"Total number of results are :"<<n<<endl;
	return 0;
}
