#include <sys/param.h>
#include <sys/sysctl.h>

#include <stdio.h>


int main() {
  int mib[2], ncpu;
  
  size_t len;
  
  mib[0] = CTL_HW;
  mib[1] = HW_NCPU;
  
  len = sizeof(ncpu);
  
  if (sysctl(mib, 2, &ncpu, &len, NULL, 0) == -1)
    err(1, "sysctl");

  printf("ncpu = %d\n", ncpu);
}
