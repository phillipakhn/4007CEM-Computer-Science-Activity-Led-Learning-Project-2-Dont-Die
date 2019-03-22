#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    
    const unsigned int sizeOfArray = 64;
    
    int firstArray[sizeOfArray];
    
    for (int a = 0; a<64; a++)
    {
        firstArray[a] = 0;
        cout << firstArray[a];
    }
    cout << endl;
    
    int middleArray[sizeOfArray];
    
    for (int j = 0; j<64; j++)
    {
        
        for (int i = 0; i<sizeOfArray; i++)
        {
            
            
            
            middleArray[i] = rand() % 4;
            middleArray[0] = 0;
            middleArray[63] = 0;
            cout << middleArray[i];
        }
        cout << endl;
    }
    
    int lastArray[sizeOfArray];
    
    for (int a = 0; a<64; a++)
    {
        lastArray[a] = 0;
        cout << lastArray[a];
    }
    cout << endl;
    
}


