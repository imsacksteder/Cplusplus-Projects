/* Isabel Sacksteder
CS 162 31145
29.06.20

Project 1: This program keeps a running total of the items added to the user's
shopping cart. Users input a name and price for each item, and can view their
total at any time by selecting "checkout" */

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// constants and functions
const int MAX_CHAR = 20;
void greeting();
double newItem(double ourSum);
double addItem();
bool checkInterest();
bool checkout(int numItems, int runningTotal);


int main (){

  //declare and initialize varialbes
  int numItems = 0;
  int runningTotal = 0;
  int rTotal = 0;
  bool quit;

  greeting();//greet the user

  while (!quit) { //add items until checkout is selected
      if (checkInterest()) {
          rTotal += addItem();
          if (rTotal > 0) {
              numItems++; //increment number of items for nonzero price
              runningTotal = rTotal;
          }
          //print running total
          cout << fixed << showpoint << setprecision(2)
          << "Your running total is now: $" << runningTotal << endl;
      } else {
          quit = checkout(numItems, runningTotal); //checkout, exit loop
      }
  }
  return 0;
}

//greet user function
void greeting() {
    cout << " --------------------------------------------------" << endl;
    cout << "|  Hi I'm ShopBot, your running total calculator!  |" << endl;
    cout << " --------------------------------------------------" << endl;
    return;
}

//selected add another item
double addItem(){

    //declare variables
    int numItems;
    double price;
    double rTotal;
    char item[MAX_CHAR];
    char response;
    bool quit;

    //prompt user to input item name
    cout << "Please enter the name of item: ";
    cin.get(item, 20, '\n');
    cin.ignore(50, '\n');

    //Validate item input
    while(!cin){
        cin.clear();
        cin.ignore(50, '\n');

        cout << "Bad input, enter item." << endl;
        cin.get(item, 20, '\n');
        cin.ignore(50, '\n');
    }

    //prompt user to input item price
    cout << "Please enter the price of " << item << " (in dollars): ";
    cin >> price;
    cin.get();

    //Validate price input
    while(!cin){
        cin.clear();
        cin.ignore(50, '\n');

        cout << "Bad input. Enter price: ";
        cin >> price;
        cin.get(); //remove \n from istream
    }

    //echo data and confirm add item
    cout << "Item: " << item << endl;
    cout << fixed << showpoint << setprecision(2)
    << "Price: $" << price << endl;
    cout << "Are you sure you want to add this item? (y/n)" << endl;
    cin >> response;
    cin.get();

    //Validate char response
    while(!cin) {
        cin.clear();
        cin >> response;
        cout << "Bad input. Enter y/n: ";
        cin >> response;
        cin.get();
    }

    //confirm data entry and return item price
    if (response == 'y') {
        cout << "New item successfully added to cart" << endl;
    } else if (response == 'n') {
        price = 0;
    }
    return price;
}

//ask if user wants to add new item
bool checkInterest() {
  char response;
  cout << "Would you like to add a new item? (y/n)" << endl;
  cin >> response;
  cin.get();

  //Validate char response
  while(!cin) {
      cin.clear();
      cin >> response;
      cout << "Bad input. Enter y/n: ";
      cin >> response;
      cin.get();
  }

  if(response == 'y'){
    return true;
  } else {
    return false;
  }
}

//confirm checkout and display total
bool checkout(int numItems, int runningTotal) {
    char response;
    cout << "Are you sure you want to checkout with " << numItems << " items? (y/n)" << endl;
    cin >> response;
    cin.get();

    //Validate char response
    while(!cin) {
        cin.clear();
        cin >> response;
        cout << "Bad input. Enter y/n: ";
        cin >> response;
        cin.get();
    }

    if (response != 'n') {
        cout << fixed << showpoint << setprecision(2)
        << "Total price: $" << runningTotal << endl;
        return true;
    }
    return false;
}
