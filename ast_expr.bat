REM ast
make -f "Makefile.executable.mak" all TARGET=release ASSEMBLY=gen_ast_expr COMPILED_NAME=ast ADDL_INC_FLAGS="" ADDL_LINK_FLAGS=""
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

call "bin/ast.exe" "./"
move "Expr.hpp" "dih\src\dih\core\ast\expr.hpp"
move "Stmt.hpp" "dih\src\dih\core\ast\stmt.hpp"