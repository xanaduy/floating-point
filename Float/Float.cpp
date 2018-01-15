#include "Float.h"

Float::Float(float f)
{
	d.f = f;
}

Float::Float(const std::string& s)
{
	d.f = std::stof(s);
}

Float::Float(const char *s)
{
	d.f = std::stof(std::string(s));
}

std::string Float::ToString() const
{
	return std::string();
}

bool Float::Sign() const
{
	return (d.u & kSignMask) != 0;
}

int32_t Float::Exponent() const
{
	return static_cast<int32_t>(((d.u & kExponentMask) >> kSignficandSize) - kExponentBias);
}

uint32_t Float::Significand() const
{
	return d.u & kSignificandMask;
}

bool Float::IsNan() const
{
	return true;
}

bool Float::IsInf() const
{
	return true;
}

bool Float::IsNormal() const
{
	return true;
}

