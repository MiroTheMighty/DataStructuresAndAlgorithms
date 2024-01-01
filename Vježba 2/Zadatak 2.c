#include<stdio.h>
#include<stdlib.h>

typedef struct {
	float x, y;
}Tocka;

typedef struct {
	Tocka* vrh;
	int n;
}Poligon;

Poligon* novi_poligon(float* niz_x, float* niz_y, int n) {
	Poligon poligon;
	Tocka* t = malloc(n * sizeof(Tocka));

	for (int i = 0; i < n; i++) {
		t[i].x = niz_x[i];
		t[i].y = niz_y[i];
	}
	poligon.vrh = t;
	poligon.n = n;

	return &poligon;
}

Tocka** pozitivni(Poligon* p, int* np) {
	int br = 0, j = 0;
	Tocka** t;
	for (int i = 0; i < p->n; i++) {
		if (p->vrh[i].x > 0 && p->vrh[i].y > 0) {
			br++;
		}
	}
	t = malloc(br * sizeof(Tocka*));
	for (int i = 0; i < p->n; i++) {
		if (p->vrh[i].x > 0 && p->vrh[i].y > 0) {
			t[j] = &p->vrh[i];
			j++;
		}
	}
	*np = br;
	return t;
}

int main() {
	Poligon* p;
	Tocka** t;
	int np;
	float x[5] = { 1.2,3,2.5,3.1,5 };
	float y[5] = { 0,1.8,2.3,5,9.9 };

	p = novi_poligon(x, y, 5);
	t = pozitivni(p,&np);

	free(p);
	for (int i = 0; i < np; i++) {
		free(t[i]);
	}
	free(t);
	return 0;
}