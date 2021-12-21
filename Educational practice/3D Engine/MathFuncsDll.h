// MathFuncsDll.h
#ifdef MATHFUNCSDLL_EXPORTS
#define MATHFUNCSDLL_API __declspec(dllexport) 
#else
#define MATHFUNCSDLL_API __declspec(dllimport) 
#endif

#include "vec2.h"
#include "vec3.h"

namespace MathFuncs
{
	// This class is exported from the MathFuncsDll.dll
	class MyMathFuncs
	{
	public:
		static MATHFUNCSDLL_API float clamp(float value, float min, float max);
		static MATHFUNCSDLL_API float length(vec2 const& v);
		static MATHFUNCSDLL_API float length(vec3 const& v);
		static MATHFUNCSDLL_API vec3 norm(vec3 v);
		static MATHFUNCSDLL_API float dot(vec3 const& a, vec3 const& b);
		static MATHFUNCSDLL_API vec2 sphere(vec3 ro, vec3 rd, float r);
		static MATHFUNCSDLL_API double sign(double a);
		static MATHFUNCSDLL_API double step(double edge, double x);
		static MATHFUNCSDLL_API	vec3 abs(vec3 const& v);
		static MATHFUNCSDLL_API vec3 sign(vec3 const& v);
		static MATHFUNCSDLL_API vec3 step(vec3 const& edge, vec3 v);
		static MATHFUNCSDLL_API vec3 reflect(vec3 rd, vec3 n);
		static MATHFUNCSDLL_API vec2 box(vec3 ro, vec3 rd, vec3 boxSize, vec3& outNormal);
		static MATHFUNCSDLL_API vec3 rotateX(vec3 a, double angle);
		static MATHFUNCSDLL_API vec3 rotateY(vec3 a, double angle);
		static MATHFUNCSDLL_API vec3 rotateZ(vec3 a, double angle);
		static MATHFUNCSDLL_API float plane(vec3 ro, vec3 rd, vec3 p, float w);
	};
}
