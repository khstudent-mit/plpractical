#include <iostream>
#include <cmath>
#define MAX 20
using namespace std;

class stack {
public:
  string arr[MAX];
  int top;
  stack() { top = -1; }

  bool isempty();
  bool isfull();
  void push(string str);
  string pop();
  int prec(char x);
};

bool stack::isempty() {
  return top == -1;
}

bool stack::isfull() {
  return top == MAX - 1;
}

void stack::push(string str) {
  if (isfull()) {
    cout << "\nStack is full.\n";
  } else {
    top++;
    arr[top] = str;
  }
}

string stack::pop() {
  if (isempty()) {
    cout << "\nStack is empty.\n";
    return "";
  } else {
    string temp = arr[top];
    top--;
    return temp;
  }
}

int stack::prec(char x) {
  if (x == '+' || x == '-') {
    return 1;
  } else if (x == '*' || x == '/') {
    return 2;
  } else if (x == '^') {
    return 3;
  } else {
    return 0;
  }
}

class expression {
public:
  void prefix_to_infix();
  void infix_to_postfix();
  void postfix_eval();
  int operation(int x, int y, char op) {
    switch (op) {
      case '+': 
        return x + y;
      case '-':
        return x - y;
      case '*':
        return x * y;
      case '/':
        return x / y;
      case '^':
        return pow(x, y);
      default:
        return 0; 
    }
  }

  bool isoperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/');
  }

  bool isoperand(char x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9');
  }
};

void expression::prefix_to_infix() {
  stack s;
  string prefix, infix;
  cout << "--------------------------------------------------" <<endl;
  cout << "Enter the prefix expression: ";
  cin >> prefix;
  int length = prefix.length();

  for (int i = length - 1; i >= 0; i--) {
    if (isoperand(prefix[i])) {
      s.push(string(1, prefix[i]));
    } else if (isoperator(prefix[i])) {
      string op1 = s.pop();
      string op2 = s.pop();
      string temp = "(" + op1 + prefix[i] + op2 + ")";
      s.push(temp);
    }
  }

  infix = s.pop();
  cout << "\nInfix expression is: " << infix << endl;
}
void expression::infix_to_postfix() {
  stack s;
  string infix, postfix;
  cout << "--------------------------------------------------" <<endl;
  cout << "Enter the infix expression: ";
  cin >> infix;
  int length = infix.length();

  for (int i = 0; i < length; i++) {
    if (infix[i] == ' ') {
      continue;  // Skip spaces
    }
    if (isoperand(infix[i])) {
      postfix += infix[i];
    } else if (infix[i] == '(') {
      s.push(string(1, infix[i]));
    } else if (infix[i] == ')') {
      while (!s.isempty() && s.arr[s.top][0] != '(') {
        postfix += s.pop();
      }
      s.pop();  // Pop '('
    } else if (isoperator(infix[i])) {
      if (s.isempty()) {
        s.push(string(1, infix[i]));
      } else {
        if (s.prec(infix[i]) == s.prec(s.arr[s.top][0]) && infix[i] == '^') {
          s.push(string(1, infix[i]));  // Right associative for '^'
        } else {
          while (!s.isempty() && s.prec(infix[i]) <= s.prec(s.arr[s.top][0])) {
            postfix += s.pop();
          }
          s.push(string(1, infix[i]));
        }
      }
    }
  }

  while (!s.isempty()) {
    postfix += s.pop();
  }

  cout << "\nPostfix expression is: " << postfix << endl;
}



class stck1 {
public:
  int top;
  int arr[MAX];
  stck1() {
    top = -1;
  }
  void push(int x);
  int pop();
};

void stck1::push(int x) {
  if (top == MAX - 1) {
    cout << "\nStack is full.\n";
  } else {
    top++;
    arr[top] = x;
  }
}

int stck1::pop() {
  if (top == -1) {
    cout << "\nStack is empty.\n";
    return -1;  
  } else {
    int temp = arr[top];
    top--;
    return temp;
  }
}

void expression::postfix_eval() {
    stck1 s;
    string postfix;
    cout << "......." <<endl;
    cout << "Enter the postfix expression: ";
    getline(cin >> ws, postfix);  
    int len = postfix.length();

    for (int i = 0; i < len; i++) {
        if (postfix[i] == ' ') {
            continue;
        } 
        else if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            s.push(num);  
            i--; 
        } 
        else if(isoperator(postfix[i])) {
            int op2 = s.pop(); 
            int op1 = s.pop();  
            int result = operation(op1, op2, postfix[i]); 
            s.push(result);  
        }
    }
    int final_r = s.pop();  
    cout << "\nResult of postfix evaluation: " << final_r << endl;
}


int main() {
  expression exp;
  int choice;
  do{
  	cout << "........" << endl;
  	cout << "Expression Using Stack" << endl;
    cout << "1. Prefix to Infix " << endl;
    cout << "2. Infix to Postfix " << endl;
    cout << "3. Postfix Evaluation " << endl;
    cout << "4. Exit " << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice){
      case 1:
        exp.prefix_to_infix();
        break;
      case 2:
        exp.infix_to_postfix();
        break;
      case 3:
        exp.postfix_eval();
        break;
      case 4:
        cout << "Exiting the program..." << endl;
        break;
      default:
        cout << "Invalid choice. Please try again." << endl;  
      
    }
    
  }while(choice != 4);
  return 0;
}
/*
........
Expression Using Stack
1. Prefix to Infix
2. Infix to Postfix
3. Postfix Evaluation
4. Exit
Enter your choice: 1
--------------------------------------------------
Enter the prefix expression: -+AB*CD

Infix expression is: ((A+B)-(C*D))
........
Expression Using Stack
1. Prefix to Infix
2. Infix to Postfix
3. Postfix Evaluation
4. Exit
Enter your choice: 2
--------------------------------------------------
Enter the infix expression: (A-B)*(C+D)

Postfix expression is: AB-CD+*
........
Expression Using Stack
1. Prefix to Infix
2. Infix to Postfix
3. Postfix Evaluation
4. Exit
Enter your choice: 3
.......
Enter the postfix expression: 5-10*12-2

Stack is empty.

Result of postfix evaluation: 2
........
Expression Using Stack
1. Prefix to Infix
2. Infix to Postfix
3. Postfix Evaluation
4. Exit
Enter your choice:
*/

