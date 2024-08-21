#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <deque>
#include <algorithm>
#include <string> 
#include <execution>
#include <numeric>
#include <iterator>

namespace Algo {

	class Point {
	public:
		int x, y;
		Point(int x = 0, int y = 0) :x{ x }, y{ y }
		{}

		bool operator < (const Point& other)
		{
			return (x + y) < (other.x + other.y);
		}
	};

	std::vector<int> v1{ 0,1,2,3,4,5 };
	std::vector<int> v2{ 4,5,6,7,8,9 };
	std::vector<int> v3, v4, v5, v6;

	template<typename T>
	std::string print_vec(const std::vector<T>& vec)
	{
		std::string out{ "" };
		for (typename std::vector<T>::const_iterator it = vec.cbegin(); it != vec.end(); ++it)
		{
			out += std::to_string(*it) + " ";
		}
		return out;
	}

	void set_union()
	{
		std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));
		std::cout << "set_union: " << print_vec<int>(v3) << "\n";
	}

	void set_intersection() {
		std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v4));
		std::cout << "set_intersection: " << print_vec<int>(v4) << "\n";
	}

	void set_difference()
	{
		std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v5));
		std::cout << "set_difference: " << print_vec<int>(v5) << "\n";
	}

	void set_symmetric_difference()
	{
		std::set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v6));
		std::cout << "set_symmetric_difference: " << print_vec<int>(v6) << "\n";
	}

	void sort()
	{
		std::vector<int> vec{ 5,4,6,7,3,2,8,9,1 };
		std::sort(std::execution::par, vec.begin(), vec.end());
		for (const auto& element : vec)
		{
			printf("%d ", element);
		}
		std::cout << "\n";
		std::vector<int> vec2{ 5,4,6,7,3,2,8,9,1 };
		std::sort(vec2.begin(), vec2.end());
		for (const auto& element : vec2)
		{
			printf("%d ", element);
		}
		std::cout << "\n";

		std::vector<Point> vec_point{ {1,2}, {3,1}, {0,1} };
		std::sort(vec_point.begin(), vec_point.end());
		for (const auto& element : vec_point)
		{
			printf("{%d, %d} ", element.x, element.y);
		}
		std::cout << "\n";

		std::vector<int> vec3{ 5,4,6,7,3,2,8,9,1 };
		std::sort(vec3.begin(), vec3.end(), [](int a, int b) {return a < b; });
		for (const auto& element : vec3)
		{
			printf("%d ", element);
		}
		std::cout << "\n";

		std::vector<int> vec4{ 5,4,6,7,3,2,8,9,1 };
		std::sort(vec4.begin(), vec4.end(), std::greater<int>());
		for (const auto& element : vec4)
		{
			printf("%d ", element);
		}
		std::cout << "\n";

		std::vector<int> vec5{ 5,4,6,7,3,2,8,9,1 };
		std::sort(vec5.begin(), vec5.end(), std::less<int>());
		for (const auto& element : vec5)
		{
			printf("%d ", element);
		}

	}

	void is_sorted()
	{
		std::vector<int> vec{ 2,3,5,6,9,1,0,3 };
		bool result = std::is_sorted(vec.begin(), vec.end());
		std::cout << "result: " << result << "\n";
		std::vector<int> vec2{ 9,8,7,6,5,4,3,2,1,0 };
		result = std::is_sorted(vec2.begin(), vec2.end(), std::greater<int>());
		std::cout << "result: " << result << "\n";
		std::sort(vec2.begin(), vec2.end());
		result = std::is_sorted(vec2.begin(), vec2.end(), std::less<int>());
		std::cout << "result: " << result << "\n";
	}

	void partial_sort()
	{
		std::vector<int> vec{ 2,3,5,6,9,1,0,3 };
		std::partial_sort(vec.begin(), vec.begin() + 4, vec.end());
		for (const auto& el : vec)
		{
			std::cout << "el: " << el << "\n";
		}

	}

	void nth_element()
	{
		std::vector<int> vec{ 2,3,5,6,9,1,0,3 };
		std::nth_element(vec.begin(), vec.begin() + vec.size() / 2, vec.end());

	}

	void is_sorted_until()
	{
		std::vector<int> vec{ 2,3,5,6,9,1,0,3 };
		auto it = std::is_sorted_until(vec.begin(), vec.end());
		auto diff = std::distance(vec.begin(), it);
		std::cout << "diff: " << diff << "\n";

		it = std::is_sorted_until(vec.begin(), vec.end(), std::greater<int>());
		diff = std::distance(vec.begin(), it);
		std::cout << "diff: " << diff << "\n";
	}

	void iota()
	{
		std::list<int> list(10);
	std:iota(list.begin(), list.end(), -4);

	}

	void copy()
	{
		std::vector<int> from_vec(10);
		std::iota(from_vec.begin(), from_vec.end(), 0);
		std::vector<int> to_vec1;
		to_vec1.resize(from_vec.size());

		std::copy(from_vec.begin(), from_vec.end(), to_vec1.begin());
		std::cout << print_vec<int>(to_vec1) << "\n";

		std::vector<int> to_vec2;
		std::copy(from_vec.begin(), from_vec.end(), std::back_inserter(to_vec2));
		std::cout << print_vec<int>(to_vec2) << "\n";
	}

	void copy_if()
	{
		std::vector<int> from_vec(10);
		std::iota(from_vec.begin(), from_vec.end(), 0);
		std::vector<int> to_vec(5);
		std::copy_if(from_vec.begin(), from_vec.end(), to_vec.begin(), [](int x) {return (x % 2) == 1; });
		std::cout << print_vec<int>(to_vec) << "\n";

	}

	void run()
	{
		//set_union();
		//set_intersection();
		//set_difference();
		//set_symmetric_difference();

		//sort();
		//is_sorted();
		//partial_sort();
		//nth_element();
		//is_sorted_until();
		//copy();
		copy_if();
	}

}

namespace Virtual
{
	/*
	* without virtual dtor, the output is:
	*	ctor Base
		ctor derived
		dtor Base

	* so want to delete also derived, so because of that we need virtual dtor
	*/
	class Base {
	public:
		Base() {
			std::cout << "ctor Base\n";
		}

		virtual ~Base() {
			std::cout << "dtor Base\n";
		}
	};

	class Derived : public Base {
	public:
		Derived() {
			std::cout << "ctor derived\n";
		}
		~Derived() override {
			std::cout << "dtor derived\n";
		}
	};

	void run()
	{
		Base* b = new Derived();
		delete b;

	}
}

int main()
{
	//Algo::run();
	Virtual::run();
}

