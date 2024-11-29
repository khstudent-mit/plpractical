#include <iostream>
using namespace std;

#define SIZE 20

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
        while (table[index] != -1)
        {
            index = (index + 1) % SIZE;
        }
        table[index] = key;
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

    void search(int key)
    {
        int index = hashFunction(key);
        int startIndex = index;
        while (table[index] != key)
        {
            index = (index + 1) % SIZE;
            if (index == startIndex || table[index] == -1)
            {
                cout << "Key " << key << " not found" << endl;
                return;
            }
        }
        cout << "Key " << key << " found at index " << index << endl;
    }
};

int main()
{
    HashTable ht;
    int data[] = {33, 56, 78, 12, 10, 67, 89, 99, 100, 23, 45, 71, 39, 62, 59, 90, 91, 20, 75, 66};

    for (int i = 0; i < 20; i++)
    {
        ht.insert(data[i]);
    }

    ht.display();

    int key;
    cout << "Enter key to search: ";
    cin >> key;
    ht.search(key);

    return 0;
}
