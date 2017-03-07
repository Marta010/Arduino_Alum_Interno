int trigger=7; //”trigger” on pin 7.
int echo=6; //”echo” on pin 6.
long time=0; //The value “time” will safe the time between transmission and
//returning of the soundwave.
long dist=0; //The value “dist” will save the calculated distance. It will
//start with “0”. Instead of “int” we are using “long” for this value, to save a
//bigger number.
int piezo=5;//piezo speaker in 5
int VER=21;
int AM=20;
int RO=19;
int led=0;
boolean control=false;
int prev=0;


void setup()
{
Serial.begin (9600); //Starting the serial communication. It will send the
//data from the arduino board to the computer to show it on the serial monitor.
pinMode(trigger, OUTPUT); //”trigger” (Pin 7) is an output.
pinMode(echo, INPUT); //”echo” (Pin 6) is an input.
pinMode(piezo, OUTPUT);
pinMode(VER,OUTPUT);
pinMode(AM,OUTPUT);
pinMode(RO,OUTPUT);
}
void loop()
{
digitalWrite(trigger, LOW); //Low voltage on the trigger pin to produce a
//clear signal.
delay(5); //….for 5 milliseconds.
digitalWrite(trigger, HIGH); //Creating the soundwave.
delay(10); //..for 10 milliseconds.
digitalWrite(trigger, LOW); //Stop creating the soundwave.

time = pulseIn(echo, HIGH); //With the command pulseIn (Capital “i” in the
//front of the “n”) the arduino board measures the time between sending and
//receiving the soundwave.
dist = (time/2) / 29.1; //This calculation transforms the measured time into
//the distance in centimeter. (The sound needs 29,1 seconds for one centimeter.
//The time gets divided with two, because we only want to get one distance and
//not the two ways that the soundwave has to take).


if (dist <=10){
  digitalWrite(piezo,HIGH);
  if(prev > 10){
    control = true;
    led = 19;
  }
  
  Serial.println("Que te la pegas, zoquete!!!!");

}
else if(dist >= 50){
   if(prev < 50){
    control = true;
    led = 21;
   }
  digitalWrite(piezo,LOW);
  Serial.println("Pa que quieres un sensor? Si estas to lejos...");
}
else //otherwise
{
Serial.print(dist); //The calculated distance is shown on the serial monitor.
Serial.println("cm");
}

if (dist <50 && dist > 10){
 //  if(prev > 50 || prev < 10){
    control = true;
    led = 20;
  // }
  digitalWrite(piezo,HIGH);
  delay (dist*10);
  digitalWrite(piezo,LOW);
}
prev = dist;
asd();
}
void asd(){
    if(control==true){
      digitalWrite(19,LOW);
      digitalWrite(20,LOW);
      digitalWrite(21,LOW);
      digitalWrite(led,HIGH);
   

      control = false;
    }
//    loop();
  
}

