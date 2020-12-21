
void readSensor(){
  sensorValue1 = analogRead(analogInPin1);  
  sensorValue2 = analogRead(analogInPin2);
  sensorValue3 = analogRead(analogInPin3);  
  sensorValue4 = analogRead(analogInPin4);  
  sensorValue5 = analogRead(analogInPin5);
  sensorValue6 = analogRead(analogInPin6);
 
  sensorValue_M = analogRead(analogInPin_M);  
  sensorValue_Mid = analogRead(analogInPin_Mid);
  
  frontSensorValue1 = analogRead(frontAnalogInPin1);  
  frontSensorValue2 = analogRead(frontAnalogInPin2);
  frontSensorValue3 = analogRead(frontAnalogInPin3);  
  
  sensorValue11 = analogRead(analogInPin11);  
  sensorValue66 = analogRead(analogInPin66);
  
  backSensorValue1 = analogRead(backAnalog1);
  backSensorValue2 = analogRead(backAnalog2);

  
  if(sensorValue1 > Th1)
     s1= AA;
  else s1= BB;
  
  if(sensorValue2 > Th2)
     s2= AA;
  else s2= BB;
  
  if(sensorValue3 > Th3)
     s3= AA;
  else s3= BB;
  
  if(sensorValue4 > Th4)
     s4= AA;
  else s4= BB;
  
  if(sensorValue5 > Th5)
     s5= AA;
  else s5= BB;
  
  if(sensorValue6 > Th6)
     s6= AA;
  else s6= BB;
  
  if(sensorValue_M > ThM)
     sM= AA;
  else sM= BB;
  
  if(sensorValue_Mid > ThMid)
     sMid= AA;
  else sMid= BB;
  
  
  //front sensor.
  if(frontSensorValue1 > Thf1)
     fs1= AA;
  else fs1= BB;
  
  if(frontSensorValue2 > Thf2)
     fs2= AA;
  else fs2= BB;
  
  if(frontSensorValue3 > Thf3)
     fs3= AA;
  else fs3= BB;
  
  //side sensor.
  if(sensorValue11 > Th11)
     s11= AA;
  else s11= BB;
  
  if(sensorValue66 > Th66)
     s66= AA;
  else s66= BB;
  
  
  //back sensor
  if(backSensorValue1 > Thb1)
     bs1= AA;
  else bs1= BB;
  
  if(backSensorValue2 > Thb2)
     bs2= AA;
  else bs2= BB;


/*
  Serial.print(s1);
  Serial.print("   ");
  Serial.print(s2);
  Serial.print("   ");
  Serial.print(s3);
  Serial.print("   ");
  Serial.print(s4);
  Serial.print("   ");
  Serial.print(s5);
  Serial.print("   ");
  Serial.print(s6);
  Serial.print("     ");
  
  Serial.print(s11);
  Serial.print("   ");
  Serial.print(s66);
  Serial.print("      ");
  
  Serial.print(fs1);
  Serial.print("   ");
  Serial.print(fs2);
  Serial.print("   ");
  Serial.print(fs3);
  Serial.print("      ");
  
  Serial.print(sM);
 Serial.print("      ");
  
  Serial.print(bs1);
  Serial.print("   ");
  Serial.print(bs2);
  Serial.print("\n");
*/

}
  



void move(int left, int right){
  
  if(motorSpeed != 100){
      left = (left*motorSpeed)/100;
      right = (right*motorSpeed)/100;
  }
  
  int speedA, speedB;
  
  if(right >= 0){
    speedA = right;        
    analogWrite(EnA, speedA);
    digitalWrite(InA, HIGH);
    digitalWrite(InB, LOW);
  }
  else if(right < 0){
    speedA = -right;       
    analogWrite(EnA, speedA);
    digitalWrite(InA, LOW);
    digitalWrite(InB, HIGH);
  }
  
  
  if(left >= 0){
    speedB = left;
    analogWrite(EnB, speedB);
    digitalWrite(InC, HIGH);
    digitalWrite(InD, LOW);
  }
  else if(left < 0){
    speedB = -left;       
    analogWrite(EnB, speedB);
    digitalWrite(InC, LOW);
    digitalWrite(InD, HIGH);
  }
  
}



