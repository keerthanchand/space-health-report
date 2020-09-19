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

void reset_pusle_sensor(){}
