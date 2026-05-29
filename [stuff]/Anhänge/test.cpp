#include <iostream>
#include <vector>
#include <algorithm> // Wichtig für std::min und std::lower_bound

// Simulierter Log-Eintrag
struct LogEntry {
    int timestamp; 
    std::string message;
};

// Unsere Funktion (Exponentielle Suche + Binärsuche)
int findFirstLogAfter(const std::vector<LogEntry>& logs, int searchTime) {
    int n = logs.size();

    if (n == 0) return -1;

    // Check: Ist das erste Element schon der Treffer?
    if (logs[0].timestamp >= searchTime) {
        return 0;
    }

    // Phase 1: Exponentielle Suche
    int bound = 1;
    while (bound < n && logs[bound].timestamp < searchTime) {
        bound *= 2;
    }

    // Phase 2: Binäre Suche (std::lower_bound)
    // Wir suchen nur im Bereich zwischen bound/2 und min(bound, n)
    int leftIndex = bound / 2;
    int rightIndex = std::min(bound, n);

    auto it = std::lower_bound(
        logs.begin() + leftIndex, 
        logs.begin() + rightIndex, 
        searchTime,
        [](const LogEntry& entry, int val) {
            return entry.timestamp < val;
        }
    );

    // Prüfen ob gefunden
    if (it != logs.begin() + rightIndex) {
        return std::distance(logs.begin(), it);
    }

    return -1; 
}

int main() {
    // 1. Daten anlegen
    std::vector<LogEntry> serverLogs = {
        {100, "Server start"}, 
        {105, "Init DB"}, 
        {120, "User login"},
        {200, "Warning X"},    
        {250, "Error Y"},  
        {300, "User logout"},
        {450, "Cleanup"},      
        {800, "Shutdown"} 
    };

    // 2. Ziel definieren
    int target = 240; 
    std::cout << "Suche nach Logs ab Zeitstempel: " << target << "...\n";

    // 3. Suche starten
    int index = findFirstLogAfter(serverLogs, target);

    // 4. Ergebnis ausgeben
    if (index != -1) {
        std::cout << "Gefunden an Index: " << index << "\n";
        std::cout << "Eintrag: [" << serverLogs[index].timestamp << "] " 
                  << serverLogs[index].message << "\n";
    } else {
        std::cout << "Nichts gefunden.\n";
    }

    return 0;
}