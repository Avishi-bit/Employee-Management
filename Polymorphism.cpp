// make an employee management system and use polymorphism, make smtg universal,
// make some child classes, etc.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// RESTAURANT MANAGEMENT

class Employee {
    protected:
        string name;
        string gender;
        int salary;
        int experience;
        int emp_ID;
        string role;

    public:
        Employee(int id, int roleSalary, string given_name, string given_gender, int yrs_exp, string emp_role) {
            emp_ID = id;
            salary = roleSalary;
            name = given_name;
            gender = given_gender;
            experience = yrs_exp;
            role = emp_role;
        }

        // GET FUNCTIONS
        int getID() {
            return emp_ID;
        }

        string getName() {
            return name;
        }

        string getGender() {
            return gender;
        }

        int getSalary() {
            return salary;
        }

        int getExperience() {
            return experience;
        }

        string getRole() {
            return role;
        }

        // SET FUNCTIONS
        void setName(string given_name) {
            name = given_name;
        }

        void setGender(string given_gender) {
            gender = given_gender;
        }

        void setExperience(int yrs_exp) {
            experience = yrs_exp;
        }

        virtual void displayDetails() {
            cout << "\n------- EMPLOYEE DETAILS -------" << endl;
            cout << "Employee ID: " << emp_ID << endl;
            cout << "Name: " << name << endl;
            cout << "Gender: " << gender << endl;
            cout << "Experience: " << experience << " years" << endl;
            cout << "Salary: Rs. " << salary << endl;
            cout << "Role: " << role << endl;
        }
};


class Chef : public Employee {
    protected:
        string speciality;

    public:
        Chef(int id, string name, string gender, int experience, string given_speciality,int chefSalary = 100000, string role = "Chef")
            :Employee(id, chefSalary, name, gender, experience, role) {
            speciality = given_speciality;
        }

        void displayDetails() {
            Employee::displayDetails();
            cout << "Speciality: " << speciality << endl;
        }
};


class headChef : public Chef {
    private:
        string cul_school;
        int chefs_managed;

    public:
        headChef(int id, string name, string gender, int experience, string speciality,string school, int managed, int hchef_salary = 150000,string role = "Head Chef")
            :Chef(id, name, gender, experience, speciality, hchef_salary, role) {

            cul_school = school;
            chefs_managed = managed;
        }

        void displayDetails() {
            Employee::displayDetails();
            cout << "Speciality: " << speciality << endl;
            cout << "Culinary School: " << cul_school << endl;
            cout << "Number of Chefs Managed: " << chefs_managed << endl;
        }
};


class Waiter : public Employee {
    protected:
        string shift;

    public:
        Waiter(int id, string name, string gender, int experience, string given_shift,int wSalary = 50000, string role = "Waiter")
            :Employee(id, wSalary, name, gender, experience, role) {
            
            shift = given_shift;
        }

        void displayDetails() {
            Employee::displayDetails();
            cout << "Shift: " << shift << endl;
        }
};


class headWaiter : public Waiter {
    private:
        int waitersManaged;

    public:
        headWaiter(int id, string name, string gender, int experience, string shift,int managed, int hwSalary = 70000, string role = "Head Waiter")
            :Waiter(id, name, gender, experience, shift, hwSalary, role) {
            
            waitersManaged = managed;
        }

        void displayDetails() {
            Employee::displayDetails();
            cout << "Shift: " << shift << endl;
            cout << "Waiters Managed: " << waitersManaged << endl;
        }
};


class Peon : public Employee {
    private:
        string assignedArea;

    public:
        Peon(int id, string name, string gender, int experience, string area,int pSalary = 20000, string role = "Peon")
            :Employee(id, pSalary, name, gender, experience, role) {
            
            assignedArea = area;
        }

        void displayDetails() {
            Employee::displayDetails();
            cout << "Assigned Area: " << assignedArea << endl;
        }
};


class genManager : public Employee {
    private:
        string department;
        int staffManaged;

