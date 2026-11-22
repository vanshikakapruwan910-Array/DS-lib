#include <iostream>
#include "school.h"
#include "hospital.h"

int main() {
    StudentManagement students;
    PatientManagement patients;

    std::cout << students.registerStudent("S001", "Aarav") << '\n';
    std::cout << patients.registerPatient("P001", "Meera") << '\n';

    std::cout << "\nStudents:\n" << students.displayAllStudents();
    std::cout << "\nPatients:\n" << patients.displayAllPatients();
    return 0;
}
