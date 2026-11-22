
import streamlit as st
import dslib
import json
from pathlib import Path

# ==================================================
# PAGE CONFIGURATION
# ==================================================

st.set_page_config(
    page_title="DSLib",
    page_icon="📚",
    layout="wide"
)

DATA_FILE = Path(__file__).with_name("dslib_data.json")

# ==================================================
# CSS
# ==================================================

st.markdown("""
<style>
    .stApp {
        background-color: #ffffff;
        color: #000000;
    }

    [data-testid="stSidebar"] {
        background-color: #f5f5f5;
    }

    html, body, p, span, label,
    h1, h2, h3, h4, h5, h6,
    .stMarkdown, .stText,
    [data-testid="stMetricLabel"],
    [data-testid="stMetricValue"] {
        color: #000000 !important;
    }

    input, textarea {
        color: #000000 !important;
        background-color: #ffffff !important;
    }

    div[data-baseweb="select"] * {
        color: #000000 !important;
    }

    button {
        color: #000000 !important;
    }

    [data-testid="stTabs"] button {
        color: #000000 !important;
    }

    .stButton button {
        background-color: #eeeeee;
        border: 1px solid #cccccc;
    }

    .stButton button:hover {
        border-color: #555555;
    }
</style>
""", unsafe_allow_html=True)


# ==================================================
# DATA STRUCTURE OBJECTS
# ==================================================

CLASSES = {
    "students": dslib.StudentManagement,
    "student_queue": dslib.StudentService,
    "assignments": dslib.AssignmentManagement,
    "student_history": dslib.StudentHistory,
    "organization": dslib.OrganizationHierarchy,
    "curriculum": dslib.CurriculumManagement,
    "campus": dslib.CampusNavigation,
    "prerequisites": dslib.SubjectPrerequisites,

    "patients": dslib.PatientManagement,
    "patient_queue": dslib.PatientQueue,
    "appointments": dslib.AppointmentManagement,
    "patient_history": dslib.PatientRecordHistory,
    "departments": dslib.DepartmentHierarchy,
    "categories": dslib.MedicalRecordCategories,
    "hospital_navigation": dslib.HospitalNavigation,
    "department_connections": dslib.DepartmentConnections
}


# ==================================================
# PERSISTENCE
# ==================================================

def save_operations():
    with open(DATA_FILE, "w", encoding="utf-8") as file:
        json.dump(
            st.session_state.operations,
            file,
            indent=4
        )


def initialize_objects():
    st.session_state.objects = {
        key: cls() for key, cls in CLASSES.items()
    }

    st.session_state.operations = []

    if DATA_FILE.exists():
        try:
            with open(DATA_FILE, "r", encoding="utf-8") as file:
                saved_operations = json.load(file)

            for operation in saved_operations:
                obj = st.session_state.objects[operation["object"]]

                getattr(obj, operation["method"])(
                    *operation["args"]
                )

            st.session_state.operations = saved_operations

        except Exception as error:
            st.error(
                "Could not restore saved data. "
                "Check dslib_data.json: " + str(error)
            )


if "objects" not in st.session_state:
    initialize_objects()


def get_object(key):
    return st.session_state.objects[key]


def modify(key, method, *args):
    obj = get_object(key)

    result = getattr(obj, method)(*args)

    st.session_state.operations.append({
        "object": key,
        "method": method,
        "args": list(args)
    })

    save_operations()

    return result


def read(key, method, *args):
    obj = get_object(key)
    return getattr(obj, method)(*args)


# ==================================================
# REUSABLE UI HELPERS
# ==================================================

def show_result(result):
    if isinstance(result, bool):
        if result:
            st.success("Operation successful.")
        else:
            st.warning("Operation returned false.")
    else:
        st.info(str(result))


def text_form(title, fields, object_key, method):
    with st.form(title):
        values = []

        for field in fields:
            values.append(st.text_input(field))

        submitted = st.form_submit_button("Submit")

        if submitted:
            if all(value.strip() for value in values):
                result = modify(
                    object_key,
                    method,
                    *values
                )
                show_result(result)
            else:
                st.warning("Please fill in all fields.")



def one_input_action(title, field, object_key, method):
    form_key = f"{object_key}_{method}_{title}"

    with st.form(form_key):
        value = st.text_input(field)
        submitted = st.form_submit_button("Submit")

        if submitted:
            if value.strip():
                show_result(modify(object_key, method, value))
            else:
                st.warning("Enter a value.")


