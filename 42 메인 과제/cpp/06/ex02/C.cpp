#include "C.hpp"

C::C()
{
}

C::C(const C	&other)
{
	*this = other;
}

C::~C()
{
}

const C	&C::operator=(const C	&other)
{
	(void)other;
	return(*this);
}