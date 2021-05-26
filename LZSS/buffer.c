#pragma once
#include<stdio.h>
#include<malloc.h>
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
	free(buffer->chs);
	(*buffer).chs = newchs;
	(*buffer).capacity = size;
}

StringBuffer init_stringbuffer() {
	int capacity = 4;
	StringBuffer bf = { (char*)malloc(sizeof(char) * capacity) ,0,capacity };
	return bf;
}

void put_to_stringbuffer(StringBuffer* buffer,char* chars,int len) {
	for (int i = 0; i < len; i++) {
		if ((*buffer).length >= (*buffer).capacity) {
			mutiple(buffer);
		}
		(*buffer).chs[(*buffer).length] = chars[i];
		(*buffer).length++;
	}
}

char* buffer_to_array(StringBuffer* buffer) {
	char* chs = (char*)malloc(sizeof(char)*buffer->length);
	for (int i = 0; i < buffer->length; i++)
	{
		chs[i] = buffer->chs[i];
	}
	return chs;
}


