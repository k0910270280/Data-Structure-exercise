#include <stdio.h>
int main() 
{
		int m, row, col, val, matrix[20][20] = { 0 }, max = 0;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf(" (%d:%d)=%d", &row, &col, &val);
			matrix[row][col] = val;
			if (row > max)
				max = row;
			else if (col > max)
				max = col;
		}
		for (int i = 1; i <= max; i++) {
			int j = 0;
			while (j < i - 1)
				printf("%d ", matrix[j++][i]);

			matrix[i - 1][++j] = 0;
			for (int k = 1; k <= max; k++)
				matrix[i - 1][j] += matrix[i][k] * matrix[j][k];

			while (j < max) {
				printf("%d ", matrix[i - 1][j]);
				matrix[i - 1][++j] = 0;
				for (int k = 1; k <= max; k++)
					matrix[i - 1][j] += matrix[i][k] * matrix[j][k];
			}
			printf("%d\n", matrix[i - 1][j]);
		}
}