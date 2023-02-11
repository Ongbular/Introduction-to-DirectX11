#include <iostream>
#include "VectorAlgebra.h"

int main()
{
	std::cout << std::boolalpha;

	// Check support for SSE2 (Pentium4, AMD K8, and above).
	if (!XMVerifyCPUSupport())
	{
		std::cout << "DirectXMath not supported" << std::endl;
		return 0;
	}

	DEMO("1.6.7 Setter Functions example", VectorAlgebra::InitFunctions);
	DEMO("1.6.8 Vector Functions example", VectorAlgebra::ShowVectorFunctions);
	DEMO("1.6.9 Floating-Point Error example", VectorAlgebra::tol);
	DEMO("1.8 EXERCISES 19", VectorAlgebra::ShowVectorOperations);

	return 0;
}
