#pragma once

#include "CoreAPI.h"

// The XNA Math Library is deprecated and no longer available.
// Use DirectXMath instead.
// To enable XMMAtrix(size_t, size_t), define _XM_NO_INTRINSICS_.
// https://stackoverflow.com/questions/17475929/access-floats-of-xmmatrix-operator-not-working
#define _XM_NO_INTRINSICS_
#include <DirectXMath.h>

using namespace DirectX;

class MatrixAlgebra
{
public:
	NON_INSTANTIABLE(MatrixAlgebra);

	static void xmmatrix();
};
