#include <LiquidCrystal.h>
#include <Button.h>
#include "pitches.h"

/*
4 buttons with 4 coresponding LEDs 
LCD display (1602LCD)
 - using Analog pins instead to save some digital pin
*/


Button buttonPin1 = Button(2,PULLDOWN); // the number of the pushbutton pin
Button buttonPin2 = Button(3,PULLDOWN);
Button buttonPin3 = Button(4,PULLDOWN);
Button buttonPin4 = Button(5,PULLDOWN);


 int ledPin1 =  6;      // the number of the LED pin
 int ledPin2 =  7;
 int ledPin3 =  8;
 int ledPin4 =  9;
 
 int buzzer = 10;

// initialize the library with the numbers of the interface pins 
LiquidCrystal lcd(12, 11, 16, 17, 18, 19);

// the button state switch
boolean btnPressed1 = false;
boolean btnPressed2 = false;
boolean btnPressed3 = false;
boolean btnPressed4 = false;
boolean okToCheck = false;

long randNum;

int sequence[16];
int sequenceIndex = 0;
int player[15];
int playerIndex = 0;
int lives = 3;
int level= 1;
boolean endGame = false;
boolean getInput = false;
boolean getSeq = true;
boolean tryAgain = false;
boolean Loser = false;


 const int PIEZO = 10;
 
  long vel = 20000;

  int peergynt_m[] = {tone_G, tone_E, tone_D, tone_C, tone_D, tone_E, tone_G, tone_E, tone_D, tone_C, tone_D, tone_E, tone_D, tone_E,tone_G, tone_E, tone_G, tone_A, tone_E, tone_A, tone_G, tone_E, tone_D, tone_C};
  int peergynt_r[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 16};


void setup() 
{
  
    
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);      
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(buzzer,OUTPUT);
  
   //LCD Analog pins (11 & 10 are not)
  pinMode(16, OUTPUT);      
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
      
      digitalWrite(buzzer,LOW);

randomSeed(analogRead(0));

    Serial.begin(9600);

   // set up the LCD's number of columns and rows:   
   lcd.begin(16, 2);

   // Print a message to the LCD.   
   lcd.print("Sezar's Game..."); 
   
   lcd.setCursor(0,1); 
   lcd.print("Lives: ");
   lcd.print(lives);
   lcd.print("  L: ");
   lcd.print(level); 
   

}




void loop()
{
  
  
 
 
 
  
  /*
     add random number to sequence array
  */
  if(getSeq == true)
  {
    lcd.setCursor(0,1);    
    lcd.print("                ");    
    lcd.setCursor(0,1); 
   lcd.print("Lives: ");
   lcd.print(lives);
   lcd.print("  L: ");
   lcd.print(level);
   
   
    if(level > 1)
    {
     sequenceIndex++;
    }
    
    sequence[sequenceIndex] = random(0,4);
    Serial.println(sequence[sequenceIndex]);

     level++;

    getSeq = false;
  }
  
  
  
    
   /*
  If player reached last level end game
 */
 if(sequenceIndex == 15)
 {
   
   GameWin();
   
   endGame=true;
 }


  
  /*
    show sequence to player
  */    
  if(getInput == false)
  {
        Serial.println("going to show sequence");
    if(endGame == false)
    {
      Serial.println("almost in show sequence");
      showSequence();

       Serial.println("out off show sequence, getInput:");
        Serial.println(getInput);

    }
  }
 
 
 /*
  check for button press and add to player array
 */
 if (getInput == true)
 {
           Serial.println("going to btnCheck");
   btnCheck();
   Serial.println("going to check player");
   Serial.println(okToCheck);
   if(okToCheck == true)
   {
        
        
     checkPlayer();

        Serial.println("almost in check player, tryAgain: ");
        Serial.println(tryAgain);
    if(tryAgain == false)
    {
             Serial.println("in tyrAgain,sequenceIndex: ");
      Serial.println(sequenceIndex);
       Serial.println(" ,  ");
       Serial.println(playerIndex);
     if(sequenceIndex == playerIndex)
       {
         Serial.println("sequence index = player index");
         playerIndex = 0; 
         getInput = false;
         getSeq = true;
       }
       playerIndex++;
       okToCheck = false;
    }
    else
    {
      Serial.println("WTFFF");
      getInput=false;
      tryAgain =false;
      playerIndex = 0; 

    }
   }
   
  
 }
 
 
 
 if(Loser == true)
 {
   loseTone();
 }
 
 if(endGame == true)
 {
   getSeq = false;
   getInput = false;

 }
    
    
    
}












