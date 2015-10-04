import serial

serialPort = "/dev/ttyS6"
print(serialPort)

def logtext():
	serialConnection = serial.Serial(serialPort, timeout = 2.0)
	filename = "test.csv"
	outputFile = open(filename, 'a')
	while True:
		data = serialConnection.readline().strip()
		if data:
			data_s = str(data)
			data_string = bytes(data_s, encoding="utf-8")
			outputFile.write(data_string + ',')
			print("data: " + data_string)
	print("exit")

if __name__ == "__main__":
	try:
		logtext()
	except Exception as e:
		print(e)
		pass