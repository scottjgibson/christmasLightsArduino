//I have 2 LED strips; one red / green, and one RGB Full color strip
int rgStripRedPin = 3;
int rgStripGreenPin = 5;

int rgbStripRedPin = 6;
int rgbStripBluePin = 10;
int rgbStripGreenPin = 11;

int FADE_DELAY = 500;
int HOLD_TIME = 200000;
void setup()
{
  pinMode(rgStripRedPin, OUTPUT);
  pinMode(rgStripGreenPin, OUTPUT);
  pinMode(rgbStripRedPin, OUTPUT);
  pinMode(rgbStripBluePin, OUTPUT);
  pinMode(rgbStripGreenPin, OUTPUT);
  analogWrite(rgStripRedPin, 255);
  analogWrite(rgStripRedPin, 0);
  analogWrite(rgbStripRedPin, 255);
  analogWrite(rgbStripRedPin, 255);
  analogWrite(rgbStripRedPin, 255);
}

void loop()
{
  int i;
  // [r,g], [r,g,b]
  // [255,0], [255,255,255]

  //Strip 1 Fade in Green (leave red)
  //Strip 2 Fade to Red
  for (i = 0; i <= 255; i++)
  {
    analogWrite(rgStripGreenPin, i);
    analogWrite(rgbStripGreenPin, (255 - i));
    analogWrite(rgbStripBluePin, (255 - i));
    delay(FADE_DELAY);
  }
  // [255,255], [255,0,0]
  delay(HOLD_TIME);

  //Strip 1 Fade out Red (leave Green)
  //Strip 2 Fade to Green
  for (i = 0; i <= 255; i++)
  {
    analogWrite(rgStripRedPin, (255-i));
    analogWrite(rgbStripGreenPin, i);
    analogWrite(rgbStripRedPin, (255 - i));
    delay(FADE_DELAY);
  }
 //[0,255],[0,255,0]
  delay(HOLD_TIME);

  //Strip 1 Fade in Red (leave Green)
  //Strip 2 Fade to Gold
  for (i = 0; i <= 255; i++)
  {
    analogWrite(rgStripRedPin, i);
    analogWrite(rgbStripRedPin, i);
    delay(FADE_DELAY);
  }
  //[255,255],[255,255,0]
  delay(HOLD_TIME);
   
  //Strip 1 Fade to Red 
  //Strip 2 Fade to White
  for (i = 0; i <= 255; i++)
  {
    analogWrite(rgStripGreenPin, (255-i));
    analogWrite(rgbStripBluePin, i);
    delay(FADE_DELAY);
  }
  //[255,0],[255,255,255]
  delay(HOLD_TIME);
} 
