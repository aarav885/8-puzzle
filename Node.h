#ifndef __Node_h__
#define __Node_h__
#include <iostream>
#include<cmath>
using namespace std;
class Node{
  public:
    //state represents the current arrangement of the puzzle
    int state[9];
    //goal state for comparison 
    int goal[9] = {1,2,3,4,5,6,7,8,0};
    //cost to get to the current state
    int cost; 
    //position of the 0/* in the current state
    int position;
    //the depth of the current state
    int depth = 0;
    //pointer to the parent Node
    Node* parent;
    Node(){}
    //default constructor that sets the state equal to the current puzzles state
    Node(int c_state[9]){
        for(int i =0; i < 9; i++){
            state[i] = c_state[i];
        }
        parent = nullptr;   
    }
    //sets the parent node and increases the depth 
    void setParent(Node* n, Node* p){
        n->parent = p;
        n->depth = p->depth + 1;
    }
    //for the trace
    void printState(){
        for(int i = 0; i < 9; i++){
            if(((i+1)%3) == 0){
                cout << state[i] << endl;
            }
            else{cout << state[i] << " ";}
            }
        
    }
    //destructor
    ~Node(){
        if(parent){
            delete parent;
        }
        else {
            delete this;
        }
    }
    //finds the position of the 0 in the puzzle
    void findPosition(Node *t){
        for(int i =0; i < 9; i++){
            if(t->state[i]==0){
                position = i;
            }
        }
    }
    //goal test to see if the current state is the goal 
    bool isGoal(int arr[9]){
        for(int i =0; i <9; i++){
            if(arr[i] != goal[i]){
                return false;
            }
        }
        return true;
    }
    //heuristic for uniform cost search
    //cost is based on how many positions the 0/* can be moved 
    void getActions(Node* n){
        if(n->position == 0){
            n->cost += 2;
        }
        else if(n->position == 1){
            n->cost +=3;
        }
        else if(n->position == 2){
            n->cost +=2;
        }
        else if(n->position == 3){
            n->cost +=3;
        }
        else if(n->position == 4){
            n->cost +=4;
        }
        else if(n->position == 5){
            n->cost +=3;
        }
        else if(n->position == 6){
            n->cost +=2;
        }
        else if(n->position == 7){
            n->cost +=3;
        }
        else if(n->position == 8){
            n->cost +=2;
        }
    }
    //heuristic for misplaced tiles
    //cost is determined by a comparison between the current
    //state and the goal state. Cost is increased for every tile
    //that is not in the correct position
    void misplaced_tiles(Node* n){
        int incorrect = 0;
        for(int i =0; i < 9; i++){
            if(n->state[i]!=goal[i]){
                ++incorrect;
            }
        }
        n->cost +=incorrect;
    }
    //heuristic for euclidean distance
    //cost is determined by the distance of each tile from its
    //position in the goal state 
    void euclidean(Node* n){
        int distance = 0;
        if(n->state[0] != 1){
            for(int i = 0; i < 9; i++){
                if(n->state[i] == 1){
                    distance = distance+(i+1);
                    distance = distance - 0;
                    break;
                }
            }
        }
        if(n->state[1] != 2){
            for(int i = 0; i < 9; i++){
                if(n->state[i] == 2){
                    distance = distance+(i +1);
                    distance = distance - 1;
                    break;
                }
            }
        }
        if(n->state[2] != 3){
            for(int i = 0; i < 9; i++){
                if(n->state[i] == 3){
                    distance = distance+(i +1);
                    distance = distance - 2;
                    break;
                }
            }
        }
        if(n->state[3] != 4){
            for(int i = 0; i < 9; i++){
                if(n->state[i] == 4){
                    distance = distance+(i +1);
                    distance = distance - 3;
                    break;
                }
            }
        }
        if(n->state[4] != 5){
            for(int i = 0; i < 9; i++){
                if(n->state[i] == 5){
                    distance = distance+(i +1);
                    distance = distance - 4;
                    break;
                }
            }
        }
        if(n->state[5] != 6){
            for(int i = 0; i < 9; i++){
                if(n->state[i] == 6){
                    distance = distance+(i +1);
                    distance = distance - 5;
                    break;
                }
            }
        }
        if(n->state[6] != 7){
            for(int i = 0; i < 9; i++){
                if(n->state[i] == 7){
                    distance = distance+(i +1);
                    distance = distance - 6;
                    break;
                }
            }
        }
        if(n->state[7] != 8){
            for(int i = 0; i < 9; i++){
                if(n->state[i] == 8){
                    distance = distance+(i +1);
                    distance = distance - 7;
                    break;
                }
            }
        }
        if(n->state[8] != 0){
            for(int i = 0; i < 9; i++){
                if(n->state[i] == 0){
                    distance = distance+(i +1);
                    distance = distance - 8;
                    break;
                }
            }
        }
        n->cost += distance;

    }
    //heuristic function that does not work 
    
    // void euclidean2(Node* n){
    //     int distance = 0;
    //     if(n->state[0] != 1){
    //         for(int i = 0; i < 9; i++){
    //             if(n->state[i] == 1){
    //                 distance = i;
    //                 break;
    //             }
    //         }
    //         n->cost = sqrt(pow(distance-0,2));
    //     }
    //     if(n->state[1] != 2){
    //         for(int i = 0; i < 9; i++){
    //             if(n->state[i] == 2){
    //                 distance = i;
    //                 break;
    //             }
    //         }
    //         n->cost = sqrt(pow(distance-1,2));
    //     }
    //     if(n->state[2] != 3){
    //         for(int i = 0; i < 9; i++){
    //             if(n->state[i] == 3){
    //                 distance = i;
    //                 break;
    //             }
    //         }
    //         n->cost = sqrt(pow(distance-2,2));
    //     }
    //     if(n->state[3] != 4){
    //         for(int i = 0; i < 9; i++){
    //             if(n->state[i] == 4){
    //                 distance = i;
    //                 break;
    //             }
    //         }
    //         n->cost = sqrt(pow(distance-3,2));
    //     }
    //     if(n->state[4] != 5){
    //         for(int i = 0; i < 9; i++){
    //             if(n->state[i] == 5){
    //                 distance = i;
    //                 break;
    //             }
    //         }
    //         n->cost = sqrt(pow(distance-4,2));
    //     }
    //     if(n->state[5] != 6){
    //         for(int i = 0; i < 9; i++){
    //             if(n->state[i] == 6){
    //                 distance = i;
    //                 break;
    //             }
    //         }
    //         n->cost = sqrt(pow(distance-5,2));
    //     }
    //     if(n->state[6] != 7){
    //         for(int i = 0; i < 9; i++){
    //             if(n->state[i] == 7){
    //                 distance = i;
    //                 break;
    //             }
    //         }
    //         n->cost = sqrt(pow(distance-6,2));
    //     }
    //     if(n->state[7] != 8){
    //         for(int i = 0; i < 9; i++){
    //             if(n->state[i] == 8){
    //                 distance = i;
    //                 break;
    //             }
    //         }
    //         n->cost = sqrt(pow(distance-7,2));
    //     }
    //     if(n->state[8] != 0){
    //         for(int i = 0; i < 9; i++){
    //             if(n->state[i] == 0){
    //                 distance = i;
    //                 break;
    //             }
    //         }
    //         n->cost = sqrt(pow(distance-8,2));
    //     }
        

    // }



};

//custom compartor class in order to implement the min heap priority queue
//This is needed in order to make a priority queue of a custom class type
class myComparator{
    public:
        int operator()(const Node* n1, const Node* n2){
            return n1->cost > n2->cost;
        }
};


#endif