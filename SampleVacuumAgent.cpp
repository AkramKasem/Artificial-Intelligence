#include <iostream>




using namespace std;

enum Location{A , B};

enum Status{Clean , Dirty};

enum Action{Nothing , MoveLeft , MoveRight , Suck};



class Environment{

private:
    int environmentLocations[2];
public:
    Environment(){
        SetEnvironment();
    }

    void SetEnvironment(){
        cout<<"\t\t <<  Environment Setting 'Create new Environment' >>"<<endl<<endl ;

        int random = rand()%10 ;
        if(random < 5){
            environmentLocations[A] = Clean ;
        }else{
            environmentLocations[A] = Dirty ;
        }

        random = rand()%10 ;
        if(random < 5){
            environmentLocations[B] = Clean ;
        }else{
            environmentLocations[B] = Dirty ;
        }

    }


    int getStatusCurrentLocation(int location){
        return environmentLocations[location];
    }


    void setStatusCurrentLocation(int location , int status){
        environmentLocations[location] = status;
    }


    void DisplayStatus(int agentLocation){
        cout<<" ....Environment Status....." <<endl ;

        if(getStatusCurrentLocation(A) == Dirty){
            cout <<" Status of location A is : " << Dirty <<endl ;
        }else{
            cout<<" Status of location A is : " << Clean <<endl ;
        }

        if(getStatusCurrentLocation(B) == Dirty){
            cout<<" Status of location B is : " << Dirty <<endl ;
        }else{
            cout<<" Status of location B is : " << Clean <<endl ;
        }

        if (agentLocation == A ){
            cout<<"Vacuum location is A " <<endl ;
        }else{
            cout<<"Vacuum location is A " <<endl ;
        }

    }


};




class Agent{

public:
    int VacuumAction(int location , int status){
        if (status == Dirty){
            return Suck ;
        }else if (location == A){
            return MoveRight ;
        }else {
            return MoveLeft ;
        }
    }


};



int main()
{
    cout << endl << endl << endl <<"\t\t\t AI Vacuum Agent Algorithm    " << endl<< endl<< endl;

        Environment E ;
        Agent a ;

        int agentAction , currentLocation = A ;

        for(int i = 0 ; i < 10 ; i++){
            E.DisplayStatus(currentLocation);
            if(E.getStatusCurrentLocation(A) == Clean && E.getStatusCurrentLocation(B) == Clean){
                agentAction = Nothing ;
                cout<<"Next Action " << agentAction <<endl ;
                E.SetEnvironment();
            }else{
                agentAction = a.VacuumAction(currentLocation,E.getStatusCurrentLocation(currentLocation));
                if(agentAction == Suck){
                    cout<<"Next Action : Suck"  <<endl ;
                    E.setStatusCurrentLocation(currentLocation,Clean);
                }else if(agentAction == MoveRight){
                    cout<<"Next Action : MoveRight"  <<endl ;
                    currentLocation = B ;
                }else {
                    cout<<"Next Action : MoveLeft"  <<endl ;
                    currentLocation = A;
                }
            }
            _sleep(1500);
            cout<<endl<<endl<<endl ;
        }

    system("Pause");
    return 0;
}
