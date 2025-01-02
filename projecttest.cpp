#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Student {
    string id;
    string name;
    string course;
    int courseFee;
    Student *next;
};

Student *createNode(string id, string name, string course, int courseFee) {
    Student *n = new Student();
    n->id = id;
    n->name = name;
    n->course = course;
    n->courseFee = courseFee;
    n->next = nullptr;
    return n;
}

void viewStudent(Student *head) {
    if (!head) {
        cout << "No students in the list." << endl;
        return;
    }
    Student *temp = head;
    while (temp) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << ", Course Enrolled: " << temp->course
             << ", Course Fee: RM" << temp->courseFee << endl;
        temp = temp->next;
    }
}

Student* addStudent(Student *head, string id, string name, string course, int courseFee) {
    Student *newNode = createNode(id, name, course, courseFee);
    if (!head) {
        return newNode;
    }

    Student *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

string generateStudentID(Student *head) {
    if (!head) {
        return "SW01083001"; // Starting ID
    }

    Student *temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    // Extract last 3 digits, increment, and return new ID
    string lastID = temp->id;
    int lastNum = stoi(lastID.substr(7)); // Extracting last 3 digits
    lastNum++;
    return "SW01083" + (lastNum < 10 ? "00" : (lastNum < 100 ? "0" : "")) + to_string(lastNum);
}

void user(Student *&head) {
    string courses[] = {"Computer Science", "Data Science", "Artificial Intelligence"};
    int courseFee = 1940;
    int choicestudent;

    do {
        cout << "\nWelcome to the Student System. Please choose one of the following functions:" << endl;
        cout << "1. Register New Student" << endl
             << "2. View All Students" << endl
             << "3. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choicestudent;
        system("cls");
        switch (choicestudent) {
            case 1: {
                string name, course;
                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, name);

                string id = generateStudentID(head);
                cout << "Student ID Assigned: " << id << endl;

                cout << "\nChoose a course to enroll in:" << endl;
                for (int i = 0; i < 3; i++) {
                    cout << i + 1 << ". " << courses[i] << endl;
                }
                int courseChoice;
                cout << "Enter your choice (1-3): ";
                cin >> courseChoice;

                if (courseChoice >= 1 && courseChoice <= 3) {
                    course = courses[courseChoice - 1];
                    head = addStudent(head, id, name, course, courseFee);
                    cout << "Student " << name << " enrolled in " << course << " successfully!" << endl;
                } else {
                    cout << "Invalid course choice!" << endl;
                }
                break;
            }
            case 2:
                viewStudent(head);
                break;
            case 3:
                cout << "Exiting Student System." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choicestudent != 3);
}

int main() {
    int choice;
    Student *head = nullptr; // Initialize empty linked list

    do {
        cout << "\nChoose (1) for Admin and (2) for New Student and enter (-1) to exit: ";
        cin >> choice;
        system("cls");
        if (choice == 2) {
            user(head);
        } else if (choice == -1) {
            cout << "Exiting the system." << endl;
        } else {
            cout << "Invalid Option! Please try again." << endl;
        }
    } while (choice != -1);

    return 0;
}
