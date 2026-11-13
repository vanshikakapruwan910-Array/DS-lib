
#include "hospital.h"
#include <iostream>
#include <algorithm>

using namespace std;

// =====================================================
// 1. PATIENT MANAGEMENT - LINKED LIST
// =====================================================

struct PatientNode {
    string id, name, details;
    PatientNode* next;

    PatientNode(string i, string n) {
        id = i;
        name = n;
        details = "";
        next = nullptr;
    }
};

static PatientNode* patientHead = nullptr;

static PatientNode* findPatientNode(string patientID) {
    PatientNode* temp = patientHead;

    while (temp) {
        if (temp->id == patientID)
            return temp;

        temp = temp->next;
    }

    return nullptr;
}

void PatientManagement::registerPatient(
    string patientID, string name) {

    if (findPatientNode(patientID)) {
        cout << "Patient already registered.\n";
        return;
    }

    PatientNode* node = new PatientNode(patientID, name);

    if (!patientHead) {
        patientHead = node;
    } else {
        PatientNode* temp = patientHead;

        while (temp->next)
            temp = temp->next;

        temp->next = node;
    }

    cout << "Patient registered successfully.\n";
}

void PatientManagement::removePatient(string patientID) {
    PatientNode* temp = patientHead;
    PatientNode* prev = nullptr;

    while (temp && temp->id != patientID) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Patient not found.\n";
        return;
    }

    if (!prev)
        patientHead = temp->next;
    else
        prev->next = temp->next;

    delete temp;

    cout << "Patient removed successfully.\n";
}

bool PatientManagement::searchPatient(string patientID) {
    return findPatientNode(patientID) != nullptr;
}

void PatientManagement::updatePatientDetails(
    string patientID, string newDetails) {

    PatientNode* temp = findPatientNode(patientID);

    if (!temp) {
        cout << "Patient not found.\n";
        return;
    }

    temp->details = newDetails;

    cout << "Patient details updated.\n";
}

void PatientManagement::displayAllPatients() {
    PatientNode* temp = patientHead;

    if (!temp) {
        cout << "No patients registered.\n";
        return;
    }

    cout << "\n--- Patient Records ---\n";

    while (temp) {
        cout << "Patient ID: " << temp->id
             << " | Name: " << temp->name
             << " | Details: " << temp->details << '\n';

        temp = temp->next;
    }
}


// =====================================================
// 2. PATIENT QUEUE - FIFO QUEUE
// =====================================================

struct PatientQueueNode {
    string patientID;
    PatientQueueNode* next;

    PatientQueueNode(string id) {
        patientID = id;
        next = nullptr;
    }
};

static PatientQueueNode* patientFront = nullptr;
static PatientQueueNode* patientRear = nullptr;
static int waitingCount = 0;

void PatientQueue::addPatientToQueue(string patientID) {
    PatientQueueNode* node = new PatientQueueNode(patientID);

    if (!patientRear) {
        patientFront = patientRear = node;
    } else {
        patientRear->next = node;
        patientRear = node;
    }

    waitingCount++;

    cout << "Patient added to queue.\n";
}

void PatientQueue::callNextPatient() {
    if (!patientFront) {
        cout << "Patient queue is empty.\n";
        return;
    }

    PatientQueueNode* temp = patientFront;

    cout << "Calling patient: " << temp->patientID << '\n';

    patientFront = patientFront->next;

    if (!patientFront)
        patientRear = nullptr;

    delete temp;
    waitingCount--;
}

string PatientQueue::viewNextPatient() {
    if (!patientFront)
        return "";

    return patientFront->patientID;
}

int PatientQueue::getWaitingCount() {
    return waitingCount;
}

void PatientQueue::cancelPatientVisit(string patientID) {
    PatientQueueNode* temp = patientFront;
    PatientQueueNode* prev = nullptr;

    while (temp && temp->patientID != patientID) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Patient not found in queue.\n";
        return;
    }

    if (!prev)
        patientFront = temp->next;
    else
        prev->next = temp->next;

    if (temp == patientRear)
        patientRear = prev;

    delete temp;
    waitingCount--;

    cout << "Patient visit cancelled.\n";
}


// =====================================================
// 3. APPOINTMENT MANAGEMENT - LINKED LIST
// =====================================================

struct AppointmentNode {
    string appointmentID;
    string patientID;
    string doctor;
    string time;
    AppointmentNode* next;

    AppointmentNode(string id, string patient, string d) {
        appointmentID = id;
        patientID = patient;
        doctor = d;
        time = "Not specified";
        next = nullptr;
    }
};

