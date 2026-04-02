/**
 * Ski Course Design
 * algorithm: Brute force
 * O(100N)
 */
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1111], n, res=2e9;
int main(){
    scanf("%d", &n); for(int i=0; i<n; i++) scanf("%d", a+i);
    sort(a, a+n);
    for(int i=a[0]; i<=100-17; i++){
        int tmp = 0;
        for(int j=0; j<n; j++){
            if(a[j]<i) tmp += (i-a[j])*(i-a[j]);
            else if(a[j]>i+17) tmp += (a[j]-i-17)*(a[j]-i-17);
        }
        res = min(res, tmp);
    }
    printf("%d", res);
    return 0;
}