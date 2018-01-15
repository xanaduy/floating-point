#ifndef TOOLS_H
#define TOOLS_H

#include <cstdint>

namespace Tools
{
	// number of leading zeros of an unsigned integer
	uint32_t nlz(uint32_t x);

	uint32_t maxu(uint32_t A, uint32_t B);
	uint32_t minu(uint32_t A, uint32_t B);
	uint32_t mul(uint32_t A, uint32_t B);
}

#endif // TOOLS_H