static AppointmentNode* appointmentHead = nullptr;
static int appointmentCounter = 1;

static AppointmentNode* findAppointmentNode(string appointmentID) {
    AppointmentNode* temp = appointmentHead;

    while (temp) {
        if (temp->appointmentID == appointmentID)
            return temp;

        temp = temp->next;
    }

    return nullptr;
}

void AppointmentManagement::scheduleAppointment(
    string patientID, string doctor) {

    string id = "APT" + to_string(appointmentCounter++);

    AppointmentNode* node =
        new AppointmentNode(id, patientID, doctor);

    if (!appointmentHead) {
        appointmentHead = node;
    } else {
        AppointmentNode* temp = appointmentHead;

        while (temp->next)
            temp = temp->next;

        temp->next = node;
    }

    cout << "Appointment scheduled successfully.\n";
    cout << "Appointment ID: " << id << '\n';
}

void AppointmentManagement::cancelAppointment(
    string appointmentID) {

    AppointmentNode* temp = appointmentHead;
    AppointmentNode* prev = nullptr;

    while (temp && temp->appointmentID != appointmentID) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Appointment not found.\n";
        return;
    }

    if (!prev)
        appointmentHead = temp->next;
    else
        prev->next = temp->next;

    delete temp;

    cout << "Appointment cancelled.\n";
}

void AppointmentManagement::rescheduleAppointment(
    string appointmentID, string newTime) {

    AppointmentNode* temp =
        findAppointmentNode(appointmentID);

    if (!temp) {
        cout << "Appointment not found.\n";
        return;
    }

    temp->time = newTime;

    cout << "Appointment rescheduled.\n";
}

bool AppointmentManagement::findAppointment(
    string appointmentID) {

    return findAppointmentNode(appointmentID) != nullptr;
}

void AppointmentManagement::displayDoctorSchedule(string doctor) {
    AppointmentNode* temp = appointmentHead;
    bool found = false;

    cout << "\n--- Schedule for Dr. " << doctor << " ---\n";

    while (temp) {
        if (temp->doctor == doctor) {
            cout << "Appointment ID: " << temp->appointmentID
                 << " | Patient ID: " << temp->patientID
                 << " | Time: " << temp->time << '\n';

            found = true;
        }

        temp = temp->next;
    }

    if (!found)
        cout << "No appointments found for this doctor.\n";
}


// =====================================================
// 4. PATIENT RECORD HISTORY - STACK
// =====================================================

struct RecordHistoryNode {
    string action;
    RecordHistoryNode* next;

    RecordHistoryNode(string a) {
        action = a;
        next = nullptr;
    }
};

static RecordHistoryNode* recordTop = nullptr;

void PatientRecordHistory::recordPatientAction(string action) {
    RecordHistoryNode* node = new RecordHistoryNode(action);

    node->next = recordTop;
    recordTop = node;

    cout << "Patient action recorded.\n";
}

void PatientRecordHistory::undoLastRecordAction() {
    if (!recordTop) {
        cout << "No record actions to undo.\n";
        return;
    }

    RecordHistoryNode* temp = recordTop;

    cout << "Removing last recorded action: "
         << temp->action << '\n';

    recordTop = recordTop->next;

    delete temp;
}

string PatientRecordHistory::viewLastRecordAction() {
    if (!recordTop)
        return "";

    return recordTop->action;
}

void PatientRecordHistory::getRecordHistory() {
    RecordHistoryNode* temp = recordTop;

    if (!temp) {
        cout << "No record history available.\n";
        return;
    }

    cout << "\n--- Patient Record History ---\n";

    while (temp) {
        cout << temp->action << '\n';
        temp = temp->next;
    }
}


// =====================================================
// 5. DEPARTMENT HIERARCHY - TREE
// =====================================================

struct DepartmentNode {
    string name;
    DepartmentNode* parent;
    vector<DepartmentNode*> children;

    DepartmentNode(string n) {
        name = n;
        parent = nullptr;
    }
};

static vector<DepartmentNode*> departmentRoots;

static DepartmentNode* findDepartmentNode(
    DepartmentNode* root, string department) {

    if (!root)
        return nullptr;

    if (root->name == department)
        return root;

    for (DepartmentNode* child : root->children) {
        DepartmentNode* result =
            findDepartmentNode(child, department);

        if (result)
            return result;
    }

    return nullptr;
}

