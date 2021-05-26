#include<stdio.h>
#include<malloc.h>

int is_end = 1;
char* read_file(char* filepath,int offset,int len) {
	int count = 0;
	FILE *p= fopen(filepath, "a+");
	char* data= (char*)malloc(sizeof(char) * (len+1));
	fseek(p, offset, SEEK_SET);
	for (int i = 0; i < len; i++) {
		int res = fgetc(p);
		if (res != -1) {
			data[i] = res;
			count++;
		}
		else
		{
			break;
		}
	}
	data[count] = '\0';
	if (count < len) {
		is_end = 0;
	}
	fclose(p);
	return data;
}




int window = 0, window_max = 4096;
int pointer = 1;
int slice = 0, slice_max = 1024;


int* find_longest_match(char* text,int len) {
	static int res[2] = {0,0};
	int start = 0, max = 0,last_start=0,last_max=0;
	int ismatch = 0;
	for (int i = 0; i < len; i++) {
		if (text[i] == text[pointer + i]) {
			if (ismatch == 0) {
				ismatch = 1;
				start = i;
			}
			max++;
		}
		else
		{
			if (max > last_max) {
				last_start = start;
				last_max = max;
			}
			ismatch = 0;
		}
	}
	if (max > last_max) {
		last_start = start;
		last_max = max;
	}
	res[0] = last_start;
	res[1] = last_max;
	return res;
}

void append_no_match(FILE* file,char c) {
	fputc(c, file);
	printf("%d %c\n", c, c);
	pointer++;
}

void append_match(FILE* file, int* res) {
	fputc(65535, file);
	fputc((res[0] + window), file);
	fputc(res[1], file);
	pointer += res[1];
}

void lzss_start(char* filepath) {
	FILE* file = fopen("./test", "w+");
	while (is_end==1)
	{
		char* data = read_file(filepath, window, window_max);
		while ((pointer) < window_max)
		{
			int* res = find_longest_match(data,strlen(data));
			if (res[1] > 3) {
				append_match(file,res);
			}
			else
			{
				if (data[pointer] == -51) {
					pointer++;
					continue;
				}
				append_no_match(file, data[pointer]);
			}
		}
		window += window_max;
		pointer = 1;
	}
	fclose(file);
}

void lzss_decode(char* filename) {
	FILE* file = fopen(filename, "r");
	FILE* decoded = fopen("decode.txt", "w+");
	int temp = 0;
	while ((temp=fgetc(file)!=EOF))
	{
		//printf("%d  %c\n", temp,temp);
		if (temp == 65535) {
			int start = fgetc(file);
			int len = fgetc(file);
			printf("%d   %d\n", start, len);
			fseek(decoded, start+1, SEEK_SET);
			char* chs = (char*)malloc(sizeof(char) * len);
			for (int i = 0; i < len; i++) {
				chs[i] = fgetc(decoded);
			}
			fputs(chs, decoded);
		}
		else
		{
			fputc(temp, decoded);
		}
	}
	fclose(file);
	fclose(decoded);
}