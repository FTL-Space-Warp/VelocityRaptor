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

#include "../include/vrMath.h"

extern inline vrMat2 vrMat(const vrVec2 m, const vrVec2 n);
extern inline vrVec2 vrVect(vrFloat x, vrFloat y);
extern inline vrVec2 vrScale(const vrVec2 a, const vrFloat scale);
extern inline vrMat2 vrMat2Scale(const vrMat2 a, const vrFloat b);
extern inline vrVec2 vrMat2Mult( const vrMat2 a, const vrVec2 b);
extern inline vrMat2 vrMat2Transpose(const vrMat2 a);
extern inline vrVec2 vrAdd(const vrVec2 a, const vrVec2 b);
extern inline vrMat2 vrMat2Add(const vrMat2 a, const vrMat2 b);
extern inline vrMat2 vrMat2Invert(vrMat2 a);
extern inline vrBOOL vrVec2Equals(const vrVec2 a, const vrVec2 b);
extern inline vrVec2 vrSub(const vrVec2 a, const vrVec2 b);
extern inline vrVec2 vrMult(const vrVec2 a, const vrVec2 b);
extern inline vrVec2 vrDiv(const vrVec2 a, const vrVec2 b);
extern inline vrFloat vrDot(const vrVec2 a, const vrVec2 b);
extern inline vrFloat vrCross(const vrVec2 a, const vrVec2 b);
extern inline vrVec2 vrCrossScalar(const vrFloat a, const vrVec2 b);
extern inline vrFloat vrMax(const vrFloat a, const vrFloat b);
extern inline vrFloat vrMin(const vrFloat a, const vrFloat b);
extern inline vrFloat vrDist(const vrVec2 a, const vrVec2 b);
extern inline vrFloat vrDist_Sqr(const vrVec2 a, const vrVec2 b);
extern inline vrFloat vrLength(const vrVec2 a);
extern inline vrFloat vrLengthSqr(const vrVec2 a);

void vrVec2Log(const vrVec2 v)
{
	printf("( %f, %f ) \t\n", v.x, v.y);
}

extern inline vrVec2 vrNormalize(const vrVec2 a);
extern inline vrFloat vrClamp(vrFloat a, vrFloat low, vrFloat high);
