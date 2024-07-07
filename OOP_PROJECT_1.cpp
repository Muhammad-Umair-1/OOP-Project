#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account
{
protected:
    string accountID;
    int op, pincode;
    float balance = 10000.0;
    float maxDepositLimit = 10000.0;

public:
    void setData()
    {
        cout << endl << "Enter your account ID: ";
        cin >> accountID;
        cout << "Enter your Pin Code: ";
        cin >> pincode;
    }

    void setOp()
    {
        cout << "Select your operation: " << endl;
        cout << "1) Inquiry" << endl;
        cout << "2) Withdrawal" << endl;
        cout << "3) Deposit" << endl;
        cout << "\nChoose: ";
        cin >> op;
        cout << endl;
        switch (op)
        {
        case 1:
            inquiryOp();
            break;
        case 2:
            withdrawalOp();
            break;
        case 3:
            depositOp();
            break;
        default:
            cout << "Invalid operation selected! " << endl << endl;
            setOp();
            break;
        }
    }

    void inquiryOp()
    {
        cout << "Account Inquiry: " << endl;
        cout << "Your account balance is " << balance << endl;
        setOp();
    }

    void withdrawalOp()
    {
        int op;
        float amount;
        cout << "Withdrawal" << endl;
        if (balance > 0)
        {
            cout << "Withdrawal Options: " << endl;
            cout << "1) 1000 " << endl;
            cout << "2) 2000 " << endl;
            cout << "3) 5000 " << endl;
            cout << "4) 10000 " << endl;
            cout << "5) Enter Manually" << endl;

            cout << endl << "Choose the amount you want to withdraw: " << endl;
            cin >> op;
            cout << endl;

            switch (op)
            {
            case 1:
                amount = 1000.0;
                break;
            case 2:
                amount = 2000.0;
                break;
            case 3:
                amount = 5000.0;
                break;
            case 4:
                amount = 10000.0;
                break;
            case 5:
                cout << endl << "Manual Entry:" << endl << "Enter the amount:" << endl;
                cin >> amount;
                break;
            default:
                cout << "Invalid option selected!" << endl << endl;
                return withdrawalOp();
                break;
            }

            if (amount <= balance)
            {
                balance -= amount;
                cout << endl << "You have successfully withdrawn $" << amount
                     << ". Your remaining balance is $" << balance << ". " << endl;
            }
            else
            {
                cout << endl << "You don't have sufficient funds in your account for this transaction!" << endl;
                return withdrawalOp();
            }
        }
    }

    void depositOp()
    {
        int op;
        float deposit;
        cout << "Deposit Options: " << endl;
        cout << "1) $1000 " << endl;
        cout << "2) $2000 " << endl;
        cout << "3) $5000 " << endl;
        cout << "4) $10000 (Limit)" << endl;
        cout << "5) Enter Manually" << endl;

        cout << endl << "Choose the amount you want to withdraw: " << endl;
        cin >> op;
        cout << endl;

        switch (op)
        {
        case 1:
            deposit = 1000.0;
            break;
        case 2:
            deposit = 2000.0;
            break;
        case 3:
            deposit = 5000.0;
            break;
        case 4:
            deposit = 10000.0;
            break;
        case 5:
            cout << endl << "Manual Entry:" << endl << "Enter the amount:" << endl;
            cin >> deposit;
            break;
        default:
            cout << "Invalid option selected!" << endl << endl;
            return depositOp();
            break;
        }

        if (deposit <= maxDepositLimit)
        {
            balance += deposit;
            cout << endl << "Amount successfully deposited. New balance is $" << balance << endl;
        }
    }

    void getData(string c)
    {
        cout << "Welcome, " << c << "!" << endl;
    }
};

class Customer
{
protected:
    string customerName;
    int age;
    string customerID;

public:
    vector<Account> customerAccounts_vec;
    Customer() {}

    void setData()
    {
        cout << "Enter the your name: ";
        cin >> customerName;
        cout << "Enter the your age: ";
        cin >> age;
        cout << "Enter the your customerID: ";
        cin >> customerID;
    }
    string getCustomerName() { return customerName; }

    int getAge() { return age; }

    string getCustomerID() { return customerID; }

    void getData()
    {
        cout << "Hi, " << customerName << ", welcome!" << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << customerID << endl;
    }
};

class Bank
{
protected:
    string bankName;
    string branch;
    string address;

public:
    vector<Customer> CustomerVec;
    Bank() {}

    void setData()
    {
        cout << "Enter the name of your bank: ";
        cin >> bankName;
        cout << endl;
        cout << "Enter the name of your branch: ";
        cin >> branch;
        cout << endl;
        cout << "Enter the address of your bank: ";
        cin >> address;
    }

    string getBankName() { return bankName; }

    string getBranch() { return branch; }

    string getAddress() { return address; }

    void getData()
    {
        cout << "Bank Name: " << bankName << endl;
        cout << "Branch: " << branch << endl;
        cout << "Address: " << address << endl;
    }
};

int main()
{
    Bank myBank;
    myBank.setData();

    Customer cust1;
    cust1.setData();
    Account acc1;
    acc1.setData();
    cust1.customerAccounts_vec.push_back(acc1);

    Customer cust2;
    cust2.setData();
    Account acc2;
    acc2.setData();
    cust2.customerAccounts_vec.push_back(acc2);

    myBank.CustomerVec.push_back(cust1);
    myBank.CustomerVec.push_back(cust2);

    cout << endl << "Bank Details: " << endl;
    myBank.getData();

    for (auto &cust : myBank.CustomerVec)
    {
        cout << endl << "Customer Details: " << endl;
        cust.getData();
        for (auto &acc : cust.customerAccounts_vec)
        {
            acc.getData(cust.getCustomerName());
        }
    }

    return 0;
}