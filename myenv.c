/*
 *  myenv.c : env コマンドのクローン
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #ifdef __linux__
 #include "myputenv.h"
 #endif
 
 extern char **environ;
 
 int main(int argc, char *argv[]) {
     int i = 1;
     while(putenv(argv[i]) != -1){
         i++;
     }
     if(argv[i] == NULL){
         for(int j = 0; environ[j] != NULL; j++){
             printf("%s\n", environ[j]);
         }
         return 0;
     }
     execvp(argv[i], &argv[i]);
     perror(argv[i]);
     return 1;
 }
 
 /* 実行例
yasunagakei@yasunagakeinoMacBook-Air kadai09-keiyasu7022-arch % ./myenv LC_TIME=ja_JP.UTF-8             
OSLogRateLimit=64
PWD=/Users/yasunagakei/kadai09-keiyasu7022-arch
NVM_DIR=/Users/yasunagakei/.nvm
USER=yasunagakei
SECURITYSESSIONID=186b0
MallocNanoZone=0
__CFBundleIdentifier=com.todesktop.230313mzl4w4u92
COMMAND_MODE=unix2003
LANG=ja_JP.UTF-8
ANTHROPIC_API_KEY=
CURSOR_CLI=ELECTRON_RUN_AS_NODE=1 "/Volumes/Cursor Installer/Cursor.app/Contents/MacOS/Cursor" "/Volumes/Cursor Installer/Cursor.app/Contents/Resources/app/out/cli.js"
PATH=/Users/yasunagakei/.nvm/versions/node/v24.15.0/bin:/Users/yasunagakei/.local/bin:/opt/homebrew/opt/openjdk/bin:/opt/homebrew/opt/openjdk/bin:/opt/anaconda3/bin:/Library/Frameworks/Python.framework/Versions/3.14/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/pkg/env/global/bin:/opt/homebrew/bin:/Users/yasunagakei/.nvm/versions/node/v24.15.0/bin:/Users/yasunagakei/.local/bin:/opt/homebrew/opt/openjdk/bin:/opt/anaconda3/bin:/Library/Frameworks/Python.framework/Versions/3.14/bin
TERM=xterm-256color
LOGNAME=yasunagakei
CURSOR_CLI_MODE=local
NVM_CD_FLAGS=-q
SSH_AUTH_SOCK=/var/run/com.apple.launchd.eksrj0fMYx/Listeners
TERM_PROGRAM_VERSION=3.3.30
CPPFLAGS=-I/opt/homebrew/opt/openjdk/include
SHLVL=3
TERM_SESSION_ID=A8C6469F-37B3-4AA5-991E-6848D833A2D9
SHELL=/bin/zsh
HOME=/Users/yasunagakei
COLORTERM=truecolor
NVM_BIN=/Users/yasunagakei/.nvm/versions/node/v24.15.0/bin
LaunchInstanceID=CBF3DB15-4C0B-4B32-9AAE-6EA7E7633FA9
NVM_INC=/Users/yasunagakei/.nvm/versions/node/v24.15.0/include/node
TMPDIR=/var/folders/40/prbwy4vx735gcqrnd76ncgtw0000gn/T/
TERM_PROGRAM=vscode
__CF_USER_TEXT_ENCODING=0x1F5:0x1:0xE
XPC_SERVICE_NAME=0
XPC_FLAGS=0x0
GIT_ASKPASS=/Volumes/Cursor Installer/Cursor.app/Contents/Resources/app/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/Volumes/Cursor Installer/Cursor.app/Contents/Frameworks/Cursor Helper (Plugin).app/Contents/MacOS/Cursor Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/Volumes/Cursor Installer/Cursor.app/Contents/Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/40/prbwy4vx735gcqrnd76ncgtw0000gn/T/vscode-git-87bdeb0c03.sock
VSCODE_GIT_IPC_AUTH_TOKEN=b6e7dd47de9e765c07940378c54c3d3e9d3ee81783bfe671821f28202f705135
CLAUDE_CODE_SSE_PORT=29318
VSCODE_INJECTION=1
ZDOTDIR=/Users/yasunagakei
USER_ZDOTDIR=/Users/yasunagakei
OLDPWD=/Users/yasunagakei/kadai09-keiyasu7022-arch
VSCODE_PROFILE_INITIALIZED=1
_=/Users/yasunagakei/kadai09-keiyasu7022-arch/./myenv
LC_TIME=ja_JP.UTF-8

yasunagakei@yasunagakeinoMacBook-Air kadai09-keiyasu7022-arch % ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba  
OSLogRateLimit=64
PWD=/Users/yasunagakei/kadai09-keiyasu7022-arch
NVM_DIR=/Users/yasunagakei/.nvm
USER=yasunagakei
SECURITYSESSIONID=186b0
MallocNanoZone=0
__CFBundleIdentifier=com.todesktop.230313mzl4w4u92
COMMAND_MODE=unix2003
LANG=ja_JP.UTF-8
ANTHROPIC_API_KEY=
CURSOR_CLI=ELECTRON_RUN_AS_NODE=1 "/Volumes/Cursor Installer/Cursor.app/Contents/MacOS/Cursor" "/Volumes/Cursor Installer/Cursor.app/Contents/Resources/app/out/cli.js"
PATH=/Users/yasunagakei/.nvm/versions/node/v24.15.0/bin:/Users/yasunagakei/.local/bin:/opt/homebrew/opt/openjdk/bin:/opt/homebrew/opt/openjdk/bin:/opt/anaconda3/bin:/Library/Frameworks/Python.framework/Versions/3.14/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/pkg/env/global/bin:/opt/homebrew/bin:/Users/yasunagakei/.nvm/versions/node/v24.15.0/bin:/Users/yasunagakei/.local/bin:/opt/homebrew/opt/openjdk/bin:/opt/anaconda3/bin:/Library/Frameworks/Python.framework/Versions/3.14/bin
TERM=xterm-256color
LOGNAME=yasunagakei
CURSOR_CLI_MODE=local
NVM_CD_FLAGS=-q
SSH_AUTH_SOCK=/var/run/com.apple.launchd.eksrj0fMYx/Listeners
TERM_PROGRAM_VERSION=3.3.30
CPPFLAGS=-I/opt/homebrew/opt/openjdk/include
SHLVL=3
TERM_SESSION_ID=A8C6469F-37B3-4AA5-991E-6848D833A2D9
SHELL=/bin/zsh
HOME=/Users/yasunagakei
COLORTERM=truecolor
NVM_BIN=/Users/yasunagakei/.nvm/versions/node/v24.15.0/bin
LaunchInstanceID=CBF3DB15-4C0B-4B32-9AAE-6EA7E7633FA9
NVM_INC=/Users/yasunagakei/.nvm/versions/node/v24.15.0/include/node
TMPDIR=/var/folders/40/prbwy4vx735gcqrnd76ncgtw0000gn/T/
TERM_PROGRAM=vscode
__CF_USER_TEXT_ENCODING=0x1F5:0x1:0xE
XPC_SERVICE_NAME=0
XPC_FLAGS=0x0
GIT_ASKPASS=/Volumes/Cursor Installer/Cursor.app/Contents/Resources/app/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/Volumes/Cursor Installer/Cursor.app/Contents/Frameworks/Cursor Helper (Plugin).app/Contents/MacOS/Cursor Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/Volumes/Cursor Installer/Cursor.app/Contents/Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/40/prbwy4vx735gcqrnd76ncgtw0000gn/T/vscode-git-87bdeb0c03.sock
VSCODE_GIT_IPC_AUTH_TOKEN=b6e7dd47de9e765c07940378c54c3d3e9d3ee81783bfe671821f28202f705135
CLAUDE_CODE_SSE_PORT=29318
VSCODE_INJECTION=1
ZDOTDIR=/Users/yasunagakei
USER_ZDOTDIR=/Users/yasunagakei
OLDPWD=/Users/yasunagakei/kadai09-keiyasu7022-arch
VSCODE_PROFILE_INITIALIZED=1
_=/Users/yasunagakei/kadai09-keiyasu7022-arch/./myenv
LC_TIME=ja_JP.UTF-8
TZ=Cuba

yasunagakei@yasunagakeinoMacBook-Air kadai09-keiyasu7022-arch % ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba ls -l
total 384
-rw-r--r--  1 yasunagakei  staff     132  6月 29 23:15 Makefile
-rwxr-xr-x  1 yasunagakei  staff   33736  6月 29 23:18 myenv
-rw-r--r--  1 yasunagakei  staff    1125  6月 29 23:20 myenv.c
-rwxr-xr-x  1 yasunagakei  staff     216  6月 29 23:15 myputenv.c
-rw-r--r--  1 yasunagakei  staff      93  6月 29 23:15 myputenv.h
-rw-r--r--  1 yasunagakei  staff    1268  6月 29 23:15 README.md
-rw-r--r--  1 yasunagakei  staff  139098  6月 29 23:15 README.pdf
 */