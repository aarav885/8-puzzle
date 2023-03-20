#include "Node.h"
#include <queue>
#include <set>
using namespace std;

//Copys the current state into another array so that we can move the zero without
//altering the parent state
void copyState(int arr[9], Node* t){
    for(int i =0; i <9;i++){
        arr[i] = t->state[i];
    }
}
//to search if the current node is in the frontier 
bool searchQ(priority_queue<Node*, vector<Node*>, myComparator>q, Node *n){
    for(int i = 0; i < q.size(); i++){
        if(n == q.top()){
            return true;
        }
        else{
            q.pop();
        }
    }
    return false;
}
//to search if a node is in the explored set.
bool searchSet(set<Node*>s, Node* n){
    set<Node*>::iterator itr;
    for(itr = s.begin(); itr != s.end(); itr++){
        if(n == *itr){
            return true;
        }
    }
    return false;
}
//All 3 algorithms follow the same overall structure of the graph serach 
//pseudo code that was provided in the reading materials. The only difference
//between them lies in the heuristics functions, which are all implemented within
//the node class itself
//uniform cost search 
void uniform(int state[9]){
    //initialize parent state and set the Node's state with the entered puzzle
    Node* n = new Node(state);
    int amount_expnaded = 0;
    int size_of_frontier = 0;
    n->cost = 0;
    cout << "\nUniform Cost Search\n";
    //initialize the frontier and explored set with the current Node
    priority_queue<Node*, vector<Node*>,myComparator> frontier;
    frontier.push(n);
    set<Node*> explored;
    while(!frontier.empty()){
        //if the frontier is empty no possible path exists 
        if(frontier.empty()){
            cout << "No possible path\n";
            return;
        }
        //set the current state to the top of the frontier 
        Node* current_state = frontier.top();
        if(frontier.size() > size_of_frontier){
            size_of_frontier = frontier.size();
        } 
        frontier.pop();
        //to check for the goal state 
        if(current_state->isGoal(current_state->state)){
            current_state->printState();
            cout << "\nGoal\nThe amount of expanded nodes was: "<<amount_expnaded << endl;
            cout << "The maximum size of the frontier at any given time was: " << size_of_frontier << endl;
            cout << "The depth of the solution was: "<<current_state->depth << "\n";
            return;
        }
        current_state->printState();
        cout << "\nExpanding\n";
        ++amount_expnaded;
        explored.insert(current_state);
        current_state->findPosition(current_state);
        current_state->getActions(current_state);
        //Evaluates the position for 0, and looks for the moves that can be made
        //with the given position of the zero. New nodes are created for every possible
        //move that the 0 can make, and is added to the priority queue with the same
        //cost since uniform cost search is an uninformed search 
        if(current_state->position == 0){
            int array1[9];
            int array2[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            array1[0] = array1[1];
            array1[1] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->getActions(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[0] = array2[3];
            array2[3] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->getActions(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
        }
        if(current_state->position == 1){
            int array1[9];
            int array2[9];
            int array3[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            array1[1] = array1[0];
            array1[0] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->getActions(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[1] = array2[2];
            array2[2] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->getActions(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[1] = array3[3];
            array3[3] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->getActions(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
        }
        if(current_state->position == 2){
            int array1[9];
            int array2[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            array1[2] = array1[1];
            array1[1] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->getActions(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[2] = array2[5];
            array2[5] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->getActions(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
        }
        if(current_state->position == 3){
            int array1[9];
            int array2[9];
            int array3[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            array1[3] = array1[0];
            array1[0] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->getActions(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[3] = array2[4];
            array2[4] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->getActions(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[3] = array3[6];
            array3[6] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->getActions(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
        }
        if(current_state->position ==4){
            int array1[9];
            int array2[9];
            int array3[9];
            int array4[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            copyState(array4,current_state);
            array1[4] = array1[1];
            array1[1] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->getActions(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[4] = array2[3];
            array2[3] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->getActions(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[4] = array3[5];
            array3[5] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->getActions(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
            array4[4] = array4[7];
            array4[7] = 0;
            Node* child4 = new Node(array4);
            child4->setParent(child4, current_state);
            child4->cost += current_state->cost;
            child4->getActions(child4);
            if((!searchQ(frontier,child4)) && (!searchSet(explored,child4))){
                frontier.push(child4);
                
            }
        }
        if(current_state->position == 5){
            int array1[9];
            int array2[9];
            int array3[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            array1[5] = array1[2];
            array1[2] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->getActions(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[5] = array2[4];
            array2[4] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->getActions(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[5] = array3[8];
            array3[8] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->getActions(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
        }
        if(current_state->position ==6){
            int array1[9];
            int array2[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            array1[6] = array1[3];
            array1[3] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->getActions(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[6] = array2[7];
            array2[7] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->getActions(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
        }
        if(current_state->position == 7){
            int array1[9];
            int array2[9];
            int array3[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            array1[7] = array1[4];
            array1[4] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->getActions(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[7] = array2[6];
            array2[6] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->getActions(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[7] = array3[8];
            array3[8] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->getActions(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
        }
        if(current_state->position == 8){
            int array1[9];
            int array2[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            array1[8] = array1[5];
            array1[5] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->getActions(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[8] = array2[7];
            array2[7] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->getActions(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
        }

    }
}

//A* Search with the misplaced tiles
void A_Misplaced(int state[9]){
    Node* n = new Node(state);
    n->cost = 0;
    int amount_expanded = 0;
    int size_of_frontier = 0;
    cout <<"\nA* Search with Misplaced Tiles\n";
    priority_queue<Node*, vector<Node*>,myComparator> frontier;
    frontier.push(n);
    set<Node*> explored;
    while(!frontier.empty()){
        if(frontier.empty()){
            cout << "No possible path\n";
            return;
        }
        Node* current_state = frontier.top();
        if(frontier.size() > size_of_frontier){
            size_of_frontier = frontier.size();
        } 
        frontier.pop();
        if(current_state->isGoal(current_state->state)){
            current_state->printState();
            cout << "\nGoal\nThe amount of expanded nodes was: "<<amount_expanded << endl;
            cout << "The maximum size of the frontier at any given time was: " << size_of_frontier <<endl;
            cout << "The depth of the solution was: "<<current_state->depth << "\n";
            return;
        }
        current_state->printState();
        cout << "\nExpanding\n";
        ++amount_expanded;
        explored.insert(current_state);
        current_state->findPosition(current_state);
        current_state->misplaced_tiles(current_state);
        //Like mentioned above, the algorithms follow the same overall structure with
        //the difference lying in the heuristics functions. In the misplaced tiles case
        //the nodes are inserted in the priority queue by the amount of tiles that are
        //misplaced, which is calculted in the Node class. 
        if(current_state->position == 0){
            int array1[9];
            int array2[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            array1[0] = array1[1];
            array1[1] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->misplaced_tiles(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[0] = array2[3];
            array2[3] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->misplaced_tiles(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
        }
        if(current_state->position == 1){
            int array1[9];
            int array2[9];
            int array3[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            array1[1] = array1[0];
            array1[0] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->misplaced_tiles(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[1] = array2[2];
            array2[2] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->misplaced_tiles(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[1] = array3[3];
            array3[3] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->misplaced_tiles(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
        }
        if(current_state->position == 2){
            int array1[9];
            int array2[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            array1[2] = array1[1];
            array1[1] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->misplaced_tiles(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[2] = array2[5];
            array2[5] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->misplaced_tiles(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
        }
        if(current_state->position == 3){
            int array1[9];
            int array2[9];
            int array3[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            array1[3] = array1[0];
            array1[0] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->misplaced_tiles(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[3] = array2[4];
            array2[4] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->misplaced_tiles(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[3] = array3[6];
            array3[6] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->misplaced_tiles(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
        }
        if(current_state->position ==4){
            int array1[9];
            int array2[9];
            int array3[9];
            int array4[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            copyState(array4,current_state);
            array1[4] = array1[1];
            array1[1] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->misplaced_tiles(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[4] = array2[3];
            array2[3] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->misplaced_tiles(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[4] = array3[5];
            array3[5] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->misplaced_tiles(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
            array4[4] = array4[7];
            array4[7] = 0;
            Node* child4 = new Node(array4);
            child4->setParent(child4, current_state);
            child4->cost += current_state->cost;
            child4->misplaced_tiles(child4);
            if((!searchQ(frontier,child4)) && (!searchSet(explored,child4))){
                frontier.push(child4);
                
            }
        }
        if(current_state->position == 5){
            int array1[9];
            int array2[9];
            int array3[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            array1[5] = array1[2];
            array1[2] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->misplaced_tiles(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[5] = array2[4];
            array2[4] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->misplaced_tiles(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[5] = array3[8];
            array3[8] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->misplaced_tiles(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
        }
        if(current_state->position ==6){
            int array1[9];
            int array2[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            array1[6] = array1[3];
            array1[3] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->misplaced_tiles(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[6] = array2[7];
            array2[7] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->misplaced_tiles(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
        }
        if(current_state->position == 7){
            int array1[9];
            int array2[9];
            int array3[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            array1[7] = array1[4];
            array1[4] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->misplaced_tiles(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[7] = array2[6];
            array2[6] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->misplaced_tiles(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[7] = array3[8];
            array3[8] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->misplaced_tiles(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
        }
        if(current_state->position == 8){
            int array1[9];
            int array2[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            array1[8] = array1[5];
            array1[5] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->misplaced_tiles(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[8] = array2[7];
            array2[7] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->misplaced_tiles(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
            }
        }
    }

}

//A* search with euclidean distance
void A_Euclidean(int state[9]){
    Node* n = new Node(state);
    n->cost = 0;
    int amount_expanded = 0;
    int size_of_frontier = 0;
    cout << "\nA* Search with Euclidean Distance\n";
    priority_queue<Node*, vector<Node*>,myComparator> frontier;
    frontier.push(n);
    set<Node*> explored;
    while(!frontier.empty()){
        if(frontier.empty()){
            cout << "No possible path\n";
            return;
        }
        Node* current_state = frontier.top();
        if(frontier.size() > size_of_frontier){
            size_of_frontier = frontier.size();
        } 
        frontier.pop();
        if(current_state->isGoal(current_state->state)){
            current_state->printState();
            cout << "\nGoal\nThe amount of expanded nodes was: "<<amount_expanded<<endl;
            cout << "The maximum size of the frontier at any given time was: "<< size_of_frontier << endl;
            cout << "The depth of the solution was: "<<current_state->depth << "\n";
            return;
        }
        current_state->printState();
        cout << "\nExpanding\n";
        ++amount_expanded;
        explored.insert(current_state);
        current_state->findPosition(current_state);
        current_state->euclidean(current_state);
        //Nodes here are inserted into the priority queue based off 
        //of the position of each number from its actual destination spot 
        //in the goal state. The heuristic is again defined in the Node class
        if(current_state->position == 0){
            int array1[9];
            int array2[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            array1[0] = array1[1];
            array1[1] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->euclidean(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[0] = array2[3];
            array2[3] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->euclidean(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
        }
        if(current_state->position == 1){
            int array1[9];
            int array2[9];
            int array3[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            array1[1] = array1[0];
            array1[0] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->euclidean(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[1] = array2[2];
            array2[2] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->euclidean(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[1] = array3[3];
            array3[3] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->euclidean(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
        }
        if(current_state->position == 2){
            int array1[9];
            int array2[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            array1[2] = array1[1];
            array1[1] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->euclidean(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[2] = array2[5];
            array2[5] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->euclidean(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
        }
        if(current_state->position == 3){
            int array1[9];
            int array2[9];
            int array3[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            array1[3] = array1[0];
            array1[0] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->euclidean(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[3] = array2[4];
            array2[4] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->euclidean(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[3] = array3[6];
            array3[6] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->euclidean(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
        }
        if(current_state->position ==4){
            int array1[9];
            int array2[9];
            int array3[9];
            int array4[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            copyState(array4,current_state);
            array1[4] = array1[1];
            array1[1] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->euclidean(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[4] = array2[3];
            array2[3] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->euclidean(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[4] = array3[5];
            array3[5] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->euclidean(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
            array4[4] = array4[7];
            array4[7] = 0;
            Node* child4 = new Node(array4);
            child4->setParent(child4, current_state);
            child4->cost += current_state->cost;
            child4->euclidean(child4);
            if((!searchQ(frontier,child4)) && (!searchSet(explored,child4))){
                frontier.push(child4);
                
            }
        }
        if(current_state->position == 5){
            int array1[9];
            int array2[9];
            int array3[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            array1[5] = array1[2];
            array1[2] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->euclidean(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[5] = array2[4];
            array2[4] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->euclidean(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[5] = array3[8];
            array3[8] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->euclidean(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
        }
        if(current_state->position ==6){
            int array1[9];
            int array2[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            array1[6] = array1[3];
            array1[3] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->euclidean(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[6] = array2[7];
            array2[7] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->euclidean(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
        }
        if(current_state->position == 7){
            int array1[9];
            int array2[9];
            int array3[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            copyState(array3,current_state);
            array1[7] = array1[4];
            array1[4] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->euclidean(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[7] = array2[6];
            array2[6] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->euclidean(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
                
            }
            array3[7] = array3[8];
            array3[8] = 0;
            Node* child3 = new Node(array3);
            child3->setParent(child3,current_state);
            child3->cost += current_state->cost;
            child3->euclidean(child3);
            if((!searchQ(frontier,child3)) && (!searchSet(explored,child3))){
                frontier.push(child3);
                
            }
        }
        if(current_state->position == 8){
            int array1[9];
            int array2[9];
            copyState(array1,current_state);
            copyState(array2,current_state);
            array1[8] = array1[5];
            array1[5] = 0;
            Node* child1 = new Node(array1);
            child1->setParent(child1,current_state);
            child1->cost += current_state->cost;
            child1->euclidean(child1);
            if((!searchQ(frontier,child1)) && (!searchSet(explored,child1))){
                frontier.push(child1);
                
            }
            array2[8] = array2[7];
            array2[7] = 0;
            Node* child2 = new Node(array2);
            child2->setParent(child2,current_state);
            child2->cost += current_state->cost;
            child2->euclidean(child2);
            if((!searchQ(frontier,child2)) && (!searchSet(explored,child2))){
                frontier.push(child2);
            }
        }
    }    
}


int main(){
    cout << "Welcome to the 8 puzzle solver\n";
    cout << "Press 1 to use the default puzzle, Press 2 to use your own\n";
    int mode;
    cin >> mode;
    //default puzzle is the easy puzzle that was provided in the report guideline
    //document
    //int puzzle[9] = {1,2,3,4,5,6,7,8,0};
    // int puzzle[9] = {1,2,3,4,5,6,7,0,8};
    // int puzzle[9] = {1,2,0,4,5,3,7,8,6};
    // int puzzle[9] = {0,1,2,4,5,3,7,8,6};
     int puzzle[9] = {1,0,3,4,2,6,7,5,8};
    
    //in the case that a user wants to enter their own puzzle 
    if(mode == 2){
        cout << "Please Enter Your Own Numbers\n";
        int num;
        for(int i =0; i < 9; i++){
            cin >> num;
            puzzle[i] = num;
        }
    }
    cout << "Please Enter a number for which algorithm you would like to use\n";
    cout << "1: Uniform Cost Search\n2: A* with Misplaced Tiles\n3: A* with Euclidean Distance\n";
    int algo_num;
    cin >> algo_num;
    if(algo_num == 1){
        uniform(puzzle);
    }
    if(algo_num ==2){
        A_Misplaced(puzzle);
    }
    if(algo_num == 3){
        A_Euclidean(puzzle);
    }
    return 0;
}