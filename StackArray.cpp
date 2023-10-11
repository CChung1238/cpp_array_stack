/*CIS 277 002HY
Professor: Aljamal
Name: Chaemin Chung
*/

#include <iostream>
using namespace std;


//Structure to create the stack
struct stack {
  int stk[10];
  int top;
};

//prototypes 
bool check_int(int i);
bool is_Empty(stack &s);
bool is_full(stack &s);
void s_push(stack &s);
void s_pop(stack &s);
void s_top(stack &s);
void s_purge(stack &s);
void s_display(stack &s);

// main function
int main() {
  cout << "\tStack\n";
  int menuChoice;

  stack stack1;
  s_purge(stack1);
  
  while (true) {
    // display menu
    cout << "------------------------\n"
     << "Menu\n\n"
     << "1 - Push\n"
     << "2 - Pop\n"
     << "3 - Top\n"
     << "4 - Purge\n"
     << "5 - Display\n"
     << "6 - Exit\n"
     << "------------------------\n\n";

    cout << "Select the menu: ";
    cin >> menuChoice;
    cout << endl;
    
    switch(menuChoice) {
      case 1:
      {
        cout << "*Operation: Push*\n";
        s_push(stack1);
        cout << endl;
        break;
      }
      case 2:
      {
        cout << "*Operation: Pop*\n";
        s_pop(stack1);
        cout << endl;
        break;
      }
      case 3:
      {
        cout << "*Operation: Top*\n";
        s_top(stack1);
        cout << endl;
        break;
      }
      case 4:
      {
        cout << "*Operation: Purge*\n";
        s_purge(stack1);
        cout << "Your stack is purged. It's empty now.\n";
        cout << endl;
        break;
      }
      case 5:
      {
        cout << "*Operation: Display*\n";
        s_display(stack1);
        cout << endl;
        break;
      }
      case 6:
      {
        cout << "End.";
        return 0;
        break;
      }
      default:
      {
        cout << "Something went wrong. Please try again.\n";
        cout << "Enter a number between 1 and 6.\n\n";
        break;
      }
    }
  }
}

// function that checks if the input valid
bool check_int(int i)  {
  if (i < 0 || i > 99) {
    cout << "Invalid number. Please enter integer between 0 to 99.\n";
    return false;
  }
  else
    return true;
}

// function hat check if the stack is empty
bool is_Empty(stack &s) {
  if (s.top == -1)  {
    cout << "Stack is empty.\n";
    return true;
  }
  else
    return false;
}

// fuction that check if the stack is full
bool is_full(stack &s) {
  if (s.top >= 9)  {
    cout << "Stack is full.\n";
    return true;
  }
  else
    return false;
}

// function that pushes the integers into the stack
void s_push(stack &s) {
  int i;
  if (is_full(s) == true) {
    cout << "Operation failed. Try again.\n";
  }
  else {
    cout << "Enter the integer which you want to push the stack: ";
    cin >> i;
    if (check_int(i) == true) {
      s.top++;
      s.stk[s.top] = i;
      s_display(s);
    }
  }
}

// function that pops the integers from the stack
void s_pop(stack &s) {
  if (is_Empty(s) == true) {
    cout << "Operation failed. Try agian.\n";
  }
  else {
    cout << s.stk[s.top] << " is popped.\n";
    s.top--;
    s_display(s);
  }
}

// function that displays the top of the stack
void s_top(stack &s) {
  if (is_Empty(s) == true) {
    cout << "Operation failed. Try again.\n";
  }
  else {
    cout  << s.stk[s.top] << " is the top.\n";
    s_display(s);
  }
}


// function that purges the stack
void s_purge(stack &s) {
  s.top = -1;
}

// function that displays the stack
void s_display(stack &s) {
  if (is_Empty(s) == false) {
    cout << "Current stack status: ";
    for (int j = 0; j <= s.top; j++) {
      cout << "[" << s.stk[j] << "] ";    
    }
  }
  cout << "(" << s.top + 1 << "/10)\n";
  cout << "\n";
}