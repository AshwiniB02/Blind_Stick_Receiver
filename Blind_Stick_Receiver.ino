#include <Gyver433.h>

Gyver433_RX<2, 20> rx;
Gyver433_TX<3> tx;
char data[] = "ALERT";

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(0, isr, CHANGE);
}

void isr() {
  rx.tickISR();
}


void loop() {
  if (rx.gotData()) {
    char data[10];
    Serial.println("Got data");
    if (data == "ALERT") {
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
    }
  }
}
