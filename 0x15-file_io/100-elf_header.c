#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <elf.h>

void merejaprint(unsigned char *e_indent);
void aynetprint(unsigned int e_type,unsigned char *e_indent);
void agebabprint(unsigned long int e_entry, unsigned char *e_ident);
void mezgat(int num);
void elfcheck(unsigned char *e_indent);
void asmatprint(unsigned char *e_indent);
void kiflprint(unsigned char *e_indent);
void versionawta(unsigned char *e_indent);
void abitiprint(unsigned char *e_indent);
void sabiprint(unsigned char *e_indent);

/**
 * mezgat - closes file
 * @num: file descript
 */
void mezgat(int num)
{
	if (close(num) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", num);
		exit(98);
	}
}

/**
 * agebabprint - prints entry
 * @e_entry: entry
 * @e_indent: pointer to array
 */
void agebabprint(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: \t");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |   ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}
/**
 * aynetprint - prints type
 * @e_indent: pointer to array
 * @e_type: type
 */
void aynetprint(unsigned int e_type,unsigned char *e_indent)
{
	if (e_indent[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf(" Type: \t");
	switch (e_type)
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
			printf("<unknown: %x>\n", e_type);
	}
}
/**
 * sabiprint - prints osabi
 * @e_indent: pointer to array
 */

void sabiprint(unsigned char *e_indent)
{
	printf(" OS/ABI: \t");
	switch (e_indent[EI_OSABI])
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
			printf("<unknown: %x>\n", e_indent[EI_OSABI]);
	}
}
/**
 * abitiprint - prints abi
 * @e_indet: pointer to array
 */
void abitiprint(unsigned char *e_indent)
{
	printf(" ABI Version: \t%d\n", e_indent[EI_ABIVERSION]);
}
/**
 * versionawta - prints version
 * @e_indet: pointer to array
 */
void versionawta(unsigned char *e_indent)
{
	 printf(" Version: \t%d",  e_indent[EI_VERSION]);
	 switch (e_indent[EI_VERSION])
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
 * merejaprint - prints data
 * @e_indet: pointer to array
 */
void merejaprint(unsigned char *e_indent)
{
	printf(" Data: \t");
	switch (e_indent[EI_DATA])
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
			printf("<unknown: %x>\n", e_indent[EI_CLASS]);
	}
}
/**
 * kiflprint - prints class
 * @e_indent: pointer to array
 */
void kiflprint(unsigned char *e_indent)
{
	printf(" Class: \t");
	switch (e_indent[EI_CLASS])
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
			printf("<unknown: %x>\n", e_indent[EI_CLASS]);
	}
}

/**
 * asmatprint - prints magic
 * @e_indent: pointer to array
 */

void asmatprint(unsigned char *e_indent)
{
	int bota;

	printf(" Magic: \t");
	while (bota < EI_NIDENT)
	{
		printf("%02x", e_indent[bota]);
		if (bota == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
		bota++;
	}
}
/**
 * elfcheck - checks file
 * @e_indent: pointer to array
 */
void elfcheck(unsigned char *e_indent)
{
	int bota;

	while (bota < 4)
	{
		if (e_indent[bota] != 127 && e_indent[bota] != 'E' &&
			e_indent[bota] != 'L' && e_indent[bota] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
		bota++;
	}
}
/**
 * main - dirver function
 * @argc: unused
 * @argv: array
 * Return: integer
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
        int file_open, file_read;
        Elf64_Ehdr *chnklat;

        file_open = open(argv[1], O_RDONLY);

        if (file_open == -1)
        {
                dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
                exit(98);
        }
        chnklat = malloc(sizeof(Elf64_Ehdr));
        if (chnklat == NULL)
        {
                mezgat(file_open);
                dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
                exit(98);
        }
        file_read = read(file_open, chnklat, sizeof(Elf64_Ehdr));
        if (file_read == -1)
        {
                mezgat(file_open);
                free(chnklat);
                dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
                exit(98);
        }
        elfcheck(chnklat->e_ident);
        printf("ELF Header:\n");
        asmatprint(chnklat->e_ident);
        kiflprint(chnklat->e_ident);
        merejaprint(chnklat->e_ident);
        versionawta(chnklat->e_ident);
        sabiprint(chnklat->e_ident);
        abitiprint(chnklat->e_ident);
        aynetprint(chnklat->e_type, chnklat->e_ident);
        agebabprint(chnklat->e_entry, chnklat->e_ident);

        free(chnklat);
        mezgat(file_open);
        return (0);
}

