./"../builder/builder" build src build dih_ast \
  "-Wall -Wextra" \
  "" \
  "" \
  "-O2"

./build/dih_ast .
mv Expr.hpp ../dih/src/dih/core/ast/expr.hpp
mv Stmt.hpp ../dih/src/dih/core/ast/stmt.hpp