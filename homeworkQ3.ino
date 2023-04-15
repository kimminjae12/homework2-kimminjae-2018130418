int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10}; // LED 핀 번호 배열
int numLeds = 9; // LED 개수
int delayTime = 200; // 딜레이 시간

void setup() {
  // LED 핀들을 출력으로 설정
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // 왼쪽에서 오른쪽으로 3번 왕복
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < numLeds; j++) {
      digitalWrite(ledPins[j], HIGH); // LED 켜기
      delay(delayTime); // 딜레이
      digitalWrite(ledPins[j], LOW); // LED 끄기
    }
    for (int j = numLeds - 2; j >= 0; j--) {
      digitalWrite(ledPins[j], HIGH); // LED 켜기
      delay(delayTime); // 딜레이
      digitalWrite(ledPins[j], LOW); // LED 끄기
    }
  }
  // 랜덤패턴
  for (int i = 0; i < 5; i++) { // 랜덤 패턴을 5번 반복
    for (int j = 0; j < 9; j++) {
      int value = random(2); // 0 또는 1 값을 랜덤으로 선택
      digitalWrite(ledPins[j], value);
    }
    delay(400);
  }
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], LOW);
  digitalWrite(ledPins[4], LOW);
  digitalWrite(ledPins[5], LOW);
  digitalWrite(ledPins[6], LOW);
  digitalWrite(ledPins[7], LOW);
  digitalWrite(ledPins[8], LOW);
  delay(200);
  // 갈때는 홀수 LED 올때는 짝수 LED만 켜지는 패턴
  for (int i = 0; i < 3; i++) {
    // 왼쪽으로 이동
    for (int j = 0; j < numLeds; j += 2) {
      digitalWrite(ledPins[j], HIGH); // LED 켜기
      delay(delayTime); // 딜레이
      digitalWrite(ledPins[j], LOW); // LED 끄기
    }
    // 오른쪽으로 이동
    for (int j = numLeds - 2; j >= 0; j -= 2) {
      digitalWrite(ledPins[j], HIGH); // LED 켜기
      delay(delayTime); // 딜레이
      digitalWrite(ledPins[j], LOW); // LED 끄기
    }
  }
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], LOW);
  digitalWrite(ledPins[4], LOW);
  digitalWrite(ledPins[5], LOW);
  digitalWrite(ledPins[6], LOW);
  digitalWrite(ledPins[7], LOW);
  digitalWrite(ledPins[8], LOW);
  delay(10000);
}
