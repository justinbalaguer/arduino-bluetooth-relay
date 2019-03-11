byte Relay1 = 8;                // device to control
byte Relay2 = 9;                // device to control
char BT_input=' ';          // to store input character received via BT.

void setup() 
{
    Serial.begin(9600);     // default baud rate of module
    pinMode(Relay1, OUTPUT);
    digitalWrite(Relay1, HIGH);
    pinMode(Relay2, OUTPUT);
    digitalWrite(Relay2, HIGH);
    
    while (!Serial)
    {
      Serial.print("Serial Connection Fail");
    }
    Serial.print("Start Success");
}
 
void loop()
{
 if (Serial.available())
 {
  Serial.print("Serial is available");
  BT_input = Serial.read();

  //FOR RELAY 1
  if ( BT_input== 48)       //ascii code for 0 is dec 48
   {
    digitalWrite(Relay1, HIGH);
    Serial.println(BT_input);
    Serial.println("RELAY 1 is OFF"); 
    
   }
  if ( BT_input== 49) 
   { 
   digitalWrite(Relay1, LOW); 
   Serial.println(BT_input);
   Serial.println("RELAY 1 is ON");  //ascii code for 1 is dec 49 
   }

   //FOR RELAY 2
   if ( BT_input== 50)       //ascii code for 2 is dec 50
   {
    digitalWrite(Relay2, HIGH);
    Serial.println(BT_input);
    Serial.println("RELAY 2 is OFF"); 
   }
  if ( BT_input== 51) 
   { 
   digitalWrite(Relay2, LOW); 
   Serial.println(BT_input);
   Serial.println("RELAY 2 is ON");  //ascii code for 3 is dec 51 
   }
 }
}
