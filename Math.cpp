#include "Math.h"

int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	return x + y;
}

int Math::Add(double x, double y, double z)
{
	return x + y + z;
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	return x * y;
}

int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}

int Math::Add(int count, ...)
{
	
	int suma = 0;
	va_list argumente;
	va_start(argumente, count);
	for (int i = 0; i < count; i++)
	{
		suma = suma + va_arg(argumente, int);
	}

	va_end(argumente); 
	return suma;
}

char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
		return nullptr;
	
	int x = atoi(a);
	int y = atoi(b);

	int suma = x + y;

	char *r = new char(strlen(a) + strlen(b) + 1);
	_itoa_s (suma, r, sizeof(r), 10);

	return r;
}