#include "Tools.h"

namespace Tools
{
	uint32_t nlz(uint32_t x)
	{
		uint32_t z = 0;

		if (x == 0) return(32);
		if (x <= 0x0000FFFF) { z = z + 16; x = x << 16; }
		if (x <= 0x00FFFFFF) { z = z + 8; x = x << 8; }
		if (x <= 0x0FFFFFFF) { z = z + 4; x = x << 4; }
		if (x <= 0x3FFFFFFF) { z = z + 2; x = x << 2; }
		if (x <= 0x7FFFFFFF) { z = z + 1; }
		return z;
	}

	uint32_t maxu(uint32_t A, uint32_t B)
	{
		return A > B ? A : B;
	}

	uint32_t minu(uint32_t A, uint32_t B)
	{
		return A < B ? A : B;
	}

	uint32_t mul(uint32_t A, uint32_t B)
	{
		uint64_t t0, t1, t2;

		t0 = A, t1 = B;
		t2 = (A * B) >> 32;
		return t2;
	}

}