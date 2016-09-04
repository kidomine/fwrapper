#include <stdio.h>
#include <stdarg.h>

extern int
ftlog_Common(	const char *file,
		int         line,
		const char *func,
		const char *prefix,
		const char *format, ...);

#define FTLOG_ERR(...)                \
do {                                  \
	ftlog_Common(__FILE__,        \
		     __LINE__,        \
		     __FUNCTION__,    \
		     "ERR",           \
		     __VA_ARGS__);    \
} while(0)


#define FTLOG_INF(...)                \
do {                                  \
	ftlog_Common(__FILE__,        \
		     __LINE__,        \
		     __FUNCTION__,    \
		     "INF",           \
		     __VA_ARGS__);    \
} while(0)

