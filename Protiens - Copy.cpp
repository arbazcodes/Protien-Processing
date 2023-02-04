#include<iostream>
#include<fstream>
#include <stdlib.h>
#include<math.h>
using namespace std;

struct Neighbour{
	
	string name;
	float weight;
	Neighbour *next;
};

struct AdjListNode{
	
	string name;
	float x,y;
	double degree;
	AdjListNode *next;
	Neighbour *neighbour;
	
};



class Graph{
	
	private:
		
		AdjListNode *head;
		float radius, theta;
		int vertices;
		
	public:
		
		Graph(){
			
			head = NULL;
			vertices =  theta = 0;
			radius = 1;
		}
		
		void Insert_Vertex(string s){
			
			AdjListNode *newNode = new AdjListNode;
			newNode->name = s;
			newNode->next = NULL;
			newNode->degree = 0;
			newNode->x = 960+radius*cos(theta);
			newNode->y = 540+radius*sin(theta);
			newNode->neighbour = NULL;
			
			
			AdjListNode *temp = head;
			
			if(temp == NULL){
				
				head = newNode;
				vertices++;
				
			}else{
				
				while(temp != NULL){
					
					if(temp->name == s){
						
						return;
						
					}
					
					temp = temp->next;
					
				}
				
				temp = head;
				
				while(temp->next != NULL){
					
					temp = temp->next;
					
				}
				
				temp->next = newNode;
				vertices++;
			}
				
		}
		
		void Insert_Edge(string s1, string s2, float weight){
			
			AdjListNode *temp = head;
			
			while(temp->name != s1 && temp != NULL){
				
				temp = temp->next;
				
			}
			
			Neighbour *newNeighbour = new Neighbour;
			newNeighbour->name = s2;
			newNeighbour->weight = weight;
			
			
			if(temp->degree == 0){
				
				newNeighbour->next = NULL;
				temp->neighbour = newNeighbour;
				temp->degree++;
				
			}else{
				
				newNeighbour->next = temp->neighbour;
				temp->neighbour = newNeighbour;
				temp->degree++;
			}
				
		}
		
		void DegreeofNode(string s){
			
			AdjListNode *temp = head;
			
			while(temp->name != s && temp != NULL){
				
				temp = temp->next;
				
			}
			
			if(temp == NULL){
				
				cout<<endl<<endl<<"Node not found in the graph."<<endl;
				
			}else{
				
				cout<<endl<<endl<<"Degrre of "<<s<<" is: "<<temp->degree<<endl;
				
			}
			
		}
		
		
		void FindMaxDegree(){
			
			AdjListNode *temp = head;
			AdjListNode *maxnode = temp;
			double max = temp->degree;
			
			while(temp != NULL){
				
				if(temp->degree > max){
					
					max = temp->degree;	
					maxnode = temp;
				}
				
				temp = temp->next;
					
			}
			
			cout<<endl<<endl<<"Max degree is of node "<<maxnode->name<<" = "<<max<<endl;	
			
		}
		
		void FindMinDegree(){
			
			AdjListNode *temp = head;
			AdjListNode *minnode = temp;
			double min = temp->degree;
			
			while(temp != NULL){
				
				if(temp->degree < min){
					
					min = temp->degree;		
					minnode = temp;					
				}
				
				temp = temp->next;
					
			}
			
			cout<<endl<<endl<<"Min degree is of node "<<minnode->name<<" = "<<min<<endl;	
			
		}
		
		void Display(){
			
			AdjListNode *temp = head;
			
			while(temp != NULL){
				
				Neighbour *temp2 = temp->neighbour;
				
				cout<<temp->name<<": ";
				
				while(temp2 != NULL){
					
					cout<<temp2->name<<"  ";
					temp2 = temp2->next;
					
				}
				
				cout<<endl;
				
				temp = temp->next;
			}
			
		}
		
		
		void FindNeighbours(string s){
			
			AdjListNode *temp = head;
			
			while(temp->name != s && temp != NULL){
				
				temp = temp->next;
				
			}
			
			if(temp == NULL){
				
				cout<<endl<<endl<<"Node not found in the graph."<<endl;
				
			}else{
			
				Neighbour *temp2 = temp->neighbour;
				
				if(temp2 == NULL){
					
					cout<<endl<<endl<<s<<" This node does not have any neighbours."<<endl;
					
				}else{
					
					cout<<endl<<endl<<"Neighbours of "<<s<<" are: ";
					
					while(temp2 != NULL){
					
						cout<<temp2->name<<"  ";	
					   temp2 = temp2->next;
					   
					}	
					
					cout<<endl;
				}
		
			}
			
			
		}
	
};

int main(){
	
	Graph g;
	
	ifstream theFile("PPI-I.txt");
	
	string p1, p2;
	float weight;
		
	while(theFile >> p1 >> p2 >> weight){
		
		g.Insert_Vertex(p1);
		g.Insert_Vertex(p2);
		g.Insert_Edge(p1,p2,weight);
			
	}
	
	g.Display();
	g.DegreeofNode("TFC3");
	g.FindMaxDegree();
	g.FindMinDegree();
	g.FindNeighbours("TFC3");
	
	return 0;
}
