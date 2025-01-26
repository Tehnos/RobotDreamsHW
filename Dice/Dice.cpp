#include <iostream>
#include <windows.h>
#include <iomanip>



int main()
{
using namespace std;
    srand(time(NULL));

    cout << "Welcome to the game \"Dice\"!" << endl;

    int compscore = 0, myscore = 0;
    int rolls = 3;
    int dice_1, dice_2;
    int n = 10;
    for (int i = 0; i < rolls; i++) {
        cout << endl << "Roll the dice (press Enter to roll)...";
        cin.get();
        dice_1 = rand() % 6 + 1;
        dice_2 = rand() % 6 + 1;
        myscore += dice_1 + dice_2;
        if (dice_1 == 1 || dice_2 == 1)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    cout << setw(2) << "0";
                    if (i == n / 2 && j == n / 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 1)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 - 1)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2)
                        cout << "\b ";
                }
                cout << endl;
            }
            cout << endl;
        }
        if (dice_1 == 2 || dice_2 == 2)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    cout << setw(2) << "0";
                    if (i == n / 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 + 2)
                        cout << "\b ";
                }
                cout << endl;
            }
            cout << endl;
        }
        if (dice_1 == 3 || dice_2 == 3)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    cout << setw(2) << "0";
                    if (i == n / 2 && j == n / 2 - 4)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 4)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 - 1)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 1)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 + 3)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 + 3)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 + 2)
                        cout << "\b ";
                }
                cout << endl;
            }
            cout << endl;
        }
        if (dice_1 == 4 || dice_2 == 4)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    cout << setw(2) << "0";
                    if (i == n / 2 - 3 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 2 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 - 2 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 2 && j == n / 2 + 2)
                        cout << "\b ";

                    if (i == n / 2 + 3 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 + 2)
                        cout << "\b ";
                }
                cout << endl;
            }
            cout << endl;
        }
        if (dice_1 == 5 || dice_2 == 5)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    cout << setw(2) << "0";
                    if (i == n / 2 - 4 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 4 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 4 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 4 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 + 2)
                        cout << "\b ";

                    if (i == n / 2 + 3 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 + 2)
                        cout << "\b ";

                    if (i == n / 2 && j == n / 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 1)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 - 1)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2)
                        cout << "\b ";

                }
                cout << endl;
            }
            cout << endl;
        }
        if (dice_1 == 6 || dice_2 == 6)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    cout << setw(2) << "0";
                    if (i == n / 2 - 4 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 4 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 4 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 4 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 + 2)
                        cout << "\b ";

                    if (i == n / 2 + 3 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 + 2)
                        cout << "\b ";

                    if (i == n / 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 + 2)
                        cout << "\b ";

                }
                cout << endl;
            }
            cout << endl;
        }
        if (dice_1 == dice_2)
        {
            if (dice_1 == 1 || dice_2 == 1)
            {
                for (size_t i = 0; i < n; i++)
                {
                    for (size_t j = 0; j < n; j++)
                    {
                        cout << setw(2) << "0";
                        if (i == n / 2 && j == n / 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 1)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 - 1)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2)
                            cout << "\b ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            if (dice_1 == 2 || dice_2 == 2)
            {
                for (size_t i = 0; i < n; i++)
                {
                    for (size_t j = 0; j < n; j++)
                    {
                        cout << setw(2) << "0";
                        if (i == n / 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 + 2)
                            cout << "\b ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            if (dice_1 == 3 || dice_2 == 3)
            {
                for (size_t i = 0; i < n; i++)
                {
                    for (size_t j = 0; j < n; j++)
                    {
                        cout << setw(2) << "0";
                        if (i == n / 2 && j == n / 2 - 4)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 4)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 - 1)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 1)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 + 3)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 + 3)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 + 2)
                            cout << "\b ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            if (dice_1 == 4 || dice_2 == 4)
            {
                for (size_t i = 0; i < n; i++)
                {
                    for (size_t j = 0; j < n; j++)
                    {
                        cout << setw(2) << "0";
                        if (i == n / 2 - 3 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 2 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 - 2 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 2 && j == n / 2 + 2)
                            cout << "\b ";

                        if (i == n / 2 + 3 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 + 2)
                            cout << "\b ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            if (dice_1 == 5 || dice_2 == 5)
            {
                for (size_t i = 0; i < n; i++)
                {
                    for (size_t j = 0; j < n; j++)
                    {
                        cout << setw(2) << "0";
                        if (i == n / 2 - 4 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 4 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 4 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 4 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 + 2)
                            cout << "\b ";

                        if (i == n / 2 + 3 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 + 2)
                            cout << "\b ";

                        if (i == n / 2 && j == n / 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 1)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 - 1)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2)
                            cout << "\b ";

                    }
                    cout << endl;
                }
                cout << endl;
            }
            if (dice_1 == 6 || dice_2 == 6)
            {
                for (size_t i = 0; i < n; i++)
                {
                    for (size_t j = 0; j < n; j++)
                    {
                        cout << setw(2) << "0";
                        if (i == n / 2 - 4 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 4 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 4 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 4 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 + 2)
                            cout << "\b ";

                        if (i == n / 2 + 3 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 + 2)
                            cout << "\b ";

                        if (i == n / 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 + 2)
                            cout << "\b ";

                    }
                    cout << endl;
                }
                cout << endl;
            }

        }
        Sleep(1500);
        cout << "You quit: " << dice_1 << " and " << dice_2 << endl;
        Sleep(500);
        cout << "Your score:" << myscore << endl;
        Sleep(2500);
        cout << endl << "Computer..." << endl;
        dice_1 = rand() % 6 + 1;
        dice_2 = rand() % 6 + 1;
        compscore += dice_1 + dice_2;
        if (dice_1 == 1 || dice_2 == 1)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    cout << setw(2) << "0";
                    if (i == n / 2 && j == n / 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 1)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 - 1)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2)
                        cout << "\b ";
                }
                cout << endl;
            }
            cout << endl;
        }
        if (dice_1 == 2 || dice_2 == 2)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    cout << setw(2) << "0";
                    if (i == n / 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 + 2)
                        cout << "\b ";
                }
                cout << endl;
            }
            cout << endl;
        }
        if (dice_1 == 3 || dice_2 == 3)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    cout << setw(2) << "0";
                    if (i == n / 2 && j == n / 2 - 4)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 4)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 - 1)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 1)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 + 3)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 + 3)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 + 2)
                        cout << "\b ";
                }
                cout << endl;
            }
            cout << endl;
        }
        if (dice_1 == 4 || dice_2 == 4)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    cout << setw(2) << "0";
                    if (i == n / 2 - 3 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 2 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 - 2 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 2 && j == n / 2 + 2)
                        cout << "\b ";

                    if (i == n / 2 + 3 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 + 2)
                        cout << "\b ";
                }
                cout << endl;
            }
            cout << endl;
        }
        if (dice_1 == 5 || dice_2 == 5)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    cout << setw(2) << "0";
                    if (i == n / 2 - 4 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 4 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 4 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 4 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 + 2)
                        cout << "\b ";

                    if (i == n / 2 + 3 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 + 2)
                        cout << "\b ";

                    if (i == n / 2 && j == n / 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 1)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 - 1)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2)
                        cout << "\b ";

                }
                cout << endl;
            }
            cout << endl;
        }
        if (dice_1 == 6 || dice_2 == 6)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    cout << setw(2) << "0";
                    if (i == n / 2 - 4 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 4 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 4 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 4 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 3 && j == n / 2 + 2)
                        cout << "\b ";

                    if (i == n / 2 + 3 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 + 2 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 + 3 && j == n / 2 + 2)
                        cout << "\b ";

                    if (i == n / 2 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 3)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 - 2)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 && j == n / 2 + 2)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 + 1)
                        cout << "\b ";
                    if (i == n / 2 - 1 && j == n / 2 + 2)
                        cout << "\b ";

                }
                cout << endl;
            }
            cout << endl;
        }
        if (dice_1 == dice_2)
        {
            if (dice_1 == 1 || dice_2 == 1)
            {
                for (size_t i = 0; i < n; i++)
                {
                    for (size_t j = 0; j < n; j++)
                    {
                        cout << setw(2) << "0";
                        if (i == n / 2 && j == n / 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 1)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 - 1)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2)
                            cout << "\b ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            if (dice_1 == 2 || dice_2 == 2)
            {
                for (size_t i = 0; i < n; i++)
                {
                    for (size_t j = 0; j < n; j++)
                    {
                        cout << setw(2) << "0";
                        if (i == n / 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 + 2)
                            cout << "\b ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            if (dice_1 == 3 || dice_2 == 3)
            {
                for (size_t i = 0; i < n; i++)
                {
                    for (size_t j = 0; j < n; j++)
                    {
                        cout << setw(2) << "0";
                        if (i == n / 2 && j == n / 2 - 4)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 4)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 - 1)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 1)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 + 3)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 + 3)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 + 2)
                            cout << "\b ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            if (dice_1 == 4 || dice_2 == 4)
            {
                for (size_t i = 0; i < n; i++)
                {
                    for (size_t j = 0; j < n; j++)
                    {
                        cout << setw(2) << "0";
                        if (i == n / 2 - 3 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 2 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 - 2 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 2 && j == n / 2 + 2)
                            cout << "\b ";

                        if (i == n / 2 + 3 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 + 2)
                            cout << "\b ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            if (dice_1 == 5 || dice_2 == 5)
            {
                for (size_t i = 0; i < n; i++)
                {
                    for (size_t j = 0; j < n; j++)
                    {
                        cout << setw(2) << "0";
                        if (i == n / 2 - 4 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 4 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 4 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 4 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 + 2)
                            cout << "\b ";

                        if (i == n / 2 + 3 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 + 2)
                            cout << "\b ";

                        if (i == n / 2 && j == n / 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 1)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 - 1)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2)
                            cout << "\b ";

                    }
                    cout << endl;
                }
                cout << endl;
            }
            if (dice_1 == 6 || dice_2 == 6)
            {
                for (size_t i = 0; i < n; i++)
                {
                    for (size_t j = 0; j < n; j++)
                    {
                        cout << setw(2) << "0";
                        if (i == n / 2 - 4 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 4 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 4 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 4 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 3 && j == n / 2 + 2)
                            cout << "\b ";

                        if (i == n / 2 + 3 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 + 2 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 + 3 && j == n / 2 + 2)
                            cout << "\b ";

                        if (i == n / 2 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 3)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 - 2)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 && j == n / 2 + 2)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 + 1)
                            cout << "\b ";
                        if (i == n / 2 - 1 && j == n / 2 + 2)
                            cout << "\b ";

                    }
                    cout << endl;
                }
                cout << endl;
            }

        }
        Sleep(1500);
        cout << "The computer dropped: " << dice_1 << " and " << dice_2 << endl;
        cout << "Computer score: " << compscore << endl;
    }
    cout << endl << "The game is over!" << endl;
    if (myscore > compscore) {
        cout << "You've won!" << endl;
    }
    if (myscore < compscore) {
        cout << "The computer won!" << endl;
    }
    if (myscore == compscore)
    {
        cout << "Draw!" << endl;
    }
    cout << "Your score: " << myscore << endl;
    cout << "Computer score: " << compscore << endl;

    return 0;
}

