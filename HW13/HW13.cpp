#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <unordered_map>

#ifdef _WIN32
#define LOCALTIME(T, TM) localtime_s(TM, T)
#else
#define LOCALTIME(T, TM) localtime_r(T, TM)
#endif

std::vector<std::string> database;
const std::string WORD_OF_THE_DAY_FILE = "word_of_the_day.txt";

void loadDatabase(const std::string& filename) 
{
    std::ifstream file(filename);
    if (!file) 
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        exit(1);
    }
    std::string word;
    while (file >> word)
    {
        if (word.size() == 5)
        {
            database.push_back(word);
        }
    }
    if (database.empty()) 
    {
        std::cerr << "Error: Database is empty or contains no valid 5-letter words." << std::endl;
        exit(1);
    }
}

std::string getCurrentDate()
{
    time_t t = time(0);
    struct tm now;
    LOCALTIME(&t, &now);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &now);
    return std::string(buffer);
}

std::string getWordOfTheDay() {
    std::ifstream file(WORD_OF_THE_DAY_FILE);
    std::string savedDate, savedWord;
    std::string currentDate = getCurrentDate();
    if (file >> savedDate >> savedWord && savedDate == currentDate) {
        if (savedWord.size() == 5) {
            for (char& c : savedWord) c = toupper(c);
            return savedWord;
        }
    }

    srand(time(0));  
    std::string newWord = database[rand() % database.size()];
    if (newWord.size() != 5) 
    {
        std::cerr << "Error: Selected word is not 5 letters long." << std::endl;
        exit(1);
    }
    for (char& c : newWord) c = toupper(c);
    std::ofstream outFile(WORD_OF_THE_DAY_FILE);
    if (!outFile) 
    {
        std::cerr << "Error: Could not open file " << WORD_OF_THE_DAY_FILE << std::endl;
        exit(1);
    }
    outFile << currentDate << " " << newWord;
    return newWord;
}

void checkGuess(const std::string& secret, const std::string& guess) 
{
    std::unordered_map<char, int> letterCount;
    for (char c : secret) letterCount[c]++;

    std::string result(secret.size(), '*');
    std::vector<bool> marked(secret.size(), false);

    for (size_t i = 0; i < secret.size(); ++i)
    {
        if (guess[i] == secret[i])
        {
            result[i] = toupper(guess[i]);
            letterCount[guess[i]]--;
            marked[i] = true;
        }
    }

    for (size_t i = 0; i < secret.size(); ++i) 
    {
        if (!marked[i] && letterCount[guess[i]] > 0) 
        {
            result[i] = tolower(guess[i]);
            letterCount[guess[i]]--;
        }
    }

    std::cout << "RESULT: " << result << std::endl;
}

void playWordleOfTheDay() 
{
    std::string secretWord = getWordOfTheDay();
    std::string userGuess;
    int attempts = 0;

    std::cout << "Welcome to Wordle of the Day! Guess the 5-letter word." << std::endl;

    while (true) 
    {
        std::cout << "ENTER: ";
        std::cin >> userGuess;

        if (userGuess.size() != 5) 
        {
            std::cout << "Please enter a 5-letter word." << std::endl;
            continue;
        }

        for (char& c : userGuess) c = toupper(c);
        attempts++;

        if (userGuess == secretWord) 
        {
            std::cout << "That's right!" << std::endl;
            std::cout << "You made " << attempts << " tries!" << std::endl;
            break;
        }

        checkGuess(secretWord, userGuess);
    }
}

void playRandomWordle()
{
    srand(time(0));  
    std::string secretWord = database[rand() % database.size()];
    for (char& c : secretWord) c = toupper(c);

    std::string userGuess;
    int attempts = 0;

    std::cout << "Welcome to Random Wordle! Guess the 5-letter word." << std::endl;

    while (true) 
    {
        std::cout << "ENTER: ";
        std::cin >> userGuess;

        if (userGuess.size() != 5) 
        {
            std::cout << "Please enter a 5-letter word." << std::endl;
            continue;
        }

        for (char& c : userGuess) c = toupper(c);
        attempts++;

        if (userGuess == secretWord) 
        {
            std::cout << "That's right!" << std::endl;
            std::cout << "You made " << attempts << " tries!" << std::endl;
            break;
        }

        checkGuess(secretWord, userGuess);
    }
}

void showMenu() 
{
    std::cout << "1 - Wordle of the day" << std::endl;
    std::cout << "2 - Random Wordle" << std::endl;
    std::cout << "0 - Exit" << std::endl;
}

int main() {
    loadDatabase("words.txt");

    int choice;
    do 
    {
        showMenu();
        std::cout << "Enter: ";
        std::cin >> choice;

        switch (choice) 
        {
        case 1:
            playWordleOfTheDay();
            break;
        case 2:
            playRandomWordle();
            break;
        case 0:
            std::cout << "Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}