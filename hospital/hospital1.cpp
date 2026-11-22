#include "hospital.h"

// ---------------- Patient linked list ----------------
std::string PatientManagement::registerPatient(std::string id,std::string name){if(searchPatient(id))return "Patient already exists.";patients.append({id,name,""});return "Patient registered successfully.";}
std::string PatientManagement::removePatient(std::string id){HospitalLinkedList<Patient>::Node*p=nullptr;auto*c=patients.head();while(c&&c->data.id!=id){p=c;c=c->next;}return patients.removeAt(p,c)?"Patient removed successfully.":"Patient not found.";}
bool PatientManagement::searchPatient(std::string id)const{for(auto*n=patients.head();n;n=n->next)if(n->data.id==id)return true;return false;}
std::string PatientManagement::updatePatientDetails(std::string id,std::string d){for(auto*n=patients.head();n;n=n->next)if(n->data.id==id){n->data.details=d;return "Patient details updated.";}return "Patient not found.";}
std::string PatientManagement::displayAllPatients()const{std::string out;for(auto*n=patients.head();n;n=n->next)out+="Patient ID: "+n->data.id+" | Name: "+n->data.name+" | Details: "+n->data.details+"\n";return out;}

// ---------------- Patient waiting queue ----------------
std::string PatientQueue::addPatientToQueue(std::string id){waiting.enqueue(id);return "Patient added to queue.";}
std::string PatientQueue::callNextPatient(){std::string id;return waiting.dequeue(id)?id:"Patient queue is empty.";}
std::string PatientQueue::viewNextPatient()const{std::string id;return waiting.peek(id)?id:"";}
std::string PatientQueue::cancelPatientVisit(std::string id){return waiting.removeValue(id)?"Patient visit cancelled.":"Patient not found in queue.";}

// ---------------- Appointment linked list ----------------
std::string AppointmentManagement::scheduleAppointment(std::string p,std::string d){std::string id="APT";id+=std::to_string(appointmentCounter++);appointments.append({id,p,d,"Not specified"});return id;}
std::string AppointmentManagement::cancelAppointment(std::string id){HospitalLinkedList<Appointment>::Node*p=nullptr;auto*c=appointments.head();while(c&&c->data.id!=id){p=c;c=c->next;}return appointments.removeAt(p,c)?"Appointment cancelled.":"Appointment not found.";}
std::string AppointmentManagement::rescheduleAppointment(std::string id,std::string t){for(auto*n=appointments.head();n;n=n->next)if(n->data.id==id){n->data.time=t;return "Appointment rescheduled.";}return "Appointment not found.";}
bool AppointmentManagement::findAppointment(std::string id)const{for(auto*n=appointments.head();n;n=n->next)if(n->data.id==id)return true;return false;}
std::string AppointmentManagement::displayDoctorSchedule(std::string d)const{std::string out;for(auto*n=appointments.head();n;n=n->next)if(n->data.doctor==d)out+="Appointment ID: "+n->data.id+" | Patient ID: "+n->data.patientID+" | Time: "+n->data.time+"\n";return out;}

// ---------------- Patient action history stack ----------------
std::string PatientRecordHistory::recordPatientAction(std::string a){actions.push(a);return "Patient action recorded.";}
std::string PatientRecordHistory::undoLastRecordAction(){std::string a;return actions.pop(a)?a:"No record actions to undo.";}
std::string PatientRecordHistory::viewLastRecordAction()const{std::string a;return actions.peek(a)?a:"";}
std::string PatientRecordHistory::getRecordHistory()const{return actions.displayTopFirst();}

