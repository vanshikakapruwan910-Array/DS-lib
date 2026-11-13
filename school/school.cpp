
#include "school.h"
#include <iostream>
#include <algorithm>

using namespace std;

// =====================================================
// 1. STUDENT MANAGEMENT - LINKED LIST
// =====================================================

struct StudentNode {
    string id, name, details;
    StudentNode* next;

    StudentNode(string i, string n) {
        id = i;
        name = n;
        details = "";
        next = nullptr;
    }
};

static StudentNode* studentHead = nullptr;

void StudentManagement::registerStudent(string studentID, string name) {
    if (searchStudent(studentID)) {
        cout << "Student already exists.\n";
        return;
    }

    StudentNode* node = new StudentNode(studentID, name);

    if (!studentHead) {
        studentHead = node;
    } else {
        StudentNode* temp = studentHead;
        while (temp->next)
            temp = temp->next;
        temp->next = node;
    }

    cout << "Student registered successfully.\n";
}

void StudentManagement::removeStudent(string studentID) {
    StudentNode* temp = studentHead;
    StudentNode* prev = nullptr;

    while (temp && temp->id != studentID) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Student not found.\n";
        return;
    }

    if (!prev)
        studentHead = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Student removed successfully.\n";
}

bool StudentManagement::searchStudent(string studentID) {
    StudentNode* temp = studentHead;

    while (temp) {
        if (temp->id == studentID)
            return true;
        temp = temp->next;
    }

    return false;
}

