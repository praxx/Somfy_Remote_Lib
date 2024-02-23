
#include "EEPROMRollingCodeStorage.h"

EEPROMRollingCodeStorage::EEPROMRollingCodeStorage(int address) : address(address) {}

uint16_t EEPROMRollingCodeStorage::nextCode(bool increment) {
	uint16_t code;
	EEPROM.get(address, code);
#ifdef DEBUG
	Serial.print("Rolling code: ");
	Serial.println(code);
#endif
  if (increment) {
  	EEPROM.put(address, (uint16_t)(code + 1));
#if defined(ESP32) || defined(ESP8266)
	  EEPROM.commit();
#endif
  }
	return code;
}

void EEPROMRollingCodeStorage::setCode(uint16_t code) {
	EEPROM.put(address, code);
#if defined(ESP32) || defined(ESP8266)
  EEPROM.commit();
#endif
}