// ---------------- Custom tree ----------------
HospitalTree::Node* HospitalTree::find(Node*n,const std::string&name)const{if(!n)return nullptr;if(n->name==name)return n;Node*r=find(n->firstChild,name);return r?r:find(n->nextSibling,name);}
void HospitalTree::destroy(Node*n){if(!n)return;destroy(n->firstChild);destroy(n->nextSibling);delete n;}
void HospitalTree::display(Node*n,int d,std::string&out)const{for(Node*c=n;c;c=c->nextSibling){out.append(d*2,' ');out+="|-- "+c->name+"\n";display(c->firstChild,d+1,out);}}
int HospitalTree::count(Node*n)const{int total=0;for(Node*c=n;c;c=c->nextSibling)total+=1+count(c->firstChild);return total;}
bool HospitalTree::removeChild(Node*parent,Node*target){if(!parent||!target)return false;Node**link=&parent->firstChild;while(*link&&*link!=target)link=&((*link)->nextSibling);if(!*link)return false;*link=target->nextSibling;target->nextSibling=nullptr;destroy(target);return true;}
bool HospitalTree::addRoot(const std::string&n){if(root)return false;root=new Node(n,nullptr);return true;}
bool HospitalTree::addChild(const std::string&p,const std::string&c){Node*parent=find(root,p);if(!parent||find(root,c))return false;Node*n=new Node(c,parent);if(!parent->firstChild)parent->firstChild=n;else{Node*x=parent->firstChild;while(x->nextSibling)x=x->nextSibling;x->nextSibling=n;}return true;}
bool HospitalTree::remove(const std::string&n){Node*t=find(root,n);if(!t)return false;if(t==root){destroy(root);root=nullptr;return true;}return removeChild(t->parent,t);}
bool HospitalTree::contains(const std::string&n)const{return find(root,n)!=nullptr;}
int HospitalTree::level(const std::string&n)const{Node*x=find(root,n);if(!x)return -1;int d=0;while(x->parent){++d;x=x->parent;}return d;}
std::string HospitalTree::display()const{std::string out;display(root,0,out);return out;}

// ---------------- Department hierarchy ----------------
std::string DepartmentHierarchy::addDepartment(std::string d){return tree.addRoot(d)?"Department added.":"Hospital root department already exists; use addSubDepartment().";}
std::string DepartmentHierarchy::removeDepartment(std::string d){return tree.remove(d)?"Department and its subdepartments removed.":"Department not found.";}
bool DepartmentHierarchy::searchDepartment(std::string d)const{return tree.contains(d);}
std::string DepartmentHierarchy::displayDepartmentHierarchy()const{return tree.display();}
std::string DepartmentHierarchy::addSubDepartment(std::string p,std::string c){return tree.addChild(p,c)?"Subdepartment added.":"Could not add subdepartment; check parent and duplicate name.";}
int DepartmentHierarchy::findDepartmentLevel(std::string d)const{return tree.level(d);}
std::string DepartmentHierarchy::displayDepartmentsInOrder()const{return tree.display();}

// ---------------- Medical record category tree ----------------
std::string MedicalRecordCategories::addRecordCategory(std::string c){return tree.addRoot(c)?"Record category added.":"Root category already exists; use addSubCategory().";}
std::string MedicalRecordCategories::addSubCategory(std::string p,std::string c){return tree.addChild(p,c)?"Subcategory added.":"Could not add subcategory; check parent and duplicate name.";}
bool MedicalRecordCategories::searchRecordCategory(std::string c)const{return tree.contains(c);}

