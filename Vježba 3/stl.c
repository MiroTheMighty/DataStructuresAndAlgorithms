#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include"stl.h"

Objekt3D* ReadBinary(FILE* fp) {
	Objekt3D* objekt = (Objekt3D*)malloc(sizeof(Objekt3D));

	if (!fp) {
		return NULL;
	}

	fseek(fp, 80, SEEK_SET);
	fread(&(objekt->n), sizeof(unsigned int), 1, fp);

	objekt->Trokuti = (Trokut*)malloc(objekt->n * sizeof(Trokut));

	int i = 0;

	while (!feof(fp)) {
		fread(&(objekt->Trokuti[i]), 50, 1, fp);
		i++;
	}

	fclose(fp);

	return objekt;
}

void WriteBinary(Objekt3D* objekt) {
	FILE *fp = fopen("writeBIN.stl", "wb");
	if (!fp)
		printf("Neuspjelo otvaranje datoteke! \n");

	int zaglavlje[20] = { 0 };

	fwrite(zaglavlje, sizeof(zaglavlje[0]), 20, fp);
	fwrite(&(objekt->n), sizeof(objekt->n), 1, fp);

	for (int i = 0; i < objekt->n; i++)
		fwrite(&(objekt->Trokuti[i]), 50, 1, fp);

	fclose(fp);
}

void WriteTextFile(Objekt3D* objekt) {
	FILE *fp = fopen("writeTXT.stl", "w");
	if (!fp)
		printf("Neuspjelo otvaranje datoteke! \n");

	fprintf(fp, "solid OpenSCAD_Model \n");
	for (int i = 0; i < objekt->n; i += 1)
	{
		fprintf(fp, "facet normal %f, %f, %f\n", objekt->Trokuti[i].nj, objekt->Trokuti[i].ni, objekt->Trokuti[i].nk);
		fprintf(fp, "outer loop\n");

		for (int j = 0; j < 3; j += 1)
		{
			fprintf(fp, "vertex %f, %f, %f\n", objekt->Trokuti[i].vertex[j].x, objekt->Trokuti[i].vertex[j].y, objekt->Trokuti[i].vertex[j].z);

		}

		fprintf(fp, "endloop\n");
		fprintf(fp, "endfacet\n");
	}
	fprintf(fp, "endsolid OpenSCAD_Model\n");

	fclose(fp);
}

void DeleteObject(Objekt3D* objekt) {
	free(objekt->Trokuti);
	free(objekt);
}