static DepartmentNode* findAnyDepartment(string department) {
    for (DepartmentNode* root : departmentRoots) {
        DepartmentNode* result =
            findDepartmentNode(root, department);

        if (result)
            return result;
    }

    return nullptr;
}

static void displayDepartmentTree(
    DepartmentNode* root, int level) {

    if (!root)
        return;

    for (int i = 0; i < level; i++)
        cout << "  ";

    cout << "|-- " << root->name << '\n';

    for (DepartmentNode* child : root->children)
        displayDepartmentTree(child, level + 1);
}

static int countDepartmentTree(DepartmentNode* root) {
    if (!root)
        return 0;

    int count = 1;

    for (DepartmentNode* child : root->children)
        count += countDepartmentTree(child);

    return count;
}

static void deleteDepartmentTree(DepartmentNode* root) {
    if (!root)
        return;

    for (DepartmentNode* child : root->children)
        deleteDepartmentTree(child);

    delete root;
}

static void departmentPreorder(
    DepartmentNode* root, vector<string>& result) {

    if (!root)
        return;

    result.push_back(root->name);

    for (DepartmentNode* child : root->children)
        departmentPreorder(child, result);
}

void DepartmentHierarchy::addDepartment(string department) {
    if (findAnyDepartment(department)) {
        cout << "Department already exists.\n";
        return;
    }

    departmentRoots.push_back(
        new DepartmentNode(department)
    );

    cout << "Department added.\n";
}

void DepartmentHierarchy::removeDepartment(string department) {
    DepartmentNode* target = findAnyDepartment(department);

    if (!target) {
        cout << "Department not found.\n";
        return;
    }

    if (!target->parent) {
        auto it = find(
            departmentRoots.begin(),
            departmentRoots.end(),
            target
        );

        if (it != departmentRoots.end())
            departmentRoots.erase(it);
    } else {
        DepartmentNode* parent = target->parent;

        auto& children = parent->children;

        children.erase(
            remove(children.begin(), children.end(), target),
            children.end()
        );
    }

    deleteDepartmentTree(target);

    cout << "Department removed.\n";
}

bool DepartmentHierarchy::searchDepartment(string department) {
    return findAnyDepartment(department) != nullptr;
}

void DepartmentHierarchy::displayDepartmentHierarchy() {
    if (departmentRoots.empty()) {
        cout << "Department hierarchy is empty.\n";
        return;
    }

    cout << "\n--- Hospital Department Hierarchy ---\n";

    for (DepartmentNode* root : departmentRoots)
        displayDepartmentTree(root, 0);
}

void DepartmentHierarchy::addSubDepartment(
    string parent, string child) {

    DepartmentNode* p = findAnyDepartment(parent);

    if (!p) {
        cout << "Parent department not found.\n";
        return;
    }

    if (findAnyDepartment(child)) {
        cout << "Department already exists.\n";
        return;
    }

    DepartmentNode* c = new DepartmentNode(child);
    c->parent = p;

    p->children.push_back(c);

    cout << "Sub-department added.\n";
}

int DepartmentHierarchy::findDepartmentLevel(
    string department) {

    DepartmentNode* node = findAnyDepartment(department);

    if (!node)
        return -1;

    int level = 0;

    while (node->parent) {
        level++;
        node = node->parent;
    }

    return level;
}

int DepartmentHierarchy::getDepartmentCount() {
    int count = 0;

    for (DepartmentNode* root : departmentRoots)
        count += countDepartmentTree(root);

    return count;
}

void DepartmentHierarchy::displayDepartmentsInOrder() {
    if (departmentRoots.empty()) {
        cout << "No departments available.\n";
        return;
    }

    vector<string> result;

    for (DepartmentNode* root : departmentRoots)
        departmentPreorder(root, result);

    sort(result.begin(), result.end());

    cout << "\n--- Departments in Alphabetical Order ---\n";

    for (string department : result)
        cout << department << '\n';
}


// =====================================================
// 6. MEDICAL RECORD CATEGORIES - TREE
// =====================================================

struct RecordCategoryNode {
    string name;
    RecordCategoryNode* parent;
    vector<RecordCategoryNode*> children;

    RecordCategoryNode(string n) {
        name = n;
        parent = nullptr;
    }
};

static vector<RecordCategoryNode*> recordCategoryRoots;

static RecordCategoryNode* findRecordCategoryNode(
    RecordCategoryNode* root, string category) {

    if (!root)
        return nullptr;

    if (root->name == category)
        return root;

    for (RecordCategoryNode* child : root->children) {
        RecordCategoryNode* result =
            findRecordCategoryNode(child, category);

        if (result)
            return result;
    }

    return nullptr;
}

