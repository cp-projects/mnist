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



/*
 * End of Custom Errors
 *
 * */





int main(){



	      /*
	       *
	       *  OPENING THE
	       *
	       *  LABELS FILE
	       *
	       *
	       * */



              //opens labels file
              ifstream labels;
              labels.open("rawMnistData/train-labels-idx1-ubyte", ios_base::in);


              //check if file opened
              if(!labels.is_open()){

                  //file did not open
                  throw failToOpen();  
	      }

              
	      //confirm that file opened
	      else{

	          std::cout << "FILE OPENED" << '\n';
	      }





	      //testing reading
	      
	      char label;

              while(labels >> label){
	      
		      std::cout << std::hex << (int)label << ' ';
	      
	      
	      } 




              /*
               *
               *  CLOSING THE
               *
               *  LABELS FILE
               *
               *
               * */

  
	      //closes labels file
	      labels.close();

	      //check if file closed
	      if(labels.is_open()){
	          
		  //file did not close
	          throw failToClose();

	      }


              //confirm that file closed
	      else{
		  
		  std::cout << "FILE CLOSED" << '\n';
	      }


}




