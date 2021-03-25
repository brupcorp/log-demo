#ifndef LOGDEMO
#define LOGDEMO

// das abstrakte log device - kann keine instanz davon erstellen
class LogDevice {
  public:
	virtual void out(const char*) = 0;
};

// enthält das jetztige logdevice und sorgt fürs logging.
class Log {
  public:
	static LogDevice* currentLogger;
	static void out(const char* message) { currentLogger->out(message); }
};

#endif