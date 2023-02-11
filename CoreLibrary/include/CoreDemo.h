#pragma once

#include <iostream>
#include "CoreTypes.h"

class ScopedDemo
{
public:
	NON_COPYABLE(ScopedDemo);
	explicit ScopedDemo(const char* demoDescription);
	~ScopedDemo();

private:
	const char* mDescription;
};

inline ScopedDemo::ScopedDemo(const char* demoDescription)
	: mDescription(demoDescription)
{
	std::cout << "\n///////////////////////////////////////////////\n";
	std::cout << "// " << mDescription << "\n";
	std::cout << "///////////////////////////////////////////////\n\n";
}

inline ScopedDemo::~ScopedDemo()
{
	std::cout << "\n" << mDescription << " end...\n\n";
}

#define DEMO(desc, func) { \
	ScopedDemo sd(desc); \
	func(); \
	} 
