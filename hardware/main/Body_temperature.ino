#include <Wire.h>
#include "GlobalVar.h"

#include "Protocentral_MAX30205.h"
MAX30205 tempSensor;

bool connect_to_temperature_sensor(){
  int tries = MAX30205_Connection_tries;
  while(!tempSensor.scanAvailableSensors()){
    delay(100);
    tries --;

     if(tries < 1){
      return(false);
     }
  }
  tempSensor.begin();
  return(true);
}

float Body_temperature_capture_data(){
  float body_temperature_data = 0.0;
  float data_sum = 0.0;
  for(int i=0; i<Body_temperature_data_sampling_rate; i++){
    float data = tempSensor.getTemperature();
    data_sum += data;
    delay(5);
  }
  body_temperature_data = data_sum/Body_temperature_data_sampling_rate;
  return(body_temperature_data);
}
