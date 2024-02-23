#pragma once

#ifdef ESP32

#include "RollingCodeStorage.h"

/**
 * Stores the rolling codes in the NVS of an ESP32, the codes require two bytes.
 */
class NVSRollingCodeStorage : public RollingCodeStorage {
private:
	const char *name;
	const char *key;

public:
	NVSRollingCodeStorage(const char *name, const char *key);
	uint16_t nextCode(bool increment = true) override;
	uint16_t peekCode() override { return nextCode(/* increment= */false); }
  void setCode(uint16_t code) override;
};

#endif
