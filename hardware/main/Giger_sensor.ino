#include "RadiationWatch.h"

RadiationWatch radiationWatch;


void connect_to_giger_sensor(){
    radiationWatch.setup();
}


int Radiation_count_capture_data(){
  return(radiationWatch.radiationCount());
}

float cpm_capture_data(){
  return(radiationWatch.cpm());
}

float uSvh_capture_data(){
  return(radiationWatch.uSvh());
}
