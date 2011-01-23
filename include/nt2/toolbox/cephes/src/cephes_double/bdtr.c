/*							bdtr.c
 *
 *	Binomial distribution
 *
 *
 *
 * SYNOPSIS:
 *
 * int k, n;
 * double p, y, cephes_bdtr();
 *
 * y = cephes_bdtr( k, n, p );
 *
 * DESCRIPTION:
 *
 * Returns the sum of the terms 0 through k of the Binomial
 * probability density:
 *
 *   k
 *   --  ( n )   j      n-j
 *   >   (   )  p  (1-p)
 *   --  ( j )
 *  j=0
 *
 * The terms are not summed directly; instead the incomplete
 * beta integral is employed, according to the formula
 *
 * y = cephes_bdtr( k, n, p ) = cephes_incbet( n-k, k+1, 1-p ).
 *
 * The arguments must be positive, with p ranging from 0 to 1.
 *
 * ACCURACY:
 *
 * Tested at random points (a,b,p), with p between 0 and 1.
 *
 *               a,b                     Relative error:
 * arithmetic  domain     # trials      peak         rms
 *  For p between 0.001 and 1:
 *    IEEE     0,100       100000      4.3e-15     2.6e-16
 * See also incbet.c.
 *
 * ERROR MESSAGES:
 *
 *   message         condition      value returned
 * bdtr domain         k < 0            0.0
 *                     n < k
 *                     x < 0, x > 1
 */
/*							cephes_bdtrc()
 *
 *	Complemented binomial distribution
 *
 *
 *
 * SYNOPSIS:
 *
 * int k, n;
 * double p, y, cephes_bdtrc();
 *
 * y = cephes_bdtrc( k, n, p );
 *
 * DESCRIPTION:
 *
 * Returns the sum of the terms k+1 through n of the Binomial
 * probability density:
 *
 *   n
 *   --  ( n )   j      n-j
 *   >   (   )  p  (1-p)
 *   --  ( j )
 *  j=k+1
 *
 * The terms are not summed directly; instead the incomplete
 * beta integral is employed, according to the formula
 *
 * y = cephes_bdtrc( k, n, p ) = cephes_incbet( k+1, n-k, p ).
 *
 * The arguments must be positive, with p ranging from 0 to 1.
 *
 * ACCURACY:
 *
 * Tested at random points (a,b,p).
 *
 *               a,b                     Relative error:
 * arithmetic  domain     # trials      peak         rms
 *  For p between 0.001 and 1:
 *    IEEE     0,100       100000      6.7e-15     8.2e-16
 *  For p between 0 and .001:
 *    IEEE     0,100       100000      1.5e-13     2.7e-15
 *
 * ERROR MESSAGES:
 *
 *   message         condition      value returned
 * bdtrc domain      x<0, x>1, n<k       0.0
 */
/*							cephes_bdtri()
 *
 *	Inverse binomial distribution
 *
 *
 *
 * SYNOPSIS:
 *
 * int k, n;
 * double p, y, cephes_bdtri();
 *
 * p = cephes_bdtr( k, n, y );
 *
 * DESCRIPTION:
 *
 * Finds the event probability p such that the sum of the
 * terms 0 through k of the Binomial probability density
 * is equal to the given cumulative probability y.
 *
 * This is accomplished using the inverse beta integral
 * function and the relation
 *
 * 1 - p = cephes_incbi( n-k, k+1, y ).
 *
 * ACCURACY:
 *
 * Tested at random points (a,b,p).
 *
 *               a,b                     Relative error:
 * arithmetic  domain     # trials      peak         rms
 *  For p between 0.001 and 1:
 *    IEEE     0,100       100000      2.3e-14     6.4e-16
 *    IEEE     0,10000     100000      6.6e-12     1.2e-13
 *  For p between 10^-6 and 0.001:
 *    IEEE     0,100       100000      2.0e-12     1.3e-14
 *    IEEE     0,10000     100000      1.5e-12     3.2e-14
 * See also incbi.c.
 *
 * ERROR MESSAGES:
 *
 *   message         condition      value returned
 * bdtri domain     k < 0, n <= k         0.0
 *                  x < 0, x > 1
 */

/*								cephes_bdtr() */


/*
Cephes Math Library Release 2.8:  June, 2000
Copyright 1984, 1987, 1995, 2000 by Stephen L. Moshier
*/

#include "mconf.h"
#ifdef ANSIPROT
extern double cephes_incbet ( double, double, double );
extern double cephes_incbi ( double, double, double );
extern double cephes_pow ( double, double );
extern double log1p ( double );
extern double expm1 ( double );
#else
double cephes_incbet(), cephes_incbi(), cephes_pow(), log1p(), expm1();
#endif

double cephes_bdtrc( k, n, p )
int k, n;
double p;
{
double dk, dn;

if( (p < 0.0) || (p > 1.0) )
	goto domerr;
if( k < 0 )
	return( 1.0 );

if( n < k )
	{
domerr:
	cephes_mtherr( "bdtrc", DOMAIN );
	return( 0.0 );
	}

if( k == n )
	return( 0.0 );
dn = n - k;
if( k == 0 )
	{
	if( p < .01 )
		dk = -expm1( dn * log1p(-p) );
	else
		dk = 1.0 - cephes_pow( 1.0-p, dn );
	}
else
	{
	dk = k + 1;
	dk = cephes_incbet( dk, dn, p );
	}
return( dk );
}



double cephes_bdtr( k, n, p )
int k, n;
double p;
{
double dk, dn;

if( (p < 0.0) || (p > 1.0) )
	goto domerr;
if( (k < 0) || (n < k) )
	{
domerr:
	cephes_mtherr( "bdtr", DOMAIN );
	return( 0.0 );
	}

if( k == n )
	return( 1.0 );

dn = n - k;
if( k == 0 )
	{
	dk = cephes_pow( 1.0-p, dn );
	}
else
	{
	dk = k + 1;
	dk = cephes_incbet( dn, dk, 1.0 - p );
	}
return( dk );
}


double cephes_bdtri( k, n, y )
int k, n;
double y;
{
double dk, dn, p;

if( (y < 0.0) || (y > 1.0) )
	goto domerr;
if( (k < 0) || (n <= k) )
	{
domerr:
	cephes_mtherr( "bdtri", DOMAIN );
	return( 0.0 );
	}

dn = n - k;
if( k == 0 )
	{
	if( y > 0.8 )
		p = -expm1( log1p(y-1.0) / dn );
	else
		p = 1.0 - cephes_pow( y, 1.0/dn );
	}
else
	{
	dk = k + 1;
	p = cephes_incbet( dn, dk, 0.5 );
	if( p > 0.5 )
		p = cephes_incbi( dk, dn, 1.0-y );
	else
		p = 1.0 - cephes_incbi( dn, dk, y );
	}
return( p );
}
