#include <string>

using namespace std;

class memberType {
    string fname;
    string lname;
    string ID;
    int booksBought;
    double amountSpent;
    public:
        void setMemberInfo(string,string,string,int,double);
        void printInfo();
};
