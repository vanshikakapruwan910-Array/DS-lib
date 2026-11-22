#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>

template <typename T>
class HospitalLinkedList {
public:
    struct Node { T data; Node* next; Node(const T&v):data(v),next(nullptr){} };
private: Node* first; int itemCount;
public:
    HospitalLinkedList():first(nullptr),itemCount(0){} ~HospitalLinkedList(){clear();}
    HospitalLinkedList(const HospitalLinkedList&)=delete; HospitalLinkedList& operator=(const HospitalLinkedList&)=delete;
    Node* head()const{return first;} int size()const{return itemCount;}
    void append(const T&v){Node*n=new Node(v);if(!first)first=n;else{Node*p=first;while(p->next)p=p->next;p->next=n;}++itemCount;}
    bool removeAt(Node*p,Node*c){if(!c)return false;if(p)p->next=c->next;else first=c->next;delete c;--itemCount;return true;}
    void clear(){while(first){Node*n=first;first=first->next;delete n;}itemCount=0;}
};
template <typename T>
class HospitalQueue {
    struct Node{T data;Node*next;Node(const T&v):data(v),next(nullptr){}};
    Node*frontNode;Node*rearNode;int itemCount;
public:
    HospitalQueue():frontNode(nullptr),rearNode(nullptr),itemCount(0){}~HospitalQueue(){clear();}
    HospitalQueue(const HospitalQueue&)=delete;HospitalQueue&operator=(const HospitalQueue&)=delete;
    bool empty()const{return !frontNode;}int size()const{return itemCount;}
    void enqueue(const T&v){Node*n=new Node(v);if(rearNode)rearNode->next=n;else frontNode=n;rearNode=n;++itemCount;}
    bool dequeue(T&out){if(!frontNode)return false;Node*n=frontNode;out=n->data;frontNode=n->next;if(!frontNode)rearNode=nullptr;delete n;--itemCount;return true;}
    bool peek(T&out)const{if(!frontNode)return false;out=frontNode->data;return true;}
    bool removeValue(const T&v){Node*p=nullptr;Node*c=frontNode;while(c&&!(c->data==v)){p=c;c=c->next;}if(!c)return false;if(p)p->next=c->next;else frontNode=c->next;if(rearNode==c)rearNode=p;delete c;--itemCount;return true;}
    void clear(){T x;while(dequeue(x)){}}
};
template <typename T>
class HospitalStack {
    struct Node{T data;Node*next;Node(const T&v,Node*n):data(v),next(n){}};Node*topNode;int itemCount;
public:
    HospitalStack():topNode(nullptr),itemCount(0){}~HospitalStack(){clear();}
    HospitalStack(const HospitalStack&)=delete;HospitalStack&operator=(const HospitalStack&)=delete;
    bool empty()const{return !topNode;}int size()const{return itemCount;}
    void push(const T&v){topNode=new Node(v,topNode);++itemCount;}
    bool pop(T&out){if(!topNode)return false;Node*n=topNode;out=n->data;topNode=n->next;delete n;--itemCount;return true;}
    bool peek(T&out)const{if(!topNode)return false;out=topNode->data;return true;}
    std::string displayTopFirst()const{std::string out;for(Node*n=topNode;n;n=n->next){out+=n->data;out+="\n";}return out;}
    void clear(){while(topNode){Node*n=topNode;topNode=topNode->next;delete n;}itemCount=0;}
};

class PatientManagement {
    struct Patient{std::string id,name,details;};HospitalLinkedList<Patient> patients;
public:
    std::string registerPatient(std::string patientID,std::string name);
    std::string removePatient(std::string patientID);
    bool searchPatient(std::string patientID)const;
    std::string updatePatientDetails(std::string patientID,std::string newDetails);
    std::string displayAllPatients()const;
    int getPatientCount()const{return patients.size();}
};
class PatientQueue {
    HospitalQueue<std::string> waiting;
public:
    std::string addPatientToQueue(std::string patientID);
    std::string callNextPatient();
    std::string viewNextPatient()const;
    int getWaitingCount()const{return waiting.size();}
    std::string cancelPatientVisit(std::string patientID);
};
class AppointmentManagement {
    struct Appointment{std::string id,patientID,doctor,time;};
    HospitalLinkedList<Appointment> appointments;unsigned int appointmentCounter;
public:
    AppointmentManagement():appointmentCounter(1){}
    std::string scheduleAppointment(std::string patientID,std::string doctor);
    std::string cancelAppointment(std::string appointmentID);
    std::string rescheduleAppointment(std::string appointmentID,std::string newTime);
    bool findAppointment(std::string appointmentID)const;
    std::string displayDoctorSchedule(std::string doctor)const;
    int getAppointmentCount()const{return appointments.size();}
};
class PatientRecordHistory {
    HospitalStack<std::string> actions;
public:
    std::string recordPatientAction(std::string action);
    std::string undoLastRecordAction();
    std::string viewLastRecordAction()const;
    std::string getRecordHistory()const;
};

