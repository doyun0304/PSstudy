/**
 * Watering the Fields
 * algorithm: MST
 * O(N^2logN)
 */
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
using pr = pair<int, int>;
int p[2222];
pr node[2222];
priority_queue<pair<int, pr>> pq;
int find(int x){
    return x==p[x]?x:p[x]=find(p[x]);
}
void Union(int x, int y){
    x = find(x), y = find(y);
    p[max(x,y)] = min(x,y);
}
int dist(pr a, pr b){
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}
int res, cnt=1;
int main(){
    int n, c; scanf("%d%d", &n, &c);
    for(int i=0; i<n; i++){
        int x, y; scanf("%d%d", &x, &y);
        node[i] = {x, y};
        p[i] = i;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int d = dist(node[i], node[j]);
            if(d<c) continue;
            pq.push({-d, {i, j}});
        }
    }
    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        if(find(t.second.first)==find(t.second.second)) continue;
        Union(t.second.first, t.second.second);
        res -= t.first;
        ++cnt;
        if(cnt==n) break;
    }
    printf("%d", cnt-n?-1:res);
    return 0;
}