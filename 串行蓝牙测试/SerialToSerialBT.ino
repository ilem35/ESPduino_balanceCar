//通过蓝牙进行串行通信（模拟的方法）
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32蓝牙测试");//Bluetooth设备命名
  Serial.println("设备启动，现在您可以将ESP32与其他设备的蓝牙配对！");
}

void loop() {
  if (Serial.available()) {     //若串口可用,蓝牙广播从串口发送的消息（大多数时候其实没有消息，也就无发送）
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {   //若蓝牙可用,串口打印从蓝牙发送的消息
    Serial.write(SerialBT.read());
  }
  delay(20);//方便调试,正式运行时去掉此延时
}
