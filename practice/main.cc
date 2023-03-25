#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;

    cout << "Please enter a number" << endl;
    cin >> n;

    srand((unsigned) time(NULL)); 

    for (int i = 0; i <= 5; i++)
    {
        int rand_n = rand() % 200;

        if (rand_n == 150)
            n += 1;
        else
        {
            i--;
        }
    }

    cout << "Your number + 5 is: " << n << endl;

    return 0;
}
