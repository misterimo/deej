const int NUM_SLIDERS = 7;
const int NUM_BUTTONS = 5; //Even though we only have 4 switches, this was done to simplify the code later
const int NUM_LEDS = 5;
const int analogInputs[NUM_SLIDERS] = {A0, A1, A2, A3, A4, A5, A6}; 
const int digitalInputs[NUM_SLIDERS] = {11, 9, 2,13, 6, 4}; //D11 and D13 are placeholders, since Channel 0 and 3 don't have switchs
const int digitalOutputs[NUM_SLIDERS] = {10, 7, 8,12, 5, 3}; //D10 and D12 are placeholders, since Channel 0 and 3 don't have LEDs

int analogSliderValues[NUM_SLIDERS];
int a;

void setup() { 
  Serial.begin(9600);
  for (int i = 0; i < NUM_SLIDERS; i++) 
  {
    pinMode(analogInputs[i], INPUT); //Setting up the analogs pins as INPUTS
    if(i<=NUM_BUTTONS) //No need to setup more than 5 digital pins
    {
      pinMode(digitalInputs[i], INPUT_PULLUP); //Setting up the switchs as internal pull-up input
      pinMode(digitalOutputs[i], OUTPUT); //Setting up the LEDs as output
      digitalWrite(digitalOutputs[i], HIGH); //Turning ON the LED to check if it's working properly and making a cool animation
      delay(500);
    }
  }
   for (int i = 1; i <= NUM_LEDS; i++)
      digitalWrite(digitalOutputs[i], LOW); //Turning off all LEDs to notify the user about the end of the setup
   delay(500);
}

void loop() {
  updateSliderValues();
  sendSliderValues(); // Actually send data (all the time)
  // printSliderValues(); // For debug
  delay(10);
}

void updateSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) //For each channel...
  {
    if(not(i==0 or i==3 or i==6)and digitalRead(digitalInputs[i])==HIGH) //...check if it's one of the 4 channels that have mute switchs and the switchs are OFF...
    {
        analogSliderValues[i]=1024; //...then give the max analog value of the channel and...
        digitalWrite(digitalOutputs[i], LOW); //...turn off the LED
    }
    else
    {
        a=analogRead(analogInputs[i]); //Store the analog value...
        analogSliderValues[i] = map(a,0,880,0,1024); //Map it to custom values you found (This is done to correct the max and min values you get with your custom potentiometers)
        digitalWrite(digitalOutputs[i], HIGH); //Turn ON the LED
    }
}
}

void sendSliderValues() 
{
  String builtString = String("");

  for (int i = 0; i < NUM_SLIDERS; i++)
  {
    builtString += String((int)analogSliderValues[i]);

    if (i < NUM_SLIDERS - 1) 
    {
      builtString += String("|");
    }
  }
  Serial.println(builtString);
}

void printSliderValues() 
{
  for (int i = 0; i < NUM_SLIDERS; i++) 
  {
    String printedString = String("Slider #") + String(i + 1) + String(": ") + String(analogSliderValues[i]) + String(" mV");
    Serial.write(printedString.c_str());
    if (i < NUM_SLIDERS - 1) 
    {
      Serial.write(" | ");
    } else {
      Serial.write("\n");
    }
  }
}
