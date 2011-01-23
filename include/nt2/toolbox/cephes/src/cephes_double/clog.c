/*							clog.c
 *
 *	Complex natural logarithm
 *
 *
 *
 * SYNOPSIS:
 *
 * void cephes_clog();
 * cmplx z, w;
 *
 * cephes_clog( &z, &w );
 *
 *
 *
 * DESCRIPTION:
 *
 * Returns complex logarithm to the base e (2.718...) of
 * the complex argument x.
 *
 * If z = x + iy, r = cephes_sqrt( x**2 + y**2 ),
 * then
 *       w = cephes_log(r) + i arctan(y/x).
 * 
 * The arctangent ranges from -PI to +PI.
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    DEC       -10,+10      7000       8.5e-17     1.9e-17
 *    IEEE      -10,+10     30000       5.0e-15     1.1e-16
 *
 * Larger relative error can be observed for z near 1 +i0.
 * In IEEE arithmetic the peak absolute error is 5.2e-16, rms
 * absolute error 1.0e-16.
 */

/*
Cephes Math Library Release 2.8:  June, 2000
Copyright 1984, 1995, 2000 by Stephen L. Moshier
*/
#include "mconf.h"
#ifdef ANSIPROT
static void cephes_cchsh ( double x, double *c, double *s );
static double cephes_redupi ( double x );
static double cephes_ctans ( cmplx *z );
/* These are supposed to be in some standard place. */
double fabs (double);
double cephes_sqrt (double);
double cephes_pow (double, double);
double cephes_log (double);
double cephes_exp (double);
double cephes_atan2 (double, double);
double cephes_cosh (double);
double cephes_sinh (double);
double cephes_asin (double);
double cephes_sin (double);
double cephes_cos (double);
double cephes_cabs (cmplx *);
void cephes_cadd ( cmplx *, cmplx *, cmplx * );
void cephes_cmul ( cmplx *, cmplx *, cmplx * );
void cephes_csqrt ( cmplx *, cmplx * );
static void cephes_cchsh ( double, double *, double * );
static double cephes_redupi ( double );
static double cephes_ctans ( cmplx * );
void cephes_clog ( cmplx *, cmplx * );
void cephes_casin ( cmplx *, cmplx * );
void cephes_cacos ( cmplx *, cmplx * );
void cephes_catan ( cmplx *, cmplx * );
#else
static void cephes_cchsh();
static double cephes_redupi();
static double cephes_ctans();
double cephes_cabs(), fabs(), cephes_sqrt(), cephes_pow();
double cephes_log(), cephes_exp(), cephes_atan2(), cephes_cosh(), cephes_sinh();
double cephes_asin(), cephes_sin(), cephes_cos();
void cephes_cadd(), cephes_cmul(), cephes_csqrt();
void cephes_clog(), cephes_casin(), cephes_cacos(), cephes_catan();
#endif


extern double MAXNUM, MACHEP, PI, PIO2;

void cephes_clog( z, w )
register cmplx *z, *w;
{
double p, rr;

/*rr = cephes_sqrt( z->r * z->r  +  z->i * z->i );*/
rr = cephes_cabs(z);
p = cephes_log(rr);
#if ANSIC
rr = cephes_atan2( z->i, z->r );
#else
rr = cephes_atan2( z->r, z->i );
if( rr > PI )
	rr -= PI + PI;
#endif
w->i = rr;
w->r = p;
}
/*							cephes_cexp()
 *
 *	Complex exponential function
 *
 *
 *
 * SYNOPSIS:
 *
 * void cephes_cexp();
 * cmplx z, w;
 *
 * cephes_cexp( &z, &w );
 *
 *
 *
 * DESCRIPTION:
 *
 * Returns the exponential of the complex argument z
 * into the complex result w.
 *
 * If
 *     z = x + iy,
 *     r = cephes_exp(x),
 *
 * then
 *
 *     w = r cos y + i r sin y.
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    DEC       -10,+10      8700       3.7e-17     1.1e-17
 *    IEEE      -10,+10     30000       3.0e-16     8.7e-17
 *
 */

