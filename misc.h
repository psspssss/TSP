/* misc.h */

/* Written by Andrew Makhorin <mao@gnu.org>, October 2015. */

#ifndef MISC_H
#define MISC_H

//#include <glpk.h>

#define xprintf printf
#define xerror  tsp_error
#define xassert tsp_assert
#define xalloc  tsp_alloc
#define xfree   free

typedef void (*tsp_errfunc)(const char *fmt, ...);

int str2int(const char *str, int *val);
/* convert character string to value of int type */

int str2num(const char *str, double *val);
/* convert character string to value of double type */

#define tsp_error tsp_error_(__FILE__, __LINE__)
tsp_errfunc tsp_error_(const char *file, int line);
/* display fatal error message and terminate execution */

#define tsp_assert(expr) \
      ((void)((expr) || (tsp_assert_(#expr, __FILE__, __LINE__), 1)))
void tsp_assert_(const char *expr, const char *file, int line);

void *tsp_alloc(unsigned int n, unsigned int size);

#endif

/* eof */
