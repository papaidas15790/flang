
/*
 * Copyright (c) 2017, NVIDIA CORPORATION.  All rights reserved.
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

#define LOG_C1       -0.5
#define LOG_C2        0.333332955837249755859375
#define LOG_C3       -0.2500000298023223876953125
#define LOG_C4        0.20003028213977813720703125
#define LOG_C5       -0.1666888296604156494140625
#define LOG_C6        0.1420460045337677001953125
#define LOG_C7       -0.12383414804935455322265625
#define LOG_C8        0.11964692175388336181640625
#define LOG_C9       -0.11824800074100494384765625
#define LOG_CA        6.7655406892299652099609375e-2

#define CANONICAL_NAN   0x7FC00000
#define MINUS_INF       0xFF800000
#define NAN_INF_MASK    0x7F800000
    
#define PARTITION_CONST   0.707106781186547524f
#define TWO_TO_M126_F     0x1p-126f
#define TWO_TO_24_F       16777216.0f
#define U24               24
#define BIT_MASK2         0x807FFFFF
#define OFFSET            0x3f000000
#define EXP_OFFSET        126