void cephes_cexp( z, w )
register cmplx *z, *w;
{
double r;

r = cephes_exp( z->r );
w->r = r * cephes_cos( z->i );
w->i = r * cephes_sin( z->i );
}
/*							cephes_csin()
 *
 *	Complex circular sine
 *
 *
 *
 * SYNOPSIS:
 *
 * void cephes_csin();
 * cmplx z, w;
 *
 * cephes_csin( &z, &w );
 *
 *
 *
 * DESCRIPTION:
 *
 * If
 *     z = x + iy,
 *
 * then
 *
 *     w = sin x  cosh y  +  i cos x sinh y.
 *
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    DEC       -10,+10      8400       5.3e-17     1.3e-17
 *    IEEE      -10,+10     30000       3.8e-16     1.0e-16
 * Also tested by cephes_csin(cephes_casin(z)) = z.
 *
 */

void cephes_csin( z, w )
register cmplx *z, *w;
{
double ch, sh;

cephes_cchsh( z->i, &ch, &sh );
w->r = cephes_sin( z->r ) * ch;
w->i = cephes_cos( z->r ) * sh;
}



/* calculate cosh and sinh */

static void cephes_cchsh( x, c, s )
double x, *c, *s;
{
double e, ei;

if( fabs(x) <= 0.5 )
	{
	*c = cephes_cosh(x);
	*s = cephes_sinh(x);
	}
else
	{
	e = cephes_exp(x);
	ei = 0.5/e;
	e = 0.5 * e;
	*s = e - ei;
	*c = e + ei;
	}
}

/*							cephes_ccos()
 *
 *	Complex circular cosine
 *
 *
 *
 * SYNOPSIS:
 *
 * void cephes_ccos();
 * cmplx z, w;
 *
 * cephes_ccos( &z, &w );
 *
 *
 *
 * DESCRIPTION:
 *
 * If
 *     z = x + iy,
 *
 * then
 *
 *     w = cos x  cosh y  -  i sin x sinh y.
 *
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    DEC       -10,+10      8400       4.5e-17     1.3e-17
 *    IEEE      -10,+10     30000       3.8e-16     1.0e-16
 */

void cephes_ccos( z, w )
register cmplx *z, *w;
{
double ch, sh;

cephes_cchsh( z->i, &ch, &sh );
w->r = cephes_cos( z->r ) * ch;
w->i = -cephes_sin( z->r ) * sh;
}
/*							cephes_ctan()
 *
 *	Complex circular tangent
 *
 *
 *
 * SYNOPSIS:
 *
 * void cephes_ctan();
 * cmplx z, w;
 *
 * cephes_ctan( &z, &w );
 *
 *
 *
 * DESCRIPTION:
 *
 * If
 *     z = x + iy,
 *
 * then
 *
 *           sin 2x  +  i sinh 2y
 *     w  =  --------------------.
 *            cos 2x  +  cosh 2y
 *
 * On the real axis the denominator is zero at odd multiples
 * of PI/2.  The denominator is evaluated by its Taylor
 * series near these points.
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    DEC       -10,+10      5200       7.1e-17     1.6e-17
 *    IEEE      -10,+10     30000       7.2e-16     1.2e-16
 * Also tested by ctan * ccot = 1 and cephes_catan(cephes_ctan(z))  =  z.
 */