    public:
        genManager(int id, string name, string gender, int experience, string given_department, int managed, int gmSalary = 200000, string role = "General Manager")
            :Employee(id, gmSalary, name, gender, experience, role) {
            
            department = given_department;
            staffManaged = managed;
        }

        void displayDetails() {
            Employee::displayDetails();
            cout << "Department: " << department << endl;
            cout << "Staff Managed: " << staffManaged << endl;
        }
};


int main() {
    vector<Employee*> employees;
    int choice;
    int next_ID = 100;

    do {
        cout << "\n==============EMPLOYEE REGISTRATION==============" << endl;
        cout << "Choose your position: " << endl;
        cout << "1. Chef" << endl;
        cout << "2. Head Chef" << endl;
        cout << "3. Waiter" << endl;
        cout << "4. Head Waiter" << endl;
        cout << "5. Peon" << endl;
        cout << "6. General Manager" << endl;
        cout << "7. Display All Employees" << endl;
        cout << "8. EXIT" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        string name;
        string gender;
        int experience;

        if (choice >= 1 && choice <= 6) {
            cout << "\n======= EMPLOYEE DETAILS =======" << endl;
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter your gender: ";
            getline(cin, gender);
            cout << "Enter years of experience: ";
            cin >> experience;
            cin.ignore();
        }

        switch (choice) {
            case 1: {
                string speciality;
                cout << "Enter Speciality: ";
                getline(cin, speciality);

                employees.push_back(new Chef(next_ID, name, gender, experience, speciality));
                next_ID++;
                cout << "Employee Added." <<endl;
                break;
            }

            case 2: {
                string speciality;
                string cul_school;
                int chefs_managed;

                cout << "Enter Speciality: ";
                getline(cin, speciality);
                cout << "Enter Culinary School: ";
                getline(cin, cul_school);
                cout << "Number of Chefs Managed: ";
                cin >> chefs_managed;
                cin.ignore();

                employees.push_back(new headChef(next_ID, name, gender, experience, speciality, cul_school, chefs_managed));
                next_ID++;
                cout << "Employee Added." <<endl;
                break;
            }

            case 3: {
                string shift;
                cout << "Enter Shift: ";
                getline(cin, shift);

                employees.push_back(new Waiter(next_ID, name, gender, experience, shift));
                next_ID++;
                cout << "Employee Added." <<endl;
                break;
            }

            case 4: {
                string shift;
                int waitersManaged;
                cout << "Enter Shift: ";
                getline(cin, shift);
                cout << "Enter number of waiters managed: ";
                cin >> waitersManaged;
                cin.ignore();

                employees.push_back(new headWaiter(next_ID, name, gender, experience, shift, waitersManaged));
                next_ID++;
                cout << "Employee Added." <<endl;
                break;
            }

            case 5: {
                string assignedArea;
                cout << "Enter Assigned Area: ";
                getline(cin, assignedArea);
                
                employees.push_back(new Peon(next_ID, name, gender, experience, assignedArea));
                next_ID++;
                cout << "Employee Added." <<endl;
                break;
            }

            case 6: {
                string department;
                int staffManaged;
                cout << "Enter department managed: ";
                getline(cin, department);
                cout << "Enter number of staff managed: ";
                cin >> staffManaged;
                cin.ignore();

                employees.push_back(new genManager(next_ID, name, gender, experience,department, staffManaged));
                next_ID++;
                cout << "Employee Added." <<endl;
                break;
            }

            case 7:
                if (employees.empty()) {
                    cout << "No employees registered." << endl;
                }
                else {
                    for (int i = 0; i < employees.size(); i++) {
                        employees[i]->displayDetails();
                    }
                }
                break;

            case 8:
                cout << "Thank you." << endl;
                break;

            default:
                cout << "Invalid Choice." << endl;
                break;
        }

    } while (choice != 8);

    for (int i = 0; i < employees.size(); i++) {
        delete employees[i];
    }

    return 0;
}