int latchPin = 8;
int clockPin = 12;
const int buttonPin = 2;
int buttonState = 0;
int dataPin = 11;
byte colDataMatrix[8] = { B01111111,
   B10111111,
   B11011111,
   B11101111,
   B11110111,
   B11111011,
   B11111101,
   B11111110
  };
                      
//byte rowDataMatrix2[8] = { B00111100,
//                           B01000010,
//                           B10100101,
//                           B10000001,
//                           B10011001,
//                           B10100101,
//                           B01000010,
//                           B00111100
//  };
 
// byte rowDataMatrix[8] = { B00111100,
//                           B01000010,
//                           B10100101,
//                           B10000001,
//                           B10100101,
//                           B10011001,
//                           B01000010,
//                           B00111100
//  };
byte rowDataMatrix[8] = { B11111111,
             B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B11111111
  };

 byte rowDataMatrix2[8] = { B00000000,
                            B01100110,
                            B11111111,
                            B11111111,
                            B11111111,
                            B01111110,
                            B00111100,
                            B00011000
  };
// 
// byte rowDataMatrix[8] = { B00000000,
//                           B01100110,
//                           B11110111,
//                           B11101111,
//                           B11110111,
//                           B01101110,
//                           B00110100,
//                           B00001000
//  };

 int delay_time = 1;
      
void setup() {
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT);
digitalWrite(buttonPin,HIGH);
  pinMode(buttonPin,INPUT);
}
void loop() {
 for(int i = 0; i < 8 ; i++){
  buttonState = digitalRead(buttonPin);
 //byte colData = colDataMatrix[i];
 if(buttonState == HIGH){
digitalWrite(latchPin,LOW);
  //  pickDigit(i);
   shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[i]);
    //shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
    digitalWrite(latchPin,HIGH);
    delay(delay_time);
    
 }
   else {
    digitalWrite(latchPin,LOW);
  //  pickDigit(i);
   shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix2[i]);
    //shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
    digitalWrite(latchPin,HIGH);

  }
}

}
