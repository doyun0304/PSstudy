/**
 * 크루스칼의 공
 * algorithm: Parallel Binary Search
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pr=pair<int,int>;
const int N=111111;
struct Edge{
    int x, y, w;
    bool operator<(Edge &o){
        return w<o.w;
    }
}; 
int n, m, q, l[N], r[N];
struct UF{
    int p[N], s[N];
    void init(){
        for(int i=0;i<=n;i++) p[i]=i, s[i]=1;
    }
    int find(int x){
        return x==p[x]?x:p[x]=find(p[x]);
    }
    void Union(int x, int y){
        x = find(x), y=find(y);
        if(x==y) return;
        p[x] = y;
        s[y] += s[x];
    }
} uf;
vector<int> g[N];
Edge edges[N];
pr query[N], res[N];
void vinit(){
    for(int i=0; i<=n; i++) g[i].clear();
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++){
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        edges[i] = {x, y, z};
    }
    sort(edges+1, edges+1+m);
    scanf("%d", &q);
    for(int i=1; i<=q; i++){
        int x, y; scanf("%d%d", &x, &y);
        query[i] = {x,y};
        l[i] = 1;
        r[i] = m+1;
    }
    while(1){
        bool flag = true;
        for(int i=1; i<=q; i++){
            if(l[i]!=r[i]){
                flag = false;
                g[(l[i]+r[i])/2].push_back(i);
            }
        }
        if(flag) break;
        uf.init();
        for(int i=1; i<=m; i++){
            uf.Union(edges[i].x, edges[i].y);
            if(g[i].empty()) continue;
            for(auto j: g[i]){
                int a = uf.find(query[j].first), b = uf.find(query[j].second);
                if(a==b){
                    r[j] = i;
                    res[j] = {edges[i].w, uf.s[a]};
                } else{
                    l[j] = i+1;
                }
            }
            g[i].clear();
        }
    }
    for(int i=1; i<=q; i++) l[i]==m+1?puts("-1"):printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}