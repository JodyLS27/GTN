#include <string>
#include <iostream>

#include <random>

#if defined(_WIN32)
#include <Windows.h>
#endif

namespace gtn
{
	void print_log(std::string msg)
	{
		msg += "\n";
		std::cout << msg;
#if defined(_WIN32)
		OutputDebugStringA(msg.c_str());
#endif
	}


	int random_in_range(int lo, int hi) 
	{
		//std::uniform_real_distribution  // For floats and doubles.
		//static auto engine = std::default_random_engine{};
		static auto engine = std::default_random_engine{ std::random_device{}() };
		auto distribution = std::uniform_int_distribution<int>{ lo, hi };		
		return distribution(engine);
	}
}

int main()
{
	using namespace gtn;

	for (int i = 0; i < 10; ++i)
	{
		int const rand_val = random_in_range(0, 10);
		print_log(std::to_string(rand_val));
	}
}