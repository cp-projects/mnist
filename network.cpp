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
class inputTable
{

    private:

	    
	    void openLabels(int iter, int* batch)
            {
               

		int i = 0;    
                char label;
	        
	        ifstream labels;
                labels.open("rawMnistData/train-labels-idx1-ubyte");
                
		  while (labels >> label){

		    if((int)label > 9 || (int)label < 0) continue;

		    
		    if(i == iter) break;  
		    cout << (int)label << endl;
		    i++;

		}	

			
		
		labels.close();

	    }

	    

	    void openImages(){
	   
		char label;

	        ifstream images;
                images.open("rawMnistData/train-images-idx3-ubyte");
               
	       
	
		while (images >> label){

                    cout << (int)label << endl;

                }

	
	
		images.close();	    

	    
	    }


    public:
	    void testTable(){
	    
                cout << "testing input table class " << '\n';
	    
	    }

	    
	    void getLabels(){
	   

		int batch[10];    

	        openLabels(10, batch); 
	    
	    }

	    
	    void getImages(){
	    
	        openImages();
	    
	    }

};





int main()
{


network net;
net.testNetwork();

inputTable input;
input.testTable();

input.getLabels();


return 0;
}
