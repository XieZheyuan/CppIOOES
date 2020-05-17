#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
char pan[50][50];
int flag[50][50];
int n,m;
int f[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int ans=10000;
struct Node
{
	Node(int a,int b,int c)
	{
		x=a;y=b;s=c;
	}
	int x,y,s;
	
}; 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int k=1;k<=m;k++)
		{
			cin>>pan[i][k];	
		}
	queue<Node> q;
	q.push(Node(1,1,1));
	flag[1][1] = 1;
	while(!q.empty())
	{
		
		Node now = q.front();
		if(now.x==n&&now.y==m)
		{
			cout<<now.s;
			break;
		}
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=now.x+f[i][0];int ny=now.y+f[i][1];int ns=now.s+1;
			if(!flag[nx][ny]&&pan[nx][ny]=='.')
			{
				flag[nx][ny]=1;
				q.push(Node(nx,ny,ns));
			}
		}
	}
	return 0;
}
