
#define LED_RED   3
#define LED_GREEN 5
#define LED_BLUE  6

#define LOOP_DELAY 30

void led(int red, int green, int blue);

void setup() 
{
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);

    led(255, 0, 0);
    delay(1000);
    led(0, 255, 0);
    delay(1000);
    led(0, 0, 255);
    delay(1000);
    led(255, 255, 255);
    delay(1000);
}

void loop() 
{
    for (int i = 0; i < 256; i++) 
    {
        int WheelPos = 255 - (i % 256);
        if (WheelPos < 85) {
            led(255 - WheelPos * 3, 0, WheelPos * 3);
        } 
        else  if (WheelPos < 170) 
        {
            WheelPos -= 85;
            led(0, WheelPos * 3, 255 - WheelPos * 3);
        }
        else 
        {
            WheelPos -= 170;
            led(WheelPos * 3, 255 - WheelPos * 3, 0);
        }

        delay(LOOP_DELAY);
    }
}

void led(int red, int green, int blue)
{
    analogWrite(LED_RED, 255 - red);
    analogWrite(LED_GREEN, 255 - green);
    analogWrite(LED_BLUE, 255 - blue);
}