void cephes_ctan( z, w )
register cmplx *z, *w;
{
double d;

d = cephes_cos( 2.0 * z->r ) + cephes_cosh( 2.0 * z->i );

if( fabs(d) < 0.25 )
	d = cephes_ctans(z);

if( d == 0.0 )
	{
	cephes_mtherr( "ctan", OVERFLOW );
	w->r = MAXNUM;
	w->i = MAXNUM;
	return;
	}

w->r = cephes_sin( 2.0 * z->r ) / d;
w->i = cephes_sinh( 2.0 * z->i ) / d;
}
/*							cephes_ccot()
 *
 *	Complex circular cotangent
 *
 *
 *
 * SYNOPSIS:
 *
 * void cephes_ccot();
 * cmplx z, w;
 *
 * cephes_ccot( &z, &w );
 *
 *
 *
 * DESCRIPTION:
 *
 * If
 *     z = x + iy,
 *
 * then
 *
 *           sin 2x  -  i sinh 2y
 *     w  =  --------------------.
 *            cosh 2y  -  cos 2x
 *
 * On the real axis, the denominator has zeros at even
 * multiples of PI/2.  Near these points it is evaluated
 * by a Taylor series.
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    DEC       -10,+10      3000       6.5e-17     1.6e-17
 *    IEEE      -10,+10     30000       9.2e-16     1.2e-16
 * Also tested by ctan * ccot = 1 + i0.
 */

void cephes_ccot( z, w )
register cmplx *z, *w;
{
double d;

d = cephes_cosh(2.0 * z->i) - cephes_cos(2.0 * z->r);

if( fabs(d) < 0.25 )
	d = cephes_ctans(z);

if( d == 0.0 )
	{
	cephes_mtherr( "ccot", OVERFLOW );
	w->r = MAXNUM;
	w->i = MAXNUM;
	return;
	}

w->r = cephes_sin( 2.0 * z->r ) / d;
w->i = -cephes_sinh( 2.0 * z->i ) / d;
}

/* Program to subtract nearest integer multiple of PI */
/* extended precision value of PI: */
#ifdef UNK
static double DP1 = 3.14159265160560607910E0;
static double DP2 = 1.98418714791870343106E-9;
static double DP3 = 1.14423774522196636802E-17;
#endif

#ifdef DEC
static unsigned short P1[] = {0040511,0007732,0120000,0000000,};
static unsigned short P2[] = {0031010,0055060,0100000,0000000,};
static unsigned short P3[] = {0022123,0011431,0105056,0001560,};
#define DP1 *(double *)P1
#define DP2 *(double *)P2
#define DP3 *(double *)P3
#endif

#ifdef IBMPC
static unsigned short P1[] = {0x0000,0x5400,0x21fb,0x4009};
static unsigned short P2[] = {0x0000,0x1000,0x0b46,0x3e21};
static unsigned short P3[] = {0xc06e,0x3145,0x6263,0x3c6a};
#define DP1 *(double *)P1
#define DP2 *(double *)P2
#define DP3 *(double *)P3
#endif

#ifdef MIEEE
static unsigned short P1[] = {
0x4009,0x21fb,0x5400,0x0000
};
static unsigned short P2[] = {
0x3e21,0x0b46,0x1000,0x0000
};
static unsigned short P3[] = {
0x3c6a,0x6263,0x3145,0xc06e
};
#define DP1 *(double *)P1
#define DP2 *(double *)P2
#define DP3 *(double *)P3
#endif

static double cephes_redupi(x)
double x;
{
double t;
long i;

t = x/PI;
if( t >= 0.0 )
	t += 0.5;
else
	t -= 0.5;

i = t;	/* the multiple */
t = i;
t = ((x - t * DP1) - t * DP2) - t * DP3;
return(t);
}

/*  Taylor series expansion for cephes_cosh(2y) - cephes_cos(2x)	*/

