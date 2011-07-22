#include <iostream>
#include <nt2/sdk/config/arch.hpp>

int main()
{
  #ifdef NT2_ARCH
  std::cout << "Current architecture      : " << NT2_ARCH           << std::endl;
  std::cout << "Current memory alignement : " << NT2_ARCH_ALIGNMENT << std::endl;
  #endif
}
