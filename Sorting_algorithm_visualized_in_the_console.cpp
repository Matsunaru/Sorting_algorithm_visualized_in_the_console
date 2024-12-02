#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
int Only_Number();
void Generte_numbers(int number,int* array);
void Quick_Sort(int* Array, int low, int high);
void Display_Sort();
void swap(int& a, int& b);
int partition(int* Array, int low, int high);




int main()
{
    std::cout << "How many Element do you want to sort: ";
    int number=Only_Number();
    int* Array = new int[number];//dynamic Array
    Generte_numbers(number,Array);
    Quick_Sort(Array, 0, number-1);
    for (int i = 0; i < number; i++)
    {
        std::cout << Array[i];
    }
}
int Only_Number()
{
    int input;
    while (true)
    {
        if (std::cin >> input)//cheking if user put number
        {
            return input;
        }
        else//if not give him another chance
        {
            std::cout << "We accept only number Bro: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
void Generte_numbers(int number,int* Array)
{
    //int* Array = new int[number];//dynamic Array
    srand(time(NULL));
    for (int i = 0; i < number; i++)//gennerating numbers from 1 to 30
    {
       Array[i] = rand() % 30 + 1;
    }
    for (int i = 0; i < number; i++)
    {
        std::cout << Array[i] << std::endl;
    }
}
void Quick_Sort(int* Array,int low,int high)
{
    if (low < high)
    {
        int PivotIndex = partition(Array, low, high);
        Quick_Sort(Array, low, PivotIndex - 1);
        Quick_Sort(Array, PivotIndex + 1,high);

    }
}
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partition(int* Array, int low, int high)
{
    int pivot = Array[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (Array[j] < pivot)
        {
            i++;
            swap(Array[i], Array[j]);
        }
    }
    swap(Array[i + 1], Array[high]);
    return i + 1;
}