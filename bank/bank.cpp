
#include "bank.h"
#include <iostream>
#include <algorithm>

using namespace std;

// =====================================================
// 1. BRANCH HIERARCHY - TREE
// =====================================================

struct BranchNode {
    string name;
    BranchNode* parent;
    vector<BranchNode*> children;

    BranchNode(string n) {
        name = n;
        parent = nullptr;
    }
};

static vector<BranchNode*> branchRoots;

static BranchNode* findBranchNode(BranchNode* root, string name) {
    if (!root)
        return nullptr;

    if (root->name == name)
        return root;

    for (BranchNode* child : root->children) {
        BranchNode* result = findBranchNode(child, name);
        if (result)
            return result;
    }

    return nullptr;
}

static BranchNode* findAnyBranch(string name) {
    for (BranchNode* root : branchRoots) {
        BranchNode* result = findBranchNode(root, name);
        if (result)
            return result;
    }
    return nullptr;
}

static void displayBranchTree(BranchNode* root, int level) {
    if (!root)
        return;

    for (int i = 0; i < level; i++)
        cout << "  ";

    cout << "|-- " << root->name << '\n';

    for (BranchNode* child : root->children)
        displayBranchTree(child, level + 1);
}

static int countBranchTree(BranchNode* root) {
    if (!root)
        return 0;

    int count = 1;

    for (BranchNode* child : root->children)
        count += countBranchTree(child);

    return count;
}

static void deleteBranchTree(BranchNode* root) {
    if (!root)
        return;

    for (BranchNode* child : root->children)
        deleteBranchTree(child);

    delete root;
}

void BranchHierarchy::addBranch(string branch) {
    if (findAnyBranch(branch)) {
        cout << "Branch already exists.\n";
        return;
    }

    branchRoots.push_back(new BranchNode(branch));
    cout << "Branch added successfully.\n";
}

void BranchHierarchy::addSubBranch(string parent, string child) {
    BranchNode* p = findAnyBranch(parent);

    if (!p) {
        cout << "Parent branch not found.\n";
        return;
    }

    if (findAnyBranch(child)) {
        cout << "Branch already exists.\n";
        return;
    }

    BranchNode* c = new BranchNode(child);
    c->parent = p;
    p->children.push_back(c);

    cout << "Sub-branch added successfully.\n";
}

void BranchHierarchy::removeBranch(string branch) {
    BranchNode* target = findAnyBranch(branch);

    if (!target) {
        cout << "Branch not found.\n";
        return;
    }

    if (!target->parent) {
        auto it = find(branchRoots.begin(), branchRoots.end(), target);

        if (it != branchRoots.end())
            branchRoots.erase(it);
    } else {
        BranchNode* parent = target->parent;
        auto& children = parent->children;

        children.erase(
            remove(children.begin(), children.end(), target),
            children.end()
        );
    }

    deleteBranchTree(target);
    cout << "Branch removed successfully.\n";
}

bool BranchHierarchy::searchBranch(string branch) {
    return findAnyBranch(branch) != nullptr;
}

void BranchHierarchy::displayBankHierarchy() {
    if (branchRoots.empty()) {
        cout << "Bank hierarchy is empty.\n";
        return;
    }

    cout << "\n--- Bank Branch Hierarchy ---\n";

    for (BranchNode* root : branchRoots)
        displayBranchTree(root, 0);
}

int BranchHierarchy::findBranchLevel(string branch) {
    BranchNode* node = findAnyBranch(branch);

    if (!node)
        return -1;

    int level = 0;

    while (node->parent) {
        level++;
        node = node->parent;
    }

    return level;
}

int BranchHierarchy::countBranches() {
    int count = 0;

    for (BranchNode* root : branchRoots)
        count += countBranchTree(root);

    return count;
}


// =====================================================
// 2. ACCOUNT CATEGORIZATION - TREE
// =====================================================

struct CategoryNode {
    string name;
    CategoryNode* parent;
    vector<CategoryNode*> children;

    CategoryNode(string n) {
        name = n;
        parent = nullptr;
    }
};

static vector<CategoryNode*> categoryRoots;

static CategoryNode* findCategoryNode(
    CategoryNode* root, string name) {

    if (!root)
        return nullptr;

    if (root->name == name)
        return root;

    for (CategoryNode* child : root->children) {
        CategoryNode* result = findCategoryNode(child, name);

        if (result)
            return result;
    }

    return nullptr;
}

