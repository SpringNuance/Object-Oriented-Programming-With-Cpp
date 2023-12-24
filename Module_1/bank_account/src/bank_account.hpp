#ifndef ELEC_AS_CPP_BANK
#define ELEC_AS_CPP_BANK
#include <string>

class BankAccount {
public:
    /* BankAccount:
     * the constructor of the BankAccount class, takes the following parameters:
     * the account's owner (string const&), 
     * the account's number (string const&) 
     * and the account's balance (double) which is 0.0 by default. 
     */ 
    BankAccount(std::string const& owner, std::string const& account_number, double balance = 0.0);

    /* GetOwner:
     * Returns the BankAccount's owner as a string, takes no parameters. 
     */
    std::string GetOwner() const;

    /* GetNumber:
     * Returns the BankAccount's number as a string, takes no parameters. 
     */
    std::string GetNumber() const;

    /* GetBalance:
     * Returns the BankAccount's balance as a double, takes no parameters.
     */
    double GetBalance() const;

    /* Deposit:
     * Deposits (stores) the parameter 'amount' to the BankAccount, returns nothing.
     */
    void Deposit(double amount);

    /* Withdraw:
     * Withdraws the parameter amount from the BankAccount. 
     * If the parameter amount is bigger than the BankAccount's current balance, 
     * no withdraw is made and the function returns false. 
     * If the amount is smaller or equal to the current balance 
     * the balance is reduced by the parameter amount and the function returns true.
     */
    bool Withdraw(double amount);

    /* Print:
     * Prints the account information to the standard output stream.
     * The function takes no parameters and returns nothing. 
     * The output format should be like the following (ends with a newline):
     Account num: <account number>, owned by: <owner>, balance: <balance> eur.
     */
    void Print() const;

private:
    std::string owner_;
    std::string account_number_;
    double balance_;
};

/* Transfer:
 * Transfers money from the source account to the target account. 
 * If the parameter amount is bigger than the current balance of the source account, 
 * the function returns false and no transfer is made. 
 * If the amount is valid, that is smaller than the source account's current balance, 
 * the function adds the parameter amount to the target account's balance, 
 * reduces the amount from the source account's balance and returns true.
 */
bool Transfer(BankAccount& source_account, BankAccount& target_account, double amount);

#endif
