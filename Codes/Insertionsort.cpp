#include<iostream>
#include<ctime>
using namespace std;

int main()
{
    clock_t x;
    x=clock();
    int n;
    cin>>n;
    int *a,t;
    a=new int(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int i,j;
    for(i=1;i<n;i++)
    {
        int val=a[i];
        for(j=i-1;j>=0 && a[j]>val;j--)
        {    
                a[j+1] = a[j];
        }
        a[j+1]=val;
    }
    for(int i=0;i<n;i++)
	{
		cout<<a[i]<<'\t';
	}
	cout<<endl;
    x=clock()-x;    
    cout<<"\nTOTAL TIME TAKEN :"<<x;
    return 0;
}

