#include "Tools.h"

namespace Tools
{
	uint32_t nlz(uint32_t x)
	{
		uint32_t Z = 0;

		if (x == 0) return(32);
		if (x <= 0x0000FFFF) { Z = Z + 16; x = x << 16; }
		if (x <= 0x00FFFFFF) { Z = Z + 8; x = x << 8; }
		if (x <= 0x0FFFFFFF) { Z = Z + 4; x = x << 4; }
		if (x <= 0x3FFFFFFF) { Z = Z + 2; x = x << 2; }
		if (x <= 0x7FFFFFFF) { Z = Z + 1; }
		return Z;
	}
}