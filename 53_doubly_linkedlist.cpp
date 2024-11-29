#include <iostream>
using namespace std;

class node {
  public:
    int roll_no;
    int marks;
    node* next;
    node* prev;

    node() {
        next = NULL;
        prev = NULL;
    }
};

class marklist {
  public:
    node* head;

    marklist() {
        head = NULL;
    }

    int create();
    void display();
    void bubblesort();
    node* swap(node* ptr1, node* ptr2);
    void merge(marklist& other);
};
int marklist::create() {
    node* temp;
    char ch;
    int cnt = 0;

    do {
        cnt++;
        temp = new node;
        cout << "Enter roll number: ";
        cin >> temp->roll_no;
        cout << "Enter marks: ";
        cin >> temp->marks;

        if (head == NULL) {
            head = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

        cout << "Do you want to add more details (Y/N): ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');

    return cnt;
}
void marklist::display() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    node* p = head;
    while (p != NULL) {
        cout << "Roll No: " << p->roll_no << ", Marks: " << p->marks << endl;
        p = p->next;
    }
}
node* marklist::swap(node* ptr1, node* ptr2) {
    if (ptr1->prev == NULL) {
        node* temp = ptr2->next;
        ptr2->next = ptr1;
        ptr2->prev = NULL;
        ptr1->next = temp;
        if (temp != NULL) temp->prev = ptr1;
        ptr1->prev = ptr2;
        head = ptr2;
    } else {
        node* temp = ptr2->next;
        ptr1->prev->next = ptr2;
        ptr2->prev = ptr1->prev;
        ptr2->next = ptr1;
        ptr1->prev = ptr2;
        ptr1->next = temp;
        if (temp != NULL) temp->prev = ptr1;
    }
    return ptr2;
}
void marklist::bubblesort() {
    if (head == NULL) return;

    bool swapped;
    node* p1;
    node* p2 = NULL;

    do {
        swapped = false;
        p1 = head;

        while (p1->next != p2) {
            if (p1->marks > p1->next->marks) {
                p1 = swap(p1, p1->next); 
                swapped = true;
            }
            p1 = p1->next;
        }
        p2 = p1;
    } while (swapped);
}
void marklist::merge(marklist& other) {
    if (head == NULL) {
        head = other.head;
        return;
    }
    if (other.head == NULL) {
        return;
    }

    node* p1 = head;
    node* p2 = other.head;
    node* new_head = NULL;
    node* last = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->marks < p2->marks) {
            if (new_head == NULL) {
                new_head = p1;
                last = p1;
                p1 = p1->next;
            } else {
                last->next = p1;
                p1->prev = last;
                last = p1;
                p1 = p1->next;
            }
        } else {
            if (new_head == NULL) {
                new_head = p2;
                last = p2;
                p2 = p2->next;
            } else {
                last->next = p2;
                p2->prev = last;
                last = p2;
                p2 = p2->next;
            }
        }
    }
    if (p1 != NULL) {
        last->next = p1;
        p1->prev = last;
    } else if (p2 != NULL) {
        last->next = p2;
        p2->prev = last;
    }

    head = new_head;
}

int main() {
    marklist m1, m2;
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Create First Marklist\n";
        cout << "2. Create Second Marklist\n";
        cout << "3. Display First Marklist\n";
        cout << "4. Display Second Marklist\n";
        cout << "5. Sort First Marklist\n";
        cout << "6. Sort Second Marklist\n";
        cout << "7. Merge Both Marklists\n";
        cout << "8. Display Merged Marklist\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter details for the first marklist:" << endl;
                m1.create();
                break;

            case 2:
                cout << "Enter details for the second marklist:" << endl;
                m2.create();
                break;

            case 3:
                cout << "First marklist:" << endl;
                m1.display();
                break;

            case 4:
                cout << "Second marklist:" << endl;
                m2.display();
                break;

            case 5:
                cout << "Sorting the first marklist..." << endl;
                m1.bubblesort();
                break;

            case 6:
                cout << "Sorting the second marklist..." << endl;
                m2.bubblesort();
                break;

            case 7:
                cout << "Merging the two sorted marklists..." << endl;
                m1.merge(m2);
                break;

            case 8:
                cout << "Merged marklist:" << endl;
                m1.display();
                break;

            case 9:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
/*--- MENU ---
1. Create First Marklist
2. Create Second Marklist
3. Display First Marklist
4. Display Second Marklist
5. Sort First Marklist
6. Sort Second Marklist
7. Merge Both Marklists
8. Display Merged Marklist
9. Exit
Enter your choice: 1
Enter details for the first marklist:
Enter roll number: 1
Enter marks: 21
Do you want to add more details (Y/N): y
Enter roll number: 3
Enter marks: 12
Do you want to add more details (Y/N): y
Enter roll number: 2
Enter marks: 14
Do you want to add more details (Y/N): n

--- MENU ---
1. Create First Marklist
2. Create Second Marklist
3. Display First Marklist
4. Display Second Marklist
5. Sort First Marklist
6. Sort Second Marklist
7. Merge Both Marklists
8. Display Merged Marklist
9. Exit
Enter your choice: 2
Enter details for the second marklist:
Enter roll number: 4
Enter marks: 21
Do you want to add more details (Y/N): y
Enter roll number: 6
Enter marks: 32
Do you want to add more details (Y/N): y
Enter roll number: 5
Enter marks: 15
Do you want to add more details (Y/N): n

--- MENU ---
1. Create First Marklist
2. Create Second Marklist
3. Display First Marklist
4. Display Second Marklist
5. Sort First Marklist
6. Sort Second Marklist
7. Merge Both Marklists
8. Display Merged Marklist
9. Exit
Enter your choice: 3
First marklist:
Roll No: 2, Marks: 14
Roll No: 3, Marks: 12
Roll No: 1, Marks: 21

--- MENU ---
1. Create First Marklist
2. Create Second Marklist
3. Display First Marklist
4. Display Second Marklist
5. Sort First Marklist
6. Sort Second Marklist
7. Merge Both Marklists
8. Display Merged Marklist
9. Exit
Enter your choice: 4
Second marklist:
Roll No: 5, Marks: 15
Roll No: 6, Marks: 32
Roll No: 4, Marks: 21

--- MENU ---
1. Create First Marklist
2. Create Second Marklist
3. Display First Marklist
4. Display Second Marklist
5. Sort First Marklist
6. Sort Second Marklist
7. Merge Both Marklists
8. Display Merged Marklist
9. Exit
Enter your choice: 5
Sorting the first marklist...

--- MENU ---
1. Create First Marklist
2. Create Second Marklist
3. Display First Marklist
4. Display Second Marklist
5. Sort First Marklist
6. Sort Second Marklist
7. Merge Both Marklists
8. Display Merged Marklist
9. Exit
Enter your choice: 7
Merging the two sorted marklists...

--- MENU ---
1. Create First Marklist
2. Create Second Marklist
3. Display First Marklist
4. Display Second Marklist
5. Sort First Marklist
6. Sort Second Marklist
7. Merge Both Marklists
8. Display Merged Marklist
9. Exit
Enter your choice: 8
Merged marklist:
Roll No: 3, Marks: 12
Roll No: 2, Marks: 14
Roll No: 5, Marks: 15
Roll No: 1, Marks: 21
Roll No: 6, Marks: 32
Roll No: 4, Marks: 21

--- MENU ---
1. Create First Marklist
2. Create Second Marklist
3. Display First Marklist
4. Display Second Marklist
5. Sort First Marklist
6. Sort Second Marklist
7. Merge Both Marklists
8. Display Merged Marklist
9. Exit
Enter your choice:
*/
