#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const unsigned int MENU_ENTRIES = 8;

struct menuItemType {
    string food;
    double price;
};

void getData(ifstream&,menuItemType m[],unsigned int);
void showMenu(menuItemType m[],unsigned int);
void printCheck(menuItemType m[]);

int main() {
    menuItemType menuList[MENU_ENTRIES];
    ifstream f;
    f.open("Ch9_Ex4Data.txt");
    getData(f, menuList, MENU_ENTRIES);
    showMenu(menuList, MENU_ENTRIES);
    printCheck(menuList);
    
    
    return 0;
}

void getData(ifstream &f, menuItemType m[], unsigned int size) {
    string temp;
    for (unsigned int i=0; i<size; i++) {
        getline(f,m[i].food);
        f >> m[i].price;
        getline(f,temp);
    }
}
void showMenu(menuItemType m[], unsigned int size) {
    cout << "Welcome to Johnny's Resturant\n----Today's Menu----\n";
    for (unsigned int i=0; i<size; i++) {
        cout << setfill(' ') << i+1 << ": " << left << setw(13) << m[i].food;
        cout << setfill(' ') <<"\t$" << showpoint << setprecision(2) << setw(4) << m[i].price << endl;
    }
}
void printCheck(menuItemType m[]) {
    char input;
    unsigned int item, i=0;
    double tax, total=0.0;
    cout << "You can make up to 8 single order selections\n";
    while (tolower(input)!='n' && i<8) {
        cout << "Do you want to make a selection Y/y (Yes), N/n (No): ";
        cin >> input;
        if (tolower(input)=='n')
            break;
        cout << "Enter item number: ";
        cin >> item;
        total = m[item-1].price + total;
        i++;
    }
    cout << setprecision(3) << setw(4) << total << endl;
    tax = total*0.05;
    cout << "Amount due\t" << setprecision(3) << setw(4) << total + tax << endl;
    cout << "Tax\t\t" << setprecision(3) << setw(4) << tax;
}
