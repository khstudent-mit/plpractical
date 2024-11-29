#include <iostream>
using namespace std;

#define SIZE 6

class HashTable
{
public:
    int hashTable[SIZE];

    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            hashTable[i] = -1;
        }
    }

    int hashFunction(int key)
    {
        return key % SIZE;
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        while (hashTable[index] != -1)
        {
            index = (index + 1) % SIZE;
        }
        hashTable[index] = key;
    }

    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (hashTable[i] != -1)
                cout << i << " : " << hashTable[i] << endl;
            else
                cout << i << " : NULL" << endl;
        }
    }

    void search(int key)
    {
        int index = hashFunction(key);
        int startIndex = index;
        while (hashTable[index] != key)
        {
            index = (index + 1) % SIZE;
            if (index == startIndex || hashTable[index] == -1)
            {
                cout << "Key not found" << endl;
                return;
            }
        }
        cout << "Key found at index " << index << endl;
    }
};

int main()
{
    HashTable ht;
    int choice, key;

    while (true)
    {
        cout << "1. Insert\n2. Display\n3. Search\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            ht.display();
            break;
        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            ht.search(key);
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
