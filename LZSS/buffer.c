#pragma once
typedef struct StringBuffer 
{
	char* chs;

	int length;

	int capacity;
}StringBuffer;

void mutiple(StringBuffer* buffer) {
	int size = (*buffer).length * 2;
	char* newchs = (char*)malloc(sizeof(char)*size);
	for (int i = 0; i < size / 2; i++) {
		newchs[i] = (*buffer).chs[i];
	}
	//free(*(buffer.chs));
	(*buffer).chs = newchs;
	(*buffer).capacity = size;
}

void init_stringbuffer(StringBuffer* buffer) {
	(*buffer).length = 0;
	(*buffer).capacity = 4;
	(*buffer).chs = (char*)malloc(sizeof(char) * (*buffer).capacity);
}

void put_to_stringbuffer(StringBuffer* buffer,char chars[],int len) {
	for (int i = 0; i < len; i++) {
		if ((*buffer).length >= (*buffer).capacity) {
			mutiple(buffer);
		}
		(*buffer).chs[(*buffer).length] = chars[i];
		(*buffer).length++;
	}
}



