#include "pitches.h"
 
int buzzer=8;
                         //음계
int melody[] ={NOTE_E4,NOTE_B4,NOTE_B4,NOTE_FS4,NOTE_E4,NOTE_E4,
                NOTE_B3,NOTE_E4,NOTE_E4,NOTE_FS4,NOTE_E4,0,
                NOTE_E4,NOTE_B4,NOTE_B4,NOTE_FS4,NOTE_E4,NOTE_E4,
                NOTE_B3,NOTE_E4,NOTE_E4,NOTE_FS4,NOTE_E4,0,
                NOTE_FS4,NOTE_B4,NOTE_A4,NOTE_E4,NOTE_FS4,NOTE_D4,
                NOTE_D4,NOTE_A4,NOTE_G4,NOTE_C4,
                NOTE_B3,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_FS4,NOTE_G4,
                NOTE_A4,NOTE_B4,NOTE_A4,NOTE_DS4
               };
                            //음의길이, 4 = 4분음표, 1.3 = 점2분음표
int noteDurations[] ={4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1.3,4,4,4,4,4,4,4,4,4,1.3};
 
void setup() {
  for(int thisNote =0; thisNote <44; thisNote++)
  {
    int noteDuration =1000 /noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);
    int pauseBetweenNotes =noteDuration *1.2;          //음표 구분 시간
    delay(pauseBetweenNotes);
    noTone(buzzer);
  }
}
 
void loop() {
}