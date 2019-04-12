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
    int fd_P2C[2], fd_C2P[2];

    pipe(fd_P2C);
    pipe(fd_C2P);

    int pid = fork();
    std::string received_str = "";

    if(pid == 0)
    {
        // Hijo
        close(fd_P2C[STDOUT_FILENO]); // Cerramos la escritura del pipe de recepcion.
        close(fd_C2P[STDIN_FILENO]);  // Cerramos la lectura del pipe de envio.

        dup2(fd_P2C[STDIN_FILENO], STDIN_FILENO);   // Remplazamos std::cin por el pipe de recepcion.
        dup2(fd_C2P[STDOUT_FILENO], STDOUT_FILENO); // Remplazamos std::cout por el pipe de salida.

        // Ejecutamos el codigo hijo.
        // char *newargv[] = { NULL };
        execve("child", nullptr, NULL);
    }
    else
    {
        // Padre
        close(fd_P2C[STDIN_FILENO]);  // Cerramos la lectura del pipe de envio.
        close(fd_C2P[STDOUT_FILENO]); // Cerramos la escritura del pipe de recepcion.

        char reading_buffer;
        std::string toWrite = "HOLA HIJO\n";

        dup2(fd_C2P[STDIN_FILENO], STDIN_FILENO); // Remplazamos std::cin al pipe de recepcion.

        // dup2(fd_C2P[STDOUT_FILENO], STDOUT_FILENO); // Remplazamos el std::cout por el pipe de envio.
        write(fd_P2C[STDOUT_FILENO], toWrite.c_str(), toWrite.length()); // Escribimos el string.
        // std::cout << toWrite;
        // dup2(STDOUT_FILENO, fd_C2P[STDOUT_FILENO]); // Restauramos el std::cout (?)

        std::getline(std::cin, received_str); // Leemos el string desde el pipe.

        std::cout << "Parent received: "<< received_str<< std::endl;
    }

    // Cerramos todo.
    close(fd_P2C[STDIN_FILENO]);
    close(fd_P2C[STDOUT_FILENO]);

    close(fd_C2P[STDIN_FILENO]);
    close(fd_C2P[STDOUT_FILENO]);

    return 0;
}