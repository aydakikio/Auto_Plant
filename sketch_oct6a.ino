#include <U8g2lib.h>

//U8G2_SH1106_128X64_NONAME_2_HW_I2C u8g2(U8G2_R0, -1, A5, A4);

void setup() {
  // put your setup code here, to run once:
  //u8g2.begin();

  pinMode(4, OUTPUT) ;// pothos moisture sensor power
  pinMode(5 , OUTPUT ) ;// other moisture sensor power
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A2, INPUT); //pothos sensor
 
  digitalWrite(4, LOW); // moisture 
  //digitalWrite(5, LOW);
  

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  /*
  if(check_water_sensor() != 1 ){
      //check_pothos_moisture();
      //Check_barg_ghashogy_moisture();
  }
  */
  digitalWrite(6, HIGH); //pump1
  digitalWrite(5 , HIGH); //pump 1
  //Serial.println("pump = on");
  //delay(1000);
  //digitalWrite(6, LOW);

  /*
  u8g2.firstPage();
  do {
    //u8g2.menu_items[item_selected]setFont(u8g2_font_5x7_mf);
    //u8g2.drawStr(0, 20, "HI");
    
      u8g2.setFont(u8g2_font_5x7_mf);
      u8g2.drawStr(0, 20, "HI!!");
    

  } while (u8g2.nextPage());
  */
  //delay(1000);
}

int check_pothos_moisture(){

  digitalWrite(4 , HIGH );
  delay(30);

  int val = analogRead(A2);

  digitalWrite(4 ,LOW );

  delay(500);

  if(val > 750){
    Serial.println("Satarting water pumps");
  } else if  ((val < 800) && (val > -1) ) {
    Serial.println("It's OK!!");
  }
  

  return val;
}

void Check_barg_ghashogy_moisture(){
  digitalWrite(5, HIGH);
  delay(30);
  int val = digitalRead(7);

  digitalWrite(5, LOW);

  delay(500);

  if(val == 1 ){
    //turn on water pomp
  } else {
    //Its Ok
  }
}

int check_water_sensor(){

  int val = analogRead(A0);

  if(val < 650 ){
    //writes some thing on display
    Serial.println("No Water");
    return 1;
  }  else {
  Serial.println("Much Water");
    return 0;
  }

  return NULL;
  
}

void turn_on_water_pomps(){

}