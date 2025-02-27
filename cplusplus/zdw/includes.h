/**
 * Copyright 2019 Adobe. All rights reserved.
 * This file is licensed to you under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain a copy
 * of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under
 * the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS
 * OF ANY KIND, either express or implied. See the License for the specific language
 * governing permissions and limitations under the License.
 */

//Contains common includes for ZDW compressor data structures.

#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>

// Constant to include in printf() calls with ULONGLONG
// WARNING - PORTABILITY: From C99 standard (not part of C++98)
// FIXME: Shift to <cinttypes> once on C++11
#include <inttypes.h>
#ifdef PRIu64
#define PF_LLU PRIu64
#else
#if (_LP64 || __LP64__) // i.e., sizeof(uint64_t) == sizeof(unsigned long)
#define PF_LLU "lu"
#else
#define PF_LLU "llu"
#endif
#endif

// WARNING - PORTABILITY: FROM C99 standard (not part of C++98)
// FIXME: Shift to <cstdint> once on C++11
#include <stdint.h>

#define DECIMAL_FACTOR_VERSION_1 (1000000000) //version 1
#define DECIMAL_FACTOR (1000000000000.0)      //version 2-3


namespace adobe {
namespace zdw {

typedef int64_t SLONGLONG;
typedef uint64_t ULONGLONG;

typedef uint8_t UCHAR;
typedef uint16_t USHORT;
typedef uint32_t ULONG;


namespace internal {

union indexBytes
{
	char c[4];
	ULONG n;
};

union storageBytes
{
	char c[8];
	ULONGLONG n;
};

} // namespace internal
} // namespace zdw
} // namespace adobe

#endif //INCLUDES_H
