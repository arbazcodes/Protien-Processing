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

bool search(string s, string buffer[], int c){
	
	for(int i=0; i < c; i++){
		
		if(s == buffer[i]){
			
			return true;
			break;
			
		}
		
	}
	
	return false;
	
}

int main(){
	
	ifstream theFile("list.txt");
	
	string protien_1, protien_2,prev=" ";
	float weight;
	int count = 0;

	//count number of unique elements in first column

		
	while(theFile >> protien_1 >> protien_2 >> weight){
		
		if(prev != protien_1){
			
			count++;
			
		}
		prev = protien_1;
			
			
	}
		
	cout<<count<<endl<<endl;

	string temp_buffer[count];
	
	//store first column in temp_buffer
	
	theFile.close();
	theFile.open("list.txt");
	prev = " ";
	int u = 0;
	
	while(theFile >> protien_1 >> protien_2 >> weight){
		
		
		if(prev != protien_1){

			temp_buffer[u] = protien_1;
			u++;
			
		}
			
		prev = protien_1;	
			
	}
	
	
	//count unique elements in second column
	
	int temp_count = count;
	
	theFile.close();
	theFile.open("list.txt");
	prev = " ";
	
	string temp_buffer2[count*10];
	
	for(int i = 0; i < count*10; i++){
		
		temp_buffer2[i] = "  ";
		
	}
	
	int j = 0;
	while(theFile >> protien_1 >> protien_2 >> weight){
		
		if(!search(protien_2, temp_buffer, count) && !search(protien_2, temp_buffer2, count)){
			
			temp_buffer2[j] = protien_2;
			j++;
			temp_count++;	
		}
			
			
	}
	
	cout<<temp_count<<endl;
	
	
	
	//initialize new buffer
	
	string buffer[temp_count];
	int z = 0;
	
	for(; z<count;z++){
		
		buffer[z] = temp_buffer[z];
	
	}
	z=count;
	for(int i = 0; z<temp_count;i++){
		
		buffer[z] = temp_buffer2[i];
		z++;
	}
	
	count = temp_count;

	/*for(int z = 0; z<count;z++){
		
		cout<<buffer[z]<<endl;
	
	}*/
	
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
