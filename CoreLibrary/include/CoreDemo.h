#pragma once

#include <Windows.h>
#include <iostream>
#include "CoreTypes.h"
#include "Misc/ConsoleManager.h"

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
	std::cout << "///////////////////////////////////////////////\n";
	std::cout << "// ";

	ConsoleManager::SetConsoleTextColor(EConsoleTextColor::Yellow);
	std::cout << mDescription;
	ConsoleManager::SetConsoleTextColor(EConsoleTextColor::Default);
	
	std::cout << "\n///////////////////////////////////////////////\n\n";
}

inline ScopedDemo::~ScopedDemo()
{
	ConsoleManager::SetConsoleTextColor(EConsoleTextColor::Yellow);
	std::cout << "\n" << mDescription << " end...\n";
	ConsoleManager::SetConsoleTextColor(EConsoleTextColor::Default);
}

#define DEMO(desc, func) { \
	ScopedDemo sd(desc); \
	func(); \
	} 
