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


    public:
	    void testTable(){
	    
		    cout << "testing input table class " << '\n';
	    
	    }



};





int main()
{


ofstream file;
file.open("rawMnistData/train-labels-idx1-ubyte");
file.close();

network net;
net.testNetwork();

inputTable input;
input.testTable();


return 0;
}