static RecordCategoryNode* findAnyRecordCategory(
    string category) {

    for (RecordCategoryNode* root : recordCategoryRoots) {
        RecordCategoryNode* result =
            findRecordCategoryNode(root, category);

        if (result)
            return result;
    }

    return nullptr;
}

static void displayRecordCategoryTree(
    RecordCategoryNode* root, int level) {

    if (!root)
        return;

    for (int i = 0; i < level; i++)
        cout << "  ";

    cout << "|-- " << root->name << '\n';

    for (RecordCategoryNode* child : root->children)
        displayRecordCategoryTree(child, level + 1);
}

void MedicalRecordCategories::addRecordCategory(string category) {
    if (findAnyRecordCategory(category)) {
        cout << "Record category already exists.\n";
        return;
    }

    recordCategoryRoots.push_back(
        new RecordCategoryNode(category)
    );

    cout << "Record category added.\n";
}

void MedicalRecordCategories::addSubCategory(
    string parent, string child) {

    RecordCategoryNode* p = findAnyRecordCategory(parent);

    if (!p) {
        cout << "Parent category not found.\n";
        return;
    }

    if (findAnyRecordCategory(child)) {
        cout << "Category already exists.\n";
        return;
    }

    RecordCategoryNode* c = new RecordCategoryNode(child);
    c->parent = p;

    p->children.push_back(c);

    cout << "Sub-category added.\n";
}

bool MedicalRecordCategories::searchRecordCategory(
    string category) {

    return findAnyRecordCategory(category) != nullptr;
}

void MedicalRecordCategories::displayRecordCategories() {
    if (recordCategoryRoots.empty()) {
        cout << "No medical record categories available.\n";
        return;
    }

    cout << "\n--- Medical Record Categories ---\n";

    for (RecordCategoryNode* root : recordCategoryRoots)
        displayRecordCategoryTree(root, 0);
}


// =====================================================
// 7. HOSPITAL NAVIGATION - UNDIRECTED GRAPH
// =====================================================

static vector<string> hospitalLocations;
static vector<vector<int>> hospitalAdjacency;

static int findHospitalLocation(string location) {
    for (int i = 0; i < (int)hospitalLocations.size(); i++) {
        if (hospitalLocations[i] == location)
            return i;
    }

    return -1;
}

void HospitalNavigation::addHospitalLocation(string location) {
    if (findHospitalLocation(location) != -1) {
        cout << "Location already exists.\n";
        return;
    }

    hospitalLocations.push_back(location);
    hospitalAdjacency.push_back(vector<int>());

    cout << "Hospital location added.\n";
}

void HospitalNavigation::connectLocations(
    string location1, string location2) {

    int u = findHospitalLocation(location1);
    int v = findHospitalLocation(location2);

    if (u == -1 || v == -1) {
        cout << "One or both locations not found.\n";
        return;
    }

    if (u == v) {
        cout << "Cannot connect a location to itself.\n";
        return;
    }

    if (find(hospitalAdjacency[u].begin(),
             hospitalAdjacency[u].end(), v)
        != hospitalAdjacency[u].end()) {
        cout << "Connection already exists.\n";
        return;
    }

    hospitalAdjacency[u].push_back(v);
    hospitalAdjacency[v].push_back(u);

    cout << "Hospital locations connected.\n";
}

void HospitalNavigation::removeLocation(string location) {
    int index = findHospitalLocation(location);

    if (index == -1) {
        cout << "Location not found.\n";
        return;
    }

    hospitalLocations.erase(hospitalLocations.begin() + index);
    hospitalAdjacency.erase(hospitalAdjacency.begin() + index);

    for (auto& neighbors : hospitalAdjacency) {
        for (int& v : neighbors) {
            if (v > index)
                v--;
        }

        neighbors.erase(
            remove(neighbors.begin(), neighbors.end(), index),
            neighbors.end()
        );
    }

    cout << "Hospital location removed.\n";
}

vector<string> HospitalNavigation::findConnectedLocations(
    string location) {

    vector<string> result;

    int index = findHospitalLocation(location);

    if (index == -1)
        return result;

    for (int v : hospitalAdjacency[index])
        result.push_back(hospitalLocations[v]);

    return result;
}

