#include "MAX30100_PulseOximeter.h"
PulseOximeter pox;

#define REPORTING_PERIOD_MS     1000

uint32_t tsLastReport = 0;

bool connect_to_pulse_sensor(){
  int tries = Pulse_sensor_Connection_tries;
  while(!pox.begin()){
    reset_pusle_sensor();
    tries--;
  }
  if (tries < 1){
    return(false);
  }
  return(true);
}

int Heart_rate_capture_data(){
      pox.update();
      return pox.getHeartRate();

}

int SpO2_capture_data(){
      pox.update();
      return pox.getSpO2();
}

int Get_heart_rate(){
 if(connect_to_pulse_sensor()){
    int pulse = Heart_rate_capture_data(); 
}else{
     int pulse = 0;
}
}

int Get_SpO2(){
 if(connect_to_pulse_sensor()){
    int SpO2 = SpO2_capture_data();
 }else{
  int SpO2 = 0;
 }
}



void reset_pusle_sensor(){}
