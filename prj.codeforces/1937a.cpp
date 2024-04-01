#include<stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a;
		scanf("%d", &a);
		int i = 1;
		while (i * 2 <= a) {
			i *= 2;
		}
		printf("%d\n", i);
	}
}