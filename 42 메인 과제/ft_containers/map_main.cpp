#include <iostream>
#include <string>
#include <deque>
// #if 1
// 	#include <map>
// 	namespace ft = std;
// #else
	#include "map/map.hpp"
	#include "stack/stack.hpp"
	#include "vector/vector.hpp"
//#endif

#include <stdlib.h>

#define T1 int
#define T2 int
typedef ft::map<T1, T2>::value_type T3;
typedef ft::map<T1, T2>::iterator ft_iterator;
typedef ft::map<T1, T2>::const_iterator ft_const_iterator;
#include <list>
#include <unistd.h>
int main()
{

	try
	{
		//pair
		std::pair<int,char> foo (10,'z');
		std::pair<int,char> bar (90,'a');

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

		//map
		ft::map<std::string, int> map1;


		map1.insert(ft::pair<std::string, int>("9", 5));
		map1.insert(ft::pair<std::string, int>("5", 1));
		map1.insert(ft::pair<std::string, int>("3", 25));
		map1.insert(ft::pair<std::string, int>("4", 5));
		map1.insert(ft::pair<std::string, int>("2", 124));
		map1.insert(ft::pair<std::string, int>("6", -25));
		map1.insert(ft::pair<std::string, int>("7", 45));
		map1.insert(ft::pair<std::string, int>("8", 11));
		map1.insert(ft::pair<std::string, int>("1", 35));

		ft::map<std::string, int>::iterator it = map1.begin();
		(void)it;
		while (it != map1.end())
		{
			std::cout << "key: " << (it)->first << std::endl;
			std::cout << "value: " << (it++)->second << std::endl;
		}

		ft::map<std::string, int>::iterator it_bound = map1.lower_bound("5");
		std::cout << "lower_bound: " << std::endl;
		std::cout << it_bound->first << " -> " << it_bound->second << std::endl;
		
		it_bound = map1.upper_bound("5");
		std::cout << "upper_bound: " << std::endl;
		std::cout << it_bound->first << " -> " << it_bound->second << std::endl;

		map1.erase("1");
		map1.erase("4");
		map1.erase("8");
		map1.erase("7");
		map1.erase("2");
		map1.erase("3");
		map1.erase("5");

		std::cout << "count: " << map1.count("8") << std::endl;
		std::cout << "count: " << map1.count("-12") << std::endl;

		ft::map<std::string, int>::iterator f = map1.find("8");
		std::cout << "find: " << f->second << std::endl;

		std::cout << "size: " << map1.size() << std::endl;
		ft::map<std::string, int>::iterator it1 = map1.begin();
		while (it1 != map1.end())
		{
			std::cout << "key: " << (it1++)->first << std::endl;
		}

		std::list<T3> lst;
		unsigned int lst_size = 10;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T3(i + 1, (i + 1) * 3));
		std::list<T3> lst2;
		lst_size = 20;
		for (unsigned int i = 10; i < lst_size; ++i)
			lst2.push_back(T3(i + 1, (i + 1) * 3));

		ft::map<T1, T2> mp(lst.begin(), lst.end());
		std::cout << std::endl;
		ft::map<T1, T2> mp2(lst2.begin(), lst2.end());

		std::cout << std::endl << "mp\n";
		ft::map<int, int>::iterator it3 = mp.begin();
		while (it3 != mp.end())
		{
			std::cout << "key: " << it3->first << std::endl;
			it3++;
		}
		std::cout << std::endl << "mp2\n";
		ft::map<int, int>::iterator it4 = mp2.begin();
		while (it4 != mp2.end())
		{
			std::cout << "key: " << (it4++)->first << std::endl;
		}

		ft::map<T1, T2> mp3(mp2);
		std::cout << std::endl << "mp3\n";
		it4 = mp3.begin();
		while (it4 != mp3.end())
		{
			std::cout << "key: " << (it4++)->first << std::endl;
		}

		mp = mp2;

		std::cout << std::endl << "mp after operator=\n";
		it4 = mp.begin();
		while (it4 != mp.end())
		{
			std::cout << "key: " << (it4++)->first << std::endl;
		}


		ft::map<int, int> test(mp);
		std::cout << std::endl << "copy constr\n";
		it4 = test.begin();
		while (it4 != test.end())
		{
			std::cout << "key: " << (it4++)->first << std::endl;
		}

		ft::map<int, int> mp_2000;
		ft::map<int, int>::iterator mp_2000_it;

		mp_2000[1] = 1;
		mp_2000[2] = 1;
		mp_2000[3] = 1;
		mp_2000[4] = 1;
		mp_2000[5] = 1;
		mp_2000[6] = 1;
		mp_2000[7] = 1;
		mp_2000[8] = 1;
		mp_2000[9] = 1;
		mp_2000[10] = 1;
		
		mp_2000_it = mp_2000.begin();
		std::cout << std::endl << "operator[] \n";
		while (mp_2000_it != mp_2000.end())
		{
			std::cout << "key: " << (mp_2000_it++)->first << std::endl;
		}

		mp_2000.erase(8);
		mp_2000.erase(++(++(++mp_2000.begin())));
		mp_2000.erase(--(--(--mp_2000.end())));
		mp_2000.erase(--(--(--mp_2000.end())), --mp_2000.end());


		mp_2000[10] = 1;
		mp_2000[11] = 2;
		mp_2000.erase(--(--(--mp_2000.end())), --mp_2000.end());

		mp_2000_it = mp_2000.begin();
		std::cout << std::endl << "erase\n";
		while (mp_2000_it != mp_2000.end())
		{
			std::cout << "key: " << (mp_2000_it++)->first << std::endl;
		}

		ft::map<int, int> mp_2001(mp_2000);
		mp_2000_it = mp_2001.begin();
		std::cout << std::endl << "copy constructor\n";
		while (mp_2000_it != mp_2001.end())
		{
			std::cout << "key: " << mp_2000_it->first << std::endl;
			mp_2000_it++;
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	system("leaks ft_containers");
}

