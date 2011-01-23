/*							cmplx.c
 *
 *	Complex number arithmetic
 *
 *
 *
 * SYNOPSIS:
 *
 * typedef struct {
 *      double r;     real part
 *      double i;     imaginary part
 *     }cmplx;
 *
 * cmplx *a, *b, *c;
 *
 * cephes_cadd( a, b, c );     c = b + a
 * cephes_csub( a, b, c );     c = b - a
 * cephes_cmul( a, b, c );     c = b * a
 * cephes_cdiv( a, b, c );     c = b / a
 * cephes_cneg( c );           c = -c
 * cephes_cmov( b, c );        c = b
 *
 *
 *
 * DESCRIPTION:
 *
 * Addition:
 *    c.r  =  b.r + a.r
 *    c.i  =  b.i + a.i
 *
 * Subtraction:
 *    c.r  =  b.r - a.r
 *    c.i  =  b.i - a.i
 *
 * Multiplication:
 *    c.r  =  b.r * a.r  -  b.i * a.i
 *    c.i  =  b.r * a.i  +  b.i * a.r
 *
 * Division:
 *    d    =  a.r * a.r  +  a.i * a.i
 *    c.r  = (b.r * a.r  + b.i * a.i)/d
 *    c.i  = (b.i * a.r  -  b.r * a.i)/d
 * ACCURACY:
 *
 * In DEC arithmetic, the test (1/z) * z = 1 had peak relative
 * error 3.1e-17, rms 1.2e-17.  The test (y/z) * (z/y) = 1 had
 * peak relative error 8.3e-17, rms 2.1e-17.
 *
 * Tests in the rectangle {-10,+10}:
 *                      Relative error:
 * arithmetic   function  # trials      peak         rms
 *    DEC        cadd       10000       1.4e-17     3.4e-18
 *    IEEE       cadd      100000       1.1e-16     2.7e-17
 *    DEC        csub       10000       1.4e-17     4.5e-18
 *    IEEE       csub      100000       1.1e-16     3.4e-17
 *    DEC        cmul        3000       2.3e-17     8.7e-18
 *    IEEE       cmul      100000       2.1e-16     6.9e-17
 *    DEC        cdiv       18000       4.9e-17     1.3e-17
 *    IEEE       cdiv      100000       3.7e-16     1.1e-16
 */
/*				cmplx.c
 * complex number arithmetic
 */


/*
Cephes Math Library Release 2.8:  June, 2000
Copyright 1984, 1995, 2000 by Stephen L. Moshier
*/


#include "mconf.h"

#ifdef ANSIPROT
extern double fabs ( double );
extern double cephes_cabs ( cmplx * );
extern double cephes_sqrt ( double );
extern double cephes_atan2 ( double, double );
extern double cephes_cos ( double );
extern double cephes_sin ( double );
extern double cephes_sqrt ( double );
extern double cephes_frexp ( double, int * );
extern double cephes_ldexp ( double, int );
int isnan ( double );
void cephes_cdiv ( cmplx *, cmplx *, cmplx * );
void cephes_cadd ( cmplx *, cmplx *, cmplx * );
#else
double fabs(), cephes_cabs(), cephes_sqrt(), cephes_atan2(), cephes_cos(), cephes_sin();
double cephes_sqrt(), cephes_frexp(), cephes_ldexp();
int isnan();
void cephes_cdiv(), cephes_cadd();
#endif

extern double MAXNUM, MACHEP, PI, PIO2, INFINITY, NAN;
/*
typedef struct
	{
	double r;
	double i;
	}cmplx;
*/
cmplx czero = {0.0, 0.0};
extern cmplx czero;
cmplx cone = {1.0, 0.0};
extern cmplx cone;

/*	c = b + a	*/

void cephes_cadd( a, b, c )
register cmplx *a, *b;
cmplx *c;
{

c->r = b->r + a->r;
c->i = b->i + a->i;
}


/*	c = b - a	*/

void cephes_csub( a, b, c )
register cmplx *a, *b;
cmplx *c;
{

c->r = b->r - a->r;
c->i = b->i - a->i;
}

/*	c = b * a */

void cephes_cmul( a, b, c )
register cmplx *a, *b;
cmplx *c;
{
double y;

y    = b->r * a->r  -  b->i * a->i;
c->i = b->r * a->i  +  b->i * a->r;
c->r = y;
}



/*	c = b / a */

void cephes_cdiv( a, b, c )
register cmplx *a, *b;
cmplx *c;
{
double y, p, q, w;


y = a->r * a->r  +  a->i * a->i;
p = b->r * a->r  +  b->i * a->i;
q = b->i * a->r  -  b->r * a->i;

if( y < 1.0 )
	{
	w = MAXNUM * y;
	if( (fabs(p) > w) || (fabs(q) > w) || (y == 0.0) )
		{
		c->r = MAXNUM;
		c->i = MAXNUM;
		cephes_mtherr( "cdiv", OVERFLOW );
		return;
		}
	}
c->r = p/y;
c->i = q/y;
}


/*	b = a
   Caution, a `short' is assumed to be 16 bits wide.  */

void cephes_cmov( a, b )
void *a, *b;
{
register short *pa, *pb;
int i;

pa = (short *) a;
pb = (short *) b;
i = 8;
do
	*pb++ = *pa++;
while( --i );
}


void cephes_cneg( a )
register cmplx *a;
{

a->r = -a->r;
a->i = -a->i;
}

