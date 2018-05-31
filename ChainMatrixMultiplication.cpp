#include<iostream>
#define INTMAX 10000
using namespace std;
int L[100][100];
void Pathprint(int i,int j){
	if(i==j)cout<<"A"<<i<<' ';
	else
	{
		cout<<"( ";
		Pathprint(i,L[i][j]);
		Pathprint(L[i][j]+1,j);
		cout<<") ";
	}
}

int matmul(int a[],int n){
	int p[n][n];
	for(int i=0;i<=n;i++)
		p[i][i]=0;
		
	for(int t=2;t<n;t++){
		int i=1;
		for(int j=t;i<=n-t;i++,j++){
			int min=INTMAX,pos;unsigned long long int q;
			for(int k=i;k<j;k++){
				q= p[i][k] + p[k+1][j] + a[i-1]*a[k]*a[j];
				if(q<min){
					min=q;
					pos=k;
				}
			}
			L[i][j]=pos;
			p[i][j]=min;
		}
	}
	Pathprint(1,n-1);
	return p[1][n-1];
}

int main()
{
	int n;
	cout<<"Enter n:";cin>>n;
	int a[n];
	cout<<"Enter dimentions :\n";
	for(int i=0; i<n;i++)
	{
		cin>>a[i];
	}
	cout<<endl<<"Minimum Cost :"<<matmul(a,n)<<endl;
}

