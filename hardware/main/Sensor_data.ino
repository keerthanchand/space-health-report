//String Get_sensor_data(){
//  int gsr_data = gsr_capture_data();
//  int pulse = 0;
//    int SpO2 = 0;
//  if(connect_to_pulse_sensor()){
//    int pulse = Heart_rate_capture_data();
//    int SpO2 = SpO2_capture_data();
//  int gama = gsr_capture_data();
//  int radiation_count = Radiation_count_capture_data();
//  float cpm = cpm_capture_data();
//  float uSvh = uSvh_capture_data();
//  if(connect_to_temperature_sensor()){
//    int body_temperature = Body_temperature_capture_data();
//  }else{
//    int body_temperature = 0;
//  }
//  String data = gsr_data + ","+ pulse+","+SpO2+","+gama+","+radiation_count+","+cpm+","+uSvh+","+body_temperature;
//  return(data);
//}
