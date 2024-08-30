/* Practice: Classes and vectors.
 * Store the name, age and generate a tag for each student */

#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <vector>


class Student
{
    std::string m_name{};
    int m_age{};
    int m_tag{};

public:
    Student() = default;

    Student (std::string_view name, int age, int tag)
    :m_name{name}, m_age{age}, m_tag{tag}
    {
    }

    //getter function
    std::string getName() const {return m_name;}
    int getAge() const {return m_age;}
    int getTag() const {return m_tag;}

};


std::vector <Student> my_vector{};
int tag{0};


void enterStudent()
{
    std::string name{};
    int age;
    tag++;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);


    std::cout << "Enter age: ";
    std::cin >> age;

    Student newStudent {name, age, tag};        //create new Student class

    my_vector.emplace_back(newStudent);         //add Student to the vector of students

}


void printStudents()
{
    std::cout << "There are currently " << my_vector.size() << " students in your list\n";
    std::cout << "-- Name -- Age -- Tag#\n";

    for (const auto& a: my_vector)
    {
        std::cout << a.getName() << " " << a.getAge() << " " << a.getTag() << '\n';
    }
    
}

void getStudentbyName()
{
    std::string name{};

    std::cout << "Type Student to search :";
    getline(std::cin, name);


    for (const auto& a: my_vector)
    {
        if (a.getName() == name)
        {
            std::cout << a.getName() << " " << a.getAge() << " " << a.getTag() << '\n';
            return;
        }

    }
    std::cout << "Name not found\n";

/* 
Or you can search by using std::find_if and lambda function:
   auto it{ std::find_if(my_vector.begin(), my_vector.end(),
                                                          [&name](const Student &a)
                                                          {
                                                              return a.getName() == name;
                                                          }
    )};

    if (it != my_vector.end())
        std::cout << it->getName() << " " << it->getAge() << " " << it->getTag() << '\n';
    else
        std::cout << "Name not found\n";
*/
}


void getStudentbyTag()
{
    int my_tag{};

    std::cout << "Type Tag to search :";
    std::cin >> my_tag;

    for (const auto& a: my_vector)
    {
        if (a.getTag() == my_tag)
        {
            std::cout << a.getName() << " " << a.getAge() << " " << a.getTag() << '\n';
            return;
        }
    }

    std::cout << "Tag not found\n";

}

int main()
{
    while(true)
    {
        //ask user what he wants to do, (1) enter new student, (2) read list of all students, (3) get student by tag
        std::cout << "\n1: Enter new Student\n"
        << "2: Display all Students\n"
        << "3: Get Student by name\n"
        << "4: Get Student by tag\n"
        << "5: Exit\n"
        << "Enter your choice: ";

        char choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
            case '1':
                enterStudent();
                break;
            case '2':
                printStudents();
                break;
            case '3':
                getStudentbyName();
                break;
            case '4':
                getStudentbyTag();
                break;
            case '5':
                std::cout << "Exiting program..";
                return 0;
            default:
                std::cout << "Invalid entry. Try again\n";
                continue;
        }
    }

    return 0;
}
