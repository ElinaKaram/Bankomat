#include <iostream>
using namespace std;

class Bankomat 
{
private:

    int id; 
    int totalAmount; 
    int minWithdrawal; 
    int maxWithdrawal; 
    int denominations[5]; 

public:
    
    void initialize(int atmId, int minWithdraw, int maxWithdraw)
    {
        id = atmId;
        minWithdrawal = minWithdraw;
        maxWithdrawal = maxWithdraw;
        totalAmount = 0;

        for (int i = 0; i < 4; ++i)
        {
            denominations[i] = 0;
        }
    }

    void loadMoney(int count100, int count200, int count500, int count1000) 
    {
        denominations[0] += count100;
        denominations[1] += count200;
        denominations[2] += count500;
        denominations[3] += count1000;
        totalAmount += count100 * 100 + count200 * 200 + count500 * 500 + count1000 * 1000;
    }

    void withdrawMoney(int amount)
    {
        if (amount < minWithdrawal) 
        {
            cout << "The amount is less than the min allowed!" << endl;
            return;
        }

        if (amount > maxWithdrawal)
        {
            cout << "The amount exceeds the max allowed!" << endl;
            return;
        }

        if (amount > totalAmount) 
        {
            cout << "Insufficient funds in ATM!" << endl;
            return;
        }

        totalAmount -= amount;
        cout << "You took it off " << amount << " currencies" << endl;
    }

    string toString() const 
    {
        return "Current amount in ATM: " + toString(totalAmount) + "  currencies";
    }
};

int main()
{
    Bankomat atm;
    atm.initialize(1, 100, 10000); 

    atm.loadMoney(10, 5, 2, 1); 

    atm.withdrawMoney(500); 
    cout << atm.toString() << endl;

    atm.withdrawMoney(15000); 
    cout << atm.toString() << endl;

    return 0;
}