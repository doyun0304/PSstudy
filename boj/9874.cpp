/**
 * Wormholes
 * algorithm: brute force
 * O(n!/2^(n/2))
 */
#include <cstdio>
int n, x[22], y[22], pair[22], next[22];

bool isCycle(){
    for(int i=1; i<=n; i++){
        int pos = i;
        for(int j=0; j<n; j++) pos=next[pair[pos]];
        if(pos) return true;
    }
    return false;
}

int f(){
    int i=1, res=0;
    for(; i<=n; i++) if(!pair[i]) break;
    if(i>n) return isCycle();
    for(int j=i+1; j<=n; j++){
        if(!pair[j]){
            pair[i] = j;
            pair[j] = i;
            res += f();
            pair[i] = pair[j] = 0;
        }
    }
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d%d", x+i, y+i);

    for(int i=1; i<=n; i++) 
        for(int j=1; j<=n; j++)
            if(x[j]>x[i] && y[i]==y[j]) 
                if(!next[i] || x[j]<x[next[i]])
                    next[i] = j;

    printf("%d\n", f());
    return 0;
}