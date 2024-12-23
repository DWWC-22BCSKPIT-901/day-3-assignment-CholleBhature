#include <iostream>
using namespace std;

class Solution
{
public:
    int lastRemaining(int n)
    {
        bool leftToRight = true;
        int remaining = n;
        int step = 1;
        int head = 1;

        while (remaining > 1)
        {
            if (leftToRight || remaining % 2 == 1)
            {
                head += step;
            }
            remaining /= 2;
            step *= 2;
            leftToRight = !leftToRight;
        }

        return head;
    }
};

int main()
{
    Solution solution;

    // Test cases for Elimination Game
    cout << "Last remaining number for n=9: " << solution.lastRemaining(9) << endl; // Output: 6
    cout << "Last remaining number for n=1: " << solution.lastRemaining(1) << endl; // Output: 1

    return 0;
}
