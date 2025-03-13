#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>


struct Node 
{
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

std::vector<std::string> splitString(const std::string& line)
{
    std::vector<std::string> words;
    std::string currentWord;
    for (char ch : line) 
    {
        if (std::ispunct(ch) || std::isspace(ch)) 
        {
            if (!currentWord.empty()) 
            {
                std::transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);
                words.push_back(currentWord);
                currentWord.clear();
            }
        }
        else
        {
            currentWord += ch;
        }
    }
    if (!currentWord.empty()) 
    {
        std::transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);
        words.push_back(currentWord);
    }
    return words;
}

unsigned int uniqueWordsCount(const std::string& line)
{
    std::set<std::string> uniqueWords;
    std::vector<std::string> words = splitString(line);
    for (const std::string& word : words)
    {
        if (!word.empty())
        {
            uniqueWords.insert(word);
        }
    }
    return uniqueWords.size();
    
}


std::string mostOccuredWord(const std::string& line) {
    std::map<std::string, int> wordCounts;
    std::string mostFrequentWord;
    int maxCount = 0;

    std::vector<std::string> words = splitString(line);
    for (const std::string& word : words)
    {
        if (!word.empty())
        {
            wordCounts[word]++;
            if (wordCounts[word] > maxCount)
            {
                maxCount = wordCounts[word];
                mostFrequentWord = word;
            }
        }
    }
    return mostFrequentWord;
}

bool checkBracket(const std::string& line)
{
    std::stack<char> s;
    for (char ch : line)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty()) return false;
            char top = s.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '['))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return s.empty();
}


bool has_cycle(Node* head)
{
    if (head == nullptr)
        return false;

    Node* firstNode = head;
    Node* secondNode = head;

    while (secondNode != nullptr && secondNode != nullptr)
    {
        firstNode->next;
        secondNode->next->next;
        if (firstNode == secondNode)
            return true;
    }
    return false;
}
void test()
{
    std::string line = "Hello Hey Hello Bye Hey bro! sister tree dog kitchen, dog, dog dog kitchen, kitchen,kitchen, kitchen, kitchen, kitchen,kitchen,kitchen,kitchen,kitchen,kitchen, bath, aloha.bath,bath,bath,bath,bath,bath,bath,bath,bath,bath,bath,bath,bath,bath,bath,bath,bath,bath, ";
    std::cout << "Unique words count: " << uniqueWordsCount(line) << std::endl;
    std::cout << "Most Freq word: " << mostOccuredWord(line) << std::endl;

    std::string str1 = "{ [()][ ] }()";
    std::string str2 = "[{]}";

    std::cout << (checkBracket(str1) ? "OK" : "NOT OK") << std::endl;
    std::cout << (checkBracket(str2) ? "OK" : "NOT OK") << std::endl;

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    std::cout << "Test No cycle: " << (has_cycle(head1) ? "Cycle found" : "No cycle") << " (Expected: No cycle)" << std::endl;

    // Тест 2: Список з циклом
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = head2; // Створюємо цикл
    std::cout << "Test Cycle: " << (has_cycle(head2) ? "Cycle found" : "No cycle") << " (Expected: Cycle found)" << std::endl;

}

int main()
{
    test();
    return 0;
}
