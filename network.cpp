#include <iostream>
#include <fstream>


using namespace std;


class network
{


    public:


	    void testNetwork() {
	    
		    cout << "testing network class " << '\n';
	        
	    }
	

	

};





//Might make this a function instead of a class later
class inputTable
{

    private:
	    void openLabels(){

                int label;
	        
	        fstream file;
                file.open("rawMnistData/train-labels-idx1-ubyte");


		for(int i = 0; i < 3; i++){
                
		    file >> label;

		    cout << label << " THIS IS A LABEL " << '\n';

		}	

		/*int size = sizeof(int)*1;
		int* memblock = new int[size];
	       	
		file.read(memblock, size);*/	
		
		file.close();

	    }

	    

	    void openImages(){
	    
	        ofstream file;
                file.open("rawMnistData/train-images-idx3-ubyte");
                file.close();	    

	    
	    }


    public:
	    void testTable(){
	    
		    cout << "testing input table class " << '\n';
	    
	    }

	    
	    void getLabels(){
	    
		   openLabels(); 
	    
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
