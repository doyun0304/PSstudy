/**
 * Dangerous Dive
 * algorithm: implementation
 */

#include <cstdio>
bool ret[11111];
int n, r;
int main() {
    while(scanf("%d %d", &n, &r) != EOF){
        for(int i=1; i<=n; i++) ret[i] = 0;
        for(int i=0; i<r; i++){
            int x; scanf("%d", &x);
            ret[x] = true;
        }
        if(n==r) puts("*");
        else {
            for(int i=1; i<=n; i++) if(!ret[i]) printf("%d ", i);
            puts("");
        }
    }
    return 0;
}