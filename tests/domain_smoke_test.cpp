#include <cassert>
#include <string>
#include "school.h"
#include "hospital.h"

int main() {
    StudentManagement schoolA;
    StudentManagement schoolB;
    PatientManagement hospitalA;
    PatientManagement hospitalB;

    assert(!schoolA.registerStudent("S1", "Asha").empty());
    assert(schoolA.searchStudent("S1"));
    assert(!schoolB.searchStudent("S1"));

    assert(!hospitalA.registerPatient("P1", "Rohan").empty());
    assert(hospitalA.searchPatient("P1"));
    assert(!hospitalB.searchPatient("P1"));

    StudentService studentQueue;
    assert(!studentQueue.addStudentToQueue("S1").empty());
    assert(studentQueue.serveNextStudent() == "S1");
    assert(studentQueue.getWaitingStudentCount() == 0);

    PatientQueue patientQueue;
    assert(!patientQueue.addPatientToQueue("P1").empty());
    assert(patientQueue.callNextPatient() == "P1");
    assert(patientQueue.getWaitingCount() == 0);

    return 0;
}
