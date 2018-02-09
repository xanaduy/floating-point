#include "Float.h"
#include <cmath>

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

Float& Float::operator +(const Float& rhs)
{
	int32_t re = rhs.Exponent();

	if (this->Exponent() == re)
	{
		uint32_t rm = rhs.Mantissa();
		uint32_t tm = this->Mantissa();

		uint64_t m = rm + tm;

		uint32_t h = 1 << kSignficandSize;
		uint32_t g = m % h;
		uint32_t c = m / h;

		d.b.m = g;
		d.b.e += c;
	}
	else if (this->Exponent() > re)
	{
		
	}
	
	return *this;
}

std::string Float::ToString() const
{
	return std::string();
}

float Float::Value() const
{
	return d.f;
}

uint32_t Float::UInt32Value() const
{
	return d.u;
}

//  Link: http://yoda.arachsys.com/csharp/DoubleConverter.cs
const std::string Float::ToExactString() const
{
	if (IsInf())
		return Sign() ? "+Inf" : "-Inf";
	
	if (IsNan())
		return "Nan";

	uint32_t bits = UInt32Value();

	// subnormal numbers
	bool negative = (d.b.s == 1);
	int exponent = (int)(bits >> 23 & 0xFF);
	int mantissa = bits & 0x7FFFFF;

	if (exponent == 0) exponent++;   // subnormal
	else mantissa |= (1 << 23);      // normal
	
	exponent -= (127 + 23);

	if (mantissa == 0)
		return "0";  //  ? "+0", "-0"

	while ((mantissa & 1) == 0)
	{
		mantissa >>= 1;
		exponent++;
	}

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

uint32_t Float::Mantissa() const
{
	return d.u & kSignificandMask;
}

void Float::Print() const
{

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

void Float::Add(uint32_t x)
{
}

void Float::Sub(uint32_t x)
{

}

void Float::Mul(uint32_t x)
{

}

void Float::Div(uint32_t x)
{

}

void Float::SetRoundMode(RoundMode mode)
{

}