// ---------------- Custom adjacency-list graph ----------------
HospitalGraph::Vertex* HospitalGraph::at(int i)const{Vertex*v=first;while(v&&i-->0)v=v->next;return v;}
int HospitalGraph::indexOf(const std::string&n)const{int i=0;for(Vertex*v=first;v;v=v->next,++i)if(v->name==n)return i;return -1;}
void HospitalGraph::clearEdges(Edge*e){while(e){Edge*n=e->next;delete e;e=n;}}
bool HospitalGraph::addOneWay(Vertex*v,int to){for(Edge*e=v->edges;e;e=e->next)if(e->to==to)return false;Edge*n=new Edge(to);n->next=v->edges;v->edges=n;return true;}
HospitalGraph::~HospitalGraph(){while(first){Vertex*n=first;first=first->next;clearEdges(n->edges);delete n;}}
bool HospitalGraph::addVertex(const std::string&n){if(indexOf(n)>=0)return false;Vertex*v=new Vertex(n);if(!first)first=v;else{Vertex*x=first;while(x->next)x=x->next;x->next=v;}++vertexCount;return true;}
bool HospitalGraph::addEdge(const std::string&a,const std::string&b){int i=indexOf(a),j=indexOf(b);if(i<0||j<0||i==j)return false;bool changed=addOneWay(at(i),j);if(!directed)addOneWay(at(j),i);return changed;}
bool HospitalGraph::removeEdge(const std::string&a,const std::string&b){int i=indexOf(a),j=indexOf(b);if(i<0||j<0)return false;bool removed=false;auto erase=[&](Vertex*v,int target){Edge*p=nullptr,*c=v->edges;while(c&&c->to!=target){p=c;c=c->next;}if(!c)return false;if(p)p->next=c->next;else v->edges=c->next;delete c;return true;};removed=erase(at(i),j);if(!directed)erase(at(j),i);return removed;}
bool HospitalGraph::removeVertex(const std::string&n){int idx=indexOf(n);if(idx<0)return false;Vertex*p=nullptr,*v=first;for(int i=0;i<idx;++i){p=v;v=v->next;}if(p)p->next=v->next;else first=v->next;clearEdges(v->edges);delete v;--vertexCount;for(Vertex*x=first;x;x=x->next){Edge*prev=nullptr,*e=x->edges;while(e){if(e->to==idx){Edge*old=e;e=e->next;if(prev)prev->next=e;else x->edges=e;delete old;}else{if(e->to>idx)--e->to;prev=e;e=e->next;}}}return true;}
bool HospitalGraph::contains(const std::string&n)const{return indexOf(n)>=0;}
int HospitalGraph::degree(const std::string&n)const{int i=indexOf(n);if(i<0)return 0;int c=0;for(Edge*e=at(i)->edges;e;e=e->next)++c;return c;}
std::string HospitalGraph::neighbors(const std::string&n)const{int i=indexOf(n);if(i<0)return "";std::string out;for(Edge*e=at(i)->edges;e;e=e->next){if(out.size())out+="\n";out+=at(e->to)->name;}return out;}
std::string HospitalGraph::route(const std::string&s,const std::string&d)const{int si=indexOf(s),di=indexOf(d);if(si<0||di<0)return "Route unavailable.";int*prev=new int[vertexCount];bool*seen=new bool[vertexCount];int*q=new int[vertexCount];for(int i=0;i<vertexCount;++i){prev[i]=-1;seen[i]=false;}int h=0,t=0;q[t++]=si;seen[si]=true;while(h<t&&!seen[di]){int u=q[h++];for(Edge*e=at(u)->edges;e;e=e->next)if(!seen[e->to]){seen[e->to]=true;prev[e->to]=u;q[t++]=e->to;}}std::string out;if(seen[di]){int*path=new int[vertexCount];int len=0;for(int x=di;x!=-1;x=prev[x])path[len++]=x;for(int k=len-1;k>=0;--k){if(out.size())out+=" -> ";out+=at(path[k])->name;}delete[]path;}else out="No route found.";delete[]prev;delete[]seen;delete[]q;return out;}
std::string HospitalGraph::display()const{std::string out;for(Vertex*v=first;v;v=v->next){out+=v->name+":";for(Edge*e=v->edges;e;e=e->next)out+=" "+at(e->to)->name;out+="\n";}return out;}
bool HospitalGraph::connected()const{if(vertexCount<=1)return true;bool*seen=new bool[vertexCount];int*q=new int[vertexCount];for(int i=0;i<vertexCount;++i)seen[i]=false;int h=0,t=0;q[t++]=0;seen[0]=true;while(h<t){int u=q[h++];for(Edge*e=at(u)->edges;e;e=e->next)if(!seen[e->to]){seen[e->to]=true;q[t++]=e->to;}}bool ok=true;for(int i=0;i<vertexCount;++i)if(!seen[i])ok=false;delete[]seen;delete[]q;return ok;}

// ---------------- Hospital navigation ----------------
std::string HospitalNavigation::addHospitalLocation(std::string l){return graph.addVertex(l)?"Location added.":"Location already exists.";}
std::string HospitalNavigation::connectLocations(std::string a,std::string b){return graph.addEdge(a,b)?"Locations connected.":"Could not connect locations; check that both exist.";}
std::string HospitalNavigation::removeLocation(std::string l){return graph.removeVertex(l)?"Location removed.":"Location not found.";}
std::string HospitalNavigation::findConnectedLocations(std::string l)const{return graph.neighbors(l);}
std::string HospitalNavigation::findHospitalRoute(std::string s,std::string d)const{return graph.route(s,d);}
std::string HospitalNavigation::findShortestHospitalRoute(std::string s,std::string d)const{return graph.route(s,d);}

// ---------------- Department connection graph ----------------
std::string DepartmentConnections::connectDepartments(std::string a,std::string b){if(!graph.contains(a))graph.addVertex(a);if(!graph.contains(b))graph.addVertex(b);return graph.addEdge(a,b)?"Departments connected.":"Departments already connected.";}
std::string DepartmentConnections::findRelatedDepartments(std::string d)const{return graph.neighbors(d);}
std::string DepartmentConnections::findDepartmentPath(std::string s,std::string d)const{return graph.route(s,d);}
