#include <iostream>

#include <stack>
#include <vector>


using namespace std;

int initialstate , goalState , numOfEdge , from , to , depth[10000];
bool visited [10000];
stack<int> openList ;
vector<int> stateSpaceGraph[10000] ;//adj
vector<int> closeList ;



// Make State Space Graph
// كل العمليات اللى عملتها  يعنى كل الحالات اللى عملتها من اول حاله
void StateSpaceGraph (){
    cout << "Enter number of Edges : " ;
    cin  >> numOfEdge ;

    cout << "Enter  Edges : ";
    for(int i= 0 ; i < numOfEdge ; i++){

        cin  >> from >> to ;
        stateSpaceGraph[from].push_back(to);
    }

}

// Make DFS Algorithm
// ازاى بشوف كل حاله وادور على النهايه
void DFS(int start){

    openList.push(start);
    depth[start] = 0;
    visited[start] = true ;

    while( !openList.empty() ){

        int currentState = openList.top();
        openList.pop();
        closeList.push_back(currentState);

        if ( currentState == goalState ){
            return ;
        }

        for(auto state : stateSpaceGraph[currentState]){
            DFS(state);
        }

    }
    return ;
}



void Display(){

    cout << " the path is => " ;
    for(int i= 0 ; i < closeList.size() ; i++){

            cout << closeList[i] << "   " ;

    }

    cout << endl << "the goal in level number  " << depth[goalState] <<endl ;
}




int main()
{
    cout << endl << endl << endl <<"\t\t\t AI DFS Algorithm    " << endl<< endl<< endl;

    StateSpaceGraph ();
    cout << "Enter initial State : " ;
    cin >> initialstate ;
    cout << "Enter goal State : " ;
    cin >> goalState ;
    DFS(initialstate);
    Display();

    return 0;
}
