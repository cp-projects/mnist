#include <iostream>
#include <fstream>
#include "fileIoError.hpp"

using namespace std;


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



		      //Strip the non-Label Data
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

	std::cout << "test" << '\n'; 



	
	

        //myLabels.printLabels();


        

	myLabels.close();

        
	

         
}






