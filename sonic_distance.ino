// defines pins numbers

#define TRIGGER 5
#define ECHO    4
#define TRIGGER2 0
#define ECHO2 2
 
// NodeMCU Pin D1 > TRIGGER | Pin D2 > ECHO
 
void setup() {
  
  Serial.begin (9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
}
 
void loop() {
  
  float duration, duration2, distance, distance2;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;/*(duration/2) / 29.1;*/

//  delayMicroseconds(100);
 // Serial.print(distance);
//  Serial.println("Centimeter: ");
   digitalWrite(TRIGGER2, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER2, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER2, LOW);
  duration2 = pulseIn(ECHO2, HIGH);
  distance2 = ((float)(340 * duration2) / 10000) / 2;/*(duration2/2) / 29.1;*/

  Serial.print(distance);
  Serial.print("Centimeter: ,");
  Serial.print(distance2);
  Serial.println("Centimeter:");
  delay(1000);
}
