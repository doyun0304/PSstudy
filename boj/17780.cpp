/**
 * 새로운 게임
 * algorithm: implementation...
 * O(1000NK)
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct piece{
    int x, y, dir;
} p[22];
vector<int> m[22][22];
int a[22][22], dx[]={0,0,0,-1,1}, dy[]={0,1,-1,0,0};
int main(){
    int n, k; scanf("%d%d", &n, &k);
    for(int i=0; i<=n+1; i++) for(int j=0; j<=n+1; j++) a[i][j] = 2;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) scanf("%d", &a[i][j]);
    for(int i=1; i<=k; i++){
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        p[i] = {x, y, z};
        m[x][y].push_back(i);
    }
    int res;
    for(res=1; res<1001; res++){
        for(int i=1; i<=k; i++){
            int x=p[i].x, y=p[i].y;
            if(m[x][y][0]!=i) continue;
            int nx=x+dx[p[i].dir], ny=y+dy[p[i].dir];
            if(a[nx][ny]==0){
                for(int j: m[x][y]) p[j].x = nx, p[j].y = ny;
                m[nx][ny].insert(m[nx][ny].end(), m[x][y].begin(), m[x][y].end());
                m[x][y].clear();
                if(m[nx][ny].size()>3){
                    printf("%d", res);
                    return 0;
                }
            }else if(a[nx][ny]==1){
                reverse(m[x][y].begin(), m[x][y].end());
                for(int j: m[x][y]) p[j].x = nx, p[j].y = ny;
                m[nx][ny].insert(m[nx][ny].end(), m[x][y].begin(), m[x][y].end());
                m[x][y].clear();
                if(m[nx][ny].size()>3){
                    printf("%d", res);
                    return 0;
                }
            } else{
                p[i].dir = p[i].dir+(p[i].dir&1?1:-1);
                nx=p[i].x+dx[p[i].dir], ny=p[i].y+dy[p[i].dir];
                if(a[nx][ny]==2) continue;
                if(a[nx][ny]==1) reverse(m[x][y].begin(), m[x][y].end());
                for(int j: m[x][y]) p[j].x = nx, p[j].y = ny;
                m[nx][ny].insert(m[nx][ny].end(), m[x][y].begin(), m[x][y].end());
                m[x][y].clear();
                if(m[nx][ny].size()>3){
                    printf("%d", res);
                    return 0;
                }
            }
        }
    }
    puts("-1");
    return 0;
}