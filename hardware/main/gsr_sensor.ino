#include "GlobalVar.h"



int gsr_capture_data(){

  int data = 0;
  int data_sum = 0;
  int GSR_data = 0;
  for(int i=0; i<GSR_data_sampling_rate; i++){
    data = analogRead(gsr_sensor_pin);
    data_sum += data;
    delay(5);
  }
  gsr_sensor_pin = data_sum/GSR_data_sampling_rate;
  return(gsr_sensor_pin);  
}

int GSR_raw_value(){
  int data = 0;
  data = analogRead(gsr_sensor_pin);
  return(data);
}
