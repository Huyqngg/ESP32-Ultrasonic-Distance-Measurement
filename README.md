# ESP32 Ultrasonic Distance Measurement System
(非接触超音波距離測定システム)

## 1. 概要 
[cite_start]このプロジェクトは、ESP32と超音波センサ（HC-SR04）を使用して、非接触で物体の距離を正確に測定するシステムです [cite: 31][cite_start]。測定されたデータはOLEDディスプレイにリアルタイムで表示され、ロボットの障害物回避や自動制御システムへの応用が可能です [cite: 29, 32]。

## 2. 主な機能 
* [cite_start]**測定範囲:** 2cm ～ 450cm [cite: 70, 133]。
* [cite_start]**精度:** ± 0.2cm [cite: 71, 134]。
* [cite_start]**リアルタイム表示:** I2C通信を介したOLEDディスプレイへの出力 [cite: 73, 87]。
* [cite_start]**統計的誤差分析:** 20回の測定データに基づく精密な誤差評価 [cite: 143, 153]。

## 3. システム構成
### [cite_start]Hardware [cite: 78, 89]
* [cite_start]**MCU:** ESP32 DevKit V1 [cite: 83]。
* [cite_start]**Sensor:** HC-SR04 Ultrasonic Sensor [cite: 85]。
* [cite_start]**Display:** OLED SSD1306 (128x64 pixel) [cite: 87, 114]。
* [cite_start]**Communication:** I2C Interface [cite: 88, 115]。

### Software
* [cite_start]**Language:** C++/Arduino [cite: 161]。
* [cite_start]**Algorithm:** 10µsのトリガーパルス送信後、エコー時間を計測して距離を算出 [cite: 49, 54, 140]。
* [cite_start]**Formula:** $$Distance (cm) = \frac{Echo\_Time (\mu s) \times 0.0343}{2}$$ [cite: 57, 59]。

## 4. 誤差分析の結果 
[cite_start]20cmの距離での実測テストにおいて、統計的な手法を用いて信頼性を検証しました [cite: 144]。
* [cite_start]**平均測定値 ($X_{tc}$):** 20.115 cm [cite: 151]。
* **標準偏差 ($\sigma^*$):** 0.2111 [cite: 155]。
* **最終的な測定結果:** $X = 20.115 \pm 0.1453$ cm (n=20) [cite: 159]。

## 5. 開発チーム (Đội ngũ phát triển) [cite: 3, 66]
* Lê Tiến Hiếu
* Nguyễn Quốc Huy
* Tạ Văn Việt
* Hoàng Quốc Việt
