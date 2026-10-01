#include <cstdio>
#include <dih/dih.hpp>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc > 2) {
        printf("Usage: dihi [script]\n");
        return 64;
    }
    else if (argc == 2) {
        dih::dihManager manager;
        dih::run_file(argv[1], manager);
    }
    else {
        dih::dihManager manager;
        dih::run_prompt(manager);
    }
}