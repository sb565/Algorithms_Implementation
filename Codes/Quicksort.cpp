#include<iostream>
#include<vector>
using namespace std;

int partition(vector <int> &a , int low, int high ) 
{
	int i=low+1,j=high-1;
	if(i>=j)return low;
	while(i<j){
		while(a[i]<=a[low])i++;
		while(a[j]>a[low])j--;
		
		if(i<j)swap(a[i],a[j]);
	}
	swap(a[j],a[low]);
	
	return j;
}

void quicksort(vector <int> &a, int low, int high){
	if(high-1<=low) return;
	int p=partition(a,low,high);
	quicksort(a,low,p);
	quicksort(a,p+1,high);
}


int main()
{
	
	int n;
	cout<<"ENTER THE NUMBER OF THE ELEMENTS IN THE ARRAY :";
	cin>>n;
	vector <int> a(n);
	cout<<"ENTER THE ELEMENTS :\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	quicksort(a,0,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}

