#include "school.h"

// ---------------- Student linked list ----------------
std::string StudentManagement::registerStudent(std::string id,std::string name){if(searchStudent(id))return "Student already exists.";students.append({id,name,""});return "Student registered successfully.";}
std::string StudentManagement::removeStudent(std::string id){auto*p=(SchoolLinkedList<Student>::Node*)nullptr;auto*c=students.head();while(c&&c->data.id!=id){p=c;c=c->next;}return students.removeAt(p,c)?"Student removed successfully.":"Student not found.";}
bool StudentManagement::searchStudent(std::string id)const{for(auto*n=students.head();n;n=n->next)if(n->data.id==id)return true;return false;}
std::string StudentManagement::updateStudentDetails(std::string id,std::string d){for(auto*n=students.head();n;n=n->next)if(n->data.id==id){n->data.details=d;return "Student details updated.";}return "Student not found.";}
std::string StudentManagement::displayAllStudents()const{std::string out;for(auto*n=students.head();n;n=n->next){out+="ID: "+n->data.id+" | Name: "+n->data.name+" | Details: "+n->data.details+"\n";}return out;}

// ---------------- Student service queue ----------------
std::string StudentService::addStudentToQueue(std::string id){waiting.enqueue(id);return "Student added to service queue.";}
std::string StudentService::serveNextStudent(){std::string id;return waiting.dequeue(id)?id:"Service queue is empty.";}
std::string StudentService::viewNextStudent()const{std::string id;return waiting.peek(id)?id:"";}
std::string StudentService::removeStudentFromQueue(std::string id){return waiting.removeValue(id)?"Student removed from queue.":"Student not found in queue.";}

// ---------------- Assignment linked list ----------------
std::string AssignmentManagement::addAssignment(std::string id,std::string title){if(searchAssignment(id))return "Assignment already exists.";assignments.append({id,title,""});return "Assignment added successfully.";}
std::string AssignmentManagement::removeAssignment(std::string id){auto*p=(SchoolLinkedList<Assignment>::Node*)nullptr;auto*c=assignments.head();while(c&&c->data.id!=id){p=c;c=c->next;}return assignments.removeAt(p,c)?"Assignment removed.":"Assignment not found.";}
std::string AssignmentManagement::updateAssignment(std::string id,std::string d){for(auto*n=assignments.head();n;n=n->next)if(n->data.id==id){n->data.details=d;return "Assignment updated.";}return "Assignment not found.";}
bool AssignmentManagement::searchAssignment(std::string id)const{for(auto*n=assignments.head();n;n=n->next)if(n->data.id==id)return true;return false;}
std::string AssignmentManagement::displayAllAssignments()const{std::string out;for(auto*n=assignments.head();n;n=n->next)out+="ID: "+n->data.id+" | Title: "+n->data.title+" | Details: "+n->data.details+"\n";return out;}

// ---------------- Student history stack ----------------
std::string StudentHistory::recordStudentChange(std::string c){changes.push(c);return "Change recorded.";}
std::string StudentHistory::undoLastStudentChange(){std::string c;return changes.pop(c)?c:"No changes to undo.";}
std::string StudentHistory::viewLastStudentChange()const{std::string c;return changes.peek(c)?c:"";}
std::string StudentHistory::getStudentChangeHistory()const{return changes.displayTopFirst();}

