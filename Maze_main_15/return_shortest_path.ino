void returnShortestPath(){
  shortestPath_breakPoint = 0;
  count = 0;
  previousMillis1 = millis();
//  millis_veri = 100;
   
  while(1){  
     readSensor();
     followLine();
     followPath();
     
     if(shortestPath_breakPoint == 1){
        move(120, 120);
        delay(500);
        turn('X');
        return; 
     }
  }
}


void followPath(){
   
   if((s1==1 && s2==1) || (s5==1 && s6==1)){
     
     //for time calculation
      currentMillis1 = millis();
      duration = (currentMillis1 - previousMillis1)/10;
      if(duration > 255){
          duration = 0;
      }
//      EEPROM.write(millis_veri, duration);
//      millis_veri++;
       
      
      
      if(data[count] == '\0'){
          shortestPath_breakPoint=1;
          return;
      }
      
      
      turn(data[count]);
      
      if(data[count] != 'S'){
          previousMillis1 = millis();
      }
      
      count++;
      
//      previousMillis = millis();
//      while(1){
//          readSensor();
//          followLine();
//          
//          currentMillis = millis();
//          if(currentMillis- previousMillis > interval){
//             break; 
//          }
//      } 
//      while(1){
//          readSensor();
//          if(s1==0 && s6==0){
//              break;
//          }
//          followLine();
//      }

    
   }
   
   
}



