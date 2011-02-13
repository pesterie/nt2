[{'functor': {'arity': '2',
              'call_types': [],
              'ret_arity': '2',
              'rturn': {'default': 'boost::fusion::tuple<T,typename nt2::meta::as_integer<T,signed>::type>'},
              'type_defs': [],
              'types': ['real_']},
  'unit': {'global_header': {'first_stamp': 'modified by jt the 01/12/2010',
                             'included': ['#include <boost/fusion/tuple.hpp>',
                                          '#include <nt2/include/functions/rem.hpp>',
                                          '#include <nt2/include/functions/idivfix.hpp>'],
                             'notes': [],
                             'stamp': 'modified by jt the 13/12/2010'},
           'ranges': {'real_': [['T(-10)', 'T(10)'], ['T(-10)', 'T(10)']],
                      'signed_int_': [['-100', '100'], ['-100', '100']],
                      'unsigned_int_': [['0', '100'], ['0', '100']]},
           'specific_values': None,
           'verif_test': {'property_call': None,
                          'property_value': {'default': [['nt2::rem(a0,a1)',
                                                         'nt2::idivfix(a0,a1)']]},
                          'ulp_thresh': {'default': ['0', '0']}}},
  'version': '0.1'}]