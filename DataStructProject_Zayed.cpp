#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;

int studentincrement = 1;

struct Student {
    string id;
    string name;
    vector<string> course;
    vector<double> coursefee;
    double totalFee;
    Student *next;
};

Student *createNode(string id, string name, vector<string> course, vector<double> coursefee, double totalFee) {
    Student *n = new Student();
    n->id = id;
    n->name = name;
    n->course = course;
    n->coursefee = coursefee;
    n->totalFee = totalFee;
    n->next = nullptr;
    // Calculate Total Fee
    double sum = 0;
    for (int i = 0; i < coursefee.size(); i++) {
        sum += coursefee[i];
    }
    n->totalFee = sum;

    return n;
}


void viewStudent(Student *head) {
    if (!head) {
        cout << "No students in the list." << endl;
    }
    Student *temp = head;
    while (temp) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << endl;
        for (int i = 0; i < temp->course.size(); i++) {
            cout << "Course " << i + 1 << ": " << temp->course[i] << ", Fee: RM" << temp->coursefee[i] << endl;
        }
        cout << "\nTotal Fee : RM" << temp->totalFee << endl;
        temp = temp->next;
        cout<<endl;
    }
}

string generateStudentID() {
    string prefix = "SW01083"; // Fixed prefix for student IDs
    string id = prefix + string(3 - to_string(studentincrement).length(), '0') + to_string(studentincrement);
    studentincrement++; // Increment counter for the next ID
    return id;
}


Student* removeStudent(Student *head, string id) {
    if (!head) {
        cout << "No students to remove." << endl;
        return head;
    }

    if (head->id == id) {
        Student *temp = head;
        head = head->next;
        delete temp;
        cout << "Student with ID " << id << " removed successfully." << endl;
        return head;
    }

    Student *current = head;
    while (current->next && current->next->id != id) {
        current = current->next;
    }

    if (current->next) {
        Student *temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Student with ID " << id << " removed successfully." << endl;
    } else {
        cout << "Student with ID " << id << " not found." << endl;
    }
    return head;
}

