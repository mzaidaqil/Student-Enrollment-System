# Student Enrollment System

## Overview
The **Student Enrollment System** is a project that implements a student management system using a linked list as the primary data structure. The system supports essential operations like adding, updating, removing, and searching student records, as well as sorting data for efficient management. This project demonstrates practical usage of data structures and algorithms to solve real-world data management challenges.

## Features
### Admin-Level Operations
- **Add Students**: Register new students with their ID, name, and courses.
- **Remove Students**: Delete a student's record by their ID.
- **Update Student Information**: Modify details such as name and courses.
- **Search Students**: Quickly locate students by their ID or name.
- **Sort Students**: Organize student records based on their name or ID.

### Student-Level Operations
- **Register for Courses**: Students can register for multiple courses.
- **View Enrolled Courses**: Display all courses a student has registered for.
- **Calculate Total Cost**: Display the total cost of all enrolled courses.

## Implementation Details
### Data Structure
- **Linked List**: Used to store and manage student records, enabling dynamic memory allocation and efficient insertion or deletion operations.

### Algorithms
- **Sorting**: Implemented a basic sorting algorithm for organizing records by name or ID.
- **Searching**: Linear search is used to find specific records efficiently within the linked list.

### Key Functions
- `addStudent()`: Adds a new student to the system.
- `removeStudent()`: Deletes a student record from the linked list.
- `updateStudent()`: Updates existing details for a student.
- `viewStudents()`: Displays all student records.
- `searchStudent()`: Searches for students by ID or name.
- `sortStudents()`: Sorts records based on specified criteria.

## Learning Outcomes
Through this project, the following skills were developed:
1. **Data Structures**: Gained hands-on experience with linked lists for managing dynamic data.
2. **Algorithm Implementation**: Learned to integrate sorting and searching algorithms for better data handling.
3. **Practical Problem-Solving**: Designed and implemented a system that meets the requirements of managing enrollment data efficiently.
4. **Software Development**: Improved understanding of project structure, function design, and debugging in C++.

## Future Enhancements
- **Database Integration**: Replace the linked list with a database for persistent storage.
- **GUI Development**: Add a user-friendly graphical interface for both admins and students.
- **Additional Features**:
  - Generate reports for student performance or course enrollment.
  - Implement advanced search features using binary search or hash tables.

## How to Use
### Prerequisites
- Install a C++ compiler (e.g., g++).
- Clone this repository to your local machine.

### Compilation and Execution
1. Navigate to the project directory:
   ```bash
   cd Group\ Project
