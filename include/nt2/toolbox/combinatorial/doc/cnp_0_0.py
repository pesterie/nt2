{ 'arity': 2,
  'dptch': ['fundamental_'],
  'incld': [],
  'norst': False,
  'notes': [],
  'rnges': { 'real_': [['T(0)', 'T(10)'], ['T(0)', 'T(10)']],
             'signed_int_': [['00', '100'], ['00', '100']],
             'unsigned_int_': [['0', '100'], ['0', '100']]},
  'rturn': { 'default': 'T'}, 
  'specv': { 'default': { },
             'real_': { 'nt2::Inf<T>()': 'nt2::Nan<T>()',
                        'nt2::Nan<T>()': 'nt2::Nan<T>()',
                        'nt2::One<T>()': 'nt2::One<T>()',
                        'nt2::Zero<T>()': 'nt2::One<T>()',
                        '2,1': '2',
                        '10,1':'10',
                        '2,2':'1',
                        '10,2':'45',
                        '10,8':'45',
                        },
             'signed_int_': { 
                              'nt2::One<T>()': 'nt2::One<T>()',
                              'nt2::Zero<T>()': 'nt2::One<T>()'},
             'unsigned_int_': { 'nt2::One<T>()': 'nt2::One<T>()',
                                'nt2::Zero<T>()': 'nt2::One<T>()'}},
  'stamp': 'modified by jt the 30/11/2010',
  'tcall': None,
  'types': ['real_', 'unsigned_int_', 'signed_int_'],
  'versn': "0.0"
  }