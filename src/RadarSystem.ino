#include <Servo.h>

const int trigPin = 4;
const int echoPin = 5;
const int buzzerPin = 8;      // buzzer ka pin

// ---- Tunable settings ----
const int MAX_VALID_CM   = 400;   // HC-SR04 ki max reliable range
const int MIN_VALID_CM   = 2;     // HC-SR04 ki min reliable range
const int NO_OBJECT_CM   = 999;   // "koi object nahi mila" ke liye placeholder
const int ALERT_RANGE_CM = 40;    // isse zyada dur ho to buzzer bilkul na baje (Processing bhi 40cm tak hi dikhata hai)
const int CLOSE_CM       = 15;    // isse kam ho to fast/loud beep
const int NEAR_CM        = 30;    // isse kam ho to medium beep
const int DEBOUNCE_COUNT = 2;     // itni consecutive "close" readings ke baad hi buzzer trigger ho

long duration;
Servo myServo;
int closeCount = 0;   // consecutive close-reading counter (debounce)

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  noTone(buzzerPin);
  Serial.begin(9600);
  myServo.attach(10);
}

void loop() {
  for (int i = 15; i <= 165; i++) {
    myServo.write(i);
    delay(30);
    int distance = getStableDistance();
    buzzerAlert(distance);

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }

  for (int i = 165; i > 15; i--) {
    myServo.write(i);
    delay(30);
    int distance = getStableDistance();
    buzzerAlert(distance);

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

// ---- Single raw reading, with timeout + range check ----
int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 20000us timeout ~= 3.4m range. Agar echo na mile to 0 milega (hang nahi hoga).
  duration = pulseIn(echoPin, HIGH, 20000UL);

  if (duration == 0) {
    return NO_OBJECT_CM;   // koi echo nahi mila -> no object
  }

  int d = duration * 0.034 / 2;

  if (d < MIN_VALID_CM || d > MAX_VALID_CM) {
    return NO_OBJECT_CM;   // sensor ke reliable range se bahar -> ignore/garbage
  }

  return d;
}

// ---- Noise filter: 3 readings ka median leke ek stable value dena ----
int getStableDistance() {
  int r1 = calculateDistance();
  int r2 = calculateDistance();
  int r3 = calculateDistance();

  int maxV = max(r1, max(r2, r3));
  int minV = min(r1, min(r2, r3));
  int median = r1 + r2 + r3 - maxV - minV;

  return median;
}

// ---- Buzzer logic with debounce, taaki ek random spike buzzer trigger na kare ----
void buzzerAlert(int dist) {
  bool inAlertRange = (dist > 0 && dist <= ALERT_RANGE_CM);

  if (inAlertRange) {
    closeCount++;
  } else {
    closeCount = 0;
  }

  // Jab tak DEBOUNCE_COUNT baar continuously object range me na mile, buzzer band rahega
  if (closeCount < DEBOUNCE_COUNT) {
    noTone(buzzerPin);
    return;
  }

  if (dist < CLOSE_CM) {
    tone(buzzerPin, 2000);        // bahut close -> tez, high pitch, continuous
  } else if (dist < NEAR_CM) {
    tone(buzzerPin, 1000);        // medium close -> medium pitch
  } else {
    tone(buzzerPin, 500);         // range ke andar par thoda dur -> low pitch
  }
}
