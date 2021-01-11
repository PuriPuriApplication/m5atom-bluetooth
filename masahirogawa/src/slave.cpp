// #include "BluetoothSerial.h"
// #include "M5Atom.h"

// #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
// #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
// #endif

// BluetoothSerial SerialBT;

// void setup()
// {
//   M5.begin(true, false, true);
//   delay(50);
//   M5.dis.drawpix(0, 0xf00000);

//   Serial.begin(115200);
//   SerialBT.begin("slave");
//   Serial.println("The device started, now you can pair it with bluetooth!");
// }

// void loop()
// {
//   if (M5.Btn.wasPressed())
//   {
//     if (Serial.available())
//     {
//       SerialBT.write(Serial.read());
//       M5.dis.drawpix(0, 0x00f000);
//     }
//     if (SerialBT.available())
//     {
//       Serial.write(SerialBT.read());
//       M5.dis.drawpix(0, 0x00f000);
//     }
//   }
//   delay(20);
// }
