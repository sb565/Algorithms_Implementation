#include<iostream>
#include<vector>
using namespace std;

vector <int> s;

void push(int n){
	s.push_back(n);
}

int pop(){
	int j=s.back();
	s.pop_back();
	return j;
}

void DFS(int **G, int n){
	push(-1);
	push(0);
	vector <int> visited(n);
	visited[0]=1;
	int x=pop();
	while(x!=-1){
		for(int i=G[x][0];i>0;i--){
			if(visited[G[x][i]]==0)
			{
				push(G[x][i]);
				visited[G[x][i]]=1;
			}	
		}
		cout<<x<<' ';
		x=pop();
	}
	cout<<endl;
}

int main(){
	int n;//number of Nodes;
	cout<<"Enter the number of Nodes :";
	cin>>n;
	
	int **G = new int*[n];
	
	for(int i=0,k;i<n;i++)
	{
		cout<<"Enter the number of adjacent nodes to node "<<i<<':';
		cin>>k;
		G[i] = new int[k+1];
		G[i][0]=k;
		for(int j=1;j<=k;j++){
			cout<<"Enter adjacent node:";
			cin>>G[i][j];
		}
	}
	cout<<"The Order of DFS\n";
	DFS(G,n);
	return 0;
}
