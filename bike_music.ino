#include "pitches.h"
#define PIN 12
#define RPIN A0
#define LPIN A1

char flag = 5;
//1: coin sound
//2: damage sound
//3: star sound
//4: dead sound
//5: vibrate short 2 times
//6: vibrate long (1 sec) Both


//coin
int melody_1[]={NOTE_B5, NOTE_E6};
int noteDurations_1[]={16,2};

//dead
int melody_2[]= {NOTE_B5,NOTE_F6,0,NOTE_F6,NOTE_F6,NOTE_E6,NOTE_D6,NOTE_C6};
int noteDurations_2[]= {8,8,8,8,6,6,6,4};

//damage
int melody_4[] = {NOTE_A3,NOTE_E3,NOTE_A2,0,NOTE_A3,NOTE_E3,NOTE_A2,0,NOTE_A3,NOTE_E3,NOTE_A2,0};
int noteDurations_4[] = {36,36,36,16,36,36,36,16,36,36,36,16};

//star
int melody_5[] = {NOTE_C5,0,NOTE_C5,0,NOTE_C5,0,NOTE_D4,NOTE_C5,0,NOTE_C5,0,NOTE_D4,NOTE_C5,NOTE_D4,NOTE_C5,0,NOTE_B4,0,NOTE_B4,0,NOTE_B4,0,NOTE_C4,NOTE_B4,0,NOTE_B4,0,NOTE_C4,NOTE_B4,NOTE_C4,NOTE_B4,0};
int noteDurations_5[] = {13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13};


int melody[100];
int noteDurations[100];
int length;

void setup() {
  //シリアル通信開始
  Serial.begin(57600);
}

void loop() {
  if(Serial.available()>0){
    flag=Serial.read();
    Serial.println(flag);
    switch(flag){
      case '1':
        for(int i=0;i<sizeof(melody_1)/sizeof(melody_1[0]);i++){
          melody[i]=melody_1[i];
          noteDurations[i]=noteDurations_1[i];
        }
        length=sizeof(noteDurations_1)/sizeof(noteDurations_1[0]);
        for (int i = 0; i < length; i++) {
          int noteDuration = 1000/noteDurations[i];
          tone(PIN, melody[i], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(PIN);
        }
        break;
      case '2':
         for(int i =0;i<sizeof(melody_4)/sizeof(melody_4[0]);i++){
           melody[i]=melody_4[i];
           noteDurations[i]=noteDurations_4[i];
         }
        length = sizeof(noteDurations_4)/sizeof(noteDurations_4[0]);
         for (int i = 0; i < length; i++) {
          int noteDuration = 1000/noteDurations[i];
          tone(PIN, melody[i], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(PIN);
        }
        break;
      case '3':
         for(int i =0;i<sizeof(melody_5)/sizeof(melody_5[0]);i++){
           melody[i]=melody_5[i];
           noteDurations[i]=noteDurations_5[i];
         }
        length = sizeof(noteDurations_5)/sizeof(noteDurations_5[0]);
         for (int i = 0; i < length; i++) {
          int noteDuration = 1000/noteDurations[i];
          tone(PIN, melody[i], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(PIN);
        }
        for (int i = 0; i < length; i++) {
          int noteDuration = 1000/noteDurations[i];
          tone(PIN, melody[i], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(PIN);
        }
        break;
      case '4':
        for(int i=0;i<sizeof(melody_2)/sizeof(melody_2[0]);i++){
          melody[i]=melody_2[i];
          noteDurations[i]=noteDurations_2[i];
        }
        length = sizeof(noteDurations_2)/sizeof(noteDurations_2[0]);
        for (int i = 0; i < length; i++) {
          int noteDuration = 1000/noteDurations[i];
          tone(PIN, melody[i], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(PIN);
        }
        break; 
      case '5':
        analogWrite(RPIN, 255);
        analogWrite(LPIN, 255);
        delay(200);
        analogWrite(RPIN, 0);
        analogWrite(LPIN, 0);
        delay(100);        
        analogWrite(RPIN, 255);
        analogWrite(LPIN, 255);
        delay(200);
        analogWrite(RPIN, 0);
        analogWrite(LPIN, 0);
        delay(100);        
        break;
      case '6':
        analogWrite(RPIN, 255);
        analogWrite(LPIN, 255);
        delay(1000);
        analogWrite(RPIN, 0);
        analogWrite(LPIN, 0);
        break;   
    }}
  else{
    //do nothing
  }
  
}
