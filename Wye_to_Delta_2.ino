int Vin = 5;
int sensorValue1 = 0,
    sensorValue2 = 0,
    sensorValue3 = 0;
float Vout1 = 0,
      Vout2 = 0,
      Vout3 = 0;
float Rref = 150,
      R1 = 0,
      R2 = 0,
      R3 = 0;
float Rout1 = 0,
      Rout2 = 0,
      Rout3 = 0,
      Rsum  = 0;
float initial;


void setup() 
{
  // put your setup code here, to run once:
  Serial.begin (9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  sensorValue1 = analogRead(A0);  // Read Vout on analog input pin A0 (Arduino can sense from 0-1023, 1023 is 5V)
  sensorValue2 = analogRead(A1);
  sensorValue3 = analogRead(A2);
  
  Vout1 = (Vin * sensorValue1) / 1024.0;
  Vout2 = (Vin * sensorValue2) / 1024.0;
  Vout3 = (Vin * sensorValue3) / 1024.0;    // Convert Vout to volts
  
  R1 = Rref * ((Vout2 / Vout1) - 1);  // Formula to calculate tested resistor's value
  R2 = Rref * ((Vout3 / Vout1) - 1) - R1;
  R3 = Rref * ((Vin / Vout1) - 1) - R1 - R2;
  
  Serial.print("Reference Resistance: ");                  
  Serial.println(Rref);                    // Give calculated resistance in Serial Monitor
  Serial.print("R1: ");                  
  Serial.println(R1); 
  Serial.print("R2: ");                  
  Serial.println(R2);
  Serial.print("R3: ");                  
  Serial.println(R3);  

  Serial.println();
  Serial.println("WYE TO DELTA CONVERSION OUTPUT]");

  initial = ((R1*R2) + (R2*R3) + (R1*R3));
  Rout1 = initial / R1;
  Rout2 = initial / R2;
  Rout3 = initial / R3;
  Serial.print("Rout1: ");                  
  Serial.println(Rout1); 
  Serial.print("Rout2: ");                  
  Serial.println(Rout2);
  Serial.print("Rout3: ");                  
  Serial.println(Rout3);  
  Serial.println();
  Serial.println();
  delay(3000);                          // Delay in milliseconds between reeds

}
