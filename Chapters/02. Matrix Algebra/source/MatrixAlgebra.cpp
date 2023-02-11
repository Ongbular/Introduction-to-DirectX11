#include "MatrixAlgebra.h"
#include <ostream>
#include <iostream>

std::ostream& operator<<(std::ostream& os, FXMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ", " << dest.w << ")";
	return os;
}

std::ostream& operator<<(std::ostream& os, CXMMATRIX m)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			os << m(i, j) << "\t";
		os << std::endl;
	}
	return os;
}

void MatrixAlgebra::xmmatrix()
{
	// Check support for SSE2 (Pentium4, AMD K8, and above).
	if (!XMVerifyCPUSupport())
	{
		std::cout << "DirectXMath not supported" << std::endl;
		return;
	}

	XMMATRIX A(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 2.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 4.0f, 0.0f,
		1.0f, 2.0f, 3.0f, 1.0f);

	XMMATRIX B = XMMatrixIdentity();

	XMMATRIX C = A * B;

	XMMATRIX D = XMMatrixTranspose(A);

	XMVECTOR det = XMMatrixDeterminant(A);
	XMMATRIX E = XMMatrixInverse(&det, A);

	XMMATRIX F = A * E;

	std::cout << "A = " << std::endl << A << std::endl;
	std::cout << "B = " << std::endl << B << std::endl;
	std::cout << "C = A*B = " << std::endl << C << std::endl;
	std::cout << "D = transpose(A) = " << std::endl << D << std::endl;
	std::cout << "det = determinant(A) = " << det << std::endl << std::endl;
	std::cout << "E = inverse(A) = " << std::endl << E << std::endl;
	std::cout << "F = A*E = " << std::endl << F << std::endl;
}
