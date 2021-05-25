#include <stdio.h>
#include "buffer.h"
int main() {
	char tc[]={ 'a','b','c','d','e' };
	char* newchs = (char*)malloc(sizeof(char)*4);
	StringBuffer sb={newchs,1,1};
	StringBuffer* buffer = &sb;
	init_stringbuffer(buffer);
	put_to_stringbuffer(buffer, tc, 5);
	char* res = sb.chs;
	for (int i = 0; i < buffer->length; i++) {
		printf("%c", sb.chs[i]);
	}
}