//check if button was pressed...
void btnCheck()
{
  

  
  if (buttonPin1.isPressed() ) {   
   if (btnPressed1==false)
   {
    // count++;
     //randNum = random(0,4);
      //      Serial.println(randNum);
          Serial.println("btn pressed:");
          Serial.println(btnPressed1);


     // turn LED on:    
        digitalWrite(ledPin1, HIGH);
        
        digitalWrite(buzzer,HIGH);
        
        
          // set the cursor to column 0, line 1
         // (note: line 1 is the second row, since counting begins with 0):   
       /*  lcd.setCursor(0,1); 
       
         // clear line first...
         lcd.print("                ");
         lcd.setCursor(0,1); 
         lcd.print("Pressed Button 1"); */
         
         
         player[playerIndex] = 0;
         
       btnPressed1 = true;
       okToCheck = true;
   }  
  }
  else  if (buttonPin2.isPressed() ) {   

    if(btnPressed2 == false)
    {
          Serial.println("btn pressed:");
          Serial.println(btnPressed2);

     // turn LED on:    
        digitalWrite(ledPin2, HIGH);
        
        digitalWrite(buzzer,HIGH);
        
        
          // set the cursor to column 0, line 1
         // (note: line 1 is the second row, since counting begins with 0):   
        /* lcd.setCursor(0,1); 
       
         // clear line first...
         lcd.print("                ");
         lcd.setCursor(0,1); 
         lcd.print("Pressed Button 2"); */ 
        
         player[playerIndex] = 1;
        btnPressed2 = true; 
        okToCheck = true;
    }
  }
  else if (buttonPin3.isPressed() ) { 
 
    if (btnPressed3 == false)
    {
          Serial.println("btn pressed:");
          Serial.println(btnPressed3);

   
     // turn LED on:    
        digitalWrite(ledPin3, HIGH);
        
        digitalWrite(buzzer,HIGH);
        
        
          // set the cursor to column 0, line 1
         // (note: line 1 is the second row, since counting begins with 0):   
        /* lcd.setCursor(0,1); 
       
         // clear line first...
         lcd.print("                ");
         lcd.setCursor(0,1); 
         lcd.print("Pressed Button 3");   */
         
         player[playerIndex] =2;
         
         btnPressed3 = true; 
         okToCheck = true;
    }

  }
  else  if (buttonPin4.isPressed() ) {    
    
    if(btnPressed4 == false)
    {
          Serial.println("btn pressed:");
          Serial.println(btnPressed4);

     // turn LED on:    
        digitalWrite(ledPin4, HIGH);
        
        digitalWrite(buzzer,HIGH);
        
        
          // set the cursor to column 0, line 1
         // (note: line 1 is the second row, since counting begins with 0):   
        /* lcd.setCursor(0,1); 
       
         // clear line first...
         lcd.print("                ");
         lcd.setCursor(0,1); 
         lcd.print("Pressed Button 4");  */
        
         player[playerIndex] = 3;
        
        btnPressed4 = true;
        okToCheck = true;
    } 
  }
  else {
    
              Serial.println("in else btnCheck");
    if(btnPressed1 == true)
    {
       // turn LED off:
        digitalWrite(ledPin1,LOW);
        digitalWrite(buzzer,LOW);
         /*
        lcd.setCursor(0,1); 
        lcd.print("                ");
        lcd.setCursor(0,1); 
        lcd.print("0 Button pressed");
        */
        btnPressed1 = false;
    }
    
    if(btnPressed2 == true)
    {
       // turn LED off:
        digitalWrite(ledPin2,LOW);
        digitalWrite(buzzer,LOW);

        /*lcd.setCursor(0,1); 
        lcd.print("                ");
        lcd.setCursor(0,1); 
        lcd.print("0 Button pressed");*/
        btnPressed2 = false;
    } 
    
    if (btnPressed3 == true)
    {
        digitalWrite(ledPin3,LOW);
        digitalWrite(buzzer,LOW);

        /*lcd.setCursor(0,1); 
        lcd.print("                ");
        lcd.setCursor(0,1); 
        lcd.print("0 Button pressed");*/
        
        btnPressed3 = false;
    }
      
     if(btnPressed4 == true)
     {
        digitalWrite(ledPin4,LOW);
        digitalWrite(buzzer,LOW);

        /*lcd.setCursor(0,1); 
        lcd.print("                ");
        lcd.setCursor(0,1); 
        lcd.print("0 Button pressed");  */
        
        btnPressed4 = false;
     }
  }  
  
 
}


void showSequence()
{
        Serial.println("In show sequence");
  int led;
  
 int i = 0; 
 
 
 //turn all leds off befor showing sequence
       digitalWrite(ledPin1,LOW);
       digitalWrite(ledPin2,LOW);
       digitalWrite(ledPin3,LOW);
       digitalWrite(ledPin4,LOW);

 
 while(i <= sequenceIndex){
    switch(sequence[i])
    {
      case 0:
            led = ledPin1;
         break;
      case 1:
            led = ledPin2;
         break;
      case 2:
            led = ledPin3;
         break;
      case 3:
            led = ledPin4;
         break;

      default:
      Serial.println("in switch default???!?!?");
    }
         
          Serial.println("sequence:");
          Serial.println(sequence[i]);
                

   Serial.println("led on:");
   Serial.println(led);
   
    delay(500);
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    Serial.println("led off:");

    i++;
  }
  
  getInput=true;
  Serial.println("getInput in show sequence");
}





