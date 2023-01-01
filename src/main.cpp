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
				if (ret <= 10)
					return ret;

				print_log("The value you entered was greater than 10, Please try again.\n");
			}
			catch (const std::exception&)
			{
				print_log("The value input is not an interger, Please try again with whole numbers\n");				
			}
		}
	}

	std::string check_user_value(const int generatedValue, const int userValue, int& score)
	{
		std::string msg{};

		// TODO: Check the users number based on the random number.
		if (userValue == generatedValue)
		{
			msg = "Congradulations, You have guessed correctly\n";
			msg += "Generated: " + std::to_string(generatedValue) + " Your Guess: " + std::to_string(userValue) + "\n\n";
			++score;
			return msg;
		}

		if (userValue < generatedValue)
		{
			
			msg = "ohh, You have guessed incorrectly. You guess was to low.\n";
			msg += "Generated: " + std::to_string(generatedValue) + " Your Guess: " + std::to_string(userValue) + "\n\n";
			return msg;
		}

		if (userValue > generatedValue)
		{

			msg = "ohh, You have guessed incorrectly. You guess was to high.\n";
			msg += "Generated: " + std::to_string(generatedValue) + " Your Guess: " + std::to_string(userValue) + "\n\n";
			return msg;
		}

	}
}

int main()
{
	using namespace gtn;

	int score{};
	std::string msg{};

	print_log("wecome to... The Guessing Game \nIf you would like to Quite, please enter -1.\n");

	while (true)
	{
		int _user_num = user_input("Please enter a number between 0 and 10");

		if (_user_num < 0)
		{
			msg = "\n\n--------------------------------------\n--------------------------------------";
			msg += "\n\nYou are now exiting the game.\nThank you for Playing.\n\nYour score was: " + std::to_string(score) + "\n";
			print_log(msg);
			return false;
		}

		int const _rand_val = random_in_range(0, 10);

		msg = check_user_value(_rand_val, _user_num, score);
		msg += "--------------------------------------";

		print_log(msg);
	}
}