#include<stdio.h>

char* read_file(char* filepath,int offset,int len) {
	FILE *p;
	fopen_s(&p, filepath, "r+");
	fseek(p, offset, SEEK_CUR);
	char* data = (char*)malloc(sizeof(char)*len);
	for (int i = 0; i < len; i++) {
		int res = fgetc(p);
		if (res != -1) {
			data[i] = res;
		}
		else
		{
			break;
		}
	}
	fclose(p);
	return data;
}