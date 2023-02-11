#pragma once

// The XNA Math Library is deprecated and no longer available.
// Use DirectXMath instead.

#include <DirectXMath.h>
#include "CoreAPI.h"

using namespace DirectX;

/*
 * A static class that collects functionality from legacy code.
 */
class VectorAlgebra
{
public:
	NON_INSTANTIABLE(VectorAlgebra);
	
	static void InitFunctions();
	
	static void ShowVectorFunctions();	
	
	static void tol();
	
	static void ShowVectorOperations();
};

std::ostream& operator<<(std::ostream& os, FXMVECTOR v);