def two_input_action(title, first, second, object_key, method):
    form_key = f"{object_key}_{method}_{title}"

    with st.form(form_key):
        value1 = st.text_input(first)
        value2 = st.text_input(second)

        submitted = st.form_submit_button("Submit")

        if submitted:
            if value1.strip() and value2.strip():
                show_result(
                    modify(object_key, method, value1, value2)
                )
            else:
                st.warning("Fill in both fields.")


def display_action(title, object_key, method, *args):
    if st.button(title, key=title + object_key):
        st.text(read(object_key, method, *args))


def metric_action(title, object_key, method):
    st.metric(title, read(object_key, method))


# ==================================================
# NAVIGATION
# ==================================================

if "selected_page" not in st.session_state:
    st.session_state.selected_page = "Dashboard"

if "pending_page" in st.session_state:
    st.session_state.selected_page = st.session_state.pending_page
    del st.session_state.pending_page

page = st.sidebar.radio(
    "NAVIGATION",
    ["Dashboard", "School", "Hospital"],
    key="selected_page"
)

st.sidebar.markdown("---")
st.sidebar.markdown("### DSLib")
st.sidebar.caption("Domain-Specific Data Structures Library")


# ==================================================
# DASHBOARD
# ==================================================

if page == "Dashboard":

    st.title("DSLib Dashboard")
    st.write("Domain-Specific Data Structures Library")

    st.markdown("---")

    st.subheader("Welcome to DSLib")

    st.write(
        "A custom C++ data structures library designed "
        "for real-world School and Hospital management."
    )

    col1, col2 = st.columns(2)

    with col1:
        st.subheader("School Management")

        if st.button("Open School", use_container_width=True):
            st.session_state.pending_page = "School"
            st.rerun()

    with col2:
        st.subheader("Hospital Management")

        if st.button("Open Hospital", use_container_width=True):
            st.session_state.pending_page = "Hospital"
            st.rerun()

    st.markdown("---")
    st.subheader("Overview")

    col1, col2, col3, col4 = st.columns(4)

    col1.metric(
        "Students",
        read("students", "getStudentCount")
    )

    col2.metric(
        "Waiting Students",
        read("student_queue", "getWaitingStudentCount")
    )

    col3.metric(
        "Patients",
        read("patients", "getPatientCount")
    )

    col4.metric(
        "Waiting Patients",
        read("patient_queue", "getWaitingCount")
    )

    st.markdown("---")
    st.subheader("Storage")

    st.write(
        "Your operations are saved in dslib_data.json "
        "inside the frontend folder."
    )

    if st.button("Refresh Dashboard"):
        st.rerun()


# ==================================================
# SCHOOL
# ==================================================

