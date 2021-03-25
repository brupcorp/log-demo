#include "log.h"
#include <stdio.h>

// muss irgendwo in einer cpp datei existieren
LogDevice* Log::currentLogger = 0;

// erstelle systemspezifisches logdevice
class TextLogger : public LogDevice {
	void out(const char* nachricht) { printf("%s\n", nachricht); }
};

int main(int argc, char const* argv[]) {
	// setze logdevice was genutzt wird
	Log::currentLogger = new TextLogger();

	// und log testen - Log::out() kann nach initialisierung überall genutzt werden.
	Log::out("halo");

	return 0;
}
