
/*
 * Copyright (c) 2018, NVIDIA CORPORATION.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#if !(defined __NAMES_H_INCLUDED__)
#define __NAMES_H_INCLUDED__ 1

#if (defined __AVX512F__)
    #define sizeof_simd 64
#elif (defined __AVX2__)
    #define sizeof_simd 32
#else //SSE
    #define sizeof_simd 16
#endif

#if !(defined _MEASURE_BASELINE_)
    #define _VECTOR_FUNCTION_
    //#define __USE_PORTABLE_CODE
#else
    #undef _VL
#endif

#if !(defined _VL)
    #if (defined _VECTOR_FUNCTION_)
        //#define _VL (sizeof_simd / sizeof(float _Complex))
        #if (defined __AVX512F__)
            #define _VL 8
        #elif (defined __AVX2__)
            #define _VL 4
        #else //SSE
            #define _VL 2
        #endif
    #else
        #define _VL 1
    #endif
#endif

#if ((_VL) == (1))
    // scalar code
    #define __SLEEF_AVX2_128__
#elif ((_VL) == (2))
    #define __SLEEF_AVX2_128__
#elif ((_VL) == (4))
    #define __SLEEF_AVX2_256__
#elif ((_VL) == (8))
    #define __SLEEF_AVX512__
#endif

#if ( sizeof_simd < (_VL*8) )
#error: SIMD size sizeof_simd is less than vector length _VL * sizeof(float _Complex)
#endif

#if !(defined _CPU)
#error: please define _CPU - specific suffix to a function name
#endif

#if (defined _VECTOR_FUNCTION_)
#if ((_VL) > (1))
#define cexpf_vec        JOIN4(__fc_exp_,_VL,_,_CPU)
#else
#define cexpf_vec        JOIN4(__fc_exp_,2,_,_CPU)
#endif
#endif

#define cexpf_scalar     JOIN4(__fc_exp_,1,_,_CPU)

#if !(defined F_VISIBILITY)
#define F_VISIBILITY extern
//#define F_VISIBILITY static __attribute((noinline))
//#define F_VISIBILITY static __attribute((always_inline)) inline
#endif


#if ((_VL) == (1))
    #define F_VISIBILITY_SCALAR F_VISIBILITY
    #define F_VISIBILITY_VEC static INLINE
#else
    #define F_VISIBILITY_VEC F_VISIBILITY
#endif

#endif //__NAMES_H_INCLUDED__
