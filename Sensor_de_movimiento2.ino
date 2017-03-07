int piezo=5; //The word “piezo” stands for the value 5.
int movement=7; //The word “movement” stands for the value 7.
int movementstatus=0; //The word “movementstatus” stands for the value 0. Later
int led=12;
//on there will be saved if a movement is detected or not
void setup()
{ //The setup starts here
pinMode(piezo, OUTPUT); //The pin connected to the piezo speaker (pin 5) is
//defined as an output.
pinMode(led,OUTPUT);

pinMode(movement, INPUT); //The pin connected to the moition detector (pin 7)is
//defined as an input.
}
void loop()
{ //The loop part starts here
movementstatus=digitalRead(movement); //The value on pin 7 is read out
//(command: digitalRead). The result will be safed under “movementstatus”. (HIGH
//means 5V and LOW means 0V)
if(movementstatus==HIGH) //if a movement is detected (voltage signal high) ..
{ //open program part of the IF-command

digitalWrite(piezo,HIGH);
digitalWrite(led,HIGH);//..the piezo should beep
delay(500); //5 seconds long
digitalWrite(piezo, LOW);
digitalWrite(led,LOW);
delay(500);
//after that the piezo should be quiet
} //close program part of the IF-command
else
{ //open else-command
digitalWrite(piezo,LOW); //the piezo speaker should be turned off
} //close else-command
} //close loop part