static CategoryNode* findAnyCategory(string name) {
    for (CategoryNode* root : categoryRoots) {
        CategoryNode* result = findCategoryNode(root, name);

        if (result)
            return result;
    }

    return nullptr;
}

static void displayCategoryTree(CategoryNode* root, int level) {
    if (!root)
        return;

    for (int i = 0; i < level; i++)
        cout << "  ";

    cout << "|-- " << root->name << '\n';

    for (CategoryNode* child : root->children)
        displayCategoryTree(child, level + 1);
}

void AccountCategories::addAccountCategory(string category) {
    if (findAnyCategory(category)) {
        cout << "Category already exists.\n";
        return;
    }

    categoryRoots.push_back(new CategoryNode(category));

    cout << "Account category added.\n";
}

void AccountCategories::addSubCategory(
    string parent, string child) {

    CategoryNode* p = findAnyCategory(parent);

    if (!p) {
        cout << "Parent category not found.\n";
        return;
    }

    if (findAnyCategory(child)) {
        cout << "Category already exists.\n";
        return;
    }

    CategoryNode* c = new CategoryNode(child);
    c->parent = p;
    p->children.push_back(c);

    cout << "Sub-category added.\n";
}

bool AccountCategories::searchAccountCategory(string category) {
    return findAnyCategory(category) != nullptr;
}

void AccountCategories::displayAccountCategories() {
    if (categoryRoots.empty()) {
        cout << "No account categories available.\n";
        return;
    }

    cout << "\n--- Account Categories ---\n";

    for (CategoryNode* root : categoryRoots)
        displayCategoryTree(root, 0);
}


// =====================================================
// 3. BRANCH NETWORK - UNDIRECTED GRAPH
// =====================================================

static vector<string> bankBranches;
static vector<vector<int>> branchAdjacency;

static int findBankBranchIndex(string branch) {
    for (int i = 0; i < (int)bankBranches.size(); i++) {
        if (bankBranches[i] == branch)
            return i;
    }

    return -1;
}

void BranchNetwork::addBankBranch(string branch) {
    if (findBankBranchIndex(branch) != -1) {
        cout << "Branch already exists in network.\n";
        return;
    }

    bankBranches.push_back(branch);
    branchAdjacency.push_back(vector<int>());

    cout << "Branch added to network.\n";
}

void BranchNetwork::connectBranches(
    string branch1, string branch2) {

    int u = findBankBranchIndex(branch1);
    int v = findBankBranchIndex(branch2);

    if (u == -1 || v == -1) {
        cout << "One or both branches not found.\n";
        return;
    }

    if (u == v) {
        cout << "Cannot connect a branch to itself.\n";
        return;
    }

    if (find(branchAdjacency[u].begin(),
             branchAdjacency[u].end(), v)
        != branchAdjacency[u].end()) {
        cout << "Connection already exists.\n";
        return;
    }

    branchAdjacency[u].push_back(v);
    branchAdjacency[v].push_back(u);

    cout << "Branches connected successfully.\n";
}

void BranchNetwork::removeBankBranch(string branch) {
    int index = findBankBranchIndex(branch);

    if (index == -1) {
        cout << "Branch not found.\n";
        return;
    }

    bankBranches.erase(bankBranches.begin() + index);
    branchAdjacency.erase(branchAdjacency.begin() + index);

    for (auto& neighbors : branchAdjacency) {
        for (int& v : neighbors) {
            if (v > index)
                v--;
        }

        neighbors.erase(
            remove(neighbors.begin(), neighbors.end(), index),
            neighbors.end()
        );
    }

    cout << "Branch removed from network.\n";
}

vector<string> BranchNetwork::getConnectedBranches(string branch) {
    vector<string> result;

    int index = findBankBranchIndex(branch);

    if (index == -1)
        return result;

    for (int v : branchAdjacency[index])
        result.push_back(bankBranches[v]);

    return result;
}

