[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '1',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'T',
            },
         'simd_types' : ['real_'],
         'type_defs' : [],
         'types' : ['real_', 'unsigned_int_', 'signed_int_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'modified by jt the 04/12/2010',
             'included' : ['#include <nt2/include/functions/next.hpp>',
                           '#include <nt2/include/constants/eps_related.hpp>'],
             'no_ulp' : 'True',
             'notes' : [],
             'stamp' : 'modified by jt the 12/12/2010',
            },
         'ranges' : {
             'real_' : [['T(-10)', 'T(10)']],
             'signed_int_' : [['-100', '100']],
             'unsigned_int_' : [['0', '100']],
            },
         'specific_values' : {
             'default' : {
                },
             'real_' : {
                 'nt2::Inf<T>()' : 'nt2::Inf<r_t>()',
                 'nt2::Minf<T>()' : 'nt2::Valmin<r_t>()',
                 'nt2::Mone<T>()' : 'nt2::Mone<r_t>()+nt2::Eps<r_t>()/2',
                 'nt2::Nan<T>()' : 'nt2::Nan<r_t>()',
                 'nt2::One<T>()' : 'nt2::One<r_t>()+nt2::Eps<r_t>()',
                 'nt2::Zero<T>()' : 'nt2::Mindenormal<T>()',
                 'nt2::Valmax<T>()' : 'nt2::Inf<r_t>()',
                },
             'signed_int_' : {
                 'nt2::Valmax<T>()' : 'nt2::Valmax<r_t>()',
                 'nt2::Mone<T>()' : 'nt2::Zero<r_t>()',
                 'nt2::One<T>()' : 'nt2::Two<r_t>()',
                 'nt2::Zero<T>()' : 'nt2::One<r_t>()',
                },
             'unsigned_int_' : {
                 'nt2::Valmax<T>()' : 'nt2::Valmax<r_t>()',
                 'nt2::One<T>()' : 'nt2::Two<r_t>()',
                 'nt2::Zero<T>()' : 'nt2::One<r_t>()',
                },
            },
         'verif_test' : {
             'property_call' :  {
                 'default' : ['nt2::successor(a0)'],
                    },
             'property_value' : {
                 'default' : ['nt2::next(a0)'],
                },
             'ulp_thresh' : '0',
            },
        },
     'version' : '0.1',
    },
    {
     'functor' : {
         'arity' : '2',
         'call_types' : ['T', 'iT'],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'T',
            },
         'simd_types' : ['real_'],
         'type_defs' : ['typedef typename nt2::meta::as_integer<T>::type iT;'],
         'types' : ['real_', 'unsigned_int_', 'signed_int_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'modified by jt the 04/12/2010',
             'included' : ['#include <nt2/include/functions/next.hpp>',
                           '#include <nt2/include/constants/eps_related.hpp>'],
             'no_ulp' : 'True',
             'notes' : [],
             'stamp' : 'modified by jt the 12/12/2010',
            },
         'ranges' : {
             'real_' : [['T(-10)', 'T(10)'], ['iT(2)', 'iT(2)']],
             'signed_int_' : [['-100', '100'], ['iT(2)', 'iT(2)']],
             'unsigned_int_' : [['0', '100'], ['iT(2)', 'iT(2)']],
            },
         'specific_values' : {},
         'verif_test' : {
             'property_call' :  {
                 'default' : ['nt2::successor(a0,a1)'],
                    },
             'property_value' : {
                 'default' : ['nt2::next(nt2::next(a0))'],
                },
             'ulp_thresh' : '0',
            },
        },
     'version' : '0.1',
    },
]
