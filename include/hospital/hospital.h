#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <vector>
using namespace std;

// 1. Patient Management - Linked List
class PatientManagement {
public:
    void registerPatient(string patientID, string name);
    void removePatient(string patientID);
    bool searchPatient(string patientID);
    void updatePatientDetails(string patientID, string newDetails);
    void displayAllPatients();
};

// 2. Patient Queue - Queue
class PatientQueue {
public:
    void addPatientToQueue(string patientID);
    void callNextPatient();
    string viewNextPatient();
    int getWaitingCount();
    void cancelPatientVisit(string patientID);
};

// 3. Appointment Management - Linked List
class AppointmentManagement {
public:
    void scheduleAppointment(string patientID, string doctor);
    void cancelAppointment(string appointmentID);
    void rescheduleAppointment(string appointmentID, string newTime);
    bool findAppointment(string appointmentID);
    void displayDoctorSchedule(string doctor);
};

// 4. Patient Record History - Stack
class PatientRecordHistory {
public:
    void recordPatientAction(string action);
    void undoLastRecordAction();
    string viewLastRecordAction();
    void getRecordHistory();
};

// 5. Review Management - Deque
// Excluded as requested.

// 6. Department Hierarchy - Tree
class DepartmentHierarchy {
public:
    void addDepartment(string department);
    void removeDepartment(string department);
    bool searchDepartment(string department);
    void displayDepartmentHierarchy();
    void addSubDepartment(string parent, string child);
    int findDepartmentLevel(string department);
    int getDepartmentCount();
    void displayDepartmentsInOrder();
};

// 7. Medical Record Categories - Tree
class MedicalRecordCategories {
public:
    void addRecordCategory(string category);
    void addSubCategory(string parent, string child);
    bool searchRecordCategory(string category);
    void displayRecordCategories();
};

// 8. Hospital Navigation - Graph
class HospitalNavigation {
public:
    void addHospitalLocation(string location);
    void connectLocations(string location1, string location2);
    void removeLocation(string location);
    vector<string> findConnectedLocations(string location);
    vector<string> findHospitalRoute(string source, string destination);
    vector<string> findShortestHospitalRoute(string source, string destination);
    void displayHospitalMap();
};

// 9. Department Connections - Graph
class DepartmentConnections {
public:
    void connectDepartments(string department1, string department2);
    vector<string> findRelatedDepartments(string department);
    int getDepartmentConnections(string department);
    vector<string> findDepartmentPath(string source, string destination);
    bool checkDepartmentConnectivity();
};

#endif