/**
 * 배열 복원하기
 * algorithm: implementation
 */
#include <cstdio>
int h, w, x, y, a[333][333], b[333][333];

int main() {
    scanf("%d%d%d%d", &h, &w, &x, &y);
    for(int i=0; i<h+x; i++) for(int j=0; j<w+y; j++) scanf("%d", &b[i][j]);

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(i >= x && j >= y) a[i][j] = b[i][j] - a[i - x][j - y];
            else a[i][j] = b[i][j];
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) printf("%d ", a[i][j]);
        puts("");
    }
    return 0;
}