void StudentManagement::updateStudentDetails(
    string studentID, string newDetails) {

    StudentNode* temp = studentHead;

    while (temp) {
        if (temp->id == studentID) {
            temp->details = newDetails;
            cout << "Student details updated.\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Student not found.\n";
}

void StudentManagement::displayAllStudents() {
    StudentNode* temp = studentHead;

    if (!temp) {
        cout << "No students registered.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";

    while (temp) {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name
             << " | Details: " << temp->details << '\n';

        temp = temp->next;
    }
}


// =====================================================
// 2. STUDENT SERVICE - QUEUE
// =====================================================

struct ServiceNode {
    string id;
    ServiceNode* next;

    ServiceNode(string i) {
        id = i;
        next = nullptr;
    }
};

static ServiceNode* serviceFront = nullptr;
static ServiceNode* serviceRear = nullptr;
static int serviceCount = 0;

void StudentService::addStudentToQueue(string studentID) {
    ServiceNode* node = new ServiceNode(studentID);

    if (!serviceRear) {
        serviceFront = serviceRear = node;
    } else {
        serviceRear->next = node;
        serviceRear = node;
    }

    serviceCount++;
    cout << "Student added to service queue.\n";
}

void StudentService::serveNextStudent() {
    if (!serviceFront) {
        cout << "Service queue is empty.\n";
        return;
    }

    ServiceNode* temp = serviceFront;

    cout << "Now serving student: " << temp->id << '\n';

    serviceFront = serviceFront->next;

    if (!serviceFront)
        serviceRear = nullptr;

    delete temp;
    serviceCount--;
}

string StudentService::viewNextStudent() {
    if (!serviceFront)
        return "";

    return serviceFront->id;
}

int StudentService::getWaitingStudentCount() {
    return serviceCount;
}

void StudentService::removeStudentFromQueue(string studentID) {
    ServiceNode* temp = serviceFront;
    ServiceNode* prev = nullptr;

    while (temp && temp->id != studentID) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Student not found in queue.\n";
        return;
    }

    if (!prev)
        serviceFront = temp->next;
    else
        prev->next = temp->next;

    if (temp == serviceRear)
        serviceRear = prev;

    delete temp;
    serviceCount--;

    cout << "Student removed from queue.\n";
}


// =====================================================
// 3. ASSIGNMENT MANAGEMENT - LINKED LIST
// =====================================================

struct AssignmentNode {
    string id, title, details;
    AssignmentNode* next;

    AssignmentNode(string i, string t) {
        id = i;
        title = t;
        details = "";
        next = nullptr;
    }
};

static AssignmentNode* assignmentHead = nullptr;

void AssignmentManagement::addAssignment(
    string assignmentID, string title) {

    if (searchAssignment(assignmentID)) {
        cout << "Assignment already exists.\n";
        return;
    }

    AssignmentNode* node =
        new AssignmentNode(assignmentID, title);

    if (!assignmentHead) {
        assignmentHead = node;
    } else {
        AssignmentNode* temp = assignmentHead;

        while (temp->next)
            temp = temp->next;

        temp->next = node;
    }

    cout << "Assignment added successfully.\n";
}

void AssignmentManagement::removeAssignment(string assignmentID) {
    AssignmentNode* temp = assignmentHead;
    AssignmentNode* prev = nullptr;

    while (temp && temp->id != assignmentID) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Assignment not found.\n";
        return;
    }

    if (!prev)
        assignmentHead = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Assignment removed.\n";
}

void AssignmentManagement::updateAssignment(
    string assignmentID, string newDetails) {

    AssignmentNode* temp = assignmentHead;

    while (temp) {
        if (temp->id == assignmentID) {
            temp->details = newDetails;
            cout << "Assignment updated.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Assignment not found.\n";
}

bool AssignmentManagement::searchAssignment(string assignmentID) {
    AssignmentNode* temp = assignmentHead;

    while (temp) {
        if (temp->id == assignmentID)
            return true;

        temp = temp->next;
    }

    return false;
}

void AssignmentManagement::displayAllAssignments() {
    AssignmentNode* temp = assignmentHead;

    if (!temp) {
        cout << "No assignments available.\n";
        return;
    }

    cout << "\n--- Assignments ---\n";

    while (temp) {
        cout << "ID: " << temp->id
             << " | Title: " << temp->title
             << " | Details: " << temp->details << '\n';

        temp = temp->next;
    }
}


// =====================================================
// 4. STUDENT HISTORY - STACK
// =====================================================

struct HistoryNode {
    string change;
    HistoryNode* next;

    HistoryNode(string c) {
        change = c;
        next = nullptr;
    }
};

static HistoryNode* historyTop = nullptr;

void StudentHistory::recordStudentChange(string change) {
    HistoryNode* node = new HistoryNode(change);

    node->next = historyTop;
    historyTop = node;

    cout << "Change recorded.\n";
}

void StudentHistory::undoLastStudentChange() {
    if (!historyTop) {
        cout << "No changes to undo.\n";
        return;
    }

    HistoryNode* temp = historyTop;

    cout << "Undoing: " << temp->change << '\n';

    historyTop = historyTop->next;

    delete temp;
}

string StudentHistory::viewLastStudentChange() {
    if (!historyTop)
        return "";

    return historyTop->change;
}

void StudentHistory::getStudentChangeHistory() {
    HistoryNode* temp = historyTop;

    if (!temp) {
        cout << "No history available.\n";
        return;
    }

    cout << "\n--- Student Change History ---\n";

    while (temp) {
        cout << temp->change << '\n';
        temp = temp->next;
    }
}


// =====================================================
// 5. ORGANIZATIONAL HIERARCHY - TREE
// =====================================================

struct OrgNode {
    string name;
    OrgNode* parent;
    vector<OrgNode*> children;

    OrgNode(string n) {
        name = n;
        parent = nullptr;
    }
};

static OrgNode* orgRoot = nullptr;

static OrgNode* findOrgNode(OrgNode* root, string name) {
    if (!root)
        return nullptr;

    if (root->name == name)
        return root;

    for (OrgNode* child : root->children) {
        OrgNode* result = findOrgNode(child, name);

        if (result)
            return result;
    }

    return nullptr;
}

static void displayOrgTree(OrgNode* root, int level) {
    if (!root)
        return;

    for (int i = 0; i < level; i++)
        cout << "  ";

    cout << "|-- " << root->name << '\n';

    for (OrgNode* child : root->children)
        displayOrgTree(child, level + 1);
}

static int countOrgNodes(OrgNode* root) {
    if (!root)
        return 0;

    int count = 1;

    for (OrgNode* child : root->children)
        count += countOrgNodes(child);

    return count;
}

static void deleteOrgTree(OrgNode* root) {
    if (!root)
        return;

    for (OrgNode* child : root->children)
        deleteOrgTree(child);

    delete root;
}

static int orgLevel(OrgNode* node) {
    if (!node)
        return -1;

    int level = 0;

    while (node->parent) {
        level++;
        node = node->parent;
    }

    return level;
}

void OrganizationHierarchy::addOrganizationNode(string node) {
    if (findOrgNode(orgRoot, node)) {
        cout << "Organization node already exists.\n";
        return;
    }

    OrgNode* newNode = new OrgNode(node);

    if (!orgRoot) {
        orgRoot = newNode;
    } else {
        newNode->parent = orgRoot;
        orgRoot->children.push_back(newNode);
    }

    cout << "Organization node added.\n";
}

void OrganizationHierarchy::removeOrganizationNode(string node) {
    OrgNode* target = findOrgNode(orgRoot, node);

    if (!target) {
        cout << "Organization node not found.\n";
        return;
    }

    if (!target->parent) {
        deleteOrgTree(orgRoot);
        orgRoot = nullptr;
    } else {
        OrgNode* parent = target->parent;

        auto& children = parent->children;

        children.erase(
            remove(children.begin(), children.end(), target),
            children.end()
        );

        deleteOrgTree(target);
    }

    cout << "Organization node removed.\n";
}

void OrganizationHierarchy::addSubordinate(
    string parent, string child) {

    OrgNode* p = findOrgNode(orgRoot, parent);

    if (!p) {
        cout << "Parent node not found.\n";
        return;
    }

    if (findOrgNode(orgRoot, child)) {
        cout << "Child node already exists.\n";
        return;
    }

    OrgNode* c = new OrgNode(child);
    c->parent = p;

    p->children.push_back(c);

    cout << "Subordinate added.\n";
}

bool OrganizationHierarchy::searchOrganizationNode(string node) {
    return findOrgNode(orgRoot, node) != nullptr;
}

void OrganizationHierarchy::displayOrganizationHierarchy() {
    if (!orgRoot) {
        cout << "Organization hierarchy is empty.\n";
        return;
    }

    cout << "\n--- Organization Hierarchy ---\n";
    displayOrgTree(orgRoot, 0);
}

int OrganizationHierarchy::findHierarchyLevel(string node) {
    OrgNode* target = findOrgNode(orgRoot, node);

    if (!target)
        return -1;

    return orgLevel(target);
}

int OrganizationHierarchy::countOrganizationMembers() {
    return countOrgNodes(orgRoot);
}


// =====================================================
// 6. CURRICULUM MANAGEMENT - TREE
// =====================================================

struct CurriculumNode {
    string name;
    CurriculumNode* child;
    CurriculumNode* sibling;

    CurriculumNode(string n) {
        name = n;
        child = nullptr;
        sibling = nullptr;
    }
};

static CurriculumNode* curriculumRoot = nullptr;

static CurriculumNode* findCurriculumNode(
    CurriculumNode* root, string name) {

    while (root) {
        if (root->name == name)
            return root;

        CurriculumNode* result =
            findCurriculumNode(root->child, name);

        if (result)
            return result;

        root = root->sibling;
    }

    return nullptr;
}

static void displayCurriculumTree(
    CurriculumNode* root, int level) {

    while (root) {
        for (int i = 0; i < level; i++)
            cout << "  ";

        cout << "|-- " << root->name << '\n';

        displayCurriculumTree(root->child, level + 1);

        root = root->sibling;
    }
}

static int countCurriculumTopics(CurriculumNode* root) {
    if (!root)
        return 0;

    int count = 0;

    while (root) {
        if (!root->child)
            count++;

        count += countCurriculumTopics(root->child);
        root = root->sibling;
    }

    return count;
}

static int curriculumDepth(CurriculumNode* root) {
    if (!root)
        return 0;

    int maximum = 0;

    while (root) {
        int depth = 1 + curriculumDepth(root->child);
        maximum = max(maximum, depth);
        root = root->sibling;
    }

    return maximum;
}

static bool removeCurriculumNode(
    CurriculumNode*& root, string name) {

    CurriculumNode* temp = root;
    CurriculumNode* prev = nullptr;

    while (temp) {
        if (temp->name == name) {
            if (!prev)
                root = temp->sibling;
            else
                prev->sibling = temp->sibling;

            delete temp;
            return true;
        }

        if (removeCurriculumNode(temp->child, name))
            return true;

        prev = temp;
        temp = temp->sibling;
    }

    return false;
}

void CurriculumManagement::addSubject(string subject) {
    if (findCurriculumNode(curriculumRoot, subject)) {
        cout << "Subject already exists.\n";
        return;
    }

    CurriculumNode* node = new CurriculumNode(subject);

    if (!curriculumRoot) {
        curriculumRoot = node;
    } else {
        CurriculumNode* temp = curriculumRoot;

        while (temp->sibling)
            temp = temp->sibling;

        temp->sibling = node;
    }

    cout << "Subject added.\n";
}

void CurriculumManagement::addChapter(
    string subject, string chapter) {

    CurriculumNode* parent =
        findCurriculumNode(curriculumRoot, subject);

    if (!parent) {
        cout << "Subject not found.\n";
        return;
    }

    if (findCurriculumNode(curriculumRoot, chapter)) {
        cout << "Chapter name already exists.\n";
        return;
    }

    CurriculumNode* node = new CurriculumNode(chapter);

    if (!parent->child) {
        parent->child = node;
    } else {
        CurriculumNode* temp = parent->child;

        while (temp->sibling)
            temp = temp->sibling;

        temp->sibling = node;
    }

    cout << "Chapter added.\n";
}

void CurriculumManagement::addTopic(
    string chapter, string topic) {

    CurriculumNode* parent =
        findCurriculumNode(curriculumRoot, chapter);

    if (!parent) {
        cout << "Chapter not found.\n";
        return;
    }

    if (findCurriculumNode(curriculumRoot, topic)) {
        cout << "Topic name already exists.\n";
        return;
    }

    CurriculumNode* node = new CurriculumNode(topic);

    if (!parent->child) {
        parent->child = node;
    } else {
        CurriculumNode* temp = parent->child;

        while (temp->sibling)
            temp = temp->sibling;

        temp->sibling = node;
    }

    cout << "Topic added.\n";
}

void CurriculumManagement::removeTopic(string topic) {
    if (!removeCurriculumNode(curriculumRoot, topic)) {
        cout << "Topic not found.\n";
        return;
    }

    cout << "Curriculum node removed.\n";
}

bool CurriculumManagement::searchTopic(string topic) {
    return findCurriculumNode(curriculumRoot, topic) != nullptr;
}

void CurriculumManagement::displayCurriculum() {
    if (!curriculumRoot) {
        cout << "Curriculum is empty.\n";
        return;
    }

    cout << "\n--- Curriculum ---\n";
    displayCurriculumTree(curriculumRoot, 0);
}

int CurriculumManagement::countTopics() {
    return countCurriculumTopics(curriculumRoot);
}

int CurriculumManagement::findCurriculumDepth() {
    return curriculumDepth(curriculumRoot);
}


// =====================================================
// 7. CAMPUS NAVIGATION - GRAPH
// =====================================================

static vector<string> campusLocations;
static vector<vector<int>> campusAdjacency;

static int findCampusIndex(string location) {
    for (int i = 0; i < (int)campusLocations.size(); i++) {
        if (campusLocations[i] == location)
            return i;
    }

    return -1;
}

void CampusNavigation::addCampusLocation(string location) {
    if (findCampusIndex(location) != -1) {
        cout << "Location already exists.\n";
        return;
    }

    campusLocations.push_back(location);
    campusAdjacency.push_back(vector<int>());

    cout << "Campus location added.\n";
}

void CampusNavigation::connectCampusLocations(
    string location1, string location2) {

    int u = findCampusIndex(location1);
    int v = findCampusIndex(location2);

    if (u == -1 || v == -1) {
        cout << "One or both locations do not exist.\n";
        return;
    }

    if (u == v) {
        cout << "Cannot connect a location to itself.\n";
        return;
    }

    if (find(campusAdjacency[u].begin(),
             campusAdjacency[u].end(), v)
        != campusAdjacency[u].end()) {
        cout << "Connection already exists.\n";
        return;
    }

    campusAdjacency[u].push_back(v);
    campusAdjacency[v].push_back(u);

    cout << "Campus locations connected.\n";
}

void CampusNavigation::removeCampusLocation(string location) {
    int index = findCampusIndex(location);

    if (index == -1) {
        cout << "Location not found.\n";
        return;
    }

    campusLocations.erase(campusLocations.begin() + index);
    campusAdjacency.erase(campusAdjacency.begin() + index);

    for (auto& neighbors : campusAdjacency) {
        for (int& v : neighbors) {
            if (v > index)
                v--;
        }

        neighbors.erase(
            remove(neighbors.begin(), neighbors.end(), index),
            neighbors.end()
        );
    }

    cout << "Campus location removed.\n";
}

vector<string> CampusNavigation::findNearbyLocations(
    string location) {

    vector<string> result;

    int index = findCampusIndex(location);

    if (index == -1)
        return result;

    for (int v : campusAdjacency[index])
        result.push_back(campusLocations[v]);

    return result;
}

vector<string> CampusNavigation::findCampusRoute(
    string source, string destination) {

    vector<string> result;

    int start = findCampusIndex(source);
    int end = findCampusIndex(destination);

    if (start == -1 || end == -1)
        return result;

    vector<bool> visited(campusLocations.size(), false);
    vector<int> parent(campusLocations.size(), -1);

    vector<int> st;
    st.push_back(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.back();
        st.pop_back();

        if (u == end)
            break;

        for (int v : campusAdjacency[u]) {
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
        result.push_back(campusLocations[v]);

    reverse(result.begin(), result.end());

    return result;
}

vector<string> CampusNavigation::findShortestCampusRoute(
    string source, string destination) {

    vector<string> result;

    int start = findCampusIndex(source);
    int end = findCampusIndex(destination);

    if (start == -1 || end == -1)
        return result;

    vector<bool> visited(campusLocations.size(), false);
    vector<int> parent(campusLocations.size(), -1);

    // BFS using a manually implemented array-based queue
    vector<int> q(campusLocations.size());
    int front = 0, rear = 0;

    q[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int u = q[front++];

        if (u == end)
            break;

        for (int v : campusAdjacency[u]) {
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
        result.push_back(campusLocations[v]);

    reverse(result.begin(), result.end());

    return result;
}

void CampusNavigation::displayCampusMap() {
    if (campusLocations.empty()) {
        cout << "Campus map is empty.\n";
        return;
    }

    cout << "\n--- Campus Map ---\n";

    for (int i = 0; i < (int)campusLocations.size(); i++) {
        cout << campusLocations[i] << " -> ";

        for (int v : campusAdjacency[i])
            cout << campusLocations[v] << " ";

        cout << '\n';
    }
}

bool CampusNavigation::checkCampusConnectivity() {
    int n = campusLocations.size();

    if (n == 0)
        return false;

    vector<bool> visited(n, false);
    vector<int> st;

    st.push_back(0);
    visited[0] = true;

    while (!st.empty()) {
        int u = st.back();
        st.pop_back();

        for (int v : campusAdjacency[u]) {
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
// 8. SUBJECT PREREQUISITES - DIRECTED GRAPH
// =====================================================

static vector<string> subjects;
static vector<vector<int>> prerequisiteGraph;

static int findSubjectIndex(string subject) {
    for (int i = 0; i < (int)subjects.size(); i++) {
        if (subjects[i] == subject)
            return i;
    }

    return -1;
}

// DFS cycle detection
static bool prerequisiteDFS(
    int u, vector<int>& state) {

    state[u] = 1;

    for (int v : prerequisiteGraph[u]) {
        if (state[v] == 1)
            return true;

        if (state[v] == 0 &&
            prerequisiteDFS(v, state))
            return true;
    }

    state[u] = 2;
    return false;
}

void SubjectPrerequisites::addSubject(string subject) {
    if (findSubjectIndex(subject) != -1) {
        cout << "Subject already exists.\n";
        return;
    }

    subjects.push_back(subject);
    prerequisiteGraph.push_back(vector<int>());

    cout << "Subject added.\n";
}

void SubjectPrerequisites::addPrerequisite(
    string subject, string prerequisite) {

    int u = findSubjectIndex(subject);
    int v = findSubjectIndex(prerequisite);

    if (u == -1 || v == -1) {
        cout << "Subject or prerequisite not found.\n";
        return;
    }

    if (u == v) {
        cout << "A subject cannot be its own prerequisite.\n";
        return;
    }

    if (find(prerequisiteGraph[u].begin(),
             prerequisiteGraph[u].end(), v)
        != prerequisiteGraph[u].end()) {
        cout << "Prerequisite already exists.\n";
        return;
    }

    prerequisiteGraph[u].push_back(v);

    if (hasPrerequisiteCycle()) {
        prerequisiteGraph[u].pop_back();
        cout << "Operation rejected: prerequisite cycle detected.\n";
        return;
    }

    cout << "Prerequisite added.\n";
}

void SubjectPrerequisites::removePrerequisite(
    string subject, string prerequisite) {

    int u = findSubjectIndex(subject);
    int v = findSubjectIndex(prerequisite);

    if (u == -1 || v == -1) {
        cout << "Subject not found.\n";
        return;
    }

    auto& edges = prerequisiteGraph[u];

    auto it = find(edges.begin(), edges.end(), v);

    if (it == edges.end()) {
        cout << "Prerequisite relationship not found.\n";
        return;
    }

    edges.erase(it);

    cout << "Prerequisite removed.\n";
}

vector<string> SubjectPrerequisites::getPrerequisites(
    string subject) {

    vector<string> result;

    int u = findSubjectIndex(subject);

    if (u == -1)
        return result;

    for (int v : prerequisiteGraph[u])
        result.push_back(subjects[v]);

    return result;
}

vector<string> SubjectPrerequisites::getDependentSubjects(
    string subject) {

    vector<string> result;

    int target = findSubjectIndex(subject);

    if (target == -1)
        return result;

    for (int i = 0; i < (int)subjects.size(); i++) {
        for (int v : prerequisiteGraph[i]) {
            if (v == target)
                result.push_back(subjects[i]);
        }
    }

    return result;
}

bool SubjectPrerequisites::checkPrerequisites(string subject) {
    int u = findSubjectIndex(subject);

    if (u == -1 || hasPrerequisiteCycle())
        return false;

    // Check that all directly linked prerequisites exist.
    for (int v : prerequisiteGraph[u]) {
        if (v < 0 || v >= (int)subjects.size())
            return false;
    }

    return true;
}

vector<string> SubjectPrerequisites::getRecommendedSubjectOrder() {
    vector<string> result;

    if (hasPrerequisiteCycle())
        return result;

    int n = subjects.size();

    vector<int> indegree(n, 0);
    vector<vector<int>> dependents(n);

    // Convert prerequisite edges into prerequisite -> dependent edges.
    for (int i = 0; i < n; i++) {
        for (int prerequisite : prerequisiteGraph[i]) {
            dependents[prerequisite].push_back(i);
            indegree[i]++;
        }
    }

    // Kahn's topological sorting algorithm
    vector<int> q(n);
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q[rear++] = i;
    }

    while (front < rear) {
        int u = q[front++];

        result.push_back(subjects[u]);

        for (int v : dependents[u]) {
            indegree[v]--;

            if (indegree[v] == 0)
                q[rear++] = v;
        }
    }

    return result;
}

bool SubjectPrerequisites::hasPrerequisiteCycle() {
    int n = subjects.size();

    vector<int> state(n, 0);

    for (int i = 0; i < n; i++) {
        if (state[i] == 0 &&
            prerequisiteDFS(i, state))
            return true;
    }

    return false;
}
