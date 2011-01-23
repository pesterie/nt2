/*							log2f.c
 *
 *	Base 2 logarithm
 *
 *
 *
 * SYNOPSIS:
 *
 * float x, y, cephes_log2f();
 *
 * y = cephes_log2f( x );
 *
 *
 *
 * DESCRIPTION:
 *
 * Returns the base 2 logarithm of x.
 *
 * The argument is separated into its exponent and fractional
 * parts.  If the exponent is between -1 and +1, the base e
 * logarithm of the fraction is approximated by
 *
 *     log(1+x) = x - 0.5 x**2 + x**3 P(x)/Q(x).
 *
 * Otherwise, setting  z = 2(x-1)/x+1),
 * 
 *     log(x) = z + z**3 P(z)/Q(z).
 *
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE      exp(+-88)   100000      1.1e-7      2.4e-8
 *    IEEE      0.5, 2.0    100000      1.1e-7      3.0e-8
 *
 * In the tests over the interval [exp(+-88)], the logarithms
 * of the random arguments were uniformly distributed.
 *
 * ERROR MESSAGES:
 *
 * log singularity:  x = 0; returns MINLOGF/log(2)
 * log domain:       x < 0; returns MINLOGF/log(2)
 */

/*
Cephes Math Library Release 2.2:  June, 1992
Copyright 1984, 1992 by Stephen L. Moshier
Direct inquiries to 30 Frost Street, Cambridge, MA 02140
*/

#include "mconf.h"
static char fname[] = {"log2"};

/* Coefficients for log(1+x) = x - x**2/2 + x**3 P(x)
 * 1/sqrt(2) <= x < sqrt(2)
 */

static float P[] = {
 7.0376836292E-2,
-1.1514610310E-1,
 1.1676998740E-1,
-1.2420140846E-1,
 1.4249322787E-1,
-1.6668057665E-1,
 2.0000714765E-1,
-2.4999993993E-1,
 3.3333331174E-1
};

#define LOG2EA 0.44269504088896340735992
#define SQRTH 0.70710678118654752440
extern float MINLOGF, LOGE2F;

#ifdef ANSIC
float cephes_frexpf(float, int *), cephes_polevlf(float, float *, int);

float cephes_log2f(float xx)
#else
float cephes_frexpf(), cephes_polevlf();

float cephes_log2f(xx)
double xx;
#endif
{
float x, y, z;
int e;

x = xx;
/* Test for domain */
 if( x != x) return x;
 if( x == 1.0/0.0) return x;
 if( x <= 0.0 )
	{
	if( x == 0.0 )
	  return -1.0/0.0;
	else
	  return 0.0/0.0;
	}

/* separate mantissa from exponent */
x = cephes_frexpf( x, &e );


/* logarithm using log(1+x) = x - .5x**2 + x**3 P(x)/Q(x) */

if( x < SQRTH )
	{
	e -= 1;
	x = 2.0*x - 1.0;
	}	
 else 
	{
	x = x - 1.0;
	}


z = x*x;
y = x * ( z * cephes_polevlf( x, P, 8 ) );
y = y - 0.5 * z;   /*  y - 0.5 * x**2  */


/* Multiply log of fraction by log2(e)
 * and base 2 exponent by 1
 *
 * ***CAUTION***
 *
 * This sequence of operations is critical and it may
 * be horribly defeated by some compiler optimizers.
 */
z = y * LOG2EA;
z += x * LOG2EA;
z += y;
z += x;
z += (float )e;
return( z );
}
