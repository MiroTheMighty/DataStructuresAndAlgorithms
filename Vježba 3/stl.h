#pragma once

typedef struct {
	float x, y, z;
}Vrh;

typedef struct {
	float nj, ni, nk;
	Vrh vertex[3];
	unsigned short color;
}Trokut;

typedef struct {
	Trokut* Trokuti;
	unsigned int n;
}Objekt3D;

Objekt3D* ReadBinary(FILE* fp);
void WriteBinary(Objekt3D* objekt);
void WriteTextFile(Objekt3D* objekt);
void DeleteObject(Objekt3D* objekt);