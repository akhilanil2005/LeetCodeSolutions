/*
Problem:
Write a C++ program that takes a string input from the user and counts the number of elements (characters) in the string, including spaces and special characters. Output the count.

Solution:
*/

#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    int count = input.length();

    std::cout << "Number of elements in the string: " << count << std::endl;
    return 0;
}