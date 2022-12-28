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

	[[nodiscard]] int user_input(std::string const& msg)
	{
		while (true)
		{
			print_log(msg);

			std::string input{};
			int ret{};

			std::getline(std::cin, input); // Delimit - Input limit.

			try
			{
				ret = std::stoi(input);
				return ret;
			}
			catch (const std::exception&)
			{
				print_log("The value input is not an interger, Please try again with whole numbers");				
			}
		}
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

	int user_num = user_input("Please enter a number");

	std::string msg = "User Input: ";
	msg += std::to_string(user_num);

	print_log(msg);
}