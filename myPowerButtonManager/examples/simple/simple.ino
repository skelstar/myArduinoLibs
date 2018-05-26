#include <myPowerButtonManager.h>

#define POWER_UP_BUTTON 13

void powerupEvent(int state);

myPowerButtonManager powerButton(POWER_UP_BUTTON, HIGH, 3000, 3000, powerupEvent);

void powerupEvent(int state) {

	switch (state) {
		case powerButton.TN_TO_POWERING_UP:
			Serial.println("TN_TO_POWERING_UP");
			break;
		case powerButton.TN_TO_POWERED_UP_WAIT_RELEASE:
			Serial.println("TN_TO_POWERED_UP_WAIT_RELEASE");
			break;
		case powerButton.TN_TO_RUNNING:
			Serial.println("TN_TO_RUNNING");
			break;
		case powerButton.TN_TO_POWERING_DOWN:
			Serial.println("TN_TO_POWERING_DOWN");
			break;
		case powerButton.TN_TO_POWERING_DOWN_WAIT_RELEASE:
			Serial.println("TN_TO_POWERING_DOWN_WAIT_RELEASE");
			break;
		case powerButton.TN_TO_POWER_OFF:
			Serial.println("TN_TO_POWER_OFF");
			esp_deep_sleep_start();
			Serial.println("This will never be printed");
			break;
	}
}

//--------------------------------------------------------------------------------
void setup() {
	Serial.begin(9600);
	Serial.printf("\nmyPowerButtonManager\n");

	powerButton.begin(0);
}
//--------------------------------------------------------------------------------
void loop() {
	powerButton.serviceButton();

	delay(100);
}
//--------------------------------------------------------------------------------