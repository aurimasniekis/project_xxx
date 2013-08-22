
#include <string.h>

#include "nuttx_lua_compat.h"

static void
_unimplemented(const char *what)
{
	printf("Lua: %s() unimplemented\n", what);
	fflush(stdout);
}

/*
 * Functions that aren't implemented and which affect Lua or 
 * Lua code in some fashion.
 */

int
ferror(FILE *f)
{
	_unimplemented("ferror");
	return 0;
}

void
clearerr(FILE *stream)
{
	_unimplemented("clearerr");
}

int
feof(FILE *f)
{
	/* XXX this needs to be fixed inside NuttX */
	_unimplemented("ferror");
	return 0;
}

FILE *
tmpfile(void)
{
	_unimplemented("tmpfile");
	return NULL;
}

int
fscanf(FILE *stream, const char *format, ...)
{
	_unimplemented("fscanf");
	return 0;
}

int
setvbuf(FILE *stream, char *buf, int type, size_t size)
{
	_unimplemented("setvbuf");
	return 0;
}

clock_t
clock(void)
{
	_unimplemented("clock");
	return -1;
}

/*
 * Some functions that Lua wants but NuttX doesn't/may never implement.
 */

FILE *
freopen(const char *filename, const char *mode, FILE *stream)
{
	/* This is only used to change from 'ascii' to 'binary' mode and can probably
	 * safely be ignored.
	 */
	return stream;
}

// int
// strcoll(const char *s1, const char *s2)
// {
//     /* this is good enough for us */
//     return strcmp(s1, s2);
// }

void *
memchr(const void *s, int c, size_t n)
{
	const char *p = (const char *)s;

	while (n--) {
		if (*p == c)
			return (void *)p;
		p++;
	}
	return NULL;
}

char *
tmpnam(char *buf)
{
	static char name[L_tmpnam];
	static int tmpidx;
	char *p;

	p = buf ? buf : name;

	sprintf(p, "/tmp/luatmp.%04d", tmpidx++);
	
	return p;
}

int remove(const char *path)
{
	return unlink(path);
}

double
difftime(time_t time1, time_t time0)
{
	return (double)time1 - (double)time0;
}

int
system(const char *command)
{
	_unimplemented("system");
	return -1;
}

char *
setlocale(int category, const char *locale)
{
	return NULL;
}
