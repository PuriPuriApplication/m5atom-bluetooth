// common
#include "M5Atom.h"
#include "BLEDevice.h"
extern const unsigned char AtomImageData[375 + 2];
uint8_t DisBuff[2 + 5 * 5 * 3];
void setBuff(uint8_t Rdata, uint8_t Gdata, uint8_t Bdata)
{
  DisBuff[0] = 0x05;
  DisBuff[1] = 0x05;
  for (int i = 0; i < 25; i++)
  {
    DisBuff[2 + i * 3 + 0] = Rdata;
    DisBuff[2 + i * 3 + 1] = Gdata;
    DisBuff[2 + i * 3 + 2] = Bdata;
  }
}
#define T_PERIOD 1
#define S_PERIOD 1
RTC_DATA_ATTR static uint8_t seq;
#define SDA 12
#define SCL 14
static BLEUUID serviceUUID("7780");
static BLEUUID charUUID("7780");
static bool doConnect = false;
static bool connected = false;
static bool doScan = false;
static BLERemoteCharacteristic *pRemoteCharacteristic;
static BLEAdvertisedDevice *myDevice;
// reciever
 class MyAdvertisedDeviceCallbacks : public BLEAdvertisedDeviceCallbacks
 {
   void onResult(BLEAdvertisedDevice advertisedDevice)
   {
     Serial.print("BLE Advertised Device found: ");
     Serial.println(advertisedDevice.toString().c_str());
      if (advertisedDevice.getName() == "AmbientEnv-02")
     {
        Serial.println(advertisedDevice.getManufacturerData().c_str());
        Serial.println(advertisedDevice.getAddress().toString().c_str());
        Serial.println();
        Serial.println(advertisedDevice.getRSSI());
        Serial.println(advertisedDevice.getServiceData().c_str());
        Serial.println((const char *)advertisedDevice.getPayload());
        setBuff(0x00, 0x80, 0x00);
        M5.dis.displaybuff(DisBuff);
        delay(T_PERIOD * 2000);
     }
   }
 };
 void setup()
 {
   M5.begin(true, false, true);
   Serial.begin(115200);
   Serial.println("Starting Arduino BLE Client application...");
   BLEDevice::init("");
 }
 void loop()
 {
   BLEScan *pBLEScan = BLEDevice::getScan();
   pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
   pBLEScan->setInterval(1349);
   pBLEScan->setWindow(449);
   pBLEScan->setActiveScan(true);
   pBLEScan->start(1, false);
   setBuff(0x40, 0x00, 0x00);
   M5.dis.displaybuff(DisBuff);
   delay(50);
 }
