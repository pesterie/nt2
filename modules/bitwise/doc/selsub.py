[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '3',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'typename boost::result_of<nt2::meta::arithmetic(T,T)>::type',
            },
         'simd_types' : ['real_', 'signed_int_', 'unsigned_int_'],
         'type_defs' : [],
         'types' : ['real_', 'signed_int_', 'unsigned_int_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 18/02/2011',
             'included' : ["#include <nt2/toolbox/predicates/include/functions/is_nez.hpp>"],
             'no_ulp' : 'True',
             'notes' : [],
             'stamp' : 'modified by jt the 18/02/2011',
            },
         'ranges' : {
             'unsigned_int_' : [
                [['T(0)', 'T(0)'], ['nt2::Valmax<T>()/2', 'nt2::Valmax<T>()'], ['nt2::Valmin<T>()/2', 'nt2::Valmax<T>()/2']],
                [['T(-1)', 'T(-1)'], ['nt2::Valmax<T>()/2', 'nt2::Valmax<T>()'], ['nt2::Valmin<T>()/2', 'nt2::Valmax<T>()/2']],
                 ],
             'default' : [
                [['T(0)', 'T(0)'], ['nt2::Valmin<T>()/2', 'nt2::Valmax<T>()/2'], ['nt2::Valmin<T>()/2', 'nt2::Valmax<T>()/2']],
                [['T(-1)', 'T(-1)'], ['nt2::Valmin<T>()/2', 'nt2::Valmax<T>()/2'], ['nt2::Valmin<T>()/2', 'nt2::Valmax<T>()/2']],
                ],
             'real_' : [
                [['T(0)', 'T(0)'], ['nt2::Valmin<T>()/2', 'nt2::Valmax<T>()/2'], ['nt2::Valmin<T>()/2', 'nt2::Valmax<T>()/2']],
                [['nt2::Nan<T>()', 'nt2::Nan<T>()'], ['nt2::Valmin<T>()/2', 'nt2::Valmax<T>()/2'], ['nt2::Valmin<T>()/2', 'nt2::Valmax<T>()/2']],
                ],
            },
         'specific_values' : {
             'default' : {
                 'T(0),T(4),T(2)' : {'result' : 'T(4)','ulp_thresh' : '0.5',},
                 'T(-1),T(4),T(2)' : {'result' : 'T(2)','ulp_thresh' : '0.5',},
                 'nt2::Zero<T>()' : {'result' : 'nt2::Zero<r_t>()','ulp_thresh' : '0.5',},
                },
             'real_' : {
                 'T(0),T(1),T(2)' : {'result' : 'T(1)','ulp_thresh' : '0.5',},
                 'nt2::Nan<T>(),T(1),T(2)' : {'result' : 'T(-1)','ulp_thresh' : '0.5',},
                 'nt2::Nan<T>(),nt2::Inf<T>(),nt2::Inf<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Nan<T>(),nt2::Minf<T>(),nt2::Minf<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Nan<T>(),nt2::Nan<T>(),nt2::Nan<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Nan<T>(),nt2::Zero<T>(),nt2::Zero<T>()' : {'result' : 'nt2::Zero<r_t>()','ulp_thresh' : '0.5',},
                },
             'signed_int_' : {
                 'T(0),T(1),T(2)' : {'result' : 'T(1)','ulp_thresh' : '0.5',},
                 'T(-1),T(1),T(2)' : {'result' : 'T(-1)','ulp_thresh' : '0.5',},
                 'nt2::Zero<T>()' : {'result' : 'nt2::Zero<r_t>()','ulp_thresh' : '0.5',},
                },
            },
         'verif_test' : {
             'property_call' : {
                 'simd_special' : 'nt2::selsub(nt2::is_nez(a0),a1,a2)',
                  'integer_' : ['nt2::selsub(nt2::is_nez(a0),a1,a2)'],
                },
             'property_value' : {
                 'integer_' : ['r_t(a0?a1-a2:a2)'],
                },
             'simd' : {
                },
             'ulp_thresh' : {
                 'default' : ['0'],
                },
            },
        },
    },
]
