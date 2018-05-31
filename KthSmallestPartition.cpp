#include <iostream>
#include <vector>

using  namespace std;

int partition(vector <int> &a,int low, int high){
	int i,j;
	if(low>=high-1) return low;
	for(i=low,j=low;j<high;j++)
		if(a[j]<a[low])
			swap(a[i],a[j]);
	swap(a[low],a[i]);
	return i;
}

int ksmallest(vector <int> &a,int low,int high,int k){
	int i=partition(a,low,high);
	if(i==k) return a[i];
	if(i>k) return ksmallest(a,low,i-1,k);
	else return ksmallest(a,i+1,high,k);
}

void selectionsort(vector <int> &a,int n)
{
	vector <int> b(n);
	for(int i=0;i<n;i++)
	{
		b[i]=ksmallest(a,0,n,i);
	}
	
	for(int i=0;i<n;i++)
	{
		a[i]=b[i];
	}
}

int main(){
	int n;
	cout<<"Enter the number of elements :";cin>>n;
	vector <int> a(n);
	cout<<"Enter the elements :\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	selectionsort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<' ';
	return 0;
}
