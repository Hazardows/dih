#include <iostream>

#include <dih/dihVM.hpp>

bool is_even(dih::var_t num) {
    if (dih::isNumber(num)) {
        return (num % 2 == 0);
    }

    dih::exeption("hey, this is not a number man!");
}

std::string func_def = "extern bool is_even(var num)";

int main() {
    dih::dihManager manager;
    dih::dihVM vm(manager);
    
    vm.init();
    if (vm.ready()) {
        // inyecta la funcion a la runtime de la vm mediante el manager
        manager.inject(is_even, func_def);
        
        // carga el script compilado
        vm.load("script.dihc");
        vm.run();   // ejecuta la función main en dih.
                    // si se especifica el nombre de otra función,
                    // esta será ejecutada con los argumentos especificados
                    // (o sin argumentos si nada es especificado)
                    // ejemplo: vm.run("update", arg1, arg2)

        if (manager.error()) {
            vm.kill();
            std::cout << "an error has ocurred during runtime" << std::endl;
            return -2;
        }

        // en dih la función main puede retornar varios tipos de datos
        if (manager.returnType() == dih::returnType::String) {
            std::cout << "a mesagge from dih: " << manager.returned() << std::endl;
        }

        return 0;
    }
    
    std::cout << "failed to initialize dihVM" << std::endl;
    return -1;
}