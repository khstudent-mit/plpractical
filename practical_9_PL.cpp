#include <iostream>
using namespace std;

class node
{
public:
    string data;
    node *next;
    node *prev;
    node()
    {
        prev = next = NULL;
    }
};

class deQueue
{
public:
    node *front;
    node *rear;

    deQueue()
    {
        front = rear = NULL;
    }
    bool isEmpty()
    {
        return front == NULL && rear == NULL;
    }
    void enqueue(string value)
    {
        node *newNode = new node();
        newNode->data = value;

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }
    void insertAtFront(node *asap)
    {
        if (isEmpty())
        {
            front = rear = asap;
        }
        else
        {
            front->prev = asap;
            asap->next = front;
            front = asap;
        }
    }
    void insertAtRear(node *asap)
    {
        if (isEmpty())
        {
            front = rear = asap;
        }
        else
        {
            rear->next = asap;
            asap->prev = rear;
            rear = asap;
        }
    }
    void delAtFront()
    {
        if (isEmpty())
        {
            cout << "The Queue is empty." << endl;
        }
        else if (front == rear)
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            node *temp = front;
            front = front->next;
            front->prev = NULL;
            delete temp;
        }
    }
    void delAtRear()
    {
        if (isEmpty())
        {
            cout << "The Queue is empty." << endl;
        }
        else if (front == rear)
        {
            delete rear;
            front = rear = NULL;
        }
        else
        {
            node *temp = rear;
            rear = rear->prev;
            rear->next = NULL;
            delete temp;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "The Queue is empty." << endl;
        }
        else
        {
            node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    deQueue q1, q2;
    node *temp;
    int choice;
    int ch2, ch3;
    do
    {
        cout << "1.Input restricted.\n2.Output Restricted.\n3.Exit." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                cout << "1.Insert at rear.\n2.Delete front.\n3.Delete rear.\n4.Display.\n5.Exit." << endl;
                cin >> ch2;
                switch (ch2)
                {
                case 1:
                    temp = new node;
                    cout << "Enter the data." << endl;
                    cin >> temp->data;
                    q1.insertAtRear(temp);
                    break;

                case 2:
                    q1.delAtFront();
                    break;

                case 3:
                    q1.delAtRear();
                    break;

                case 4:
                    q1.display();
                    break;

                case 5:
                    break;

                default:
                    cout << "Enter a valid choice." << endl;
                    break;
                }

            } while (ch2 != 5);
            break;

        case 2:
            do
            {
                cout << "1.Insert at front.\n2.Delete front.\n3.Delete rear.\n4.Display.\n5.Exit." << endl;
                cin >> ch3;
                switch (ch3)
                {
                case 1:
                    temp = new node;
                    cout << "Enter the data." << endl;
                    cin >> temp->data;
                    q2.insertAtFront(temp);
                    break;

                case 2:
                    q2.delAtFront();
                    break;

                case 3:
                    q2.delAtRear();
                    break;

                case 4:
                    q2.display();
                    break;

                case 5:
                    break;

                default:
                    cout << "Enter a valid choice." << endl;
                    break;
                }

            } while (ch3 != 5);
            break;

        case 3:
            break;

        default:
            cout << "Enter a valid choice." << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}
