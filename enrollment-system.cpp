#include <iostream>
#include <string>
#include <list>
#include <stdexcept>

/*
References
	Chained hash tables by Prof. Harder
	Factory method pattern : CMSC 23
*/

class Student
{
public:
    int studentID, age;
    std::string familyName, firstName, middleName, gender, contactNum, address;
    Student() {}
};

class HashTable
{
private:
    int size;
    std::list<Student *> *table;
    int elementsSize;

public:
    HashTable();
    int hashFunction(int);
    bool isEmpty();
    Student *getStudentDetails();
    void enrollStudent();
    void removeStudent(int);
    void searchStudent(int);
    void printTable();
};

HashTable::HashTable()
{
    this->size = 0;
    this->elementsSize = 10;
    table = new std::list<Student *>[elementsSize];
}

int HashTable::hashFunction(int studentID)
{ //computing the simplified identity number
    return studentID % elementsSize;
}

bool HashTable::isEmpty()
{ //check if the table is empty
    if (size == 0)
        return true;
    return false;
}

Student *HashTable::getStudentDetails()
{ //getting student details
    Student *student = new Student();

    std::cout << "Family Name: ";
    std::getline(std::cin, student->familyName);

    std::cout << "First Name: ";
    std::getline(std::cin, student->firstName);

    std::cout << "Middle Name: ";
    std::getline(std::cin, student->middleName);

    std::cout << "Gender: ";
    std::getline(std::cin, student->gender);

    std::cout << "Contact Number: ";
    std::getline(std::cin, student->contactNum);

    std::cout << "Address: ";
    std::getline(std::cin, student->address);

    std::cout << "Student ID: ";
    std::cin >> student->studentID;
    std::cin.ignore();

    std::cout << "Age: ";
    std::cin >> student->age;

    return student;
}

void HashTable::enrollStudent()
{ //inserting student object in the hash table
    Student *studentDetails = getStudentDetails();
    table[hashFunction(studentDetails->studentID)].push_back(studentDetails);
    size++;
}

void HashTable::removeStudent(int studentID)
{ //removing student object in the hash table

    if (isEmpty())
    {
        std::cout << "Table is empty. Nothing to remove." << std::endl;
        return;
    }

    int hashKey = hashFunction(studentID);
    bool keyExist = false;

    for (auto i = table[hashKey].begin(); i != table[hashKey].end(); i++)
    {
        if ((*i)->studentID == studentID)
        {
            keyExist = true;
            table[hashKey].erase(i);
            std::cout << "STUDENT DELETED!" << std::endl;
            size--;
            break;
        }
    }

    if (!keyExist)
        std::cout << "STUDENT DOESN'T EXIST!" << std::endl;
}

void HashTable::searchStudent(int studentID)
{ //searching student object in the hash table

    if (isEmpty())
    {
        std::cout << "Table is empty. Nothing to search." << std::endl;
        return;
    }

    int hashKey = hashFunction(studentID);
    bool keyExist = false;
    Student *student;

    for (auto i : table[hashKey])
    {
        if (i->studentID == studentID)
        {
            keyExist = true;
            student = i;
            break;
        }
    }
    if (!keyExist)
        std::cout << "STUDENT DOESN'T EXIST!" << std::endl;
    else
        std::cout << "STUDENT EXIST! " << std::endl;
}

void HashTable::printTable()
{ //printing students

    if (isEmpty())
    {
        std::cout << "Table is empty. Nothing to print." << std::endl;
        return;
    }

    std::cout << "S  T  U  D  E  N  T     D  A  T  A" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "STUDENTS:  " << std::endl;

    for (int i = 0; i < elementsSize; i++)
    {
        for (auto student : table[i])
        {
            std::cout << "Name: " << student->familyName << ", ";
            std::cout << student->firstName << ", ";
            std::cout << student->middleName << " ";
            std::cout << "Age: " << student->age << " ";
            std::cout << "Gender: " << student->gender << " ";
            std::cout << "Contact number: " << student->contactNum << " ";
            std::cout << "Address: " << student->address << " ";
            std::cout << "Student ID: " << student->studentID << "\n";
        }
    }
}

class IGradeLevel
{ //P R O D U C T
public:
    virtual void enrollStudent() = 0;
    virtual void removeStudent(int) = 0;
    virtual void searchStudent(int) = 0;
    virtual void printTable() = 0;
};

class Grade_1 : public IGradeLevel
{ //C O N C R E T E	P R O D U C T
private:
    HashTable table;

public:
    void enrollStudent() override { table.enrollStudent(); }
    void removeStudent(int studentID) override { table.removeStudent(studentID); }
    void searchStudent(int studentID) override { table.searchStudent(studentID); }
    void printTable() override
    {
        std::cout << " ----G R A D E	  O N E----" << std::endl;
        table.printTable();
    }
};

class Grade_2 : public IGradeLevel
{ //C O N C R E T E	P R O D U C T
private:
    HashTable table;

public:
    void enrollStudent() override { table.enrollStudent(); }
    void removeStudent(int studentID) override { table.removeStudent(studentID); }
    void searchStudent(int studentID) override { table.searchStudent(studentID); }
    void printTable() override
    {
        std::cout << " ----G R A D E	  T W O----" << std::endl;
        table.printTable();
    }
};

