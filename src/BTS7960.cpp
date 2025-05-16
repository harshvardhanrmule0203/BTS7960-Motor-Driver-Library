#include "BTS7960.h"

BTS7960::BTS7960(int l, int r)
  : lpwm(l), rpwm(r), Renb(-1), Lenb(-1), enableUse(false) {
  pinMode(lpwm, OUTPUT);
  pinMode(rpwm, OUTPUT);
}

BTS7960::BTS7960(int l, int r, int enbA, int enbB)
  : lpwm(l), rpwm(r), Lenb(enbA), Renb(enbB), enableUse(true) {
  pinMode(lpwm, OUTPUT);
  pinMode(rpwm, OUTPUT);
  pinMode(Lenb, OUTPUT);
  pinMode(Renb, OUTPUT);

  digitalWrite(Lenb, HIGH);
  digitalWrite(Renb, HIGH);
}

void BTS7960::rotate(int pwm) {
  pwm = constrain(pwm, -255, 255);
  if (pwm > 0) {
    analogWrite(lpwm, pwm);
    analogWrite(rpwm, 0);
  } else if (pwm < 0) {
    analogWrite(lpwm, 0);
    analogWrite(rpwm, -pwm);
  } else {
    stop();
  }
}

void BTS7960::stop() {
  analogWrite(lpwm, 0);
  analogWrite(rpwm, 0);
}

void BTS7960::setEnable(bool state) {
  if (enableUse) {
    digitalWrite(Lenb, state ? HIGH : LOW);
    digitalWrite(Renb, state ? HIGH : LOW);
  }
}

void BTS7960::test(int pwm) {
  Serial.println("Testing the BTS7960 Motor Driver & printing pins");

  Serial.println(String("LPWM: ") + lpwm);
  Serial.println(String("RPWM: ") + rpwm);

  if (enableUse) {
    Serial.println(String("Enable R: ") + Renb);
    Serial.println(String("Enable L: ") + Lenb);
  }

  Serial.println("Forward: ");
  for (int i = 0; i <= pwm; i++) {  // Smoother increase
    rotate(i);
    Serial.println(i);
    delay(300);
  }
  stop();
  delay(2000);

  Serial.println("Reverse: ");
  for (int i = 0; i >= -pwm; i--) {
    rotate(i);
    Serial.println(i);
    delay(300);
  }
  stop();
}