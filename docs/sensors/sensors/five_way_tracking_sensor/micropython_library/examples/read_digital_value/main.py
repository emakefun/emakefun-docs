import machine
from five_line_tracker import FiveLineTracker

i2c = machine.I2C(0, sda=21, scl=22)
five_line_tracker = FiveLineTracker(i2c, i2c_address=0x50)
five_line_tracker.sensitivity = 500

while True:
    print('digital_values:', five_line_tracker.digital_value(0),
          five_line_tracker.digital_value(1),
          five_line_tracker.digital_value(2),
          five_line_tracker.digital_value(3),
          five_line_tracker.digital_value(4))
