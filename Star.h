#ifndef STAR_H
#define STAR_H


class Planet{
	private:
		long id;
		int pos;
		int distance;
        char type;
	public:
		Planet(){this->id=-1;};
		Planet(int);
        int orbit();
		long getID();
        int getDistance();
        int getPos();
        char getType();
        char rand_type();
		//you may add any additional methods you may need.
};

class Star{
	private:
        //int max_planets;
        int current_planets;
        //int next_id;
	public:
        Planet ** planets;
        Star();
        ~Star();
        long addPlanet();
        Planet * getPlanet(int);
        bool removePlanet(int);
        void orbit();
        void printStarInfo();
        int getCurrentNumPlanets();
        bool findPlanet(int);
        //int getMaxPlanets();
        //you may add any additional methodas you may need.
};

#endif