#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char **argv)
{
    std::string sampleLower("this is a lower string");
    std::string sampleUpper("THIS IS A UPPER STRING");

    std::cout << sampleLower << std::endl;
    std::cout << sampleUpper << std::endl;
    std::cout << "----------------------" << std::endl;
    std::string sampleLower("this is a lower string");
    std::transform(sampleLower.begin(), sampleLower.end(), sampleLower.begin(), toupper); // Now this `sampleLower` is made upper
    std::transform(sampleUpper.begin(), sampleUpper.end(), sampleUpper.begin(), tolower); // Now this `sampleUpper` is made lower
    std::cout << sampleLower << std::endl;
    std::cout << sampleUpper << std::endl;
    return 0;
}