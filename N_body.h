// Darryl Seligman N_body simulation header file
/*This is the header file definining the structures 
  class
  and the methods that we will use to set the structures

 */

#ifndef collider_h
#define collider_h

// Particle struct to hold particle info
struct Position {
  double x;
  double y;
  double z;
};
struct Velocity{
  double vx;
  double vy;
  double vz;
};
struct Density{
  double rhox;//rho x  is density
  double rhoy;
  double rhoz;
};
struct Potential{
  double phix;
  double phiy;
  double phiz;
};



// Particle grid class
class grid {
 public:
  int N=100;
  Position position[N];
  Velocity velocity[N];


  // Private -> not accessible from outside class!
  //Include the constructor destructor
 private:
 public:
  grid();
  ~grid();

  // Public -> accessible


  
  //set and get methods for position and velocity
  //set position for given x y z
  void set_position(double x, double y, double z);
  //defaul set all positions to zero
  void set_position();

  void get_position(Position, &position);


  void set_velocity(double vx, double vy, double vz);
  void set_velocity();
  void get_velocity(Velocity, &velocity);


  /* method cicInterpolate calculates the contribution of each 
     particle in our grid to the density grid using the CIC interpolation
     outlined in section 2.4 of the writeup  */
  void cicInterpolate(int ngrid, int npart, double *x, double *y, double *z, double ***rho);

  /*method solvePoisson will use the density grid and solve Poissions equation
    to get the acceleration field */

  void solvePoisson(double a, double ***rho, double ***phi, int ngrid);

  /*method updateParticles will update the position and velocity for each particle
    in our simulation using the leapfrog integration method outlined in section 2.7*/
  void updateParticles(int ngrid, int npart, double a, double da, double *x, double *y, double *z, double *vx, double *vy, double *vz double ***phi);


};

#endif
