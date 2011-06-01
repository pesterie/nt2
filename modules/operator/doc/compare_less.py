[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '2',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'bool',
            },
         'type_defs' : [],
         'types' : ['real_', 'integer_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 18/02/2011',
             'included' : ['#include <nt2/include/functions/all.hpp>'],
             'no_ulp' : 'True',
             'notes' : [],
             'stamp' : 'modified by jt the 18/02/2011',
            },
         'ranges' : {
             'default' : [
                [['nt2::Valmin<T>()/2', 'nt2::Valmax<T>()/2'], ['nt2::Valmin<T>()/2', 'nt2::Valmax<T>()/2']],
                ],
            },
         'specific_values' : {
             'default' : {
                 'nt2::One<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                 'nt2::One<T>(),nt2::Zero<T>()' : {'result' : 'false','ulp_thresh' : '0',},
                 'nt2::Zero<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                },
             'integer_   ' : {
                 'nt2::One<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                 'nt2::One<T>(),nt2::Zero<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                 'nt2::Zero<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                 'nt2::Mone<T>(),nt2::Zero<T>()' : {'result' : 'false','ulp_thresh' : '0',},
                },
             'real_' : {
                 'nt2::Inf<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                 'nt2::Minf<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                 'nt2::Nan<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                 'nt2::One<T>(),nt2::Zero<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                 'nt2::Zero<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                },
            },
         'verif_test' : {
             'property_call' : {
                 'integer_' : ['nt2::compare_less(a0,a1)'],
                },
             'property_value' : {
                 'integer_' : ['nt2::all(lt(a0,a1))'],
                },
             'simd' : {
                },
             'ulp_thresh' : {
                 'integer_' : ['0'],
                },
            },
        },
    },
]