// DFS traversal to find a route
vector<string> BranchNetwork::findBranchRoute(
    string source, string destination) {

    vector<string> result;

    int start = findBankBranchIndex(source);
    int end = findBankBranchIndex(destination);

    if (start == -1 || end == -1)
        return result;

    vector<bool> visited(bankBranches.size(), false);
    vector<int> parent(bankBranches.size(), -1);

    vector<int> st;

    st.push_back(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.back();
        st.pop_back();

        if (u == end)
            break;

        for (int v : branchAdjacency[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                st.push_back(v);
            }
        }
    }

    if (!visited[end])
        return result;

    for (int v = end; v != -1; v = parent[v])
        result.push_back(bankBranches[v]);

    reverse(result.begin(), result.end());

    return result;
}

// BFS traversal to find shortest route
vector<string> BranchNetwork::findShortestBranchRoute(
    string source, string destination) {

    vector<string> result;

    int start = findBankBranchIndex(source);
    int end = findBankBranchIndex(destination);

    if (start == -1 || end == -1)
        return result;

    vector<bool> visited(bankBranches.size(), false);
    vector<int> parent(bankBranches.size(), -1);

    vector<int> q(bankBranches.size());

    int front = 0, rear = 0;

    q[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int u = q[front++];

        if (u == end)
            break;

        for (int v : branchAdjacency[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q[rear++] = v;
            }
        }
    }

    if (!visited[end])
        return result;

    for (int v = end; v != -1; v = parent[v])
        result.push_back(bankBranches[v]);

    reverse(result.begin(), result.end());

    return result;
}

void BranchNetwork::displayBranchNetwork() {
    if (bankBranches.empty()) {
        cout << "Branch network is empty.\n";
        return;
    }

    cout << "\n--- Branch Network ---\n";

    for (int i = 0; i < (int)bankBranches.size(); i++) {
        cout << bankBranches[i] << " -> ";

        for (int v : branchAdjacency[i])
            cout << bankBranches[v] << " ";

        cout << '\n';
    }
}

bool BranchNetwork::checkNetworkConnectivity() {
    int n = bankBranches.size();

    if (n == 0)
        return false;

    vector<bool> visited(n, false);
    vector<int> st;

    st.push_back(0);
    visited[0] = true;

    while (!st.empty()) {
        int u = st.back();
        st.pop_back();

        for (int v : branchAdjacency[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push_back(v);
            }
        }
    }

    for (bool value : visited) {
        if (!value)
            return false;
    }

    return true;
}


// =====================================================
// 4. INTER-BRANCH TRANSACTION NETWORK - GRAPH
// =====================================================

static vector<string> transactionBranches;
static vector<vector<int>> transactionAdjacency;

static int findTransactionBranch(string branch) {
    for (int i = 0; i < (int)transactionBranches.size(); i++) {
        if (transactionBranches[i] == branch)
            return i;
    }

    return -1;
}

static int addTransactionBranchIfMissing(string branch) {
    int index = findTransactionBranch(branch);

    if (index != -1)
        return index;

    transactionBranches.push_back(branch);
    transactionAdjacency.push_back(vector<int>());

    return (int)transactionBranches.size() - 1;
}

void TransactionNetwork::addTransactionRoute(
    string branch1, string branch2) {

    if (branch1 == branch2) {
        cout << "Invalid transaction route.\n";
        return;
    }

    int u = addTransactionBranchIfMissing(branch1);
    int v = addTransactionBranchIfMissing(branch2);

    if (find(transactionAdjacency[u].begin(),
             transactionAdjacency[u].end(), v)
        != transactionAdjacency[u].end()) {
        cout << "Transaction route already exists.\n";
        return;
    }

    transactionAdjacency[u].push_back(v);
    transactionAdjacency[v].push_back(u);

    cout << "Transaction route added.\n";
}

bool TransactionNetwork::checkTransactionConnectivity(
    string branch1, string branch2) {

    int start = findTransactionBranch(branch1);
    int end = findTransactionBranch(branch2);

    if (start == -1 || end == -1)
        return false;

    vector<bool> visited(transactionBranches.size(), false);
    vector<int> st;

    st.push_back(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.back();
        st.pop_back();

        if (u == end)
            return true;

        for (int v : transactionAdjacency[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push_back(v);
            }
        }
    }

    return false;
}

vector<string> TransactionNetwork::findTransferRoute(
    string source, string destination) {

    vector<string> result;

    int start = findTransactionBranch(source);
    int end = findTransactionBranch(destination);

    if (start == -1 || end == -1)
        return result;

    vector<bool> visited(transactionBranches.size(), false);
    vector<int> parent(transactionBranches.size(), -1);

    vector<int> q(transactionBranches.size());

    int front = 0, rear = 0;

    q[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int u = q[front++];

        if (u == end)
            break;

        for (int v : transactionAdjacency[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q[rear++] = v;
            }
        }
    }

    if (!visited[end])
        return result;

    for (int v = end; v != -1; v = parent[v])
        result.push_back(transactionBranches[v]);

    reverse(result.begin(), result.end());

    return result;
}

