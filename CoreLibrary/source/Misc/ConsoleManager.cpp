#include "CoreLibraryPCH.h"
#include "Misc/ConsoleManager.h"

void ConsoleManager::SetConsoleTextColor(const EConsoleTextColor color)
{
	initConsoleHandle();

	SetConsoleTextAttribute(mHConsole, convertColorValue(color));
}

void ConsoleManager::initConsoleHandle()
{
	if (mHConsole != nullptr)
	{
		return;
	}

	mHConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	assert(mHConsole != nullptr);

	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(mHConsole, &info);

	mDefaultTextColor = info.wAttributes | convertColorValue(EConsoleTextColor::White);
}

WORD ConsoleManager::convertColorValue(const EConsoleTextColor color)
{
	WORD ret{ 0 };

	switch (color)
	{
	case EConsoleTextColor::Default:
		ret = mDefaultTextColor;
		break;
	case EConsoleTextColor::White:
		ret = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
		break;
	case EConsoleTextColor::Red:
		ret = FOREGROUND_RED;
		break;
	case EConsoleTextColor::Green:
		ret = FOREGROUND_GREEN;
		break;
	case EConsoleTextColor::Blue:
		ret = FOREGROUND_BLUE;
		break;
	case EConsoleTextColor::Yellow:
		ret = FOREGROUND_GREEN | FOREGROUND_RED;
		break;
	default:
		assert(false);
	}

	return ret;
}
