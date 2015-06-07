/*
Fishackathon 2015 - Challenge 15-9
"Develop a measuring board (or other system) that could automatically measure and record fish length."
*/
int i;
int r;
int l;
int x;
int y;

int ON = 1;
int OFF = 0;

int numSensors = 4;
int magicNumbers[3]; // All possible valid sequences as integers, numSensors-1 because you need minimum 2 sensors to take a measurement

int bias;
int sample;

//int pcellBias[4] {0, 0, 0, 0};
int pcellSample[4] {0, 0, 0, 0};
double pcellSensitivity = 0.20; // 20% sample sensitivity

int pcellPrevious[4] {0, 0, 0, 0};

int LEDpins[4] {11, 10, 6, 5};
int LEDstate[4] {OFF, OFF, OFF, OFF};

void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
  
  // Generate all valid sequences that trigger measurement
  for (x = 1, y = 0; y < numSensors-1; ++y) {
      x *= 2;
      x = x + 1;
      magicNumbers[y] = x;
  }

  // set initial LED state
  for (r = 0; r < numSensors; ++r) {
    analogWrite(LEDpins[r], LEDstate[r]);
  }
  
}
 
void loop(void) {
// Attempt to reduce false positives by taking samples and averaging
// them to establish bias/sensitivity per photocell
//
//  // Take 50 bias samples of each photocell squentially
//  for (i = 0; i < 50; ++i) { // times sampled
//    for (r = 0; r < numSensors; ++r) { // photocells in array
//      bias = analogRead(r);
//      pcellBias[r] += abs(bias);
//    }
//  }
//  
//  // Average bias samples
//  for (r = 0; r < numSensors; ++r) {
//    pcellBias[r] = pcellBias[r] / 50;
//    //Serial.println(pcellBias[r]);
//  }
 
  // take 60 samples with a short wait at the end
  for (i = 0; i < 60; ++i) {
    // Sample each photo cell in the row
    for (r = 0; r < numSensors; ++r) {
      pcellSample[r] = analogRead(r);
    }
    
    // watch me not memcpy
    if (pcellPrevious[0] == 0) {
      for (r = 0; r < numSensors; ++r) {
        pcellPrevious[r] = pcellSample[r];
      }
    }
    else {
      // examine each photocell's resistance to see if it changed
      for (r = 0; r < numSensors; ++r) {
        // compare to the previous sample within the sensitivity range
        if (abs(pcellPrevious[r] - pcellSample[r]) > int(pcellPrevious[r] * pcellSensitivity)) {
          analogWrite(LEDpins[r], LEDswitch(r));
        }
      }
    }
    
    x = currentState();      
    y = sequenceLength(x);
    if (y > 0) {
      Serial.print(y);
      Serial.println(" unit(s)");
    }
    
    // watch me not memcpy again
    for (r = 0; r < numSensors; r++) {
      pcellPrevious[r] = pcellSample[r];
    }
      
    // this holds the current state for 2s 
    delay(2000);  
  }    
}

int LEDswitch(int r) {
  if (LEDstate[r] == ON)
    return LEDstate[r] = OFF;
  else
    return LEDstate[r] = ON;
}

int currentState() {
  int j;
  int k;
  // convert LED state to integer (so array acts like a bit field)
  for (j = 0, k = 0; k < numSensors; ++k) {
    j *= 2;
    j = j + LEDstate[k];
  }
  return j;
}

int sequenceLength(int s) {
  int k;
  for (k = 0; k < numSensors-1; ++k) {
    if (magicNumbers[k] == s) {
      return k+1;
    }
  }
  return -1;
}
