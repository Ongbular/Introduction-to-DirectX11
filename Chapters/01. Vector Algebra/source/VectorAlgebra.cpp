#include "VectorAlgebra.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, FXMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
	return os;
}

void VectorAlgebra::InitFunctions()
{
	XMVECTOR p = XMVectorZero();
	XMVECTOR q = XMVectorSplatOne();
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorReplicate(-2.0f);
	XMVECTOR w = XMVectorSplatZ(u);

	std::cout << "p = " << p << std::endl;
	std::cout << "q = " << q << std::endl;
	std::cout << "u = " << u << std::endl;
	std::cout << "v = " << v << std::endl;
	std::cout << "w = " << w << std::endl;
}

void VectorAlgebra::ShowVectorFunctions()
{
	XMVECTOR n = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f, 0.0f);
	XMVECTOR w = XMVectorSet(0.707f, 0.707f, 0.0f, 0.0f);

	// Vector addition: XMVECTOR operator + 
	XMVECTOR a = u + v;

	// Vector subtraction: XMVECTOR operator - 
	XMVECTOR b = u - v;

	// Scalar multiplication: XMVECTOR operator * 
	XMVECTOR c = 10.0f * u;

	// ||u||
	XMVECTOR L = XMVector3Length(u);

	// d = u / ||u||
	XMVECTOR d = XMVector3Normalize(u);

	// s = u dot v
	XMVECTOR s = XMVector3Dot(u, v);

	// e = u x v
	XMVECTOR e = XMVector3Cross(u, v);

	// Find proj_n(w) and perp_n(w)
	XMVECTOR projW;
	XMVECTOR perpW;
	XMVector3ComponentsFromNormal(&projW, &perpW, w, n);

	// Does projW + perpW == w?
	bool equal = XMVector3Equal(projW + perpW, w) != 0;
	bool notEqual = XMVector3NotEqual(projW + perpW, w) != 0;

	// The angle between projW and perpW should be 90 degrees.
	XMVECTOR angleVec = XMVector3AngleBetweenVectors(projW, perpW);
	float angleRadians = XMVectorGetX(angleVec);
	float angleDegrees = XMConvertToDegrees(angleRadians);

	std::cout << "u                   = " << u << std::endl;
	std::cout << "v                   = " << v << std::endl;
	std::cout << "w                   = " << w << std::endl;
	std::cout << "n                   = " << n << std::endl;
	std::cout << "a = u + v           = " << a << std::endl;
	std::cout << "b = u - v           = " << b << std::endl;
	std::cout << "c = 10 * u          = " << c << std::endl;
	std::cout << "d = u / ||u||       = " << d << std::endl;
	std::cout << "e = u x v           = " << e << std::endl;
	std::cout << "L  = ||u||          = " << L << std::endl;
	std::cout << "s = u.v             = " << s << std::endl;
	std::cout << "projW               = " << projW << std::endl;
	std::cout << "perpW               = " << perpW << std::endl;
	std::cout << "projW + perpW == w  = " << equal << std::endl;
	std::cout << "projW + perpW != w  = " << notEqual << std::endl;
	std::cout << "angle               = " << angleDegrees << std::endl;
}

void VectorAlgebra::tol()
{
	XMVECTOR u = XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
	XMVECTOR n = XMVector3Normalize(u);

	float LU = XMVectorGetX(XMVector3Length(n));

	// Mathematically, the length should be 1.  Is it numerically?
	std::cout << LU << std::endl;
	if (LU == 1.0f)
	{
		std::cout << "Length 1" << std::endl;
	}
	else
	{
		std::cout << "Length not 1" << std::endl;
	}

	// Raising 1 to any power should still be 1.  Is it?
	float powLU = powf(LU, 1.0e6f);
	std::cout << "LU^(10^6) = " << powLU << std::endl;
}

void VectorAlgebra::ShowVectorOperations()
{
	XMVECTOR p = XMVectorSet(2.0f, 2.0f, 1.0f, 0.0f);
	XMVECTOR q = XMVectorSet(2.0f, -0.5f, 0.5f, 0.1f);
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 4.0f, 8.0f);
	XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f, 2.5f);
	XMVECTOR w = XMVectorSet(0.0f, XM_PIDIV4, XM_PIDIV2, XM_PI);

	std::cout << "XMVectorAbs(v)                 = " << XMVectorAbs(v) << std::endl;
	std::cout << "XMVectorCos(w)                 = " << XMVectorCos(w) << std::endl;
	std::cout << "XMVectorLog(u)                 = " << XMVectorLog(u) << std::endl;
	std::cout << "XMVectorExp(p)                 = " << XMVectorExp(p) << std::endl;

	std::cout << "XMVectorPow(u, p)              = " << XMVectorPow(u, p) << std::endl;
	std::cout << "XMVectorSqrt(u)                = " << XMVectorSqrt(u) << std::endl;

	std::cout << "XMVectorSwizzle(u, 2, 2, 1, 3) = "
		<< XMVectorSwizzle(u, 2, 2, 1, 3) << std::endl;
	std::cout << "XMVectorSwizzle(u, 2, 1, 0, 3) = "
		<< XMVectorSwizzle(u, 2, 1, 0, 3) << std::endl;

	std::cout << "XMVectorMultiply(u, v)         = " << XMVectorMultiply(u, v) << std::endl;
	std::cout << "XMVectorSaturate(q)            = " << XMVectorSaturate(q) << std::endl;
	std::cout << "XMVectorMin(p, v               = " << XMVectorMin(p, v) << std::endl;
	std::cout << "XMVectorMax(p, v)              = " << XMVectorMax(p, v) << std::endl;
}
