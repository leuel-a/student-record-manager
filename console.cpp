#include "headers/main.hpp"
#include "headers/file_Storage.hpp"

FileStorage storage;

int main()
{
    // Configure readline to auto-complete paths when the tab key is hit.
    rl_bind_key('\t', rl_complete);

    // Enable history
    using_history();

    while (1) {

        char* input = readline_gets();
        int check = get_function(input);
        if (check == -1)
        {
            free(input);
            exit(EXIT_FAILURE);
        }
        free(input);
    }
    return 0;
}
