// #include <stddef.h>
// #include <stdint.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <errno.h>
// #include <string.h>

// int main() {
//     pid_t pid;
//     const char *program = "./hello"; // Program to execute

//     // Create a new child process
//     pid = fork();

//     if (pid < 0) {
//         perror("fork failed");
//         exit(EXIT_FAILURE);
//     }

//     if (pid == 0) {
//         // Child process
//         char *args[] = {program, NULL};  // Arguments array

//         if (execv(program, args) == -1) {
//             perror("execv failed");
//             exit(EXIT_FAILURE);
//         }
//     } else {
//         // Parent process
//         if (wait(NULL) == -1) { // Wait for child process to finish
//             perror("wait failed");
//             exit(EXIT_FAILURE);
//         }
//         printf("Child process completed\n");
//     }

//     return EXIT_SUCCESS;
// }