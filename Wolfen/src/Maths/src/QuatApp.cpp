//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Gam575
//----------------------------------------------------------------------------- 
#include "wfpch.h"

#include "Maths/include/MathEngine.h"
#include "Maths/include/MathApp.h"
#include <math.h>

//----------------------------------------------------------------------------- 
// Mutates result to be a slerp between the source and target by the
// specified factor.
// For a factor of 0.0, result == source.
// For a factor of 1.0, result == target.
//----------------------------------------------------------------------------- 

void QuatApp::Slerp(Quat &result, const Quat &src, const Quat &tar, const float slerpFactor)
{
	// Do your magic here
	MATH_UNUSED(result);
	MATH_UNUSED(src);
	MATH_UNUSED(tar);
	MATH_UNUSED(slerpFactor);

	if (slerpFactor == 0.0f) {
		result = src;
	}
	else if (slerpFactor == 1.0f) {
		result = tar;
	}

	else {
		float tmp = src.dot(tar);
		float theta;

		if (cosf(tmp) < 0.0f) {
			tmp = -cosf(tmp);
		}
		theta = acosf(tmp);

		result = src * ((sinf(1.0f - slerpFactor)*theta) / sinf(theta)) + tar * (sinf(slerpFactor*theta) / sinf(theta));
	}

};

void QuatApp::SlerpArray(Quat *out, const Quat *source, const Quat *target, const float slerpFactor, const int numQuats)
{
	out[numQuats];

	for (int i = 0; i < numQuats; i++) {
		Slerp(out[i], source[i], target[i], slerpFactor);
	}


};

// ---  End of File ---------------
