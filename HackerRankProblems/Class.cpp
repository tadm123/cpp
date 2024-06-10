/*
You have to create a class, named Student, representing the student's details, as mentioned above, and store the data of a student. 
Create setter and getter functions for each element; that is, the class should at least have following functions:

get_age, set_age
get_first_name, set_first_name
get_last_name, set_last_name
get_standard, set_standard
Also, you have to create another method to_string() which returns the string consisting of the above elements, separated by a comma(,)
*/


#include <iostream>
#include <sstream>
#include <string>

class Student
{
    int m_age;
    int m_standard;
    std::string m_first_name;
    std::string m_last_name;

public:
    //setter functions
    void set_age(int age){m_age=age;}
    void set_standard(int standard){m_standard=standard;}
    void set_first_name(std::string& first_name){m_first_name=first_name;}
    void set_last_name(std::string& last_name){m_last_name=last_name;}

    //getter functions
    int get_age(){return m_age;}
    int get_standard(){return m_standard;}
    std::string& get_first_name(){return m_first_name;}
    std::string& get_last_name(){return m_last_name;}


    //return a string of all member variables
    std::string to_string()
    {
        std::string temp{};
        temp += std::to_string(m_age);
        temp += ",";
        temp += m_first_name;
        temp += ",";
        temp += m_last_name;
        temp += ",";
        temp += std::to_string(m_standard);


        return temp;
    }
};

int main() {
    int age, standard;
    std::string first_name, last_name;

    std::cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    std::cout << st.get_age() << "\n";
    std::cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    std::cout << st.get_standard() << "\n";
    std::cout << "\n";
    std::cout << st.to_string();

    return 0;
}