static double cephes_ctans(z)
cmplx *z;
{
double f, x, x2, y, y2, rn, t;
double d;

x = fabs( 2.0 * z->r );
y = fabs( 2.0 * z->i );

x = cephes_redupi(x);

x = x * x;
y = y * y;
x2 = 1.0;
y2 = 1.0;
f = 1.0;
rn = 0.0;
d = 0.0;
do
	{
	rn += 1.0;
	f *= rn;
	rn += 1.0;
	f *= rn;
	x2 *= x;
	y2 *= y;
	t = y2 + x2;
	t /= f;
	d += t;

	rn += 1.0;
	f *= rn;
	rn += 1.0;
	f *= rn;
	x2 *= x;
	y2 *= y;
	t = y2 - x2;
	t /= f;
	d += t;
	}
while( fabs(t/d) > MACHEP );
return(d);
}
/*							cephes_casin()
 *
 *	Complex circular arc sine
 *
 *
 *
 * SYNOPSIS:
 *
 * void cephes_casin();
 * cmplx z, w;
 *
 * cephes_casin( &z, &w );
 *
 *
 *
 * DESCRIPTION:
 *
 * Inverse complex sine:
 *
 *                               2
 * w = -i cephes_clog( iz + cephes_csqrt( 1 - z ) ).
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    DEC       -10,+10     10100       2.1e-15     3.4e-16
 *    IEEE      -10,+10     30000       2.2e-14     2.7e-15
 * Larger relative error can be observed for z near zero.
 * Also tested by cephes_csin(cephes_casin(z)) = z.
 */

void cephes_casin( z, w )
cmplx *z, *w;
{
static cmplx ca, ct, zz, z2;
double x, y;

x = z->r;
y = z->i;

if( y == 0.0 )
	{
	if( fabs(x) > 1.0 )
		{
		w->r = PIO2;
		w->i = 0.0;
		cephes_mtherr( "casin", DOMAIN );
		}
	else
		{
		w->r = cephes_asin(x);
		w->i = 0.0;
		}
	return;
	}

/* Power series expansion */
/*
b = cephes_cabs(z);
if( b < 0.125 )
{
z2.r = (x - y) * (x + y);
z2.i = 2.0 * x * y;

cn = 1.0;
n = 1.0;
ca.r = x;
ca.i = y;
sum.r = x;
sum.i = y;
do
	{
	ct.r = z2.r * ca.r  -  z2.i * ca.i;
	ct.i = z2.r * ca.i  +  z2.i * ca.r;
	ca.r = ct.r;
	ca.i = ct.i;

	cn *= n;
	n += 1.0;
	cn /= n;
	n += 1.0;
	b = cn/n;

	ct.r *= b;
	ct.i *= b;
	sum.r += ct.r;
	sum.i += ct.i;
	b = fabs(ct.r) + fabs(ct.i);
	}
while( b > MACHEP );
w->r = sum.r;
w->i = sum.i;
return;
}
*/


ca.r = x;
ca.i = y;

ct.r = -ca.i;	/* iz */
ct.i = ca.r;

	/* cephes_sqrt( 1 - z*z) */
/* cephes_cmul( &ca, &ca, &zz ) */
zz.r = (ca.r - ca.i) * (ca.r + ca.i);	/*x * x  -  y * y */
zz.i = 2.0 * ca.r * ca.i;

zz.r = 1.0 - zz.r;
zz.i = -zz.i;
cephes_csqrt( &zz, &z2 );

cephes_cadd( &z2, &ct, &zz );
cephes_clog( &zz, &zz );
w->r = zz.i;	/* mult by 1/i = -i */
w->i = -zz.r;
return;
}
/*							cephes_cacos()
 *
 *	Complex circular arc cosine
 *
 *
 *
 * SYNOPSIS:
 *
 * void cephes_cacos();
 * cmplx z, w;
 *
 * cephes_cacos( &z, &w );
 *
 *
 *
 * DESCRIPTION:
 *
 *
 * w = arccos z  =  PI/2 - arcsin z.
 *
 *
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    DEC       -10,+10      5200      1.6e-15      2.8e-16
 *    IEEE      -10,+10     30000      1.8e-14      2.2e-15
 */

