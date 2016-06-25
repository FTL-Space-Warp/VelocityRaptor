/*
* Copyright (c) 2006-2009 Cormac Grindall (Mithreindeir)
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef HEADER_VRPARTICLESYS
#define HEADER_VRPARTICLESYS

#include "vrParticle.h"
#include "vrArray.h"
#include "vrHashMap.h"

static const vrFloat upper_bound = 5.8;
static const vrFloat lower_bound = 0.2;

typedef struct vrParticleSystem
{
	vrArray* particles;

	vrFloat resting_d;
	vrFloat k_stiffN;
	vrFloat k_stiff;
	vrFloat viscosity;
	vrFloat k_spring;
	vrFloat restLen;
	vrVec2 gravity;

} vrParticleSystem;

vrParticleSystem* vrParticleSystemAlloc();
vrParticleSystem* vrParticleSystemInit(vrParticleSystem* psys);
void vrParticleSystemStep(vrParticleSystem* system, vrFloat dt);
void vrParticleSystemBoundaries(vrParticleSystem* system);
//Smoothing functions
vrFloat W(vrFloat x, vrFloat h);
vrVec2 GradW(vrVec2 d, vrFloat h);
vrFloat LaplacianW(vrFloat x, vrFloat h);

#endif