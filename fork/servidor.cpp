#include <unistd.h>
#include <iostream>
#include <cstring>
#include <string>

/*
#define STDIN_FILENO    0       Standard input
#define STDOUT_FILENO   1       Standard output
#define STDERR_FILENO   2       Standard error output
*/

int main()
{
    int pipe_iz[2], pipe_dc[2]; // Se declaran los dos file descriptors.

    // Creamos los buffers.
    pipe(pipe_iz);
    pipe(pipe_dc);

    int pid = fork(); // Creamos el hijo.
    std::string childSaid = ""; // Creamos el string de recepcion de codigo externo.

    if(pid == 0)
    {
        // Cerrammos los descriptores que no vamos a usar.
        close(pipe_iz[STDIN_FILENO]);  // Cerramos pipe iz, lectura.
        close(pipe_dc[STDOUT_FILENO]); // Cerramos pipe dc, escritura.

        // Duplicamos los fd que vamos a usar.
        dup2(pipe_iz[STDOUT_FILENO], STDOUT_FILENO); // Redirección std::cout, pipe iz.
        dup2(pipe_dc[STDIN_FILENO], STDIN_FILENO);   // Redirección std::cin, pipe dc.

        execve("cli", nullptr, NULL); // Ejecutamos el codigo.

        dup2(STDOUT_FILENO, pipe_iz[STDOUT_FILENO]); // Restablecemos std::cout.
        dup2(STDIN_FILENO, pipe_dc[STDIN_FILENO]);   // Restalecemos std::cin.
    }
    else
    {
        // Cerrammos los descriptores que no vamos a usar.
        close(pipe_iz[STDOUT_FILENO]); // Cerramos pipe iz, escritura.
        close(pipe_dc[STDIN_FILENO]);  // Cerramos pipe dc, lectura.

        // Duplicamos los fd que vamos a usar.
        dup2(pipe_iz[STDIN_FILENO], STDIN_FILENO);   // Redirección std::cin, pipe iz.
        dup2(pipe_dc[STDOUT_FILENO], STDOUT_FILENO); // Redirección std::cout, pipe dc.

        std::cout << "LE ESCRIBIMOS AL HIJO";
        std::getline(std::cin, childSaid); // Leemos lo que diga el hijo.

        dup2(STDIN_FILENO, pipe_iz[STDIN_FILENO]); // Restablecemos std::cin
        dup2(STDOUT_FILENO, pipe_dc[STDOUT_FILENO]); // Restablecemos std::cout
    }

    // Cerramos todo.
    close(pipe_iz[STDIN_FILENO]);
    close(pipe_dc[STDOUT_FILENO]);
    close(pipe_iz[STDOUT_FILENO]);
    close(pipe_dc[STDIN_FILENO]);

    return 0;
}