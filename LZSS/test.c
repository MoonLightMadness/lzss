#include <stdio.h>
#include "buffer.h"
#include "log.h"
#include"lzss.h"
int main() {
	char tc[]={ 'a','b','c','d','e' };
	char* newchs = (char*)malloc(sizeof(char)*4);
	StringBuffer sb =init_stringbuffer();
	StringBuffer* buffer = &sb;
	put_to_stringbuffer(buffer, tc, 5);
	char* res = sb.chs;
	for (int i = 0; i < buffer->length; i++) {
		printf("%c", buffer->chs[i]);
	}
	//log test
	Log log = LogFactory_get();
	char* text = "{} this {} a test {}";
	log_info(&log, text, 3,"zhl","ss","20210525");
	log_info(&log, text, 3, "world", "aas", "20210525");
	//lzss
	char* chs = (char*)malloc(sizeof(char));
	lzss_start("./LICENSE",chs);
	lzss_decode("./test");
}