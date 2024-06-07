
#include <bits/stdc++.h>
using namespace std;
const int MX = 100100;
int t, n, a[MX];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        int w = 0, i = 1;
        for (; i < n; i++) if (a[i] % a[0]) {
            if (w) {
                if (a[i] % a[w]) break;
            }
            else w = i;
        }
        puts((i >= n) ? "Yes" : "No");
    }
}