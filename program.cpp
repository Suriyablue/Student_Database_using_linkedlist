#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    char name[50];
    int age;
    int clg_year;
    float gpa;
    float cgpa;
    int roll;
    Student *next;
};

Student* createNode(const char name[], int age, int clg_year, float gpa, float cgpa, int roll) {
    Student* newNode = new Student;
    strcpy(newNode->name, name);  // Copying string safely
    newNode->age = age;
    newNode->clg_year = clg_year;
    newNode->gpa = gpa;
    newNode->cgpa = cgpa;
    newNode->roll = roll;
    newNode->next = nullptr;
    return newNode;
}

// Function to check if roll number is unique
bool isRollNumberUnique(Student* head, int roll) {
    Student* temp = head;
    while (temp != nullptr) {
        if (temp->roll == roll) {
            return false; // Roll number already exists
        }
        temp = temp->next;
    }
    return true; // Roll number is unique
}

void insertStudent(Student** head, const char name[], int age, int clg_year, float gpa, float cgpa, int roll,bool msg) {
    // Ensure the college year is valid
    if (clg_year > 4 || clg_year <= 0) {
        cout << "Invalid College Year! Must be between 1 and 4.\n";
        return;
    }

    // Check if the roll number is unique
    if (!isRollNumberUnique(*head, roll)) {
        cout << "Error: Roll number already exists!\n";
        return;
    }

    Student* newNode = createNode(name, age, clg_year, gpa, cgpa, roll);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Student* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    if(msg)
    cout << "Student detail inserted into database.\n";
}



void displaySpecificStudent(Student* head, const char username[], int password) {
    Student* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (strcmp(temp->name, username) == 0 && temp->roll == password) {
            cout << "Student Details:\n";
            cout << "Name: " << temp->name << endl;
            cout << "Roll No: " << temp->roll << endl;
            cout << "Age: " << temp->age << endl;
            cout << "College Year: " << temp->clg_year << endl;
            cout << "GPA: " << temp->gpa << endl;
            cout << "CGPA: " << temp->cgpa << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Details not found.\n";
    }
}

bool login(Student* head, const char username[], int password) {
    Student* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (strcmp(temp->name, username) == 0 && temp->roll == password) {
            cout << "Login successful.\n";
            found = true;
            break;
        }
        temp = temp->next;
    }
    
    cout << "Press Enter to continue...";
    cin.get(); 
    return found;
}

void editStudentDetails(Student* head, const char username[], int password, int roll) {
    Student* temp = head;
    bool foundUser = false;

    // First, check if the user credentials are valid
    while (temp != nullptr) {
        if (strcmp(temp->name, username) == 0 && temp->roll == password) {
            foundUser = true;
            break;
        }
        temp = temp->next;
    }

    if (foundUser) {
        // Now search for the student to edit by roll number
        temp = head;  // Reset temp to head to search for roll
        while (temp != nullptr) {
            if (temp->roll == roll) {
                cout << "Enter Name: ";
                cin >> temp->name;
                cout << "Enter Age: ";
                cin >> temp->age;
                cout << "Enter College Year: ";
                cin >> temp->clg_year;
                cout << "Enter GPA: ";
                cin >> temp->gpa;
                cout << "Enter CGPA: ";
                cin >> temp->cgpa;
                cout << "Student details updated successfully.\n";
                return; // Exit after updating
            }
            temp = temp->next;
        }
        cout << "Student with roll number " << roll << " not found.\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

#include <iostream>
using namespace std;

// Assume the necessary functions like insertStudent, login, displaySpecificStudent, editStudentDetails, isRollNumberUnique are defined

int main() {
    Student* head = nullptr;
    char name[50], username[50];
    int age, clg_year, roll, password, n = 1, c;
    float gpa, cgpa;

    // Insert admin user
    insertStudent(&head, "admin", 23, 4, 3.7, 3.5, 1234, false);

    bool loggedIn = false;

    cout << ">> Student Database <<\n";
    cout << "Press Enter to login...\n";
    cin.get();

    while (n) {
        if (!loggedIn) {
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;
            if (login(head, username, password)) {
                cout << "Login successful.\n";
                loggedIn = true;
            } else {
                cout << "Invalid username or password. Try again.\n";
                continue;
            }
        } else {
            cout << "Options\n------------------------------";
            cout << "\n   1. Display Student Details.\n   2. Insert Student Details.\n   3. Edit Student Details.\n";
            cout << "   4. Logout\n";
            cout << "------------------------------\n";
            cout << "Enter your choice: ";
            cin >> c;

            switch (c) {
                case 1:
                    cout << "Enter Student Name: ";
                    cin >> username;
                    cout << "Enter Student Roll No: ";
                    cin >> password;
                    displaySpecificStudent(head, username, password);
                    break;
                case 2:
                    cout << "Enter Name of Student: ";
                    cin.ignore();
                    cin.getline(name, 50); // Capture name with spaces

                    cout << "Enter Age: ";
                    cin >> age;

                    cout << "Enter College Year (1-4): ";
                    cin >> clg_year;

                    // Validate College Year
                    if (clg_year > 4 || clg_year < 1) {
                        cout << "Invalid College Year! Please enter a value between 1 and 4.\n";
                        break;
                    }

                    cout << "Enter GPA: ";
                    cin >> gpa;

                    cout << "Enter CGPA: ";
                    cin >> cgpa;

                    cout << "Enter Roll No: ";
                    cin >> roll;

                    // Validate if roll number is unique
                    if (!isRollNumberUnique(head, roll)) {
                        cout << "Roll number already exists! Please enter a unique roll number.\n";
                        break;
                    }

                    insertStudent(&head, name, age, clg_year, gpa, cgpa, roll, true);
                    cout << "Student detail inserted into database.\n";
                    break;

                case 3:
                    cout << "Enter Student Roll No: ";
                    cin >> roll;
                    editStudentDetails(head, username, password, roll);
                    break;

                case 4:
                    loggedIn = false;
                    cout << "Logout successful!\n";
                    break;

                default:
                    cout << "Invalid choice\n";
            }
        }
        cout << "------------------------------------\n";
        cout << "To continue, enter 1;\n---------------\notherwise, enter 0:" ;
        cin >> n;
    }
    return 0;
}
