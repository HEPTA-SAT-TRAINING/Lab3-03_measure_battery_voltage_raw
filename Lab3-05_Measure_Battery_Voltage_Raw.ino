#include "src/HeptaSat.h"

HeptaCdh cdh;
HeptaEps eps;

const float adc_ref_voltage = 3.3;
const uint16_t adc_max_value = 4096;

// Bus voltage divider resistors (in ohms, V4.1.1)
const float bus_vol_res_top = 1300.0f;
const float bus_vol_res_bottom = 1500.0f;

const float bus_vol_divider_gain = (bus_vol_res_top + bus_vol_res_bottom) / bus_vol_res_bottom;

void setup() {
  cdh.begin();
  eps.init();
}

void loop() {
  uint16_t raw_voltage = eps.get_bus_voltage_raw();
  cdh.printf("Raw Bus voltage: %d\r\n", raw_voltage);

  float converted_voltage = raw_voltage * (adc_ref_voltage / adc_max_value) * bus_vol_divider_gain;
  cdh.printf("Converted Bus voltage: %f V\r\n", converted_voltage);

  delay(1000);
}
