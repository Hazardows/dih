./"../builder/builder" build src build dihi \
  "-Wall -Wextra" \
  "" \
  "-I../dih/src" \
  "-O2 -L../dih/build -ldih -Wl,-rpath,'\$ORIGIN'"

cp ../dih/build/libdih.so build/