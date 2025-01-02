#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int studentincrement = 1;

struct Student {
    string id;
    string name;
    vector<string> course;
    vector<double> coursefee;
    vector<double> totalFee;
    Student *next;
};

Student *createNode(string id, string name, vector<string> course, vector<double> coursefee, vector<double> totalFee) {
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
    n->totalFee.push_back(sum);

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

Student* addStudent(Student *head, string id, string name, vector<string> course, vector<double> coursefee, vector<double> totalFee) {
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
        }
        temp = temp->next;
    }
    cout << "Student with id " << id << " not found" << endl;
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

        return;
        }
        temp = temp->next;
    }
    cout << "Student with ID " << id << " not found." << endl;

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
                    if (current->id > current->next->id) {
                        swap(current->id, current->next->id);
                        swap(current->name, current->next->name);
                        swap(current->course, current->next->course);
                        swap(current->coursefee, current->next->coursefee);
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
        for (const auto& c : current->course) {
            cout << c << " ";
        }
        cout << ", Fees: ";
        for (const auto& fee : current->coursefee) {
            cout << fee << " ";
        }
        cout << endl;
        current = current->next;
    }
}


void admin(Student *&head) {
    int choiceadmin;
    do {
        cout << "\nAdmin Menu:" << endl;
        cout << "1. View All Students\n2. Remove Student\n3. Search Student\n4. Sort student\n5. Exit\nEnter choice: ";
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
            case 4:
            system("cls");
            int sortChoice;
                cout << "Sort Students By : " << endl
                	<< "1. Total Fee" <<endl
                    << "2. Name" <<endl;

                cout << "Enter your choice : ";
                cin >> sortChoice;

                switch (sortChoice){
                    case 1: 
                        bubbleSort(head,sortChoice);
                        printList(head);
                        break;
                    case 2: 
                       bubbleSort(head,sortChoice);
                        printList(head);
                        break;
                }
            break;
            
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
        cout << "\nUser Menu:" << endl;
        cout << "1. Add New Student\n2. View All Students\n3. Exit\nEnter choice: ";
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

                vector<double> totalFee = {0};
                for (double fee : selectedFees) {
                    totalFee[0] += fee;
                }
                head = addStudent(head, id, name, selectedCourses, selectedFees, totalFee);
                cout << "Student added successfully." << endl;
                cout << "Total Fee = RM" << totalFee[0] << endl;
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
        cout << "\nMain Menu:\n1. Admin\n2. User\n-1. Exit\nEnter choice: ";
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
            cout << "Invalid choice!" << endl;
        }
    } while (choice != -1);

    freeMemory(head);
    return 0;
}