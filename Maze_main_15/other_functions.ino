void readThreshold(){
    Th1 = 800;//EEPROM.read(65) * 5;
    Th2 = 800;//EEPROM.read(66) * 5;
    Th3 = 800;//EEPROM.read(67) * 5;
    Th4 = 800;//EEPROM.read(68) * 5;
    Th5 = 700;//EEPROM.read(69) * 5;
    Th6 = 800;//EEPROM.read(70) * 5;
    
    ThM = 800;//EEPROM.read(71) * 5;
    
    Thf1 = 800;//EEPROM.read(72) * 5;
    Thf2 = 800;//EEPROM.read(73) * 5;
    Thf3 = 800;//EEPROM.read(74) * 5;
    
    Th11 = 800;//EEPROM.read(75) * 5;
    Th66 = 800;//EEPROM.read(76) * 5; 
    
    Thb1 = 800;//EEPROM.read(77) * 5;
    Thb2 = 800;//EEPROM.read(78) * 5;
    
    ThMid = 800;//EEPROM.read(79) * 5;
}


void LED(byte ii, byte jj, byte kk){  
   digitalWrite(31, ii);  //Red
   digitalWrite(33, jj);  //Yellow
   digitalWrite(35, kk);  //Blue
}

