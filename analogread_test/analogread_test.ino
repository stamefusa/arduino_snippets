void setup() {
  Serial.begin(9600);
}
 
void loop() {  
  int val = getPercentage();
  Serial.println(val);
  delay(50);
}

int getPercentage()
{
  int val = analogRead(A0);
  int result = 0;
  if (val < 25) {
    val = 0; 
  } else if (val >= 25 && val < 33) {
    val = 1;
  } else if (val >= 33 && val < 55) {
    val = 2;
  } else if (val >= 55 && val < 77) {
    val = 3;
  } else if (val >= 77 && val < 108) {
    val = 4;
  } else if (val >= 108 && val < 210) {
    val = 5;
  } else if (val >= 210 && val < 250) {
    val = 6;
  } else if (val >= 250 && val < 400) {
    val = 7;
  } else if (val >= 400 && val < 670) {
    val = 8;
  } else if (val >= 670 && val < 760) {
    val = 9;
  } else if (val >= 760) {
    val = 10;
  }

  return val;
}