void followLine(){
  
  if(s1==0 && s2==0 && s3==1 && s4==1 && s5==0 && s6==0){
      move(255, 255);
  }
  else if(s1==0 && s2==0 && s3==1 && s4==0 && s5==0 && s6==0){
      move(140,255);
  }
  else if(s1==0 && s2==1 && s3==1 && s4==0 && s5==0 && s6==0){
      move(10, 255);
  }
  else if(s1==0 && s2==1 && s3==0 && s4==0 && s5==0 && s6==0){
      move(0, 255);
  }
  else if(s1==1 && s2==1 && s3==0 && s4==0 && s5==0 && s6==0){
      move(-70, 150);
  }
  else if(s1==1 && s2==0 && s3==0 && s4==0 && s5==0 && s6==0){
      move(-150, 150);
  }
  
  else if(s1==0 && s2==0 && s3==0 && s4==1 && s5==0 && s6==0){
      move(255, 140);
  }
  else if(s1==0 && s2==0 && s3==0 && s4==1 && s5==1 && s6==0){
      move(255, 10);
  }
  else if(s1==0 && s2==0 && s3==0 && s4==0 && s5==1 && s6==0){
      move(255, 0);
  }
  else if(s1==0 && s2==0 && s3==0 && s4==0 && s5==1 && s6==1){
      move(150, -70);
  }
  else if(s1==0 && s2==0 && s3==0 && s4==0 && s5==0 && s6==1){
      move(150, -150);
  }
  
  //3 sensor
  else if(s1==0 && s2==1 && s3==1 && s4==1 && s5==0 && s6==0){
      move(70, 255);
  }
  else if(s1==0 && s2==0 && s3==1 && s4==1 && s5==1 && s6==0){
      move(255, 50);
  }
  
  else if(s1==1 && s2==1 && s3==1 && s4==0 && s5==0 && s6==0){
      move(10, 255);
  }
  else if(s1==0 && s2==0 && s3==0 && s4==1 && s5==1 && s6==1){
      move(255, 10);
  }
  
//  else if(s1==0 && s2==0 && s3==0 && s4==0 && s5==0 && s6==0){
//      move(-80, -80);
//  }
  
  else move(100, 100);
  
  
  if(s1==1 && s6==1){
      move(255, 255);
  }
}



