#ifndef HOSPITAL_MANAGEMENT_H
#define HOSPITAL_MANAGEMENT_H

#include <iostream>
#include "array.hpp"
#include "array2D.hpp"
#include "linkedList.h"
#include "q1.h"
#include "stack.h"

using namespace std;

class HospitalManagementSystem
{
private:
    int arr[MAX],beds[MAX][MAX];
    int n,rows,cols;
    LinkedList l;
    Queue q;
    Stack s;
    int beds[MAX][MAX];
public:
    HospitalManagementSystem() : q(100)
    {
        n = 0;
        rows = 4;
        cols = 5;
        for (int i = 0; i < MAX; i++)
            arr[i] = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                beds[i][j] = 0;
        }
    }
    void registerPatient()
    {
        int data;
        cout << "Enter Patient ID: ";
        cin >> data;
        if (l.search(data))
        {
            cout << "Patient already registered.\n";
            return;
        }
        l.insertAtEnd(data);
        cout << "Patient registered successfully.\n";
    }    
    void displayPatients()
    {
        cout << "\nRegistered Patient IDs:\n";
        l.display();
    }    
    void registerBed()
    {
        if (n >= MAX)
        {
            cout << "Bed storage is full.\n";
            return;
        }
        cout << "Enter Bed ID when prompted:\n";
        INSERT_AT_End(arr, &n);
        cout << "Bed entry added.\n";
    }
    void displayBeds()
    {
        cout << "\nHospital Bed Records:\n";
        display(arr, &n);
    }

    void searchBed()
    {
        cout << "\nSearch Bed ID:\n";
        search(arr, &n);
    }

    void updateBed()
    {
        cout << "\nUpdate Bed Record:\n";
        update(arr, &n);
    }

    void addPatientToQueue()
    {
        int data;
        cout << "Enter Patient ID: ";
        cin >> data;
        if (!l.search(data))
        {
            cout << "Register the patient first.\n";
            return;
        }
        if (q.isFull())
        {
            cout << "Waiting queue is full.\n";
            return;
        }
        q.enqueue(data);

        cout << "Patient added to consultation queue.\n";
    }
    void callNextPatient()
    {
        if (q.isEmpty())
        {
            cout << "No patients are waiting.\n";
            return;
        }
        cout << "Next Patient ID: " << q.getFront() << '\n';
        q.dequeue();
        cout << "Patient consultation queue updated.\n";
    }
    void displayWaitingPatients()
    {
        cout << "\nPatients Waiting for Consultation:\n";
        q.display();
    }
    void recordOperation()
    {
        cout << "Enter operation code when prompted:\n";
        s.push();
    }
    void latestOperation()
    {
        if (s.isEmpty())
        {
            cout << "No operation history available.\n";
            return;
        }

        cout << "Latest Operation Code: " << s.peek() << '\n';
    }

    void displayHistory()
    {
        cout << "\nHospital Operation History:\n";
        s.display();
    }
    void removeHistory()
    {
        if (s.isEmpty())
        {
            cout << "Operation history is empty.\n";
            return;
        }

        cout << "Removed Operation Code: " << s.pop() << '\n';
    }
    void ayushmanPatientService()
{
    int id;
    char verified, admission;

    cout << "\n===== AYUSHMAN PATIENT SERVICE =====\n";
    cout << "Enter registered Patient ID: ";
    cin >> id;

    if (l.search(id!=1))
    {
        cout << "Patient is not registered.\n";
        cout << "Please register the patient first.\n";
        return;
    }

    cout << "Is Ayushman beneficiary status verified? (Y/N): ";
    cin >> verified;

    if (verified != 'Y' && verified != 'y')
    {
        cout << "Verification is pending.\n";
        cout << "Refer the patient to the Ayushman help desk.\n";
        return;
    }

    cout << "Beneficiary status recorded as verified.\n";
    cout << "Confirm that the proposed treatment is covered.\n";

    cout << "Add patient to consultation queue? (Y/N): ";
    cin >> admission;

    if (admission == 'Y' || admission == 'y')
    {
        if (q.isFull())
        {
            cout << "Consultation queue is full.\n";
            return;
        }
        q.enqueue(id);
        cout << "Patient added to consultation queue.\n";
    }
    cout << "\nManage ward bed records? (Y/N): ";
    cin >> admission;
    if (admission == 'Y' || admission == 'y')
    {
        cout << "\nCurrent ward-bed matrix:\n";
        display2D(beds, rows, cols);
        cout << "\nSearch a bed status/value:\n";
        search2D(beds, rows, cols);
        cout << "\nUpdate a bed status/value if required:\n";
        update2D(beds, rows, cols);
        cout << "Ward-bed records processed.\n";
    }
}
    void main()
    {
        int ch;

        do
        {
            cout << "\n-------HOSPITAL MANAGEMENT SYSTEM --------\n";
            cout << "1. Register Patient\n";
            cout << "2. Display Patients\n";
            cout << "3. Register Bed\n";
            cout << "4. Display Beds\n";
            cout << "5. Search Bed\n";
            cout << "6. Update Bed Record\n";
            cout << "7. Add Patient to Waiting Queue\n";
            cout << "8. Call Next Patient\n";
            cout << "9. Display Waiting Queue\n";
            cout << "10. Record Operation\n";
            cout << "11. View Latest Operation\n";
            cout << "12. Display Operation History\n";
            cout << "13. Remove Latest History Entry\n";
            cout << "14. Ayushman Patient Service\n";
            cout << "0. Exit\n";
            cout << "Enter Choice: ";

            cin >> ch;

            switch (ch)
            {
                case 1:
                    registerPatient();
                    break;

                case 2:
                    displayPatients();
                    break;

                case 3:
                    registerBed();
                    break;

                case 4:
                    displayBeds();
                    break;

                case 5:
                    searchBed();
                    break;

                case 6:
                    updateBed();
                    break;

                case 7:
                    addPatientToQueue();
                    break;

                case 8:
                    callNextPatient();
                    break;

                case 9:
                    displayWaitingPatients();
                    break;

                case 10:
                    recordOperation();
                    break;

                case 11:
                    latestOperation();
                    break;

                case 12:
                    displayHistory();
                    break;

                case 13:
                    removeHistory();
                    break;
                case 14:
                    ayushmanPatientService();
                    break;
                case 0:
                    cout << "Hospital system closed.\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }

        } while (ch != 0);
    }
};

#endif
