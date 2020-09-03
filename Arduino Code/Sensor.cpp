#include "Sensor.h"
#include "DualVNH5019MotorShield.h"
#include "SharpIR.h"

SharpIR right_sensor(A0, 20150);
SharpIR left_back_sensor(A1, 1080);
SharpIR left_front_sensor(A2, 1080);
SharpIR front_middle_sensor(A3, 1080);
SharpIR front_left_sensor(A4, 1080);
SharpIR front_right_sensor(A5, 1080);


Sensor::Sensor(){
    
}


void Sensor::wallHugging(long l_speed, long r_speed){
	  int sensorA1 = LFDistance(1); // left front
  	int sensorA2 = LBDistance(1); // left back
  	int checked = 0;
  	//Check if front and back is aligned
  	while(checked == 0){
  		Serial.println("calibrating");
	  	checked = 1; // if entered either of the loops, check again
	  	while(sensorA1 != sensorA2){
	  		if(sensorA1 <= sensorA2){ // if sensorA1 is closer to wall than sensorA2	  	
	  			rotateRight(sensorA2-sensorA1, l_speed, r_speed);
	  		}
	  		else{
	  			rotateLeft(sensorA1-sensorA2, l_speed, r_speed);
	  		}
	  		checked = 0;
	  	}
		//check if it is 5 cm
	  	while(sensorA1 != 5){
	  	  	if(sensorA1 <= 5){ // if sensorA1 is closer to wall than sensorA2
	  			moveRight(5-sensorA1, l_speed, r_speed);
	  		}
	  		else{
	  			moveLeft(sensorA1-5, l_speed, r_speed);
	  		}	
	  		checked = 0;
	  	}
	}
}

void Sensor:: rotateRight(int sensDiff, long l_speed, long r_speed){
	//md.setSpeeds(l_speed,-r_speed);
	delay(1);
	//md.setBrakes(l_speed,-r_speed);
}

void Sensor:: rotateLeft(int sensDiff, long l_speed, long r_speed){
	//md.setSpeeds(-l_speed,r_speed);
	delay(1);
	//md.setBrakes(-l_speed,r_speed);	
}

void Sensor::moveRight(int x,long l_speed, long r_speed){
	//Turn right
	//move forward by x cm
	//turn left
}

void Sensor::moveLeft(int x,long l_speed,long r_speed){
	//turn left
	//move forward by x cm
	//turn right
}

float Sensor::FMDistance(int method) {
  float distance;
  if (method == 1) {
    return distance = front_middle_sensor.distance() - 2.26; 
  }
  else if (method == 2) {
    float x = front_middle_sensor.median_Voltage_Sampling();
    return distance = (342249.6-32728.63*x)/(1+12763.97*x+328.3559*(pow(x,2)));
  }
  else if (method == 3) {
    float x = front_middle_sensor.median_Voltage_Sampling();
    return distance = (26.9723/x)-3.142919;
  }
  return -1;
}

float Sensor::FLDistance(int method) {
  float distance;
  if (method == 1) {
    return distance = front_left_sensor.distance() - 3.91;
  }
  else if (method == 2) {
    float x = front_left_sensor.median_Voltage_Sampling();
    return distance = (163.3724-5.125353*x)/(1+2.455257*x+2.906178*(pow(x,2)));
  }
  else if (method == 3) {
    float x = front_left_sensor.median_Voltage_Sampling();
    return distance = (30.23257/x)-5.944718;
  }
  return -1;
}

float Sensor::FRDistance(int method) {
  float distance;
  if (method == 1) {
    return distance = front_right_sensor.distance() - 3.92;
  }
  else if (method == 2) {
    float x = front_right_sensor.median_Voltage_Sampling();
    return distance = (228550.6-46173.84*x)/(1+7737.163*x-259.7944*(pow(x,2)));
  }
  else if (method == 3) {
    float x = front_right_sensor.median_Voltage_Sampling();
    return distance = (31.05792/x)-6.114549;
  }
  return -1;
}

float Sensor::LFDistance(int method) {
  float distance;
  if (method == 1) {
    return distance = left_front_sensor.distance() - 5.34;
  }
  else if (method == 2) {
    float x = left_front_sensor.median_Voltage_Sampling();
    return distance = (159401.4-22277.58*x)/(1+3966.488*x+1617.304*(pow(x,2)));
  }
  else if (method == 3) {
    float x = left_front_sensor.median_Voltage_Sampling();
    return distance = (32.2953/x)-7.67349;
  }
  return -1;
}

float Sensor::LBDistance(int method) {
  float distance;
  if (method == 1) {
    return distance = left_back_sensor.distance() - 6.14;
  }
  else if (method == 2) {
    float x = left_back_sensor.median_Voltage_Sampling();
    return distance = (64608.62-10629.52*x)/(1+1970.039*x+384.1247*(pow(x,2)));
  }
  else if (method == 3) {
    float x = left_back_sensor.median_Voltage_Sampling();
    return distance = (30.68132/x)-7.074208;
  }
  return -1;
}

float Sensor::RDistance(int method) {
  float distance;
  if (method == 1) {
    return distance = right_sensor.distance() - 5.84;
  }
  else if (method == 2) {
    float x = right_sensor.median_Voltage_Sampling();
    return distance = (278976.2-69729.29*x)/(1+3824.989*x-614.9018*(pow(x,2)));
  }
  else if (method == 3) {
    float x = right_sensor.median_Voltage_Sampling();
    return distance = (87.40818/x)-17.38074;
  }
  return -1;
}
