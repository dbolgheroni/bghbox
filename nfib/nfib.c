/*
 * Copyright (c) 2011, Daniel Bolgheroni. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY DANIEL BOLGHERONI ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL DANIEL BOLGHERONI OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <mpfr.h>

#define PREC 1024
#define DISP_PREC 128

int main(void)
{
  int i, n;
  mpfr_t v[3], tmp, r;

  mpfr_init2(v[0], PREC);
  mpfr_init2(v[1], PREC);
  mpfr_init2(v[2], PREC);
  mpfr_init2(tmp, PREC);
  mpfr_init2(r, PREC);

  mpfr_set_d(v[0], 1, GMP_RNDN);
  mpfr_set_d(v[1], 1, GMP_RNDN);
  mpfr_set_d(v[2], 2, GMP_RNDN);

  do {
    printf("Iter. (between 3 and 512): ");
    scanf("%d", &n);
  } while ((n < 3) || (n > 512));

  i = 1;
  mpfr_div(tmp, v[2], v[1], GMP_RNDN);
  printf("n = 001: ");
  mpfr_out_str(stdout, 10, DISP_PREC, tmp, GMP_RNDN);
  printf("\n");

  for (i = 2; i <= n; i++)
  {
    mpfr_set(v[0], v[1], GMP_RNDN);
    mpfr_set(v[1], v[2], GMP_RNDN);
    mpfr_add(v[2], v[0], v[1], GMP_RNDN);

    mpfr_div(r, v[2], v[1], GMP_RNDN);
  
    printf("n = %03d: ", i); 
    mpfr_out_str(stdout, 10, DISP_PREC, r, GMP_RNDN);
    printf("\n");
  }

  mpfr_clear(v[0]);
  mpfr_clear(v[1]);
  mpfr_clear(v[2]);
  mpfr_clear(tmp);
  mpfr_clear(r);

  exit(0);
}
  
