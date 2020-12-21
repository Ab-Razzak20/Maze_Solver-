void turn(char ch){
    
   if(ch=='X'){
      if(duration==0 || duration > 100){ 
         move(-180,-180);
         delay(200);
         move(0, 0); 
         return;
      }
      
      else if(duration > 50 && duration < 100){ 
         move(-130,-130);
         delay(200);
         move(0, 0); 
         return;
      }
      
      else if(duration < 25 && duration != 0){ 
         move(-30,-30);
         delay(200);
         move(0, 0); 
         return;
      }
      
      else { 
         move(-80,-80);
         delay(200);
         move(0, 0); 
         return;
      }
      
      
   }
   
   else if(ch=='R'){
            
      while(1){
         readSensor();
         if(duration > 60)
            move(60,60);
         else if(duration > 30)
            move(80,80);
         else move(110, 110);
         if(bs1==1 || bs2==1)
             break;
         //followLine();
      }
      turn('X');
      while(1){
          readSensor();
          if(bs1==1 || bs2==1)
              break;
          move(-120,-120); 
      }
     
      move(240, -240);
      delay(200);
      
      while(1){
         readSensor();
         if(s3==0 && s4==0){
            break;
         }                                       
      }
      
   
      
      while(1){
          readSensor();
          if(sM==1 || s4==1){
             
              if(sMid==1){
                 previousMillis = millis();
                 while(1){
                    readSensor();
                    if(sM==1 || s4==1)
                       break;
                    currentMillis = millis();
                    if(currentMillis - previousMillis > 70)
                        break;
                 }
              }
              
              move(-100, 100);
              delay(50);   
              
              readSensor();
              if(s2==0 && s3==0 && s4==0 && s5==0 && sM==0){
                  shortLine_R();
                  return;
              }
              
              while(1){
                  readSensor();
                  if(s1==0 || s6==0){
                      break;
                  }
                  followLine();
              }
              return;
          }
      }
      
      break_veri = 0;
   }
   
   
   
   
   else if(ch=='r'){
            

      turn('X');
      while(1){
          readSensor();
          if(bs1==1 || bs2==1)
              break;
          move(-120,-120); 
      }
     
      move(240, -240);
      delay(200);
      
      while(1){
         readSensor();
         if(s3==0 && s4==0){
            break;
         }                                       
      }
      
      while(1){
          readSensor();
          if(s3==1 || s4==1){
              
              move(-100, 100);
              delay(30);   
              
              while(1){
                  readSensor();
                  if(s1==0 || s6==0){
                      break;
                  }
                  followLine();
              }
              return;
          }
      }
      
      break_veri = 0;
   }

   
   
   
   else if(ch=='L'){
      
      while(1){
         readSensor();
         if(duration > 60)
            move(60,60);
         else if(duration > 30)
            move(80,80);
         else move(110, 110);
         if(bs1==1 || bs2==1)
             break;
         //followLine();
      }
      turn('X');
      while(1){
          readSensor();
          if(bs1==1 || bs2==1)
              break;
          move(-120,-120); 
      }
     
      move(-240, 240);
      delay(200);

      
      while(1){
         readSensor();
         if(s3==0 && s4==0){
            break;
         }                                       
      }
      
      while(1){
          readSensor();
          if(s3 == 1 || sM==1 || s4==1 || sMid==1){
             
              if(sMid==1){
                 previousMillis = millis();
                 while(1){
                    readSensor();
                    if(sM==1 || s4==1)
                       break;
                    currentMillis = millis();
                    if(currentMillis - previousMillis > 230)
                        break;
                 }
              }
              
              move(100, -100);
              delay(30);   
              
              readSensor();
              if(s2==0 && s3==0 && s4==0 && s5==0 && sM==0){
                  shortLine();
                  return;
              }
              
//              while(1){
//                  readSensor();
//                  if(s1==0 || s6==0){
//                      break;
//                  }
//                  followLine();
//              }
              return;
          }
      }
      
      break_veri = 0;
   }
   
   
   
   else if(ch=='l'){
      
      turn('X');
      while(1){
          readSensor();
          if(bs1==1 || bs2==1)
              break;
          move(-120,-120); 
      }
     
      move(-240, 240);
      delay(200);
      
   //   move(0,0);
   //   while(1){}
      
      while(1){
         readSensor();
         if(s3==0 && s4==0){
            break;
         }                                       
      }
      
      while(1){
          readSensor();
          if(fs1==1 || fs2==1){
              
              move(100, -100);
              delay(30);   
              
              while(1){
                  readSensor();
                  if(s1==0 || s6==0){
                      break;
                  }
                  followLine();
              }
              return;
          }
      }
      
      break_veri = 0;
   }

   
   
   
   else if(ch=='B'){
      move(100,100);
      delay(150);
      turn('X');
      move(120, -220);
      
      delay(500);
      
      while(1){
         readSensor();
         if(fs1==0 && fs2==0){
            break;
         }                                       
      }
      
      while(1){
          readSensor();
          if(fs1==1 || fs3==1){
              
              move(-100, 100);
              delay(30);   
              
//              while(1){
//                  readSensor();
//                  if(s1==0 || s6==0){
//                      break;
//                  }
//                  followLine();
//              }
              return;
          }
      }
      
      break_veri = 0;
   }
   
   
   else if(ch=='S'){
     
      previousMillis = millis();
      while(1){
          readSensor();
          followLine();
          
          currentMillis = millis();
          if(currentMillis- previousMillis > 100){
             break; 
          }
      } 
      while(1){
          readSensor();
          if(s1==0 && s6==0){
              break;
          }
          followLine();
      }
      
      break_veri = 1;
      return;
   }  
}



