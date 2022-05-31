/*
  [Attiny 25/45/85 Pinout]
                  ------
  RESET=A0=PB5=5-|      |-VCC
        A3=PB3=3-|      |-2=PB2=A1=SCK=SCL
        A2=PB4=4-|      |-1(~)=PB1=MISO
             GND-|      |-0(~)=PB0=MOSI=SDA
                  ------
  [Functions]
  WATER L  : FAN & PELTIER  -> OFF
  WATER H  : FAN & PELTIER  -> ON
*/

#define MISO          1     // PELTIER
#define WATER         3     // WATER
#define FAN           4     // FAN 
                                                                                                                          
void tempGet();

void setup()
{
  pinMode(MISO, OUTPUT);
  pinMode(WATER, INPUT);
  pinMode(FAN, OUTPUT);

  digitalWrite(MISO, LOW);
  digitalWrite(FAN, LOW);
}

void loop(void)
{
  int waterState = digitalRead(WATER);
 
  if (waterState == 0 )
  {
    digitalWrite(MISO, LOW);    // PELTIER OFF
    digitalWrite(FAN, LOW);     // FAN OFF
    delay(5000);
  }

  else if ( waterState == 1 )   //1번째 응답 요청
  {
    digitalWrite(MISO, HIGH);    // PELTIER ON
    digitalWrite(FAN, HIGH);     // FAN ON
    delay(30000);
  }

  else if ( waterState == 1 )   //2번째 응답 요청
  {
    digitalWrite(MISO, HIGH);    // PELTIER ON
    digitalWrite(FAN, HIGH);     // FAN ON
    delay(30000);
  }

  else if ( waterState == 1 )   //3번째 응답 요청
  {
    digitalWrite(MISO, LOW);    // PELTIER OFF
    digitalWrite(FAN, LOW);     // FAN OFF
  } 
  else
    {
    digitalWrite(MISO, LOW);    // PELTIER OFF
    digitalWrite(FAN, LOW);     // FAN OFF
  }
  delay(2000); 
}
