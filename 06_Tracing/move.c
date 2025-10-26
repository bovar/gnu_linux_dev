#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Too few arguements. Usage: ./move <infile> <outfile>\n");
		return 1;
	}

	int fin = open(argv[1], O_RDONLY);
	if (fin < 0) {
		fprintf(stderr, "Can't open file %s\n", argv[1]);
		return 2;
	}

	int fout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fout < 0) {
		close(fin);
		fprintf(stderr, "Can't open file %s\n", argv[1]);
		return 3;
	}

	char buf[4096];

	int rd;
	while ((rd = read(fin, buf, sizeof(buf))) > 0) {
		int t = write(fout, buf, rd);
		if (t != rd) {
			fprintf(stderr, "Error while writing to file %s\n", argv[2]);
			close(fin);
			close(fout);
			remove(argv[2]);
			return 4;
		}
	}

	if (rd < 0) {
		fprintf(stderr, "Error while reading from file %s\n", argv[1]);
		close(fin);
		close(fout);
		remove(argv[2]);
		return 5;
	}

	close(fin);
	close(fout);

	if (remove(argv[1])) {
		fprintf(stderr, "Error while deleting file %s\n", argv[1]);
		remove(argv[2]);
		return 6;
	}

	return 0;
}
