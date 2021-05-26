#pragma once
#include "buffer.h"
#include<stdio.h>
#include <stdarg.h>
typedef struct Log
{
	int timestamp;

	StringBuffer buffer;
	



}Log;

static Log log;

Log get_Log() {
	Log l = { 1,init_stringbuffer() };
	return l;
}

Log LogFactory_get() {
	if (log.timestamp==0) {
		log = get_Log();
	}
	return log;
}

void save_log(Log* log) {
	FILE *p;
	fopen_s(&p,"./log.txt", "a+");
	int len = log->buffer.length;
	char* text = log->buffer.chs;
	if (!&p) {
		fputc('\n', p);
		for (int i = 0; i < len; i++)
		{
			fputc(text[i], p);
		}
		fclose(p);
		free(log->buffer);
		log->buffer = init_stringbuffer();
	}
}


void log_info(Log* log,char* buffer,int sum,...) {
	StringBuffer newbuf = init_stringbuffer();
	va_list list;
	va_start(list, sum);
	for (int i = 0; i < strlen(buffer); i++) {
		if (buffer[i] == '{') {
			char* arg = va_arg(list, char*);
			put_to_stringbuffer(&newbuf, arg, strlen(arg));
			i += 1;
		}
		else
		{
			put_to_stringbuffer(&newbuf, &buffer[i], 1);
		}
	}
	va_end(list);
	put_to_stringbuffer(&(log->buffer), buffer_to_array(&newbuf), newbuf.length);
	save_log(log);
}