#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>

// Custom linked list used by the School domain. No STL containers are used.
template <typename T>
class SchoolLinkedList {
public:
    struct Node { T data; Node* next; Node(const T& value) : data(value), next(nullptr) {} };
private:
    Node* first;
    int itemCount;
public:
    SchoolLinkedList() : first(nullptr), itemCount(0) {}
    ~SchoolLinkedList() { clear(); }
    SchoolLinkedList(const SchoolLinkedList&) = delete;
    SchoolLinkedList& operator=(const SchoolLinkedList&) = delete;
    Node* head() const { return first; }
    int size() const { return itemCount; }
    void append(const T& value) { Node* n = new Node(value); if (!first) first=n; else { Node* p=first; while(p->next) p=p->next; p->next=n; } ++itemCount; }
    bool removeAt(Node* previous, Node* current) { if(!current) return false; if(previous) previous->next=current->next; else first=current->next; delete current; --itemCount; return true; }
    void clear() { while(first) { Node* n=first; first=first->next; delete n; } itemCount=0; }
};

// Custom linked queue.
template <typename T>
class SchoolQueue {
    struct Node { T data; Node* next; Node(const T& v):data(v),next(nullptr){} };
    Node* frontNode; Node* rearNode; int itemCount;
public:
    SchoolQueue():frontNode(nullptr),rearNode(nullptr),itemCount(0){}
    ~SchoolQueue(){ clear(); }
    SchoolQueue(const SchoolQueue&)=delete; SchoolQueue& operator=(const SchoolQueue&)=delete;
    bool empty() const { return frontNode==nullptr; }
    int size() const { return itemCount; }
    void enqueue(const T& v){ Node* n=new Node(v); if(rearNode) rearNode->next=n; else frontNode=n; rearNode=n; ++itemCount; }
    bool dequeue(T& out){ if(!frontNode)return false; Node* n=frontNode; out=n->data; frontNode=n->next; if(!frontNode)rearNode=nullptr; delete n; --itemCount; return true; }
    bool peek(T& out) const { if(!frontNode)return false; out=frontNode->data; return true; }
    bool removeValue(const T& value){ Node* p=nullptr; Node* c=frontNode; while(c && !(c->data==value)){p=c;c=c->next;} if(!c)return false; if(p)p->next=c->next;else frontNode=c->next; if(rearNode==c)rearNode=p;delete c;--itemCount;return true; }
    void clear(){ T ignored; while(dequeue(ignored)){} }
};

// Custom linked stack.
template <typename T>
class SchoolStack {
    struct Node { T data; Node* next; Node(const T& v,Node* n):data(v),next(n){} };
    Node* topNode; int itemCount;
public:
    SchoolStack():topNode(nullptr),itemCount(0){}
    ~SchoolStack(){clear();}
    SchoolStack(const SchoolStack&)=delete; SchoolStack& operator=(const SchoolStack&)=delete;
    bool empty()const{return topNode==nullptr;} int size()const{return itemCount;}
    void push(const T&v){topNode=new Node(v,topNode);++itemCount;}
    bool pop(T&out){if(!topNode)return false;Node*n=topNode;out=n->data;topNode=n->next;delete n;--itemCount;return true;}
    bool peek(T&out)const{if(!topNode)return false;out=topNode->data;return true;}
    std::string displayTopFirst() const { std::string out; for(Node*n=topNode;n;n=n->next){out+=n->data;out+="\n";} return out; }
    void clear(){while(topNode){Node*n=topNode;topNode=topNode->next;delete n;}itemCount=0;}
};

class StudentManagement {
    struct Student { std::string id,name,details; };
    SchoolLinkedList<Student> students;
public:
    std::string registerStudent(std::string studentID,std::string name);
    std::string removeStudent(std::string studentID);
    bool searchStudent(std::string studentID) const;
    std::string updateStudentDetails(std::string studentID,std::string newDetails);
    std::string displayAllStudents() const;
    int getStudentCount() const { return students.size(); }
};
class StudentService {
    SchoolQueue<std::string> waiting;
public:
    std::string addStudentToQueue(std::string studentID);
    std::string serveNextStudent();
    std::string viewNextStudent() const;
    int getWaitingStudentCount() const { return waiting.size(); }
    std::string removeStudentFromQueue(std::string studentID);
};
class AssignmentManagement {
    struct Assignment { std::string id,title,details; };
    SchoolLinkedList<Assignment> assignments;
public:
    std::string addAssignment(std::string assignmentID,std::string title);
    std::string removeAssignment(std::string assignmentID);
    std::string updateAssignment(std::string assignmentID,std::string newDetails);
    bool searchAssignment(std::string assignmentID) const;
    std::string displayAllAssignments() const;
};
class StudentHistory {
    SchoolStack<std::string> changes;
public:
    std::string recordStudentChange(std::string change);
    std::string undoLastStudentChange();
    std::string viewLastStudentChange() const;
    std::string getStudentChangeHistory() const;
};

