#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

//struct defining custom exceptions
struct failToOpen : public exception
{

   const char* what() const throw(){

       return "The File Could not be opened";
   }

};


