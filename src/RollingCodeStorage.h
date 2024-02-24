#pragma once

#include <Arduino.h>

class RollingCodeStorage {
public:
	/**
	 * Get the next rolling code from the store. This should also increase the rolling code and store it persistently.
	 *
	 * @return next rolling code
	 */
	virtual uint16_t nextCode(bool increment = true) = 0;

	/**
	 * Peek at the next rolling code from the store, without incrementing the stored value.
	 *
	 * @return next rolling code
	 */
  virtual uint16_t peekCode() = 0;

  /**
   * Explicitly set the rolling code for the store.
   */
  virtual void setCode(uint16_t code) = 0;
};
