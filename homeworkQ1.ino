#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
	SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
	SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
	SEG_C | SEG_E | SEG_G,                           // n
	SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
	};

TM1637Display display(CLK, DIO);

#define numberOfSeconds(_time_) ((_time_ / 1000) % 60)
#define numberOfMinutes(_time_) ((_time_ / 1000) / 60)
// hold time selected in ms.
unsigned long timeLimit = 600000; // 타이머 시간 입력 10분

void setup() {

  Serial.begin(115200);
  delay(50);
  Serial.println("-----------Timer Arduino Comms up------------");

  display.setBrightness(5);    // LED 밝기조정   0~6
  display.showNumberDecEx(0, 0x40, true);

}

void loop() {

 for (long i = timeLimit; i > 0; i=i-1000)   // 1초씩 감소
 
  { 

    int seconds = numberOfSeconds(i);
    int minutes = numberOfMinutes(i);
    Serial.println(i);
    
    display.showNumberDecEx(seconds, 0, true, 2, 2) ;  // 초 표시
    display.showNumberDecEx(minutes, (0x80 >> 1), true, 2, 0) ;  // 분, : 표시
    
    delay(1000);   

  }
      
   display.setSegments(SEG_DONE);
   delay(2000);
   timeLimit = 0;
  
  }
