#include "Vector.h"
#include "Star.h"
#include <iostream>

Vector::Vector(){
    planets = NULL;
	capacity = 0;
}

void Vector::insert(int index, Planet * p){
    if(index > (capacity - 1)){			//index exceeds bound
      	Planet ** temp = new Planet * [index + 1];
      	for(int i = 0; i < capacity; i++){
        	temp[i] = planets[i];
      	}
      	temp[index] = p;
      	for(int i = 0; i < capacity; i++){
        	planets[i] = NULL;
      	}
      	delete[] planets;
      	planets = temp;
      	temp = NULL;
		capacity = index + 1 ;
    }
    else{
      	Planet ** temp = new Planet * [capacity+1];
      	for(int i = 0; i< capacity ;i++){
          	temp[i] = planets[i];
      	}
		for(int i = index; i< capacity+1 ; i++){
			if(i == index){
				if(i == capacity) temp[i] = p;
				else{
					temp[i+1] = temp[i];
					temp[i] = p;
				} 
			}
			else{
				if(i == capacity) break;
				else{
					temp[i+1] = temp[i];
				}
			}
		}
		for(int i = 0; i < capacity; i++){
        	planets[i] = NULL;
      	}
		delete[] planets;
		planets = temp;
		temp = NULL;
		capacity++;
    }
}

Planet* Vector::read(int index){
	if(index > (capacity - 1)) return NULL;
	else{
		return planets[index];
	}
}

bool Vector::remove(int index){
	if(index > (capacity - 1)) return false;
	else{
		Planet ** temp = new Planet * [capacity-1];
		delete this->planets[index];
		for(int i = index;i<this->capacity;i++){					
			if(i==this->capacity-1) this->planets[i] = NULL;
			else this->planets[i] = this->planets[i+1];
		}
		for(int i =0;i<this->capacity-1;i++){	//copy
			temp[i] = this->planets[i];
		}
		if(this->planets != NULL){						//free the old array
			for(int i=0;i<this->capacity-1;i++){
				this->planets[i] = NULL;	
			}
		}
		delete[] this->planets;
		this->planets = temp;
		temp = NULL;
		this->capacity--;

		return true;
	}
}

unsigned Vector::size(){
	
}

Vector::~Vector(){
    //delete
	//this->capacity = 0;
	for(int i = 0;i<this->capacity;i++){
		delete this->planets[i];
		this->planets = NULL;
	}
	delete[] this->planets;
}