// ---------------- Organization tree ----------------
OrganizationHierarchy::Node* OrganizationHierarchy::find(Node*n,const std::string&name)const{if(!n)return nullptr;if(n->name==name)return n;Node*r=find(n->firstChild,name);return r?r:find(n->nextSibling,name);}
void OrganizationHierarchy::destroy(Node*n){if(!n)return;destroy(n->firstChild);destroy(n->nextSibling);delete n;}
void OrganizationHierarchy::appendDisplay(Node*n,int d,std::string&out)const{for(Node*c=n;c;c=c->nextSibling){out.append(d*2,' ');out+="|-- "+c->name+"\n";appendDisplay(c->firstChild,d+1,out);}}
bool OrganizationHierarchy::detachAndDelete(Node*parent,Node*target){if(!parent||!target)return false;Node**link=&parent->firstChild;while(*link&&*link!=target)link=&((*link)->nextSibling);if(!*link)return false;*link=target->nextSibling;target->nextSibling=nullptr;destroy(target);return true;}
std::string OrganizationHierarchy::addOrganizationNode(std::string n){if(root)return "Organization root already exists.";root=new Node(n,nullptr);return "Organization node added.";}
std::string OrganizationHierarchy::removeOrganizationNode(std::string n){Node*t=find(root,n);if(!t)return "Organization node not found.";if(t==root){destroy(root);root=nullptr;}else detachAndDelete(t->parent,t);return "Organization node and its subtree removed.";}
std::string OrganizationHierarchy::addSubordinate(std::string p,std::string c){Node*parent=find(root,p);if(!parent)return "Parent node not found.";if(find(root,c))return "Child node already exists.";Node*n=new Node(c,parent);if(!parent->firstChild)parent->firstChild=n;else{Node*x=parent->firstChild;while(x->nextSibling)x=x->nextSibling;x->nextSibling=n;}return "Subordinate added.";}
bool OrganizationHierarchy::searchOrganizationNode(std::string n)const{return find(root,n)!=nullptr;}
std::string OrganizationHierarchy::displayOrganizationHierarchy()const{std::string out;appendDisplay(root,0,out);return out;}
int OrganizationHierarchy::findHierarchyLevel(std::string n)const{Node*x=find(root,n);if(!x)return -1;int d=0;while(x->parent){++d;x=x->parent;}return d;}
int OrganizationHierarchy::countOrganizationMembers()const{int count=0;for(Node*n=root;n;){++count;if(n->firstChild){n=n->firstChild;continue;}while(n&&!n->nextSibling)n=n->parent;if(n)n=n->nextSibling;}return count;}

// ---------------- Curriculum tree ----------------
CurriculumManagement::Node* CurriculumManagement::find(Node*n,const std::string&name)const{for(Node*c=n;c;c=c->nextSibling){if(c->name==name)return c;Node*r=find(c->firstChild,name);if(r)return r;}return nullptr;}
void CurriculumManagement::destroy(Node*n){if(!n)return;destroy(n->firstChild);destroy(n->nextSibling);delete n;}
void CurriculumManagement::display(Node*n,std::string&out)const{for(Node*c=n;c;c=c->nextSibling){out.append(c->level*2,' ');out+="|-- "+c->name+"\n";display(c->firstChild,out);}}
int CurriculumManagement::countTopics(Node*n)const{int total=0;for(Node*c=n;c;c=c->nextSibling){if(c->level==2)++total;total+=countTopics(c->firstChild);}return total;}
int CurriculumManagement::depth(Node*n)const{int best=0;for(Node*c=n;c;c=c->nextSibling){int d=depth(c->firstChild)+(c->level?1:0);if(d>best)best=d;}return best;}
std::string CurriculumManagement::addSubject(std::string s){if(find(firstSubject,s))return "Subject already exists.";Node*n=new Node(s,0,nullptr);if(!firstSubject)firstSubject=n;else{Node*c=firstSubject;while(c->nextSibling)c=c->nextSibling;c->nextSibling=n;}return "Subject added.";}
std::string CurriculumManagement::addChapter(std::string s,std::string c){Node*p=find(firstSubject,s);if(!p||p->level!=0)return "Subject not found.";if(find(firstSubject,c))return "Chapter already exists.";Node*n=new Node(c,1,p);if(!p->firstChild)p->firstChild=n;else{Node*x=p->firstChild;while(x->nextSibling)x=x->nextSibling;x->nextSibling=n;}return "Chapter added.";}
std::string CurriculumManagement::addTopic(std::string ch,std::string t){Node*p=find(firstSubject,ch);if(!p||p->level!=1)return "Chapter not found.";if(find(firstSubject,t))return "Topic already exists.";Node*n=new Node(t,2,p);if(!p->firstChild)p->firstChild=n;else{Node*x=p->firstChild;while(x->nextSibling)x=x->nextSibling;x->nextSibling=n;}return "Topic added.";}
std::string CurriculumManagement::removeTopic(std::string t){Node*x=find(firstSubject,t);if(!x||x->level!=2)return "Topic not found.";Node*p=x->parent;Node**link=&p->firstChild;while(*link&&*link!=x)link=&((*link)->nextSibling);if(*link){*link=x->nextSibling;x->nextSibling=nullptr;destroy(x);}return "Topic removed.";}
bool CurriculumManagement::searchTopic(std::string t)const{Node*n=find(firstSubject,t);return n&&n->level==2;}
std::string CurriculumManagement::displayCurriculum()const{std::string out;display(firstSubject,out);return out;}
int CurriculumManagement::countTopics()const{return countTopics(firstSubject);}
int CurriculumManagement::findCurriculumDepth()const{return depth(firstSubject);}

