#include <EEPROM.h>

const byte analogInPin1 = A2;
const byte analogInPin2 = A1;
const byte analogInPin3 = A0;
const byte analogInPin4 = A8; 
const byte analogInPin5 = A9;
const byte analogInPin6 = A10;

const byte analogInPin_M = A7;
const byte analogInPin_Mid = A14;

const byte frontAnalogInPin1 = A4;
const byte frontAnalogInPin2 = A5;
const byte frontAnalogInPin3 = A6;

const byte analogInPin11 = A3; 
const byte analogInPin66 = A11;

const byte backAnalog1 = A12;
const byte backAnalog2 = A13;


const byte EnA = 11, EnB = 12;
const byte InA = 5, InB = 4, InC = 6, InD = 7;


const byte button1 = 16, button2 =15, button3=14;


int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorValue5 = 0;
int sensorValue6 = 0;

int sensorValue_M = 0;
int sensorValue_Mid = 0;

int frontSensorValue1 = 0;
int frontSensorValue2 = 0;
int frontSensorValue3 = 0;

int sensorValue11 = 0;
int sensorValue66 = 0;

int backSensorValue1 = 0;
int backSensorValue2 = 0;


byte AA= 1, BB= 0;

//threshold
int Th1, Th2, Th3, Th4, Th5, Th6, ThM, ThMid;
int Thf1, Thf2, Thf3;
int Th11, Th66;
int Thb1, Thb2;

byte s1, s2, s3, s4, s5, s6, sM, sMid;
byte fs1, fs2, fs3;
byte s11, s66;
byte bs1, bs2;


byte motorSpeed = 100; //parcent


long previousMillis = 0, previousMillis1 = 0;
int interval = 300, duration;
long currentMillis, currentMillis1;
int millis_veri = 100;

byte followLeft_breakPoint = 0, followRight_breakPoint = 0, shortestPath_breakPoint = 0, break_veri = 0, SL=0;


char data[500]; // = "LLBLLLRLBRLSLLBRLLLRLBLLBRSLLLBLLSSSLBLBLBLLLBRLLRR";
int count=0;


int rf=0;

void setup(){
   Serial.begin(9600);
  
   pinMode(EnA, OUTPUT);
   pinMode(EnB, OUTPUT);
   
   pinMode(InA, OUTPUT);
   pinMode(InB, OUTPUT);
   pinMode(InC, OUTPUT);
   pinMode(InD, OUTPUT);
   
   pinMode(31, OUTPUT);
   pinMode(33, OUTPUT);  
   pinMode(35, OUTPUT);  
   
   pinMode(button1, INPUT);
   pinMode(button2, INPUT);
   pinMode(button3, INPUT);
}

void loop(){
   delay(1000);
  
   readThreshold();
   
   byte Bt1 = digitalRead(button1);
   byte Bt2 = digitalRead(button2);
   byte Bt3 = digitalRead(button3);
   

   if(Bt1==HIGH){
      calibration();
   }
   
   if(Bt2==HIGH){  //white line
      AA= 0;
      BB= 1;
      
      LED(0,0,1);
      if(Bt3==LOW){
         delay(1000);
      }
   }
   
   char hand = 'L';
   
   if(Bt3==HIGH){
       hand = 'R';
       LED(0,1,0);
       delay(1000);
   }
   
//   while(1){
//      readSensor();
//      followLine();
//      
//      if((s1==1 && s3==1) || (s4==1 && s6==1)){
//         move(0, 0);
//         while(1){} 
//      }
//   }
//   
   
//   LED(1,0,0);




//   while(1){
//      readSensor();
//     followLine(); 
//   }

    while(1){
       readSensor();
       if(s1==0 && s6==0){
          break;
       }
       move(150, 150);
    }
    

   
       leftHand();
   
   
   LED(1,1,1);
   
    move(120,120);
    delay(200);
    
    turn('X');
    delay(3000);
//    move(140, -210);
//    
//    delay(500);
//    
//    while(1){
//       readSensor();
//       if(fs1==0 && fs3==0){
//          break;
//       }                                       
//    }
//    
//    while(1){
//        readSensor();
//        if(fs1==1 || fs3==1){
//            
//            move(100, 100);
//            delay(100);   
//            
//            while(1){
//                readSensor();
//                if(s1==0 || s6==0){
//                    break;
//                }
//                followLine();
//            }
//            break;
//        }
//    }
    while(1){
       readSensor();
       if(s1==0 && s6==0){
          break;
       }
       move(150, 150);
    }
   
   
   if(hand == 'R'){
      generatePath();
      
   }
   else{
     // data[]= "RRSLLSRLLSRSS";
      data[0]='R';
      data[1]='R';
      data[2]='S';
      data[3]='L';
      data[4]='L';
      data[5]='S';
      data[6]='R';
      data[7]='L';
      data[8]='L';
      data[9]='S';
      data[10]='R';
      data[11]='S';
      data[12]='S';
      data[13]='\0';
   }

 //  delay(1000);
   
   returnShortestPath();
   
   LED(0,0,0);
   while(1){
     //nothing
   }
}
