#include "B.hpp"

B::B()
{
}

B::B(const B	&other)
{
	*this = other;
}

B::~B()
{
}

const B	&B::operator=(const B	&other)
{
	(void)other;
	return(*this);
}