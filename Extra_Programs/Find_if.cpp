/*
  This program finds if an element (string) of a vector contains a substring
  Ex: if searching for "bb", it should match at Gabby. Then we output the position, or index, of the element of the vector in which it was found.
  We used std::find_if to iterate throught the elements of the vector, and str.find() method of the <string> library to see if the substring appears in any vector element (string) 
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int main()
{

    std::vector<std::string> vect{"Daniel", "Maria", "Edgar", "Gabby"};

    std::string word{"bb"};

    auto it{std::find_if(vect.begin(),vect.end(),
                         [&word](const auto& elem)
                         {
                            return (elem.find(word) != std::string_view::npos);  //find if each element (string) of vector matches the word
                         }
                         )};

    if (it != vect.end())   //if it found it (exited before it iterated through the whole vector
    {
        std::cout << "Found!\n";
        std::cout << "Position: " << it - vect.begin() + 1;
    }
    else
    {
        std::cout << "Not found!\n";
    }


    return 0;
}
