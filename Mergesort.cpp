#include <iostream>
#include <vector>

using  namespace std;

void merge(vector<int> &a , int low , int high, int mid)
{
	vector <int> c(high-low);
	int i=low,j=mid,k=0 ;
	while(i<mid && j<high){
		if(a[i]<a[j]){
			c[k]=a[i];
			i++;
		
		}
		else{
			c[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<mid){
		c[k]=a[i];
		i++;k++;
	}
	while(j<high){
		c[k]=a[j];
		j++;k++;
	}
	
	for(i=0,j=low;j<high;j++,i++)
		a[j]=c[i];

}

void mergesort(vector<int> &a,int low ,int high){
	if(low+1>=high)return;
	int mid=(low + high)/2;
	mergesort(a,low,mid);
	mergesort(a,mid,high);
	merge(a,low,high,mid);
}

int main(){
	int n;
	cout<<"Enter the number of elements :";cin>>n;
	vector <int> a(n);
	cout<<"Enter the elements :\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergesort(a,0,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<' ';
	return 0;
}
