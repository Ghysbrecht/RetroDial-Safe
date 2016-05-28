        //          1  2   3   4   5   6   7   8  9
const int dig[] = {A0, A1, A2, A3, A4, A5, 12, 2, 3 };
const int nrs[] = {A6,A7,4,5,6,7,8,9,10,11};
        //         0  1  2 3 4 5 6 7 8  9

unsigned long number;

void setup() {
  Serial.begin(9600); 

  //Setting the in and outputs
  int i;
  for(i = 0; i < 9; i++){
    pinMode(dig[i], OUTPUT);
    digitalWrite(dig[i], LOW);
  }
  for(i = 0; i < 10; i++){
    pinMode(nrs[i], INPUT);
  }
  
}
void loop() {


                                                                               
  number = getNumber();
                                                                               Serial.print("Value is: ");
                                                                              
  Serial.println(number,DEC);
  delay(100);

}


//General function that return the number on the dial thingy
unsigned long getNumber(){
  int number[9];
  int i, numbers;
  unsigned long completeNumber = 0, powerNumber, additionNumber;
  
  for(i=1;i<10;i++){ 
     number[i] = getValueOfDigit(i);
     powerNumber = pow(10, (9-i));
     additionNumber = number[i] * powerNumber;  
     completeNumber = completeNumber + additionNumber;

                                                                                /*   Serial.println("In getNumber part:");
                                                                                   Serial.print("Number I: ");
                                                                                   Serial.println(i,DEC);
                                                                                   Serial.print("Value got from other function: ");
                                                                                   Serial.println(number[i]);
                                                                                   Serial.print("powerNumber: ");
                                                                                   Serial.println(powerNumber,DEC);
                                                                                   Serial.print("additionNumber: ");
                                                                                   Serial.println(additionNumber,DEC);
                                                                                   Serial.print("completeNumber: ");
                                                                                   Serial.println(completeNumber,DEC);
                                                                                  Serial.println("");*/
                                                                                   
                                                                                   
  }
  return completeNumber; 
}


//Asking the value of a digit
int getValueOfDigit(int digit){
  int value = 0, buttonState, completedSucces = 0, stillOk = 0;
                                                                  // Serial.println("In the getValueOfDigit function: ");
  digitalWrite(dig[digit-1], HIGH);
                                                                   //Serial.print("This pin is set to HIGH: ");     
                                                                   //Serial.println(dig[digit-1]);    
  for(int i = 0; i < 10; i++){
      
                                                                 //  Serial.print("Reading pin: ");     
                                                                 //  Serial.println(nrs[i]); 
      if( nrs[i] == 20 || nrs[i] == 21 ){
        int data = analogRead(nrs[i]);
                                                                  // Serial.println("This is an analog pin!");
                                                                  // Serial.print("Analog value: ");
                                                                  // Serial.println(data,DEC);
        if(data > 500){
          stillOk = 1;                                             
                                                                  // Serial.println("This pin is high");
        }
      }
      else{
        buttonState = digitalRead(nrs[i]);
      }

                                                                   
                                                                  

      
      if (buttonState == HIGH || stillOk == 1){      
                                                                //  Serial.print("stillOk = ");
                                                                 // Serial.println(stillOk,DEC);
                                                                 // Serial.print("Buttonstate: ");
                                                                 // Serial.println(buttonState);
        value = i;
        stillOk = 0;
        buttonState = LOW;
        completedSucces = 1;
                                                                  //Serial.print("FOUND A NUMBER! THE NUMBER IS: ");
                                                                  // Serial.println(i);
        i = 10;
      }
  }
  if(completedSucces == 0){
    completedSucces = 0;
    value = 0;         
                                                                  // Serial.println("*ERROR* No number found! Value set to 0");
  }

  delay(10);
  digitalWrite(dig[digit-1], LOW);
                                                                  /* Serial.print("This pin is set to LOW: ");
                                                                   Serial.println(dig[digit-1]); 
                                                                   Serial.print("The loop has ended, the value I will return is: ");
                                                                   Serial.println(value,DEC);
                                                                   Serial.println("");*/
                                                                  
  
  
  return value;
}
