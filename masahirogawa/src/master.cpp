// #include "BluetoothSerial.h"
// #include "M5Atom.h"

// BluetoothSerial SerialBT;

// String MACadd = "24:A1:60:52:51:5E";
// uint8_t address[6] = {0xAA, 0xBB, 0xCC, 0x11, 0x22, 0x33};
// String name = "OBDII";
// char *pin = "1234";
// bool connected;

// void setup()
// {
//   M5.begin(true, false, true);
//   delay(50);
//   M5.dis.drawpix(0, 0xf00000);

//   Serial.begin(115200);
//   SerialBT.begin("master", true);
//   Serial.println("The device started in master mode, make sure remote BT device is on!");

//   connected = SerialBT.connect(name);

//   if (connected)
//   {
//     Serial.println("Connected Succesfully!");
//   }
//   else
//   {
//     while (!SerialBT.connected(10000))
//     {
//       Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app.");
//     }
//   }
//   if (SerialBT.disconnect())
//   {
//     Serial.println("Disconnected Succesfully!");
//   }
//   SerialBT.connect();
// }

// void loop()
// {
//   if (M5.Btn.wasPressed())
//   {
//     if (Serial.available())
//     {
//       SerialBT.write(Serial.read());
//       M5.dis.drawpix(0, 0xf00000);
//     }
//     if (SerialBT.available())
//     {
//       Serial.write(SerialBT.read());
//       M5.dis.drawpix(0, 0xf00000);
//     }
//   }
//   delay(20);
// }
