#include<stdio.h>
#include"stl.h"

int main() {
	FILE* fp = fopen("primjerbin.stl", "rb");;
	Objekt3D* object = ReadBinary(fp);

	WriteBinary(object);

	WriteTextFile(object);

	DeleteObject(object);

	return 0;
}