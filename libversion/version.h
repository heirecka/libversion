/*
 * Copyright (c) 2017-2018 Dmitry Marakasov <amdmi3@amdmi3.ru>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef LIBVERSION_VERSION_H
#define LIBVERSION_VERSION_H

#include <libversion/config.h>

#define LIBVERSION_VERSION_ATLEAST(x, y, z) \
	( \
		(LIBVERSION_VERSION_MAJOR > (x)) || \
		(LIBVERSION_VERSION_MAJOR == (x) && LIBVERSION_VERSION_MINOR > (y)) || \
		(LIBVERSION_VERSION_MAJOR == (x) && LIBVERSION_VERSION_MINOR == (y) && LIBVERSION_VERSION_PATCH >= (z)) \
	)

#ifdef __cplusplus
extern "C" {
#endif

enum {
	VERSIONFLAG_P_IS_PATCH_LEFT = 0x1, /* deprecated: use version_compare4() and VERSIONFLAG_P_IS_PATCH */
	VERSIONFLAG_P_IS_PATCH_RIGHT = 0x2, /* deprecated: use version_compare4() and VERSIONFLAG_P_IS_PATCH */
	VERSIONFLAG_P_IS_PATCH = VERSIONFLAG_P_IS_PATCH_LEFT|VERSIONFLAG_P_IS_PATCH_RIGHT,

	VERSIONFLAG_ANY_IS_PATCH_LEFT = 0x4, /* deprecated: use version_compare4() and VERSIONFLAG_ANY_IS_PATCH */
	VERSIONFLAG_ANY_IS_PATCH_RIGHT = 0x8, /* deprecated: use version_compare4() and VERSIONFLAG_ANY_IS_PATCH */
	VERSIONFLAG_ANY_IS_PATCH = VERSIONFLAG_ANY_IS_PATCH_LEFT|VERSIONFLAG_ANY_IS_PATCH_RIGHT
};

int version_compare2(const char* v1, const char* v2);
int version_compare4(const char* v1, const char* v2, int v1_flags, int v2_flags);

#ifndef LIBVERSION_NO_DEPRECATED
/* deprecated */
typedef unsigned long version_signature_t;

/* deprecated */
version_signature_t version_signature_simple(const char* v);

/* deprecated, use version_compare2 */
int version_compare_simple(const char* v1, const char* v2);

/* deprecated, use version_compare4 */
int version_compare_flags(const char* v1, const char* v2, int flags); /* deprecated: use version_compare_flags2() */

/* deprecated, use version_compare4 */
int version_compare_flags2(const char* v1, const char* v2, int v1_flags, int v2_flags);

/* deprecated, use version_compare4 */
int version_compare3(const char* v1, const char* v2, int flags);
#endif

#ifdef __cplusplus
}
#endif

#endif /* LIBVERSION_VERSION_H */
