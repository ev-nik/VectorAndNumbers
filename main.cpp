#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

enum MenuIteam
{
    Exit            = 0,  // Выход из программы
    Print           = 1,  // Вывести вектор на консоль
    Find            = 2,  // Найти адрес числа в векторе
    Recreate        = 3,  // Создать вектор заново
    Change          = 4,  // Поменять местами 1й и последний элемент вектора
    SortByIndex     = 5,  // Отсортировать вектор по индексу
    SortByIt        = 50, // Отсортировать вектор по итератору
    ReplaceOn       = 6,  // Замена чисел в векторе
    Arithmetic_mean = 7   // Среднее арифметическое вектора
};



// Функция генерирует числа в заданном диапазоне min/max
int GetRandomNumber(int min, int max)
{
    int num = min + rand() % (max - min + 1);

    return num;
}

// Функция создает вектор в диапазоне чисел
std::vector<int> createArr()
{
    int countNum = 0;
    int min = 0;
    int max = 0;

    std::cout << " enter a min number: " << '\n';
    std::cin >> min;

    std::cout << " enter a max number: " << '\n';
    std::cin >> max;

    std::cout << " enter a count numbers: " << '\n';
    std::cin >> countNum;

    std::vector<int> vec(countNum);

    for(size_t i = 0; i < vec.size(); i++)
    {
        vec[i] = GetRandomNumber(min, max);
    }

    return vec;
}

// Функция печатает значения из вектора
void printValue( std::vector<int>& v )
{
    for(int& val : v)
    {
        std::cout << val << '\n';
    }
}

// Функция ищет заданное число
std::vector<int>::iterator findPointerValue(std::vector<int>& v, int value)
{
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        if(*it == value)
        {
            return it;
        }
    }

    return v.end();
}

// Функция сортирует вектор с помощью итератора
void sortByIt(std::vector<int>& v)
{
    for(std::vector<int>::iterator it = v.begin(); it != v.end() - 1; it++)
    {
        std::vector<int>::iterator smallIt = it;

        for(std::vector<int>::iterator itt = it + 1; itt < v.end(); itt++)
        {
            if(*itt < *smallIt)
            {
                smallIt = itt;
            }
        }

        int tmp = *smallIt;
        *smallIt = *it;
        *it = tmp;
    }
}

// Функция сортирует вектор с помощью индексов
void sortByIndex(std::vector<int>& v)
{
    for(size_t i = 0; i < v.size() - 1; i++)
    {
        int smallIt = i;

        for(size_t ii = i + 1; ii < v.size(); ii++)
        {
            if(v[ii] < v[smallIt])
            {
                smallIt = ii;
            }
        }

        int tmp = v[smallIt];
        v[smallIt] = v[i];
        v[i] = tmp;
    }
}

// Функция производит замену чисел
int replaceOn( std::vector<int>& v, int valueArr, int valueChange)
{
    int countChange = 0;

    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        if(*it == valueArr)
        {
            *it = valueChange;
            countChange++;
        }
    }

    return countChange;
}

// Функция рассчитывает среднее арифметическое вектора
double arithmeticMean(std::vector<int>& v)
{
    double sum = 0.0;

    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        sum += *it;
    }

    return sum / v.size();
}

int main()
{
    std::vector<int> vect = createArr();

    bool t = true;

    while(t)
    {
        std::cout << "[" << Exit            << "] Exit" << '\n'
                  << "[" << Print           << "] Print: address : value" << '\n'
                  << "[" << Find            << "] Find : address : value" << '\n'
                  << "[" << Recreate        << "] Recreate array" << '\n'
                  << "[" << Change          << "] Change 1 and end value" << '\n'
                  << "[" << SortByIndex     << "] Sort by index" << '\n'
                  << "[" << SortByIt        << "] Sort by iterator" << '\n'
                  << "[" << ReplaceOn       << "] ReplaceOn" << '\n'
                  << "[" << Arithmetic_mean << "] Arithmetic_mean" << '\n';

        int operation;

        std::cout << " -> ";

        std::cin >> operation;

        switch(operation)
        {
            case Exit:
            {
                t = false;
                break;
            }

            case Print:
            {
                printValue(vect);
                break;
            }

            case Find:
            {
                std::cout << " Enter rand value of min max " << '\n';

                int valueAnyNum;
                std:: cin >> valueAnyNum;

                std::vector<int>::iterator val2 = findPointerValue( vect, valueAnyNum );

                if(val2 != vect.end())
                {
                    std::cout << "Value is found: " << *val2 << '\n';
                }
                else
                {
                    std::cout << "Value is not found!" << '\n';
                }

                break;
            }

            case Recreate:
            {
                vect = createArr();
                break;
            }

            case Change:
            {
                std::cout << "before swap" << '\n';
                printValue(vect);

                int tmp = vect[0];
                vect[0] = vect[vect.size() - 1];
                vect[vect.size() - 1] = tmp;

                std::cout << "after swap" << '\n';
                printValue(vect);

                break;
            }

            case SortByIndex:
            {
                sortByIndex(vect);
                break;
            }

            case SortByIt:
            {
                sortByIt(vect);
                break;
            }

            case ReplaceOn:
            {

                std::cout << "Enter the number which need to be changed" << '\n';
                int valueArr;
                std::cin >> valueArr;

                std::cout << "Enter the number to be changed to" << '\n';
                int valueChange;
                std::cin >> valueChange;

                std::cout << "Array before replacement" << '\n';
                std::cout << " " << '\n';
                printValue(vect);

                int countChanged = replaceOn(vect, valueArr, valueChange);

                std::cout << " " << '\n';
                std::cout << "Array after replacement" << '\n';

                std::cout << " " << '\n';
                printValue(vect);

                std::cout << " " << '\n';
                std::cout << "Replacements made: " << countChanged << '\n';
                std::cout << " " << '\n';

                break;
            }

            case Arithmetic_mean:
            {
                double arKMean = arithmeticMean(vect);
                std::cout << " Arithmetic mean: " << arKMean << '\n';

                break;
            }

            default:
            {
                std::cout << "Error!" << '\n';
                break;
            }
        }
    }

    return 0;
}
