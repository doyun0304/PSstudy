/**
 * Cross Country Skiing
 * algorithm: Union Find, MST
 * O(N^2logN)
 */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &o) const {
        return w < o.w;
    }
};

const int N = 555, dx[] = {0, 1}, dy[] = {1, 0};
int n, m, t, a[N][N], p[N*N], sz[N*N], start_node_cnt[N*N], start[N][N];

int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
void Union(int x, int y){
    x=find(x), y=find(y);
    if(x==y) return;
    p[y] = x;
    sz[x] += sz[y];
}

int main() {
    scanf("%d%d", &n, &m); t=n*m;

    for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf("%d", &a[i][j]);

    int tot_start = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &start[i][j]);
            int id = i * m + j;
            p[id] = id;
            sz[id] = 1;
            if(start[i][j]){
                start_node_cnt[id] = 1; 
                tot_start++;
            }
        }
    }

    vector<Edge> edges;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<2; k++){
                int ni=i+dx[k], nj=j+dy[k];
                if(ni<n && nj<m){
                    edges.push_back({i*m+j, ni*m+nj, abs(a[i][j]-a[ni][nj])});
                }
            }
        }
    }
    sort(edges.begin(), edges.end());

    if(tot_start<=1){
        puts("0");
        return 0;
    }

    ll res = 0;
    for(auto &edge: edges){
        int u = find(edge.u);
        int v = find(edge.v);
        if(u!=v){
            p[v] = u;
            sz[u] += sz[v];
            start_node_cnt[u] += start_node_cnt[v];
            if(start_node_cnt[u]==tot_start){
                printf("%d", edge.w);
                return 0;
            }
        }
    }
    return 0;
}