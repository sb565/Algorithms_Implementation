#include <iostream>

using namespace std;

struct activity
{
	int start;
	int end;
	int no;
};

int sortEnd(activity A[], int n)
{
		for(int i=0; i<n; i++)
		for(int j=0; j<n-1-i; j++)
			if(( A[j].end) > ( A[j+1].end))
				swap(A[j],A[j+1]);
}

void Compatible(activity A[], int n)
{	
	int count=1, j=0;
	sortEnd(A,n);

	for(int i=1; i<n; i++)
	{
		if(A[j].end <= A[i].start)
		{	
			cout<<"Activity "<<A[j].no<<" is compatible with "<<A[i].no<<endl;
			j = i;
			count++;
		}
	}

	cout<<"\nMaximum compatible activities are "<<count<<endl;
}

int main()
{
	int n;
	cout<<"Enter the number of activities :";cin>>n;
	cout<<"Enter the details of activities\n";
	activity A[n];
	for(int i=0;i<n;i++)
	{
		A[i].no=i;
		cout<<"Start:";cin>>A[i].start;
		cout<<"End:";cin>>A[i].end;
	}
	Compatible(A,n);
	return 0;
}
