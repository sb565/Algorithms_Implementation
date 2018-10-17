#include<iostream>
#include<vector>
using namespace std;

vector <int> s;

void EnterQ(int n){
	s.insert(s.end()-1,n);
}

int ExitQ(){
	int j=s.front();
	s.erase(s.begin());
	return j;
}

void BFS(int **G, int n){
	s.push_back(-1);
	EnterQ(0);
	vector <int> visited(n);
	visited[0]=1;
	int x=ExitQ();
	while(x!=-1){
		for(int i=1;i<=G[x][0];i++){
			if(visited[G[x][i]]==0)
			{
				EnterQ(G[x][i]);
				visited[G[x][i]]=1;
			}	
		}
		cout<<x<<' ';
		x=ExitQ();
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
	BFS(G,n);
	return 0;
}
