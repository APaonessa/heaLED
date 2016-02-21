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
  pinMode (buzzer1, OUTPUT);
  pinMode (buzzer2, OUTPUT);


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
    noTone(buzzer1);
    chase(strip.Color(0, 0, 0));
    
    
    break; 
    
    case fist:
      noTone(buzzer1);
      tone(buzzer1, 440.00); //A
      flash(strip.Color(255, 0, 0)); // Red 
      break; 
    case waveIn: 
     noTone(buzzer1);
     tone(buzzer1, 293.66); //D
     chase(strip.Color(0, 255, 0)); // Green 
      break; 
    case waveOut:
      noTone(buzzer1);
      tone(buzzer1, 349.23); //F 
      chase(strip.Color(100, 0, 200)); // Blue
      break; 
    case fingersSpread: 
      noTone(buzzer1);
      tone(buzzer1, 493.88); //high B
      chase(strip.Color(250,30,70)); //Hot Pink? 
      break; 
    case doubleTap: 
      chase(strip.Color(0, 200,250)); //Teal?

      break; 
       }
     delay(25); 
}

static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.show();
   delay(25);  
  }
   
}



static void chase2(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i+4, 0); // Erase pixel a few steps back
      strip.show();
      delay(25);
  }

}

static void chase3(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(20-i  , c); // Draw new pixel
      strip.setPixelColor(i+4, 0); // Erase pixel a few steps back
      strip.show();
      delay(25);
  }
}
static void flash(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      
      strip.show();
      
      delay(1);
  }

}
static void chaseWait(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+400; i++) {
      
      strip.setPixelColor(i%20, c++); // Draw new pixel
    
      strip.show();
      delay(10);
  }
}

