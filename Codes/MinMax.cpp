#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    vector<Node *>child;
};

int minimax(Node *a,int minmax)
{
	if(a->child.empty())return a->val;
	int val;
	a->val=minimax(a->child[0],!minmax);
	for(int i=1;i<a->child.size();i++){
		val=minimax(a->child[i],!minmax);
		if(minmax==1){
			if(val>a->val)a->val=val;
		}
		else{
			if(val<a->val)a->val=val;
		}
	}
	return a->val;
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
	Node *root;
	root = new Node;
	char ch='y';
	enter(root);
	cout<<minimax(root,1);
}