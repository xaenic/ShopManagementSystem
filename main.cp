#include <iostream>
#include <cctype>
#include <string>
#include <conio.h>
#include <iomanip>
using namespace std;

int main() {

  bool error {false};
  // DataBase
  string items[500];
  double prices[500];
  int quantity[500];
  // for customers
  string customerName[500];
  string customerPass[500];
  int customerNumber[500];
  float customerCredits[500];
  int phonenumber, customers=0;
  string password;
  string name;

//admin
string admin_pass = "admin123";
  string bought[500];
  int total=0;
  char menu;
  //Validation
  int addAnother = 1,currentSize=0, empty=0;

  int exit=1,removed =0,update,select;

  //validation for customer's prompt
  char prompt;

  //loop until program is terminated
  while(true) {
  char userType,todo,regular;
  system ("CLS");
  cout << " User code type:\n\t\tA.Admin\n\t\tB.Customer"<<endl;
  cout << " ---> ";
  cin >> userType;

  switch(towlower(userType)) {
    case 'a':
      system ("CLS");
      cout << "Enter admin password: ";
      cin.ignore();
      getline(cin, password);
      if(password == admin_pass) {
      // loop until admin choose exit
      while(true) {
      system ("CLS");
      cout << "\t\t\t---------ADMIN DASHBOARD---------" << endl;
      cout << " Things you can do: "<<endl;
      cout << "\tA. Add Items\t\tB. Remove item\t\tE. Exit\n\tC. Update Pirce \tD. Show items'\n";
      cout << " ---> ";
      cin >> todo;

      switch(towlower(todo)){

          // if the user wants to add more items in the menu
        case 'a':
          system ("CLS");
          // if(removed > 0) {
          //   currentSize++;
          // }
          // add items maximum upto 500 only
          for (; currentSize <= 500; currentSize++ ) {
          cout << "Total Items: "<< currentSize << "/500\n";
          cout << "Enter item name: ";
          cin.ignore();
          getline(cin, items[currentSize]);
          cout << "Enter item price: ";
          cin >> prices[currentSize];
          cout << "Enter item quantity: ";
          cin >> quantity[currentSize];
          cout << "Enter any number to continue, otherwise 0 to exit\n";
          cout << " ---> ";
          cin >> addAnother;
          empty++;

          system("CLS");
          if(addAnother == 0) {
            currentSize++;
            break;
          }
        }
        break;
        case 'b':
          system ("CLS");
          cout << "\t\t\t\t\t========================\n";
          cout << "\t\t\t\t\t|     DELETE A ITEM    |\n";
          cout << "\t\t\t\t\t========================\n";
          if(empty > 0) {

            cout << setw(4) << "No." << setw(20) << "Item" << setw(20) << "Price" << setw(20) << "Stocks"
               << endl << endl;
            cout << setprecision(2) << fixed;
            for(int i = 0; i < currentSize; i++) {
              cout << setw(4) << i+1 << setw(20) << items[i] << setw(20) << prices[i] << setw(20)<< quantity[i] << endl;
            }
            cout << "\nEnter any number less than 1 to cancel\nEnter the number of the item to remove\n";
            cout << " ---> ";
            cin >> select;
            if(select < 1) {
              break;
            }
            select = select -1;

            // for(int i = 0; i <= currentSize; i++) {
            //   // remove the selected items along with its prices
            //   if(i >= del && del != currentSize) {
            //
            //
            //     items[i] = items[i+1];
            //     prices[i] = prices[i+1];
            //   }
            // }

            // for(int i=0; i < currentSize; i++) {
            //
            //   if(i == del) {
            //     for(int j = i;  j <= (currentSize - 1); j++) {
            //       items[j] = items[j+1];
            //     }
            //   }
            // }


            // final
            for(int i=select; i < currentSize; i++) {
                  items[i] = items[i+1];
                  prices[i] = prices[i+1];
                  quantity[i] = quantity[i+1];
            }

            currentSize --;
            empty--;
            removed = 1; // this is to determine if there's an item that is removed

            // shows the current items on the list.
            if(empty >0) {
              cout << setw(4) << "No." << setw(20) << "Item" << setw(20) << "Price" << setw(20) << "Stocks"
                 << endl << endl;
              cout << setprecision(2) << fixed;
              for(int i = 0; i < currentSize; i++) {
                cout << setw(4) << i+1 << setw(20) << items[i] << setw(20) << prices[i] << setw(20)<< quantity[i] << endl;
              }
            } else {
              cout << "\t\t\t\tThere are no items are on the list yet.\n";
            }
          } else {
            cout << "\t\t\t\tThere are no items are on the list yet\n";}
          break;

        case 'c':
        cout << "\t\t\t\t\t========================\n";
        cout << "\t\t\t\t\t|     UPDATE A ITEM     |\n";
        cout << "\t\t\t\t\t========================\n";
          if(empty > 0) {
            cout <<"\t\t" << setw(4) << "No." << setw(20) << "Item" << setw(20) << "Price" << setw(20) << "Stocks"
               << endl << endl;
            cout << setprecision(2) << fixed;
            for(int i = 0; i < currentSize; i++) {
              cout <<"\t\t" << setw(4) << i+1 << setw(20) << items[i] << setw(20) << prices[i] << setw(20)<< quantity[i] << endl;
            }
            cout<< "\nEnter -1 to cancel\nSelect the item number to update its price: ";
            cin >> select;
            if(select < 1) {
              break;
            }
            cout << "Do you want to update the item's?:\n\tA.Name\n\tB.Price\n\tC.Quantity"<<endl;
            cin >> menu;
            //local initialization
            string d,e,selected;
            int up,b;
            bool no {true};
            selected = items[select - 1];
            while(no) {

            switch(towlower(menu)) {

              case 'a':
                    cout <<"Okay!\nEnter the updated name: ";
                    cin.ignore();
                    getline(cin, d);
                    items[select-1] = d;
                    no = false;
                    cout << "\n\t\t\t\tYou have successfully updated the name of " << selected << " to " << d << endl;
                    break;
              case 'b':
                    cout <<"Okay!\nEnter the updated price: ";
                    cin >> up;
                    prices[select-1] = up;
                    no = false;
                    cout << "\n\t\t\t\tYou have successfully updated the price of " << selected << " to " << up << endl;
                    break;
              case 'c':
                    cout <<"Okay!\nEnter the updated quantity: ";
                    cin >> up;
                    quantity[select-1] = up;
                    no = false;
                    cout << "\n\t\t\t\tYou have successfully updated the quantity of " << selected << " to " << up<< endl;
                    break;
              default:
                    cout << "\n\t\t\t\tInvalid input\n";
            }
          }

          }else
            cout << "\t\t\t\tThere are no items are on the list yet.\n";
          break;
        case 'd':
          system ("CLS");
          cout << "\t\t\t\t\t=========================\n";
          cout << "\t\t\t\t\t|     SHOP ITEM LISTS    |\n";
          cout << "\t\t\t\t\t=========================\n\n";
          cout <<"\t\t"<< setw(4) << "No." << setw(20) << "Item" << setw(20) << "Price" << setw(20) << "Stocks"<< endl << endl;
          cout << setprecision(2) << fixed;
          if(empty > 0) {
            for(int i =0; i < currentSize; i++) { //iterating the list.
              if (prices[i] == 0) {
                cout << "\n\t\t\t\tThere are no items are on the list yet.\n\n";
              }else {
                cout <<"\t\t" << setw(4) << i+1 << setw(20) << items[i] << setw(20) <<prices[i] << setw(20)<< quantity[i] << endl;
              }
          }
          }else
            cout << "\n\t\t\t\tThere are no items are on the list yet.\n";
          break;
        case 'e':
          system("CLS");
          goto exit_admin;
          break;
        default:
          break;
      }

      cout << "\nPress Enter to Continue";
      getch();
      system("CLS");
    }
  }else {
    system ("CLS");
    cout << "Incorrect Password";
    cout << "\nPress Enter to Continue";
    getch();
  }
    exit_admin: ;
      // end of admin dashboard
      break;
    case 'b':

      cout << "-------Chorlan's Store-------" << endl;
      cout << "\nDo you have an account?(Y/N): ";
      cin >> regular;

      switch(towlower(regular)) {
        case 'y':
          cout << "Enter your phonenumber: ";
          cin >> phonenumber;
          cout << "Enter your password: ";
          cin >>  password;
          //check if user exist
          for(int i = 0; i <= customers; i++) {
              if(customerNumber[i] == phonenumber && customerPass[i] == password) {
                system ("CLS");

                cout << "\t\t-----Welcome back !" << customerName[i] << "-----"<<endl;
                if(empty > 0) {
                  cout << "\t\t\t\t\t=========================\n";
                  cout << "\t\t\t\t\t|     SHOP ITEM LISTS    |\n";
                  cout << "\t\t\t\t\t=========================\n\n";
                  int count=0;
                  int selected;
                  do  {
                    cout <<"\t\t" << setw(4) << "No." << setw(20) << "Item" << setw(20) << "Price" << setw(20) << "Stocks"
                       << endl << endl;
                    cout << setprecision(2) << fixed;
                    for(int i = 0; i < currentSize; i++) {
                      cout <<"\t\t" << setw(4) << i+1 << setw(20) << items[i] << setw(20) << prices[i] << setw(20)<< quantity[i] << endl;
                    }

                    cout << "Enter the number of the item you want to buy: ";
                    cin >> selected;

                    bought[count] = items[selected-1];
                    total += prices[selected-1];
                    count++;
                    cout << "\n\t\t\tDo you want to buy more?(Y/N): ";
                    cin >> prompt;

                  }while(towlower(prompt) == 'y');

                  for(int j=0; j < count; j++) {
                    cout << j+1 << " . " << bought[j] << endl;
                  }
                  cout << "Total pay: " << total <<endl;
                  break;
                }else {
                  cout << "There are no items available yet. Please comeback later\n";
                }
                break;


              } else if(customerNumber[i] != phonenumber && i == customers) {
                  cout << "Invalid phonenumber/password.\n";

                  break;
              }
          }

          cout << "\nPress Enter to Continue";
          getch();
          // end
          break;
          case 'n':


            cout << "---Registration--- \n";
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your phone number: ";
            cin >> phonenumber;
            cout << "Enter your desired password: ";
            cin >> password;

            for(int i = 0; i <= customers; i++) {
              if(customerNumber[i] == phonenumber){
                error = true;
                cout << "\nPhone number already exist\n";
            }
          }
            if(!error) {
              customerPass[customers] = password;
              customerNumber[customers] = phonenumber;
              customerName[customers] = name;
              customerCredits[customers]  = 0;
              system("CLS");
              cout << "\t\t\t\n You have successfully registered.\n\n";
              customers++;
            }
            error = false;
            cout << "\nPress Enter to Continue";
            getch();
          // end of customer interface
          break;
          default:
            cout <<"\nInvalid input.\n";
      }
      break;
    default:
      cout << "\nInvalid input";
      break;
  }

 }

}
