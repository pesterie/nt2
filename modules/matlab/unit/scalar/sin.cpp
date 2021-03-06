#define NT2_UNIT_MODULE "nt2 matlab toolbox - sin"

#include <nt2/toolbox/matlab/functions/sin.hpp>
#include <nt2/toolbox/trigonometric/constants.hpp>
#include <nt2/include/constants/pi.hpp>
#include <nt2/include/constants/mone.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

NT2_TEST_CASE(sin)
{
    NT2_TEST_LESSER_EQUAL(nt2::ulpdist(nt2::matlab::sin(-nt2::Pi<double>()/2), nt2::Mone<double>()), 0.5);
}
