import dslib

# Test School module
students = dslib.StudentManagement()

print("SCHOOL TEST")
print(students.registerStudent("S001", "Aarav"))
print(students.registerStudent("S002", "Meera"))
print("Total students:", students.getStudentCount())
print(students.displayAllStudents())


# Test Hospital module
patients = dslib.PatientManagement()

print("\nHOSPITAL TEST")
print(patients.registerPatient("P001", "Rahul"))
print(patients.registerPatient("P002", "Ananya"))
print("Total patients:", patients.getPatientCount())
print(patients.displayAllPatients())