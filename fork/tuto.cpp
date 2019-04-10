// Tutorial
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <string>
#include <sys/wait.h>

int main()
{
    int fd_C2P[2], fd_P2C[2]; // Creamos las pipe.
    pipe(fd_C2P);
    pipe(fd_P2C);

    int pid1 = fork(); // Creamos el hijo.

    if(pid1 == 0)
    {
        // Somos el hijo.
        std::string str = "";

        close(fd_C2P[STDIN_FILENO]);                // Cerraremos el pipe de lectura, puesto que no lo vamos a usar.
        dup2(fd_C2P[STDOUT_FILENO], STDOUT_FILENO); // Redirigimos la escritura del pipe.
        dup2(fd_P2C[STDIN_FILENO], STDIN_FILENO);   // Redirigimos la entrada de datos.
        std::getline(std::cin, str);                // Recibimos desde el pipe.
        
        dup2(STDIN_FILENO, fd_P2C[STDIN_FILENO]);
        // Ejecutamos el codigo.
        std::cout << "Hijo: " << str << "\n";
    }
    else
    {
        // Estamos en el padre.
        std::string str = "";
        close(fd_C2P[STDOUT_FILENO]); // Cerramos la escritura del pipe, que no lo vamos a usar.
        dup2(fd_C2P[STDIN_FILENO], STDIN_FILENO); // Redirigimos la salida.
        std::getline(std::cin, str);
        dup2(fd_P2C[STDOUT_FILENO], STDOUT_FILENO); // Redirigimos el cout.
        std::cout << "Padre: " << str << "<<\t";
        // Ejecutamos el codigo
        // 1execlp("grep", "grep", "raodm", NULL);
    }
    
    waitpid(pid1, nullptr, 0); // Esperamos al primer hijo.
    close(fd_C2P[1]);
    close(fd_P2C[1]);

    return 0;
}