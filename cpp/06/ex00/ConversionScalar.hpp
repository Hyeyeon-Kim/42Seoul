#ifndef CONVERSIONSCALAR_HPP
#define CONVERSIONSCALAR_HPP

#include <iostream>
#include <math.h>
#include <exception>

class ConversionScalar
{
private:
	double value;
	bool ischar_;
	bool isinf_;
	bool isnan_;
	bool isprint_;
public:
	ConversionScalar();
	ConversionScalar(std::string scalar);
	~ConversionScalar();
	ConversionScalar(const ConversionScalar& copy);
	ConversionScalar& operator=(const ConversionScalar& asign);

	void toDouble() const;
	void toChar() const;
	void toInt() const;
	void toFloat() const;

	class ExceptCase : public std::exception
	{
        private:
            std::string msg;
        public:
            ExceptCase(std::string msg_);
            ~ExceptCase() throw(); // 멤버변수를 만들면서 소멸자도 오버라이딩을 사용
            const char* what() const throw();
	};
};


#endif 
