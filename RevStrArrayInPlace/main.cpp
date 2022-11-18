// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

void revStrArrInPlace(std::vector<std::string>& input)
{
    int midPoint{0};
    
    if (input.size() > 0)
        midPoint = (int) (input.size() / 2);

    int indexFront{ 0 };
    int indexEnd{ (int)(input.size() - 1) };
    for (; indexFront < midPoint; ++indexFront, --indexEnd)
    {
        std::string holder = input[indexFront];
        input[indexFront] = input[indexEnd];
        input[indexEnd] = holder;
    }
}

void outputStrArrToConsole(std::vector<std::string> input)
{
    std::vector<std::string>::iterator it;
    for (it = input.begin(); it != input.end(); ++it)
        std::cout << *it << " ";

    std::cout << '\n';
}

int main()
{
    std::vector<std::string> arrOdd = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<std::string> arrEven = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

    revStrArrInPlace(arrOdd);
    outputStrArrToConsole(arrOdd);

    revStrArrInPlace(arrEven);
    outputStrArrToConsole(arrEven);

    return 0;
}


