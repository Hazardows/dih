./"../builder/builder" build src build libdih.so \
  "-Wall -Wextra -fPIC" \
  "-DDIH_API_EXPORT" \
  "" \
  "-O2 -shared"