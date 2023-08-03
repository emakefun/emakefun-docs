#define DIR1 4  // define direction 4 port
#define PWM1 5  // define pwm1 5 port
#define DIR2 7  // define direction 7 port
#define PWM2 6  // define pwm2 6 port

void setup() {
  Serial.begin(115200);
  Serial.println("Starting......");
  pinMode(DIR1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(PWM2, OUTPUT);

}

void loop() {
  // forward speed 255
  Serial.println("M1,M2 Forward");
  
  digitalWrite(DIR1, HIGH);
  analogWrite(PWM1, 255);
  digitalWrite(DIR2, HIGH);
  analogWrite(PWM2, 255);
  delay(1000);
  // reversal speed 255
  Serial.println("M1,M2 Reversal");
  digitalWrite(DIR1, LOW);
  analogWrite(PWM1, 255);
  digitalWrite(DIR2, LOW);
  analogWrite(PWM2, 255);
  delay(1000);
  // Stop speed 255
  Serial.println("M1,M2 Stop");
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);
  delay(1000); 
}
