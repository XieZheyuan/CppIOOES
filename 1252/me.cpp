#include<iostream>
#include<queue>
using namespace std;
//Is Node Seeked
int flag[50][50];
//Go Poses
int pos[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
//Map
char map[50][50];
//Node Define 
struct Node{
	int x=0,y=0,c=0;
	Node(int a, int b, int s){
		//constructor function
		x=a;
		y=b;
		c=s;
	}
	
};
int main(int *argc,char **argv){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char temp;
			cin>>temp;
			map[i+1][j+1]=temp;
			
		}
	}
	//Get Queue
	queue<Node> q;
	//Push Start Node
	q.push(Node(1,1,1));
	flag[1][1]=1;
	
	//If Queue is NOT EMPTY
	while(!q.empty()){
		Node now=q.front();
		q.pop();
		
		if(now.x==n&&now.y==m){
			//It's End!
			cout<<now.c;
			break;
			
		}
		
		//Find Dots
		for(int i=0;i<4;i++){
			int *pos2=pos[i];
			int nx,ny;
			nx=now.x+pos2[0];
			ny=now.y+pos2[1];
			//Is Can Walk To
			if(nx<=n && ny<=m && nx>0 && ny>0 && map[nx][ny] =='.' && flag[nx][ny]==0)
			{
				//Push And Mark
				flag[nx][ny]=1;
				q.push(Node(nx,ny,now.c+1));
			}
		}
	}
	
	return 0;
}

