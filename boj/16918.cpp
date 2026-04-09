/**
 * 봄버맨
 * algorithm: implementation
 */
#include <cstdio>
using namespace std;
const int dx[4]={0,1,0,-1}, dy[]={1,0,-1,0};
int a[222][222], b[222][222], n, m, t;

int main() {
    scanf("%d%d%d", &n, &m, &t);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char x; scanf(" %c", &x);
            a[i][j] = x=='.'?-1:1;
        }
    }

    int cnt = 1;
    while(cnt < t){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j]>=0)
                    a[i][j]--;
                else
                    a[i][j] = 1;
            }
        }
        cnt++;
        if(cnt >= t) break;

        for(int i=0; i<n; i++) for(int j=0; j<m; j++) b[i][j] = !a[i][j];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!b[i][j]) continue;
                a[i][j] = -1;
                for(int k=0; k<4; k++){
                    int nx = i+dx[k], ny = j+dy[k];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m) a[i + dx[k]][j + dy[k]] = -1;
                }
            }
        }
        cnt++;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) printf("%c", a[i][j]>=0?'O':'.');
        puts("");
    }

    return 0;
}