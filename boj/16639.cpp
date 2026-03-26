/**
 * 괄호 추가하기 3
 * algorithm: DP
 * 
 */
#include <cstdio>
using ll = long long;
ll max(ll a, ll b){return a>b?a:b;}
ll min(ll a, ll b){return a<b?a:b;}
ll m[11][11], M[11][11];
int n;
char a[11], op[11];
ll calc(ll a, ll b, char op){
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    return 0;
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf(" %c", &(i&1?op:a)[i/2]);
    for(int i=0; i<11; i++) for(int j=0; j<11; j++) m[i][j] = 1e18, M[i][j] = -1e18;
    for(int i=0; i<n/2+1; i++) m[i][i] = M[i][i] = a[i]-'0';
    for(int size=1; size<n/2+1; size++){        // size of interval
        for(int i=0; i<n/2+1-size; i++){        // start of interval
            for(int j=i+1; j<=i+size; j++){    // division of interval
                m[i][i+size] = min(m[i][i+size], calc(m[i][j-1], m[j][i+size], op[j-1]));
                m[i][i+size] = min(m[i][i+size], calc(m[i][j-1], M[j][i+size], op[j-1]));
                m[i][i+size] = min(m[i][i+size], calc(M[i][j-1], m[j][i+size], op[j-1]));
                m[i][i+size] = min(m[i][i+size], calc(M[i][j-1], M[j][i+size], op[j-1]));
                M[i][i+size] = max(M[i][i+size], calc(m[i][j-1], m[j][i+size], op[j-1]));
                M[i][i+size] = max(M[i][i+size], calc(m[i][j-1], M[j][i+size], op[j-1]));
                M[i][i+size] = max(M[i][i+size], calc(M[i][j-1], m[j][i+size], op[j-1]));
                M[i][i+size] = max(M[i][i+size], calc(M[i][j-1], M[j][i+size], op[j-1]));
            }
        }
    }
    printf("%lld", M[0][n/2]);
    return 0;
}