Student* addStudent(Student *head, string id, string name, vector<string> course, vector<double> coursefee, double totalFee) {
    Student *newNode = createNode(id, name, course, coursefee, totalFee);
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

Student *updateStudent(Student *&head, string id){
    Student *temp=head;
    while (temp){
        if (temp->id == id){
            cout << "Updating details for student ID: " << temp->id << endl;
            string newId;
            cout << "Enter new ID : ";
            cin >> newId;
            temp->id = newId; // Update the ID
            
            // You can add more fields for updates, such as course, fee, etc.
            cout << "Update Successful!" << endl;
            break;
        }
        temp = temp->next;
    }
    if (!temp){
        cout << "Student with id " << id << " not found" << endl;
    }
    return head;
}

void searchStudent(Student *head, string id) {
    Student *temp = head;
    int choice;
    while (temp) {
        if (temp->id == id) {
            cout << "Student Found: ID: " << temp->id << ", Name: " << temp->name << endl;

             cout << "Choose : " << endl
                  << " 1. Update student details. "
                  << "2. Exit." << endl;

            cin >> choice;

         if (choice == 1){
            updateStudent(head, id);
            }
        break;
        return;
        }
        temp = temp->next;
    }

    if (!temp){
        cout << "Student with ID " << id << " not found." << endl;
    }
}

Student* createDummyLinkedList(Student *head){
    Student *dummyHead = nullptr;
    Student *temp = head;
    Student *current = nullptr;

    while (temp!= nullptr){
        Student * newNode = createNode(temp->id, temp->name, temp->course, temp->coursefee, temp->totalFee);
        if (dummyHead == nullptr){
            dummyHead = newNode;
            current = newNode;
        }else {
            current ->next = newNode;
            current= newNode;
        }
        temp = temp->next;
    }
    return dummyHead;
}

void bubbleSort(Student *&head, int sortchoice) {
    if (!head || !head->next)
        return;

    switch (sortchoice) {
        case 1: {
            bool swapped;
            do {
                swapped = false;
                Student *current = head;

                while (current->next != nullptr) {
                    if (current->totalFee > current->next->totalFee) {
                        swap(current->id, current->next->id);
                        swap(current->name, current->next->name);
                        swap(current->course, current->next->course);
                        swap(current->coursefee, current->next->coursefee);
                        swap(current->totalFee, current->next->totalFee);
                        swapped = true;
                    }
                    current = current->next;
                }
            } while (swapped);
            break;
        }

        case 2: {
            bool swapped;
            do {
                swapped = false;
                Student *current = head;

                while (current->next != nullptr) {
                    // Compare only the first character of the names
                    if (tolower(current->name[0]) > tolower(current->next->name[0])) {
                        swap(current->id, current->next->id);
                        swap(current->name, current->next->name);
                        swap(current->course, current->next->course);
                        swap(current->coursefee, current->next->coursefee);
                        swap(current->totalFee, current->next->totalFee);
                        swapped = true;
                    }
                    current = current->next;
                }
            } while (swapped);
            break;
        }
    }
}


void printList(Student* head) {
    Student* current = head;
    while (current != nullptr) {
        cout << "ID: " << current->id << ", Name: " << current->name
             << ", Courses: ";
        for (vector<string>::iterator it = current->course.begin(); it != current->course.end(); ++it) {
            cout << *it << " ";
        }

        cout << ", Total Fee : " << current->totalFee;
        cout << endl;
        current = current->next;
    }
}


void admin(Student *&head) {
    int choiceadmin;
    do {
        system("cls");
        cout << "\n=========================================" << endl;
        cout << "| " << setw(23) << right << "ADMIN MENU" << setw(16) << " |" << endl;
        cout << "=========================================" << endl;
        cout << "| " << setw(5) << left << "1." << setw(32) << left << "View All Students" << " |" << endl;
        cout << "| " << setw(5) << left << "2." << setw(32) << left << "Remove Student" << " |" << endl;
        cout << "| " << setw(5) << left << "3." << setw(32) << left << "Search Student" << " |" << endl;
        cout << "| " << setw(5) << left << "4." << setw(32) << left << "Sort Students" << " |" << endl;
        cout << "| " << setw(5) << left << "5." << setw(32) << left << "Exit" << " |" << endl;
        cout << "=========================================" << endl;
        cout << "Enter choice: ";
        cin >> choiceadmin;

        switch (choiceadmin) {
            case 1:
            	system("cls");
                viewStudent(head);
                break;
            case 2: {
            	system("cls");
                string id;
                cout << "Enter student ID to remove: ";
                cin >> id;
                head = removeStudent(head, id);
                break;
            }
            case 3: {
            	system("cls");
                string id;
                cout << "Enter student ID to search: ";
                cin >> id;
                searchStudent(head,id);
                break;
            }
            case 4: {
                system("cls");
                int sortChoice;
                cout << "Sort Students By : " << endl
                	<< "1. Total Fee" <<endl
                    << "2. Name" <<endl;

                cout << "Enter your choice : ";
                cin >> sortChoice;

                //Create dummy linked list 
                Student *dummyHead = createDummyLinkedList(head);

                switch (sortChoice){
                    case 1: 
                        bubbleSort(dummyHead,sortChoice);
                        printList(dummyHead);
                        break;
                    case 2: 
                        bubbleSort(dummyHead,sortChoice);
                        printList(dummyHead);
                        break;
                }
            break;
            }
            
            case 5: 
                cout << "Exiting the program";
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choiceadmin != 5);
}

void user(Student *&head) {
    int choicestudent;
    string courses[] = {"Computer Science", "Data Science", "Artificial Intelligence"};
    double courseFee[] = {1940, 2040, 2140};

    do {
        system("cls");
        cout << "\n====================================" << endl;
        cout << "| " << setw(20) << right << "USER MENU" << setw(15) << "| " << endl;
        cout << "====================================" << endl;
        cout << "| " << setw(5) << left << "1." << setw(28) << left << "Add New Student" << "| " << endl;
        cout << "| " << setw(5) << left << "2." << setw(28) << left << "View All Students" << "| " << endl;
        cout << "| " << setw(5) << left << "3." << setw(28) << left << "Exit" << "| " << endl;
        cout << "====================================" << endl;
        cout << "Enter choice: ";
        cin >> choicestudent;

        switch (choicestudent) {
            case 1: {
            	system("cls");
                string name;
                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, name);
                string id = generateStudentID();
                cout << "Generated ID: " << id << endl;

                vector<string> selectedCourses;
                vector<double> selectedFees;
                char choice;
                do {
                    cout << "\nAvailable Courses:" << endl;
                    for (int i = 0; i < 3; i++) {
                        cout << i + 1 << ". " << courses[i] << " (Fee: RM" << courseFee[i] << ")" << endl;
                    }
                    int courseChoice;
                    cout << "\nEnter course number to enroll: ";
                    cin >> courseChoice;

                    if (courseChoice >= 1 && courseChoice <= 3) {
                        selectedCourses.push_back(courses[courseChoice - 1]);
                        selectedFees.push_back(courseFee[courseChoice - 1]);
                    } else {
                        cout << "Invalid course choice!" << endl;
                    }

                    cout << "Add another course? (y/n): ";
                    cin >> choice;
                } while (choice == 'y' || choice == 'Y');

                double totalFee = 0;
                for (double fee : selectedFees) {
                    totalFee += fee;
                }
                head = addStudent(head, id, name, selectedCourses, selectedFees, totalFee);
                cout << "Student added successfully." << endl;
                cout << "Total Fee = RM" << totalFee << endl;
                break;
            }
            case 2:
            	system("cls");
                viewStudent(head);
                break;
            case 3:
                cout << "Exiting User Menu." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choicestudent != 3);
}

void freeMemory(Student *head) {
    while (head) {
        Student *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int choice;
    Student *head = nullptr;

    do {
    system("color 06");
        cout << "\n=========================================" << endl;
        cout << "| " << setw(23) << right << "MAIN MENU" << setw(16) << "  |" << endl;
        cout << "=========================================" << endl;
        cout << "| " << setw(5) << left << "1." << setw(32) << left << "Admin" << " |" << endl;
        cout << "| " << setw(5) << left << "2." << setw(32) << left << "User" << " |" << endl;
        cout << "| " << setw(5) << left << "-1." << setw(32) << left << "Exit" << " |" << endl;
        cout << "=========================================" << endl;
        cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        system("cls");
        admin(head);
    } else if (choice == 2) {
        system("cls");
        user(head);
    } else if (choice == -1) {
        cout << "Exiting program." << endl;
    } else {
        cout << "Invalid choice. Please try again." << endl;
    }
} while (choice != -1);

    freeMemory(head);
    return 0;
}