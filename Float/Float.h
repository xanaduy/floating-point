#ifndef FLOAT_H
#define FLOAT_H

#include <string>
#include <cstdint>  // uint32_t

class Float
{
public:
	Float() {}
	Float(float f);
	Float(const std::string& s);
	Float(const char* s);

	std::string ToString() const;
	bool Valid() const;

	bool Sign() const;
	int32_t Exponent() const;
	uint32_t Significand() const;

	bool IsNan() const;
	bool IsInf() const;
	bool IsNormal() const;
	bool IsQuietNan() const;
private:
	static const int32_t kSignficandSize = 23;
	static const int32_t kExponentBias = 0x7F;
	static const int32_t kDenormalExponent = 1 - kExponentBias;
	static const uint32_t kSignMask = 0x80000000;
	static const uint32_t kExponentMask = 0x7F800000;
	static const uint32_t kSignificandMask = 0x007FFFFF;

	union Data
	{
		float f;
		uint32_t u;
	};

	Data d;
};

#endif // FLOAT_H