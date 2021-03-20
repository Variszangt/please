#include <iostream>
#include <string>

enum class Result
{
    Continue,
    ShouldExit,
};

Result run(std::string input)
{
    std::cout << input;
    return Result::ShouldExit;
}

int main(int argc, char** argv)
{
    if (argc == 1) // Interactive mode:
    {
        std::cout << '>';
        std::string input;
        while (std::getline(std::cin, input))
        {
            auto result = run(input);
            if (result == Result::ShouldExit)
                break;
        }
    }
    else // Input as arguments:
    {
        std::string input;
        for (int i = 1; i != argc; ++i)
        {
            input += argv[i];
            input += ' ';
        }
        run(input);
    }
}
