#include "clog.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <memory.h>

#define CLOG(level, handle, time_buf, file, line, msg) \
	do {                                               \
		va_list _clog_args;                            \
		va_start(_clog_args, msg);                     \
		fprintf(                                       \
			handle,                                    \
			"%-5s : %s : [%s:%d] : ",                  \
			level_labels[level], time_buf, file, line  \
		);                                             \
		vfprintf(handle, msg, _clog_args);             \
		fprintf(handle, "\n");                         \
		va_end(_clog_args);                            \
	} while(0)


static struct clogger {
	FILE *handle;          /* log file to which messages should be written */
	enum clog_level level; /* control what messages should be printed */
	enum clog_echo echo;   /* echo log messages to stderr if true */
} clogger;

static char *level_labels[] = { "OFF", "ERROR", "WARN", "INFO", "DEBUG" };

void
clog_init (enum clog_level level, enum clog_echo echo)
{
	memset(&clogger, 0, sizeof(struct clogger));
	clogger.echo = echo;
	clogger.level = level;
}

int
clog_open (const char *fname)
{	
	clogger.handle = fopen(fname, "w");
	return clogger.handle != NULL;
}

void
clog_message (enum clog_level level, const char *file, int line,
	const char *msg, ...)
{	
	time_t time_raw;
	struct tm *time_info;
	char *time_buf;

	if (level > clogger.level)
		return;

	time(&time_raw);
	time_info = localtime(&time_raw);
	time_buf = asctime(time_info);
	
	if (time_buf) 
		time_buf[24] = '\0'; /* remove trailing newline */

	if (clogger.echo == CLOG_ECHO_ON)
		CLOG(clogger.level, stderr, time_buf, file, line, msg);
	
	if (clogger.handle != NULL)
		CLOG(clogger.level, clogger.handle, time_buf, file, line, msg);
}

void
clog_set_echo ( enum clog_echo echo )
{
	clogger.echo = echo;
}

void
clog_set_level(enum clog_level level)
{
	clogger.level = level;
}

void
clog_close ()
{
	if (clogger.handle != NULL) {
		fflush(clogger.handle);
		fclose(clogger.handle);
	}
}
