#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

struct Node
{
    int val;
    vector<Node *>child;
};

int max(int a, int b){
	return a>b?a:b;
}

int min(int a, int b){
	return a<b?a:b;
}


int minimax(Node *nn,int minmax,int a, int b)
{
	if(nn->child.empty())return nn->val;
	int val;
	nn->val=minimax(nn->child[0],!minmax,a,b);
	for(int i=1;i<nn->child.size();i++){
		val=minimax(nn->child[i],!minmax,a,b);
		if(minmax==1){
			a=max(a,val);
			if(a>=b)return b;
			nn->val=max(nn->val,val);
		}
		else{
			b=min(b,val);
			if(a>=b)return a;
			nn->val=min(nn->val,val);
		}
	}
	return nn->val;
}

void enter(Node *a){
	static int k=1;
	int n;
	cout<<"Enter number of children for node "<<k<<":";
	cin>>n;
	Node *newn;
	for(int i=0;i<n;i++){
		newn=new Node;
		a->child.push_back(newn);
		k++;
		enter(a->child[i]);
	}
	if(n==0){
		cout<<"Enter value for node : ";
		cin>>a->val;
	}
}

int main()
{
	int a,b;
	a=-1;
	b=INF;
	Node *root;
	root = new Node;
	char ch='y';
	enter(root);
	cout<<minimax(root,1,a,b);
}
