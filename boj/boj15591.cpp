/**
 * MooTube (Silver) https://www.acmicpc.net/problem/15591
 * algorithm: DFS
 * O(NQ)
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
using pr = pair<int, int>;
int n, q, inf=2e9+5; 
vector<pr> edges[5555];
int d[5555];
int dfs(int cur, int k){
    int res = 1;
    d[cur] = 2e9;
    for(pr i: edges[cur]){
        if(d[i.first]!=inf) continue;
        d[i.first] = min(d[i.first], i.second);
        if(d[i.first]<k) continue;
        res+=dfs(i.first, k);
    }
    return res;
}
int main(){
    scanf("%d%d", &n, &q);
    for(int i=1; i<n; i++){
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        edges[x].push_back({y, z});
        edges[y].push_back({x, z});
    }
    while(q--){
        int x, y; scanf("%d%d", &x, &y);
        fill(d, d+5555, inf);
        printf("%d\n", dfs(y, x)-1);
    }
    return 0;
}