#include<iostream>
#include<vector>

using namespace std; 


void bubblesort(vector<int> &a,int b,int n){
	if(b==n)return;
	for(int i=b;i<n-1;i++)
		if(a[i]>a[i+1])swap(a[i],a[i+1]);
	bubblesort(a,b,n-1);
}

void selectionsort(vector<int> &a,int b,int n){
	if(b>n) return;
	int min=b;
	for(int i=b+1;i<n;i++)
		if(a[i]<a[min])min=i;
	swap(a[b],a[min]);
	selectionsort(a,b+1,n);
}

void bubbleswap(vector<int> &a,int b,int e){
	
	if(b>=e) return;
	else{
		if(a[b]>a[b+1]){
			swap(a[b],a[b+1]);
		}
		bubbleswap(a,b+1,e);
	}
}

int selectmin(vector<int> &a,int min, int b,int e){
	if(b>e)return min;
	else{
		if(a[b]<=a[min])
			min =b;
		selectmin(a,min,b+1,e);
	}
}

int main()
{
	int n;
	cout<<"Enter the size of array :"; 
	cin>>n;
	vector <int> a(n);
	cout<<"Enter the elements:\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	//for(int i=0;i<n-1;i++)bubbleswap(a,0,n-1-i);
	
	//for(int i=0;i<n-1;i++){
	//	int min=selectmin(a,i,i+1,n-1);
	//	swap(a,min,i);
	//}
	//bubblesort(a,0,n);
	selectionsort(a,0,n);
	cout<<"The elements after Sorting:\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<' ';
}
