#include <LiquidCrystal.h>
#include <Button.h>

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


long randNum;


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
   lcd.print("hello, world!"); 
   
   lcd.setCursor(0,1); 
   lcd.print("Pressed A Button"); 
   

}




void loop()
{
  
      
  /*    
  // read the state of the pushbutton value:
  btnCheck(buttonPin1,ledPin1,btnPressed1);
  btnCheck(buttonPin2,ledPin2,btnPressed2);
  btnCheck(buttonPin3,ledPin3,btnPressed3);
  btnCheck(buttonPin4,ledPin4,btnPressed4);
 */
 
 btnCheck();
 
 
  
  
  
  
  
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
         // Serial.println(btnPressed1);


     // turn LED on:    
        digitalWrite(ledPin1, HIGH);
        
        digitalWrite(buzzer,HIGH);
        
        
          // set the cursor to column 0, line 1
         // (note: line 1 is the second row, since counting begins with 0):   
         lcd.setCursor(0,1); 
       
         // clear line first...
         lcd.print("                ");
         lcd.setCursor(0,1); 
         lcd.print("Pressed Button 1"); 
       
       btnPressed1 = true;
   }  
  }
  else  if (buttonPin2.isPressed() ) {   

    if(btnPressed2 == false)
    {
       // Serial.println( " in pressed2, state: ");
        //  Serial.println(btnPressed2);

     // turn LED on:    
        digitalWrite(ledPin2, HIGH);
        
        digitalWrite(buzzer,HIGH);
        
        
          // set the cursor to column 0, line 1
         // (note: line 1 is the second row, since counting begins with 0):   
         lcd.setCursor(0,1); 
       
         // clear line first...
         lcd.print("                ");
         lcd.setCursor(0,1); 
         lcd.print("Pressed Button 2");  
        
        btnPressed2 = true; 
    }
  }
  else if (buttonPin3.isPressed() ) { 
 
    if (btnPressed3 == false)
    {
          //Serial.println(" in pressed3, state: ");
          // Serial.println(btnPressed3);

   
     // turn LED on:    
        digitalWrite(ledPin3, HIGH);
        
        digitalWrite(buzzer,HIGH);
        
        
          // set the cursor to column 0, line 1
         // (note: line 1 is the second row, since counting begins with 0):   
         lcd.setCursor(0,1); 
       
         // clear line first...
         lcd.print("                ");
         lcd.setCursor(0,1); 
         lcd.print("Pressed Button 3");   

         btnPressed3 = true; 
    }

  }
  else  if (buttonPin4.isPressed() ) {    
    
    if(btnPressed4 == false)
    {
      //    Serial.println(" in pressed4, state: ");
            //  Serial.println(btnPressed4);


     // turn LED on:    
        digitalWrite(ledPin4, HIGH);
        
        digitalWrite(buzzer,HIGH);
        
        
          // set the cursor to column 0, line 1
         // (note: line 1 is the second row, since counting begins with 0):   
         lcd.setCursor(0,1); 
       
         // clear line first...
         lcd.print("                ");
         lcd.setCursor(0,1); 
         lcd.print("Pressed Button 4");  
        
        btnPressed4 = true;
    } 
  }
  else {
    
    
    if(btnPressed1 == true)
    {
       // turn LED off:
        digitalWrite(ledPin1,LOW);
        digitalWrite(buzzer,LOW);

        lcd.setCursor(0,1); 
        lcd.print("                ");
        lcd.setCursor(0,1); 
        lcd.print("0 Button pressed");
        
        btnPressed1 = false;
    }
    
    if(btnPressed2 == true)
    {
       // turn LED off:
        digitalWrite(ledPin2,LOW);
        digitalWrite(buzzer,LOW);

        lcd.setCursor(0,1); 
        lcd.print("                ");
        lcd.setCursor(0,1); 
        lcd.print("0 Button pressed");
        btnPressed2 = false;
    } 
    
    if (btnPressed3 == true)
    {
        digitalWrite(ledPin3,LOW);
        digitalWrite(buzzer,LOW);

        lcd.setCursor(0,1); 
        lcd.print("                ");
        lcd.setCursor(0,1); 
        lcd.print("0 Button pressed");
        
        btnPressed3 = false;
    }
      
     if(btnPressed4 == true)
     {
        digitalWrite(ledPin4,LOW);
        digitalWrite(buzzer,LOW);

        lcd.setCursor(0,1); 
        lcd.print("                ");
        lcd.setCursor(0,1); 
        lcd.print("0 Button pressed");  
        
        btnPressed4 = false;
     }
  }  
  
}

