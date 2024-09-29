# Student Management System

This is a **Student Management System** implemented in C++ that allows the admin user to perform operations such as **inserting**, **editing**, and **viewing** student details. The system also includes login functionality for both admin and student users.

## Features

- **Login functionality**: Admin or students can log in using their credentials.
- **Insert student details**: Admin can add student details to the database.
- **Edit student details**: Admin can modify existing student records.
- **View student details**: Users can view specific student details after logging in.
- **Logout functionality**: Users can log out once their tasks are completed.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Usage](#usage)
- [Code Overview](#code-overview)
  - [Data Structure](#data-structure)
  - [Core Functions](#core-functions)
- [How to Run](#how-to-run)
- [Contributing](#contributing)
- [License](#license)

## Prerequisites

To compile and run this project, you need:

- A C++ compiler (e.g., GCC, Clang, MSVC)
- Basic knowledge of terminal/command prompt usage

## Usage

1. **Login**: Start by logging in using the username and password. By default, an admin user is inserted with:
   - Username: `admin`
   - Roll No: `1234`

2. **Menu Options**:
   - **Display Student Details**: Enter a student's name and roll number to view their details.
   - **Insert Student Details**: Admin can add new students by providing the student's information such as name, age, college year, GPA, CGPA, and roll number.
   - **Edit Student Details**: Admin can edit the details of any student by providing their roll number.
   - **Logout**: The user can log out after completing their tasks.

3. **Exit**: To stop the program, input `0` after the prompt for continuation.

## Code Overview

### Data Structure

The core data structure used is a **Singly Linked List**, where each node represents a student with the following attributes:

- `name` (char array): The student's name.
- `age` (int): The student's age.
- `clg_year` (int): The student's current year in college (between 1 and 4).
- `gpa` (float): The student's GPA.
- `cgpa` (float): The student's CGPA.
- `roll` (int): The student's unique roll number.
- `next` (pointer): A pointer to the next student node in the linked list.

### Core Functions

#### `createNode`
Creates and initializes a new student node.

#### `insertStudent`
Inserts a new student into the list. Ensures the roll number is unique and that the college year is valid.

#### `isRollNumberUnique`
Checks if the roll number is unique by scanning the list.

#### `displaySpecificStudent`
Displays the details of a specific student based on the provided username and roll number.

#### `login`
Validates the user's credentials (username and roll number).

#### `editStudentDetails`
Allows the admin to edit student details by specifying the student's roll number.

## How to Run

1. **Clone the repository**:

   ```bash
   git clone https://github.com/Suriyablue/student_data_base.CPP.git

### Key Changes:
1. **Markdown Formatting**: Added missing backticks and fixed code block indentation for better readability.
2. **Clarity**: Improved the phrasing in the "How to Run" section for clearer instructions.
3. **Sections for Contribution and License**: Included a simple contribution and license section for completeness.

You can now copy and paste this updated code directly into your `README.md` file. Let me know if you need any further adjustments!
