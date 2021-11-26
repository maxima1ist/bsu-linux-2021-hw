#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd1 = open("file1.txt", O_RDWR);
    int fd2 = open("file2.txt", O_RDWR);

    const off_t fileSize1 = lseek(fd1, 0, SEEK_END);
    const off_t fileSize2 = lseek(fd2, 0, SEEK_END);
    lseek(fd1, 0, SEEK_SET);
    lseek(fd2, 0, SEEK_SET);

    if (fileSize1 > fileSize2) {
        ftruncate(fd2, fileSize1);
    }
    else {
        ftruncate(fd1, fileSize2);
    }

    char buff1[BUFSIZ];
    char buff2[BUFSIZ];
    int n1 = read(fd1, buff1, BUFSIZ);
    int n2 = read(fd2, buff2, BUFSIZ);
    while (n1 > 0 || n2 > 0) {
        if (n1 > 0 && n2 > 0) {
            lseek(fd1, -n1, SEEK_CUR);
            lseek(fd2, -n2, SEEK_CUR);
            if (write(fd2, buff1, n1) != n1 ||
                write(fd1, buff2, n2) != n2) {
                printf("failed to swap files\n");
                break;
            }
        }
        else if (n1 > 0) {
            lseek(fd1, -n1, SEEK_CUR);
            if (write(fd2, buff1, n1) != n1) {
                printf("failed to swap files\n");
                break;
            }
        }
        else if (n2 > 0) {
            lseek(fd2, -n2, SEEK_CUR);
            if (write(fd1, buff2, n2) != n2) {
                printf("failed to swap files\n");
                break;
            }
        }
        if (n1 > 0) {
            n1 = read(fd1, buff1, BUFSIZ);
        }
        if (n2 > 0) {
            n2 = read(fd2, buff2, BUFSIZ);
        }
    }

    if (fileSize1 > fileSize2) {
        ftruncate(fd1, fileSize2);
    }
    else {
        ftruncate(fd2, fileSize1);
    }

    close(fd1);
    close(fd2);

    return 0;
}