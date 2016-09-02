#include "ftlog.h"

int
ftlog_Common(	const char *file,
		int         line,
		const char *func,
		const char *prefix,
		const char *format,
		...)
{
	va_list args;

	va_start(args, format);

	printf("[%s] %s:%d @%s(): ", prefix, file, line, func);
	vprintf(format, args);
	printf("\n");

	va_end(args);
}



