#include <pybind11/pybind11.h>
#include "school.h"
#include "hospital.h"

namespace py = pybind11;

PYBIND11_MODULE(dslib, m) {
    m.doc() = "DSLib - Custom Data Structures for School and Hospital Management";

    // ==================== SCHOOL ====================

    py::class_<StudentManagement>(m, "StudentManagement")
        .def(py::init<>())
        .def("registerStudent", &StudentManagement::registerStudent)
        .def("removeStudent", &StudentManagement::removeStudent)
        .def("searchStudent", &StudentManagement::searchStudent)
        .def("updateStudentDetails", &StudentManagement::updateStudentDetails)
        .def("displayAllStudents", &StudentManagement::displayAllStudents)
        .def("getStudentCount", &StudentManagement::getStudentCount);

    py::class_<StudentService>(m, "StudentService")
        .def(py::init<>())
        .def("addStudentToQueue", &StudentService::addStudentToQueue)
        .def("serveNextStudent", &StudentService::serveNextStudent)
        .def("viewNextStudent", &StudentService::viewNextStudent)
        .def("getWaitingStudentCount", &StudentService::getWaitingStudentCount)
        .def("removeStudentFromQueue", &StudentService::removeStudentFromQueue);

    py::class_<AssignmentManagement>(m, "AssignmentManagement")
        .def(py::init<>())
        .def("addAssignment", &AssignmentManagement::addAssignment)
        .def("removeAssignment", &AssignmentManagement::removeAssignment)
        .def("updateAssignment", &AssignmentManagement::updateAssignment)
        .def("searchAssignment", &AssignmentManagement::searchAssignment)
        .def("displayAllAssignments", &AssignmentManagement::displayAllAssignments);

    py::class_<StudentHistory>(m, "StudentHistory")
        .def(py::init<>())
        .def("recordStudentChange", &StudentHistory::recordStudentChange)
        .def("undoLastStudentChange", &StudentHistory::undoLastStudentChange)
        .def("viewLastStudentChange", &StudentHistory::viewLastStudentChange)
        .def("getStudentChangeHistory", &StudentHistory::getStudentChangeHistory);

    py::class_<OrganizationHierarchy>(m, "OrganizationHierarchy")
        .def(py::init<>())
        .def("addOrganizationNode", &OrganizationHierarchy::addOrganizationNode)
        .def("removeOrganizationNode", &OrganizationHierarchy::removeOrganizationNode)
        .def("addSubordinate", &OrganizationHierarchy::addSubordinate)
        .def("searchOrganizationNode", &OrganizationHierarchy::searchOrganizationNode)
        .def("displayOrganizationHierarchy", &OrganizationHierarchy::displayOrganizationHierarchy)
        .def("findHierarchyLevel", &OrganizationHierarchy::findHierarchyLevel)
        .def("countOrganizationMembers", &OrganizationHierarchy::countOrganizationMembers);

    py::class_<CurriculumManagement>(m, "CurriculumManagement")
        .def(py::init<>())
        .def("addSubject", &CurriculumManagement::addSubject)
        .def("addChapter", &CurriculumManagement::addChapter)
        .def("addTopic", &CurriculumManagement::addTopic)
        .def("removeTopic", &CurriculumManagement::removeTopic)
        .def("searchTopic", &CurriculumManagement::searchTopic)
        .def("displayCurriculum", &CurriculumManagement::displayCurriculum)
        .def("countTopics",
            static_cast<int (CurriculumManagement::*)() const>(
                &CurriculumManagement::countTopics
            )
        )
        .def("findCurriculumDepth", &CurriculumManagement::findCurriculumDepth);

    py::class_<CampusNavigation>(m, "CampusNavigation")
        .def(py::init<>())
        .def("addCampusLocation", &CampusNavigation::addCampusLocation)
        .def("connectCampusLocations", &CampusNavigation::connectCampusLocations)
        .def("removeCampusLocation", &CampusNavigation::removeCampusLocation)
        .def("findNearbyLocations", &CampusNavigation::findNearbyLocations)
        .def("findCampusRoute", &CampusNavigation::findCampusRoute)
        .def("findShortestCampusRoute", &CampusNavigation::findShortestCampusRoute)
        .def("displayCampusMap", &CampusNavigation::displayCampusMap)
        .def("checkCampusConnectivity", &CampusNavigation::checkCampusConnectivity);

    py::class_<SubjectPrerequisites>(m, "SubjectPrerequisites")
        .def(py::init<>())
        .def("addSubject", &SubjectPrerequisites::addSubject)
        .def("addPrerequisite", &SubjectPrerequisites::addPrerequisite)
        .def("removePrerequisite", &SubjectPrerequisites::removePrerequisite)
        .def("getPrerequisites", &SubjectPrerequisites::getPrerequisites)
        .def("getDependentSubjects", &SubjectPrerequisites::getDependentSubjects)
        .def("checkPrerequisites", &SubjectPrerequisites::checkPrerequisites)
        .def("getRecommendedSubjectOrder", &SubjectPrerequisites::getRecommendedSubjectOrder)
        .def("hasPrerequisiteCycle", &SubjectPrerequisites::hasPrerequisiteCycle);


    // ==================== HOSPITAL ====================

    py::class_<PatientManagement>(m, "PatientManagement")
        .def(py::init<>())
        .def("registerPatient", &PatientManagement::registerPatient)
        .def("removePatient", &PatientManagement::removePatient)
        .def("searchPatient", &PatientManagement::searchPatient)
        .def("updatePatientDetails", &PatientManagement::updatePatientDetails)
        .def("displayAllPatients", &PatientManagement::displayAllPatients)
        .def("getPatientCount", &PatientManagement::getPatientCount);

    py::class_<PatientQueue>(m, "PatientQueue")
        .def(py::init<>())
        .def("addPatientToQueue", &PatientQueue::addPatientToQueue)
        .def("callNextPatient", &PatientQueue::callNextPatient)
        .def("viewNextPatient", &PatientQueue::viewNextPatient)
        .def("getWaitingCount", &PatientQueue::getWaitingCount)
        .def("cancelPatientVisit", &PatientQueue::cancelPatientVisit);

    py::class_<AppointmentManagement>(m, "AppointmentManagement")
        .def(py::init<>())
        .def("scheduleAppointment", &AppointmentManagement::scheduleAppointment)
        .def("cancelAppointment", &AppointmentManagement::cancelAppointment)
        .def("rescheduleAppointment", &AppointmentManagement::rescheduleAppointment)
        .def("findAppointment", &AppointmentManagement::findAppointment)
        .def("displayDoctorSchedule", &AppointmentManagement::displayDoctorSchedule)
        .def("getAppointmentCount", &AppointmentManagement::getAppointmentCount);

    py::class_<PatientRecordHistory>(m, "PatientRecordHistory")
        .def(py::init<>())
        .def("recordPatientAction", &PatientRecordHistory::recordPatientAction)
        .def("undoLastRecordAction", &PatientRecordHistory::undoLastRecordAction)
        .def("viewLastRecordAction", &PatientRecordHistory::viewLastRecordAction)
        .def("getRecordHistory", &PatientRecordHistory::getRecordHistory);

    py::class_<DepartmentHierarchy>(m, "DepartmentHierarchy")
        .def(py::init<>())
        .def("addDepartment", &DepartmentHierarchy::addDepartment)
        .def("removeDepartment", &DepartmentHierarchy::removeDepartment)
        .def("searchDepartment", &DepartmentHierarchy::searchDepartment)
        .def("displayDepartmentHierarchy", &DepartmentHierarchy::displayDepartmentHierarchy)
        .def("addSubDepartment", &DepartmentHierarchy::addSubDepartment)
        .def("findDepartmentLevel", &DepartmentHierarchy::findDepartmentLevel)
        .def("getDepartmentCount", &DepartmentHierarchy::getDepartmentCount)
        .def("displayDepartmentsInOrder", &DepartmentHierarchy::displayDepartmentsInOrder);

    py::class_<MedicalRecordCategories>(m, "MedicalRecordCategories")
        .def(py::init<>())
        .def("addRecordCategory", &MedicalRecordCategories::addRecordCategory)
        .def("addSubCategory", &MedicalRecordCategories::addSubCategory)
        .def("searchRecordCategory", &MedicalRecordCategories::searchRecordCategory)
        .def("displayRecordCategories", &MedicalRecordCategories::displayRecordCategories);

    py::class_<HospitalNavigation>(m, "HospitalNavigation")
        .def(py::init<>())
        .def("addHospitalLocation", &HospitalNavigation::addHospitalLocation)
        .def("connectLocations", &HospitalNavigation::connectLocations)
        .def("removeLocation", &HospitalNavigation::removeLocation)
        .def("findConnectedLocations", &HospitalNavigation::findConnectedLocations)
        .def("findHospitalRoute", &HospitalNavigation::findHospitalRoute)
        .def("findShortestHospitalRoute", &HospitalNavigation::findShortestHospitalRoute)
        .def("displayHospitalMap", &HospitalNavigation::displayHospitalMap);

    py::class_<DepartmentConnections>(m, "DepartmentConnections")
        .def(py::init<>())
        .def("connectDepartments", &DepartmentConnections::connectDepartments)
        .def("findRelatedDepartments", &DepartmentConnections::findRelatedDepartments)
        .def("getDepartmentConnections", &DepartmentConnections::getDepartmentConnections)
        .def("findDepartmentPath", &DepartmentConnections::findDepartmentPath)
        .def("checkDepartmentConnectivity", &DepartmentConnections::checkDepartmentConnectivity);
}