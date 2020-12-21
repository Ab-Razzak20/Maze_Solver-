void leftHand(){
   followLeft_breakPoint = 0;
   count = 0;
   
   while(1){  
      readSensor();
      followLeft();
      followLine();
      
     
      if(followLeft_breakPoint == 1){
         //turn('X');
         //delay(2000);
         return; 
      }
   }
}


void followLeft(){
   
   if(((s1==1 && s3==1) || (s4==1 && s6==1)) && fs1==1 && fs2==1 && fs3==1){
       delay(10);
       readSensor();
       if(s1==1 && s3==1 && s4==1 && s6==1 && fs1==1 && fs2==1 && fs3==1){
       
       
       followLeft_breakPoint=1;
       return;
       }
   }
  
   else if((s1==1 && s3==1) || (s4==1 && s6==1)){
     
        if(fs1==1 || fs2==1 || fs3==1){
            SL=1; 
        }
        else SL=0;
     
     
        //for time calculation
        currentMillis1 = millis();
        duration = (currentMillis1 - previousMillis1)/10;
        if(duration > 255){
            duration = 0;
        }
//        EEPROM.write(millis_veri, duration);
//        millis_veri++;
     
       
      if(s1==1 || s11==1){
         
         ch1:
        
         data[count] = 'L';
         LED(1,0,0);
         
         turn('L');
      }
      
      else if(fs1==1 || fs2==1 || fs3==1){
        
         ch2: 
        
         while(1){
            readSensor();
            if(bs1==1 || bs2==1){
               break;
            }
            else if(s1==1 || s11==1){
               goto ch1;
            }
            followLine();
         }
        
         data[count] = 'S';
         LED(0,1,0);
         turn('S');
      }
      
      else if(s6==1 || s66==1){
        
         while(1){
            readSensor();
            if(duration > 60)
               move(60,60);
            else if(duration > 30)
               move(80,80);
            else move(110, 110);
            
            if(s1==1 || s11==1){
               LED(1,1,1);
               goto ch1;
            }
            if(fs1==1 || fs2==1 || fs3==1){
                goto ch2;
            }
            
            if(bs1==1 || bs2==1)
                break;
            //followLine();
         }
        
         data[count] = 'R';
         LED(0,0,1);
         
         turn('r');
      }
      
      if(data[count] != 'S'){
          previousMillis1 = millis();
      }
      
      count++;     
   }
   
   
   else if(s1==0 && s2==0 && s3==0 && s4==0 && s5==0 && s6==0 && sM==0 && fs1==0 && fs2==0 && fs3==0){
     
        //for time calculation
        currentMillis1 = millis();
        duration = (currentMillis1 - previousMillis1)/10;
        if(duration > 255){
            duration = 0;
        }
        EEPROM.write(millis_veri, duration);
        millis_veri++;
        
     
       data[count] = 'B';
       turn('B');
       
       
       previousMillis1 = millis();
      
       
       
       count++;
   }

     else {
       LED(0,0,0);
     }  
  
}
