const int LED1 = 11;
const int LED2 = 12;
const int LED3 = 13;

const int BUTTON1 = 8;
const int BUTTON2 = 9;
const int BUTTON3 = 10;

const unsigned long HOLD_TIME = 1000;
const unsigned long RELEASE_DELAY = 500;

unsigned long button1Start = 0;
unsigned long button2Start = 0;
unsigned long button3Start = 0;

unsigned long button1Release = 0;
unsigned long button2Release = 0;
unsigned long button3Release = 0;

bool led1On = false;
bool led2On = false;
bool led3On = false;

bool button1Triggered = false;
bool button2Triggered = false;
bool button3Triggered = false;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

void loop() {
  unsigned long now = millis();

  bool button1 = digitalRead(BUTTON1) == LOW;
  bool button2 = digitalRead(BUTTON2) == LOW;
  bool button3 = digitalRead(BUTTON3) == LOW;

  // BUTTON 1
  if (button1) {
    if (button1Start == 0) {
      button1Start = now;
    }

    button1Release = 0;

    if (!button1Triggered && now - button1Start >= HOLD_TIME) {
      led1On = true;
      button1Triggered = true;
      digitalWrite(LED1, HIGH);
    }
  } else {
    if (button1Triggered && button1Release == 0) {
      button1Release = now;
    }

    if (button1Release != 0 && now - button1Release >= RELEASE_DELAY) {
      led1On = false;
      button1Triggered = false;
      button1Start = 0;
      button1Release = 0;
      digitalWrite(LED1, LOW);
    }

    if (!button1Triggered) {
      button1Start = 0;
      button1Release = 0;
    }
  }

  // BUTTON 2
  if (button2) {
    if (button2Start == 0) {
      button2Start = now;
    }

    button2Release = 0;

    if (!button2Triggered && now - button2Start >= HOLD_TIME) {
      led2On = true;
      button2Triggered = true;
      digitalWrite(LED2, HIGH);
    }
  } else {
    if (button2Triggered && button2Release == 0) {
      button2Release = now;
    }

    if (button2Release != 0 && now - button2Release >= RELEASE_DELAY) {
      led2On = false;
      button2Triggered = false;
      button2Start = 0;
      button2Release = 0;
      digitalWrite(LED2, LOW);
    }

    if (!button2Triggered) {
      button2Start = 0;
      button2Release = 0;
    }
  }

  // BUTTON 3
  if (button3) {
    if (button3Start == 0) {
      button3Start = now;
    }

    button3Release = 0;

    if (!button3Triggered && now - button3Start >= HOLD_TIME) {
      led3On = true;
      button3Triggered = true;
      digitalWrite(LED3, HIGH);
    }
  } else {
    if (button3Triggered && button3Release == 0) {
      button3Release = now;
    }

    if (button3Release != 0 && now - button3Release >= RELEASE_DELAY) {
      led3On = false;
      button3Triggered = false;
      button3Start = 0;
      button3Release = 0;
      digitalWrite(LED3, LOW);
    }

    if (!button3Triggered) {
      button3Start = 0;
      button3Release = 0;
    }
  }
}