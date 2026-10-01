#include <iostream>
#include <memory>

// this include is long as hell
#include <dih/core/ast/ast_printer.hpp>

using namespace std;

int main() {
    unique_ptr<dih::expr::Binary> expression = make_unique<dih::expr::Binary>(
        make_unique<dih::expr::Unary>(
            dih::Token(dih::Token::Type::T_MINUS, "-", 1),
            make_unique<dih::expr::Literal>(123.0)
        ),
        dih::Token(dih::Token::Type::T_ASTERISK, "*", 1),
            make_unique<dih::expr::Grouping>(
            make_unique<dih::expr::Literal>(45.67)
        )
    );
    
    dih::AstPrinter printer;
    cout << printer.print(*expression) << endl;
    // Salida esperada: (* (- 123) (group 45.67))
    
    return 0;
}