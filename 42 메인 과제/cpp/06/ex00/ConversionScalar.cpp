#include "ConversionScalar.hpp"

ConversionScalar::ConversionScalar(): value(0), ischar_(false), isinf_(false), isnan_(false), isprint_(false)
{

}
ConversionScalar::ConversionScalar(std::string scalar) : value(0), ischar_(false), isinf_(false), isnan_(false), isprint_(false)
{
	if (scalar.length() == 1 && isdigit(scalar[0]) == 0)
	{
		value = scalar[0];
		ischar_ = true;
	}
	else
	{
		value = atof(scalar.c_str());
	}
	isnan_ = isnan(value);
	isinf_ = isinf(value);
	isprint_ = isprint(value);
}

ConversionScalar::~ConversionScalar()
{
    
}

ConversionScalar::ConversionScalar(const ConversionScalar& copy) : value(copy.value), ischar_(copy.ischar_), isinf_(copy.isinf_), isnan_(copy.isnan_), isprint_(copy.isprint_)
{}

ConversionScalar& ConversionScalar::operator=(const ConversionScalar& asign)
{
    if (this == &asign)
		return(*this);
	this->value = asign.value;
	this->ischar_ = asign.ischar_;
	this->isinf_ = asign.isinf_;
	this->isnan_ = asign.isnan_;
	this->isprint_ = asign.isprint_;
	return (*this);
}

void ConversionScalar::toDouble() const
{
    double ret = static_cast<double>(value);
	int jeongsu = static_cast<int>(value);
	try
	{
		std::cout << "double: ";
		if (isinf_ && value < 0)
			throw ExceptCase("-inf");
		else if (isinf_ && value > 0)
			throw ExceptCase("+inf");
		else if (isnan_)
			throw ExceptCase("nan");
		std::cout << ret;
		if (ischar_ || ret - jeongsu == 0.0 ) // 변환 후 소수점 부분이 없을 때
			std::cout << ".0";
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void ConversionScalar::toChar() const
{
    double value;
	char ret;
	value = this->value;
	ret = static_cast<char>(value);
	try
	{
		std::cout << "char: ";
		if (isnan_ || isinf_ || value < 0 || value > 127) //아스키 범위 이상
			throw ExceptCase("impossible");
		else if (isprint_ == false)
			throw ExceptCase("Non displayable");
		else
			std::cout << "'" << ret << "'\n";
		
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void ConversionScalar::toInt() const
{
    double value;
	int ret;
	value = this->value;
	ret = static_cast<int>(value);
	try
	{
		std::cout << "int: ";
		if (isnan_ || isinf_ || value < -2147483648 || value > 2147483637)
			throw ExceptCase("impossible");
		else
			std::cout << ret << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void ConversionScalar::toFloat() const
{
    double value_;
	float ret;
	int jeongsu;

	value_ = value;
	jeongsu = static_cast<int>(value_);
	ret = static_cast<float>(value_);
	try
	{
		std::cout << "float: ";
		if (isnan_)
			throw ExceptCase("nanf");
		else if (isinf_ && value_ < 0)
			throw ExceptCase("-inff");
		else if (isinf_ && value_ > 0)
			throw ExceptCase("+inff");
		else
			std::cout << ret;
		if (ischar_ || ret - jeongsu == 0.0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}


ConversionScalar::ExceptCase::ExceptCase(std::string msg_)
{
    msg = msg_;
}

ConversionScalar::ExceptCase::~ExceptCase() throw()
{}

const char* ConversionScalar::ExceptCase::what() const throw()
{
    return msg.c_str(); //char *로 변형
}
