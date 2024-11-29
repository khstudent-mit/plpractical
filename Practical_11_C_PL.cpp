#include <iostream>
using namespace std;

#define SIZE 11

class HashTable
{
public:
    int table[SIZE];

    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = -1;
        }
    }

    int hashFunction(int key)
    {
        return key % SIZE;
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i * i) % SIZE] != -1)
        {
            i++;
        }
        table[(index + i * i) % SIZE] = key;
    }

    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (table[i] != -1)
                cout << i << " : " << table[i] << endl;
            else
                cout << i << " : NULL" << endl;
        }
    }
};

int main()
{
    HashTable ht;
    int data[] = {25, 15, 10, 5, 11, 19, 16, 36, 42, 28, 32};

    for (int i = 0; i < 11; i++)
    {
        ht.insert(data[i]);
    }

    ht.display();

    return 0;
}
