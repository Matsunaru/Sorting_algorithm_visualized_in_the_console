#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
int Only_Number();
void Generte_numbers(int number);
void Quick_Sort();
void Display_Sort();




int main()
{
    std::cout << "How many Element do you want to sort: ";
    Generte_numbers(Only_Number());
}
int Only_Number()
{
    int input;
    if (std::cin >> input)
    {
        return input;
    }
    else
    {
        std::cout << "We accept only number Bro";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
void Generte_numbers(int number)
{
    int* Array = new int[number];
    srand(time(NULL));
    for (int i = 0; i < number; i++)
    {
       Array[i] = rand() % 30 + 1;
    }
    /*for (int i = 0; i < number; i++)
    {
        std::cout << Array[i] << std::endl;
    }*/
}