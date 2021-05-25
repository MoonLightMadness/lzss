#pragma once
#include"buffer.h"
typedef struct Log
{
	int timestamp;

	StringBuffer buffer;




}Log;

Log LogFactory_get();

void save_log(Log* log);

void log_info(Log* log, char* buffer,int sum, ...);