vector<string> TransactionNetwork::getConnectedBanks(string branch) {
    vector<string> result;

    int index = findTransactionBranch(branch);

    if (index == -1)
        return result;

    for (int v : transactionAdjacency[index])
        result.push_back(transactionBranches[v]);

    return result;
}


// =====================================================
// 5. TRANSACTION HISTORY - STACK
// =====================================================

static vector<string> transactionHistoryStack;

void TransactionHistory::recordTransaction(string transaction) {
    transactionHistoryStack.push_back(transaction);

    cout << "Transaction recorded.\n";
}

string TransactionHistory::viewLastTransaction() {
    if (transactionHistoryStack.empty())
        return "";

    return transactionHistoryStack.back();
}

vector<string> TransactionHistory::getRecentTransactions() {
    vector<string> result;

    for (int i = (int)transactionHistoryStack.size() - 1;
         i >= 0; i--) {

        result.push_back(transactionHistoryStack[i]);
    }

    return result;
}

void TransactionHistory::undoPendingOperation() {
    if (transactionHistoryStack.empty()) {
        cout << "No pending operation to undo.\n";
        return;
    }

    cout << "Removing last recorded operation: "
         << transactionHistoryStack.back() << '\n';

    transactionHistoryStack.pop_back();
}

void TransactionHistory::clearTransactionHistory() {
    transactionHistoryStack.clear();

    cout << "Transaction history cleared.\n";
}


// =====================================================
// 6. CUSTOMER SERVICE QUEUE - FIFO QUEUE
// =====================================================

struct CustomerQueueNode {
    string customerID;
    CustomerQueueNode* next;

    CustomerQueueNode(string id) {
        customerID = id;
        next = nullptr;
    }
};

static CustomerQueueNode* customerFront = nullptr;
static CustomerQueueNode* customerRear = nullptr;
static int waitingCustomers = 0;

void CustomerServiceQueue::addCustomerToQueue(string customerID) {
    CustomerQueueNode* node = new CustomerQueueNode(customerID);

    if (!customerRear) {
        customerFront = customerRear = node;
    } else {
        customerRear->next = node;
        customerRear = node;
    }

    waitingCustomers++;

    cout << "Customer added to service queue.\n";
}

void CustomerServiceQueue::serveNextCustomer() {
    if (!customerFront) {
        cout << "Customer queue is empty.\n";
        return;
    }

    CustomerQueueNode* temp = customerFront;

    cout << "Now serving customer: "
         << temp->customerID << '\n';

    customerFront = customerFront->next;

    if (!customerFront)
        customerRear = nullptr;

    delete temp;
    waitingCustomers--;
}

string CustomerServiceQueue::viewNextCustomer() {
    if (!customerFront)
        return "";

    return customerFront->customerID;
}

int CustomerServiceQueue::getWaitingCustomerCount() {
    return waitingCustomers;
}

void CustomerServiceQueue::removeCustomerFromQueue(
    string customerID) {

    CustomerQueueNode* temp = customerFront;
    CustomerQueueNode* prev = nullptr;

    while (temp && temp->customerID != customerID) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Customer not found in queue.\n";
        return;
    }

    if (!prev)
        customerFront = temp->next;
    else
        prev->next = temp->next;

    if (temp == customerRear)
        customerRear = prev;

    delete temp;
    waitingCustomers--;

    cout << "Customer removed from queue.\n";
}


// =====================================================
// 7. CUSTOMER AND ACCOUNT MANAGEMENT - LINKED LIST
// =====================================================

struct AccountNode {
    string accountID;
    AccountNode* next;

    AccountNode(string id) {
        accountID = id;
        next = nullptr;
    }
};

struct CustomerNode {
    string customerID;
    string name;
    string details;

    AccountNode* accounts;
    CustomerNode* next;

    CustomerNode(string id, string n) {
        customerID = id;
        name = n;
        details = "";
        accounts = nullptr;
        next = nullptr;
    }
};

