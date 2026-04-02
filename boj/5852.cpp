/**
 * Island Travels
 * algorithm: TSP
 * O(2^(n/2)*n^2+r^2c^2)
 */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using pr = pair<int, int>;
int r, c, cnt=2, a[55][55], dist[22][22], dp[1<<15][22];
const int dx[]={1,-1,0,0}, dy[]={0,0,1,-1}, inf=1e9;
bool visited[55][55];
int TSP(int set, int idx){
    if(!set) return 0;
    if(dp[set][idx]) return dp[set][idx];
    int res = inf;
    for(int i=0; i<cnt-2; i++){
        if((set&(1<<i)) && dist[idx][i]!=inf){
            int x=TSP(set^(1<<i), i);
            if(x==inf) continue;
            res = min(res, x+dist[idx][i]);
        }
    }
    return dp[set][idx] = res;
}

int main(){
    scanf("%d%d", &r, &c);
    // input
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++) {
            char x; scanf(" %c", &x);
            if(x=='X') a[i][j] = 1;
            else if(x=='S') a[i][j] = -1;
        }
    }
    // labeling island: O(rc)
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(a[i][j]==1){
                queue<pr> q;
                q.push({i,j});
                a[i][j] = cnt;
                while(!q.empty()){
                    pr cur = q.front(); q.pop();
                    for(int k=0; k<4; k++){
                        int x=cur.first+dx[k], y=cur.second+dy[k];
                        if(a[x][y]==1){
                            a[x][y] = cnt;
                            q.push({x, y});
                        }
                    }
                }
                cnt++;
            }
        }
    }

    // measuring distance: O(r^2c^2)
    for(int i=0; i<cnt-2; i++) for(int j=0; j<cnt-2; j++) dist[i][j] = inf;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            int island = a[i][j];
            if(island>=2){
                bool flag = true;
                for(int k=0; k<4; k++) if(a[i+dx[k]][j+dy[k]]==-1) flag = false;
                if(flag) continue;
                queue<pair<int, pr>> q;
                q.push({-1,{i,j}});
                for(int i=1; i<=r; i++) for(int j=1; j<=c; j++) visited[i][j] = 0;
                visited[i][j] = true;
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int k=0; k<4; k++){
                        int x=cur.second.first+dx[k], y=cur.second.second+dy[k];
                        if(visited[x][y] || !a[x][y]) continue;
                        if(a[x][y]>=2) dist[island-2][a[x][y]-2] = min(dist[island-2][a[x][y]-2], cur.first+1);
                        else if(a[x][y]==-1){
                            visited[x][y] = true;
                            q.push({cur.first+1, {x,y}});
                        }
                    }
                }
            }
        }
    }
    
    // Floyd warshall: O(n^3)
    for(int k=0; k<cnt-2; k++){
        for(int i=0; i<cnt-2; i++){
            for(int j=0; j<cnt-2; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    // TSP: O(2^(n/2)*n^2)
    int res = inf;
    for(int i=0; i<cnt-2; i++) res = min(res, TSP(((1<<(cnt-2))-1)^(1<<i), i));
    printf("%d", res);
    return 0;
}