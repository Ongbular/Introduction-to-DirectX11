#include "CoreLibraryPCH.h"
#include "Misc/ScopedDemo.h"

#include <iostream>

#include "Misc/ConsoleManager.h"

ScopedDemo::ScopedDemo(const char* demoDescription)
	: mDescription(demoDescription)
{
	std::cout << "///////////////////////////////////////////////\n";
	std::cout << "// ";

	ConsoleManager::SetConsoleTextColor(EConsoleTextColor::Yellow);
	std::cout << mDescription;
	ConsoleManager::SetConsoleTextColor(EConsoleTextColor::Default);

	std::cout << "\n///////////////////////////////////////////////\n\n";
}

ScopedDemo::~ScopedDemo()
{
	ConsoleManager::SetConsoleTextColor(EConsoleTextColor::Yellow);
	std::cout << "\n" << mDescription << " end...\n\n";
	ConsoleManager::SetConsoleTextColor(EConsoleTextColor::Default);
}
