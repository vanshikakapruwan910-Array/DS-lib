
#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>
#include <vector>
using namespace std;

// 1. Student Management - Linked List
class StudentManagement {
public:
    void registerStudent(string studentID, string name);
    void removeStudent(string studentID);
    bool searchStudent(string studentID);
    void updateStudentDetails(string studentID, string newDetails);
    void displayAllStudents();
};

// 2. Student Service Queue - Queue
class StudentService {
public:
    void addStudentToQueue(string studentID);
    void serveNextStudent();
    string viewNextStudent();
    int getWaitingStudentCount();
    void removeStudentFromQueue(string studentID);
};

// 3. Assignment Management - Linked List
class AssignmentManagement {
public:
    void addAssignment(string assignmentID, string title);
    void removeAssignment(string assignmentID);
    void updateAssignment(string assignmentID, string newDetails);
    bool searchAssignment(string assignmentID);
    void displayAllAssignments();
};

// 4. Student Record History - Stack
class StudentHistory {
public:
    void recordStudentChange(string change);
    void undoLastStudentChange();
    string viewLastStudentChange();
    void getStudentChangeHistory();
};

// 5. Organizational Hierarchy - Tree
class OrganizationHierarchy {
public:
    void addOrganizationNode(string node);
    void removeOrganizationNode(string node);
    void addSubordinate(string parent, string child);
    bool searchOrganizationNode(string node);
    void displayOrganizationHierarchy();
    int findHierarchyLevel(string node);
    int countOrganizationMembers();
};

// 6. Curriculum Management - Tree
class CurriculumManagement {
public:
    void addSubject(string subject);
    void addChapter(string subject, string chapter);
    void addTopic(string chapter, string topic);
    void removeTopic(string topic);
    bool searchTopic(string topic);
    void displayCurriculum();
    int countTopics();
    int findCurriculumDepth();
};

// 7. Campus Navigation - Graph
class CampusNavigation {
public:
    void addCampusLocation(string location);
    void connectCampusLocations(string location1, string location2);
    void removeCampusLocation(string location);
    vector<string> findNearbyLocations(string location);
    vector<string> findCampusRoute(string source, string destination);
    vector<string> findShortestCampusRoute(string source, string destination);
    void displayCampusMap();
    bool checkCampusConnectivity();
};

// 8. Subject Prerequisites - Graph
class SubjectPrerequisites {
public:
    void addSubject(string subject);
    void addPrerequisite(string subject, string prerequisite);
    void removePrerequisite(string subject, string prerequisite);
    vector<string> getPrerequisites(string subject);
    vector<string> getDependentSubjects(string subject);
    bool checkPrerequisites(string subject);
    vector<string> getRecommendedSubjectOrder();
    bool hasPrerequisiteCycle();
};

#endif