// DFS for finding a route
vector<string> HospitalNavigation::findHospitalRoute(
    string source, string destination) {

    vector<string> result;

    int start = findHospitalLocation(source);
    int end = findHospitalLocation(destination);

    if (start == -1 || end == -1)
        return result;

    vector<bool> visited(hospitalLocations.size(), false);
    vector<int> parent(hospitalLocations.size(), -1);

    vector<int> st;

    st.push_back(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.back();
        st.pop_back();

        if (u == end)
            break;

        for (int v : hospitalAdjacency[u]) {
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
        result.push_back(hospitalLocations[v]);

    reverse(result.begin(), result.end());

    return result;
}

// BFS for shortest route
vector<string> HospitalNavigation::findShortestHospitalRoute(
    string source, string destination) {

    vector<string> result;

    int start = findHospitalLocation(source);
    int end = findHospitalLocation(destination);

    if (start == -1 || end == -1)
        return result;

    vector<bool> visited(hospitalLocations.size(), false);
    vector<int> parent(hospitalLocations.size(), -1);

    vector<int> q(hospitalLocations.size());

    int front = 0, rear = 0;

    q[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int u = q[front++];

        if (u == end)
            break;

        for (int v : hospitalAdjacency[u]) {
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
        result.push_back(hospitalLocations[v]);

    reverse(result.begin(), result.end());

    return result;
}

void HospitalNavigation::displayHospitalMap() {
    if (hospitalLocations.empty()) {
        cout << "Hospital map is empty.\n";
        return;
    }

    cout << "\n--- Hospital Map ---\n";

    for (int i = 0; i < (int)hospitalLocations.size(); i++) {
        cout << hospitalLocations[i] << " -> ";

        for (int v : hospitalAdjacency[i])
            cout << hospitalLocations[v] << " ";

        cout << '\n';
    }
}


// =====================================================
// 8. DEPARTMENT CONNECTIONS - GRAPH
// =====================================================

static vector<string> connectedDepartments;
static vector<vector<int>> departmentAdjacency;

static int findConnectedDepartment(string department) {
    for (int i = 0; i < (int)connectedDepartments.size(); i++) {
        if (connectedDepartments[i] == department)
            return i;
    }

    return -1;
}

static int addConnectedDepartmentIfMissing(string department) {
    int index = findConnectedDepartment(department);

    if (index != -1)
        return index;

    connectedDepartments.push_back(department);
    departmentAdjacency.push_back(vector<int>());

    return (int)connectedDepartments.size() - 1;
}

void DepartmentConnections::connectDepartments(
    string department1, string department2) {

    if (department1 == department2) {
        cout << "Cannot connect a department to itself.\n";
        return;
    }

    int u = addConnectedDepartmentIfMissing(department1);
    int v = addConnectedDepartmentIfMissing(department2);

    if (find(departmentAdjacency[u].begin(),
             departmentAdjacency[u].end(), v)
        != departmentAdjacency[u].end()) {
        cout << "Departments are already connected.\n";
        return;
    }

    departmentAdjacency[u].push_back(v);
    departmentAdjacency[v].push_back(u);

    cout << "Departments connected successfully.\n";
}

vector<string> DepartmentConnections::findRelatedDepartments(
    string department) {

    vector<string> result;

    int index = findConnectedDepartment(department);

    if (index == -1)
        return result;

    for (int v : departmentAdjacency[index])
        result.push_back(connectedDepartments[v]);

    return result;
}

int DepartmentConnections::getDepartmentConnections(
    string department) {

    int index = findConnectedDepartment(department);

    if (index == -1)
        return 0;

    return (int)departmentAdjacency[index].size();
}

// BFS to find a path between departments
vector<string> DepartmentConnections::findDepartmentPath(
    string source, string destination) {

    vector<string> result;

    int start = findConnectedDepartment(source);
    int end = findConnectedDepartment(destination);

    if (start == -1 || end == -1)
        return result;

    vector<bool> visited(connectedDepartments.size(), false);
    vector<int> parent(connectedDepartments.size(), -1);

    vector<int> q(connectedDepartments.size());

    int front = 0, rear = 0;

    q[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int u = q[front++];

        if (u == end)
            break;

        for (int v : departmentAdjacency[u]) {
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
        result.push_back(connectedDepartments[v]);

    reverse(result.begin(), result.end());

    return result;
}

bool DepartmentConnections::checkDepartmentConnectivity() {
    int n = connectedDepartments.size();

    if (n == 0)
        return false;

    vector<bool> visited(n, false);
    vector<int> st;

    st.push_back(0);
    visited[0] = true;

    while (!st.empty()) {
        int u = st.back();
        st.pop_back();

        for (int v : departmentAdjacency[u]) {
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