elif page == "School":

    st.title("School Management")
    st.write("Manage students and academic activities.")

    tabs = st.tabs([
        "Students",
        "Student Queue",
        "Assignments",
        "History",
        "Organization",
        "Curriculum",
        "Campus Navigation",
        "Prerequisites"
    ])

    # ----------------------------------------------
    # STUDENTS
    # ----------------------------------------------

    with tabs[0]:

        action = st.radio(
            "Student Operation",
            [
                "Register",
                "Remove",
                "Search",
                "Update",
                "View All"
            ],
            horizontal=True,
            key="school_students"
        )

        if action == "Register":
            text_form(
                "Register Student",
                ["Student ID", "Student Name"],
                "students",
                "registerStudent"
            )

        elif action == "Remove":
            one_input_action(
                "Remove Student",
                "Student ID",
                "students",
                "removeStudent"
            )

        elif action == "Search":
            with st.form("search_student"):
                sid = st.text_input("Student ID")
                submit = st.form_submit_button("Search")

                if submit:
                    if sid.strip():
                        if read("students", "searchStudent", sid):
                            st.success("Student found.")
                        else:
                            st.error("Student not found.")

        elif action == "Update":
            text_form(
                "Update Student",
                ["Student ID", "New Details"],
                "students",
                "updateStudentDetails"
            )

        elif action == "View All":
            display_action(
                "Display Students",
                "students",
                "displayAllStudents"
            )

        st.metric(
            "Total Students",
            read("students", "getStudentCount")
        )

    # ----------------------------------------------
    # STUDENT QUEUE
    # ----------------------------------------------

    with tabs[1]:

        action = st.radio(
            "Queue Operation",
            [
                "Add",
                "Serve Next",
                "View Next",
                "Remove"
            ],
            horizontal=True,
            key="school_queue"
        )

        if action == "Add":
            one_input_action(
                "Add Student",
                "Student ID",
                "student_queue",
                "addStudentToQueue"
            )

        elif action == "Serve Next":
            if st.button("Serve Next Student"):
                show_result(
                    modify("student_queue", "serveNextStudent")
                )

        elif action == "View Next":
            if st.button("View Next Student"):
                show_result(
                    read("student_queue", "viewNextStudent")
                )

        elif action == "Remove":
            one_input_action(
                "Remove Student From Queue",
                "Student ID",
                "student_queue",
                "removeStudentFromQueue"
            )

        st.metric(
            "Waiting Students",
            read("student_queue", "getWaitingStudentCount")
        )

    # ----------------------------------------------
    # ASSIGNMENTS
    # ----------------------------------------------

    with tabs[2]:

        action = st.radio(
            "Assignment Operation",
            [
                "Add",
                "Remove",
                "Update",
                "Search",
                "View All"
            ],
            horizontal=True,
            key="school_assignments"
        )

        if action == "Add":
            text_form(
                "Add Assignment",
                ["Assignment Name", "Description"],
                "assignments",
                "addAssignment"
            )

        elif action == "Remove":
            one_input_action(
                "Remove Assignment",
                "Assignment Name",
                "assignments",
                "removeAssignment"
            )

        elif action == "Update":
            text_form(
                "Update Assignment",
                ["Assignment Name", "New Description"],
                "assignments",
                "updateAssignment"
            )

        elif action == "Search":
            with st.form("search_assignment"):
                name = st.text_input("Assignment Name")
                submit = st.form_submit_button("Search")

                if submit and name.strip():
                    if read("assignments", "searchAssignment", name):
                        st.success("Assignment found.")
                    else:
                        st.error("Assignment not found.")

        elif action == "View All":
            display_action(
                "Display Assignments",
                "assignments",
                "displayAllAssignments"
            )

    # ----------------------------------------------
    # STUDENT HISTORY
    # ----------------------------------------------

    with tabs[3]:

        text_form(
            "Record Student Change",
            ["Change Description"],
            "student_history",
            "recordStudentChange"
        )

        col1, col2 = st.columns(2)

        with col1:
            display_action(
                "View History",
                "student_history",
                "getStudentChangeHistory"
            )

        with col2:
            display_action(
                "View Last Change",
                "student_history",
                "viewLastStudentChange"
            )

        if st.button("Undo Last Change"):
            show_result(
                modify(
                    "student_history",
                    "undoLastStudentChange"
                )
            )

    # ----------------------------------------------
    # ORGANIZATION HIERARCHY
    # ----------------------------------------------

    with tabs[4]:

        action = st.radio(
            "Organization Operation",
            [
                "Add Organization",
                "Add Subordinate",
                "Remove",
                "Search",
                "Display",
                "Find Level",
                "Count Members"
            ],
            horizontal=True,
            key="organization"
        )

        if action == "Add Organization":
            one_input_action(
                "Add Organization",
                "Organization Name",
                "organization",
                "addOrganizationNode"
            )

        elif action == "Add Subordinate":
            two_input_action(
                "Add Subordinate",
                "Parent Organization",
                "Subordinate Organization",
                "organization",
                "addSubordinate"
            )

        elif action == "Remove":
            one_input_action(
                "Remove Organization",
                "Organization Name",
                "organization",
                "removeOrganizationNode"
            )

        elif action == "Search":
            with st.form("search_organization"):
                name = st.text_input("Organization Name")
                submit = st.form_submit_button("Search")

                if submit and name.strip():
                    if read("organization", "searchOrganizationNode", name):
                        st.success("Organization found.")
                    else:
                        st.error("Organization not found.")

        elif action == "Display":
            display_action(
                "Display Hierarchy",
                "organization",
                "displayOrganizationHierarchy"
            )

        elif action == "Find Level":
            with st.form("organization_level"):
                name = st.text_input("Organization Name")
                submit = st.form_submit_button("Find Level")

                if submit and name.strip():
                    st.write(
                        read("organization", "findHierarchyLevel", name)
                    )

        elif action == "Count Members":
            metric_action(
                "Organization Members",
                "organization",
                "countOrganizationMembers"
            )

    # ----------------------------------------------
    # CURRICULUM MANAGEMENT
    # ----------------------------------------------

    with tabs[5]:

        action = st.radio(
            "Curriculum Operation",
            [
                "Add Subject",
                "Add Chapter",
                "Add Topic",
                "Remove Topic",
                "Search Topic",
                "Display",
                "Count Topics",
                "Find Depth"
            ],
            horizontal=True,
            key="curriculum"
        )

        if action == "Add Subject":
            one_input_action(
                "Add Subject",
                "Subject Name",
                "curriculum",
                "addSubject"
            )

        elif action == "Add Chapter":
            two_input_action(
                "Add Chapter",
                "Subject Name",
                "Chapter Name",
                "curriculum",
                "addChapter"
            )

        elif action == "Add Topic":
            two_input_action(
                "Add Topic",
                "Chapter Name",
                "Topic Name",
                "curriculum",
                "addTopic"
            )

        elif action == "Remove Topic":
            one_input_action(
                "Remove Topic",
                "Topic Name",
                "curriculum",
                "removeTopic"
            )

        elif action == "Search Topic":
            with st.form("search_topic"):
                topic = st.text_input("Topic Name")
                submit = st.form_submit_button("Search")

                if submit and topic.strip():
                    if read("curriculum", "searchTopic", topic):
                        st.success("Topic found.")
                    else:
                        st.error("Topic not found.")

        elif action == "Display":
            display_action(
                "Display Curriculum",
                "curriculum",
                "displayCurriculum"
            )

        elif action == "Count Topics":
            metric_action(
                "Total Topics",
                "curriculum",
                "countTopics"
            )

        elif action == "Find Depth":
            metric_action(
                "Curriculum Depth",
                "curriculum",
                "findCurriculumDepth"
            )

    # ----------------------------------------------
    # CAMPUS NAVIGATION
    # ----------------------------------------------

    with tabs[6]:

        action = st.radio(
            "Campus Operation",
            [
                "Add Location",
                "Connect Locations",
                "Remove Location",
                "Nearby Locations",
                "Find Route",
                "Shortest Route",
                "Display Map",
                "Connectivity"
            ],
            horizontal=True,
            key="campus"
        )

        if action == "Add Location":
            one_input_action(
                "Add Location",
                "Location Name",
                "campus",
                "addCampusLocation"
            )

        elif action == "Connect Locations":
            two_input_action(
                "Connect Locations",
                "First Location",
                "Second Location",
                "campus",
                "connectCampusLocations"
            )

        elif action == "Remove Location":
            one_input_action(
                "Remove Location",
                "Location Name",
                "campus",
                "removeCampusLocation"
            )

        elif action == "Nearby Locations":
            one_input_action(
                "Find Nearby Locations",
                "Starting Location",
                "campus",
                "findNearbyLocations"
            )

        elif action in ["Find Route", "Shortest Route"]:
            with st.form("campus_route"):
                start = st.text_input("Starting Location")
                end = st.text_input("Destination")
                submit = st.form_submit_button("Find Route")

                if submit and start.strip() and end.strip():
                    method = (
                        "findCampusRoute"
                        if action == "Find Route"
                        else "findShortestCampusRoute"
                    )

                    st.text(read("campus", method, start, end))

        elif action == "Display Map":
            display_action(
                "Display Campus Map",
                "campus",
                "displayCampusMap"
            )

        elif action == "Connectivity":
            if st.button("Check Connectivity"):
                if read("campus", "checkCampusConnectivity"):
                    st.success("Campus is connected.")
                else:
                    st.warning("Campus is not fully connected.")

    # ----------------------------------------------
    # SUBJECT PREREQUISITES
    # ----------------------------------------------

    with tabs[7]:

        action = st.radio(
            "Prerequisite Operation",
            [
                "Add Subject",
                "Add Prerequisite",
                "Remove Prerequisite",
                "View Prerequisites",
                "Dependent Subjects",
                "Check Prerequisites",
                "Recommended Order",
                "Check Cycles"
            ],
            horizontal=True,
            key="prerequisites"
        )

        if action == "Add Subject":
            one_input_action(
                "Add Subject",
                "Subject Name",
                "prerequisites",
                "addSubject"
            )

        elif action == "Add Prerequisite":
            two_input_action(
                "Add Prerequisite",
                "Subject",
                "Prerequisite Subject",
                "prerequisites",
                "addPrerequisite"
            )

        elif action == "Remove Prerequisite":
            two_input_action(
                "Remove Prerequisite",
                "Subject",
                "Prerequisite Subject",
                "prerequisites",
                "removePrerequisite"
            )

        elif action in ["View Prerequisites", "Dependent Subjects"]:
            with st.form("prerequisite_view"):
                subject = st.text_input("Subject Name")
                submit = st.form_submit_button("View")

                if submit and subject.strip():
                    method = (
                        "getPrerequisites"
                        if action == "View Prerequisites"
                        else "getDependentSubjects"
                    )

                    st.text(read("prerequisites", method, subject))

        elif action == "Check Prerequisites":
            with st.form("check_prerequisites"):
                subject = st.text_input("Subject Name")
                submit = st.form_submit_button("Check")

                if submit and subject.strip():
                    if read("prerequisites", "checkPrerequisites", subject):
                        st.success("Prerequisites satisfied.")
                    else:
                        st.warning("Prerequisites not satisfied.")

        elif action == "Recommended Order":
            display_action(
                "Get Recommended Order",
                "prerequisites",
                "getRecommendedSubjectOrder"
            )

        elif action == "Check Cycles":
            if st.button("Check for Cycles"):
                if read("prerequisites", "hasPrerequisiteCycle"):
                    st.error("A prerequisite cycle exists.")
                else:
                    st.success("No prerequisite cycles found.")


