#pragma once

#include "CoreTypes.h"
#include "Misc/ScopedDemo.h"

#define DEMO(desc, func) { \
	ScopedDemo sd(desc); \
	func(); \
	} 
