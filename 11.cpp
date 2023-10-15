/******************************************************************************
Implement copy constructor(use deep copy), assignment operator and parameterized
constructor for below class.
Class Test{

Public:

    int modelNumber;
    char *modelName;
    static int chasisNumber;
    const int engineNumber;

};
*******************************************************************************/
#include <iostream>
#include <string.h>

using namespace std;

class Test{
    
    public:
        
        int modelNumber;
        char *modelName;
        static int chasisNumber;
        const int engineNumber=0;
        
        //Default Constructor
        Test()
        {
            cout<<"Constructor Called"<<endl;
            modelNumber = 0;
            modelName = NULL;
            chasisNumber = 0;
            
        }
        //Parameterized Constructor
        Test(int model,const char *p,int chasis,int engine):engineNumber(engine)
        {
            cout<<"Parameterized Constructor Called"<<endl;
            modelNumber=model;
            chasisNumber=chasis;
            // engineNumber=engine;//assignment of read only member
            
            modelName = new char[strlen(p)+1];
            strcpy(modelName,p);
            
        }
        //Deep Copy Constructor
        Test (Test & t):engineNumber(t.engineNumber)
        {
            cout<<"Deep Copy Constructor Called"<<endl;
            modelNumber=t.modelNumber;
            chasisNumber=t.chasisNumber;
            // engineNumber=t.engineNumber;//assignment of read only member
            // modelName=t.modelName;
            
            modelName=new char[strlen(t.modelName)+1];
            strcpy(modelName,t.modelName);
        }
        //Assignment operator
        Test & operator =(const Test &t)
        {
            modelNumber=t.modelNumber;
            chasisNumber=t.chasisNumber;
            
            // modelName=t.modelName;
            
            delete[] modelName;
            modelName=new char[strlen(t.modelName)+1];
            strcpy(modelName,t.modelName);
            
            return *this;
        }
        void display()
        {
            cout<<"****************************"<<endl;
    	    cout<<"Model Number: "<<modelNumber<<endl;
            cout<<"Model Name: "<<modelName<<endl;
            cout<<"Chasis Number: "<<chasisNumber<<endl;
            cout<<"Engine Number: "<<engineNumber<<endl;
	    cout<<"****************************"<<endl;    
        }
        ~Test()
        {
            cout<<"Destructor Called"<<endl;
            delete[] modelName;
        }
        
};

int Test::chasisNumber=0;

int main()
{
    // Test t;
    // t.display();
    
    Test t1(1,"abc",1,1001);
    t1.display();
    Test t2 = t1;  // Copy constructor
    t2.display();
    
    Test t3(2,"xyz",2,1002);
    t3 = t1;      // Assignment operator
    
    t2.display();
    t3.display();
    return 0;
}

