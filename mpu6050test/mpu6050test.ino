#include <Adafruit_MPU6050.h>
Adafruit_MPU6050 mpu;

#include "getAngle.h"

void setup(void) {
  Serial.begin(115200);
  while (!Serial){
    delay(10); 
  }
  Serial.println("Adafruit MPU6050 test!");

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);//设置加速度
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  Serial.print("各方向重力加速度 X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  float angle_x = getAngle(a.acceleration.x,a.acceleration.z);
  float angle_y = getAngle(a.acceleration.y,a.acceleration.z);
  Serial.print("各方向角度 X: ");
  Serial.print(angle_x);
  Serial.print(", Y: ");
  Serial.print(angle_y);
  Serial.println(" °");

  Serial.print("各方向角速度 X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  Serial.print("温度: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");

  Serial.println();
//  delay(50);//调试时方便观察,运行时此处直接注释掉
}
