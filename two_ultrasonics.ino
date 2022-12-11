#define TRIG1 33
#define ECHO1 32
#define LED_IN 25

#define TRIG2 27
#define ECHO2 26
#define LED_OUT 14

float distance1, distance2;
int headcounter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG1, OUTPUT);
  pinMode(TRIG2, OUTPUT); 
  pinMode(ECHO1, INPUT);
  pinMode(ECHO2, INPUT); 
  pinMode(LED_IN, OUTPUT);
  pinMode(LED_OUT, OUTPUT);

  Serial.begin(115200);
}

float read_ultrasonic1(){
  digitalWrite(TRIG1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG1, HIGH);
  delayMicroseconds(2);
  digitalWrite(TRIG1, LOW);

  float duration1 = pulseIn(ECHO1, HIGH);
  float distance1 = 0.0343 * (duration1/2);

  if(distance1 < 30){
    digitalWrite(LED_IN, HIGH);
    headcounter += 1;
  } else{
    digitalWrite(LED_IN, LOW);
  }

  return distance1;
}

float read_ultrasonic2(){
  digitalWrite(TRIG2,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG2,HIGH);
  delayMicroseconds(2);
  digitalWrite(TRIG2,LOW);

  float duration2 = pulseIn(ECHO2,HIGH);
  float distance2 = 0.0343 * (duration2/2);

  if(distance2 < 30){
    digitalWrite(LED_OUT, HIGH);
    headcounter -= 1;
  } else{
    digitalWrite(LED_OUT, LOW);
  }

  return distance2;
}

void loop() {
  distance1 = read_ultrasonic1();
  // Serial.print("Sensor 1 : ");
  // Serial.println(distance1);

  delayMicroseconds(2);

  distance2 = read_ultrasonic2();
  // Serial.print("Sensor 2 : ");
  // Serial.println(distance2);

  Serial.println(headcounter);
}
