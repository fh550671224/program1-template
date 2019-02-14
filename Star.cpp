#include "Star.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Planet::Planet(){
	this->id = (long)this;      //NOT SURE
	this->distance = rand() % 3001 ;
    this->pos = rand() % 360 ;
	this->type = rand_type();
}

long Planet::getID(){
	return this->id;
}

char Planet::rand_type(){
	int i = rand() % 3 ;
	switch (i){
		case 0: 
			return 'h';
			break;
		case 1:
			return 'r';
			break;
		case 2:
			return 'g';
			break;
		default:
			return 'q';
			break;
	}
}

char Planet::getType(){
	return this->type;
}

int Planet::orbit(){
	this->pos++;
	if(360==this->pos){
		this->pos=0;
	}
	return this->pos;
}

int Planet::getDistance(){
	return this->distance;
}

int Planet::getPos(){
	return this->pos;
}

Star::Star(){
	this->current_planets = 0;
	//this->next_id = 0;
	planets = NULL ;
}

Star::~Star(){
	//destructor
	for(int i = 0;i< this->current_planets;i++){
		delete this->planets[i];
		this->planets[i]=NULL;
	}
	delete[] this->planets;
	this->planets = NULL;
}

long Star::addPlanet(){

	Planet ** temp = new Planet * [this->current_planets+1];	//allocate a new array of size 1 + the current number of Planets
	for(int i=0;i<this->current_planets;i++){
		temp[i] = this->planets[i];					//copy all the pointers over to the new array
	}
	temp[this->current_planets] = new Planet();	//create a new Planet object
	long id = temp[this->current_planets]->getID();
	if(this->planets != NULL){						//free the old array
		for(int i=0;i<this->current_planets;i++){
			this->planets[i] = NULL;	
		}
	}
	delete[] this->planets;
	this->planets = temp; 	//point the planet array to the new array
	temp = NULL;
	//this->next_id++;
	this->current_planets++;
	
	return id;
}

Planet * Star::getPlanet(int id){
	for(int i = 0;i<this->current_planets;i++){
		if(this->planets[i]->getID() == id) return this->planets[i];
	}
	return NULL;
}

bool Star::findPlanet(int id){
	if( NULL==getPlanet(id) ) return false;
	else return true;
}

bool Star::removePlanet(int id){
	if(true==findPlanet(id)){
		Planet ** temp = new Planet * [this->current_planets-1];
		int index = 0;
		for(int i=0;i<this->current_planets;i++){		//find index of the planet in the old array
			if(id==this->planets[i]->getID()){
				index = i;
				break;
			}
		}
		delete this->planets[index];
		for(int i = index;i<this->current_planets;i++){					
			if(i==this->current_planets-1) this->planets[i] = NULL;
			else this->planets[i] = this->planets[i+1];
		}

		for(int i =0;i<this->current_planets-1;i++){	//copy
			temp[i] = this->planets[i];
		}

		if(this->planets != NULL){						//free the old array
			for(int i=0;i<this->current_planets-1;i++){
				this->planets[i] = NULL;	
			}
		}
		delete[] this->planets;
		this->planets = temp;
		temp = NULL;
		this->current_planets--;
		
		return true;
		
	}
	else return false;
}

void Star::orbit(){
	for(int i=0;i<this->current_planets;i++){
		this->planets[i]->orbit();
	}
}

void Star::printStarInfo(){
	cout<<"The star has "<<this->current_planets<<" planets."<<endl;
	cout<<"Planets:"<<endl;
	for(int i=0;i<this->current_planets;i++){
		cout<<"\t"<<"Planet "<<this->planets[i]->getType()<< this->planets[i]->getID()<< " is "<< this->planets[i]->getDistance() <<" miles away at positon "<< this->planets[i]->getPos() << " around the star."<<endl;
	}
	
}

int Star::getCurrentNumPlanets(){
	return this->current_planets;
}