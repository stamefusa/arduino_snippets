// ピンと光る7セグの対応
// 右下：6 左下：7 下：8 中央：9 左上：10 右上：11 上：12

boolean num_array[10][7] = {
  {0, 0, 0, 1, 0, 0, 0}, // 0ok
  {0, 1, 1, 1, 1, 0, 1}, // 1ok
  {1, 0, 0, 0, 1, 0, 0}, // 2ok
  {0, 1, 0, 0, 1, 0, 0}, // 3ok
  {0, 1, 1, 0, 0, 0, 1}, // 4ok
  {0, 1, 0, 0, 0, 1, 0}, // 5ok
  {0, 0, 0, 0, 0, 1, 0}, // 6ok
  {0, 1, 1, 1, 0, 0, 0}, // 7ok
  {0, 0, 0, 0, 0, 0, 0}, // 8ok
  {0, 1, 0, 0, 0, 0, 0} // 9ok
};

int digit_1 = 5; // 1の桁
int digit_10 = 4; // 10の桁
int digit_100 = 3; // 100の桁
int digit_1000 = 2; // 1000の桁

int del = 3; // ディレイ

void numPrint(int num) {
  for (int j=0; j<=6; j++) {
    digitalWrite(j+6, num_array[num][j]);
  }
}

void setup() {
  pinMode(digit_1, OUTPUT); // 光る桁
  pinMode(digit_10, OUTPUT); // 光る桁
  pinMode(digit_100, OUTPUT); // 光る桁
  pinMode(digit_1000, OUTPUT); // 光る桁
  for (int i=6; i<=12; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // 1の桁
  digitalWrite(digit_10, 0);
  digitalWrite(digit_100, 0);
  digitalWrite(digit_1000, 0);
  digitalWrite(digit_1, 1);
  numPrint(5);
  delay(del);
  
  // 10の桁
  digitalWrite(digit_1, 0);
  digitalWrite(digit_100, 0);
  digitalWrite(digit_1000, 0);
  digitalWrite(digit_10, 1);
  numPrint(1);
  delay(del);
  
  // 100の桁
  digitalWrite(digit_1, 0);
  digitalWrite(digit_10, 0);
  digitalWrite(digit_1000, 0);
  digitalWrite(digit_100, 1);
  numPrint(9);
  delay(del);
  
  // 1000の桁
  digitalWrite(digit_1, 0);
  digitalWrite(digit_10, 0);
  digitalWrite(digit_100, 0);
  digitalWrite(digit_1000, 1);
  numPrint(6); 
  delay(del);
}