void calibration(){
  
  LED(HIGH, HIGH, HIGH);
  delay(2000);
  
  int Th1H=0, Th2H=0, Th3H=0, Th4H=0, Th5H=0, Th6H=0, ThMH=0, ThMidH=0;
  int Th1L=1023, Th2L=1023, Th3L=1023, Th4L=1023, Th5L=1023, Th6L=1023, ThML=1023, ThMidL=1023;
  
  int Thf1H=0, Thf2H=0, Thf3H=0;
  int Thf1L=1023, Thf2L=1023, Thf3L=1023;
  
  int Th11H=0, Th11L=1023, Th66H=0, Th66L=1023;
    
  int Thb1H=0, Thb2H=0;
  int Thb1L=1023, Thb2L=1023;
  
  
  LED(LOW, HIGH, LOW);
  previousMillis = millis();
  while(1){
     currentMillis = millis();
     if(currentMillis- previousMillis > 10000){
        break; 
     }
     
     readSensor();
     
     if(sensorValue1 > Th1H){
         Th1H = sensorValue1;
     }
     if(sensorValue2 > Th2H){
         Th2H = sensorValue2;
     }
     if(sensorValue3 > Th3H){
         Th3H = sensorValue3;
     }
     if(sensorValue4 > Th4H){
         Th4H = sensorValue4;
     }
     if(sensorValue5 > Th5H){
         Th5H = sensorValue5;
     }
     if(sensorValue6 > Th6H){
         Th6H = sensorValue6;
     }
     if(sensorValue_M > ThMH){
         ThMH = sensorValue_M;
     }
     if(sensorValue_Mid > ThMidH){
         ThMidH = sensorValue_Mid;
     }
     
     
     
     if(sensorValue1 < Th1L){
         Th1L = sensorValue1;
     }
     if(sensorValue2 < Th2L){
         Th2L = sensorValue2;
     }
     if(sensorValue3 < Th3L){
         Th3L = sensorValue3;
     }
     if(sensorValue4 < Th4L){
         Th4L = sensorValue4;
     }
     if(sensorValue5 < Th5L){
         Th5L = sensorValue5;
     }
     if(sensorValue6 < Th6L){
         Th6L = sensorValue6;
     }
     if(sensorValue_M < ThML){
         ThML = sensorValue_M;
     }
     if(sensorValue_Mid < ThMidL){
         ThMidL = sensorValue_Mid;
     }
     
     
     //front sensor
     
     if(frontSensorValue1 > Thf1H){
         Thf1H = frontSensorValue1;
     }
     if(frontSensorValue2 > Thf2H){
         Thf2H = frontSensorValue2;
     }
     if(frontSensorValue3 > Thf3H){
         Thf3H = frontSensorValue3;
     }
     

     if(frontSensorValue1 < Thf1L){
         Thf1L = frontSensorValue1;
     }
     if(frontSensorValue2 < Thf2L){
         Thf2L = frontSensorValue2;
     }
     if(frontSensorValue3 < Thf3L){
         Thf3L = frontSensorValue3;
     }

     
     
     
     if(sensorValue11 > Th11H){
         Th11H = sensorValue11;
     }
     if(sensorValue66 > Th66H){
         Th66H = sensorValue66;
     }
     
     if(sensorValue11 < Th11L){
         Th11L = sensorValue11;
     }
     if(sensorValue66 < Th66L){
         Th66L = sensorValue66;
     }
     
     
     
     //back sensor     
     if(backSensorValue1 > Thb1H){
         Thb1H = backSensorValue1;
     }
     if(frontSensorValue2 > Thb2H){
         Thb2H = backSensorValue2;
     }


     if(backSensorValue1 < Thb1L){
         Thb1L = backSensorValue1;
     }
     if(backSensorValue2 < Thb2L){
         Thb2L = backSensorValue2;
     }
  } 
   
  Th1 = (Th1H + Th1L) / 2;
  Th2 = (Th2H + Th2L) / 2;
  Th3 = (Th3H + Th3L) / 2;
  Th4 = (Th4H + Th4L) / 2;
  Th5 = (Th5H + Th5L) / 2;
  Th6 = (Th6H + Th6L) / 2;
  
  ThM = (ThMH + ThML) / 2;
  ThMid = (ThMidH + ThMidL) / 2;
  
  Thf1 = (Thf1H + Thf1L) / 2;
  Thf2 = (Thf2H + Thf2L) / 2;
  Thf3 = (Thf3H + Thf3L) / 2;
  
  Th11 = (Th11H + Th11L) / 2;
  Th66 = (Th66H + Th66L) / 2;
  
  Thb1 = (Thb1H + Thb1L) / 2;
  Thb2 = (Thb2H + Thb2L) / 2;

  LED(HIGH, LOW, LOW);
  delay(1000);
  
  EEPROM.write(65, Th1/5);
  EEPROM.write(66, Th2/5);
  EEPROM.write(67, Th3/5);
  EEPROM.write(68, Th4/5);
  EEPROM.write(69, Th5/5);
  EEPROM.write(70, Th6/5);
  
  EEPROM.write(71, ThM/5);
  
  EEPROM.write(72, Thf1/5);
  EEPROM.write(73, Thf2/5);
  EEPROM.write(74, Thf3/5);
  
  EEPROM.write(75, Th11/5);
  EEPROM.write(76, Th66/5);
  
  EEPROM.write(77, Thb1/5);
  EEPROM.write(78, Thb2/5);
  
  EEPROM.write(79, ThMid/5);

  delay(100);
  LED(HIGH, HIGH, HIGH);
  while(1){
    //nothing 
  }
}

