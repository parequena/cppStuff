// Fichero padre


int main()
{
    // Creamos el pipe
    int fd_padreHijo[2];
    pipe(fd_padreHijo); // Creamos el pipe.


    int pid = fork(); // Creamos el hijo

    if(pid == 0)
    {
        // Somos el proceso hijo.
        close(fd_padreHijo[0]); // Cerramos la lectura.
        // dup2(fd_padreHijo[1], 1); // Escritura redirigida al pipe.
        stdio_filebuf<char> fb(pipefd[1], ios::out, 1);

        std::string fileName = "",
                    args = "";
        execve(fileName, args, NULL);
    }
    else
    {
        // Somos el proceso padre.
        close(fd_padreHijo[1]); // Cerramos la escritura.
        dup2(fd_padreHijo[0], 0); // Lectura redirigida al pipe.
    }
    

    return 0;
}