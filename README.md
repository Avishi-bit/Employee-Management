# Restaurant Employee Management System

A beginner-friendly C++ console application that manages restaurant employees using Object-Oriented Programming concepts.

## Features

* Register different types of restaurant employees
* Assign fixed salaries based on employee role
* Automatically generate employee IDs
* Store multiple employees using a vector
* Display details of all registered employees

## Employee Roles

* Chef
* Head Chef
* Waiter
* Head Waiter
* Peon
* General Manager

## OOP Concepts Used

* **Encapsulation**
  Employee details such as employee ID and password are kept private.

* **Inheritance**
  All employee roles inherit from the `Employee` class.

* **Multilevel Inheritance**
  `HeadChef` inherits from `Chef`, and `HeadWaiter` inherits from `Waiter`.

* **Polymorphism**
  The `displayDetails()` function is virtual and behaves differently for each employee role.

* **Static Member Variable**
  `nextID` is used to automatically assign a unique employee ID to every employee.

## Class Structure

```text
Employee
├── Chef
│   └── HeadChef
├── Waiter
│   └── HeadWaiter
├── Peon
└── GeneralManager
```

## How to Run

1. Compile the program:

```bash
g++ employee_management.cpp -o employee_management
```

2. Run the program:

```bash
./employee_management
```

## Example Menu

```text
1. Chef
2. Head Chef
3. Waiter
4. Head Waiter
5. Peon
6. General Manager
7. Display All Employees
8. Exit
```

## Technologies Used

* C++
* Object-Oriented Programming
* STL Vector
