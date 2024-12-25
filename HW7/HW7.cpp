#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <cstring> 

const unsigned short BACKCOLOR = 7;
const unsigned short FRONTCOLOR = 0;
const unsigned short SELECTCOLOR = 4;
const unsigned short TOPMENU = 10;
const unsigned short LEFTMENU = 20;

void SetColor(unsigned short backColor, unsigned short frontColor)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD color = ((backColor & 0x0f) << 4) + (frontColor & 0x0f);
    SetConsoleTextAttribute(h, color);
}
void SetCursor(unsigned short row, unsigned short column)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c{ column,row };
    SetConsoleCursorPosition(h, c);
}
void PaintMenu(const char** textMenu, size_t sizeMenu, size_t select)
{
    SetColor(BACKCOLOR, FRONTCOLOR);
    SetCursor(TOPMENU, LEFTMENU);
    for (size_t i = 0; i < sizeMenu; i++)
    {
        SetCursor(TOPMENU + i + 1, LEFTMENU + 25);
        if (i == select)
            SetColor(BACKCOLOR, SELECTCOLOR);
        else
            SetColor(BACKCOLOR, FRONTCOLOR);
        std::cout << (i == select ? "=>" : " ") << textMenu[i];
        std::cout << "           ";
    }

    SetCursor(20, 0);
}
size_t Menu(const char** textMenu, size_t sizeMenu, size_t select)
{
    unsigned char c = 72;
    while (true)
    {
        if (c == 72 || c == 80) PaintMenu(textMenu, sizeMenu, select);
        c = _getch();
        switch (c)
        {
        case 13: return select;
        case 72:
            if (select == 0) select = sizeMenu;
            select--;
            break; 
        case 80:
            select++;
            if (select == sizeMenu)
                select = 0;
            break; 
        default:
            break;
        }
    }

    return select;
}


int main()
{
    srand(time(NULL));
    SetColor(BACKCOLOR, FRONTCOLOR);
    system("cls");
    size_t select = 0;
    int compscore = 0, myscore = 0, draws = 0;
    const char* compChoise = nullptr;
    const char* myChoise = nullptr;
    int rolls;
    const char* textMenu[] = { "Start Game",
                               "Exit" };
    size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
    const char* gameMenu[] = { "Rock",
                               "Paper",
                               "Scissors" };
    size_t sizeGameMenu = sizeof(gameMenu) / sizeof(*gameMenu);
    while (1)
    {
        select = Menu(textMenu, sizeMenu, select);
        system("cls");
        switch (select)
        {
        case 0:
            SetCursor(6, 40);
            system("cls");
            std::cout << "Welcome to the game \"Rock, paper, scissors\"!" << std::endl;
            std::cout << "Enter round numbers: ";
            std::cin >> rolls;
            std::cout << std::endl;
            compscore = 0;
            myscore = 0;
            for (int i = 0; i < rolls; i++)
            {
                select = 0;
                select = Menu(gameMenu, sizeGameMenu, select);
                system("cls");
                std::cout << "Your choice is " << gameMenu[select] << std::endl;

                int myChoice = select; 
                int compChoice = rand() % 3; 
                std::cout << "Computer choice is " << gameMenu[compChoice] << std::endl;

                if (myChoice == compChoice)
                {
                    std::cout << "\nIt's a draw!" << std::endl;
                    draws++;
                }
                else if ((myChoice == 0 && compChoice == 2) || 
                    (myChoice == 1 && compChoice == 0) || 
                    (myChoice == 2 && compChoice == 1))   
                {
                    myscore++;
                    std::cout << "\nYou've won!" << std::endl;
                }
                else
                {
                    compscore++;
                    std::cout << "\nYou lost\n";
                }
            }

            select = 0;
            std::cout << std::endl << "The game is over!" << std::endl;
            std::cout << "Numbers of rounds - " << rolls << std::endl;
            std::cout << "Numbers of wins - " << myscore << std::endl;
            std::cout << "Numbers of losses - " << compscore << std::endl;
            std::cout << "Numbers of draws - " << draws << std::endl;
            if (myscore > compscore)
                std::cout << "You've won the game!\nYou're smarter than my PC" << std::endl;

            else if (myscore < compscore)
                std::cout << "The computer won the game!" << std::endl;
            else
                std::cout << "It's a draw!" << std::endl;
            break;
        case 1:
            return 0;
        default:
            break;
        }
    }
}
