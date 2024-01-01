#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM (rand() * rand())

int* generate(int n) {
	int* niz = (int*)malloc(n * sizeof(int));
	niz[0] = 1 + rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	}
	return niz;
}

void shuffle(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		int j = RANDOM % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int cmp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void presjek(int* skupA, int* skupB, int n) {
	int br = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (skupA[i] == skupB[j])
				br++;
		}
	}

	printf("Duljina presjeka je %d ", br);
}

void presjek_jedan_sortiran(int* skupA, int* skupB, int n) {
	int br = 0;

	qsort(skupB, n, sizeof(int), cmp);

	printf("\n");

	for (int i = 0; i < n; i++) {
		if (bsearch(&skupA[i], skupB, n, sizeof(int), cmp) != NULL)
			br++;
	}

	printf("Duljina presjeka je %d", br);
}

void presjek_oba_sortirana(int* skupA, int* skupB, int n, int n1) {
	int br = 0, i = 0, j = 0;

	qsort(skupA, n, sizeof(int), cmp);
	qsort(skupB, n, sizeof(int), cmp);

	while (i < n && j < n1) {
		if (skupA[i] == skupB[j]) {
			br++;
			i++;
			j++;
		}
		else if (skupA[i] < skupB[j]) {
			i++;
		}
		else {
			j++;
		}	
	}

	printf("Duljina presjeka je %d ", br);
}

void presjek_po_indeksima(int* skupA, int* skupB, int n) {
	int* indexA;
	int* indexB;
	int maxA = skupA[0];
	int maxB = skupB[0];
	int max;
	int min;

	for (int i = 0; i < n; i++) {
		if (skupA[i] > maxA)
			maxA = skupA[i];

		if (skupB[i] > maxB)
			maxB = skupB[i];
	}

	if (maxA >= maxB) {
		max = maxA;
		min = maxB;
	} else {
		max = maxB;
		min = maxA;
	}

	indexA = (int*)malloc(sizeof(int) * (maxA + 1));
	indexB = (int*)malloc(sizeof(int) * (maxB + 1));

	for (int i = 0; i < maxA + 1; i++)
		indexA[i] = 0;

	for (int i = 0; i < maxB + 1; i++)
		indexB[i] = 0;

	for (int i = 0; i < n; i++) {
		indexA[skupA[i]] = 1;
		indexB[skupB[i]] = 1;
	}

	int br = 0;

	for (int i = 0; i < min; i++) {
		if (indexA[i] == indexB[i] && indexA[i] == 1)
			br++;
	}

	printf("Duljina presjeka je %d ", br);

	free(indexA);
	free(indexB);
}

int main() {
	srand(time(NULL));

	clock_t start, end;

	int* skupA;
	int* skupB;

	/*for (int i = 10000; i < 100000; i += 10000) {
		skupA = generate(i);
		skupB = generate(i);

		start = clock();

		presjek(skupA, skupB, i);

		end = clock();

		printf("\n%f\n", (double)(end - start) / CLOCKS_PER_SEC);
	}*/

	/*for (int i = 100000; i < 3000000; i += 300000) {
		skupA = generate(i);
		skupB = generate(i);

		start = clock();
		presjek_jedan_sortiran(skupA, skupB, i);
		end = clock();

		printf("\n%f\n", (double)(end - start) / CLOCKS_PER_SEC);
	}*/

	/*for (int i = 100000; i < 3000000; i += 300000) {
		skupA = generate(i);
		skupB = generate(i);

		start = clock();

		presjek_oba_sortirana(skupA, skupB, i, i);

		end = clock();

		printf("\n%f\n", (double)(end - start) / CLOCKS_PER_SEC);
	}*/

	for (int i = 100000; i < 3000000; i += 300000) {
		skupA = generate(i);
		skupB = generate(i);

		start = clock();

		presjek_po_indeksima(skupA, skupB, i);

		end = clock();

		printf("%f \n", (double)(end - start) / CLOCKS_PER_SEC);
	}

	free(skupA);
	free(skupB);

	return 0;
}