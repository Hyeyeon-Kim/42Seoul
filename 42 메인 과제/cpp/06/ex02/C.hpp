#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base
{
	public:
		C();
		C(const C	&other);
		~C();
		const C	&operator=(const C	&other);
};

#endif