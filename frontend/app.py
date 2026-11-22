
'''import streamlit as st

st.set_page_config(
    page_title="DSLib",
    page_icon="✩",
    layout="wide"
)

st.title("DSLib : Domain-Specific Data Structures")
st.caption("A C++ data structures library for real-world workflows")


if "items" not in st.session_state:
    st.session_state["items"] = []

if "history" not in st.session_state:
    st.session_state.history = []


domain = st.sidebar.selectbox(
    "Choose domain",
    ["Regular", "Hospital", "School", "Bank"]
)

structure = st.sidebar.selectbox(
    "Choose data structure",
    ["Queue", "Deque", "Stack", "Linked List", "Tree", "Graph"]
)

st.header(f"{domain} | {structure}")


if structure == "Queue":
    st.subheader("Queue Operations")

    with st.form("add_item"):
        item_id = st.text_input("Record ID")
        item_name = st.text_input("Name")
        submitted = st.form_submit_button("Add to Queue")

    if submitted:
        if item_id.strip() and item_name.strip():
            if any(
                item["id"] == item_id.strip()
                for item in st.session_state["items"]
            ):
                st.error("This ID already exists.")
            else:
                st.session_state["items"].append({
                    "id": item_id.strip(),
                    "name": item_name.strip()
                })
                st.session_state.history.append(f"Added {item_id.strip()}")
                st.success("Record added successfully.")
        else:
            st.warning("Enter valid record.")

    col1, col2 = st.columns(2)

    with col1:
        if st.button("Serve Next", use_container_width=True):
            if st.session_state["items"]:
                removed = st.session_state["items"].pop(0)
                st.session_state.history.append(
                    f"Served {removed['id']}"
                )
                st.success(f"Served: {removed['name']}")
            else:
                st.warning("The queue is empty.")

    with col2:
        if st.button("Clear Demo Data", use_container_width=True):
            st.session_state["items"] = []
            st.session_state.history = []
            st.rerun()


    st.subheader("Current Queue")

    if st.session_state["items"]:
        st.dataframe(
            st.session_state["items"],
            use_container_width=True,
            hide_index=True
        )
    else:
        st.write("No records in the queue yet.")

    st.metric(
        "Records Waiting",
        len(st.session_state["items"])
    )

    st.subheader("Recent Activity")
    for event in reversed(st.session_state.history[-5:]):
        st.write("•", event)
'''


import streamlit as st
import pandas as pd
from datetime import date

# ---------------- PAGE CONFIG ----------------
st.set_page_config(
    page_title="DSA Management System",
    page_icon="🎓",
    layout="wide"
)

# ---------------- CUSTOM CSS ----------------
st.markdown("""
<style>
.main {
    background-color: #f5f7fb;
}
[data-testid="stSidebar"] {
    background-color: #172554;
}
[data-testid="stSidebar"] * {
    color: white !important;
}
.metric-card {
    background: white;
    padding: 20px;
    border-radius: 12px;
    border: 1px solid #e5e7eb;
}
h1, h2, h3 {
    color: #172554;
}
</style>
""", unsafe_allow_html=True)

# ---------------- LINKED LIST ----------------
class StudentNode:
    def __init__(self, student_id, name, course, grade):
        self.student_id = student_id
        self.name = name
        self.course = course
        self.grade = grade
        self.next = None


class StudentLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, student_id, name, course, grade):
        new_node = StudentNode(student_id, name, course, grade)

        if self.head is None:
            self.head = new_node
            return

        temp = self.head
        while temp.next:
            temp = temp.next

        temp.next = new_node

    def delete(self, student_id):
        temp = self.head
        prev = None

        while temp:
            if temp.student_id == student_id:
                if prev is None:
                    self.head = temp.next
                else:
                    prev.next = temp.next
                return True

            prev = temp
            temp = temp.next

        return False

    def search(self, student_id):
        temp = self.head
        while temp:
            if temp.student_id == student_id:
                return temp
            temp = temp.next
        return None

    def display(self):
        students = []
        temp = self.head

        while temp:
            students.append({
                "ID": temp.student_id,
                "Name": temp.name,
                "Course": temp.course,
                "Grade": temp.grade
            })
            temp = temp.next

        return students


# ---------------- QUEUE ----------------
class AdmissionQueue:
    def __init__(self):
        self.queue = []

    def enqueue(self, request):
        self.queue.append(request)

    def dequeue(self):
        if self.is_empty():
            return None
        return self.queue.pop(0)

    def peek(self):
        if self.is_empty():
            return None
        return self.queue[0]

    def is_empty(self):
        return len(self.queue) == 0


# ---------------- INITIAL DATA ----------------
if "students" not in st.session_state:
    st.session_state.students = StudentLinkedList()

    st.session_state.students.insert("S101", "Aarav Sharma", "BTech CSE", "A")
    st.session_state.students.insert("S102", "Ananya Gupta", "BTech CSE", "B")
    st.session_state.students.insert("S103", "Rohan Mehta", "BBA", "A")
    st.session_state.students.insert("S104", "Priya Singh", "BTech IT", "A")

if "admissions" not in st.session_state:
    st.session_state.admissions = AdmissionQueue()

if "request_count" not in st.session_state:
    st.session_state.request_count = 0

students = st.session_state.students
admissions = st.session_state.admissions

# ---------------- SIDEBAR ----------------
st.sidebar.title("🎓 DSA SYSTEM")
st.sidebar.caption("Domain Specific Data Structures Library")
st.sidebar.divider()

page = st.sidebar.radio(
    "NAVIGATION",
    [
        "Dashboard",
        "Student Management",
        "Admission Queue",
        "About the Project"
    ]
)

st.sidebar.divider()
st.sidebar.caption("Built using C++ DSA concepts")

