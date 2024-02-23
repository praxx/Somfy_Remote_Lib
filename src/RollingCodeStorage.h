#pragma once

#include <Arduino.h>

class RollingCodeStorage {
public:
	/**
	 * Get the next rolling code from the store. This should also increase the rolling code and store it persistently.
	 *
	 * @return next rolling code
	 */
	virtual uint16_t nextCode() = 0;

	/**
	 * Peek at the next rolling code from the store, without incrementing the stored value.
	 *
	 * @return next rolling code
	 */
  virtual uint16_t peekCode() = 0;
};