/*

  checking if the two arrays (sequence and player) are the same
  Game over logic is here...
*/

void checkPlayer()
{
  for(int i = 0; i <= playerIndex; i++)
  {
    /* Serial.println("In Check player, sequence index:");
     Serial.println(sequenceIndex);
     Serial.println("player index:");
     Serial.println(playerIndex);


     Serial.println("sequence[i]:");
     Serial.println(sequence[i]);


     Serial.println("player[i]:");
     Serial.println(player[i]);*/
     
    if(sequence[i] != player[i])
    {
      if(lives > 0)
      {
        lives--;
        digitalWrite(buzzer,HIGH);
        lcd.setCursor(0,1); 
        lcd.print("                ");
        lcd.setCursor(0,1); 
        lcd.print("Lives: ");
        lcd.print(lives);
        lcd.print("  L: ");
        lcd.print(level);
        delay(1500);
        digitalWrite(buzzer,LOW);   
        
        tryAgain =true;
        getSeq =false;
      }
      else
      {
        endGame = true;
        
        digitalWrite(buzzer,HIGH);
        lcd.setCursor(0,0); 
        lcd.print("                ");
        lcd.setCursor(0,0); 
        lcd.print("GAME OVER!!");
        lcd.setCursor(0,1); 
        lcd.print("                ");
        lcd.setCursor(0,1); 
        lcd.print("reset btn 2 play");
        delay(3000);
        digitalWrite(buzzer,LOW);
          Loser =true;

      }
    }
  }
}





/*

  Game win logic

*/
void GameWin()
{
        digitalWrite(buzzer,HIGH);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        

        lcd.setCursor(0,0); 
        lcd.print("                ");
        lcd.setCursor(0,0); 
        lcd.print("U ARE Victorious");
        lcd.setCursor(0,1); 
        lcd.print("                ");
        lcd.setCursor(0,1); 
        lcd.print("reset btn 2 play");
        delay(3000);
        digitalWrite(buzzer,LOW);
        
          winTone();
        
}

void loseTone ()
{
    tone(10, NOTE_G2, 600);
    digitalWrite(ledPin1,HIGH);
      delay(600);
     digitalWrite(ledPin1,LOW);
     
     
      tone(10, NOTE_G2, 600);
      digitalWrite(ledPin1,HIGH);
      delay(600);
     digitalWrite(ledPin1,LOW);
     
      tone(10, NOTE_G2, 600);
     digitalWrite(ledPin1,HIGH);
      delay(600);
     digitalWrite(ledPin1,LOW);
     
      tone(10, NOTE_DS2, 500);
    digitalWrite(ledPin2,HIGH);
      delay(500);
     digitalWrite(ledPin2,LOW);

      tone(10, NOTE_AS2, 150);
    digitalWrite(ledPin4,HIGH);
      delay(150);
    digitalWrite(ledPin4,LOW);

      tone(10, NOTE_G2, 600);
     digitalWrite(ledPin1,HIGH);
      delay(600);
     digitalWrite(ledPin1,LOW);
     
      tone(10, NOTE_DS2, 500);
    digitalWrite(ledPin2,HIGH);
      delay(500);
     digitalWrite(ledPin2,LOW);
     
      tone(10, NOTE_AS2, 150);
    digitalWrite(ledPin4,HIGH);
      delay(150);
    digitalWrite(ledPin4,LOW);
     
      tone(10, NOTE_G2, 1200);
     digitalWrite(ledPin3,HIGH);
      delay(1200);
    digitalWrite(ledPin3,LOW);

     
      tone(10, NOTE_D3, 600);
     digitalWrite(ledPin1,HIGH);
      delay(600);
     digitalWrite(ledPin1,LOW);
     
      tone(10, NOTE_D3, 600);
     digitalWrite(ledPin1,HIGH);
      delay(600);
     digitalWrite(ledPin1,LOW);
     
      tone(10, NOTE_D3, 600);
     digitalWrite(ledPin1,HIGH);
      delay(600);
     digitalWrite(ledPin1,LOW);
     
      tone(10, NOTE_DS3, 500);
      delay(500);
     
      tone(10, NOTE_C3, 150);
    digitalWrite(ledPin4,HIGH);
      delay(150);
    digitalWrite(ledPin4,LOW);
     
      tone(10, NOTE_FS2, 600);
     digitalWrite(ledPin1,HIGH);
      delay(600);
     digitalWrite(ledPin1,LOW);
     
      tone(10, NOTE_D2, 500);
    digitalWrite(ledPin2,HIGH);
      delay(500);
     digitalWrite(ledPin2,LOW);
     
      tone(10, NOTE_AS2, 150);
    digitalWrite(ledPin4,HIGH);
      delay(150);
    digitalWrite(ledPin4,LOW);
     
      tone(10, NOTE_G2, 1200);
     digitalWrite(ledPin3,HIGH);
      delay(1200);
    digitalWrite(ledPin3,LOW);
     
      noTone(10);
}

void winTone()
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
