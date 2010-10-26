
typedef struct {
  float r;     /* real part */
  float i;     /* imaginary part */
 }cmplxf;

float cephes_acosf( float );
float cephes_acoshf( float );
void cephes_airyf( float, float *, float *, float *, float * );
float cephes_asinf( float );
float cephes_asinhf( float );
float cephes_atanf( float );
float cephes_atanhf( float );
float cephes_atan2f( float, float );
float cephes_bdtrcf( int, int, float );
float cephes_bdtrf( int, int, float );
float cephes_bdtrif( int, int, float );
float cephes_betaf( float, float );
float cephes_cbrtf( float );
float cephes_chbevlf( float, float *, int );
float cephes_chdtrcf(float, float);
float cephes_chdtrf(float, float);
float cephes_chdtrif( float, float );
float cephes_cabsf(cmplxf *);
void cephes_caddf( cmplxf *, cmplxf *, cmplxf * );
void cephes_cacosf( cmplxf *, cmplxf * );
void cephes_casinf( cmplxf *, cmplxf * );
void cephes_catanf( cmplxf *, cmplxf * );
void cephes_ccosf( cmplxf *, cmplxf * );
void cephes_ccotf( cmplxf *, cmplxf * );
void cephes_cdivf( cmplxf *, cmplxf *, cmplxf * );
float cephes_ceilf( float );
void cephes_cexpf( cmplxf *, cmplxf * );
void cephes_clogf( cmplxf *, cmplxf * );
void cephes_cmovf( cmplxf *, cmplxf * );
void cephes_cmulf( cmplxf *, cmplxf *, cmplxf * );
void cephes_cnegf( cmplxf * );
float cephes_cosdgf( float );
float cephes_cosf(float);
float cephes_coshf(float);
float cot( float );
float cephes_cotdgf( float );
void cephes_csubf( cmplxf *, cmplxf *, cmplxf * );
void cephes_csinf( cmplxf *, cmplxf * );
void cephes_csqrtf( cmplxf *, cmplxf * );
void cephes_ctanf( cmplxf *, cmplxf * );
float cephes_dawsnf(float);
float cephes_ellief( float, float );
float cephes_ellikf( float, float );
float cephes_ellpef(float);
float cephes_ellpjf( float, float, float *, float *, float *, float * );
float cephes_ellpkf(float);
float cephes_expf(float);
float expf2(float);
float cephes_exp10f(float);
float cephes_expnf( int, float );
float cephes_facf( int );
float cephes_fdtrcf( int, int, float );
float cephes_fdtrf( int, int, int );
float cephes_fdtrif( int, int, int );
float cephes_floorf(float);
void cephes_fresnlf( float, float *, float * );
float cephes_frexpf(float, int *);
float cephes_gammaf(float);
float cephes_gdtrf( float, float, float );
float cephes_gdtrcf( float, float, float );
float cephes_hyp2f1f( float, float, float, float );
float cephes_hyp2f0f(float, float, float, int, float *);
float cephes_hypergf( float, float, float );
float cephes_i0f( float );
float cephes_i0ef( float );
float cephes_i1f( float );
float cephes_i1ef( float );
float cephes_igamcf(float, float);
float cephes_igamf(float, float);
float cephes_igamif(float, float);
float cephes_incbetf(float, float, float);
float cephes_incbif( float, float, float );
float cephes_ivf( float, float );
float cephes_j0f( float );
float cephes_j1f( float );
float cephes_jnf( int, float );
float cephes_jvf( float, float );
float cephes_k0f( float );
float cephes_k1f( float );
float cephes_knf( int, float );
float cephes_ldexpf(float, int);
float cephes_lgamf(float);
float cephes_logf( float );
float cephes_log2f( float );
float cephes_log10f( float );
float cephes_nbdtrcf( int, int, float );
float cephes_nbdtrf( int, int, float );
float cephes_ndtrf( float );
float cephes_ndtrif( float );
float cephes_onef2f( float, float, float, float, float * );
float cephes_pdtrcf( int, float );
float cephes_pdtrf( int, float );
float cephes_pdtrif( int, float );
float cephes_polevlf( float, float *, int );
float cephes_p1evlf( float, float *, int );
float cephes_powf(float, float);
float cephes_powif(float, int);
float cephes_psif( float );
float cephes_rgammaf( float );
int cephes_shichif( float, float *, float * );
int cephes_sicif( float, float *, float * );
float cephes_sindgf( float );
float cephes_sinf( float );
float cephes_sinhf( float );
float cephes_spencef( float );
float cephes_sqrtf( float );
float cephes_stdtrf( int, float );
float cephes_struvef( float, float );
float cephes_tandgf( float );
float cephes_tanf( float );
float cephes_tanhf( float );
float cephes_threef0f( float, float, float, float, float * );
float cephes_ynf( int, float );
float cephes_yvf( float, float );
float cephes_zetacf( float );
float cephes_zetaf( float, float );