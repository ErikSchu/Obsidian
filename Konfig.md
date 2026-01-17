#linux
##### Git, Debugger `gdb`, Compiler `gcc-c++` & Build Tools `cmake`

```bash
Erik@fedora:~$ sudo dnf install git gcc-c++ gdb cmake  
[sudo] Passwort für Erik:    
Aktualisiere und lade Paketquellen:  
Paketquellen geladen.  
Das Paket "gcc-c++-15.2.1-5.fc42.x86_64" ist bereits installiert.  
Das Paket "gdb-16.3-1.fc42.x86_64" ist bereits installiert.  
  
Paket                                    Architektur    Version                                   Paketquelle             Größe  
Installiere:  
cmake                                   x86_64         3.31.6-2.fc42                             fedora               34.2 MiB  
git                                     x86_64         2.52.0-1.fc42                             updates              56.4 KiB  
Abhängigkeiten werden installiert:  
cmake-data                              noarch         3.31.6-2.fc42                             fedora                8.5 MiB  
git-core                                x86_64         2.52.0-1.fc42                             updates              24.0 MiB  
git-core-doc                            noarch         2.52.0-1.fc42                             updates              18.4 MiB  
perl-Error                              noarch         1:0.17030-1.fc42                          fedora               76.7 KiB  
perl-Git                                noarch         2.52.0-1.fc42                             updates              64.4 KiB  
perl-TermReadKey                        x86_64         2.38-24.fc42                              fedora               64.0 KiB  
perl-lib                                x86_64         0.65-519.fc42                             updates               8.5 KiB  
rhash                                   x86_64         1.4.5-2.fc42                              fedora              351.0 KiB  
  
Transaktionszusammenfasung:  
Installiere:        10 Pakete  
  
Die vollständige Größe eingehender Pakete ist 23 MiB. Heruntergeladen werden müssen 23 MiB.  
Nach dieser Operation werden 86 MiB mehr benötigt (installiere 86 MiB, entferne 0 B).  
Is this ok [y/N]: y  
[ 1/10] git-0:2.52.0-1.fc42.x86_64                                                     100% |  95.1 KiB/s |  40.7 KiB |  00m00s  
[ 2/10] perl-TermReadKey-0:2.38-24.fc42.x86_64                                         100% |  82.2 KiB/s |  35.4 KiB |  00m00s  
[ 3/10] perl-Git-0:2.52.0-1.fc42.noarch                                                100% | 138.0 KiB/s |  37.8 KiB |  00m00s  
[ 4/10] perl-Error-1:0.17030-1.fc42.noarch                                             100% | 339.3 KiB/s |  40.4 KiB |  00m00s  
[ 5/10] git-core-0:2.52.0-1.fc42.x86_64                                                100% |   4.6 MiB/s |   5.2 MiB |  00m01s  
[ 6/10] git-core-doc-0:2.52.0-1.fc42.noarch                                            100% |   3.6 MiB/s |   3.1 MiB |  00m01s  
[ 7/10] rhash-0:1.4.5-2.fc42.x86_64                                                    100% | 773.2 KiB/s | 198.7 KiB |  00m00s  
[ 8/10] perl-lib-0:0.65-519.fc42.x86_64                                                100% | 389.0 KiB/s |  14.8 KiB |  00m00s  
[ 9/10] cmake-data-0:3.31.6-2.fc42.noarch                                              100% |   4.0 MiB/s |   2.5 MiB |  00m01s  
[10/10] cmake-0:3.31.6-2.fc42.x86_64                                                   100% |   5.5 MiB/s |  12.2 MiB |  00m02s  
-------------------------------------------------------------------------------------------------------------------------------  
[10/10] Gesamt                                                                         100% |   5.2 MiB/s |  23.3 MiB |  00m04s  
Transaktion wird ausgeführt  
[ 1/12] Verifiziere Paket Dateien                                                      100% |  80.0   B/s |  10.0   B |  00m00s  
[ 2/12] Transaktion vorbereiten                                                        100% |  20.0   B/s |  10.0   B |  00m00s  
[ 3/12] Installiere git-core-0:2.52.0-1.fc42.x86_64                                    100% |  68.2 MiB/s |  24.0 MiB |  00m00s  
[ 4/12] Installiere git-core-doc-0:2.52.0-1.fc42.noarch                                100% |  73.1 MiB/s |  18.6 MiB |  00m00s  
[ 5/12] Installiere perl-lib-0:0.65-519.fc42.x86_64                                    100% |   2.9 MiB/s |   8.9 KiB |  00m00s  
[ 6/12] Installiere rhash-0:1.4.5-2.fc42.x86_64                                        100% |  12.9 MiB/s | 356.4 KiB |  00m00s  
[ 7/12] Installiere cmake-data-0:3.31.6-2.fc42.noarch                                  100% |  15.3 MiB/s |   9.1 MiB |  00m01s  
[ 8/12] Installiere cmake-0:3.31.6-2.fc42.x86_64                                       100% | 257.3 MiB/s |  34.2 MiB |  00m00s  
[ 9/12] Installiere perl-Error-1:0.17030-1.fc42.noarch                                 100% |  13.0 MiB/s |  80.0 KiB |  00m00s  
[10/12] Installiere perl-TermReadKey-0:2.38-24.fc42.x86_64                             100% |  12.9 MiB/s |  66.2 KiB |  00m00s  
[11/12] Installiere perl-Git-0:2.52.0-1.fc42.noarch                                    100% |  21.3 MiB/s |  65.4 KiB |  00m00s  
[12/12] Installiere git-0:2.52.0-1.fc42.x86_64                                         100% |  72.2 KiB/s |  57.7 KiB |  00m01s
```

##### Git für Obsidian

- Git community Erweiterung
  
- `cd ~/home/Erik/Dokumente/Obsidian_Vault/Vault_von_Erik` → Ordner jetzt mit Git verwaktet
  
- `echo ".obsidian/workspace >> .gitignore` → ignoriert u.a. offene Fenster
	-  ` >> ` append
	-  ` > ` replace

- `git --global user.email "erik.schulze@tu-dortmund.de" --global user.name "Erik Schulze"

- `git add .` ; `git commit -m "first_backup"`

- GitHub-Verknüpfung 