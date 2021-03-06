#include <Wire.h>
#include "Adafruit_MCP23017.h"

// Basic pin reading and pullup test for the MCP23017 I/O expander
// public domain!

// Connect pin #12 of the expander to Analog 5 (i2c clock)
// Connect pin #13 of the expander to Analog 4 (i2c data)
// Connect pins #15, 16 and 17 of the expander to ground (address selection) - All 0, for our purposes
// Connect pin #9 of the expander to 5V (power)
// Connect pin #10 of the expander to ground (common ground)
// Connect pin #18 through a ~10kohm resistor to 5V (reset pin, active low) - Hardwired to 5V, w/out 10k

Adafruit_MCP23017 mcp;
  
void setup() {  
  mcp.begin();      // use default address 0 (all 3 set to gnd)

  mcp.pinMode(0, OUTPUT); // pin 0 is GPA0 (not GPB0)
}



void loop() {
  // toggle back and forth every second
  mcp.digitalWrite(0, HIGH);
  delay(1000);
  mcp.digitalWrite(0, LOW);
  delay(1000);  
}
