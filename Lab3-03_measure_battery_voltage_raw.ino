#include "src/HeptaSat.h"

HeptaCdh cdh;
HeptaEps eps;

const float adc_ref_voltage = 3.3;
const uint16_t adc_max_value = 4096;

// Battery divider resistors (in ohms)
const float bat_res_top = 12000.0f;
const float bat_res_bottom = 30000.0f;

const float bat_vol_divider_gain = (bat_res_top + bat_res_bottom) / bat_res_bottom;

void setup() {
  cdh.begin();
  eps.init();
}

void loop() {
  uint16_t raw_voltage = eps.get_battery_voltage_raw();
  cdh.printf("Raw Battery Voltage: %d\r\n", raw_voltage);

  float converted_voltage = raw_voltage * (adc_ref_voltage / adc_max_value) * bat_vol_divider_gain;
  cdh.printf("Converted Battery Voltage: %f V\r\n", converted_voltage);

  delay(1000);
}
