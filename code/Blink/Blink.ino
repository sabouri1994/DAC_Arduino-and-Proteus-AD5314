#include <SoftwareSerial.h>


SoftwareSerial mySerial(10, 11); // RX, TX
byte  LSB;
byte  MSB;
void setup()
{
Serial.begin(9600);
mySerial.begin(9600);
pinMode(3, OUTPUT); // pin 3.3 in datasheet
// First config for AD5314:
LSB =  00000000;
MSB =  00110000;   ///PD=1 , LDAC=1

digitalWrite(3, LOW);
mySerial.print(LSB, BIN);
digitalWrite(3, HIGH);
mySerial.print(MSB, BIN);

Serial.println("PD and LDAC set to 1 ");
Serial.println("Normal operation is Active");
delay(2000);
}

void loop()
{
WriteDAC('A',250);
delay(700);
}

 
 void WriteDAC(char a, int num){
  
    uint8_t bitsCount = sizeof( num ) * 5;
      char str[ bitsCount + 1 ];
      char t[9];
      char t2[3];
      uint8_t i = 0;
      while ( bitsCount-- )
          str[ i++ ] = bitRead( num, bitsCount ) + '0';
      str[ i ] = '\0';
    Serial.print( "Binary of cammand: ");
    Serial.println( str );
   i = 2;
   int bitt=9,s=0;
    while ( bitt-- )
      {
       t[s++]=str[i++];
       }

   i = 0;
   s=0;
   bitt=2;
    while ( bitt-- )
      {
       t2[s++]=str[i];
       i=i+1;
       }
//     Serial.println( t ); 
//     Serial.println( t2 );
      
  //Select AD5314 Output:
switch (a) {
  uint16_t r;
  uint8_t b1,b2;
  uint8_t bitsCount;
  uint8_t i ;
  char str[ 256 ];
    case 'A':
      Serial.println("Your output is A");
      
       b1 = 0b0000011, b2 = t2;
       r = (b1<<4) + b2;
      

       bitsCount = sizeof( r ) * 4;
       i = 0;
      while ( bitsCount-- )
          str[ i++ ] = bitRead( r, bitsCount ) + '0';
      str[ i ] = '\0';
      Serial.print( "MSB =");
      Serial.println( str );

      Serial.print( "LSM =");
      Serial.println( t);


      digitalWrite(3, LOW);
      mySerial.print(LSB, BIN);
      digitalWrite(3, HIGH);
      mySerial.print(MSB, BIN);
    break;
     case 'B':
     Serial.println("Your output is B");
     b1 = 0b0000111, b2 = t2;
      r = (b1<<4) + b2;
      

       bitsCount = sizeof( r ) * 4;
      
       i = 0;
      while ( bitsCount-- )
          str[ i++ ] = bitRead( r, bitsCount ) + '0';
      str[ i ] = '\0';
      Serial.print( "MSB =");
      Serial.println( str );

      Serial.print( "LSM =");
      Serial.println( t );


      digitalWrite(3, LOW);
      mySerial.print(LSB, BIN);
      digitalWrite(3, HIGH);
      mySerial.print(MSB, BIN);
      break;
     case 'C':
     Serial.println("Your output is C");
      b1 = 0b0001011, b2 = t2;
       r = (b1<<4) + b2;
      

       bitsCount = sizeof( r ) * 4;
      
       i = 0;
      while ( bitsCount-- )
          str[ i++ ] = bitRead( r, bitsCount ) + '0';
      str[ i ] = '\0';
      Serial.print( "MSB =");
      Serial.println( str );

      Serial.print( "LSM =");
      Serial.println( t );

      digitalWrite(3, LOW);
      mySerial.print(LSB, BIN);
      digitalWrite(3, HIGH);
      mySerial.print(MSB, BIN);
      break;
     case 'D':
     Serial.println("Your output is D");
      b1 = 0b0001111, b2 = t2;
       r = (b1<<4) + b2;
      

       bitsCount = sizeof( r ) * 4;
      
       i = 0;
      while ( bitsCount-- )
          str[ i++ ] = bitRead( r, bitsCount ) + '0';
      str[ i ] = '\0';
      Serial.print( "MSB =");
      Serial.println( str );

      Serial.print( "LSM =");
      Serial.println( t );
      
      digitalWrite(3, LOW);
      mySerial.print(LSB, BIN);
      digitalWrite(3, HIGH);
      mySerial.print(MSB, BIN);
      break;
          default: 
        Serial.println("Your output not defined");
        break;
            }
 }
