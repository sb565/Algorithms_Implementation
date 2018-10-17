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


void IDS(int **G, int n, int t,int max_depth){
	cout<<"Level 0:"<<0;
	if(t==0){
		cout<<endl<<"Found at level 0 ";
		return;
	} 
	int fl=0;
	for(int k=1;k<=max_depth;k++){
		int q;
		cout<<endl<<"Level "<<k<<":";
		s.clear();
		s.push_back(-1);
		vector <int> visited(n);
		for(int i=0;i<n;i++)visited[i]=-1;
		visited[0]=0;
		int x=0;
		while(x!=-1){
			if(x==t)fl=1;
			for(int i=G[x][0];i>0;i--){
				if(visited[G[x][i]]==-1)
				{
					if(k-(visited[x]+1)>=0)
					{
						push(G[x][i]);
						visited[G[x][i]]=visited[x]+1;
					}
				}	
			}
			cout<<x<<' ';
			x=pop();
			
		}
		if(fl==1){
			cout<<endl<<"Found at level "<<k<<endl;
			break;
		}
	}
	if(fl==0){
		cout<<endl<<"Element not found";
	}
}

int main(){
	int n,x,d;//number of Nodes;
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
	
	cout<<endl;
	cout<<"Enter the node to be searched :";
	cin>>x;
	cout<<"Enter the depth to be searched :";
	cin>>d;
	cout<<"The Order of DFS\n";
	IDS(G,n,x,d);
	return 0;
}