static CustomerNode* customerHead = nullptr;

static CustomerNode* findCustomer(string customerID) {
    CustomerNode* temp = customerHead;

    while (temp) {
        if (temp->customerID == customerID)
            return temp;

        temp = temp->next;
    }

    return nullptr;
}

static bool findAccount(string accountID) {
    CustomerNode* customer = customerHead;

    while (customer) {
        AccountNode* account = customer->accounts;

        while (account) {
            if (account->accountID == accountID)
                return true;

            account = account->next;
        }

        customer = customer->next;
    }

    return false;
}

void CustomerManagement::registerCustomer(
    string customerID, string name) {

    if (findCustomer(customerID)) {
        cout << "Customer already registered.\n";
        return;
    }

    CustomerNode* node = new CustomerNode(customerID, name);

    if (!customerHead) {
        customerHead = node;
    } else {
        CustomerNode* temp = customerHead;

        while (temp->next)
            temp = temp->next;

        temp->next = node;
    }

    cout << "Customer registered successfully.\n";
}

void CustomerManagement::removeCustomer(string customerID) {
    CustomerNode* temp = customerHead;
    CustomerNode* prev = nullptr;

    while (temp && temp->customerID != customerID) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Customer not found.\n";
        return;
    }

    if (!prev)
        customerHead = temp->next;
    else
        prev->next = temp->next;

    AccountNode* account = temp->accounts;

    while (account) {
        AccountNode* next = account->next;
        delete account;
        account = next;
    }

    delete temp;

    cout << "Customer removed successfully.\n";
}

bool CustomerManagement::searchCustomer(string customerID) {
    return findCustomer(customerID) != nullptr;
}

void CustomerManagement::updateCustomerDetails(
    string customerID, string newDetails) {

    CustomerNode* temp = findCustomer(customerID);

    if (!temp) {
        cout << "Customer not found.\n";
        return;
    }

    temp->details = newDetails;

    cout << "Customer details updated.\n";
}

void CustomerManagement::createAccount(
    string customerID, string accountID) {

    CustomerNode* customer = findCustomer(customerID);

    if (!customer) {
        cout << "Customer not found.\n";
        return;
    }

    if (findAccount(accountID)) {
        cout << "Account ID already exists.\n";
        return;
    }

    AccountNode* node = new AccountNode(accountID);

    if (!customer->accounts) {
        customer->accounts = node;
    } else {
        AccountNode* temp = customer->accounts;

        while (temp->next)
            temp = temp->next;

        temp->next = node;
    }

    cout << "Account created successfully.\n";
}

void CustomerManagement::closeAccount(string accountID) {
    CustomerNode* customer = customerHead;

    while (customer) {
        AccountNode* temp = customer->accounts;
        AccountNode* prev = nullptr;

        while (temp && temp->accountID != accountID) {
            prev = temp;
            temp = temp->next;
        }

        if (temp) {
            if (!prev)
                customer->accounts = temp->next;
            else
                prev->next = temp->next;

            delete temp;

            cout << "Account closed successfully.\n";
            return;
        }

        customer = customer->next;
    }

    cout << "Account not found.\n";
}

bool CustomerManagement::searchAccount(string accountID) {
    return findAccount(accountID);
}

void CustomerManagement::displayCustomerAccounts(string customerID) {
    CustomerNode* customer = findCustomer(customerID);

    if (!customer) {
        cout << "Customer not found.\n";
        return;
    }

    cout << "\nAccounts of " << customer->name << ":\n";

    AccountNode* temp = customer->accounts;

    if (!temp) {
        cout << "No accounts available.\n";
        return;
    }

    while (temp) {
        cout << "Account ID: " << temp->accountID << '\n';
        temp = temp->next;
    }
}

void CustomerManagement::displayAllCustomers() {
    CustomerNode* temp = customerHead;

    if (!temp) {
        cout << "No customers registered.\n";
        return;
    }

    cout << "\n--- Customer Records ---\n";

    while (temp) {
        cout << "\nCustomer ID: " << temp->customerID
             << "\nName: " << temp->name
             << "\nDetails: " << temp->details << '\n';

        cout << "Accounts: ";

        AccountNode* account = temp->accounts;

        if (!account)
            cout << "None";

        while (account) {
            cout << account->accountID << " ";
            account = account->next;
        }

        cout << '\n';

        temp = temp->next;
    }
}