void cephes_cacos( z, w )
cmplx *z, *w;
{

cephes_casin( z, w );
w->r = PIO2  -  w->r;
w->i = -w->i;
}
/*							cephes_catan()
 *
 *	Complex circular arc tangent
 *
 *
 *
 * SYNOPSIS:
 *
 * void cephes_catan();
 * cmplx z, w;
 *
 * cephes_catan( &z, &w );
 *
 *
 *
 * DESCRIPTION:
 *
 * If
 *     z = x + iy,
 *
 * then
 *          1       (    2x     )
 * Re w  =  - arctan(-----------)  +  k PI
 *          2       (     2    2)
 *                  (1 - x  - y )
 *
 *               ( 2         2)
 *          1    (x  +  (y+1) )
 * Im w  =  - cephes_log(------------)
 *          4    ( 2         2)
 *               (x  +  (y-1) )
 *
 * Where k is an arbitrary integer.
 *
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    DEC       -10,+10      5900       1.3e-16     7.8e-18
 *    IEEE      -10,+10     30000       2.3e-15     8.5e-17
 * The check cephes_catan( cephes_ctan(z) )  =  z, with |x| and |y| < PI/2,
 * had peak relative error 1.5e-16, rms relative error
 * 2.9e-17.  See also cephes_clog().
 */

void cephes_catan( z, w )
cmplx *z, *w;
{
double a, t, x, x2, y;

x = z->r;
y = z->i;

if( (x == 0.0) && (y > 1.0) )
	goto ovrf;

x2 = x * x;
a = 1.0 - x2 - (y * y);
if( a == 0.0 )
	goto ovrf;

#if ANSIC
t = cephes_atan2( 2.0 * x, a )/2.0;
#else
t = cephes_atan2( a, 2.0 * x )/2.0;
#endif
w->r = cephes_redupi( t );

t = y - 1.0;
a = x2 + (t * t);
if( a == 0.0 )
	goto ovrf;

t = y + 1.0;
a = (x2 + (t * t))/a;
w->i = cephes_log(a)/4.0;
return;

ovrf:
cephes_mtherr( "catan", OVERFLOW );
w->r = MAXNUM;
w->i = MAXNUM;
}


/*							csinh
 *
 *	Complex hyperbolic sine
 *
 *
 *
 * SYNOPSIS:
 *
 * void csinh();
 * cmplx z, w;
 *
 * csinh( &z, &w );
 *
 *
 * DESCRIPTION:
 *
 * csinh z = (cephes_cexp(z) - cephes_cexp(-z))/2
 *         = sinh x * cos y  +  i cosh x * sin y .
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE      -10,+10     30000       3.1e-16     8.2e-17
 *
 */

void
csinh (z, w)
     cmplx *z, *w;
{
  double x, y;

  x = z->r;
  y = z->i;
  w->r = cephes_sinh (x) * cephes_cos (y);
  w->i = cephes_cosh (x) * cephes_sin (y);
}


/*							casinh
 *
 *	Complex inverse hyperbolic sine
 *
 *
 *
 * SYNOPSIS:
 *
 * void casinh();
 * cmplx z, w;
 *
 * casinh (&z, &w);
 *
 *
 *
 * DESCRIPTION:
 *
 * casinh z = -i casin iz .
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE      -10,+10     30000       1.8e-14     2.6e-15
 *
 */

void
casinh (z, w)
     cmplx *z, *w;
{
  cmplx u;

  u.r = 0.0;
  u.i = 1.0;
  cephes_cmul( z, &u, &u );
  cephes_casin( &u, w );
  u.r = 0.0;
  u.i = -1.0;
  cephes_cmul( &u, w, w );
}

/*							ccosh
 *
 *	Complex hyperbolic cosine
 *
 *
 *
 * SYNOPSIS:
 *
 * void ccosh();
 * cmplx z, w;
 *
 * ccosh (&z, &w);
 *
 *
 *
 * DESCRIPTION:
 *
 * ccosh(z) = cosh x  cos y + i sinh x sin y .
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE      -10,+10     30000       2.9e-16     8.1e-17
 *
 */

