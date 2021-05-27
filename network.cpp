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






//class for defining structure of the network and propagation
class network
{


    public:


	    void testNetwork() {
	    
		    cout << "testing network class " << '\n';
	        
	    }
	

	

};





//class for handling and preparing data batches
class inputFeed
{

    private:

	    /*
	     *
	     *  Method to open and read the labels file
	     *
	     *
	     *
	     * private method to openLabels to protect
	    original data source, takes args
	    n iterations (batch size) and an array
	    of size n to hold the batch
	    */
	    int openLabels(int iter, int* batch, int lastBatch)
            {
               

		//intitializes realized iteration tracker
		int i = 0;    
                
		//initializes container to read each label
		char label;

		

		//adjust to specify which batch we are using
		//i = lastBatch;
		//cout << '\n' << '\n';
		//cout << " i = " <<  lastBatch << '\n';
		iter += lastBatch;
		//cout << " iter = " <<  iter << '\n';



	        
		//opens labels file
	        ifstream labels;
		labels.open("rawMnistData/train-labels-idx1-ubyte", ios_base::in);


		//check if files is open
		if(!labels.is_open()){
		
		    //file did not open
		    throw failToOpen();			    	
		}
                


		  //iterates through labels file label-wise
		  while (labels >> label){
			  
			  
                    //handles cases of corrupted or misinterpreted label data
		    //(need to track index of currupted labels to remove corresponding images at some point)
		    if(label > 9 || label < 0) continue;

		    //breaks when batch size is reached
		    if(i == iter) break;

		    //cout << " Lable  " << (int)label << '\n';
		    
		    //adds labels batch array
		    batch[i] = label;
		    i++;

		}	

			
		//close files
		labels.close();

		//print batch
		cout << '\n' <<  "Batch " << iter << '\n';

		//prints batch array
		for(int i = lastBatch; i < iter; i++){
		
		    cout << batch[i] << ' ';

		}

		//cout << iter << '\n';
		return iter;
	    }



	    



	    /*
	     * Method to open and read image data
	     *
	     *
	     *
	     * */

	    void openImages(){
	   
		char label;

	        ifstream images;
                images.open("rawMnistData/train-images-idx3-ubyte");


                //check if files is open
                if(!images.is_open()){

                    //file did not open
                    throw failToOpen();
                }

	       
	
		while (images >> label){

                    cout << (int)label << endl;

                }

	
	
		images.close();	    

	    
	    }


	    /*
	     * Method for constructing syboltable
	     *
	     *
	     *
	     * */
	    void constructTable()
	    {
	    
	    
	    
	    
	    }


    public:
	    void testIOfeed(){
	    
                cout << "testing input table class " << '\n';
	    
	    }

	    
	    void getLabels(int batchSize, int numBatches){

		int oldBatchLocation = 0;
		int temp;
		for(int i = 0; i < numBatches; i++)
		{


		int batch[batchSize];   

	        //cout << i << ' ';	

	        temp = openLabels(batchSize, batch, oldBatchLocation);
	
		//cout << "old Batch Location  " << oldBatchLocation << '\n';
		oldBatchLocation = temp;
		//cout << "old Batch Location  " << oldBatchLocation << '\n';
	    
		}

		//oldBatchLocation = temp;
	    }

	    
	    void getImages(){
	    
	        openImages();
	    
	    }



	    

};





int main()
{


network net;
net.testNetwork();

inputFeed input;
input.testIOfeed();

input.getLabels(5, 50);


return 0;
}
