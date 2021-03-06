#ifndef FLOAT_H
#define FLOAT_H

#include <string>
#include <cstdint>  // uint32_t

/*
	floating-point add��http://sandbox.mc.edu/~bennet/cs110/textbook/module4_3.html

*/

class Float
{
public:
	enum RoundMode
	{
		NEARSET,
	};

	union Data
	{
		float f;
		uint32_t u;
		struct Bits
		{
			uint32_t m : 23;
			uint32_t e : 8;
			uint32_t s : 1;
		}b;
	};

public:
	Float() {}
	Float(float f);
	Float(const std::string& s);
	Float(const char* s);

	Float& operator +(const Float& rhs);
	Float& operator -(const Float& rhs);

	float NextPositiveFloat() const;

	std::string ToString() const;
	const std::string ToExactString() const;

	bool Valid() const;

	float Value() const;
	uint32_t UInt32Value() const;
	bool Sign() const;
	int32_t Exponent() const;
	uint32_t Significand() const;
	uint32_t Mantissa() const;

	// precise print the internal value 
	void Print() const;

	bool IsNan() const;
	bool IsInf() const;
	bool IsNormal() const;
	bool IsQuietNan() const;

	bool IsSubNormal() const;
private:
	static const int32_t kSignficandSize = 23;
	static const int32_t kExponentBias = 0x7F;
	static const int32_t kDenormalExponent = 1 - kExponentBias;
	static const uint32_t kSignMask = 0x80000000;
	static const uint32_t kExponentMask = 0x7F800000;
	static const uint32_t kSignificandMask = 0x007FFFFF;

	// detect underflow, upperflow, nan
	// warning, throw exception ?
	void Add(uint32_t x);
	void Sub(uint32_t x);
	void Mul(uint32_t x);
	void Div(uint32_t x);

	void Round(uint32_t x);

	void SetRoundMode(RoundMode mode);
	RoundMode GetRoundMode() const;
	RoundMode DefaultRoundMode() const;

	RoundMode rm = RoundMode::NEARSET;
	Data d;
};

#endif // FLOAT_H