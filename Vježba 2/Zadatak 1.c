#include<stdio.h>
#include<stdlib.h>

int* podniz(int* a, int start, int stop) {
	int n = (stop - start) + 1, j = 0;
	int* niz = (int*)malloc(n * sizeof(int));

	for (int i = start; i < stop + 1; i++, j++) {
		niz[j] = a[i];
	}

	return niz;
}

int* filtriraj(int* niz, int n, int th, int *nth) {
	int* a;
	int br = 0;

	for (int i = 0; i < n; i++) {
		if (niz[i] < th) {
			br++;
		}
	}
	a = malloc(br * sizeof(int));
	br = 0;
	for (int i = 0; i < n; i++) {
		if (niz[i] < th) {
			a[br] = niz[i];
			br++;
		}
	}
	*nth = br;
	return a;
}

int** podijeli(int* niz, int n) {
	int p = n / 2;
	int** a = malloc(2 * sizeof(int*));
	int j = 0;
	a[0] = malloc(p * sizeof(int));
	a[1] = malloc(p * sizeof(int));

	for (int i = 0; i < p; i++) {
		a[0][i] = niz[i];
	}
	for (int i = p; i < n; i++) {
		a[1][j] = niz[i];
		j++;
	}

	return a;
}

int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* n;
	int** pp;
	int c[6] = { 1,10,3,12,4,5 };
	int nth;
	int* p;
	n = podniz(a, 1, 3);

	for (int i = 0; i < 2; i++) {
		printf("%d ", n[i]);
	}

	printf("\n");

	p = filtriraj(c, 6, 10, &nth);

	for (int i = 0; i < nth; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
	pp = podijeli(a, 10);
	for (int i = 0; i < 5; i++) {
		printf("%d ", pp[0][i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", pp[1][i]);
	}
	printf("\n");

	free(n);
	free(p);
	free(pp[0]);
	free(pp[1]);
	free(pp);
	
	return 0;
}