class Grade_3 : public IGradeLevel
{ //C O N C R E T E	P R O D U C T
private:
    HashTable table;

public:
    void enrollStudent() override { table.enrollStudent(); }
    void removeStudent(int studentID) override { table.removeStudent(studentID); }
    void searchStudent(int studentID) override { table.searchStudent(studentID); }
    void printTable() override
    {
        std::cout << " ----G R A D E	  T H R E E----" << std::endl;
        table.printTable();
    }
};

class Grade_4 : public IGradeLevel
{ //C O N C R E T E	P R O D U C T
private:
    HashTable table;

public:
    void enrollStudent() override { table.enrollStudent(); }
    void removeStudent(int studentID) override { table.removeStudent(studentID); }
    void searchStudent(int studentID) override { table.searchStudent(studentID); }
    void printTable() override
    {
        std::cout << " ----G R A D E	  F O U R----" << std::endl;
        table.printTable();
    }
};

class Grade_5 : public IGradeLevel
{ //C O N C R E T E	P R O D U C T
private:
    HashTable table;

public:
    void enrollStudent() override { table.enrollStudent(); }
    void removeStudent(int studentID) override { table.removeStudent(studentID); }
    void searchStudent(int studentID) override { table.searchStudent(studentID); }
    void printTable() override
    {
        std::cout << " ----G R A D E	  F I V E---" << std::endl;
        table.printTable();
    }
};

class Grade_6 : public IGradeLevel
{ //C O N C R E T E	P R O D U C T
private:
    HashTable table;

public:
    void enrollStudent() override { table.enrollStudent(); }
    void removeStudent(int studentID) override { table.removeStudent(studentID); }
    void searchStudent(int studentID) override { table.searchStudent(studentID); }
    void printTable() override
    {
        std::cout << " ----G R A D E	  S I X---" << std::endl;
        table.printTable();
    }
};

class GradeLevelProducer
{ //C R E A T O R
public:
    ~GradeLevelProducer() { delete grade; }
    IGradeLevel *grade;
    virtual IGradeLevel *gradeLevel() const = 0;
    void render() { grade = this->gradeLevel(); }
};

class Grade1Producer : public GradeLevelProducer
{ //C O N C R E T E	C R E A T O R
public:
    IGradeLevel *gradeLevel() const override
    {
        return new Grade_1();
    }
};

class Grade2Producer : public GradeLevelProducer
{ //C O N C R E T E	C R E A T O R
public:
    IGradeLevel *gradeLevel() const override
    {
        return new Grade_2();
    }
};

class Grade3Producer : public GradeLevelProducer
{ //C O N C R E T E	C R E A T O R
public:
    IGradeLevel *gradeLevel() const override
    {
        return new Grade_3();
    }
};

class Grade4Producer : public GradeLevelProducer
{ //C O N C R E T E	C R E A T O R
public:
    IGradeLevel *gradeLevel() const override
    {
        return new Grade_4();
    }
};

class Grade5Producer : public GradeLevelProducer
{ //C O N C R E T E	C R E A T O R
public:
    IGradeLevel *gradeLevel() const override
    {
        return new Grade_5();
    }
};

class Grade6Producer : public GradeLevelProducer
{ //C O N C R E T E	C R E A T O R
public:
    IGradeLevel *gradeLevel() const override
    {
        return new Grade_6();
    }
};

class EnrollmentApp
{
public:
    ~EnrollmentApp() { delete creator; }
    GradeLevelProducer *creator;
    void initialize(int num)
    {
        switch (num)
        {
        case 1:
            creator = new Grade1Producer();
            break;
        case 2:
            creator = new Grade2Producer();
            break;
        case 3:
            creator = new Grade3Producer();
            break;
        case 4:
            creator = new Grade4Producer();
            break;
        case 5:
            creator = new Grade5Producer();
            break;
        case 6:
            creator = new Grade6Producer();
            break;
        default:
            throw std::invalid_argument("INVALID INPUT! Choose the grade level under specified options.");
        }
        creator->render();
    }
};

int main()
{
    EnrollmentApp app = EnrollmentApp();
    int choice = 0;
    std::cout << "***REFERENCES:\nChained hash tables by Prof.Harder\nFactory method pattern : CMSC 23***\n"
              << std::endl;
    std::cout << "1.Grade 1\n2.Grade 2\n3.Grade 3\n4.Grade 4\n5.Grade 5\n6.Grade 6" << std::endl;
    std::cout << "Enter choice: ";
    std::cin >> choice;

    try
    {
        app.initialize(choice);
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << "exception: " << e.what() << std::endl;
        return -1;
    }

    do
    {
        std::cout << "\n1.Enroll Student \n2.Remove Student \n3.Search Student \n4.Print Table\n5.Quit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        std::cin.ignore();
        switch (choice)
        {
        case 1:
            app.creator->grade->enrollStudent();
            break;
        case 2:
            std::cout << "Enter student ID: ";
            std::cin >> choice;
            app.creator->grade->removeStudent(choice);
            std::cin.ignore();
            break;
        case 3:
            std::cout << "Enter student ID: ";
            std::cin >> choice;
            app.creator->grade->searchStudent(choice);
            std::cin.ignore();
            break;
        case 4:
            app.creator->grade->printTable();
            break;
        case 5:
            return 0;
        default:
            std::cout << "INVALID INPUT!";
            break;
        }
    } while (true);
}