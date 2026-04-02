/**
 * Mania de Par
 * algorithm: dijkstra
 * O((V+E)logE)
 */
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
using pr = pair<int, int>;
const int inf = 2e9;
int c, v, dist[11111][2];
vector<pr> edges[11111];
priority_queue<pair<int, pr>> pq;
int main(){
    scanf("%d%d", &c, &v);
    while(v--){
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        edges[x].push_back({y,z});
        edges[y].push_back({x,z});
    }
    for(int i=1; i<=c; i++) dist[i][0] = dist[i][1] = inf;
    dist[1][0] = 0;
    pq.push({0, {1, 0}});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(dist[cur.second.first][cur.second.second]<-cur.first) continue;
        for(pr i: edges[cur.second.first]){
            if(dist[i.first][1-cur.second.second]>dist[cur.second.first][cur.second.second]+i.second){
                dist[i.first][1-cur.second.second]=dist[cur.second.first][cur.second.second]+i.second;
                pq.push({-i.second, {i.first, 1-cur.second.second}});
            }
        } 
    }
    printf("%d", dist[c][0]==inf?-1:dist[c][0]);
    return 0;
}
