void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10); // SerialでのString受信のタイムアウト設定（ms）

  pinMode(3, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String key = Serial.readStringUntil(';');
    key.trim();
    //Serial.print("receive : ");
    Serial.println(key);

    if (key == "a") {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  }

 delay(100);
}
