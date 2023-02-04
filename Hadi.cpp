#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
using namespace std;

struct neighbors{
    string name;
    float weight;
    neighbors *next;
};

struct node{
    string n;
    int x, y, degree;
    neighbors *nb;
    node *next;
};

class AdjList{
    private:
    node *head;
    float t;
    float r;

    public:
    AdjList(){
        t = 0.01;
        r = 1;
        head = NULL;
    }
    
    void insertVertex(string name){
        node *newNode =new node;
        newNode->next = NULL;
        node *temp = head;

        while(temp != NULL){
            if(temp->n == name)
                return;
            temp = temp->next;
        }

        if(head == NULL){
            newNode->n = name;
            newNode->degree = 0;
            newNode->x = 960 + r*cos(t);
            newNode->y = 540 + r*sin(t);
            head = newNode;
            t += 0.01;
            return;
        }
        temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }
        newNode->n = name;
        newNode->degree = 0;
        newNode->x = 960 + r*cos(t);
        newNode->y = 540 + r*sin(t);
        temp->next = newNode;
        t +=0.01;
        return;
    }

    void insertEdge(string n1, string n2, float w){
        neighbors *newNeighbor = new neighbors;
        newNeighbor->name = n2;
        newNeighbor->weight = w;
        newNeighbor->next = NULL;

        node *temp = head;

        while(temp->n!=n1){
            temp = temp->next;
        }
        temp->degree++;
        if(temp->degree == 1){
            temp->nb = newNeighbor;
            return;
        }
        neighbors *temp2 = temp->nb;
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = newNeighbor;
        return;
    }

    int numOfNodes(){
        int count = 0;
        node *temp = head;
        while(temp != NULL){

            count++;
            temp = temp->next;
        }
        return count;
    }

    void highestDegree(){
        int highestDeg = head->degree;
        string highestName = head->n;
        node *temp = head;

        while(temp->next != NULL){
            if(highestDeg < temp->next->degree){
                highestDeg = temp->next->degree;
                highestName = temp->next->n;
            }
            temp = temp->next;
        }

        cout << "The node with the highest degree is: " << highestName << "\nand its degree is: " << highestDeg << endl;
    }

    void lowestDegree(){
        int lowestDeg = head->degree;
        string lowestName = head->n;
        node *temp = head;

        while(temp->next != NULL){
            if(lowestDeg > temp->next->degree){
                lowestDeg = temp->next->degree;
                lowestName = temp->next->n;
            }
            temp = temp->next;
        }

        cout << "The node with the highest degree is: " << lowestName << "\nand its degree is: " << lowestDeg << endl;
    }

    void displayList(){
        node *temp = head;

        while(temp != NULL){
            cout << temp->n <<": ";
            neighbors *temp2 = temp->nb;
            while(temp2 != NULL){
                cout << "-->" << temp2->name;
                temp2 = temp2->next;
            }
            cout << endl;
            temp = temp->next;
        }
    }
    void searchNode(string key){
        node *temp = head;
        while(temp != NULL){
            if(temp->n == key){
                neighbors *temp2 = temp->nb;
                cout << temp->n <<": ";
                while(temp2 != NULL){
                    cout <<"-->" << temp2->name;
                    temp2 = temp2->next;
                }
                return;
            }
            temp = temp->next;
        }
        cout <<"This node could not be found!\n";
    }

    void degreeOfNode(string key){
        node *temp = head;
        while(temp != NULL){
            if(temp->n == key){
                cout << "The degree of node " << temp->n << " is " << temp->degree << endl;
                return;
            }
            temp = temp->next;
        }
        cout <<"This node could not be found!\n";
    }
};


int main(){

    AdjList L;

    string col1, col2, line1, line2;
    double w;
    ifstream in("list.txt");
    while (getline(in, line1))
    {
        istringstream extraction(line1);
        extraction >> col1 >> col2 >> w;
        L.insertVertex(col1);
        L.insertVertex(col2);

    }
    
    in.clear();
    ifstream on("list.txt");
    while (getline(on, line2))
    {
        istringstream extraction(line2);
        extraction >> col1 >> col2 >> w;
        L.insertEdge(col1, col2, w);
        L.insertEdge(col2, col1, w);

    }
    
    L.displayList();

    cout << L.numOfNodes() << endl;
    L.highestDegree();
    L.lowestDegree();
    // L.displayList();

    L.searchNode("FUN30");
    return 0;
}
