/*
* Copyright (c) 2016 Cormac Grindall (Mithreindeir)
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* vrFreely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef HEADER_VRMATH
#define HEADER_VRMATH
#include <math.h>
#include "vr.h"

#define VR_ABS abs
#define VR_SQRT sqrt
#define VR_POW pow
#define VR_POWF powf
#define VR_COSINE cos
#define VR_SINE sin
#define VR_TANGENT tan
#define VR_ARCTANGENT atan
#define VR_ARCCOSINE acos
#define VR_ARCSINE asin
#define VR_ARCTANGENT2 atan2
#define VR_MAX vrMax
#define VR_MIN vrMin
#define VR_PI (vrFloat)(3.14159265358979)

typedef float vrFloat;

#define EPSILON 1.192092896e-07f
#define NUM_PRIMES 26
static unsigned int primes[] =
{
	53,
	97,
	193,
	389,
	769,
	1543,
	3079,
	6151,
	12289,
	24593,
	49157,
	98317,
	196613,
	393241,
	786433,
	1572869,
	3145739,
	6291469,
	12582917,
	25165843,
	50331653,
	100663319,
	201326611,
	402653189,
	805306457,
	1610612741
};

typedef struct vrVec2
{
	vrFloat x;
	vrFloat y;
} vrVec2;

typedef struct vrMat2
{
	vrVec2 m;
	vrVec2 n;
} vrMat2;

inline vrMat2 vrMat(const vrVec2 m, const vrVec2 n)
{
	vrMat2 A;
	A.m = m;
	A.n = n;
	return A;
}
inline vrVec2 vrVect(vrFloat x, vrFloat y)
{
	vrVec2 v = { x, y };
	return v;
}
inline vrVec2 vrScale(const vrVec2 a, const vrFloat scale)
{
	return vrVect(a.x * scale, a.y * scale);
}
inline vrMat2 vrMat2Scale(const vrMat2 a, const vrFloat b)
{
	return vrMat(vrScale(a.m, b), vrScale(a.m, b));
}
inline vrVec2 vrMat2Mult(const vrMat2 a, const vrVec2 b)
{
	return vrVect(a.m.x * b.x + a.m.y * b.y, a.n.x * b.x + a.n.y * b.y);
}
inline vrMat2 vrMat2Transpose(const vrMat2 a)
{
	return vrMat(vrVect(a.m.x, a.n.x), vrVect(a.m.y, a.n.y));
}
inline vrVec2 vrAdd(const vrVec2 a, const vrVec2 b)
{
	return vrVect(a.x + b.x, a.y + b.y);
}
inline vrMat2 vrMat2Add(const vrMat2 a, const vrMat2 b)
{
	return vrMat(vrAdd(a.m, b.m), vrAdd(a.n, b.n));
}
inline vrMat2 vrMat2Invert(vrMat2 m)
{
	vrFloat a, b, c, d;
	a = m.m.x;
	b = m.m.y;
	c = m.n.x;
	d = m.n.y;
	vrFloat determinant = a*d - b*c;
	VR_ASSERT(determinant != 0, "DIVISION BY ZERO MAT2 INVERSE");
	determinant = 1.0 / determinant;
	m.m.x = d*determinant;
	m.m.y = -b*determinant;
	m.n.x = -c*determinant;
	m.n.y = a*determinant;
	return m;
}
inline vrBOOL vrVec2Equals(const vrVec2 a, const vrVec2 b)
{
	return (a.x == b.x && a.y == b.y);
}
inline vrVec2 vrSub(const vrVec2 a, const vrVec2 b)
{
	return vrVect(a.x - b.x, a.y - b.y);
}
inline vrVec2 vrMult(const vrVec2 a, const vrVec2 b)
{
	return vrVect(a.x * b.x, a.y * b.y);
}
inline vrVec2 vrDiv(const vrVec2 a, const vrVec2 b)
{
	vrVec2 v = vrVect(a.x / b.x, a.y / b.y);
	if (b.x == 0) v.x = 0;
	if (b.y == 0) v.y = 0;
	return v;
}
inline vrFloat vrDot(const vrVec2 a, const vrVec2 b)
{
	return a.x * b.x + a.y * b.y;
}
inline vrFloat vrCross(const vrVec2 a, const vrVec2 b)
{
	return a.x*b.y - a.y*b.x;
}
inline vrVec2 vrCrossScalar(const vrFloat a, const vrVec2 b)
{
	return vrVect(-a * b.y, a * b.x);
}
inline vrFloat vrMax(const vrFloat a, const vrFloat b)
{
	return a > b ? a : b;
}
inline vrFloat vrMin(const vrFloat a, const vrFloat b)
{
	return a < b ? a : b;
}
inline vrFloat vrDist(const vrVec2 a, const vrVec2 b)
{
	return VR_SQRT(VR_POW(a.x - b.x, 2) + VR_POW(a.y - b.y, 2));
}
inline vrFloat vrDist_Sqr(const vrVec2 a, const vrVec2 b)
{
	return (VR_POW(a.x - b.x, 2) + VR_POW(a.y - b.y, 2));
}
inline vrFloat vrLength(const vrVec2 a)
{
	return VR_SQRT(a.x*a.x + a.y*a.y);
}
inline vrFloat vrLengthSqr(const vrVec2 a)
{
	return (a.x*a.x + a.y*a.y);
}
void vrVec2Log(const vrVec2 v);

inline vrVec2 vrNormalize(const vrVec2 a)
{
	vrFloat len = vrLength(a);
	len = 1.0 / len;
	return vrVect(a.x * len, a.y * len);
}
inline vrFloat vrClamp(vrFloat a, vrFloat low, vrFloat high)
{
	return VR_MAX(low, VR_MIN(a, high));
}


#endif
