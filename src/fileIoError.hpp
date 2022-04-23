#include <iostream>
#include <fstream>
#include <exception>



using namespace std;



/*
 * Defining Custom Errors to Control for
 *
 * Problems Opening and Closing Files
 *
 * */



//struct defining custom exceptions
struct failToOpen : public exception
{

   const char* what() const throw(){

       return "The File Could Not Be Opened!!!!!!!";
   }

};




//struct defining custom exceptions
struct failToClose : public exception
{

   const char* what() const throw(){

       return "The File Could Not Be Closed!!!!!!";
   }

};



//struct defining custom exceptions
struct alreadyOpened : public exception
{

   const char* what() const throw(){

       return "The File is Already Opened!!!!!!";
   }

};




//struct defining custom exceptions
struct alreadyClosed : public exception
{

   const char* what() const throw(){

       return "The File is Not Open!!!!!!";
   }

};




/*
 * End of Custom Errors
 *
 */