/*							cephes_cabs()
 *
 *	Complex absolute value
 *
 *
 *
 * SYNOPSIS:
 *
 * double cephes_cabs();
 * cmplx z;
 * double a;
 *
 * a = cephes_cabs( &z );
 *
 *
 *
 * DESCRIPTION:
 *
 *
 * If z = x + iy
 *
 * then
 *
 *       a = cephes_sqrt( x**2 + y**2 ).
 * 
 * Overflow and underflow are avoided by testing the magnitudes
 * of x and y before squaring.  If either is outside half of
 * the floating point full scale range, both are rescaled.
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    DEC       -30,+30     30000       3.2e-17     9.2e-18
 *    IEEE      -10,+10    100000       2.7e-16     6.9e-17
 */


/*
Cephes Math Library Release 2.1:  January, 1989
Copyright 1984, 1987, 1989 by Stephen L. Moshier
Direct inquiries to 30 Frost Street, Cambridge, MA 02140
*/


/*
typedef struct
	{
	double r;
	double i;
	}cmplx;
*/

#ifdef UNK
#define PREC 27
#define MAXEXP 1024
#define MINEXP -1077
#endif
#ifdef DEC
#define PREC 29
#define MAXEXP 128
#define MINEXP -128
#endif
#ifdef IBMPC
#define PREC 27
#define MAXEXP 1024
#define MINEXP -1077
#endif
#ifdef MIEEE
#define PREC 27
#define MAXEXP 1024
#define MINEXP -1077
#endif


double cephes_cabs( z )
register cmplx *z;
{
double x, y, b, re, im;
int ex, ey, e;

#ifdef INFINITIES
/* Note, cephes_cabs(INFINITY,NAN) = INFINITY. */
if( z->r == INFINITY || z->i == INFINITY
   || z->r == -INFINITY || z->i == -INFINITY )
  return( INFINITY );
#endif

#ifdef NANS
if( isnan(z->r) )
  return(z->r);
if( isnan(z->i) )
  return(z->i);
#endif

re = fabs( z->r );
im = fabs( z->i );

if( re == 0.0 )
	return( im );
if( im == 0.0 )
	return( re );

/* Get the exponents of the numbers */
x = cephes_frexp( re, &ex );
y = cephes_frexp( im, &ey );

/* Check if one number is tiny compared to the other */
e = ex - ey;
if( e > PREC )
	return( re );
if( e < -PREC )
	return( im );

/* Find approximate exponent e of the geometric mean. */
e = (ex + ey) >> 1;

/* Rescale so mean is about 1 */
x = cephes_ldexp( re, -e );
y = cephes_ldexp( im, -e );
		
/* Hypotenuse of the right triangle */
b = cephes_sqrt( x * x  +  y * y );

/* Compute the exponent of the answer. */
y = cephes_frexp( b, &ey );
ey = e + ey;

/* Check it for overflow and underflow. */
if( ey > MAXEXP )
	{
	cephes_mtherr( "cabs", OVERFLOW );
	return( INFINITY );
	}
if( ey < MINEXP )
	return(0.0);

/* Undo the scaling */
b = cephes_ldexp( b, e );
return( b );
}
/*							cephes_csqrt()
 *
 *	Complex square root
 *
 *
 *
 * SYNOPSIS:
 *
 * void cephes_csqrt();
 * cmplx z, w;
 *
 * cephes_csqrt( &z, &w );
 *
 *
 *
 * DESCRIPTION:
 *
 *
 * If z = x + iy,  r = |z|, then
 *
 *                       1/2
 * Im w  =  [ (r - x)/2 ]   ,
 *
 * Re w  =  y / 2 Im w.
 *
 *
 * Note that -w is also a square root of z.  The root chosen
 * is always in the upper half plane.
 *
 * Because of the potential for cancellation error in r - x,
 * the result is sharpened by doing a Heron iteration
 * (see sqrt.c) in complex arithmetic.
 *
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    DEC       -10,+10     25000       3.2e-17     9.6e-18
 *    IEEE      -10,+10    100000       3.2e-16     7.7e-17
 *
 *                        2
 * Also tested by cephes_csqrt( z ) = z, and tested by arguments
 * close to the real axis.
 */


void cephes_csqrt( z, w )
cmplx *z, *w;
{
cmplx q, s;
double x, y, r, t;

x = z->r;
y = z->i;

if( y == 0.0 )
	{
	if( x < 0.0 )
		{
		w->r = 0.0;
		w->i = cephes_sqrt(-x);
		return;
		}
	else
		{
		w->r = cephes_sqrt(x);
		w->i = 0.0;
		return;
		}
	}


if( x == 0.0 )
	{
	r = fabs(y);
	r = cephes_sqrt(0.5*r);
	if( y > 0 )
		w->r = r;
	else
		w->r = -r;
	w->i = r;
	return;
	}

/* Approximate  cephes_sqrt(x^2+y^2) - x  =  y^2/2x - y^4/24x^3 + ... .
 * The relative error in the first term is approximately y^2/12x^2 .
 */
if( (fabs(y) < 2.e-4 * fabs(x))
   && (x > 0) )
	{
	t = 0.25*y*(y/x);
	}
else
	{
	r = cephes_cabs(z);
	t = 0.5*(r - x);
	}

r = cephes_sqrt(t);
q.i = r;
q.r = y/(2.0*r);
/* Heron iteration in complex arithmetic */
cephes_cdiv( &q, z, &s );
cephes_cadd( &q, &s, w );
w->r *= 0.5;
w->i *= 0.5;
}


double hypot( x, y )
double x, y;
{
cmplx z;

z.r = x;
z.i = y;
return( cephes_cabs(&z) );
}
