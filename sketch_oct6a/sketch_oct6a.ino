//#include <U8g2lib.h>

//U8G2_SH1106_128X64_NONAME_2_HW_I2C u8g2(U8G2_R0, -1, A5, A4);

void setup() {
  // put your setup code here, to run once:
  //u8g2.begin();

  pinMode(4, OUTPUT) ;// pothos moisture sensor power
  pinMode(3 , OUTPUT ) ;// other moisture sensor power

  pinMode(A2, INPUT); //pothos sensor in

   pinMode(6, OUTPUT); // pothos water pump
   pinMode(5, OUTPUT); //pothos water pump

   pinMode(11 , OUTPUT);
   pinMode(12 , OUTPUT);

   pinMode(13 , OUTPUT); // water sensor

  digitalWrite(4, LOW); // moisture 
  digitalWrite(3 , LOW);

  digitalWrite(13 , LOW); // water sensor 

  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

    check_pothos_moisture();
    Check_barg_ghashogy_moisture();

  /*
  u8g2.firstPage();
  do {
    //u8g2.menu_items[item_selected]setFont(u8g2_font_5x7_mf);
    //u8g2.drawStr(0, 20, "HI");
    
      u8g2.setFont(u8g2_font_5x7_mf);
      u8g2.drawStr(0, 20, "HI!!");
    

  } while (u8g2.nextPage());
  */
  delay(28800000);
}

int check_pothos_moisture(){

  digitalWrite(4 , HIGH );
  delay(30);

  int val = analogRead(A2);

  digitalWrite(4 ,LOW );

  delay(500);

  if(val > 800){

    if(check_water_sensor() == 0 ){
       turn_on_pothos_water_pomps();
    }
  
  } else if  ((val < 800) && (val > -1) ) {

    //ITS OK!!
  }
  

  return val;
}

void Check_barg_ghashogy_moisture(){
  digitalWrite(3, HIGH);
  delay(30);
  int val = digitalRead(7);

  digitalWrite(3, LOW);

  delay(500);

  if(val == 1 ){
    //turn on water pomp
    if(check_water_sensor() == 0){

      turn_on_barg_ghashogi_water_pump();

    }
  } else {
    //Its Ok
  }
}

int check_water_sensor(){

  digitalWrite(13 , HIGH);
  delay(10);
  int val = analogRead(A0);

  digitalWrite(13 , LOW);

  if(val < 395 ){
    //No water
    return 1;
  }  else {
    //enough water
    return 0;
  }

  return NULL;
  
}

void turn_on_pothos_water_pomps(){

  digitalWrite(5 , HIGH);
  digitalWrite(6 , HIGH);

  delay (450000);

  digitalWrite(5, LOW);
  digitalWrite(6 , LOW);

}
void turn_on_barg_ghashogi_water_pump(){

  digitalWrite(11 , HIGH);
  digitalWrite(12 , HIGH);

  delay (450000);

  digitalWrite(11, LOW);
  digitalWrite(12 , LOW);

}