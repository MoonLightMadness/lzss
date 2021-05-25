
#pragma once
typedef struct StringBuffer
{
	char* chs;

	int length;

	int capacity;
}StringBuffer;

StringBuffer init_stringbuffer();

char* buffer_to_array(StringBuffer* buffer);

void put_to_stringbuffer(StringBuffer* buffer, char* chars, int len);