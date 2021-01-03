UKSH
By: Brennen Green
----------------------------------------
Usage: A simple shell command line interpreter
----------------------------------------

- Commands:
-- plist: displays a list of all processes running in background
-- cd: change directory command
-- setprompt: change the prompt at the command line (default: uksh > )
-- most unix supported commands
- Flags:
-- '&': used to force a process to run in the background
--- ex: sleep 15 &

- Compilation:
-- Just run make at your command line and the Makefile will handle the rest

- Implementation Issues
-- plist:
Plist was perhaps the biggest challenge to implement. My solution was to great a type defined struct "process" which contains two fields, id (pid_t) and name (char[]). This was paired with a global that kept track of the current number of processes running in the background. When a new background process started, it added it to the end of the array then incremented the list. When a background process finished (caught by SIGCHLD handler using wait()) then it would decrement number of processes and remove the specific process from the array using a shift to make sure there is not underutilized space in the array.
