#include <iostream>
using namespace std;

class Student
{
public:
    int rollNum;
    string name;
    float sgpa;
    string department;
    void getInfo();
    void display();
};

void Student::getInfo()
{
    cout << "Enter Roll No: ";
    cin >> rollNum;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter SGPA: ";
    cin >> sgpa;
    cout << "Enter Department: ";
    cin >> department;
}

void Student::display()
{

    cout << "Roll No: " << rollNum << endl;
    cout << "Name: " << name << endl;
    cout << "SGPA: " << sgpa << endl;
    cout << "Department: " << department << endl;
}

void bubbleSort(Student s[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (s[j].rollNum > s[j + 1].rollNum)
            {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void insertionSort(Student s[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Student temp = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].name > temp.name)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}

int partition(Student s[], int low, int high)
{
    int pivot = s[high].rollNum;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (s[j].rollNum <= pivot)
        {
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[high]);
    return i + 1;
}

void quickSort(Student s[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(s, low, high);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

void linearSearch(Student s[], int n, float sgpa)
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i].sgpa == sgpa)
        {
            s[i].display();
            found = true;
        }
    }
    if (!found)
        cout << "Student not found" << endl;
}

void binarySearch(Student s[], int n, string name)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (s[mid].name == name)
        {
            s[mid].display();
            return;
        }
        else if (s[mid].name < name)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Student not found" << endl;
}

void fibonacciSearch(Student s[], int n, float sgpa)
{
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib2 + fib1;

    while (fib < n)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib > 1)
    {
        int i = min(offset + fib2, n - 1);

        if (s[i].sgpa < sgpa)
        {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (s[i].sgpa > sgpa)
        {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else
        {
            s[i].display();
            return;
        }
    }

    if (fib1 && s[offset + 1].sgpa == sgpa)
    {
        s[offset + 1].display();
        return;
    }
    cout << "Student not found" << endl;
}

int main()
{
    int n;
    cout << "Enter number of Students: ";
    cin >> n;
    Student s[n];
    for (int i = 0; i < n; i++)
    {
        s[i].getInfo();
    }
    int ch;
    do
    {
        cout << "1. Searching" << endl;
        cout << "2. Sorting" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int ch1;
            do
            {
                cout << "1. Linear Search" << endl;
                cout << "2. Binary Search" << endl;
                cout << "3. Fibonacci Search" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> ch1;
                switch (ch1)
                {
                case 1:
                {
                    float sgpa;
                    cout << "Enter SGPA: ";
                    cin >> sgpa;
                    linearSearch(s, n, sgpa);
                    break;
                }
                case 2:
                {
                    string name;
                    cout << "Enter Name: ";
                    cin >> name;
                    binarySearch(s, n, name);
                    break;
                }
                case 3:
                {
                    float sgpa;
                    cout << "Enter SGPA: ";
                    cin >> sgpa;
                    fibonacciSearch(s, n, sgpa);
                    break;
                }
                case 4:
                {
                    cout << "Exiting..." << endl;
                    break;
                }
                default:
                {
                    cout << "Invalid choice" << endl;
                }
                }
            } while (ch1 != 4);
            break;
        }
        case 2:
        {
            int ch2;
            do
            {
                cout << "1. Bubble Sort" << endl;
                cout << "2. Insertion Sort" << endl;
                cout << "3. Quick Sort" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> ch2;
                switch (ch2)
                {
                case 1:
                {
                    bubbleSort(s, n);
                    break;
                }
                case 2:
                {
                    insertionSort(s, n);
                    break;
                }
                case 3:
                {
                    quickSort(s, 0, n - 1);
                    break;
                }
                case 4:
                {
                    cout << "Exiting..." << endl;
                    break;
                }
                default:
                {
                    cout << "Invalid choice" << endl;
                }
                }
            } while (ch2 != 4);
            break;
        }
        case 3:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }
    } while (ch != 3);
    return 0;
}
