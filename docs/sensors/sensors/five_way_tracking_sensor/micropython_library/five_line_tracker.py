import struct


class FiveLineTracker:

    def __init__(self, i2c, i2c_address=0x50):
        self._i2c = i2c
        self._i2c_address = i2c_address

    @property
    def sensitivity(self):
        self._i2c.writeto(self._i2c_address, bytes([0x00]))
        return struct.unpack("<h", self._i2c.readfrom(self._i2c_address, 2))[0]

    @sensitivity.setter
    def sensitivity(self, value):
        if value < 0 or value > 1023:
            raise ValueError(
                f'{value} is out of range for sensitivity (0 ~ 1023)')

        self._i2c.writeto(self._i2c_address,
                          bytes([0x00]) + struct.pack("<h", value))

    @property
    def analog_values(self):
        self._i2c.writeto(self._i2c_address, bytes([0x02]))
        return struct.unpack("HHHHH", self._i2c.readfrom(self._i2c_address, 10))

    @property
    def digital_values(self):
        self._i2c.writeto(self._i2c_address, bytes([0x0c]))
        return self._i2c.readfrom(self._i2c_address, 1)[0]

    def analog_value(self, channel):
        return self.analog_values[channel]

    def digital_value(self, channel):
        return (self.digital_values >> channel) & 0x01
