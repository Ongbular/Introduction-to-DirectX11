#pragma once

#include "CoreTypes.h"

enum class EConsoleTextColor
{
	Default,
	White,
	Red,
	Green,
	Blue,
	Yellow
};

class ConsoleManager
{
public:
	NON_INSTANTIABLE(ConsoleManager);

	static void SetConsoleTextColor(EConsoleTextColor color);

private:
	static void initConsoleHandle();

	static WORD convertColorValue(EConsoleTextColor color);

	inline static HANDLE mHConsole{ nullptr };

	inline static WORD mDefaultTextColor{ 0 };
};

