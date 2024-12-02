#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <thread>

//func that cheking if user input is number or not
int Only_Number();
//generete numbers from 0 to 30, from user input
void Generte_numbers(int number,int* array);
//Quick Sort algorytm
void Quick_Sort(int* Array, int low, int high, int number1);
//visualization of sorting process
void Display_Sort(int* Array,int number);
//helping void that make easier to change numbers
void swap(int& a, int& b);
//Key element of Quick sort algo
int partition(int* Array, int low, int high,int number1);




int main()
{
    std::cout << "How many Element do you want to sort: ";
    int number=Only_Number();
    int* Array = new int[number];//dynamic Array
    Generte_numbers(number,Array);
    Display_Sort(Array, number);// Display the array before sorting
    Quick_Sort(Array, 0, number-1,number);// Perform Quick Sort
    Display_Sort(Array, number);// Display the sorted array
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
        else//If not, prompt the user to try again
        {
            std::cout << "We accept only number Bro: ";
            std::cin.clear();// Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
void Generte_numbers(int number,int* Array)
{
    srand(time(NULL));//Initialize the random number generator
    for (int i = 0; i < number; i++)//gennerating numbers from 1 to 30
    {
       Array[i] = rand() % 30 + 1;
    }
}
void Quick_Sort(int* Array,int low,int high,int number1)
{
    if (low < high)
    {
        //Pivot returning Array in 2 parts and return the pivot index
        int PivotIndex = partition(Array, low, high,number1);
        // Recursively sort the left part
        Quick_Sort(Array, low, PivotIndex - 1,number1);
        // Recursively sort the right part
        Quick_Sort(Array, PivotIndex + 1,high,number1);

    }
}
void swap(int& a, int& b)
{
    // Swap the values of two variables
    int temp = a;
    a = b;
    b = temp;
}
int partition(int* Array, int low, int high,int number1)
{
    int pivot = Array[high]; // Set the last element as the pivot
    int i = low - 1;
    //loop that loop from begining of Array to end
    for (int j = low; j < high; j++)
    {
        if (Array[j] < pivot)//if Array[j] is lower then pivot then execiut
        {
            i++;
            swap(Array[i], Array[j]);//swap element
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Add a delay for visualization
            Display_Sort(Array, number1);
        }
    }
    // Place the pivot in the correct position
    swap(Array[i + 1], Array[high]);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));// Add a delay for visualization
    Display_Sort(Array, number1);
    return i + 1;// Return the pivot index
}
void Display_Sort(int* Array,int number)
{
    system("CLS");
    for (int p = 30; p > 0;p--)//looping 30 times 
    {
        for (int i = 0; i < number; i++)//looping throu how many Array there is
        {
            if (Array[i] < p)//if Array number is lower then p printing " "
            {
                std::cout << " ";
            }
            else//else prining "#"
            {
                std::cout << "#";
            }
        }
        std::cout << std::endl;//Move to the next line
    }
}