class HospitalTree {
public:
    struct Node{std::string name;Node*parent;Node*firstChild;Node*nextSibling;Node(const std::string&n,Node*p):name(n),parent(p),firstChild(nullptr),nextSibling(nullptr){}};
private:Node*root;
    Node*find(Node*n,const std::string&name)const;void destroy(Node*n);void display(Node*n,int depth,std::string&out)const;int count(Node*n)const;bool removeChild(Node*parent,Node*target);
public:
    HospitalTree():root(nullptr){}~HospitalTree(){destroy(root);}
    HospitalTree(const HospitalTree&)=delete;HospitalTree&operator=(const HospitalTree&)=delete;
    bool addRoot(const std::string&name);bool addChild(const std::string&parent,const std::string&child);bool remove(const std::string&name);bool contains(const std::string&name)const;int level(const std::string&name)const;int size()const{return count(root);}std::string display()const;
};
class DepartmentHierarchy {
    HospitalTree tree;
public:
    std::string addDepartment(std::string department);
    std::string removeDepartment(std::string department);
    bool searchDepartment(std::string department)const;
    std::string displayDepartmentHierarchy()const;
    std::string addSubDepartment(std::string parent,std::string child);
    int findDepartmentLevel(std::string department)const;
    int getDepartmentCount()const{return tree.size();}
    std::string displayDepartmentsInOrder()const;
};
class MedicalRecordCategories {
    HospitalTree tree;
public:
    std::string addRecordCategory(std::string category);
    std::string addSubCategory(std::string parent,std::string child);
    bool searchRecordCategory(std::string category)const;
    std::string displayRecordCategories()const{return tree.display();}
};

class HospitalGraph {
    struct Edge{int to;Edge*next;Edge(int v):to(v),next(nullptr){}};
    struct Vertex{std::string name;Edge*edges;int mark;Vertex*next;Vertex(const std::string&n):name(n),edges(nullptr),mark(0),next(nullptr){}};
    Vertex*first;int vertexCount;bool directed;
    Vertex*at(int i)const;int indexOf(const std::string&name)const;void clearEdges(Edge*e);bool addOneWay(Vertex*from,int to);
public:
    explicit HospitalGraph(bool d=false):first(nullptr),vertexCount(0),directed(d){}~HospitalGraph();
    HospitalGraph(const HospitalGraph&)=delete;HospitalGraph&operator=(const HospitalGraph&)=delete;
    bool addVertex(const std::string&name);bool addEdge(const std::string&a,const std::string&b);bool removeVertex(const std::string&name);bool removeEdge(const std::string&a,const std::string&b);
    bool contains(const std::string&name)const;int degree(const std::string&name)const;std::string neighbors(const std::string&name)const;std::string route(const std::string&s,const std::string&d)const;std::string display()const;bool connected()const;
};
class HospitalNavigation {
    HospitalGraph graph;
public:
    std::string addHospitalLocation(std::string location);
    std::string connectLocations(std::string location1,std::string location2);
    std::string removeLocation(std::string location);
    std::string findConnectedLocations(std::string location)const;
    std::string findHospitalRoute(std::string source,std::string destination)const;
    std::string findShortestHospitalRoute(std::string source,std::string destination)const;
    std::string displayHospitalMap()const{return graph.display();}
};
class DepartmentConnections {
    HospitalGraph graph;
public:
    std::string connectDepartments(std::string department1,std::string department2);
    std::string findRelatedDepartments(std::string department)const;
    int getDepartmentConnections(std::string department)const{return graph.degree(department);}
    std::string findDepartmentPath(std::string source,std::string destination)const;
    bool checkDepartmentConnectivity()const{return graph.connected();}
};
#endif
