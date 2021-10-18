#include <iostream>
#include "memberType.h"

void memberType::setMemberInfo(string ID, string fn, string ln, int bk, double am) {
    memberType::ID = ID;
    memberType::fname = fn;
    memberType::lname = ln;
    memberType::booksBought = bk;
    memberType::amountSpent = am;
}
void memberType::printInfo() {
    cout << "Member ID: " << memberType::ID << endl;
    cout << "Name: " << memberType::fname << " " << memberType::lname << endl;
    cout << "Number of Books Bought: " << memberType::booksBought << endl;
    cout << "Total Amount Spent: " << memberType::amountSpent << endl;
}
