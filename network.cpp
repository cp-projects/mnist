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

                char label;
	        
	        ifstream file;
                file.open("rawMnistData/train-labels-idx1-ubyte");
                
		  while (file >> label){

		    cout << (int)label << endl;

		}	

			
		
		file.close();

	    }

	    

	    void openImages(){
	    
	        ifstream file;
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
