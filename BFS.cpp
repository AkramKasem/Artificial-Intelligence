#include <iostream>

#include <queue>
#include <vector>


using namespace std;

int initialstate , goalState , numOfEdge , from , to , depth[10000];
bool visited [10000];
queue<int> openList ;
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

// Make BFS Algorithm
// ازاى بشوف كل حاله وادور على النهايه
void BFS(int start){

    openList.push(start);
    depth[start] = 0;
    visited[start] = true ;

    while( !openList.empty() ){

        int currentState = openList.front();
        openList.pop();
        closeList.push_back(currentState);

        if ( currentState == goalState ){
            return ;
        }

        for(auto state : stateSpaceGraph[currentState]){
            if(visited[state]){
                continue ;
            }
            openList.push(state);
            visited[state] = true ;
            depth[state] = depth[currentState]+1;
        }

    }
    return ;
}



void Display(){

    cout << " the path is => " ;
    for(int i= 0 ; i < closeList.size() ; i++){

            cout << closeList[i] << "   " ;

    }

    cout <<endl << "the goal in level number  " << depth[goalState] <<endl ;
}




int main()
{
    cout << endl << endl << endl <<"\t\t\t AI BFS Algorithm    " << endl<< endl<< endl;

    StateSpaceGraph ();
    cout << "Enter initial State : " ;
    cin >> initialstate ;
    cout << "Enter goal State : " ;
    cin >> goalState ;
    BFS(initialstate);
    Display();

    return 0;
}