class OrganizationHierarchy {
    struct Node { std::string name; Node* parent; Node* firstChild; Node* nextSibling; Node(const std::string& n,Node*p):name(n),parent(p),firstChild(nullptr),nextSibling(nullptr){} };
    Node* root;
    Node* find(Node* n,const std::string& name) const;
    void destroy(Node* n);
    void appendDisplay(Node* n,int depth,std::string& out) const;
    bool detachAndDelete(Node* parent,Node* target);
public:
    OrganizationHierarchy():root(nullptr){} ~OrganizationHierarchy(){destroy(root);}
    OrganizationHierarchy(const OrganizationHierarchy&)=delete; OrganizationHierarchy& operator=(const OrganizationHierarchy&)=delete;
    std::string addOrganizationNode(std::string node);
    std::string removeOrganizationNode(std::string node);
    std::string addSubordinate(std::string parent,std::string child);
    bool searchOrganizationNode(std::string node) const;
    std::string displayOrganizationHierarchy() const;
    int findHierarchyLevel(std::string node) const;
    int countOrganizationMembers() const;
};
class CurriculumManagement {
    struct Node { std::string name; int level; Node* parent; Node* firstChild; Node* nextSibling; Node(const std::string&n,int l,Node*p):name(n),level(l),parent(p),firstChild(nullptr),nextSibling(nullptr){} };
    Node* firstSubject;
    Node* find(Node*n,const std::string&name)const;
    void destroy(Node*n);
    void display(Node*n,std::string&out)const;
    int countTopics(Node*n)const;
    int depth(Node*n)const;
public:
    CurriculumManagement():firstSubject(nullptr){} ~CurriculumManagement(){destroy(firstSubject);}
    CurriculumManagement(const CurriculumManagement&)=delete; CurriculumManagement& operator=(const CurriculumManagement&)=delete;
    std::string addSubject(std::string subject);
    std::string addChapter(std::string subject,std::string chapter);
    std::string addTopic(std::string chapter,std::string topic);
    std::string removeTopic(std::string topic);
    bool searchTopic(std::string topic) const;
    std::string displayCurriculum() const;
    int countTopics() const;
    int findCurriculumDepth() const;
};

// Custom adjacency-list graph. Edges and vertices are dynamically allocated nodes.
class SchoolGraph {
    struct Edge { int to; Edge* next; Edge(int v):to(v),next(nullptr){} };
    struct Vertex { std::string name; Edge* edges; int mark; Vertex* next; Vertex(const std::string&n):name(n),edges(nullptr),mark(0),next(nullptr){} };
    Vertex* first; int vertexCount; bool directed;
    Vertex* at(int index) const;
    int indexOf(const std::string& name) const;
    void clearEdges(Edge* e);
    bool addOneWay(Vertex* from,int to);
public:
    explicit SchoolGraph(bool isDirected=false):first(nullptr),vertexCount(0),directed(isDirected){}
    ~SchoolGraph(); SchoolGraph(const SchoolGraph&)=delete; SchoolGraph& operator=(const SchoolGraph&)=delete;
    bool addVertex(const std::string& name);
    bool addEdge(const std::string& from,const std::string& to);
    bool removeVertex(const std::string& name);
    bool removeEdge(const std::string& from,const std::string& to);
    bool contains(const std::string& name) const;
    int degree(const std::string& name) const;
    std::string neighbors(const std::string& name) const;
    std::string incoming(const std::string& name) const;
    std::string route(const std::string& source,const std::string& destination) const;
    std::string display() const;
    bool connected() const;
    std::string topologicalOrder() const;
    bool hasCycle() const;
};
class CampusNavigation {
    SchoolGraph graph;
public:
    std::string addCampusLocation(std::string location);
    std::string connectCampusLocations(std::string location1,std::string location2);
    std::string removeCampusLocation(std::string location);
    std::string findNearbyLocations(std::string location) const;
    std::string findCampusRoute(std::string source,std::string destination) const;
    std::string findShortestCampusRoute(std::string source,std::string destination) const;
    std::string displayCampusMap() const;
    bool checkCampusConnectivity() const { return graph.connected(); }
};
class SubjectPrerequisites {
    SchoolGraph graph;
public:
    SubjectPrerequisites():graph(true){}
    std::string addSubject(std::string subject);
    std::string addPrerequisite(std::string subject,std::string prerequisite);
    std::string removePrerequisite(std::string subject,std::string prerequisite);
    std::string getPrerequisites(std::string subject) const;
    std::string getDependentSubjects(std::string subject) const;
    bool checkPrerequisites(std::string subject) const;
    std::string getRecommendedSubjectOrder() const;
    bool hasPrerequisiteCycle() const { return graph.hasCycle(); }
};
#endif
