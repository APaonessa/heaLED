#include <MyoController.h>
#include <Adafruit_NeoPixel.h>

#define FIST_PIN 7
#define WAVEIN_PIN 5
#define WAVEOUT_PIN 10
#define FINGERSSPREAD_PIN 9
#define DOUBLETAP_PIN 8
#define PIN 6  //Green
#define N_LEDS 16
#define buzzer1  2
#define buzzer2  4

MyoController myo = MyoController();
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
  pinMode(FIST_PIN, OUTPUT);
  pinMode(WAVEIN_PIN, OUTPUT);
  pinMode(WAVEOUT_PIN, OUTPUT);
  pinMode(FINGERSSPREAD_PIN, OUTPUT);
  pinMode(DOUBLETAP_PIN, OUTPUT);
 // pinMode (buzzer1, OUTPUT);
 // pinMode (buzzer2, OUTPUT);

  strip.begin();

  myo.initMyo();

}

void loop() {
  // put your main code here, to run repeatedly:
  myo.updatePose();
  switch (myo.getCurrentPose() ) {
    case rest:
      digitalWrite(FIST_PIN, LOW);
      digitalWrite(WAVEIN_PIN, LOW);
      digitalWrite(WAVEOUT_PIN, LOW);
      digitalWrite(FINGERSSPREAD_PIN, LOW);
      digitalWrite(DOUBLETAP_PIN, LOW);
      flash(strip.Color(0, 0, 0));


      break;

    case fist:
      flash(strip.Color(255, 200, 0)); // Red
      break;
    case waveIn:
      chase(strip.Color(0, 255, 0)); // Green
      break;
    case waveOut:
      chase2(strip.Color(255, 0, 0)); // Red
      break;
    case fingersSpread:
      chase(strip.Color(250, 30, 70)); //Hot Pink?
      break;
    case doubleTap:
      chase(strip.Color(0, 200, 250)); //Teal?

      break;
  }
  delay(25);
}

static void chase(uint32_t c) {
 // noTone(buzzer1);
  for (uint16_t i = 0; i < strip.numPixels() + 4; i++) {
   // tone(buzzer1, 349.23, 500); //F
    //delay(500);

    strip.setPixelColor(i  , c); // Draw new pixel
    //tone(buzzer1, 392.00, 500); //G
    //delay(500);
    strip.setPixelColor(i + 4, 0); // Erase pixel a few steps back
    //tone(buzzer1, 493.88, 500); //B
    //delay(500);

    strip.show();
    //tone(buzzer1, 392.00, 500); //G
    //delay(500);
    delay(25);
  }
}



static void chase2(uint32_t c) {
 // noTone(buzzer1);
  for (uint16_t i = 0; i < strip.numPixels() + 4; i++) {
   // tone(buzzer1, 293.66, 500); //D
   // delay(500);

    strip.setPixelColor(i  , c); // Draw new pixel
   // tone(buzzer1, 293.66, 250); //D
   // delay(250);
   // tone(buzzer1, 246.94, 250); //B
   // delay(250);

    strip.setPixelColor(i + 4, 0); // Erase pixel a few steps back
    //tone(buzzer1, 293.66, 500); //D
    //delay(500);

    strip.show();
    //tone(buzzer1, 246.94, 500); //B
    //delay(500);

    delay(25);
  }

}

static void chase3(uint32_t c) {
  //noTone(buzzer1);
  for (uint16_t i = 0; i < strip.numPixels() + 4; i++) {
    //tone(buzzer1, 493.88, 250); //high B
    //delay(250);

    strip.setPixelColor(20 - i  , c); // Draw new pixel
    //tone(buzzer1, 523.25, 250); //C
   // delay(250);
   // tone(buzzer1, 329.63, 250); //E
   // delay(250);
    strip.setPixelColor(i + 4, 0); // Erase pixel a few steps back
   // tone(buzzer1, 493.88, 250); //high B
    //delay(240);
   // tone(buzzer1, 493.88, 250); //high B
    //delay(250);

    strip.show();
    //tone(buzzer1, 523.25, 750); //C

    delay(25);
  }
}
static void flash(uint32_t c) {
  //noTone(buzzer1);
  for (uint16_t i = 0; i < strip.numPixels() + 4; i++) {
    //tone(buzzer1, 440.00, 250); //A
    //delay(250);
    //tone(buzzer1, 349.23, 250); //F
    //delay(250);

    strip.setPixelColor(i  , c); // Draw new pixel
    //tone(buzzer1, 293.66, 250); //D
    //delay(250);
    //tone(buzzer1, 440.00, 250); //A
    //delay(250);

    strip.setPixelColor(i - 4, 0); // Erase pixel a few steps back
    //tone(buzzer1, 392.00, 250); //G
    //delay(250);
    //tone(buzzer1, 329.63, 250); //E
    //delay(250);

    strip.show();
    //tone(buzzer1, 261.63, 250); //Middle C
    //delay(250);
    //tone(buzzer1, 392.00, 250); //G;

    delay(1);
  }

}
static void chaseWait(uint32_t c) {
  //noTone(buzzer1);
  for (uint16_t i = 0; i < strip.numPixels() + 4; i++) {
    //tone(buzzer1, 261.63, 500); //Middle C
    //delay(500);
    //tone(buzzer1, 349.23, 500); //F
    //delay(500);

    strip.setPixelColor(i % 20, c++); // Draw new pixel
    //tone(buzzer1, 261.63, 500); //Middle C
    //delay(500);
    //tone(buzzer1, 174.61, 500); //low F
    //delay(500);

    strip.show();
    delay(10);
  }
}

