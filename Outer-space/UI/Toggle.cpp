#include "Toggle.h"

void Toggle::toggleKey(bool key, bool variable)
{
	if (key)//!lastKeyState[0])
	{
		variable = !variable;
	}
	//lastKeyState = key;
}
