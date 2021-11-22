/*
NOTE: After I first made this and the GitHub branch, I uploaded to GitHub to find that my files were missing,
so I spent the next 20 minutes looking for the files before giving up... as such, I did this twice... and it sucked...
*/

#include <iostream>

using namespace std;


//check balance normally
void checkBal(int balance) {
    cout << "Balance: " << balance << endl;
}

//check balance, but if terrorist then give them a reference to the balance of the coffee shop
void hackBal(int& balance, int& hBalance, bool isTerrorist) {
    if (isTerrorist) {
        //show coffee shop balance by reference
        cout << "Balance: " << hBalance << endl;
    }
    else {
        //show balance by reference
        cout << "Balance: " << balance << endl;
    }
}

int main()
{
    //set up integers and references for bank accounts
    int terrorBal = 100000;
    int& terrorBalRef = terrorBal;
    int coffeeBal = 100;
    int& coffeeBalRef = coffeeBal;

    //show regular balance
    cout << "Coffee Shop Balance" << endl;
    checkBal(coffeeBal);
    cout << "Terrorist Balance" << endl;
    checkBal(terrorBal);


    //show hacked balance
    cout << "Coffee Shop Hack Balance" << endl;
    hackBal(coffeeBalRef, terrorBalRef, false);
    cout << "Terrorist Hack Balance" << endl;
    hackBal(terrorBalRef, coffeeBalRef, true);

}