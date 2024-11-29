#include <iostream>
#include <cstring>
using namespace std;

class node 
{
public:
    char pizza_name[33];
    int qty;
    float prize;
    float total_prize;
    node *next;
};

class Cll
{
  public:
    node *head;
    Cll()
    {
        head = NULL;
    }
    void insert(node *temp);
    void display();
    void deleteOrder(const char pizza_name[]);
    
};
void Cll::insert(node *temp){
  node *p;
  if(head == NULL){
    head = temp;
    head->next = head;
  }
  else{
    p = head;
    while(p->next != head){
      p = p->next;
    }
    p->next = temp;
    temp->next = head; 
  }
}

void Cll::deleteOrder(const char pizza_name[]) {
  if(head == NULL) {
    cout << "\n?? No orders to delete.\n";
    return;
  }

  node *curr = head, *prev = NULL;
  do {
    if(strcmp(curr->pizza_name, pizza_name) == 0) {
      if(curr == head && curr->next == head) { 
        head = NULL;
      } else if(curr == head) { 
        node *last = head;
        while(last->next != head) {
          last = last->next;
        }
        head = head->next;
        last->next = head;
      } else { 
        prev->next = curr->next;
      }
      delete curr;
      cout << "\n? Order for " << pizza_name << " has been successfully deleted!\n";
      return;
    }
    prev = curr;
    curr = curr->next;
  } while(curr != head);

  cout << "\n?? No such pizza found to delete!\n";
}

void Cll::display(){
  if(head == NULL){
      cout << "\nNo orders to display.\n";
      return;
  }
  
  node *p = head;
  cout << "\n---------- Current Orders ----------\n";
  do {
    cout << "?? Pizza Name: " << p->pizza_name << endl;
    cout << "?? Quantity: " << p->qty << endl;
    cout << "?? Price per Pizza: Rs " << p->prize << endl;
    cout << "?? Total Price: Rs " << p->total_prize << endl;
    cout << "-------------------------------------\n";
    
    p = p->next;
  } while(p != head);
} 

int main(){
  Cll c;
  node *temp;
  int choice;
  char pizza_to_delete[33];

  do{
    cout << "\n========== Pizza Parlor Menu ==========" << endl;
    cout << "1.  Place Order" << endl;
    cout << "2.  Display Orders" << endl;
    cout << "3.  Delete Order" << endl;
    cout << "4.  Exit" << endl;
    cout << "=======================================" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch(choice){
      case 1:
        temp = new node;
        
        cout << "\nEnter the Pizza Name: ";
        cin >> ws; 
        cin.getline(temp->pizza_name, 33);
        
        cout << "Enter price per pizza: Rs ";
        cin >> temp->prize;

        cout << "Enter quantity: ";
        cin >> temp->qty;

        temp->total_prize = temp->qty * temp->prize;
        
        c.insert(temp);
        cout << "\n? Order placed successfully for " << temp->pizza_name << "!\n";
        break;

      case 2:
        c.display();
        break;

      case 3:
        cout << "\nEnter the pizza name to delete the order: ";
        cin >> ws;
        cin.getline(pizza_to_delete, 33);
        c.deleteOrder(pizza_to_delete);
        break;

      case 4:
        cout << "\nThank you for using the Pizza Parlor system. Goodbye!\n";
        break;

      default:
        cout << "\n?? Invalid choice! Please try again.\n";
    }
    
  }while(choice != 4);

  return 0;
}
/*========== Pizza Parlor Menu ==========
1.  Place Order
2.  Display Orders
3.  Delete Order
4.  Exit
=======================================
Enter your choice: 1

Enter the Pizza Name: Margherita
Enter price per pizza: Rs 120
Enter quantity: 3

? Order placed successfully for Margherita!

========== Pizza Parlor Menu ==========
1.  Place Order
2.  Display Orders
3.  Delete Order
4.  Exit
=======================================
Enter your choice: 1

Enter the Pizza Name: Cheez
Enter price per pizza: Rs 130
Enter quantity:
4

? Order placed successfully for Cheez!

========== Pizza Parlor Menu ==========
1.  Place Order
2.  Display Orders
3.  Delete Order
4.  Exit
=======================================
Enter your choice: 1

Enter the Pizza Name: CornPizza
Enter price per pizza: Rs 120
Enter quantity: 4

? Order placed successfully for CornPizza!

========== Pizza Parlor Menu ==========
1.  Place Order
2.  Display Orders
3.  Delete Order
4.  Exit
=======================================
Enter your choice: 2

---------- Current Orders ----------
?? Pizza Name: Margherita
?? Quantity: 3
?? Price per Pizza: Rs 120
?? Total Price: Rs 360
-------------------------------------
?? Pizza Name: Cheez
?? Quantity: 4
?? Price per Pizza: Rs 130
?? Total Price: Rs 520
-------------------------------------
?? Pizza Name: CornPizza
?? Quantity: 4
?? Price per Pizza: Rs 120
?? Total Price: Rs 480
-------------------------------------

========== Pizza Parlor Menu ==========
1.  Place Order
2.  Display Orders
3.  Delete Order
4.  Exit
=======================================
Enter your choice: 3

Enter the pizza name to delete the order: CornPizza

? Order for CornPizza has been successfully deleted!

========== Pizza Parlor Menu ==========
1.  Place Order
2.  Display Orders
3.  Delete Order
4.  Exit
=======================================
Enter your choice: 2

---------- Current Orders ----------
?? Pizza Name: Margherita
?? Quantity: 3
?? Price per Pizza: Rs 120
?? Total Price: Rs 360
-------------------------------------
?? Pizza Name: Cheez
?? Quantity: 4
?? Price per Pizza: Rs 130
?? Total Price: Rs 520
-------------------------------------

========== Pizza Parlor Menu ==========
1.  Place Order
2.  Display Orders
3.  Delete Order
4.  Exit
=======================================
Enter your choice:
*/
