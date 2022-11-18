// main.cpp : 
//

#include <iostream>
#include <vector>

void sortOddEven(std::vector<int>& v, int num)
{
    int inputLength = (int) v.size();
    int processCount = 0;
    for (std::vector<int>::size_type index = 0; ((index < inputLength) && (processCount < inputLength)); ++processCount)
    {
        if (v[index] % num == 0)
        {
            v.push_back(v[index]);
            v.erase(v.begin() + index);
        }
        else
        {
            ++index;
        }
    }
}

int main()
{
    std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
    int num = 2;
    std::vector<int>::iterator it;

    sortOddEven(v, num);

    for (it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";

    std::cout << '\n';

    return 0;
}


