
#include <M5Atom.h>
#include "BLEDevice.h"
#include "BLEServer.h"
#include "BLEUtils.h"
#include "esp_sleep.h"
#include <Wire.h>
// #include "bme280_i2c.h"

#define T_PERIOD     10   // Transmission period
#define S_PERIOD     1  // Silent period
RTC_DATA_ATTR static uint8_t seq; // remember number of boots in RTC Memory

#define SDA 12
#define SCL 14

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

void setup()
{
    M5.begin(true, false, true);
    Serial.begin(115200);
    Serial.printf("start ESP32 %d\n",seq);
}

void loop()
{
    BLEDevice::init("AmbientEnv-02");                  // デバイスを初期化
    BLEServer *pServer = BLEDevice::createServer();    // サーバーを生成

    BLEAdvertising *pAdvertising = pServer->getAdvertising(); // アドバタイズオブジェクトを取得

    // デバイス名とフラグをセットし、送信情報を組み込んでアドバタイズオブジェクトに設定する
    BLEAdvertisementData oAdvertisementData = BLEAdvertisementData();
    
    oAdvertisementData.setName("device naaaaaame");
    oAdvertisementData.setFlags(0x06);      // LE General Discoverable Mode | BR_EDR_NOT_SUPPORTED
    oAdvertisementData.addData("Hello world!!!");

    int sleepsec;
    if (M5.Btn.wasPressed()){
      pAdvertising->start();                             // アドバタイズ起動
      Serial.println("Advertizing started!!!");
      sleepsec = 10000;
      setBuff(0x00, 0x80, 0x00);
    }else{
      //Serial.println("Advertizing stoping...");
      pAdvertising->stop();                              // アドバタイズ停止
      sleepsec = 1000;
      setBuff(0x40, 0x00, 0x00);
    }
    M5.dis.displaybuff(DisBuff);

    delay(sleepsec);
    M5.update();
}
