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





int getLabel(int labelIndex){



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





	      /*
	       *
	       *  Reading the Labels File
	       *
	       *
	       *
	       * */


	      char label; //char with later int conversion necessary due to some earlier dependency regarding the file (maybe the way it was open) 


              labels.seekg(labelIndex);

   
              labels >> label;             
 

   

             
	     /*
	      *
	      * Print ALl Label Data
	      *
	      * */
   

	   /*char iterator;
	     while(labels >> iterator){
	      
	          
	         std::cout << (int)iterator << ' ';
	              
	      } */



	      
	    




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



return (int)label;

}





int main(){


	std::cout << getLabel(8) << '\n' << '\n';

	std::cout << getLabel(9) << '\n' << '\n';

	std::cout << getLabel(10) << '\n' << '\n';

        std::cout << getLabel(11) << '\n' << '\n';

	std::cout << getLabel(12) << '\n' << '\n';


}






