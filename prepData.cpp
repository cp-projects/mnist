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



//struct defining fail to open exception
struct failToOpen : public exception
{

   const char* what() const throw(){

       return "The File Could Not Be Opened!!!!!!!";
   }

};




//struct defining fail to close exception
struct failToClose : public exception
{

   const char* what() const throw(){

       return "The File Could Not Be Closed!!!!!!";
   }

};



//struct defining file is already opened exception
struct alreadyOpened : public exception
{

   const char* what() const throw(){

       return "The File is Already Opened!!!!!!";
   }

};




//struct defining file is already closed exception
struct alreadyClosed : public exception
{

   const char* what() const throw(){

       return "The File is Not Open!!!!!!";
   }

};




/*
 * End of Custom Errors
 *
 * */



/*
 *
 * Class for Processing Labels Data
 *
 *
 *
 *
 * */




class Labels{



    public:


              // Declaration of Reference to Labels
	      ifstream labels;


	      /*
	       *
	       * Method to Open File
	       *
	       *
	       *
	       * */

              void open(){


		  //Check to see if file needs to be closed
                  if(labels.is_open()){

                      throw alreadyOpened();
                  }


                  //opens labels file
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

             }




	      /*
	       *
	       * Method to Close File
	       *
	       *
	       *
	       * */


              void close(){


		  //Check to see if file needs to be closed    
		  if(!labels.is_open()){
		  
	              throw alreadyClosed();
                  }

	      
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


           
	      /*
	       *
	       *
	       * Method for Printing Labels Data
	       *
	       *
	       * */

               void printLabels(){
	       
	           
                      //Check to make sure file is opened    
                      if(!labels.is_open()){

                          throw alreadyClosed();
                      }



		      //Strip the non-Label Data at beginning of labels input
		      labels.seekg(8);


		      //print
	              char iterator;
                      while(labels >> iterator){
                   
	              std::cout << (int)iterator << ' ';       
                   
		      }
	       
	       }



	       /*
		* 
		* 
		* Function Which Returns  
		*
		* One Label From Any Index
		*
		* of the Labels Data
		*
		*
		*
		* */

                int getLabel(int labelIndex){

                    //Check to make sure file is opened    
                    if(!labels.is_open()){

                        throw alreadyClosed();
                     }


		    char label; 
                    labels.seekg(labelIndex);
		    
		    labels >> label;             
 

                  return (int)label;
		
		}




};





int main(){


	Labels myLabels;

        myLabels.open();


	for(int i = 8; i < 192; i++){

	    std::cout << myLabels.getLabel(i) << ' ';

	}


       



	
	

        //myLabels.printLabels();


        

	myLabels.close();

        
	

         
}