// ---------------- Custom adjacency-list graph ----------------
SchoolGraph::Vertex* SchoolGraph::at(int i)const{Vertex*v=first;while(v&&i-->0)v=v->next;return v;}
int SchoolGraph::indexOf(const std::string&n)const{int i=0;for(Vertex*v=first;v;v=v->next,++i)if(v->name==n)return i;return -1;}
void SchoolGraph::clearEdges(Edge*e){while(e){Edge*n=e->next;delete e;e=n;}}
bool SchoolGraph::addOneWay(Vertex*f,int to){for(Edge*e=f->edges;e;e=e->next)if(e->to==to)return false;Edge*e=new Edge(to);e->next=f->edges;f->edges=e;return true;}
SchoolGraph::~SchoolGraph(){while(first){Vertex*n=first;first=first->next;clearEdges(n->edges);delete n;}}
bool SchoolGraph::addVertex(const std::string&n){if(indexOf(n)>=0)return false;Vertex*v=new Vertex(n);if(!first)first=v;else{Vertex*x=first;while(x->next)x=x->next;x->next=v;}++vertexCount;return true;}
bool SchoolGraph::addEdge(const std::string&a,const std::string&b){int i=indexOf(a),j=indexOf(b);if(i<0||j<0||i==j)return false;bool changed=addOneWay(at(i),j);if(!directed)addOneWay(at(j),i);return changed;}
bool SchoolGraph::removeEdge(const std::string&a,const std::string&b){int i=indexOf(a),j=indexOf(b);if(i<0||j<0)return false;bool removed=false;auto erase=[&](Vertex*v,int target){Edge*p=nullptr,*c=v->edges;while(c&&c->to!=target){p=c;c=c->next;}if(!c)return false;if(p)p->next=c->next;else v->edges=c->next;delete c;return true;};removed=erase(at(i),j);if(!directed)erase(at(j),i);return removed;}
bool SchoolGraph::removeVertex(const std::string&n){
    int idx=indexOf(n); if(idx<0) return false;
    Vertex* previous=nullptr; Vertex* victim=first;
    for(int i=0;i<idx;++i){previous=victim;victim=victim->next;}
    if(previous) previous->next=victim->next; else first=victim->next;
    clearEdges(victim->edges); delete victim; --vertexCount;
    for(Vertex*x=first;x;x=x->next){
        Edge* edgePrevious=nullptr; Edge* edge=x->edges;
        while(edge){
            if(edge->to==idx){Edge* removed=edge;edge=edge->next;if(edgePrevious)edgePrevious->next=edge;else x->edges=edge;delete removed;}
            else {if(edge->to>idx)--edge->to;edgePrevious=edge;edge=edge->next;}
        }
    }
    return true;
}
bool SchoolGraph::contains(const std::string&n)const{return indexOf(n)>=0;}
int SchoolGraph::degree(const std::string&n)const{int i=indexOf(n);if(i<0)return 0;int c=0;for(Edge*e=at(i)->edges;e;e=e->next)++c;return c;}
std::string SchoolGraph::neighbors(const std::string&n)const{int i=indexOf(n);if(i<0)return "";std::string out;for(Edge*e=at(i)->edges;e;e=e->next){if(out.size())out+="\n";out+=at(e->to)->name;}return out;}
std::string SchoolGraph::incoming(const std::string&n)const{int target=indexOf(n);if(target<0)return "";std::string out;int i=0;for(Vertex*v=first;v;v=v->next,++i)for(Edge*e=v->edges;e;e=e->next)if(e->to==target){if(out.size())out+="\n";out+=v->name;}return out;}
std::string SchoolGraph::route(const std::string&s,const std::string&d)const{int si=indexOf(s),di=indexOf(d);if(si<0||di<0)return "Route unavailable.";int*prev=new int[vertexCount];bool*seen=new bool[vertexCount];int*q=new int[vertexCount];for(int i=0;i<vertexCount;++i){prev[i]=-1;seen[i]=false;}int h=0,t=0;q[t++]=si;seen[si]=true;while(h<t&&!seen[di]){int u=q[h++];for(Edge*e=at(u)->edges;e;e=e->next)if(!seen[e->to]){seen[e->to]=true;prev[e->to]=u;q[t++]=e->to;}}std::string out;if(seen[di]){int*path=new int[vertexCount];int len=0;for(int x=di;x!=-1;x=prev[x])path[len++]=x;for(int k=len-1;k>=0;--k){if(out.size())out+=" -> ";out+=at(path[k])->name;}delete[]path;}else out="No route found.";delete[]prev;delete[]seen;delete[]q;return out;}
std::string SchoolGraph::display()const{std::string out;for(Vertex*v=first;v;v=v->next){out+=v->name+":";for(Edge*e=v->edges;e;e=e->next)out+=" "+at(e->to)->name;out+="\n";}return out;}
bool SchoolGraph::connected()const{if(vertexCount<=1)return true;bool*seen=new bool[vertexCount];int*q=new int[vertexCount];for(int i=0;i<vertexCount;++i)seen[i]=false;int h=0,t=0;q[t++]=0;seen[0]=true;while(h<t){int u=q[h++];for(Edge*e=at(u)->edges;e;e=e->next)if(!seen[e->to]){seen[e->to]=true;q[t++]=e->to;}}bool ok=true;for(int i=0;i<vertexCount;++i)if(!seen[i])ok=false;delete[]seen;delete[]q;return ok;}
std::string SchoolGraph::topologicalOrder()const{int*in=new int[vertexCount];bool*done=new bool[vertexCount];int*q=new int[vertexCount];for(int i=0;i<vertexCount;++i){in[i]=0;done[i]=false;}for(Vertex*v=first;v;v=v->next)for(Edge*e=v->edges;e;e=e->next)++in[e->to];int h=0,t=0;for(int i=0;i<vertexCount;++i)if(in[i]==0)q[t++]=i;std::string out;int processed=0;while(h<t){int u=q[h++];if(out.size())out+=" -> ";out+=at(u)->name;++processed;done[u]=true;for(Edge*e=at(u)->edges;e;e=e->next)if(--in[e->to]==0)q[t++]=e->to;}if(processed!=vertexCount)out="Cycle detected: no valid subject order.";delete[]in;delete[]done;delete[]q;return out;}
bool SchoolGraph::hasCycle()const{int*in=new int[vertexCount];int*q=new int[vertexCount];for(int i=0;i<vertexCount;++i)in[i]=0;for(Vertex*v=first;v;v=v->next)for(Edge*e=v->edges;e;e=e->next)++in[e->to];int h=0,t=0;for(int i=0;i<vertexCount;++i)if(!in[i])q[t++]=i;int n=0;while(h<t){int u=q[h++];++n;for(Edge*e=at(u)->edges;e;e=e->next)if(--in[e->to]==0)q[t++]=e->to;}delete[]in;delete[]q;return n!=vertexCount;}

