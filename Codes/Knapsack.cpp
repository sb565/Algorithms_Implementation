#include<iostream>
#include<algorithm>
using namespace std;

struct val {
	int profit;
	int weight;
};

bool valsort(val a,val b){
	float m=(float)a.profit/a.weight;
	float n=(float)b.profit/b.weight;
	if(m>n)return true;
	else return false;
}

float knapsack(val a[],int n,int w){
	float x[n],profit=0;
	for(int i=0;i<n;i++)x[i]=0;
	for(int i=0;i<n;i++)
	{
		if(w>a[i].weight){
			w=w-a[i].weight;
			x[i]=1;
		}
		else{
			x[i]=(float)w/a[i].weight;
			break;
		}
	}
	for(int i=0;i<n;i++)
		profit+=a[i].profit*x[i];
	return profit; 
}

int main(){
	int n,k;
	cout<<"No of valuse to be inserted:";cin>>n;
	val a[n];
	for(int i=0;i<n;i++){
		cout<<"profit:";cin>>a[i].profit;
		cout<<"weight:";cin>>a[i].weight;
	}
	sort(a,a+n,valsort);
	cout<<"Enter tne max weight:";cin>>k;
	cout<<knapsack(a,n,k);
}