# ---------------- DASHBOARD ----------------
if page == "Dashboard":

    st.title("School Management Dashboard")
    st.caption("Overview of school operations and data structures")

    data = students.display()

    col1, col2, col3, col4 = st.columns(4)

    with col1:
        st.metric("Total Students", len(data))

    with col2:
        st.metric("Admission Requests", len(admissions.queue))

    with col3:
        st.metric("Courses", len(set(s["Course"] for s in data)))

    with col4:
        st.metric("Data Structures", "2")

    st.divider()

    left, right = st.columns([2, 1])

    with left:
        st.subheader("Recent Student Records")

        if data:
            st.dataframe(
                pd.DataFrame(data),
                use_container_width=True,
                hide_index=True
            )
        else:
            st.info("No student records available.")

    with right:
        st.subheader("System Modules")

        st.info("🔗 Linked List\n\nStudent record management")

        st.info("📥 Queue\n\nAdmission request processing")

    st.subheader("System Information")

    st.write("""
    This application demonstrates how fundamental Data Structures
    can be implemented in real-world school management operations.

    - Linked List: Dynamic student record management.
    - Queue: First-In-First-Out admission processing.
    """)

# ---------------- STUDENT MANAGEMENT ----------------
elif page == "Student Management":

    st.title("Student Management")
    st.caption("Linked List Implementation")

    tab1, tab2, tab3 = st.tabs([
        "View Students",
        "Add Student",
        "Search / Delete"
    ])

    with tab1:
        st.subheader("Student Records")

        data = students.display()

        if data:
            st.dataframe(pd.DataFrame(data), use_container_width=True,
                         hide_index=True)
        else:
            st.warning("No students found.")

        st.caption("Underlying Structure: Singly Linked List")

    with tab2:
        st.subheader("Register New Student")

        with st.form("add_student"):
            sid = st.text_input("Student ID")
            name = st.text_input("Student Name")
            course = st.selectbox(
                "Course",
                ["BTech CSE", "BTech IT", "BBA", "BCA", "MBA"]
            )
            grade = st.selectbox("Grade", ["A", "B", "C", "D"])

            submit = st.form_submit_button("Add Student")

            if submit:
                if not sid or not name:
                    st.error("Please enter all required details.")
                elif students.search(sid):
                    st.error("Student ID already exists.")
                else:
                    students.insert(sid, name, course, grade)
                    st.success("Student added successfully!")
                    st.rerun()

    with tab3:
        st.subheader("Search Student")

        search_id = st.text_input("Enter Student ID")

        if st.button("Search"):
            result = students.search(search_id)

            if result:
                st.success("Student Found")
                st.write("**Name:**", result.name)
                st.write("**Course:**", result.course)
                st.write("**Grade:**", result.grade)
            else:
                st.error("Student not found.")

        st.divider()

        st.subheader("Delete Student")

        delete_id = st.text_input("Student ID to delete")

        if st.button("Delete Student"):
            if students.delete(delete_id):
                st.success("Student deleted successfully!")
                st.rerun()
            else:
                st.error("Student ID not found.")

# ---------------- ADMISSION QUEUE ----------------
elif page == "Admission Queue":

    st.title("Admission Request Management")
    st.caption("Queue Data Structure | First In First Out (FIFO)")

    col1, col2 = st.columns(2)

    with col1:
        st.metric("Pending Requests", len(admissions.queue))

    with col2:
        st.metric("Total Requests Received", st.session_state.request_count)

    st.divider()

    st.subheader("Add Admission Request")

    with st.form("admission_form"):
        applicant = st.text_input("Applicant Name")
        applicant_id = st.text_input("Application ID")
        requested_course = st.selectbox(
            "Course Applied For",
            ["BTech CSE", "BTech IT", "BBA", "BCA", "MBA"]
        )

        add_request = st.form_submit_button("Add to Queue")

        if add_request:
            if applicant and applicant_id:
                if any(r["ID"] == applicant_id for r in admissions.queue):
                    st.error("Application ID already exists in queue.")
                else:
                    admissions.enqueue({
                        "ID": applicant_id,
                        "Name": applicant,
                        "Course": requested_course
                    })
                    st.session_state.request_count += 1
                    st.success("Request added to admission queue!")
                    st.rerun()
            else:
                st.error("Please enter applicant details.")

    st.divider()

    st.subheader("Pending Admission Requests")

    if admissions.queue:
        for i, request in enumerate(admissions.queue):
            st.write(
                f"**{i+1}. {request['Name']}** — "
                f"{request['ID']} | {request['Course']}"
            )

        st.info("Requests are processed in First-In First-Out order.")

        if st.button("Process Next Request"):
            processed = admissions.dequeue()

            if processed:
                st.success(
                    f"Processed application of {processed['Name']}"
                )
                st.rerun()

    else:
        st.info("No pending admission requests.")

# ---------------- ABOUT ----------------
elif page == "About the Project":

    st.title("About the Project")

    st.subheader("Domain Specific Data Structures Library")

    st.write("""
    A C++ based Data Structures Library designed to provide
    reusable data structure implementations for domain-specific
    applications.

    Instead of using generic data structures alone, this project
    connects them with practical real-world operations.
    """)

    st.subheader("Implemented Modules")

    st.markdown("""
    **1. Student Management — Linked List**
    - Insert student records
    - Delete student records
    - Search student records
    - Display all students

    **2. Admission Management — Queue**
    - Enqueue admission requests
    - Dequeue processed requests
    - View the front request
    - Maintain FIFO order
    """)

    st.subheader("Technology Stack")

    st.write("""
    - Core Library: C++
    - Frontend: Streamlit
    - Data Structures: Linked List and Queue
    - Interface: Python
    """)

    st.success("Demonstrating the practical application of DSA concepts.")

