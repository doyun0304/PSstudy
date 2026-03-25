/**
 * 소가 길을 건너간 이유 6
 * algorithm: DFS
 * O(N^2+K^2)?
 */
#include <cstdio>
#include <vector>
using namespace std;
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
int n, k, r, a[111][111], cnt, visited[111][111], road[111][111][4], ans;
vector<int> t;
int dfs(int x, int y){
    visited[x][y] = cnt;
    int res = a[x][y];
    for(int i=0; i<4; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(road[x][y][i] || nx<1 || nx>n || ny<1 || ny>n || visited[nx][ny]) continue;
        res += dfs(nx, ny);
    }
    return res;
}
int main(){
    scanf("%d%d%d", &n, &k, &r);
    while(r--){
        int x,y,z,w;scanf("%d%d%d%d",&x,&y,&z,&w);
        if(z==x+1) road[x][y][0] = road[z][w][1] = 1;
        if(z==x-1) road[x][y][1] = road[z][w][0] = 1;
        if(w==y+1) road[x][y][2] = road[z][w][3] = 1;
        if(w==y-1) road[x][y][3] = road[z][w][2] = 1;
    }
    while(k--){
        int x, y; scanf("%d%d", &x, &y);
        a[x][y]++;   
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(visited[i][j]) continue;
            cnt++;
            int d = dfs(i, j);
            if(d) t.push_back(d);
        }
    }
    for(int i=0; i<(int)t.size(); i++) 
        for(int j=i+1; j<(int)t.size(); j++) 
            ans += t[i] * t[j];
    printf("%d", ans);
    return 0;
}