#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <functional>

namespace ft
{

template <class ForwardIterator, class T>
void
fill(ForwardIterator first, ForwardIterator last, const T& val)
{
	while (first != last)
	{
		*first = val;
		++first;
	}
}

template <class InputIterator1, class InputIterator2>
bool
equal( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return false;
		++first1;
		++first2;
	}
	return true;
}

template<class InputIterator1, class InputIterator2, class BinaryPredicate>
bool
equal( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred )
{
	while (first1 != last1)
	{
		if (!pred(*first1, *first2))
			return false;
		++first1;
		++first2;
	}
	return true;
}

template <class InputIterator1, class InputIterator2>
bool
lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
						InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1) return false;
		else if (*first1 < *first2) return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}

template<class InputIterator, class OutputIterator>
OutputIterator
copy(InputIterator first, InputIterator last, OutputIterator result)
{
	while (first != last)
	{
		*result = *first;
		++result;
		++first;
	}
	return result;
}
template <class T>
void
swap ( T& a, T& b )
{
    T c(a); a=b; b=c;
}
}

#endif