# ==================================================
# HOSPITAL
# ==================================================

elif page == "Hospital":

    st.title("Hospital Management")
    st.write("Manage patients and hospital activities.")

    tabs = st.tabs([
        "Patients",
        "Patient Queue",
        "Appointments",
        "History",
        "Departments",
        "Record Categories",
        "Hospital Navigation",
        "Department Connections"
    ])

    # ----------------------------------------------
    # PATIENTS
    # ----------------------------------------------

    with tabs[0]:

        action = st.radio(
            "Patient Operation",
            [
                "Register",
                "Remove",
                "Search",
                "Update",
                "View All"
            ],
            horizontal=True,
            key="hospital_patients"
        )

        if action == "Register":
            text_form(
                "Register Patient",
                ["Patient ID", "Patient Name"],
                "patients",
                "registerPatient"
            )

        elif action == "Remove":
            one_input_action(
                "Remove Patient",
                "Patient ID",
                "patients",
                "removePatient"
            )

        elif action == "Search":
            with st.form("search_patient"):
                pid = st.text_input("Patient ID")
                submit = st.form_submit_button("Search")

                if submit and pid.strip():
                    if read("patients", "searchPatient", pid):
                        st.success("Patient found.")
                    else:
                        st.error("Patient not found.")

        elif action == "Update":
            text_form(
                "Update Patient",
                ["Patient ID", "New Details"],
                "patients",
                "updatePatientDetails"
            )

        elif action == "View All":
            display_action(
                "Display Patients",
                "patients",
                "displayAllPatients"
            )

        st.metric(
            "Total Patients",
            read("patients", "getPatientCount")
        )

    # ----------------------------------------------
    # PATIENT QUEUE
    # ----------------------------------------------

    with tabs[1]:

        action = st.radio(
            "Queue Operation",
            [
                "Add",
                "Call Next",
                "View Next",
                "Cancel Visit"
            ],
            horizontal=True,
            key="hospital_queue"
        )

        if action == "Add":
            one_input_action(
                "Add Patient",
                "Patient ID",
                "patient_queue",
                "addPatientToQueue"
            )

        elif action == "Call Next":
            if st.button("Call Next Patient"):
                show_result(
                    modify("patient_queue", "callNextPatient")
                )

        elif action == "View Next":
            if st.button("View Next Patient"):
                show_result(
                    read("patient_queue", "viewNextPatient")
                )

        elif action == "Cancel Visit":
            one_input_action(
                "Cancel Patient Visit",
                "Patient ID",
                "patient_queue",
                "cancelPatientVisit"
            )

        st.metric(
            "Waiting Patients",
            read("patient_queue", "getWaitingCount")
        )

    # ----------------------------------------------
    # APPOINTMENTS
    # ----------------------------------------------

    with tabs[2]:

        action = st.radio(
            "Appointment Operation",
            [
                "Schedule",
                "Cancel",
                "Reschedule",
                "Find",
                "Doctor Schedule",
                "Count"
            ],
            horizontal=True,
            key="hospital_appointments"
        )

        if action == "Schedule":
            text_form(
                "Schedule Appointment",
                ["Patient ID", "Appointment Details"],
                "appointments",
                "scheduleAppointment"
            )

        elif action == "Cancel":
            one_input_action(
                "Cancel Appointment",
                "Patient ID",
                "appointments",
                "cancelAppointment"
            )

        elif action == "Reschedule":
            text_form(
                "Reschedule Appointment",
                ["Patient ID", "New Appointment Details"],
                "appointments",
                "rescheduleAppointment"
            )

        elif action == "Find":
            with st.form("find_appointment"):
                pid = st.text_input("Patient ID")
                submit = st.form_submit_button("Find")

                if submit and pid.strip():
                    if read("appointments", "findAppointment", pid):
                        st.success("Appointment found.")
                    else:
                        st.error("Appointment not found.")

        elif action == "Doctor Schedule":
            one_input_action(
                "View Doctor Schedule",
                "Doctor Name",
                "appointments",
                "displayDoctorSchedule"
            )

        elif action == "Count":
            metric_action(
                "Total Appointments",
                "appointments",
                "getAppointmentCount"
            )

    # ----------------------------------------------
    # PATIENT HISTORY
    # ----------------------------------------------

    with tabs[3]:

        text_form(
            "Record Patient Action",
            ["Action Description"],
            "patient_history",
            "recordPatientAction"
        )

        col1, col2 = st.columns(2)

        with col1:
            display_action(
                "View Record History",
                "patient_history",
                "getRecordHistory"
            )

        with col2:
            display_action(
                "View Last Action",
                "patient_history",
                "viewLastRecordAction"
            )

        if st.button("Undo Last Record Action"):
            show_result(
                modify(
                    "patient_history",
                    "undoLastRecordAction"
                )
            )

    # ----------------------------------------------
    # DEPARTMENT HIERARCHY
    # ----------------------------------------------

    with tabs[4]:

        action = st.radio(
            "Department Operation",
            [
                "Add Department",
                "Remove Department",
                "Search",
                "Display",
                "Add Subdepartment",
                "Find Level",
                "Count",
                "Display In Order"
            ],
            horizontal=True,
            key="departments"
        )

        if action == "Add Department":
            one_input_action(
                "Add Department",
                "Department Name",
                "departments",
                "addDepartment"
            )

        elif action == "Remove Department":
            one_input_action(
                "Remove Department",
                "Department Name",
                "departments",
                "removeDepartment"
            )

        elif action == "Search":
            with st.form("search_department"):
                name = st.text_input("Department Name")
                submit = st.form_submit_button("Search")

                if submit and name.strip():
                    if read("departments", "searchDepartment", name):
                        st.success("Department found.")
                    else:
                        st.error("Department not found.")

        elif action == "Display":
            display_action(
                "Display Department Hierarchy",
                "departments",
                "displayDepartmentHierarchy"
            )

        elif action == "Add Subdepartment":
            two_input_action(
                "Add Subdepartment",
                "Parent Department",
                "Subdepartment",
                "departments",
                "addSubDepartment"
            )

        elif action == "Find Level":
            with st.form("department_level"):
                name = st.text_input("Department Name")
                submit = st.form_submit_button("Find Level")

                if submit and name.strip():
                    st.write(
                        read("departments", "findDepartmentLevel", name)
                    )

        elif action == "Count":
            metric_action(
                "Department Count",
                "departments",
                "getDepartmentCount"
            )

        elif action == "Display In Order":
            display_action(
                "Display Departments In Order",
                "departments",
                "displayDepartmentsInOrder"
            )

    # ----------------------------------------------
    # MEDICAL RECORD CATEGORIES
    # ----------------------------------------------

    with tabs[5]:

        action = st.radio(
            "Category Operation",
            [
                "Add Category",
                "Add Subcategory",
                "Search",
                "Display"
            ],
            horizontal=True,
            key="record_categories"
        )

        if action == "Add Category":
            one_input_action(
                "Add Record Category",
                "Category Name",
                "categories",
                "addRecordCategory"
            )

        elif action == "Add Subcategory":
            two_input_action(
                "Add Subcategory",
                "Parent Category",
                "Subcategory",
                "categories",
                "addSubCategory"
            )

        elif action == "Search":
            with st.form("search_category"):
                name = st.text_input("Category Name")
                submit = st.form_submit_button("Search")

                if submit and name.strip():
                    if read("categories", "searchRecordCategory", name):
                        st.success("Category found.")
                    else:
                        st.error("Category not found.")

        elif action == "Display":
            display_action(
                "Display Record Categories",
                "categories",
                "displayRecordCategories"
            )

    # ----------------------------------------------
    # HOSPITAL NAVIGATION
    # ----------------------------------------------

    with tabs[6]:

        action = st.radio(
            "Navigation Operation",
            [
                "Add Location",
                "Connect Locations",
                "Remove Location",
                "Connected Locations",
                "Find Route",
                "Shortest Route",
                "Display Map"
            ],
            horizontal=True,
            key="hospital_navigation"
        )

        if action == "Add Location":
            one_input_action(
                "Add Hospital Location",
                "Location Name",
                "hospital_navigation",
                "addHospitalLocation"
            )

        elif action == "Connect Locations":
            two_input_action(
                "Connect Locations",
                "First Location",
                "Second Location",
                "hospital_navigation",
                "connectLocations"
            )

        elif action == "Remove Location":
            one_input_action(
                "Remove Location",
                "Location Name",
                "hospital_navigation",
                "removeLocation"
            )

        elif action == "Connected Locations":
            one_input_action(
                "Find Connected Locations",
                "Location Name",
                "hospital_navigation",
                "findConnectedLocations"
            )

        elif action in ["Find Route", "Shortest Route"]:
            with st.form("hospital_route"):
                start = st.text_input("Starting Location")
                end = st.text_input("Destination")
                submit = st.form_submit_button("Find Route")

                if submit and start.strip() and end.strip():
                    method = (
                        "findHospitalRoute"
                        if action == "Find Route"
                        else "findShortestHospitalRoute"
                    )

                    st.text(
                        read("hospital_navigation", method, start, end)
                    )

        elif action == "Display Map":
            display_action(
                "Display Hospital Map",
                "hospital_navigation",
                "displayHospitalMap"
            )

    # ----------------------------------------------
    # DEPARTMENT CONNECTIONS
    # ----------------------------------------------

    with tabs[7]:

        action = st.radio(
            "Connection Operation",
            [
                "Connect Departments",
                "Related Departments",
                "Connection Count",
                "Find Department Path",
                "Check Connectivity"
            ],
            horizontal=True,
            key="department_connections"
        )

        if action == "Connect Departments":
            two_input_action(
                "Connect Departments",
                "First Department",
                "Second Department",
                "department_connections",
                "connectDepartments"
            )

        elif action == "Related Departments":
            one_input_action(
                "Find Related Departments",
                "Department Name",
                "department_connections",
                "findRelatedDepartments"
            )

        elif action == "Connection Count":
            with st.form("connection_count"):
                name = st.text_input("Department Name")
                submit = st.form_submit_button("Get Count")

                if submit and name.strip():
                    st.metric(
                        "Connections",
                        read(
                            "department_connections",
                            "getDepartmentConnections",
                            name
                        )
                    )

        elif action == "Find Department Path":
            with st.form("department_path"):
                start = st.text_input("Starting Department")
                end = st.text_input("Destination Department")
                submit = st.form_submit_button("Find Path")

                if submit and start.strip() and end.strip():
                    st.text(
                        read(
                            "department_connections",
                            "findDepartmentPath",
                            start,
                            end
                        )
                    )

        elif action == "Check Connectivity":
            if st.button("Check Connectivity"):
                if read(
                    "department_connections",
                    "checkDepartmentConnectivity"
                ):
                    st.success("Departments are connected.")
                else:
                    st.warning("Departments are not fully connected.")


# ==================================================
# FOOTER
# ==================================================

st.markdown("---")
st.caption("DSLib | Custom C++ Data Structures Library")
