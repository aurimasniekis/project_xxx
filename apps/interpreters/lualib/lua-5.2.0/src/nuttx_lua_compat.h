
#include <stdio.h>
#include <unistd.h>	// for SEEK_*, should be in stdio.h
#include <apps/include/readline.h>

#define LUA_NUTTX

#define RAND_MAX		MAX_RAND

#define offsetof(st, m) __builtin_offsetof(st, m)

#define _IOFBF			0
#define _IOLBF			0
#define _IONBF			0

#define L_tmpnam		32

#define iscntrl(_c)		iscontrol(_c)

#define getlocaledecpoint()	'.'

#define lua_readline(L,b,p)     \
        ((void)L, fputs(p, stdout), fflush(stdout),  /* show prompt */ \
	readline(b, LUA_MAXINPUT, stdin, stdout) > 0) /* get line */
#define lua_saveline(L,idx)     { (void)L; (void)idx; }
#define lua_freeline(L,b)       { (void)L; (void)b; }


/*
 * Stubs for NuttX functionality that's missing and needs to be implemented.
 */
extern int ferror(FILE *);
extern void clearerr(FILE *stream);
extern int feof(FILE *);
extern FILE *tmpfile(void);
extern int fscanf(FILE *stream, const char *format, ...);
extern int setvbuf(FILE *stream, char *buf, int type, size_t size);
//extern clock_t clock(void);

/*
 * Wrappers for missing NuttX functionality, or functionality that is
 * unlikely to ever be implemented.
 */
extern FILE *freopen(const char *filename, const char *mode, FILE *stream);
extern int strcoll(const char *s1, const char *s2);
extern void *memchr(const void *s, int c, size_t n);
extern char *tmpnam(char *buf);
extern int remove(const char *path);
extern double difftime(time_t time1, time_t time0);
extern int system(const char *command);
extern char *setlocale(int category, const char *locale);
