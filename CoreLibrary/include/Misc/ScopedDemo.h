#pragma once

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
