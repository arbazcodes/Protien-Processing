#include<iostream>
#include<fstream>
using namespace std;

int index(string s, string buffer[]){
	
	int i = 0;
	
	while(s != buffer[i]){
		
		i++;
		
	}
	
	
	return i;
}

int main(){
	
	ifstream theFile("list.txt");
	
	string protien_1, protien_2,prev=" ";
	float weight;
	int count = 0;

		
	while(theFile >> protien_1 >> protien_2 >> weight){
		
		if(prev != protien_1){
			
			count++;
			
		}
		prev = protien_1;
			
			
	}
		
	cout<<count<<endl<<endl;

	string buffer[count];
	
	theFile.close();
	theFile.open("list.txt");
	prev = " ";
	int u = 0;
	
	while(theFile >> protien_1 >> protien_2 >> weight){
		
		
		if(prev != protien_1){
			
			buffer[u] = protien_1;
			//cout<<buffer[u]<<endl;
			u++;
			
		}
			
		prev = protien_1;	
			
	}
	
	float Matrix[count][count];
	
	int a = 0;
	
	while(a<count){
		
		int b = 0;
		
		while(b<count){
			
			Matrix[a][b] = 0;
			b++; 
			
		}
		
		cout<<endl;
		a++;	
			
	}
	
	theFile.close();
	theFile.open("list.txt");
	prev = " ";
	int i = 0;
	
	while(theFile >> protien_1 >> protien_2 >> weight){
		
			
		Matrix[index(protien_1,buffer)][index(protien_2,buffer)] = weight;
		Matrix[index(protien_2,buffer)][index(protien_1,buffer)] = weight;
			
	}
	
	theFile.close();
	theFile.open("list.txt");
	prev = " ";
	int x = 0, y = 0;
	
	while(x<count){
		
		int y = 0;
		
		while(y<count){
			
			cout<<Matrix[x][y]<<"	";
			y++; 
			
		}
		
		cout<<endl;
		x++;	
			
	}
	
	return 0;
}
