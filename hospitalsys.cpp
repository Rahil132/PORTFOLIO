#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Base Class - Abstraction of a Person in the Hospital
class Person {
public:
    string name;
};

// Derived Class - Specialized for Patients
class Patient : public Person {
public:
    int age;
    string ailment;
    string assignedDoctor;
    bool isAdmitted;

    Patient() {
        assignedDoctor = "Not Assigned";
        isAdmitted = false;
    }
};

int main() {
    Patient ward[50]; // Capacity for 50 patients
    int patientCount = 0;
    int choice;

    // --- PRE-LOADING PATIENTS ---
    ward[patientCount].name = "John Doe"; ward[patientCount].age = 45; ward[patientCount].ailment = "Fever"; patientCount++;
    ward[patientCount].name = "Jane Smith"; ward[patientCount].age = 30; ward[patientCount].ailment = "Fracture"; patientCount++;
    ward[patientCount].name = "Robert Brown"; ward[patientCount].age = 65; ward[patientCount].ailment = "Cardiac"; patientCount++;

    while (true) {
        cout << "\n========================================================";
        cout << "\n                CITY HOSPITAL RECORDS SYSTEM";
        cout << "\n========================================================";
        cout << "\n1. Admit New Patient\n2. View Patient List\n3. Assign Doctor\n4. Discharge Patient\n5. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (patientCount < 50) {
                cout << "Patient Name: "; getline(cin, ward[patientCount].name);
                cout << "Age: "; cin >> ward[patientCount].age;
                cin.ignore();
                cout << "Ailment/Reason: "; getline(cin, ward[patientCount].ailment);
                ward[patientCount].isAdmitted = true;
                patientCount++;
                cout << "Patient admitted to ward!\n";
            }
        }
        else if (choice == 2) {
            cout << "\n" << left << setw(4) << "ID" << setw(18) << "NAME" << setw(6) << "AGE" << setw(15) << "AILMENT" << "DOCTOR" << endl;
            cout << "---------------------------------------------------------------------" << endl;
            for (int i = 0; i < patientCount; i++) {
                if (ward[i].isAdmitted) {
                    cout << left << setw(4) << i + 1 << setw(18) << ward[i].name << setw(6) << ward[i].age << setw(15) << ward[i].ailment << ward[i].assignedDoctor << endl;
                }
            }
        }
        else if (choice == 3) {
            int id;
            string docName;
            cout << "Enter Patient ID: "; cin >> id;
            cin.ignore();
            if (id > 0 && id <= patientCount && ward[id-1].isAdmitted) {
                cout << "Enter Doctor Name: "; getline(cin, docName);
                ward[id-1].assignedDoctor = "Dr. " + docName;
                cout << "Doctor Assigned Successfully.\n";
            } else cout << "Invalid ID or Patient already discharged.\n";
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Patient ID to Discharge: "; cin >> id;
            if (id > 0 && id <= patientCount) {
                ward[id-1].isAdmitted = false;
                cout << "Patient " << ward[id-1].name << " has been discharged.\n";
            } else cout << "Invalid ID.\n";
        }
        else if (choice == 5) break;
    }
    return 0;
}
