#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int pnr;
    string passengerName;
    string trainName;
    int seatNumber;
    Node *next;
};

class Sll {
public:
    Node *head;

    Sll() : head(NULL) {}

    ~Sll();
    void create();
    void display();
    void insert();
    void del();
    void search();
    void update();
    void sort();
};

Sll::~Sll() {
    Node *current = head;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

void Sll::create() {
    Node *temp, *p;
    char ch;

    do {
        temp = new Node;
        cout << "Enter PNR: ";
        cin >> temp->pnr;
        cout << "Enter Passenger Name: ";
        cin >> temp->passengerName;
        cout << "Enter Train Name: ";
        cin >> temp->trainName;
        cout << "Enter Seat Number: ";
        cin >> temp->seatNumber;

        temp->next = NULL;
        if (head == NULL) {
            head = temp;
        } else {
            p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }

        cout << "Do you want to add more details (Y/N): ";
        cin >> ch;
        ch = toupper(ch);

    } while (ch == 'Y');
}

void Sll::display() {
    Node *temp = head;
    if (temp == NULL) {
        cout << "No reservation details available." << endl;
        return;
    }

    while (temp != NULL) {
        cout << "PNR: " << temp->pnr << endl;
        cout << "Passenger Name: " << temp->passengerName << endl;
        cout << "Train Name: " << temp->trainName << endl;
        cout << "Seat Number: " << temp->seatNumber << endl;
        cout << "-----------------------------" << endl;
        temp = temp->next;
    }
}

void Sll::insert() {
    Node *temp, *p = head;
    int pos, i = 1;

    cout << "Enter the position to insert the new reservation: ";
    cin >> pos;

    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    temp = new Node;
    cout << "Enter PNR: ";
    cin >> temp->pnr;
    cout << "Enter Passenger Name: ";
    cin >> temp->passengerName;
    cout << "Enter Train Name: ";
    cin >> temp->trainName;
    cout << "Enter Seat Number: ";
    cin >> temp->seatNumber;

    temp->next = NULL;
    if (pos == 1) {
        temp->next = head;
        head = temp;
    } else {
        while (i < pos - 1 && p != NULL) {
            p = p->next;
            i++;
        }
        if (p == NULL) {
            cout << "Position out of range." << endl;
        } else {
            temp->next = p->next;
            p->next = temp;
        }
    }
}

void Sll::del() {
    Node *curr = head, *prev = NULL;
    int pnr;

    cout << "Enter the PNR to be deleted: ";
    cin >> pnr;

    while (curr != NULL) {
        if (curr->pnr == pnr) {
            if (curr == head) {
                head = head->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            cout << "Reservation with PNR " << pnr << " deleted." << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "PNR not found." << endl;
}

void Sll::search() {
    int pnr;
    cout << "Enter the PNR to search: ";
    cin >> pnr;

    Node *temp = head;
    while (temp != NULL) {
        if (temp->pnr == pnr) {
            cout << "\nReservation found:";
            cout << "\nPNR: " << temp->pnr;
            cout << "\nPassenger Name: " << temp->passengerName;
            cout << "\nTrain Name: " << temp->trainName;
            cout << "\nSeat Number: " << temp->seatNumber << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Reservation with PNR " << pnr << " not found." << endl;
}

void Sll::update() {
    int pnr;
    cout << "Enter the PNR to update: ";
    cin >> pnr;

    Node *temp = head;
    while (temp != NULL) {
        if (temp->pnr == pnr) {
            cout << "Enter new Passenger Name: ";
            cin >> temp->passengerName;
            cout << "Enter new Train Name: ";
            cin >> temp->trainName;
            cout << "Enter new Seat Number: ";
            cin >> temp->seatNumber;
            cout << "Reservation details updated." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Reservation with PNR " << pnr << " not found." << endl;
}

void Sll::sort() {
    if (head == NULL || head->next == NULL) {
        return; 
    }

    Node *i, *j;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->pnr > j->pnr) {
                swap(i->pnr, j->pnr);
                swap(i->passengerName, j->passengerName);
                swap(i->trainName, j->trainName);
                swap(i->seatNumber, j->seatNumber);
            }
        }
    }
    cout << "Reservation details sorted by PNR." << endl;
}

int main() {
    Sll s;
    int choice;
    cout << "-------Railway Reservation System--------" << endl;

    do {
        cout << "\nMenu:";
        cout << "\n1. Create reservation details";
        cout << "\n2. Display reservation details";
        cout << "\n3. Insert reservation details";
        cout << "\n4. Delete reservation details";
        cout << "\n5. Update reservation details";
        cout << "\n6. Search reservation details";
        cout << "\n7. Sort reservation details";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.create();
                break;

            case 2:
                s.display();
                break;

            case 3:
                s.insert();
                break;

            case 4:
                s.del();
                break;

            case 5:
                s.update();
                break;

            case 6:
                s.search();
                break;

            case 7:
                s.sort();
                s.display();  
                break;

            case 8:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "\nInvalid choice!";
        }
    } while (choice != 8);

    return 0;
}
/*-------Railway Reservation System--------

Menu:
1. Create reservation details
2. Display reservation details
3. Insert reservation details
4. Delete reservation details
5. Update reservation details
6. Search reservation details
7. Sort reservation details
8. Exit
Enter your choice: 1
Enter PNR: 225
Enter Passenger Name: Abhinav
Enter Train Name: VandeBharat
Enter Seat Number: 78
Do you want to add more details (Y/N): y
Enter PNR: 335
Enter Passenger Name: Uber
Enter Train Name: RajdhaniExpress
Enter Seat Number: 98
Do you want to add more details (Y/N): y
Enter PNR: 325
Enter Passenger Name: Harshad
Enter Train Name: ShatbdiExpress
Enter Seat Number: 336
Do you want to add more details (Y/N): n

Menu:
1. Create reservation details
2. Display reservation details
3. Insert reservation details
4. Delete reservation details
5. Update reservation details
6. Search reservation details
7. Sort reservation details
8. Exit
Enter your choice: 2
PNR: 225
Passenger Name: Abhinav
Train Name: VandeBharat
Seat Number: 78
-----------------------------
PNR: 335
Passenger Name: Uber
Train Name: RajdhaniExpress
Seat Number: 98
-----------------------------
PNR: 325
Passenger Name: Harshad
Train Name: ShatbdiExpress
Seat Number: 336
-----------------------------

Menu:
1. Create reservation details
2. Display reservation details
3. Insert reservation details
4. Delete reservation details
5. Update reservation details
6. Search reservation details
7. Sort reservation details
8. Exit
Enter your choice: 3
Enter the position to insert the new reservation: 2
Enter PNR: 245
Enter Passenger Name: Nagesh
Enter Train Name: RajyaRaniExpress
Enter Seat Number: 312

Menu:
1. Create reservation details
2. Display reservation details
3. Insert reservation details
4. Delete reservation details
5. Update reservation details
6. Search reservation details
7. Sort reservation details
8. Exit
Enter your choice: 2
PNR: 225
Passenger Name: Abhinav
Train Name: VandeBharat
Seat Number: 78
-----------------------------
PNR: 245
Passenger Name: Nagesh
Train Name: RajyaRaniExpress
Seat Number: 312
-----------------------------
PNR: 335
Passenger Name: Uber
Train Name: RajdhaniExpress
Seat Number: 98
-----------------------------
PNR: 325
Passenger Name: Harshad
Train Name: ShatbdiExpress
Seat Number: 336
-----------------------------

Menu:
1. Create reservation details
2. Display reservation details
3. Insert reservation details
4. Delete reservation details
5. Update reservation details
6. Search reservation details
7. Sort reservation details
8. Exit
Enter your choice: 5
Enter the PNR to update: 325
Enter new Passenger Name: Chetanraje
Enter new Train Name: Ahimsa
Enter new Seat Number: 336
Reservation details updated.

Menu:
1. Create reservation details
2. Display reservation details
3. Insert reservation details
4. Delete reservation details
5. Update reservation details
6. Search reservation details
7. Sort reservation details
8. Exit
Enter your choice: 2
PNR: 225
Passenger Name: Abhinav
Train Name: VandeBharat
Seat Number: 78
-----------------------------
PNR: 245
Passenger Name: Nagesh
Train Name: RajyaRaniExpress
Seat Number: 312
-----------------------------
PNR: 335
Passenger Name: Uber
Train Name: RajdhaniExpress
Seat Number: 98
-----------------------------
PNR: 325
Passenger Name: Chetanraje
Train Name: Ahimsa
Seat Number: 336
-----------------------------

Menu:
1. Create reservation details
2. Display reservation details
3. Insert reservation details
4. Delete reservation details
5. Update reservation details
6. Search reservation details
7. Sort reservation details
8. Exit
Enter your choice: 6
Enter the PNR to search: 335

Reservation found:
PNR: 335
Passenger Name: Uber
Train Name: RajdhaniExpress
Seat Number: 98

Menu:
1. Create reservation details
2. Display reservation details
3. Insert reservation details
4. Delete reservation details
5. Update reservation details
6. Search reservation details
7. Sort reservation details
8. Exit
Enter your choice: 7
Reservation details sorted by PNR.
PNR: 225
Passenger Name: Abhinav
Train Name: VandeBharat
Seat Number: 78
-----------------------------
PNR: 245
Passenger Name: Nagesh
Train Name: RajyaRaniExpress
Seat Number: 312
-----------------------------
PNR: 325
Passenger Name: Chetanraje
Train Name: Ahimsa
Seat Number: 336
-----------------------------
PNR: 335
Passenger Name: Uber
Train Name: RajdhaniExpress
Seat Number: 98
-----------------------------

Menu:
1. Create reservation details
2. Display reservation details
3. Insert reservation details
4. Delete reservation details
5. Update reservation details
6. Search reservation details
7. Sort reservation details
8. Exit
Enter your choice:
*/
