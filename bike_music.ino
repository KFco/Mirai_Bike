#include "pitches.h"
#define PIN 12
#define VIBPIN A0

int flag = 5;
//1: coin
//2: dead
//3: star
//4: vibrate short 2 times
//5: vibrate long (1 sec)

//coin
int melody_1[]={NOTE_B5, NOTE_E6};
int noteDurations_1[]={16,2};

//dead
int melody_2[]= {NOTE_B5,NOTE_F6,0,NOTE_F6,NOTE_F6,NOTE_E6,NOTE_D6,NOTE_C6};
int noteDurations_2[]= {8,8,8,8,6,6,6,4};

//star
int melody_3[] = {NOTE_C6,NOTE_C6,NOTE_C6,NOTE_D5,NOTE_C6,0,NOTE_C6,NOTE_D6,NOTE_C6,NOTE_D5,NOTE_C6};
int noteDurations_3[] = {8,8,8,16,16,16,8,16,16,16,8};
    
int melody[100];
int noteDurations[100];
int length;

void setup() {
  if (flag == 1){
    for(int i=0;i<sizeof(melody_1)/sizeof(melody_1[0]);i++){
      melody[i]=melody_1[i];
      noteDurations[i]=noteDurations_1[i];
    }
    length = sizeof(noteDurations_1)/sizeof(noteDurations_1[0]);
  }if (flag == 2){
     for(int i =0;i<sizeof(melody_2)/sizeof(melody_2[0]);i++){
       melody[i]=melody_2[i];
       noteDurations[i]=noteDurations_2[i];
     }
     length = sizeof(noteDurations_2)/sizeof(noteDurations_2[0]);
  }if (flag == 3){
     for(int i =0;i<sizeof(melody_3)/sizeof(melody_3[0]);i++){
       melody[i]=melody_3[i];
       noteDurations[i]=noteDurations_3[i];
     }
     length = sizeof(noteDurations_3)/sizeof(noteDurations_3[0]);
  }if (flag == 4){
    analogWrite(VIBPIN, 255);
    delay(200);
    analogWrite(VIBPIN, 0);
    delay(100);
    analogWrite(VIBPIN, 255);
    delay(200);
    analogWrite(VIBPIN, 0);
  }if (flag == 5){
    analogWrite(VIBPIN, 255);
    delay(1000);
    analogWrite(VIBPIN, 0);
  }

  for (int i = 0; i < length; i++) {
    int noteDuration = 1000/noteDurations[i];
    tone(PIN, melody[i], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(PIN);
  }
  
}

void loop() {

  // no need to repeat the melody.
}
