	
     #include "pitches.h"
     
   /*  
    void setup() {
     
    }
     
    void loop() {
      tone(1, NOTE_G2, 600);
      delay(600);
     
      tone(9, NOTE_G2, 600);
      delay(600);
     
      tone(9, NOTE_G2, 600);
      delay(600);
     
      tone(9, NOTE_DS2, 500);
      delay(500);
     
      tone(9, NOTE_AS2, 150);
      delay(150);
     
      tone(9, NOTE_G2, 600);
      delay(600);
     
      tone(9, NOTE_DS2, 500);
      delay(500);
     
      tone(9, NOTE_AS2, 150);
      delay(150);
     
      tone(9, NOTE_G2, 1200);
      delay(1200);
     
      tone(9, NOTE_D3, 600);
      delay(600);
     
      tone(9, NOTE_D3, 600);
      delay(600);
     
      tone(9, NOTE_D3, 600);
      delay(600);
     
      tone(9, NOTE_DS3, 500);
      delay(500);
     
      tone(9, NOTE_C3, 150);
      delay(150);
     
      tone(9, NOTE_FS2, 600);
      delay(600);
     
      tone(9, NOTE_D2, 500);
      delay(500);
     
      tone(9, NOTE_AS2, 150);
      delay(150);
     
      tone(9, NOTE_G2, 1200);
      delay(1200);
     
      noTone(9);
    }

*/

const int PIEZO = 10;
 
long vel = 20000;
 
// mario
int mario_m[] = {tone_e, tone_e, tone_e, tone_c, tone_e, tone_g, tone_G, tone_c, tone_G, tone_E, tone_A, tone_B, tone_Bb, tone_A, tone_G, tone_e, tone_g, tone_a, tone_f, tone_g, tone_e, tone_c, tone_d, tone_B, tone_c};
int mario_r[] = {6, 12, 12, 6, 12, 24, 24, 18, 18, 18, 12, 12, 6, 12, 8, 8, 8, 12, 6, 12, 12, 6, 6, 6, 12};
 
// Looks like zelda
int peergynt_m[] = {tone_G, tone_E, tone_D, tone_C, tone_D, tone_E, tone_G, tone_E, tone_D, tone_C, tone_D, tone_E, tone_D, tone_E,tone_G, tone_E, tone_G, tone_A, tone_E, tone_A, tone_G, tone_E, tone_D, tone_C};
int peergynt_r[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 16};
 
// Some electric guitar...
int smoke_m[] = {tone_E, tone_G, tone_A, tone_E, tone_G, tone_Bb, tone_A, tone_E, tone_G, tone_A, tone_G, tone_E};
int smoke_r[] = {12, 12, 18, 12, 12, 6, 18, 12, 12, 18, 12, 24};
 
// Start like something similar to le reine au nez rouge...
int natal_m[] = {tone_G, tone_A, tone_G, tone_E, tone_G, tone_A, tone_G, tone_E, tone_c, tone_c, tone_A, tone_B, tone_B, tone_G, tone_A, tone_G, tone_A, tone_c, tone_B, tone_A, tone_G, tone_A, tone_G, tone_E};
int natal_r[] = {12, 4, 8, 16, 12, 4, 8, 16, 12, 4, 16, 12, 4, 16, 12, 4, 8, 8, 8, 8, 12, 4, 8, 16};
 
// Seems like some electric guitar solo...
int LTS_m[] = {tone_Bb, tone_G, tone_G, tone_Bb, tone_G, tone_G, tone_Bb, tone_G, tone_G, tone_Bb, tone_G, tone_G, tone_Bb, tone_G, tone_C, tone_G, tone_Bb, tone_G, tone_G, tone_Bb, tone_G, tone_G, tone_Bb, tone_G, tone_G, tone_Bb, tone_G, tone_G, tone_Bb, tone_G, tone_F, tone_D, tone_F, tone_D, tone_G, tone_F, tone_D, tone_C, tone_Bb, tone_G, tone_Bb, tone_C, tone_C1, tone_C, tone_Bb, tone_F, tone_D, tone_Bb, tone_G, tone_F, tone_D, tone_C, tone_Bb, tone_D, tone_C, tone_Bb, tone_G} ;
int LTS_r[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
 
void setup()
{
    pinMode(PIEZO, OUTPUT);
    delay(2000);
   
    Serial.begin(115200);
}
 
void loop()
{
    const int LEN = (sizeof(peergynt_r) + 1) / 4;
    Serial.println(LEN);
    for (int i=0; i < LEN; i++)
    {
        int tom = peergynt_m[i];
        int tempo = peergynt_r[i];
 
        long tvalue = tempo * vel;
 
        tocar(tom, tvalue);
 
        delayMicroseconds(1000); //pause between notes
    }
}
 
void tocar(int tom, long tempo_value)
{
     long tempo_gasto = 0;
     while (tempo_gasto < tempo_value && tempo_value < 640000) // enters an infinite loop when tempo_value is a big value
     {  
        digitalWrite(PIEZO, HIGH);
        delayMicroseconds(tom / 2);
 
        digitalWrite(PIEZO, LOW);
        delayMicroseconds(tom/2);
 
        tempo_gasto += tom;
    }
}
