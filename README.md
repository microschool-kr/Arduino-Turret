# Arduino-Turret
Arduino turret with HC-SR04 ultrasonic sensor and SG90 servo motor and visualize using processing

## 아두이노 터렛
- HC-SR04 초음파 센서 1개
- SG90 서보모터 2개

## processing을 이용한 시각화
1. processing 설치
2. arduino_radar_processing 파일 실행
3. 15번줄 `myPort = new Serial(this, "COM3", 9600);` 에서 ""안을 자신의 아두이노 포트 이름으로 수정(윈도우일 경우 COM숫자, 맥의 경우 /dev/~~)
4. 재생버튼 눌러서 
