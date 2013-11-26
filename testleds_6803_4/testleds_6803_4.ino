#include <FastSPI_LED.h>

#define NUM_LEDS 9
#define MAX_COLORS 31
#define FACTOR_COLORS 8
#define MAX_INTENSIDAD 15
#define MAX_COLORS2 (MAX_COLORS - (MAX_COLORS-MAX_INTENSIDAD))

// Sometimes chipsets wire in a backwards sort of way
// struct CRGB { unsigned char b; unsigned char r; unsigned char g; };
struct CRGB { unsigned char r; unsigned char g; unsigned char b; };
struct CRGB *leds;

#define PIN 4


int serialData = 0;


/////////////////////////////////////////////

int animationFrames = 3;

int animationDelays[] = { 200, 200, 200};

// Animation is designed for 3x3 pixels
unsigned char animation[][9*3] = {
 {0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
 {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
 {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },

};


/////////////////////////////////////////////






void setup()
{
  Serial.begin(9600); 
  randomSeed(analogRead(0));
          Serial.println("------------------------------");

           Serial.println(NUM_LEDS);
           Serial.println(MAX_COLORS);      
           Serial.println(FACTOR_COLORS);
              Serial.println(MAX_INTENSIDAD);
                      Serial.println(MAX_COLORS2);

          Serial.println("------------------------------");
  
  
  FastSPI_LED.setLeds(NUM_LEDS);
  FastSPI_LED.setChipset(CFastSPI_LED::SPI_LPD6803);
  
  // LPD 6803 -- >  32 niveles por color  Total 32768 Colores

  FastSPI_LED.setPin(PIN);
  FastSPI_LED.init();
  FastSPI_LED.start();

  leds = (struct CRGB*)FastSPI_LED.getRGBData(); 

}

void loop() { 
  
      for(int i = 0; i < animationFrames; i++ ) {
      
      
      
      }





  FullRandomization();
/*  
  FullBlack();
  delay(500);
  FullBlue(); 
  FullBlack();
  FullBlue(); 
  FullBlack();
  delay(500);
  
*/

//set todo negro ( inicializa todo en 0 ) 



//Led1 Azul
   
/*   
  // Fade in/fade out
  for(int j = 0; j < 3; j++ ) { 
    memset(leds, 0, NUM_LEDS * 3);
    for(int k = 0, l=MAX_COLORS+2 ; k < MAX_COLORS-2; k++, l--) { 
      for(int i = 0; i < NUM_LEDS; i++ ) {
        switch(j) { 
          case 0:
             leds[i+1].r = k+2 * FACTOR_COLORS ; leds[i+1].g = l-2 * FACTOR_COLORS; break;
             leds[i].r = k * FACTOR_COLORS ; leds[i].g = l * FACTOR_COLORS; break;
          case 2: leds[i].g = k * FACTOR_COLORS ; leds[i].b = l * FACTOR_COLORS; break;
          case 1: leds[i].b = k * FACTOR_COLORS ; leds[i].r = l * FACTOR_COLORS;break;
        }
      }
      FastSPI_LED.show();
      delay(500);
    }
    
  }

  FullBlack();
  delay(1000);
*/

}


void FullBlack(){

  memset(leds, 0, NUM_LEDS * 3);
  FastSPI_LED.show();
  delay(100);

}
void FullBlue(){

  memset(leds, 0, NUM_LEDS * 3);
  for(int i = 0 ; i < NUM_LEDS; i++ ) {
    leds[i].b=128;
  }
  
  FastSPI_LED.show();
  delay(100);

}

void FullRandomization()
{
      memset(leds, 0, NUM_LEDS * 3);
      for(int i = 0; i < NUM_LEDS; i++ ) {
        leds[i].r = random(MAX_COLORS2)*FACTOR_COLORS;
        leds[i].g = random(MAX_COLORS2)*FACTOR_COLORS;
        leds[i].b = random(MAX_COLORS2)*FACTOR_COLORS;
        
        Serial.print("Led:");
        Serial.print(i);
        Serial.print("r:");
        Serial.print(leds[i].r);
        Serial.print(" g:");
        Serial.print(leds[i].g);
        Serial.print(" b:");
        Serial.println(leds[i].b);

      }
        Serial.println("------------------------------");
        FastSPI_LED.show();
        delay(30);
        
      


}

