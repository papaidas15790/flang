/*
 * Copyright (c) 2017-2019, NVIDIA CORPORATION.  All rights reserved.
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

/******************************************************************************
 *                                                                            *
 * Background:                                                                *
 * The POWERPC ABI does not provide for tail calls. Thus, the math dispatch   *
 * table processing incurs overhead with the saving and restoration of GPR 2  *
 * that can severely affect application performance.  For POWERPC, we use an  *
 * optimized assembly dispatch set of routines that make tail calls to all of *
 * the routines defined in the math dispatch configuration files but do not   *
 * saveand /restore GPR 2.                                                    *
 *                                                                            *
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! WARNING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! *
 *                                                                            *
 * If any entry (routine <FUNC>) in any of the dispatch tables is not present *
 * in i.e. not  satisfied by, libpgmath, in order to properly preserve/restore*
 * GRP 2 when calling routine <FUNC>, the actual function must first be       *
 * encapsulated in a routine present in libpgmath.                            *
 *                                                                            *
 * No doubt there are pathological cases that will show this engineering      *
 * choice to be wrong, but current performance testing shows otherwise.       *
 *                                                                            *
 *****************************************************************************/

MTHINTRIN(sinh , ss   , any        , __mth_i_sinh          , __mth_i_sinh          , __mth_i_sinh          ,__math_dispatch_error)
MTHINTRIN(sinh , ds   , any        , __mth_i_dsinh         , __mth_i_dsinh         , __mth_i_dsinh         ,__math_dispatch_error)
MTHINTRIN(sinh , sv4  , any        , __gs_sinh_4_f         , __gs_sinh_4_r         , __gs_sinh_4_p         ,__math_dispatch_error)
MTHINTRIN(sinh , dv2  , any        , __gd_sinh_2_f         , __gd_sinh_2_r         , __gd_sinh_2_p         ,__math_dispatch_error)
MTHINTRIN(sinh , sv4m , any        , __fs_sinh_4_mn        , __rs_sinh_4_mn        , __ps_sinh_4_mn        ,__math_dispatch_error)
MTHINTRIN(sinh , dv2m , any        , __fd_sinh_2_mn        , __rd_sinh_2_mn        , __pd_sinh_2_mn        ,__math_dispatch_error)