void shortLine(){
  
   rf++;
  
   LED(0,0,0);

//    move(-120,-120); 
//    while(1){
//       readSensor();
//       if(bs1==1 || bs2==1)
//           break;          
//    }
    
    if(rf>=3){
        move(-210, 45);
        delay(200);
        while(1){
          readSensor();
          if(fs2==1||fs3==1){
             move(0,0);
             return;
          }
        }
          
    }
    
    move(180, -210);
    delay(200);
    
    while(1){
       readSensor();
       if(sM==0 && s3==0){
          break;
       }                                       
    }
    
    while(1){

             previousMillis = millis();
             while(1){
                readSensor();
                if(fs1==1 || fs2==1 ||fs3==1)   //(sM==1 || s4==1 || s3==1)   // *** can be changed with front sensors ***
                   break;
                currentMillis = millis();
                if(currentMillis - previousMillis > 200){
                    readSensor();
                    break;
                }
             }
            
            
            if(fs1==0 && fs2==0 && fs3==0){ //(s2==0 && s3==0 && s4==0 && s5==0 && sM==0){
                while(1){
                   readSensor();
                   if(fs1==1 || fs2==1 || fs3==1)
                      break;
                }
                move(-100, 100);
                delay(50);
                data[count] = 'B';
                return;
            }
            
            else{
                move(-100, 100);
                delay(50);
                
                count++;
                data[count] = 'B';
                count++;
                data[count] = 'L';
                return;
            }

            return;
        
    }
    
}



void shortLine_R(){

//    move(-120,-120); 
//    while(1){
//       readSensor();
//       if(bs1==1 || bs2==1)
//           break;          
//    }
    
    move(-230, 60);
    delay(200);
    
    while(1){
       readSensor();
       if(sM==0 && s4==0){
          break;
       }                                       
    }
    
    while(1){

             previousMillis = millis();
             while(1){
                readSensor();
                if(fs1==1 || fs2==1 ||fs3==1)   //(sM==1 || s4==1 || s3==1)   // *** can be changed with front sensors ***
                   break;
                currentMillis = millis();
                if(currentMillis - previousMillis > 200){
                    readSensor();
                    break;
                }
             }
            
            
            if(fs1==0 && fs2==0 && fs3==0){ //(s2==0 && s3==0 && s4==0 && s5==0 && sM==0){
                while(1){
                   readSensor();
                   if(fs1==1 || fs2==1 || fs3==1)
                      break;
                }
                move(100, -100);
                delay(50);
                data[count] = 'B';
                return;
            }
            
            else{
                move(100, -100);
                delay(50);
                
                count++;
                data[count] = 'B';
                count++;
                data[count] = 'L';
                return;
            }

            return;
        
    }
    
}
