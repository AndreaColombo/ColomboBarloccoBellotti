
#ifndef SERIAL_H
#define SERIAL_H

class SerialPort
{
public:
	SerialPort();

	void write(const char *s);
	void writeN(const int n);
};

#endif //SERIAL_H
