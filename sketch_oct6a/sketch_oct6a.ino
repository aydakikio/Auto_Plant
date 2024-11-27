#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>

void setup() {
  
  pinMode(8, OUTPUT) ;// pothos moisture sensor power
  pinMode(9 , OUTPUT ) ;// Peperomia moisture sensor power

  pinMode(A2, INPUT); //pothos sensor read

   pinMode(6, OUTPUT); // pothos water pump
   pinMode(5, OUTPUT); //pothos water pump

   pinMode(11 , OUTPUT); //Peperomia water pomp
   pinMode(12 , OUTPUT); //Peperomia water pump

   pinMode(13 , OUTPUT); // water sensor 

  digitalWrite(8, LOW); 
  digitalWrite(9 , LOW);

  digitalWrite(13 , LOW); // water sensor 

  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

  //power off unnessary pins
  digitalWrite(A0, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);

  digitalWrite(2, LOW);
  digitalWrite(10, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);

}

void loop() {
    
    sleep_disable();
    power_all_enable (); 

    check_pothos_moisture();
    Check_Peperomia_moisture();

 
  delay(70);
  Deep_Sleep_Manual();

  delay(86400000);//24 hour check
}

int check_pothos_moisture(){

  digitalWrite(8 , HIGH );
  delay(30);

  int val = analogRead(A2);


  delay(500);

  if(val > 720){

    if(check_water_sensor() == 0 ){
      while (analogRead(A2) > 720) {
      turn_on_pothos_water_pomps(0);
      }
        
      turn_on_pothos_water_pomps(1);
    }
  
  } else if  ((val < 720) && (val > -1) ) {

    //ITS OK!!
  }
    digitalWrite(8 ,LOW );

  return val;
}

void Check_Peperomia_moisture(){
  digitalWrite(9, HIGH);
  delay(30);
  int val = digitalRead(7);

  

  delay(500);

  if(val == 1 ){
    //turn on water pomp
    if(check_water_sensor() == 0){
      while (digitalRead(7) == 1 ) {
        turn_on_Peperomia_water_pump(0);
      }

      turn_on_Peperomia_water_pump(1);

    }
  } else {
    //Its Ok
  }

  digitalWrite(9, LOW);
}

int check_water_sensor(){

  digitalWrite(13 , HIGH);
  delay(10);
  int val = analogRead(A0);

  digitalWrite(13 , LOW);

  if(val < 360 ){
    //No water
    return 1;
  }  else {
    //enough water
    return 0;
  }

  return NULL;
  
}

void turn_on_pothos_water_pomps(int mode ){

  switch (mode) {
  case 0:
    digitalWrite(5 , HIGH);
   digitalWrite(6 , HIGH);
  break;
  case 1:
    digitalWrite(5, LOW);
    digitalWrite(6 , LOW);
  break;
  }
}
void turn_on_Peperomia_water_pump(int mode ){


  switch (mode) {
    case 0 :
      digitalWrite(11 , HIGH);
      digitalWrite(12 , HIGH);
    break;
    case 1 :

      digitalWrite(11, LOW);
      digitalWrite(12 , LOW);

    break;
  }

}



void Deep_Sleep_Manual(){

  
  set_sleep_mode (SLEEP_MODE_IDLE);

  power_all_disable (); // power off ADC, Timer 0 and 1, serial interface

  noInterrupts ();       // timed sequence coming up

  sleep_enable ();       // ready to sleep

  interrupts ();         // interrupts are required now

  sleep_cpu ();          // sleep     

}
