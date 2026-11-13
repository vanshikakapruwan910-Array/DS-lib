#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
using namespace std;

// 1. Branch Hierarchy - Tree
class BranchHierarchy {
public:
    void addBranch(string branch);
    void addSubBranch(string parent, string child);
    void removeBranch(string branch);
    bool searchBranch(string branch);
    void displayBankHierarchy();
    int findBranchLevel(string branch);
    int countBranches();
};

// 2. Account Categorization - Tree
class AccountCategories {
public:
    void addAccountCategory(string category);
    void addSubCategory(string parent, string child);
    bool searchAccountCategory(string category);
    void displayAccountCategories();
};

// 3. Branch Network - Graph
class BranchNetwork {
public:
    void addBankBranch(string branch);
    void connectBranches(string branch1, string branch2);
    void removeBankBranch(string branch);
    vector<string> getConnectedBranches(string branch);
    vector<string> findBranchRoute(string source, string destination);
    vector<string> findShortestBranchRoute(string source, string destination);
    void displayBranchNetwork();
    bool checkNetworkConnectivity();
};

// 4. Inter-Branch Transaction Network - Graph
class TransactionNetwork {
public:
    void addTransactionRoute(string branch1, string branch2);
    bool checkTransactionConnectivity(string branch1, string branch2);
    vector<string> findTransferRoute(string source, string destination);
    vector<string> getConnectedBanks(string branch);
};

// 5. Transaction History - Stack
class TransactionHistory {
public:
    void recordTransaction(string transaction);
    string viewLastTransaction();
    vector<string> getRecentTransactions();
    void undoPendingOperation();
    void clearTransactionHistory();
};

// 6. Customer Service Queue - Queue
class CustomerServiceQueue {
public:
    void addCustomerToQueue(string customerID);
    void serveNextCustomer();
    string viewNextCustomer();
    int getWaitingCustomerCount();
    void removeCustomerFromQueue(string customerID);
};

// 7. Service Requests - Deque
// Excluded as requested.

// 8. Customer and Account Management - Linked List
class CustomerManagement {
public:
    void registerCustomer(string customerID, string name);
    void removeCustomer(string customerID);
    bool searchCustomer(string customerID);
    void updateCustomerDetails(string customerID, string newDetails);
    void createAccount(string customerID, string accountID);
    void closeAccount(string accountID);
    bool searchAccount(string accountID);
    void displayCustomerAccounts(string customerID);
    void displayAllCustomers();
};

// 9. Priority Customer Service - Priority Queue
// Excluded as requested.

#endif