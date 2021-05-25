
#pragma once
typedef struct StringBuffer
{
	char* chs;

	int length;

	int capacity;
}StringBuffer;

void init_stringbuffer(StringBuffer* buffer);

void put_to_stringbuffer(StringBuffer* buffer, char chars[], int len);