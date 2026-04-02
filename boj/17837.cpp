/**
 * 새로운 게임 2
 * algorithm: implementation
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
            int x=p[i].x, y=p[i].y, pos = 0;
            for(int j=0; j<m[x][y].size(); j++) {
                if(m[x][y][j]==i){
                    pos = j;
                    break;
                }
            }
            int nx=x+dx[p[i].dir], ny=y+dy[p[i].dir];
            if(a[nx][ny]==2){
                p[i].dir = p[i].dir+(p[i].dir&1?1:-1);
                nx = x+dx[p[i].dir];
                ny = y+dy[p[i].dir];
                if(a[nx][ny]==2) continue;
            }
            vector<int> move;
            move.insert(move.end(), m[x][y].begin()+pos, m[x][y].end());
            m[x][y].erase(m[x][y].begin()+pos, m[x][y].end());
            if(a[nx][ny]==1) reverse(move.begin(), move.end());
            for(int i : move){
                p[i].x = nx;
                p[i].y = ny;
                m[nx][ny].push_back(i);
            }
            if(m[nx][ny].size()>=4){
                printf("%d\n", res);
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}