#include<iostream>
using namespace std;
int a,b,h;
char map[100][100][100];
int way_count=10000000;
int is_vis[100][100][100];
int endpos[3],startpos[3];
int pos[6][3]= {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,-1},{0,0,1}};
void DFS(int x,int y,int z,int cnt=1) {
	if(cnt>=way_count)
		return;
	for(int i=0; i<6; i++) {
		int *npos=pos[i];
		int nx=npos[0]+x;
		int ny=npos[1]+y;
		int nz=npos[2]+z;
		if(nx == endpos[0] && ny == endpos[1] && nz == endpos[2]) {

			if(way_count > cnt) {
				way_count=cnt;
			}
			return;
		}
		if(nx<h &&nx > -1 && ny<a && ny > -1 && nz < b && nz > -1 && map[nx][ny][nz] == '.' && !is_vis[nx][ny][nz]) {
			is_vis[nx][ny][nz] = 1;
			DFS(nx,ny,nz,cnt+1);
			is_vis[nx][ny][nz]=0;
		}
	}

}
int main() {
	while(1) {
		cin>>h>>a>>b;
		if(h == 0 && a == 0 && b == 0) {
			break;
		}
		for(int i=0; i<h; i++) {
			for(int j=0; j<a; j++) {
				for(int k=0; k<b; k++) {
					char temp;
					cin>>temp;
					map[i][j][k]=temp;
					if(temp == 'E') {
						endpos[0]=i;
						endpos[1]=j;
						endpos[2]=k;
					} else if(temp == 'S') {
						startpos[0]=i;
						startpos[1]=j;
						startpos[2]=k;
					}
				}
			}
		}
		is_vis[startpos[0]][startpos[1]][startpos[2]]=1;
		DFS(startpos[0],startpos[1],startpos[2]);
		if(way_count == 10000000) {
			cout<<"Trapped!"<<endl;
		} else {
			//Escaped in 11 minute(s).
			cout<<"Escaped in "<<way_count<<" minute(s)."<<endl;
		}
		way_count=10000000;
		for(int i=0; i<h; i++) {
			for(int j=0; j<a; j++) {
				for(int k=0; k<b; k++) {
					is_vis[i][j][k]=0;
				}
			}
		}
	}
	return 0;
}
