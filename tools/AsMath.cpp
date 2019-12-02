#include "AsMath.h"

namespace Asemco
{
	void normalize(float & num1, float & num2)
	{
		if (num1 > num2)
		{
			num2 = (1.0f / num1)*num2;
			num1 = 1.0f;
		}
		else
		{
			num1 = (1.0f / num2)*num1;
			num2 = 1.0f;
		}
	}

	float f3min(float f1, float f2, float f3)
	{
		float tmp = (float)fmin(f1, f2);
		return (float)fmin(tmp, f3);
	}

	float f3max(float f1, float f2, float f3)
	{
		float tmp = (float)fmax(f1, f2);
		return (float)fmax(tmp, f3);
	}

	float ufmodf(float fnum, float fmod)
	{
		float r = fmodf(fnum, fmod);
		return r = (r < 0) ? (fmod - r * -1.0f) : r;
	}
}