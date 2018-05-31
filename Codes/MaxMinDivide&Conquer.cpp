#include <iostream>
#include <vector>

using  namespace std;

struct mm {
	int max;
	int min;
};

mm maxmin(mm a,mm b)
{
	mm c;
	if(a.max>b.max)c.max=a.max;
	else c.max=b.max;
	if(a.min<b.min)c.min=a.min;
	else c.min=b.min;
	return c;
}

mm maxminsearch(vector<int> &a,int low ,int high){
	if(low+1>=high){
		mm b;
		b.min=a[low];
		b.max=a[low];
		return b;
	}
	int mid=(low + high)/2;
	mm b,c;
	b=maxminsearch(a,low,mid);
	c=maxminsearch(a,mid,high);
	return maxmin(b,c);
}

int main(){
	int n;
	cout<<"Enter the number of elements :";cin>>n;
	vector <int> a(n);
	cout<<"Enter the elements :\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	mm t;
	t=maxminsearch(a,0,n);
	cout<<"Max :"<<t.max<<endl;
	cout<<"Min :"<<t.min<<endl;
	return 0;
}
