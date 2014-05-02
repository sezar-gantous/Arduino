#include <Button.h>

/*
4 buttons with 4 coresponding LEDs 

*/


Button buttonPin1 = Button(2); // the number of the pushbutton pin
Button buttonPin2 = Button(3);
Button buttonPin3 = Button(4);
Button buttonPin4 = Button(5);


 int ledPin1 =  6;      // the number of the LED pin
 int ledPin2 =  7;
 int ledPin3 =  8;
 int ledPin4 =  9;




void btnCheck(Button btn, int led)
{
  
  if (btn.isPressed()) {    
    // turn LED on:    
    digitalWrite(led, HIGH);  
  }
  else {
    // turn LED off:
    digitalWrite(led, LOW);
  }  
}



void setup() 
{
  
  
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);      
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  
}




void loop()
{
  // read the state of the pushbutton value:
  btnCheck(buttonPin1,ledPin1);
  btnCheck(buttonPin2,ledPin2);
  btnCheck(buttonPin3,ledPin3);
  btnCheck(buttonPin4,ledPin4);
 
 
 /*
 if (buttonPin1.isPressed()) {    
    // turn LED on:    
    digitalWrite(ledPin1, HIGH);  
  }
  else {
    // turn LED off:
    digitalWrite(ledPin1, LOW);
  }  
  
  
  
  
   if (buttonPin2.isPressed()) 
  {    
    // turn LED on:    
    digitalWrite(ledPin2, HIGH);  
  }
  else
  {
    digitalWrite(ledPin2, LOW);

  }
  
  
  
   if (buttonPin3.isPressed()) {    
    // turn LED on:    
    digitalWrite(ledPin3, HIGH);  
  }
  else {
    // turn LED off:
    digitalWrite(ledPin3, LOW);
  } 
  
  
  
   if (buttonPin4.isPressed()) {    
    // turn LED on:    
    digitalWrite(ledPin4, HIGH);  
  }
  else {
    // turn LED off:
    digitalWrite(ledPin4, LOW);
  } 
  */
  
}
