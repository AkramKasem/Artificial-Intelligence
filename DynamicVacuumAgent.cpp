#include <iostream>
#include <vector>




using namespace std;



enum Status {Clean, Dirty};

enum Action {Nothing, MoveLeft, MoveRight, Suck};



class Environment{

private:
    vector<int> environmentLocations;
    int numberOfLocations ;

public:
    Environment(int n){
        environmentLocations.resize(n);
        numberOfLocations = n;
        SetEnvironment();
    }


    void SetEnvironment() {

        cout<<endl<<endl<<endl ;

        cout<<"\t\t <<  Environment Setting 'Create new Environment' >>"<<endl<<endl ;
        int random ;
        for(int i = 0 ; i < numberOfLocations ; i++){
            random = rand()%10 ;

            if(random < 5){
                environmentLocations[i] = Clean ;
            }else{
                environmentLocations[i] = Dirty ;
            }
        }
    }


    int getStatusCurrentLocation(int location){
        return environmentLocations[location];
    }


    void setStatusCurrentLocation(int location, int status){
        environmentLocations[location] = status;
    }


    void DisplayStatus(int agentLocation){


        cout<<" ....Environment Status....." <<endl ;

        for(int i = 0 ; i < numberOfLocations ; i++){
            if(getStatusCurrentLocation(i) == Dirty)
            {
            cout <<" Status of location "<< i+1 <<" is : Dirty "  <<endl ;
            }
            else
            {
            cout <<" Status of location "<< i+1 <<" is : Clean" <<endl ;
            }
        }
        cout<<"Vacuum in location  " << agentLocation <<endl ;
    }


};




class Agent {

private:
    int numberOfLocations ;

public:
    Agent(int n){
        numberOfLocations = n ;
    }

    int VacuumAction(int location, int status)
    {
        if (status == Dirty){
            return Suck ;
        }
        else if (location == 0){
            return MoveRight ;
        }
        else if (location == (numberOfLocations-1))
        {
            return MoveLeft ;
        }else{
            int random = rand()%2 ;
            if(random == 1){
                return MoveRight ;
            }else{
                return MoveRight ;
            }
        }
    }


};



int main()
{
    cout << endl << endl << endl <<"\t\t\t AI Vacuum Agent Algorithm    " << endl<< endl<< endl;


    int numberOfLocations ;
    cout << "Enter number of locations : ";
    cin >>numberOfLocations;

    Environment E(numberOfLocations) ;
    Agent a(numberOfLocations) ;

    int agentAction , currentLocation = 0 ;

    for(int i = 0 ; i < 20 ; i++)
    {
        E.DisplayStatus(currentLocation);
        bool flag = true ;
        for(int i = 0 ; i < numberOfLocations ; i++){
            if(E.getStatusCurrentLocation(i) == Clean){
                flag = false ;
            }else{
                flag = true ;
            }
        }

        if(flag == false)
        {
            agentAction = Nothing ;
            cout<<"Next Action " << agentAction <<endl ;
            E.SetEnvironment();
        }
        else
        {
            agentAction = a.VacuumAction(currentLocation,E.getStatusCurrentLocation(currentLocation));
            if(agentAction == Suck)
            {
                cout<<"Next Action : Suck"  <<endl ;
                E.setStatusCurrentLocation(currentLocation,Clean);
            }
            else if(agentAction == MoveRight)
            {
                cout<<"Next Action : MoveRight"  <<endl ;
                currentLocation++ ;
            }
            else
            {
                cout<<"Next Action : MoveLeft"  <<endl ;
                currentLocation--;
            }
        }
        _sleep(1500);
        cout<<endl<<endl<<endl ;
    }

    system("Pause");
    return 0;
}