void
ccosh (z, w)
     cmplx *z, *w;
{
  double x, y;

  x = z->r;
  y = z->i;
  w->r = cephes_cosh (x) * cephes_cos (y);
  w->i = cephes_sinh (x) * cephes_sin (y);
}


/*							cacosh
 *
 *	Complex inverse hyperbolic cosine
 *
 *
 *
 * SYNOPSIS:
 *
 * void cacosh();
 * cmplx z, w;
 *
 * cacosh (&z, &w);
 *
 *
 *
 * DESCRIPTION:
 *
 * acosh z = i acos z .
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE      -10,+10     30000       1.6e-14     2.1e-15
 *
 */

void
cacosh (z, w)
     cmplx *z, *w;
{
  cmplx u;

  cephes_cacos( z, w );
  u.r = 0.0;
  u.i = 1.0;
  cephes_cmul( &u, w, w );
}


/*							ctanh
 *
 *	Complex hyperbolic tangent
 *
 *
 *
 * SYNOPSIS:
 *
 * void ctanh();
 * cmplx z, w;
 *
 * ctanh (&z, &w);
 *
 *
 *
 * DESCRIPTION:
 *
 * tanh z = (sinh 2x  +  i sin 2y) / (cosh 2x + cos 2y) .
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE      -10,+10     30000       1.7e-14     2.4e-16
 *
 */

/* 5.253E-02,1.550E+00 1.643E+01,6.553E+00 1.729E-14  21355  */

void
ctanh (z, w)
     cmplx *z, *w;
{
  double x, y, d;

  x = z->r;
  y = z->i;
  d = cephes_cosh (2.0 * x) + cephes_cos (2.0 * y);
  w->r = cephes_sinh (2.0 * x) / d;
  w->i = cephes_sin (2.0 * y) / d;
  return;
}


/*							catanh
 *
 *	Complex inverse hyperbolic tangent
 *
 *
 *
 * SYNOPSIS:
 *
 * void catanh();
 * cmplx z, w;
 *
 * catanh (&z, &w);
 *
 *
 *
 * DESCRIPTION:
 *
 * Inverse tanh, equal to  -i cephes_catan (iz);
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE      -10,+10     30000       2.3e-16     6.2e-17
 *
 */

void
catanh (z, w)
     cmplx *z, *w;
{
  cmplx u;

  u.r = 0.0;
  u.i = 1.0;
  cephes_cmul (z, &u, &u);  /* i z */
  cephes_catan (&u, w);
  u.r = 0.0;
  u.i = -1.0;
  cephes_cmul (&u, w, w);  /* -i catan iz */
  return;
}


/*							cpow
 *
 *	Complex power function
 *
 *
 *
 * SYNOPSIS:
 *
 * void cpow();
 * cmplx a, z, w;
 *
 * cpow (&a, &z, &w);
 *
 *
 *
 * DESCRIPTION:
 *
 * Raises complex A to the complex Zth power.
 * Definition is per AMS55 # 4.2.8,
 * analytically equivalent to cpow(a,z) = cephes_cexp(z cephes_clog(a)).
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE      -10,+10     30000       9.4e-15     1.5e-15
 *
 */


void
cpow (a, z, w)
     cmplx *a, *z, *w;
{
  double x, y, r, theta, absa, arga;

  x = z->r;
  y = z->i;
  absa = cephes_cabs (a);
  if (absa == 0.0)
    {
      w->r = 0.0;
      w->i = 0.0;
      return;
    }
  arga = cephes_atan2 (a->i, a->r);
  r = cephes_pow (absa, x);
  theta = x * arga;
  if (y != 0.0)
    {
      r = r * cephes_exp (-y * arga);
      theta = theta + y * cephes_log (absa);
    }
  w->r = r * cephes_cos (theta);
  w->i = r * cephes_sin (theta);
  return;
}
