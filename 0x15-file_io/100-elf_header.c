#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void validateElfFile(unsigned char *e_ident);
void printMagicNumbers(unsigned char *e_ident);
void printElfClass(unsigned char *e_ident);
void printElfData(unsigned char *e_ident);
void printElfVersion(unsigned char *e_ident);
void printElfOSABI(unsigned char *e_ident);
void printElfType(unsigned int e_type);
void printElfEntry(unsigned long int e_entry);

/**
 * validateElfFile - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit with code 98.
 */
void validateElfFile(unsigned char *e_ident)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (e_ident[i] != 127 && e_ident[i] != 'E' && e_ident[i] != 'L' && e_ident[i] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * printMagicNumbers - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void printMagicNumbers(unsigned char *e_ident)
{
    int i;

    printf(" Magic: ");

    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", e_ident[i]);

        if (i == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * printElfClass - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void printElfClass(unsigned char *e_ident)
{
    printf(" Class: ");

    switch (e_ident[EI_CLASS])
    {
        case ELFCLASSNONE:
            printf("none\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

/**
 * printElfData - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void printElfData(unsigned char *e_ident)
{
    printf(" Data: ");

    switch (e_ident[EI_DATA])
    {
        case ELFDATANONE:
            printf("none\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

/**
 * printElfVersion - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void printElfVersion(unsigned char *e_ident)
{
    printf(" Version: %d", e_ident[EI_VERSION]);

    switch (e_ident[EI_VERSION])
    {
        case EV_CURRENT:
            printf(" (current)\n");
            break;
        default:
            printf("\n");
            break;
    }
}

/**
 * printElfOSABI - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void printElfOSABI(unsigned char *e_ident)
{
    printf(" OS/ABI: ");

    switch (e_ident[EI_OSABI])
    {
        case ELFOSABI_NONE:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("UNIX - HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        case ELFOSABI_IRIX:
            printf("UNIX - IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("UNIX - FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("UNIX - TRU64\n");
            break;
        case ELFOSABI_ARM:
            printf("UNIX - ARM architecture\n");
            break;
        case ELFOSABI_STANDALONE:
            printf("Standalone (embedded) application\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

/**
 * printElfType - Prints the type of an ELF header.
 * @e_type: The type of the ELF header.
 */
void printElfType(unsigned int e_type)
{
    printf(" Type: ");

    switch (e_type)
    {
        case ET_NONE:
            printf("NONE (No file type)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            printf("<unknown: %x>\n", e_type);
    }
}

/**
 * printElfEntry - Prints the entry point address of an ELF header.
 * @e_entry: The entry point address.
 */
void printElfEntry(unsigned long int e_entry)
{
    printf(" Entry point address: 0x%lx\n", e_entry);
}

/**
 * main - Entry point.
 * @argc: The number of command line arguments.
 * @argv: An array of command line argument strings.
 *
 * Return: 0 on success, otherwise 98.
 */
int main(int argc, char *argv[])
{
    int fd;
    ssize_t bytes_read;
    unsigned char e_ident[EI_NIDENT];
    Elf64_Ehdr elf_header;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", argv[0]);
        return (98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Cannot open file '%s'\n", argv[1]);
        return (98);
    }

    bytes_read = read(fd, e_ident, EI_NIDENT);
    if (bytes_read == -1)
    {
        dprintf(STDERR_FILENO, "Error: Cannot read file '%s'\n", argv[1]);
        close(fd);
        return (98);
    }

    validateElfFile(e_ident);
    printMagicNumbers(e_ident);

    bytes_read = read(fd, &elf_header, sizeof(elf_header));
    if (bytes_read == -1)
    {
        dprintf(STDERR_FILENO, "Error: Cannot read file '%s'\n", argv[1]);
        close(fd);
        return (98);
    }

    printElfClass(e_ident);
    printElfData(e_ident);
    printElfVersion(e_ident);
    printElfOSABI(e_ident);
    printElfType(elf_header.e_type);
    printElfEntry(elf_header.e_entry);

    close(fd);
    return (0);
}
