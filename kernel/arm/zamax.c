/***************************************************************************
Copyright (c) 2013, The OpenBLAS Project
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in
the documentation and/or other materials provided with the
distribution.
3. Neither the name of the OpenBLAS project nor the names of
its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE OPENBLAS PROJECT OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

/**************************************************************************************
* 2013/09/14 Saar
*	 BLASTEST float		: OK
* 	 BLASTEST double	: OK
* 	 CTEST			: NoTest
* 	 TEST			: NoTest
*
**************************************************************************************/

#include "common.h"
#include <math.h>

#if defined(DOUBLE)

#define ABS fabs

#else

#define ABS fabsf

#endif

#define CABS1(x,i)	ABS(x[i])+ABS(x[i+1])

FLOAT CNAME(BLASLONG n, FLOAT *x, BLASLONG inc_x)
{
	BLASLONG i=0;
	BLASLONG ix=0;
	FLOAT maxf[2];
	BLASLONG max=0;
	BLASLONG inc_x2;

	if (n < 0 || inc_x < 1 ) return(0.0);

	inc_x2 = 2 * inc_x;

	maxf[0] = ABS(x[ix]);
	maxf[1] = ABS(x[ix+1]);

	while(i < n)
	{
		if( CABS1(x,ix) > CABS1(maxf,0) ) 
		{
			max = i;
			maxf[0] = ABS(x[ix]);
			maxf[1] = ABS(x[ix+1]);
		}
		ix += inc_x2;
		i++;
	}
	return(CABS1(maxf,0));
}
	