// ---------------- Campus navigation ----------------
std::string CampusNavigation::addCampusLocation(std::string l){return graph.addVertex(l)?"Campus location added.":"Location already exists.";}
std::string CampusNavigation::connectCampusLocations(std::string a,std::string b){return graph.addEdge(a,b)?"Campus locations connected.":"Could not connect locations; check that both exist.";}
std::string CampusNavigation::removeCampusLocation(std::string l){return graph.removeVertex(l)?"Campus location removed.":"Location not found.";}
std::string CampusNavigation::findNearbyLocations(std::string l)const{return graph.neighbors(l);}
std::string CampusNavigation::findCampusRoute(std::string s,std::string d)const{return graph.route(s,d);}
std::string CampusNavigation::findShortestCampusRoute(std::string s,std::string d)const{return graph.route(s,d);}
std::string CampusNavigation::displayCampusMap()const{return graph.display();}

// ---------------- Directed prerequisite graph ----------------
std::string SubjectPrerequisites::addSubject(std::string s){return graph.addVertex(s)?"Subject added.":"Subject already exists.";}
std::string SubjectPrerequisites::addPrerequisite(std::string subject,std::string prerequisite){if(!graph.contains(subject)||!graph.contains(prerequisite))return "Add both subjects before linking them.";return graph.addEdge(prerequisite,subject)?"Prerequisite added.":"Prerequisite already exists or is invalid.";}
std::string SubjectPrerequisites::removePrerequisite(std::string subject,std::string prerequisite){return graph.removeEdge(prerequisite,subject)?"Prerequisite removed.":"Prerequisite relationship not found.";}
std::string SubjectPrerequisites::getPrerequisites(std::string s)const{return graph.incoming(s);}
std::string SubjectPrerequisites::getDependentSubjects(std::string s)const{return graph.neighbors(s);}
bool SubjectPrerequisites::checkPrerequisites(std::string s)const{return graph.incoming(s).size()!=0;}
std::string SubjectPrerequisites::getRecommendedSubjectOrder()const{return graph.topologicalOrder();}
