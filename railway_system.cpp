//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node
//{
//public:
//    int age;
//    string passenger_name;
//    string gender;
//    Node *next;
//
//    Node *insert(Node *head, string newpassenger_name, string newgender, int newage, int &currentbookings)
//    {
//        if (currentbookings >= 4)
//        {
//            cout << "Booking limit reached. Cannot book more tickets.\n";
//            return head;
//        }
//        Node *newnode = new Node();
//        newnode->passenger_name = newpassenger_name;
//        newnode->gender = newgender;
//        newnode->age = newage;
//        if (head != NULL)
//        {
//            Node *ptr = head;
//            while (ptr->next != head)
//                ptr = ptr->next;
//
//            newnode->next = head;
//            ptr->next = newnode;
//        }
//        else
//        {
//            newnode->next = newnode;
//            head = newnode;
//        }
//
//        currentbookings++;
//        cout << "\nTicket Booked Successfully: Passenger Name = " << newpassenger_name << ", Gender = " << newgender << ", Age = " << newage << endl;
//        return head;
//    }
//    Node *canceltickets(Node *head, int &currentbookings)
//    {
//        if (head == NULL)
//        {
//            cout << "\nNo reservations to cancel.\n";
//            return head;
//        }
//        Node *ptr = head;
//        Node *temp;
//        if (ptr->next == head)
//        {
//            cout << "\nTicket Canceled Successfully: Passenger Name = " << head->passenger_name << ", Gender = " << head->gender << ", Age = " << head->age;
//            delete head;
//            head = NULL;
//            currentbookings--;
//            return head;
//        }
//        while (ptr->next != head)
//            ptr = ptr->next;
//
//        cout << "\nTicket Canceled Successfully: Passenger Name = " << head->passenger_name << ", Gender = " << head->gender << ", Age = " << head->age;
//        temp = head;
//        head = head->next;
//        ptr->next = head;
//        delete temp;
//        currentbookings--;
//
//        return head;
//    }
//    void displaytickets(Node *head)
//    {
//        if (head == NULL)
//        {
//            cout << "\nNo Tickets to display.\n";
//            return;
//        }
//
//        Node *ptr = head;
//        cout << "\nCurrent Reservations : ";
//
//        do
//        {
//            cout << "\nPassenger Name: " << ptr->passenger_name << ", Gender: " << ptr->gender << ", Age: " << ptr->age;
//            ptr = ptr->next;
//        } while(ptr != head);
//
//        cout << "\n";
//    }
//};
//
//int main()
//{
//    cout << "Maximum no. of Reservations are 4"<< endl;
//
//    Node* head = NULL;
//    Node *cll = new Node();
//    int age, choice, currentbookings = 0;
//    string passenger_name, gender;
//
//    do
//    {
//        cout << "\n1. Book Ticket\n2. Cancel Ticket\n3. Display Tickets\n4. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch(choice)
//        {
//            case 1:
//                if (currentbookings >= 3)
//                {
//                    cout << "Order limit reached. Cannot book more tickets.\n";
//                    break;
//                }
//                cout << "Enter Passenger Name : ";
//                cin >> passenger_name;
//                cout << "Enter Gender : ";
//                cin >> gender;
//                cout << "Enter Age: ";
//                cin >> age;
//                head = cll->insert(head, passenger_name, gender, age, currentbookings);
//                break;
//
//            case 2:
//                head = cll->canceltickets(head, currentbookings);
//                break;
//
//            case 3:
//                cll->displaytickets(head);
//                break;
//
//            case 4:
//                cout << "Exiting...\n";
//                break;
//
//            default:
//                cout << "Invalid choice! Please enter a valid option.\n";
//        }
//
//    } while(choice != 4);
//
//    return 0;
//}

#include <iostream>
using namespace std;

// Function to add two polynomials
void addPolynomials(int poly1[], int poly2[], int result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = poly1[i] + poly2[i];
    }
}

int main() {
    int poly1[] = {5, 0, 10, 6}; // 5 + 0x + 10x^2 + 6x^3
    int poly2[] = {1, 2, 4, 0};  // 1 + 2x + 4x^2 + 0x^3
    int n = 4; // Size of the polynomials
    int result[4]; // To store the result

    // Add the two polynomials
    addPolynomials(poly1, poly2, result, n);

    // Print the resulting polynomial
    cout << "Resultant polynomial: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << "x^" << i;
        if (i != n - 1) {
            cout << " + ";
        }
    }
    cout << endl;

    return 0;
}
