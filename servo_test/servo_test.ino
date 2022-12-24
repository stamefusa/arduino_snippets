#include <Servo.h>

Servo s;
int val = 90;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10); // SerialでのString受信のタイムアウト設定（ms）

  // サーボピン初期化
  s.attach(7);
}

/*
 * はじめに90度の位置になり、aとbを押すと10度ずつ正転・逆転
 */
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String key = Serial.readStringUntil(';');
    key.trim();
    Serial.println(key);

    if (key == "a" && val < 170) {
      val += 10;
    } else if (key == "b" && val > 10) {
      val -= 10;
    }
  }

  Serial.println(val);
  s.write(val);

  delay(100);
}
