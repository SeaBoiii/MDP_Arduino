long static errorL[2] = {-1};
long static errorR[2] = {-1};


class Movement {

	private:
		float lk1, lk2, lk3,lkp,lkd,lki;
	    float rk1, rk2, rk3,rkp,rkd,rki;
		float l_speed, r_speed;
	public: 
	    float distanceL = 0;
	    float distanceR = 0;
	    float distanceTraversed = 0;
	    float previousLSpeed = 0;
	    float previousLError = 0;
	    float previousLError2 = 0;
	    float previousRSpeed = 0;
	    float previousRError = 0;
	    float previousRError2 = 0;
      float LErrors = 0;
      float RErrors = 0;
		//Left
		int pinA1;
		int pinA2;
		//Right
		int pinB1;
		int pinB2;		 
		Movement(int, int, int, int, float, float, float,float,float,float);
		float computeL(long setLSpeed, unsigned long ltime);
		float computeR(long setRSpeed, unsigned long rtime);
		//void moveForward(long setLSpeed, long setRSpeed, Encoder en , DualVNH5019MotorShield md);
	    float convertLSpeed(float rpm);
	    float convertRSpeed(float rpm);
      float convertRRPM(float rspeed);
      float convertLRPM(float lspeed);
	    void resetDistance();
};	
