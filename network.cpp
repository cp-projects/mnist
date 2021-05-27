#include <iostream>
#include <fstream>


using namespace std;


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
	    void openLabels(int iter, int* batch, int batchNumber)
            {
               

		//intitializes realized iteration tracker
		int i = 0;    
                
		//initializes container to read each label
		char label;




	        
		//opens labels file
	        ifstream labels;
                labels.open("rawMnistData/train-labels-idx1-ubyte");
                
		  //iterates through labels file label-wise
		  while (labels >> label){
			  
			  
                    //handles cases of corrupted or misinterpreted label data
		    //(need to track index of currupted labels to remove corresponding images at some point)
		    if((int)label > 9 || (int)label < 0) continue;

		    //breaks when batch size is reached
		    if(i == iter) break;
		    
		    //adds labels batch array
		    batch[i] = (int)label;
		    i++;

		}	

			
		//close files
		labels.close();

		//prints batch array
		for(int i = 0; i < iter; i++){
		
		    cout << batch[i] << ' ';

		}

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

	    
	    void getLabels(int batchSize){     

		int batch[batchSize];    

	        openLabels(batchSize, batch, 29); 
	    
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

input.getLabels(30);


return 0;
}
