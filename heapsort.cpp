#include<iostream>
#include<vector>

using namespace std;

void heapify(int a[],int &n,int r)
{
	int large=r,left=(2*r),right=(2*r+1);
	if(left<=n)
		if(a[large]<a[left])
			large=left;
	if(right<=n)
		if(a[large]<a[right])
			large=right;
	if(r!=large){
		swap(a[large],a[r]);
		heapify(a,n,large);
	}
}

void createheap(int a[],int n)
{
	for(int i=n/2;i>0;i--)
	{
		heapify(a,n,i);
	}
}

void heapsort(int a[],int n)
{
	createheap(a,n);
	while(n>0){
		swap(a[n],a[1]);
		n--;
		heapify(a,n,1);
	}
}

int main()
{ 
	int n;
	cout<<"Enter the number of elements :";cin>>n;
	int arr[n+1];
	cout<<"Enter the elements :\n";
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	heapsort(arr,n);
	cout<<"elements after sorting :\n";
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<' ';
	return 0;
}
