#include <iostream>
#include <string>
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

	void check_user_value(const int generatedValue, int userValue)
	{
		// TODO: Check the users number based on the random number.
	}

	// TODO: Create a score counter.
}

int main()
{
	using namespace gtn;

	print_log("wecome to... The Guessing Game \nIf you would like to Quite, please enter -1.\n");

	while (true)
	{
		int _user_num = user_input("Please enter a number between 0 and 10");

		if (_user_num < 0)
		{
			print_log("\n\nYou are not exiting the game.\nThank you for Playing.\n");
			return false;
		}

		int const _rand_val = random_in_range(0, 10);

		check_user_value(_rand_val, _user_num);

	}


	/*for (int i = 0; i < 10; ++i)
	{
		int const rand_val = random_in_range(0, 10);
		print_log(std::to_string(rand_val));
	}*/
}