#include<iostream>
using namespace std;

int binser(int *a,int beg,int end,int val)
{
	int mid;
	if(beg<=end){
		mid=(beg+end)/2;
		if(a[mid]==val)
		return mid;
		else if(val<a[mid])
			return binser(a,beg,mid-1,val);
		else
			return binser(a,mid+1,end,val);
	}
	return -1;
}

int main()
{
	int n;
	cout<<"Enter the number of elements :";
	cin>>n;
	int *a;
	a=new int(n);
	cout<<"Enter the elements:"<<endl;
	for(int i=0;i<n;i++)
	cin>>a[i];
	int val,fl;
	cout<<"Enter the value to be searched :";
	cin>>val;
	fl=binser(a,0,n-1,val);
	
	if(fl==-1)cout<<"Element not found";
	else cout<<"Element found at position:"<<fl;
        return 0;
}

