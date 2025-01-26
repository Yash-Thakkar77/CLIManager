#include <iostream>
#include <string>
using namespace std;

class node;
node *start = NULL;
node *current_node = NULL;

class node {
public:
  string info;
  node *next;
  node *prev;

  node *create_node() {
    node *temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return (temp);
  }

  void add_command(string data) {
    node *newnode, *temp;
    newnode = create_node();
    newnode->info = data;

    if (start == NULL) {
      start = newnode;
      current_node = newnode;
    } else {
      temp = start;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newnode;
      newnode->prev = temp;
      current_node = newnode;
    }
  }

  void print_history() {
    node *temp = start;
    while (temp != NULL) {
      cout << temp->info << endl;
      temp = temp->next;
    }
    cout << endl;
  }

  void clear_history() {
    node *temp = start;
    while (temp != NULL) {
      node *temp2 = temp;
      temp = temp->next;
      delete temp2;
    }
    start = NULL;
    current_node = NULL;
  }
};

void navigate_up() {
  if (current_node == NULL) {
    cout << "No commands" << endl;
    return;
  }

  if (current_node->prev != NULL) {
    current_node = current_node->prev;
    cout << current_node->info << endl;
  } else {
    // Handle the case when navigating up from the end of the list
    cout << "No commands" << endl;
  }
}

void navigate_down() {
  if (current_node == NULL) {
    cout << "No commands" << endl;
    return;
  }

  if (current_node->next != NULL) {
    current_node = current_node->next;
    cout << current_node->info << endl;
  } else {
    cout << "No commands" << endl;
  }
}
int main() {
  node n1;
  int x = 1;
  string choice;
  while (x == 1) {
    cout << "Enter a choice (w, s, history, history -c, or any other text): ";
    getline(cin, choice);

    // Sanitize input by removing leading and trailing spaces
    choice.erase(0, choice.find_first_not_of(" "));
    choice.erase(choice.find_last_not_of(" ") + 1);

    if (choice == "w" || choice == "W") {
      navigate_up();
    } else if (choice == "s" || choice == "S") {
      navigate_down();
    } else if (choice == "history") {
      n1.add_command(choice);
      n1.print_history();
    } else if (choice == "history -c") {
      n1.clear_history();
    } else {
      n1.add_command(choice);
    }
  }
}
