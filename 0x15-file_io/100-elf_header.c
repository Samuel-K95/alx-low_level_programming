#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void verifyElf(unsigned char *magicNumbers);
void displayMagicNumbers(unsigned char *magicNumbers);
void displayElfClass(unsigned char *magicNumbers);
void displayDataEncoding(unsigned char *magicNumbers);
void displayElfVersion(unsigned char *magicNumbers);
void displayOsAbi(unsigned char *magicNumbers);
void displayAbiVersion(unsigned char *magicNumbers);
void displayElfType(unsigned int elfType, unsigned char *magicNumbers);
void displayEntryPoint(unsigned long int entryPoint, unsigned char *magicNumbers);
void closeElfFile(int fileDescriptor);

/**
 * verifyElf - Checks if a file is an ELF file.
 * @magicNumbers: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void verifyElf(unsigned char *magicNumbers)
{
    int index;

    for (index = 0; index < 4; index++)
    {
        if (magicNumbers[index] != 127 &&
            magicNumbers[index] != 'E' &&
            magicNumbers[index] != 'L' &&
            magicNumbers[index] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * displayMagicNumbers - Prints the magic numbers of an ELF header.
 * @magicNumbers: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void displayMagicNumbers(unsigned char *magicNumbers)
{
    int index;

    printf(" Magic: ");

    for (index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", magicNumbers[index]);

        if (index == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * displayElfClass - Prints the class of an ELF header.
 * @magicNumbers: A pointer to an array containing the ELF class.
 */
void displayElfClass(unsigned char *magicNumbers)
{
    printf(" Class:                          ");

    switch (magicNumbers[EI_CLASS])
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
        printf("<unknown: %x>\n", magicNumbers[EI_CLASS]);
    }
}

/**
 * displayDataEncoding - Prints the data encoding of an ELF header.
 * @magicNumbers: A pointer to an array containing the ELF data encoding.
 */
void displayDataEncoding(unsigned char *magicNumbers)
{
    printf(" Data Encoding:                  ");

    switch (magicNumbers[EI_DATA])
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
        printf("<unknown: %x>\n", magicNumbers[EI_DATA]);
    }
}

/**
 * displayElfVersion - Prints the version of an ELF header.
 * @magicNumbers: A pointer to an array containing the ELF version.
 */
void displayElfVersion(unsigned char *magicNumbers)
{
    printf(" Version:                        %d", magicNumbers[EI_VERSION]);

    switch (magicNumbers[EI_VERSION])
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
 * displayOsAbi - Prints the OS/ABI of an ELF header.
 * @magicNumbers: A pointer to an array containing the ELF OS/ABI.
 */
void displayOsAbi(unsigned char *magicNumbers)
{
    printf(" OS/ABI:                         ");

    switch (magicNumbers[EI_OSABI])
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
		    printf("ARM\n");
		    break;
	   case ELFOSABI_STANDALONE:
		    printf("Standalone App\n");
		    break;
	   default:
		    printf("<unknown: %x>\n", magicNumbers[EI_OSABI]);
		    break;
    }
}

/**
 * displayAbiVersion - Prints the ABI version of an ELF header.
 * @magicNumbers: A pointer to an array containing the ELF ABI version.
 */
void displayAbiVersion(unsigned char *magicNumbers)
{
    printf(" ABI Version:                    %d\n", magicNumbers[EI_ABIVERSION]);
}

/**
 * displayElfType - Prints the type of an ELF header.
 * @elfType: The ELF type.
 * @magicNumbers: A pointer to an array containing the ELF class.
 */
void displayElfType(unsigned int elfType, unsigned char *magicNumbers)
{
    if (magicNumbers[EI_DATA] == ELFDATA2MSB)
        elfType >>= 8;

    printf(" Type:                           ");

    switch (elfType)
    {
    case ET_NONE:
        printf("NONE (None)\n");
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
        printf("<unknown: %x>\n", elfType);
    }
}

/**
 * displayEntryPoint - Prints the entry point of an ELF header.
 * @entryPoint: The address of the ELF entry point.
 * @magicNumbers: A pointer to an array containing the ELF class.
 */
void displayEntryPoint(unsigned long int entryPoint, unsigned char *magicNumbers)
{
    printf(" Entry Point Address:            ");

    if (magicNumbers[EI_DATA] == ELFDATA2MSB)
    {
        entryPoint = ((entryPoint << 8) & 0xFF00FF00) |
                     ((entryPoint >> 8) & 0xFF00FF);
        entryPoint = (entryPoint << 16) | (entryPoint >> 16);
    }

    if (magicNumbers[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)entryPoint);
    else
        printf("%#lx\n", entryPoint);
}

/**
 * closeElfFile - Closes an ELF file.
 * @fileDescriptor: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void closeElfFile(int fileDescriptor)
{
    if (close(fileDescriptor) == -1)
    {
        dprintf(STDERR_FILENO,
                "Error: Can't close file descriptor %d\n", fileDescriptor);
        exit(98);
    }
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
    Elf64_Ehdr *elfHeader;
    int fileDescriptor, readResult;

    fileDescriptor = open(argv[1], O_RDONLY);
    if (fileDescriptor == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    elfHeader = malloc(sizeof(Elf64_Ehdr));
    if (elfHeader == NULL)
    {
        closeElfFile(fileDescriptor);
        dprintf(STDERR_FILENO, "Error: Can't allocate memory for ELF header\n");
        exit(98);
    }

    readResult = read(fileDescriptor, elfHeader, sizeof(Elf64_Ehdr));
    if (readResult == -1)
    {
        free(elfHeader);
        closeElfFile(fileDescriptor);
        dprintf(STDERR_FILENO, "Error: %s: No such file\n", argv[1]);
        exit(98);
    }

    verifyElf(elfHeader->e_ident);
    printf("ELF Header:\n");
    displayMagicNumbers(elfHeader->e_ident);
    displayElfClass(elfHeader->e_ident);
    displayDataEncoding(elfHeader->e_ident);
    displayElfVersion(elfHeader->e_ident);
    displayOsAbi(elfHeader->e_ident);
    displayAbiVersion(elfHeader->e_ident);
    displayElfType(elfHeader->e_type, elfHeader->e_ident);
    displayEntryPoint(elfHeader->e_entry, elfHeader->e_ident);

    free(elfHeader);
    closeElfFile(fileDescriptor);
    return 0;
}

