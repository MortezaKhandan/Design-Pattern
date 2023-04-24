#include <iostream>
#include <vector>

// Component interface
class Account {
public:
    virtual void deposit(int amount) = 0;
    virtual int getBalance() const = 0;
};

// Leaf class
class SavingsAccount : public Account {
private:
    int balance;
public:
    SavingsAccount() : balance(0) {}
    void deposit(int amount) override {
        balance += amount;
        std::cout << "Deposited " << amount << " into savings account." << std::endl;
    }
    int getBalance() const override {
        return balance;
    }
};

// Leaf class
class CheckingAccount : public Account {
private:
    int balance;
public:
    CheckingAccount() : balance(0) {}
    void deposit(int amount) override {
        balance += amount;
        std::cout << "Deposited " << amount << " into checking account." << std::endl;
    }
    int getBalance() const override {
        return balance;
    }
};

// Composite class
class Bank : public Account {
private:
    std::vector<Account*> accounts;
public:
    void addAccount(Account* account) {
        accounts.push_back(account);
    }
    void removeAccount(Account* account) {
        // Remove the account from the vector
        accounts.erase(std::remove(accounts.begin(), accounts.end(), account), accounts.end());
    }
    void deposit(int amount) override {
        // Deposit into all accounts
        for (auto account : accounts) {
            account->deposit(amount);
        }
    }
    int getBalance() const override {
        int totalBalance = 0;
        // Sum the balances of all accounts
        for (auto account : accounts) {
            totalBalance += account->getBalance();
        }
        return totalBalance;
    }
};

// Client code
int main() {
    // Create some accounts (leaf objects)
    SavingsAccount savingsAccount;
    CheckingAccount checkingAccount;

    // Create a bank (composite object)
    Bank bank;
    bank.addAccount(&savingsAccount);
    bank.addAccount(&checkingAccount);

    // Deposit into the bank account (which will deposit into all accounts)
    bank.deposit(1000);

    // Print the total balance of all accounts
    std::cout << "Total balance: " << bank.getBalance() << std::endl;

    return 0;
}